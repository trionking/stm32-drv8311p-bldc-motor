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


