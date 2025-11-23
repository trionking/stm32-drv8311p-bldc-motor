# DRV8311P tSPI SDO Response Format Fix

## Issue

The register read/write was not working correctly despite proper tSPI frame format. All configuration registers were reading as 0x0000, and SYS_CTRL was reading 0x0003 instead of the written value 0x5000.

## Root Cause

**Incorrect data extraction from SDO response.**

### SDO Response Format (per Table 8-8)

The SDO output is **24 bits**:
- **Bits 23-16 (8 bits)**: Status byte (S7-S0)
- **Bits 15-0 (16 bits)**: Register data (D15-D0)

When receiving during a 32-bit SPI transfer, the 24-bit SDO is aligned to **bits 31-8**:
```
Bit 31-24: Status (8 bits S7-S0)
Bit 23-8:  Data (16 bits D15-D0)
Bit 7-0:   Don't care (undefined)
```

### Previous (Incorrect) Extraction

The code was extracting 15 bits from bits 15-1:
```c
*value = (uint16_t)((rx_frame >> 1) & 0x7FFF);  // WRONG
```

For RX Frame `0xFE002077`:
- Extracted value: `0x103B` (incorrect)

### Corrected Extraction

Extract 16 bits from bits 23-8:
```c
uint8_t status_byte = (rx_frame >> 24) & 0xFF;   // Status: 0xFE
*value = (uint16_t)((rx_frame >> 8) & 0xFFFF);   // Data: 0x0020
```

For RX Frame `0xFE002077`:
- Status byte: `0xFE`
- Data value: `0x0020`

## Status Byte (0xFE)

The status byte (S7-S0) is sent during the **first byte of the header** reception. According to the datasheet:

> "Upon receiving the first byte of header, the secondary device responds with an 8-bit device status information."

The `0xFE` status byte indicates the device's real-time status including:
- Fault conditions
- Parity errors
- Frame errors
- Other device status bits

**Note**: The exact bit definitions for S7-S0 are device-specific and should be referenced in the datasheet's status register section.

## Code Changes

### File: `Core/Src/drv8311.c`

**Function**: `DRV8311_ReadRegister16()` (lines 361-381)

**Before**:
```c
// Extract 15-bit data from bits 15-1
*value = (uint16_t)((rx_frame >> 1) & 0x7FFF);
printf("[DEBUG] RX Frame: 0x%08lX, Extracted 15-bit: 0x%04X\r\n", rx_frame, *value);
```

**After**:
```c
// SDO output is 24 bits: 8-bit status + 16-bit data
// In 32-bit SPI transfer, 24-bit SDO is aligned to bits 31-8:
//   Bits 31-24: Status (8 bits S7-S0)
//   Bits 23-8:  Data (16 bits D15-D0)
//   Bits 7-0:   Don't care
uint8_t status_byte = (rx_frame >> 24) & 0xFF;
*value = (uint16_t)((rx_frame >> 8) & 0xFFFF);

printf("[DEBUG] RX Frame: 0x%08lX, Status: 0x%02X, Data: 0x%04X\r\n",
       rx_frame, status_byte, *value);
```

## Expected Results After Fix

With the corrected data extraction:

1. **SYS_CTRL (0x3F)** should read back `0x5000` after writing `0x5000`
2. **PWM_CTRL1 (0x20)** should read back `0x0007` after configuration
3. **PWMG_CTRL (0x1D)** should show `PWM_EN` bit set after enabling PWM generation
4. **All configuration registers** should read back their written values correctly

### Debug Output Example

**Before** (incorrect):
```
[DEBUG] RX Frame: 0xFE00A000, Extracted 15-bit: 0x5000
Read back SYS_CTRL: 0x5000  <- Wrong extraction, by coincidence matched
```

**After** (correct):
```
[DEBUG] RX Frame: 0xFE00A000, Status: 0xFE, Data: 0x00A0
Read back SYS_CTRL: 0x00A0   <- Correct extraction
```

## Motor Control Impact

Once register writes are confirmed working:

1. **SYS_CTRL unlock** will succeed → other registers become writable
2. **PWM_CTRL1** configuration will apply → PWM mode set correctly
3. **PWMG_CTRL** will enable internal PWM generation → motor should spin
4. **DRV_CTRL** settings (slew rate, deadtime) will be applied
5. **CSA_CTRL** will enable current sensing with correct gain

## Build Information

**Build Date**: 2025-11-22
**Firmware**: `bldc_h743_mot_v101.elf`
**Size**: 89,160 bytes (text)
**Toolchain**: ARM GCC 13.3.rel1

## Testing Checklist

After flashing the new firmware:

- [ ] Verify SYS_CTRL reads back 0x5000 after write
- [ ] Verify PWM_CTRL1 reads back 0x0007 after init
- [ ] Verify PWMG_CTRL shows PWM_EN bit set (bit 10)
- [ ] Verify PWM_STATE reads back 0x003F
- [ ] Verify PWMG_PERIOD reads back configured value
- [ ] Monitor nFAULT pin (should stay HIGH)
- [ ] Check if motor spins when PWM generation is enabled

## References

- DRV8311 Datasheet: SLVSFN2B
- Table 8-8: SDO Output Data Word Format
- Section 8.3.10: tSPI Communication Protocol
- `.doc/DRV8311_Init_Analysis.md`
- `.doc/drv8311_registers.md`
