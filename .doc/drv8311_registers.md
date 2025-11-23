**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**8.4 Device Functional Modes**


**8.4.1 Functional Modes**

_**8.4.1.1 Sleep Mode**_


The nSLEEP pin manages the state of the DRV8311 family of devices. When the nSLEEP pin is low, the device
goes to a low-power sleep mode. In sleep mode, all FETs are disabled, sense amplifiers are disabled, the charge
pump is disabled, the AVDD regulator is disabled, and the SPI bus is disabled. The tSLEEP time must elapse after
a falling edge on the nSLEEP pin before the device goes to sleep mode. The device comes out of sleep mode
automatically if the nSLEEP pin is pulled high. The tWAKE time must elapse before the device is ready for inputs.


In sleep mode and when VVM < VUVLO, all MOSFETs are disabled.


**Note**


During power up and power down of the device through the nSLEEP pin, the nFAULT pin is held low
as the internal regulators are enabled or disabled. After the regulators have enabled or disabled, the
nFAULT pin is automatically released. The duration that the nFAULT pin is low does not exceed the
tSLEEP or tWAKE time.


_**8.4.1.2 Operating Mode**_


When the nSLEEP pin is high and the VVM voltage is greater than the VUVLO voltage, the device goes to
operating mode. The tWAKE time must elapse before the device is ready for inputs. In this mode the charge
pump, AVDD regulator and SPI bus are active.


_**8.4.1.3 Fault Reset (CLR_FLT or nSLEEP Reset Pulse)**_


In the case of device latched faults, the DRV8311 family of devices goes to a partial shutdown state to help
protect the power MOSFETs and system.


When the fault condition clears, the device can go to the operating state again by either setting the CLR_FLT
SPI bit on SPI devices or issuing a reset pulse to the nSLEEP pin on either interface variant. The nSLEEP
reset pulse (tRST) consists of a high-to-low-to-high transition on the nSLEEP pin. The low period of the sequence
should fall with the tRST time window or else the device will start the complete shutdown sequence. The reset
pulse has no effect on any of the regulators, device settings, or other functional blocks


46 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**8.5 SPI Communication**


**8.5.1 Programming**

_**8.5.1.1 SPI and tSPI Format**_


**SPI Format - with Parity**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



The SDI input data word is 24 bits long and consists of the following format:


 - 1 read or write bit, W (bit B23)

 - 6 address bits, A (bits B22 through B17)

 - Parity bit, P (bit B16)

 - 15 data bits with 1 parity bit, D (bits B15 through B0)


The SDO output data word is 24 bits long. The most significant bits are status bits and the least significant 16
bits are the data content of the register being accessed.


**Table 8-7. SDI Input Data Word Format for SPI**







|R/W|ADDRESS|Col3|Col4|Col5|Col6|Col7|PAR<br>ITY|PAR<br>ITY|DATA|Col11|Col12|Col13|Col14|Col15|Col16|Col17|Col18|Col19|Col20|Col21|Col22|Col23|Col24|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|
|W0|A5|A4|A3|A2|A1|A0|P|P|D14|D13|D12|D11|D10|D9|D8|D7|D6|D5|D4|D3|D2|D1|D0|


**Table 8-8. SDO Output Data Word Format**

|STATUS|Col2|Col3|Col4|Col5|Col6|Col7|Col8|DATA|Col10|Col11|Col12|Col13|Col14|Col15|Col16|Col17|Col18|Col19|Col20|Col21|Col22|Col23|Col24|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|B23<br>B22<br>B21<br>B20<br>B19<br>B18<br>B17<br>B16<br>B15<br>B14<br>B13<br>B12<br>B11<br>B10<br>B9<br>B8<br>B7<br>B6<br>B5<br>B4<br>B3<br>B2<br>B1<br>B0|
|S7|S6|S5|S4|S3|S2|S1|S0|D15|D14|D13|D12|D11|D10|D9|D8|D7|D6|D5|D4|D3|D2|D1|D0|



**tSPI Format - with Parity**


The SDI input data word is 32 bits long and consists of the following format:


 - 1 read or write bit, W (bit B31)

 - 4 secondary device ID bits, AD (bits B30 through B27)

 - 8 address bits, A (bits B26 through B19)

 - 2 reserved bits, 0 (bits B18, bit B17)

 - Parity bit, P (bit B16)

 - 15 data bits with 1 parity bit, D (bits B15 through B0)


The SDO output data word is 24 bits long. The first 8 bits are status bits and the last 16 bits are the data content
of the register being accessed. The format is same as standard SPI shown in Table 8-8


**Table 8-9. tSPI with Parity - SDI Input Data Word Format**

|R/W|SecondarydeviceID|Col3|Col4|Col5|ADDRESS|00|Col8|PARITY|PARITY|DATA|
|---|---|---|---|---|---|---|---|---|---|---|
|B31<br>B30<br>B29<br>B28<br>B27<br>B26 - B19<br>B18<br>B17<br>B16<br>B15<br>B14 - B0|B31<br>B30<br>B29<br>B28<br>B27<br>B26 - B19<br>B18<br>B17<br>B16<br>B15<br>B14 - B0|B31<br>B30<br>B29<br>B28<br>B27<br>B26 - B19<br>B18<br>B17<br>B16<br>B15<br>B14 - B0|B31<br>B30<br>B29<br>B28<br>B27<br>B26 - B19<br>B18<br>B17<br>B16<br>B15<br>B14 - B0|B31<br>B30<br>B29<br>B28<br>B27<br>B26 - B19<br>B18<br>B17<br>B16<br>B15<br>B14 - B0|B31<br>B30<br>B29<br>B28<br>B27<br>B26 - B19<br>B18<br>B17<br>B16<br>B15<br>B14 - B0|B31<br>B30<br>B29<br>B28<br>B27<br>B26 - B19<br>B18<br>B17<br>B16<br>B15<br>B14 - B0|B31<br>B30<br>B29<br>B28<br>B27<br>B26 - B19<br>B18<br>B17<br>B16<br>B15<br>B14 - B0|B31<br>B30<br>B29<br>B28<br>B27<br>B26 - B19<br>B18<br>B17<br>B16<br>B15<br>B14 - B0|B31<br>B30<br>B29<br>B28<br>B27<br>B26 - B19<br>B18<br>B17<br>B16<br>B15<br>B14 - B0|B31<br>B30<br>B29<br>B28<br>B27<br>B26 - B19<br>B18<br>B17<br>B16<br>B15<br>B14 - B0|
|W0|0|0|AD1|AD0|A7 - A0|0|0|P|P|D14 - D0|



The details of the bits used in SPI and tSPI frame format are detailed below.


**Read/Write Bit (R/W)** : R/W (W0) bit being 0 indicates a SPI/tSPI Write transaction. For a read operation RW bit
needs to be 1.


**Secondary device ID Bits (AD)** : Each tSPI secondary device on the same chip select should have a unique
identifier. Secondary device ID field is the 4-bit unique identifier of the tSPI secondary device. For a successful
Read/Write transaction the secondary device ID field should match with the secondary device address. In
DRV8311 the two most significant bits of secondary device addresses are set to 00. The least two significant
bits of the secondary device address can be configured using the AD1 and AD0 pins. The secondary device
address 15 (0xF) is reserved for general call, all the devices on the same bus accept a write operation when


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 47


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


the secondary device ID field is set to 15. Hence the valid tSPI secondary device addresses for DRV8311 range
from 0 to 3 and 15 (general call address).


**Address Bits (A)** : A tSPI secondary device takes 8-bit register address whereas SPI secondary device takes
6-bit register address. Each tSPI secondary device has two dedicated 8-bit address pointers, one for read and
one for write. During a sequential read transaction, the read address pointer gets incremented automatically.
During a sequential write transaction, both write address pointer and read address pointer will be incremented
automatically.


**Parity Bit (P)** : Both header and data fields of a SPI/tSPI input data frame include a parity bit for single bit error
detection. The parity scheme used is even parity i.e., the number of ones in a block of 16-bits (including the
parity bit) is even. Data will be written to the internal registers only if the parity check is successful. During a read
operation, the tSPI secondary device inserts a parity bit at the MSB of read data. Parity checks can be enabled
or disabled by configuring the SPI_PEN bit of SYS_CTRL register. Parity checks are disabled by default.


**Note**
_Though parity checks are disabled by default, TI recommends enabling parity checks to safeguard_
_against single-bit errors._


**Error Handling**


**Parity Error** : Upon detecting a parity error, the secondary device responds in the following ways. Parity error
gets latched and reported on nFAULT. The error status is available for read on SPI_PARITY field of SYS_STS
register. A parity error in the header will not prevent the secondary device from responding with data. The
SDO will be driven by the secondary device being addressed. Updates to write address pointer and the device
registers will be ignored when parity error is detected. In a sequential write, upon detection of parity error any
subsequent register writes will be ignored.


**Frame Error** :Any incomplete tSPI Frame will be reported as Frame error. If the number of tSPI clock cycles is
not a multiple of 16, then the transfer is considered to be incomplete. Frame errors will be latched in FRM_ERR
field of SYS_STS register and indicated on nFAULT.


**SPI Read / Write Sequence**


**SPI Read Sequence** : The SPI read transaction comprises of an 8-bit header (R/W - 1 bit, Address - 6 bits,
and party -1 bit) followed by 16-bit dummy data words. Upon receiving the first byte of header, the secondary
device responds with an 8-bit device status information. The read address pointer gets updated immediately
after receiving the address field of the header. The read address from the header acts as the starting address for
the register reads. The read address pointer gets incremented automatically upon completion of a 16-bit transfer.
The length of data transfer is not restricted by the secondary device. The secondary device responds with data
as long as the primary device transmits dummy words. If parity error check is enabled, the MSB of read data will
be replaced with computed parity bit


**SPI Write Sequence** : SPI write transaction comprises of an 8-bit header followed by 16-bit data words to be
written into the register bank. Similar to a read transaction, the addressed secondary device responds with an
8-bit device status information upon receiving the first byte of header. Once the header bytes are received,
the write address pointer gets updated. The write address from the header acts as the starting address for
sequential register writes. The read address pointer will retain the address of the register being read in the
previous tSPI transaction. The length of data transfer is not restricted by the secondary device. Both read and
write address pointers will be incremented automatically upon completion of a 16-bit transfer. While receiving
data from the primary device, the SDO will be driven with the register data addressed by read address pointer.


**tSPI Communication Sequence**


The tSPI interface is similar to regular SPI interface in functionality but add support for multiple devices under
the same Chip Select (nSCS). Any existing SPI primary device would be able to communicate with the tSPI
secondary devices with modifications in the frame format. A valid tSPI frame must meet the following conditions
(similar to SPI interface):


48 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)




 - The SCLK pin should be low when the nSCS pin transitions from high to low and from low to high. A high to
low transition at the nSCS pin is the start of frame and a low to high transition is the end of the frame.

 - When the nSCS pin is pulled high, any signals at the SCLK and SDI pins are ignored and the SDO pin is
placed in the Hi-Z state.

 - Data is captured on the falling edge of the SCLK signal and data is driven on the rising edge of the SCLK
signal.

 - The most significant bit (MSB) is shifted in and out first.

 - A minimum of 16 SCLK cycles must occur for transaction to be valid & the number of SCLK cycles in a single
transaction must me a multiple of 16.

 - If the data word sent to the SDI pin is not a multiple of 16 bits, a frame error occurs and the excess SCLK
cycles are ignored.


AD0 AD1






























|M<br>M|CS<br>MCLK<br>MO<br>CU<br>I|Col3|Col4|Col5|Col6|
|---|---|---|---|---|---|
|**M**<br>M|**CU**<br>CS<br>I<br>MCLK<br>MO|||||
|**M**<br>M|**CU**<br>CS<br>I<br>MCLK<br>MO|||||
|**M**<br>M|**CU**<br>CS<br>I<br>MCLK<br>MO|||||
|**M**<br>M|**CU**<br>CS<br>I<br>MCLK<br>MO|||||
|**M**<br>M|**CU**<br>CS<br>I<br>MCLK<br>MO|||||
|**M**<br>M|**CU**<br>CS<br>I<br>MCLK<br>MO|||||
|**M**<br>M|**CU**<br>CS<br>I<br>MCLK<br>MO|||||
|**M**<br>M|**CU**<br>CS<br>I<br>MCLK<br>MO|||||



**Figure 8-34. tSPI Block Diagram with Multiple Devices on Same Chip Select**


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 49


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


AD0 AD1































**Figure 8-35. tSPI with PWM_SYNC**


**tSPI Read Sequence** : A tSPI read transaction has a 16-bit header (R/W - 1 bit, Secondary device ID - 4 bits,
Address - 8 bits, reserved -2 bits and party -1 bit) followed by 16-bit dummy data words. Upon receiving the
first byte of header, the secondary device being addressed with matching secondary device ID field (configured
using AD0 and AD1 pins), responds with an 8-bit device status information. The read address from the header
acts as the starting address for the register reads. The address gets incremented automatically upon completion
of a 16-bit transfer. The length of data transfer is not restricted by the secondary device. The secondary device
responds with data as long as the primary device transmits dummy words. If parity error check is enabled, the
MSB of read data will be replaced with computed parity bit.


**tSPI Write Sequence** : A tSPI write transaction has a 16-bit header followed by 16-bit data words to be written
into the register bank. Similar to a read transaction, the addressed secondary device responds with an 8-bit
device status information upon receiving the first byte of header. The write address from the header acts as
the starting address for sequential register writes. The length of data transfer is not restricted by the secondary
device. Both write and read address pointers will be incremented automatically upon completion of a 16-bit
transfer. While receiving data from the primary device, the SDO will be driven with the register data addressed
by read address pointer


**tSPI Read Address Update Sequence** : The independent read and write address pointers in the secondary
device would allow reading data from one set of registers while writing data to another set of registers. To
achieve this, the primary device should first send a read address update frame before the tSPI write transaction.
A read address frame is nothing but just the tSPI read sequence with just the header. The first tSPI transaction


50 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



updates the read address pointer to desired register address. The second tSPI transaction is a register write
sequence. During this sequence, the data send on SDO by the secondary device will be from the register
pointed by read address pointer which was initialized in the previous tSPI read sequence.


The tSPI read/write sequence with parity is shown in Figure 8-36. The SPI frame header is marked as
CMD[15:8] and CMD[7:0].


Read address update SPI_PEN=0, R/W=1


CMD[15:8] CMD[7:0]

|Col1|DEV STS<br>_|
|---|---|
|||



Single Read – 16-bit SPI_PEN=0, R/W=1


CMD[15:8] CMD[7:0] DUMMY


|Col1|DEV STS<br>_|RDATA[15:0]|
|---|---|---|
||||



Single Write with parity -16-bit



SPI_PEN=0, R/W=0



CMD[15:8] CMD[7:0] P WDATA[15:0]


|Col1|DEV STS<br>_|RDATA[15:0]|
|---|---|---|
||||



Multi-Write with parity – 2x16-bit



DLEN=0, CE=1, R/W =0



CMD[15:8] CMD[7:0] P WDATA0[15:0] P WDATA1[15:0]


|Col1|DEV STS<br>_|RDATA0[15:0]|RDATA1[15:0]|
|---|---|---|---|
|||||



Multi-Write with parity – 3x16-bit



DLEN=1, CE=1, R/W =0



CMD[15:8] CMD[7:0] P WDATA0[15:0] P WDATA1[15:0] P WDATA2[15:0]


|Col1|DEV STS<br>_|RDATA0[15:0]|RDATA1[15:0]|RDATA2[15:0]|
|---|---|---|---|---|
||||||



Multi-Write with parity – 4x16-bit



DLEN=2, CE=1, R/W =0



CMD[15:8] CMD[7:0] P WDATA0[15:0] P WDATA1[15:0] P WDATA2[15:0] P WDATA3[15:0]

|Col1|DEV STS<br>_|RDATA0[15:0]|RDATA1[15:0]|RDATA2[15:0]|RDATA3[15:0]|
|---|---|---|---|---|---|
|||||||



**Figure 8-36. tSPI Read/Write with Parity**


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 51


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**9 DRV8311 Registers**


DRV8311 Registers lists the memory-mapped registers for the DRV8311 registers. All register offset addresses
not listed in DRV8311 Registers should be considered as reserved locations and the register contents should not
be modified.


**Table 9-1. DRV8311 Registers**





Complex bit access types are encoded to fit into small table cells. DRV8311 Access Type Codes shows the
codes that are used for access types in this section.


**Table 9-2. DRV8311 Access Type Codes**







|AccessType|Code|Description|
|---|---|---|
|**Read Type**|**Read Type**|**Read Type**|
|R|R|Read|
|R-0|R<br>-0|Read<br>Returns 0s|
|**Write Type**|**Write Type**|**Write Type**|
|W|W|Write|
|**Reset or Default Value**|**Reset or Default Value**|**Reset or Default Value**|
|-_n_||Value after reset or the default<br>value|


52 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**9.1 DEV_STS1 Register (Offset = 0h) [Reset = 0080h]**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



DEV_STS1 is shown in DEV_STS1 Register and described in DEV_STS1 Register Field Descriptions.


Return to the DRV8311 Registers.


Device Status 1 Register


**Figure 9-1. DEV_STS1 Register**

|15 14 13 12 11 10 9 8|Col2|Col3|Col4|Col5|Col6|Col7|
|---|---|---|---|---|---|---|
|Parity_bit|RESERVED|RESERVED|RESERVED|RESERVED|RESERVED|OTP_FLT|
|R-0h<br>R-0-0h<br>R-0h|R-0h<br>R-0-0h<br>R-0h|R-0h<br>R-0-0h<br>R-0h|R-0h<br>R-0-0h<br>R-0h|R-0h<br>R-0-0h<br>R-0h|R-0h<br>R-0-0h<br>R-0h|R-0h<br>R-0-0h<br>R-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|RESET|SPI_FLT|OCP|RESERVED|UVP|OT|FAULT|
|R-1h<br>R-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0h|R-1h<br>R-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0h|R-1h<br>R-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0h|R-1h<br>R-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0h|R-1h<br>R-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0h|R-1h<br>R-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0h|R-1h<br>R-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0h|



**Table 9-3. DEV_STS1 Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-9|RESERVED|R-0|0h|Reserved|
|8|OTP_FLT|R|0h|OTP read fault<br>0h = No OTP read fault is detected<br>1h = OTP read fault detected|
|7|RESET|R|1h|Supply Power On Reset Status<br>0h = No power on reset condition is detected<br>1h = Power-on-reset condition is detected|
|6|SPI_FLT|R|0h|SPI Fault Status<br>0h = No SPI communication fault is detected<br>1h = SPI communication fault is detected|
|5|OCP|R|0h|Driver Overcurrent Protection Status<br>0h = No overcurrent condition is detected<br>1h = Overcurrent condition is detected|
|4-3|RESERVED|R|0h|Reserved|
|2|UVP|R|0h|Supply Undervoltage Status<br>0h = No undervoltage voltage condition is detected on CP, AVDD or<br>VIN_AVDD<br>1h = Undervoltage voltage condition is detected on CP, AVDD or<br>VIN_AVDD|
|1|OT|R|0h|Overtemperature Fault Status<br>0h = No overtemperature warning / shutdown is detected<br>1h = Overtemperature warning / shutdown is detected|
|0|FAULT|R|0h|Device Fault Status<br>0h = No fault condition is detected<br>1h = Fault condition is detected|



Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 53


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**9.2 OT_STS Register (Offset = 4h) [Reset = 0000h]**


OT_STS is shown in OT_STS Register and described in OT_STS Register Field Descriptions.


Return to the DRV8311 Registers.


Over Temperature Status Register


**Figure 9-2. OT_STS Register**

|15 14 13 12 11 10 9 8|Col2|Col3|Col4|Col5|
|---|---|---|---|---|
|Parity_bit|RESERVED|RESERVED|RESERVED|RESERVED|
|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|RESERVED|RESERVED|OTS_AVDD|OTW|OTSD|
|R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0h|



**Table 9-4. OT_STS Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-3|RESERVED|R-0|0h|Reserved|
|2|OTS_AVDD|R|0h|AVDD LDO Overtemperature Fault Status<br>0h = No overtemperature shutdown near AVDD is detected<br>1h = Overtemperature shutdown near AVDD is detected|
|1|OTW|R|0h|Overtemperature Warning Status<br>0h = No overtemperature warning is detected<br>1h = Overtemperature warning is detected|
|0|OTSD|R|0h|Overtemperature Shutdown Fault Status<br>0h = No overtemperature shutdown is detected<br>1h = Overtemperature shutdown is detected|



54 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**9.3 SUP_STS Register (Offset = 5h) [Reset = 0000h]**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



SUP_STS is shown in SUP_STS Register and described in SUP_STS Register Field Descriptions.


Return to the DRV8311 Registers.


Supply Status Register


**Figure 9-3. SUP_STS Register**

|15 14 13 12 11 10 9 8|Col2|Col3|Col4|Col5|Col6|Col7|Col8|
|---|---|---|---|---|---|---|---|
|Parity_bit|RESERVED|RESERVED|RESERVED|RESERVED|RESERVED|RESERVED|RESERVED|
|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|RESERVED|RESERVED|CSAREF_UV|CP_UV|RESERVED|AVDD_UV|RESERVED|VINAVDD_UV|
|R-0-0h<br>R-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0-0h<br>R-0h|



**Table 9-5. SUP_STS Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-6|RESERVED|R-0|0h|Reserved|
|5|CSAREF_UV|R|0h|CSA REF Undervoltage Fault Status<br>0h = No CSAREF undervoltage is detected<br>1h = CSAREF undervoltage is detected|
|4|CP_UV|R|0h|Charge Pump Undervoltage Fault Status<br>0h = No charge pump undervoltage is detected<br>1h = Charge pump undervoltage is detected|
|3|RESERVED|R-0|0h|Reserved|
|2|AVDD_UV|R|0h|AVDD LDO Undervoltage Fault Status<br>0h = No AVDD output undervoltage is detected<br>1h = AVDD output undervoltage is detected|
|1|RESERVED|R-0|0h|Reserved|
|0|VINAVDD_UV|R|0h|VIN_AVDD Undervoltage Fault Status<br>0h = No AVDD supply input undervoltage is detected<br>1h = AVDD supply input undervoltage is detected|



Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 55


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**9.4 DRV_STS Register (Offset = 6h) [Reset = 0000h]**


DRV_STS is shown in DRV_STS Register and described in DRV_STS Register Field Descriptions.


Return to the DRV8311 Registers.


Driver Status Register


**Figure 9-4. DRV_STS Register**

|15 14 13 12 11 10 9 8|Col2|Col3|Col4|Col5|Col6|Col7|Col8|
|---|---|---|---|---|---|---|---|
|Parity_bit|RESERVED|RESERVED|RESERVED|RESERVED|RESERVED|RESERVED|RESERVED|
|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|RESERVED|OCPC_HS|OCPB_HS|OCPA_HS|RESERVED|OCPC_LS|OCPB_LS|OCPA_LS|
|R-0-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0h<br>R-0h|



**Table 9-6. DRV_STS Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-7|RESERVED|R-0|0h|Reserved|
|6|OCPC_HS|R|0h|Overcurrent Status on High-side MOSFET of OUTC<br>0h = No overcurrent detected on high-side MOSFET of OUTC<br>1h = Overcurrent detected on high-side MOSFET of OUTC|
|5|OCPB_HS|R|0h|Overcurrent Status on High-side MOSFET of OUTB<br>0h = No overcurrent detected on high-side MOSFET of OUTB<br>1h = Overcurrent detected on high-side MOSFET of OUTB|
|4|OCPA_HS|R|0h|Overcurrent Status on High-side MOSFET of OUTA<br>0h = No overcurrent detected on high-side MOSFET of OUTA<br>1h = Overcurrent detected on high-side MOSFET of OUTA|
|3|RESERVED|R-0|0h|Reserved|
|2|OCPC_LS|R|0h|Overcurrent Status on Low-side MOSFET of OUTC<br>0h = No overcurrent detected on low-side MOSFET of OUTC<br>1h = Overcurrent detected on low-side MOSFET of OUTC|
|1|OCPB_LS|R|0h|Overcurrent Status on Low-side MOSFET of OUTB<br>0h = No overcurrent detected on low-side MOSFET of OUTB<br>1h = Overcurrent detected on low-side MOSFET of OUTB|
|0|OCPA_LS|R|0h|Overcurrent Status on Low-side MOSFET of OUTA<br>0h = No overcurrent detected on low-side MOSFET of OUTA<br>1h = Overcurrent detected on low-side MOSFET of OUTA|



56 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**9.5 SYS_STS Register (Offset = 7h) [Reset = 0000h]**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



SYS_STS is shown in SYS_STS Register and described in SYS_STS Register Field Descriptions.


Return to the DRV8311 Registers.


System Status Register


**Figure 9-5. SYS_STS Register**

|15 14 13 12 11 10 9 8|Col2|Col3|Col4|Col5|Col6|Col7|
|---|---|---|---|---|---|---|
|Parity_bit|RESERVED|RESERVED|RESERVED|RESERVED|RESERVED|RESERVED|
|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|RESERVED|RESERVED|OTPLD_ERR|RESERVED|SPI_PARITY|BUS_CNT|FRM_ERR|
|R-0-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0h<br>R-0h|R-0-0h<br>R-0h<br>R-0-0h<br>R-0h<br>R-0h<br>R-0h|



**Table 9-7. SYS_STS Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-5|RESERVED|R-0|0h|Reserved|
|4|OTPLD_ERR|R|0h|OTP Read Error<br>0h = No OTP read error is detected<br>1h = OTP read error is detected|
|3|RESERVED|R-0|0h|Reserved|
|2|SPI_PARITY|R|0h|SPI Parity Error<br>0h = No SPI Parity Error is detected<br>1h = SPI Parity Error is detected|
|1|BUS_CNT|R|0h|SPI Bus Contention Error<br>0h = No SPI Bus Contention Error is detected<br>1h = SPI Bus Contention Error is detected|
|0|FRM_ERR|R|0h|SPI Frame Error<br>0h = No SPI Frame Error is detected<br>1h = SPI Frame Error is detected|



Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 57


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**9.6 PWM_SYNC_PRD Register (Offset = Ch) [Reset = 0000h]**


PWM_SYNC_PRD is shown in PWM_SYNC_PRD Register and described in PWM_SYNC_PRD Register Field
Descriptions.


Return to the DRV8311 Registers.


PWM Sync Period Register


**Figure 9-6. PWM_SYNC_PRD Register**

|15 14 13 12 11 10 9 8|Col2|Col3|
|---|---|---|
|Parity_bit|RESERVED|PWM_SYNC_PRD|
|R-0h<br>R-0-0h<br>R-0h|R-0h<br>R-0-0h<br>R-0h|R-0h<br>R-0-0h<br>R-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|PWM_SYNC_PRD|PWM_SYNC_PRD|PWM_SYNC_PRD|
|R-0h|R-0h|R-0h|



**Table 9-8. PWM_SYNC_PRD Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-12|RESERVED|R-0|0h|Reserved|
|11-0|PWM_SYNC_PRD|R|0h|12-bit output indicating period of PWM_SYNC signal|



58 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**9.7 FLT_MODE Register (Offset = 10h) [Reset = 0115h]**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



FLT_MODE is shown in FLT_MODE Register and described in FLT_MODE Register Field Descriptions.


Return to the DRV8311 Registers.


Fault Mode Register


**Figure 9-7. FLT_MODE Register**

|15 14 13 12 11 10 9 8|Col2|Col3|Col4|Col5|
|---|---|---|---|---|
|Parity_bit|RESERVED|RESERVED|RESERVED|OTPFLT_MOD<br>E|
|R-0h<br>R-0-0h<br>R/W-1h|R-0h<br>R-0-0h<br>R/W-1h|R-0h<br>R-0-0h<br>R/W-1h|R-0h<br>R-0-0h<br>R/W-1h|R-0h<br>R-0-0h<br>R/W-1h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|SPIFLT_MODE|OCP_MODE|UVP_MODE|OTSD_MODE|OTSD_MODE|
|R/W-0h<br>R/W-1h<br>R/W-1h<br>R/W-1h|R/W-0h<br>R/W-1h<br>R/W-1h<br>R/W-1h|R/W-0h<br>R/W-1h<br>R/W-1h<br>R/W-1h|R/W-0h<br>R/W-1h<br>R/W-1h<br>R/W-1h|R/W-0h<br>R/W-1h<br>R/W-1h<br>R/W-1h|



**Table 9-9. FLT_MODE Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-9|RESERVED|R-0|0h|Reserved|
|8|OTPFLT_MODE|R/W|1h|System Fault Mode.<br>0h = OTP read fault is enabled<br>1h = OTP read fault is disabled|
|7|SPIFLT_MODE|R/W|0h|SPI Fault mode<br>0h = SPI Fault is enabled<br>1h = SPI Fault is disabled|
|6-4|OCP_MODE|R/W|1h|Overcurrent Protection Fault mode<br>0h = Report on nFault, predriver HiZ, auto recovery with Slow Retry<br>time (in ms)<br>1h = Report on nFault, predriver HiZ, auto recovery with Fast Retry<br>time (in ms)<br>2h = Report on nFault, predriver HiZ, Latched Fault<br>3h = Report on nFault, No action on predriver<br>4h = Reserved<br>5h = Reserved<br>6h = Reserved<br>7h = Disabled|
|3-2|UVP_MODE|R/W|1h|Undervoltage Protection Fault mode<br>0h = Report on nFault, predriver HiZ, auto recovery with Slow Retry<br>time (in ms)<br>1h = Report on nFault, predriver HiZ, auto recovery with Fast Retry<br>time (in ms)<br>2h = Reserved<br>3h = Reserved|
|1-0|OTSD_MODE|R/W|1h|Overtemperature Fault mode<br>0h = Report on nFault, predriver HiZ, auto recovery with Slow Retry<br>time (in ms)<br>1h = Report on nFault, predriver HiZ, auto recovery with Fast Retry<br>time (in ms)<br>2h = Reserved<br>3h = Reserved|



Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 59


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**9.8 SYSF_CTRL Register (Offset = 12h) [Reset = 0515h]**


SYSF_CTRL is shown in SYSF_CTRL Register and described in SYSF_CTRL Register Field Descriptions.


Return to the DRV8311 Registers.


System Fault Control Register


**Figure 9-8. SYSF_CTRL Register**







|15 14 13 12 11 10 9 8|Col2|Col3|Col4|Col5|Col6|Col7|Col8|
|---|---|---|---|---|---|---|---|
|Parity_bit|RESERVED|RESERVED|RESERVED|RESERVED|OTAVDD_EN|OTW_EN|RESERVED|
|R-0h<br>R-0-0h<br>R/W-1h<br>R/W-0h<br>R-0-4h|R-0h<br>R-0-0h<br>R/W-1h<br>R/W-0h<br>R-0-4h|R-0h<br>R-0-0h<br>R/W-1h<br>R/W-0h<br>R-0-4h|R-0h<br>R-0-0h<br>R/W-1h<br>R/W-0h<br>R-0-4h|R-0h<br>R-0-0h<br>R/W-1h<br>R/W-0h<br>R-0-4h|R-0h<br>R-0-0h<br>R/W-1h<br>R/W-0h<br>R-0-4h|R-0h<br>R-0-0h<br>R/W-1h<br>R/W-0h<br>R-0-4h|R-0h<br>R-0-0h<br>R/W-1h<br>R/W-0h<br>R-0-4h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|RESERVED|RESERVED|CSAREFUV_E<br>N|RESERVED|RESERVED|RESERVED|RESERVED|RESERVED|
|R-0-4h<br>R/W-0h<br>R/W-1h<br>R-0-0h<br>R/W-1h<br>R-0-0h<br>R/W-1h|R-0-4h<br>R/W-0h<br>R/W-1h<br>R-0-0h<br>R/W-1h<br>R-0-0h<br>R/W-1h|R-0-4h<br>R/W-0h<br>R/W-1h<br>R-0-0h<br>R/W-1h<br>R-0-0h<br>R/W-1h|R-0-4h<br>R/W-0h<br>R/W-1h<br>R-0-0h<br>R/W-1h<br>R-0-0h<br>R/W-1h|R-0-4h<br>R/W-0h<br>R/W-1h<br>R-0-0h<br>R/W-1h<br>R-0-0h<br>R/W-1h|R-0-4h<br>R/W-0h<br>R/W-1h<br>R-0-0h<br>R/W-1h<br>R-0-0h<br>R/W-1h|R-0-4h<br>R/W-0h<br>R/W-1h<br>R-0-0h<br>R/W-1h<br>R-0-0h<br>R/W-1h|R-0-4h<br>R/W-0h<br>R/W-1h<br>R-0-0h<br>R/W-1h<br>R-0-0h<br>R/W-1h|


**Table 9-10. SYSF_CTRL Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-11|RESERVED|R-0|0h|Reserved|
|10|OTAVDD_EN|R/W|1h|AVDD Overtemperature Fault Enable<br>0h = Overtemperature protection near AVDD is disabled<br>1h = Overtemperature protection near AVDD is enabled|
|9|OTW_EN|R/W|0h|Overtemperature Warning Fault Enable<br>0h = Over temperature warning reporting on nFAULT is disabled<br>1h = Over temperature warning reporting on nFAULT is enabled|
|8-6|RESERVED|R-0|4h|Reserved|
|5|CSAREFUV_EN|R/W|0h|CSAREF Undervoltage Fault Enable<br>0h = CSAREF undervoltage lockout is disabled<br>1h = CSAREF undervoltage lockout is enabled|
|4|RESERVED|R/W|1h|Reserved|
|3|RESERVED|R-0|0h|Reserved|
|2|RESERVED|R/W|1h|Reserved|
|1|RESERVED|R-0|0h|Reserved|
|0|RESERVED|R/W|1h|Reserved|



60 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**9.9 DRVF_CTRL Register (Offset = 13h) [Reset = 0030h]**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



DRVF_CTRL is shown in DRVF_CTRL Register and described in DRVF_CTRL Register Field Descriptions.


Return to the DRV8311 Registers.


Driver Fault Control Register


**Figure 9-9. DRVF_CTRL Register**

|15 14 13 12 11 10 9 8|Col2|Col3|Col4|Col5|Col6|
|---|---|---|---|---|---|
|Parity_bit|RESERVED|RESERVED|RESERVED|RESERVED|RESERVED|
|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|RESERVED|RESERVED|OCP_DEG|OCP_TBLANK|RESERVED|OCP_LVL|
|R-0-0h<br>R/W-3h<br>R/W-0h<br>R-0-0h<br>R/W-0h|R-0-0h<br>R/W-3h<br>R/W-0h<br>R-0-0h<br>R/W-0h|R-0-0h<br>R/W-3h<br>R/W-0h<br>R-0-0h<br>R/W-0h|R-0-0h<br>R/W-3h<br>R/W-0h<br>R-0-0h<br>R/W-0h|R-0-0h<br>R/W-3h<br>R/W-0h<br>R-0-0h<br>R/W-0h|R-0-0h<br>R/W-3h<br>R/W-0h<br>R-0-0h<br>R/W-0h|



**Table 9-11. DRVF_CTRL Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-6|RESERVED|R-0|0h|Reserved|
|5-4|OCP_DEG|R/W|3h|OCP Deglitch time<br>0h = OCP deglitch time is 0.2 µs<br>1h = OCP deglitch time is 0.5 µs<br>2h = OCP deglitch time is 0.8 µs<br>3h = OCP deglitch time is 1 µs|
|3-2|OCP_TBLANK|R/W|0h|OCP Blanking time<br>0h = OCP blanking time is 0.2 µs<br>1h = OCP blanking time is 0.5 µs<br>2h = OCP blanking time is 0.8 µs<br>3h = OCP blanking time is 1 µs|
|1|RESERVED|R-0|0h|Reserved|
|0|OCP_LVL|R/W|0h|OCP Level Settings<br>0h = OCP level is 9 A (TYP)<br>1h = OCP level is 5 A (TYP)|



Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 61


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**9.10 FLT_TCTRL Register (Offset = 16h) [Reset = 0003h]**


FLT_TCTRL is shown in FLT_TCTRL Register and described in FLT_TCTRL Register Field Descriptions.


Return to the DRV8311 Registers.


Fault Timing Control Register


**Figure 9-10. FLT_TCTRL Register**

|15 14 13 12 11 10 9 8|Col2|Col3|Col4|
|---|---|---|---|
|Parity_bit|RESERVED|RESERVED|RESERVED|
|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|RESERVED|RESERVED|SLOW_TRETRY|FAST_TRETRY|
|R-0-0h<br>R/W-0h<br>R/W-3h|R-0-0h<br>R/W-0h<br>R/W-3h|R-0-0h<br>R/W-0h<br>R/W-3h|R-0-0h<br>R/W-0h<br>R/W-3h|



**Table 9-12. FLT_TCTRL Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-4|RESERVED|R-0|0h|Reserved|
|3-2|SLOW_TRETRY|R/W|0h|Slow Recovery Retry Time from Fault Condition<br>0h = 0.5s<br>1h = 1s<br>2h = 2s<br>3h = 5s|
|1-0|FAST_TRETRY|R/W|3h|Fast Recovery Retry Time from Fault Condition<br>0h = 0.5ms<br>1h = 1ms<br>2h = 2ms<br>3h = 5ms|



62 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**9.11 FLT_CLR Register (Offset = 17h) [Reset = 0000h]**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



FLT_CLR is shown in FLT_CLR Register and described in FLT_CLR Register Field Descriptions.


Return to the DRV8311 Registers.


Fault Clear Register


**Figure 9-11. FLT_CLR Register**

|15 14 13 12 11 10 9 8|Col2|Col3|
|---|---|---|
|Parity_bit|RESERVED|RESERVED|
|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|RESERVED|RESERVED|FLT_CLR|
|R-0-0h<br>W-0h|R-0-0h<br>W-0h|R-0-0h<br>W-0h|



**Table 9-13. FLT_CLR Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-1|RESERVED|R-0|0h|Reserved|
|0|FLT_CLR|W|0h|Clear Fault<br>0h = No clear fault command is issued<br>1h = To clear the latched fault bits. This bit automatically resets after<br>being written.|



Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 63


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**9.12 PWMG_PERIOD Register (Offset = 18h) [Reset = 0000h]**


PWMG_PERIOD is shown in PWMG_PERIOD Register and described in PWMG_PERIOD Register Field
Descriptions.


Return to the DRV8311 Registers.


PWM_GEN Period Register


**Figure 9-12. PWMG_PERIOD Register**

|15 14 13 12 11 10 9 8|Col2|Col3|
|---|---|---|
|Parity_bit|RESERVED|PWM_PRD_OUT|
|R-0h<br>R-0-0h<br>R/W-0h|R-0h<br>R-0-0h<br>R/W-0h|R-0h<br>R-0-0h<br>R/W-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|PWM_PRD_OUT|PWM_PRD_OUT|PWM_PRD_OUT|
|R/W-0h|R/W-0h|R/W-0h|



**Table 9-14. PWMG_PERIOD Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-12|RESERVED|R-0|0h|Reserved|
|11-0|PWM_PRD_OUT|R/W|0h|12-bit Period for output PWM signals in PWM Generation Mode|



64 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**9.13 PWMG_A_DUTY Register (Offset = 19h) [Reset = 0000h]**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



PWMG_A_DUTY is shown in PWMG_A_DUTY Register and described in PWMG_A_DUTY Register Field
Descriptions.


Return to the DRV8311 Registers.


PWM_GEN A Duty Register


**Figure 9-13. PWMG_A_DUTY Register**

|15 14 13 12 11 10 9 8|Col2|Col3|
|---|---|---|
|Parity_bit|RESERVED|PWM_DUTY_OUTA|
|R-0h<br>R-0-0h<br>R/W-0h|R-0h<br>R-0-0h<br>R/W-0h|R-0h<br>R-0-0h<br>R/W-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|PWM_DUTY_OUTA|PWM_DUTY_OUTA|PWM_DUTY_OUTA|
|R/W-0h|R/W-0h|R/W-0h|



**Table 9-15. PWMG_A_DUTY Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-12|RESERVED|R-0|0h|Reserved|
|11-0|PWM_DUTY_OUTA|R/W|0h|12-bit Duty Cycle for Phase A output in PWM Generation Mode|



Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 65


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**9.14 PWMG_B_DUTY Register (Offset = 1Ah) [Reset = 0000h]**


PWMG_B_DUTY is shown in PWMG_B_DUTY Register and described in PWMG_B_DUTY Register Field
Descriptions.


Return to the DRV8311 Registers.


PWM_GEN B Duty Register


**Figure 9-14. PWMG_B_DUTY Register**

|15 14 13 12 11 10 9 8|Col2|Col3|
|---|---|---|
|Parity_bit|RESERVED|PWM_DUTY_OUTB|
|R-0h<br>R-0-0h<br>R/W-0h|R-0h<br>R-0-0h<br>R/W-0h|R-0h<br>R-0-0h<br>R/W-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|PWM_DUTY_OUTB|PWM_DUTY_OUTB|PWM_DUTY_OUTB|
|R/W-0h|R/W-0h|R/W-0h|



**Table 9-16. PWMG_B_DUTY Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-12|RESERVED|R-0|0h|Reserved|
|11-0|PWM_DUTY_OUTB|R/W|0h|12-bit Duty Cycle for Phase B output in PWM Generation Mode|



66 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**9.15 PWMG_C_DUTY Register (Offset = 1Bh) [Reset = 0000h]**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



PWMG_C_DUTY is shown in PWMG_C_DUTY Register and described in PWMG_C_DUTY Register Field
Descriptions.


Return to the DRV8311 Registers.


PWM_GEN C Duty Register


**Figure 9-15. PWMG_C_DUTY Register**

|15 14 13 12 11 10 9 8|Col2|Col3|
|---|---|---|
|Parity_bit|RESERVED|PWM_DUTY_OUTC|
|R-0h<br>R-0-0h<br>R/W-0h|R-0h<br>R-0-0h<br>R/W-0h|R-0h<br>R-0-0h<br>R/W-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|PWM_DUTY_OUTC|PWM_DUTY_OUTC|PWM_DUTY_OUTC|
|R/W-0h|R/W-0h|R/W-0h|



**Table 9-17. PWMG_C_DUTY Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-12|RESERVED|R-0|0h|Reserved|
|11-0|PWM_DUTY_OUTC|R/W|0h|12-bit Duty Cycle for Phase C output in PWM Generation Mode|



Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 67


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**9.16 PWM_STATE Register (Offset = 1Ch) [Reset = 0777h]**


PWM_STATE is shown in PWM_STATE Register and described in PWM_STATE Register Field Descriptions.


Return to the DRV8311 Registers.


PWM State Register


**Figure 9-16. PWM_STATE Register**

|15 14 13 12 11 10 9 8|Col2|Col3|Col4|
|---|---|---|---|
|Parity_bit|RESERVED|RESERVED|PWMC_STATE|
|R-0h<br>R-0-0h<br>R/W-7h|R-0h<br>R-0-0h<br>R/W-7h|R-0h<br>R-0-0h<br>R/W-7h|R-0h<br>R-0-0h<br>R/W-7h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|RESERVED|PWMB_STATE|RESERVED|PWMA_STATE|
|R-0-0h<br>R/W-7h<br>R-0-0h<br>R/W-7h|R-0-0h<br>R/W-7h<br>R-0-0h<br>R/W-7h|R-0-0h<br>R/W-7h<br>R-0-0h<br>R/W-7h|R-0-0h<br>R/W-7h<br>R-0-0h<br>R/W-7h|



**Table 9-18. PWM_STATE Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-11|RESERVED|R-0|0h|Reserved|
|10-8|PWMC_STATE|R/W|7h|Phase C Driver Output control<br>0h = High Side is OFF, Low Side is OFF<br>1h = High Side is OFF, Low Side is forced ON<br>2h = High Side is forced ON, Low Side is OFF<br>3h = Reserved<br>4h = Reserved<br>5h = High Side is OFF, Low Side PWM<br>6h = High Side PWM, Low Side is OFF<br>7h = High Side PWM, Low Side !PWM|
|7|RESERVED|R-0|0h|Reserved|
|6-4|PWMB_STATE|R/W|7h|Phase B Driver Output control<br>0h = High Side is OFF, Low Side is OFF<br>1h = High Side is OFF, Low Side is forced ON<br>2h = High Side is forced ON, Low Side is OFF<br>3h = Reserved<br>4h = Reserved<br>5h = High Side is OFF, Low Side PWM<br>6h = High Side PWM, Low Side is OFF<br>7h = High Side PWM, Low Side !PWM|
|3|RESERVED|R-0|0h|Reserved|
|2-0|PWMA_STATE|R/W|7h|Phase A Driver Output control<br>0h = High Side is OFF, Low Side is OFF<br>1h = High Side is OFF, Low Side is forced ON<br>2h = High Side is forced ON, Low Side is OFF<br>3h = Reserved<br>4h = Reserved<br>5h = High Side is OFF, Low Side PWM<br>6h = High Side PWM, Low Side is OFF<br>7h = High Side PWM, Low Side !PWM|



68 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**9.17 PWMG_CTRL Register (Offset = 1Dh) [Reset = 0000h]**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



PWMG_CTRL is shown in PWMG_CTRL Register and described in PWMG_CTRL Register Field Descriptions.


Return to the DRV8311 Registers.


PWM_GEN Control Register


**Figure 9-17. PWMG_CTRL Register**

|15 14 13 12 11 10 9 8|Col2|Col3|Col4|Col5|
|---|---|---|---|---|
|Parity_bit|RESERVED|RESERVED|PWM_EN|PWMCNTR_MODE|
|R-0h<br>R-0-0h<br>R/W-0h<br>R/W-0h|R-0h<br>R-0-0h<br>R/W-0h<br>R/W-0h|R-0h<br>R-0-0h<br>R/W-0h<br>R/W-0h|R-0h<br>R-0-0h<br>R/W-0h<br>R/W-0h|R-0h<br>R-0-0h<br>R/W-0h<br>R/W-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|PWM_OSC_SYNC|PWM_OSC_SYNC|SPICLK_FREQ_SYNC|SPICLK_FREQ_SYNC|SPISYNC_ACRCY|
|R/W-0h<br>R/W-0h<br>R/W-0h|R/W-0h<br>R/W-0h<br>R/W-0h|R/W-0h<br>R/W-0h<br>R/W-0h|R/W-0h<br>R/W-0h<br>R/W-0h|R/W-0h<br>R/W-0h<br>R/W-0h|



**Table 9-19. PWMG_CTRL Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-11|RESERVED|R-0|0h|Reserved|
|10|PWM_EN|R/W|0h|Enable 3X Internal mode PWM Generation<br>0h = PWM_GEN disabled<br>1h = PWM_GEN enabled|
|9-8|PWMCNTR_MODE|R/W|0h|PWM Gen counter mode<br>0h = Up and Down<br>1h = Up<br>2h = Down<br>3h = No action|
|7-5|PWM_OSC_SYNC|R/W|0h|Oscillator synchronization and PWM_SYNC control<br>0h = Oscillator synchronization is disable<br>1h = PWM_SYNC_PRD indicates period of PWM_SYNC signal and<br>can be used to calibrate PWM period<br>2h = PWM_SYNC used to set PWM period<br>3h = Oscillator synchronization is disable<br>4h = Oscillator synchronization is disable<br>5h = PWM_SYNC used for oscillator synchronization (only 20 kHz<br>frequency supported)<br>6h = PWM_SYNC used for oscillator synchronization and setting<br>PWM period (only 20 kHz frequency supported)<br>7h = SPI Clock pin SCLK used for oscillator synchronization<br>(Configure SPICLK_FREQ_SYNC)|
|4-2|SPICLK_FREQ_SYNC|R/W|0h|SPI Clock Frequency for synchronizing the Oscillator<br>0h = 1 MHz<br>1h = 1.25 MHz<br>2h = 2 MHz<br>3h = 2.5 MHz<br>4h = 4 MHz<br>5h = 5 MHz<br>6h = 8 MHz<br>7h = 10 MHz|



Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 69


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**Table 9-19. PWMG_CTRL Register Field Descriptions (continued)**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|1-0|SPISYNC_ACRCY|R/W|0h|Number of SPI Clock Cycle require for synchronizing the Oscillator<br>0h = 512 Clock Cycles (1%)<br>1h = 256 Clock Cycles (1%)<br>2h = 128 Clock Cycles (1%)<br>3h = 64 Clock Cycles (2%)|



70 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**9.18 PWM_CTRL1 Register (Offset = 20h) [Reset = 0007h]**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



PWM_CTRL1 is shown in PWM_CTRL1 Register and described in PWM_CTRL1 Register Field Descriptions.


Return to the DRV8311 Registers.


PWM Control Register 1


**Figure 9-18. PWM_CTRL1 Register**

|15 14 13 12 11 10 9 8|Col2|Col3|Col4|
|---|---|---|---|
|Parity_bit|RESERVED|RESERVED|RESERVED|
|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|RESERVED|RESERVED|SSC_DIS|PWM_MODE|
|R-0-0h<br>R/W-1h<br>R/W-3h|R-0-0h<br>R/W-1h<br>R/W-3h|R-0-0h<br>R/W-1h<br>R/W-3h|R-0-0h<br>R/W-1h<br>R/W-3h|



**Table 9-20. PWM_CTRL1 Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-3|RESERVED|R-0|0h|Reserved|
|2|SSC_DIS|R/W|1h|Disable Spread Spectrum Modulation for internal Oscillator<br>0h = Spread spectrum modulation is enabled<br>1h = Spread spectrum modulation is disabled|
|1-0|PWM_MODE|R/W|3h|PWM mode selection (The reset setting in DRV8311S is 00b and in<br>DRV8311P is 11b)<br>0h = 6x mode<br>1h = 6x mode<br>2h = 3x mode<br>3h = PWM Generation mode|



Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 71


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**9.19 DRV_CTRL Register (Offset = 22h) [Reset = 0000h]**


DRV_CTRL is shown in DRV_CTRL Register and described in DRV_CTRL Register Field Descriptions.


Return to the DRV8311 Registers.


Predriver control Register


**Figure 9-19. DRV_CTRL Register**

|15 14 13 12 11 10 9 8|Col2|Col3|Col4|
|---|---|---|---|
|Parity_bit|RESERVED|RESERVED|RESERVED|
|R-0h<br>R-0-0h<br>R/W-0h|R-0h<br>R-0-0h<br>R/W-0h|R-0h<br>R-0-0h<br>R/W-0h|R-0h<br>R-0-0h<br>R/W-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|DLYCMP_EN|TDEAD_CTRL|RESERVED|SLEW_RATE|
|R/W-0h<br>R/W-0h<br>R-0-0h<br>R/W-0h|R/W-0h<br>R/W-0h<br>R-0-0h<br>R/W-0h|R/W-0h<br>R/W-0h<br>R-0-0h<br>R/W-0h|R/W-0h<br>R/W-0h<br>R-0-0h<br>R/W-0h|



**Table 9-21. DRV_CTRL Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-12|RESERVED|R-0|0h|Reserved|
|11-8|RESERVED|R/W|0h|Reserved|
|7|DLYCMP_EN|R/W|0h|Driver Delay Compensation enable<br>0h = Driver Delay Compensation is disabled<br>1h = Driver Delay Compensation is enabled|
|6-4|TDEAD_CTRL|R/W|0h|Deadtime insertion control<br>0h = No deadtime (Handshake Only)<br>1h = 200ns<br>2h = 400ns<br>3h = 600ns<br>4h = 800ns<br>5h = 1us<br>6h = 1.2us<br>7h = 1.4us|
|3-2|RESERVED|R-0|0h|Reserved|
|1-0|SLEW_RATE|R/W|0h|Slew rate settings<br>0h = Slew rate is 35 V/µs<br>1h = Slew rate is 75 V/µs<br>2h = Slew rate is 180 V/µs<br>3h = Slew rate is 230 V/µs|



72 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**9.20 CSA_CTRL Register (Offset = 23h) [Reset = 0008h]**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



CSA_CTRL is shown in CSA_CTRL Register and described in CSA_CTRL Register Field Descriptions.


Return to the DRV8311 Registers.


CSA Control Register


**Figure 9-20. CSA_CTRL Register**

|15 14 13 12 11 10 9 8|Col2|Col3|Col4|Col5|
|---|---|---|---|---|
|Parity_bit|RESERVED|RESERVED|RESERVED|RESERVED|
|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|R-0h<br>R-0-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|RESERVED|RESERVED|CSA_EN|RESERVED|CSA_GAIN|
|R-0-0h<br>R/W-1h<br>R-0-0h<br>R/W-0h|R-0-0h<br>R/W-1h<br>R-0-0h<br>R/W-0h|R-0-0h<br>R/W-1h<br>R-0-0h<br>R/W-0h|R-0-0h<br>R/W-1h<br>R-0-0h<br>R/W-0h|R-0-0h<br>R/W-1h<br>R-0-0h<br>R/W-0h|



**Table 9-22. CSA_CTRL Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-4|RESERVED|R-0|0h|Reserved|
|3|CSA_EN|R/W|1h|Current Sense Amplifier Enable<br>0h = Current Sense Amplifier is disabled<br>1h = Current Sense Amplifier is enabled|
|2|RESERVED|R-0|0h|Reserved|
|1-0|CSA_GAIN|R/W|0h|Current Sense Amplifier Gain settings<br>0h = CSA gain is 0.25 V/A<br>1h = CSA gain is 0.5 V/A<br>2h = CSA gain is 1 V/A<br>3h = CSA gain is 2 V/A|



Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 73


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**9.21 SYS_CTRL Register (Offset = 3Fh) [Reset = 0000h]**


SYS_CTRL is shown in SYS_CTRL Register and described in SYS_CTRL Register Field Descriptions.


Return to the DRV8311 Registers.


System Control Register


**Figure 9-21. SYS_CTRL Register**

|15 14 13 12 11 10 9 8|Col2|Col3|Col4|Col5|Col6|
|---|---|---|---|---|---|
|Parity_bit|WRITE_KEY|WRITE_KEY|RESERVED|RESERVED|RESERVED|
|R-0h<br>W-0h<br>R-0-0h<br>R/W-0h|R-0h<br>W-0h<br>R-0-0h<br>R/W-0h|R-0h<br>W-0h<br>R-0-0h<br>R/W-0h|R-0h<br>W-0h<br>R-0-0h<br>R/W-0h|R-0h<br>W-0h<br>R-0-0h<br>R/W-0h|R-0h<br>W-0h<br>R-0-0h<br>R/W-0h|
|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|REG_LOCK|SPI_PEN|RESERVED|RESERVED|RESERVED|RESERVED|
|R/W-0h<br>R/W-0h<br>R/W-0h<br>R/W-0h<br>R/W-0h|R/W-0h<br>R/W-0h<br>R/W-0h<br>R/W-0h<br>R/W-0h|R/W-0h<br>R/W-0h<br>R/W-0h<br>R/W-0h<br>R/W-0h|R/W-0h<br>R/W-0h<br>R/W-0h<br>R/W-0h<br>R/W-0h|R/W-0h<br>R/W-0h<br>R/W-0h<br>R/W-0h<br>R/W-0h|R/W-0h<br>R/W-0h<br>R/W-0h<br>R/W-0h<br>R/W-0h|



**Table 9-23. SYS_CTRL Register Field Descriptions**

|Bit|Field|Type|Reset|Description|
|---|---|---|---|---|
|15|Parity_bit|R|0h|Parity Bit if SPI_PEN is set to '1' otherwise reserved|
|14-12|WRITE_KEY|W|0h|0x5 Write Key Specific to this register.|
|11-9|RESERVED|R-0|0h|Reserved|
|8|RESERVED|R/W|0h|Reserved|
|7|REG_LOCK|R/W|0h|Register Lock Bit<br>0h = Registers Unlocked<br>1h = Registers Locked|
|6|SPI_PEN|R/W|0h|Parity Enable for both SPI and tSPI<br>0h = Parity Disabled<br>1h = Parity Enabled|
|5-4|RESERVED|R/W|0h|Reserved|
|3|RESERVED|R/W|0h|Reserved|
|2-0|RESERVED|R/W|0h|Reserved|



74 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**10 Application and Implementation**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



**Note**


Information in the following applications sections is not part of the TI component specification,
and TI does not warrant its accuracy or completeness. TI’s customers are responsible for
determining suitability of components for their purposes, as well as validating and testing their design
implementation to confirm system functionality.


**10.1 Application Information**


The DRV8311 can be used to drive Brushless-DC motors. The following design procedure can be used to
configure the DRV8311.

















































**Figure 10-1. Application Schematics (DRV8311S)**


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 75


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**10.2 Typical Applications**


**10.2.1 Three-Phase Brushless-DC Motor Control**


In this application, the DRV8311 is used to drive a Brushless-DC motor using PWMs from an external
microcontroller.


_**10.2.1.1 Detailed Design Procedure**_


Table 10-1 lists the example input parameters for the system design.


**Table 10-1. Design Parameters**

|DESIGNPARAMETERS|REFERENCE|EXAMPLEVALUE|
|---|---|---|
|Supply voltage|VVM|12 V|
|Motor RMS current|IRMS|2 A|
|Motor peak current|IPEAK|3 A|
|PWM Frequency|fPWM|50 kHz|
|Slew Rate Setting|SR|230 V/µs|
|VIN_AVDD supply voltage|VVIN_AVDD|12 V|
|CSA reference voltage|VCSA_REF|3.0 V|
|System ambient temperature|TA|–20°C to +105°C|



**10.2.1.1.1 Motor Voltage**


Brushless-DC motors are typically rated for a certain voltage (for example 5V or 12V). The DRV8311 allows for a
range of possible operating voltages from 3V to 20 V.


_**10.2.1.2 Driver Propagation Delay and Dead Time**_


The propagation delay is defined as the time taken for changing input logic edges INHx and INLx (whichever
changes first if MCU dead time is added) to change the half-bridge output voltage (OUTx). Driver propagation
delay (tPD) and dead time (tdead) is specified with a typical and maximum value, but not with a minimum value.
This is because the propagation delay can be smaller than typical depending on the direction of current at
the OUTx pin during synchronous switching. Driver propagation delay and dead time can be more than typical
values due to slower internal turn-ons of the high-side or low-side internal MOSFETs to avoid internal dV/dt
coupling.


For more information and examples of how propagation delay and dead time differs for input PWM and output
[configurations, refer Delay and Dead Time in Integrated MOSFET Drivers](https://www.ti.com/lit/an/slvaf84/slvaf84.pdf) .


The dead time from the microcontroller’s PWM outputs can be used as an extra precaution in addition to the
DRV8311 internal shoot-through protection. The DRV8311 uses an internal logic prioritizes the MCU dead time
or driver dead time based on their durations.


If the MCU dead time is less than the DRV8311 driver dead time, the driver will compensate and make the true
output dead time with the value specified by the DRV8311. If the MCU inserted dead time is larger than the
driver dead time, then the DRV8311 will adjust timing as per the MCU dead time.


A summary of the DRV8311 delay times with respect to synchronous inputs INHx and INLx, OUTx current
direction, and MCU dead time are listed in Table 10-2.


**Table 10-2. Summary of Delay Times in DRV8311 Depending on Logic Inputs and Output Current**
**Direction**









|OUTxCurrent<br>Direction|INHx|INLx|PropagationDelay<br>(tPD)|Dead Time (tdead)|Inserted MCU Dead Time (tdead(MCU))|Col7|
|---|---|---|---|---|---|---|
|**OUTx Current**<br>**Direction**|**INHx**|**INLx**|**Propagation Delay**<br>**(tPD)**|**Dead Time (tdead)**|**tdead(MCU) < tdead**|**tdead(MCU) > tdead**|
|Out of OUTx|Rising|Falling|Typical|Typical|Output dead time = tdead|Output dead time = tdead(MCU)|
|Out of OUTx|Falling|Rising|Smaller than typical|Smaller than typical|Output dead time < tdead|Output dead time < tdead(MCU)|


76 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


