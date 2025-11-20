/**
  ******************************************************************************
  * @file           : ads8638_diag.c
  * @brief          : ADS8638 diagnostic and troubleshooting functions
  ******************************************************************************
  */

#include "ads8638.h"
#include <stdio.h>

/**
  * @brief  Check ADS8638 communication status
  * @param  hadc: Pointer to ADS8638 handle structure
  * @retval 1 if communication OK, 0 if failed
  */
uint8_t ADS8638_CheckCommunication(ADS8638_HandleTypeDef *hadc)
{
    uint16_t response;
    HAL_StatusTypeDef status;

    // Test 1: Send NOP and check if we get any response
    status = ADS8638_SendCommand(hadc, ADS8638_CMD_NO_OP, &response);
    if (status != HAL_OK) {
        return 0;  // SPI communication failed
    }

    // Test 2: Check if MISO is stuck (all 0xFF or all 0x00 indicates problem)
    if (response == 0xFFFF || response == 0x0000) {
        return 0;  // MISO line issue
    }

    // Test 3: Try reading Feature Select register
    uint8_t feature_reg = 0;
    status = ADS8638_ReadRegister(hadc, ADS8638_REG_FEATURE_SEL, &feature_reg);
    if (status != HAL_OK) {
        return 0;  // Register read failed
    }

    // If we got here, basic communication is working
    return 1;
}

/**
  * @brief  Run comprehensive diagnostic test on ADS8638
  * @param  hadc: Pointer to ADS8638 handle structure
  * @retval None (prints results to UART)
  */
void ADS8638_DiagnosticTest(ADS8638_HandleTypeDef *hadc)
{
    uint16_t response;
    uint8_t reg_value;
    HAL_StatusTypeDef status;

    printf("\r\n=== ADS8638 Diagnostic Test ===\r\n");

    // Test 1: SPI Communication Test
    printf("\n1. SPI Communication Test:\r\n");
    printf("   Sending NOP commands...\r\n");

    for (int i = 0; i < 5; i++) {
        status = ADS8638_SendCommand(hadc, ADS8638_CMD_NO_OP, &response);
        printf("   NOP #%d: Status=%s, RX=0x%04X\r\n",
               i+1,
               (status == HAL_OK) ? "OK" : "FAIL",
               response);
        HAL_Delay(10);
    }

    // Test 2: MISO Line State Test
    printf("\n2. MISO Line State Test:\r\n");
    uint16_t test_patterns[] = {0x0000, 0xAAAA, 0x5555, 0xFFFF};
    for (int i = 0; i < 4; i++) {
        status = ADS8638_SendCommand(hadc, test_patterns[i], &response);
        printf("   TX=0x%04X -> RX=0x%04X (Status=%s)\r\n",
               test_patterns[i],
               response,
               (status == HAL_OK) ? "OK" : "FAIL");
        HAL_Delay(10);
    }

    // Test 3: Register Read Test
    printf("\n3. Register Read Test:\r\n");

    // Try to read Feature Select register
    status = ADS8638_ReadRegister(hadc, ADS8638_REG_FEATURE_SEL, &reg_value);
    printf("   Feature Select Reg: 0x%02X (Status=%s)\r\n",
           reg_value,
           (status == HAL_OK) ? "OK" : "FAIL");

    // Try to read Auto-Sequence Enable register
    status = ADS8638_ReadRegister(hadc, ADS8638_REG_AUTO_SEQ_EN, &reg_value);
    printf("   Auto-Seq Enable Reg: 0x%02X (Status=%s)\r\n",
           reg_value,
           (status == HAL_OK) ? "OK" : "FAIL");

    // Test 4: Data Pattern Analysis
    printf("\n4. ADC Data Pattern Analysis:\r\n");
    ADS8638_ReadAllChannels_AutoScan(hadc);

    uint8_t all_same = 1;
    uint16_t first_val = hadc->adc_data[0];
    for (int i = 1; i < 8; i++) {
        if (hadc->adc_data[i] != first_val) {
            all_same = 0;
            break;
        }
    }

    if (all_same && first_val == 0xFFF) {
        printf("   WARNING: All channels = 0xFFF (MISO stuck HIGH)\r\n");
    } else if (all_same && first_val == 0x000) {
        printf("   WARNING: All channels = 0x000 (MISO stuck LOW)\r\n");
    } else if (all_same) {
        printf("   WARNING: All channels same value (0x%03X)\r\n", first_val);
    } else {
        printf("   OK: Channels show variation\r\n");
    }

    // Test 5: Communication Status
    printf("\n5. Overall Communication Status:\r\n");
    if (ADS8638_CheckCommunication(hadc)) {
        printf("   PASS: Communication appears functional\r\n");
    } else {
        printf("   FAIL: Communication problem detected\r\n");
        printf("   Possible causes:\r\n");
        printf("   - SPI mode mismatch (should be Mode 1: CPOL=0, CPHA=1)\r\n");
        printf("   - Damaged chip or poor solder joints\r\n");
        printf("   - Insufficient power supply (AVDD/DVDD)\r\n");
        printf("   - MISO line issue (short/open circuit)\r\n");
        printf("   - Wrong SPI speed (try slower: <1MHz)\r\n");
    }

    printf("\n=== Diagnostic Test Complete ===\r\n\n");
}
