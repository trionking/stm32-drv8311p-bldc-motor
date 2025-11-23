**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)

## **DRV8311 Three-Phase PWM Motor Driver**



**1 Features**


- Three-phase PWM motor driver

– 3-Phase brushless DC motors

- 3-V to 20-V operating voltage

–
24-V Absolute maximum voltage

- High output current capability

– 5-A Peak current drive

- Low on-state resistance MOSFETs

– 210-mΩ typ RDS(ON) (HS + LS) at TA = 25°C

- Low power sleep mode
– 1.5-µA at VVM = 12-V, TA = 25°C

- Multiple control interface options

– 6x PWM control interface

– 3x PWM control interface

–
PWM generation mode (SPI/tSPI) with optional
calibration between MCU and DRV8311

- tSPI interface (DRV8311P)

–
PWM duty and frequency update over SPI

–
Control multiple DRV8311P devices using
standard 4-wire SPI interface

- Supports up to 200-kHz PWM frequency

- Integrated current sensing

–
No external resistor required

–
Sense amplifier output, one per 1/2-bridge

- SPI and hardware device variants

–
10-MHz SPI communication (SPI/tSPI)

- Supports 1.8-V, 3.3-V, and 5-V logic inputs

- Built-in 3.3-V ± 4.5%, 100-mA LDO regulator

- Integrated protection features

–
VM undervoltage lockout (UVLO)

–
Charge pump undervoltage (CPUV)

–
Overcurrent protection (OCP)

–
Thermal warning and shutdown (OTW/OTSD)

–
Fault condition indication pin (nFAULT)


**2 Applications**


- [Brushless-DC (BLDC) Motor Modules](https://www.ti.com/solution/dc-input-bldc-motor-drive)

- [Drones and Handheld Gimbal](https://www.ti.com/solution/drone-propeller-esc)

- [Coffee Machines](https://www.ti.com/solution/coffee-machine)

- [Vacuum Robots](https://www.ti.com/solution/vacuum-robot)

- [Washer and Dryer Pumps](https://www.ti.com/solution/washer-dryer)

- [Laptop, Desktop, and Server Fans](https://www.ti.com/solution/standard-notebook-pc)



**3 Description**


The DRV8311 provides three integrated MOSFET
half-H-bridges for driving a three-phase brushless DC
(BLDC) motor for 5-V, 9-V, 12-V, or 18-V DC rails or
1S to 4S battery powered applications. The device
integrates three current-sense amplifiers (CSA) with
integrated current sense for sensing the three phase
currents of BLDC motors to achieve optimum FOC
and current-control system implementation.


The DRV8311P device provides capability to generate
and configure PWM timers over Texas Instruments
SPI (tSPI), and allows the control of multiple BLDC
motors directly over the tSPI interface. This feature
reduces the number of required I/O ports from the
primary controller to control multiple motors.


**Device Information** [(1) ]

|PARTNUMBER|PACKAGE|BODYSIZE(NOM)|
|---|---|---|
|DRV8311H|WQFN (24)|3.00 mm × 3.00 mm|
|DRV8311S(2)|WQFN (24)|3.00 mm × 3.00 mm|
|DRV8311P|WQFN (24)|3.00 mm × 3.00 mm|



(1) For all available packages, see the orderable addendum at
the end of the data sheet.
(2) Device available for preview only.



3- to 20-V (24-V abs max)











LDO out







**DRV8311H/S Simplified Schematic**



3- to 20-V (24-V abs max)









LDO out







**DRV8311P Simplified Schematic**


An IMPORTANT NOTICE at the end of this data sheet addresses availability, warranty, changes, use in safety-critical applications,
intellectual property matters and other important disclaimers. PRODUCTION DATA.


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**Table of Contents**



**1 Features** ............................................................................1

**2 Applications** ..................................................................... 1
**3 Description** .......................................................................1
**4 Revision History** .............................................................. 2
**5 Device Comparison Table** ...............................................3
**6 Pin Configuration and Functions** ...................................4
**7 Specifications** .................................................................. 7

7.1 Absolute Maximum Ratings........................................ 7
7.2 ESD Ratings............................................................... 7
7.3 Recommended Operating Conditions.........................7
7.4 Thermal Information....................................................8

7.5 Electrical Characteristics.............................................8
7.6 SPI Timing Requirements......................................... 14
7.7 SPI Secondary Device Mode Timings.......................15
7.8 Typical Characteristics.............................................. 16
**8 Detailed Description** ......................................................17

8.1 Overview................................................................... 17

8.2 Functional Block Diagram......................................... 18
8.3 Feature Description...................................................21
8.4 Device Functional Modes..........................................46


**4 Revision History**



8.5 SPI Communication.................................................. 47

**9 DRV8311 Registers** ........................................................52
**10 Application and Implementation** ................................ 75

10.1 Application Information........................................... 75
10.2 Typical Applications................................................ 76
10.3 Three Phase Brushless-DC tSPI Motor Control......79

10.4 Alternate Applications............................................. 81
**11 Power Supply Recommendations** ..............................82

11.1 Bulk Capacitance.................................................... 82
**12 Layout** ...........................................................................83

12.1 Layout Guidelines................................................... 83
12.2 Layout Example...................................................... 84
12.3 Thermal Considerations..........................................85
**13 Device and Documentation Support** ..........................86

13.1 Support Resources................................................. 86
13.2 Trademarks............................................................. 86
13.3 Electrostatic Discharge Caution..............................86
13.4 Glossary..................................................................86
**14 Mechanical, Packaging, and Orderable**

**Information** .................................................................... 86



**Changes from Revision A (December 2021) to Revision B (February 2022)** **Page**

 - Added DRV8311H to the data sheet...................................................................................................................1


**Changes from Revision * (September 2021) to Revision A (December 2021)** **Page**

 - Updated device status to Production Data......................................................................................................... 1


2 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**5 Device Comparison Table**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)











|DEVICE|PACKAGES|INTERFACE|nSLEEPINPUT|
|---|---|---|---|
|DRV8311P|24-pin WQFN (3 mm x 3 mm)|SPI / tSPI|Yes|
|DRV8311S|DRV8311S|SPI|No|
|DRV8311H|DRV8311H|Hardware|Yes|


**Table 5-1. DRV8311H vs. DRV8311S vs. DRV8311P Configuration Comparison**
























|Parameters|DRV8311H|DRV8311S|DRV8311P|
|---|---|---|---|
|PWM control mode settings|MODE pin (2 settings)|PWM_MODE (3 settings)|PWM_MODE (3 settings)|
|Slew rate settings|SLEW pin (4 settings)|SLEW_RATE (4 settings)|SLEW_RATE (4 settings)|
|Current sense amplifier gain|GAIN pin (4 settings)|CSA_GAIN (4 settings)|CSA_GAIN (4 settings)|
|Over current protection (OCP)<br>level settings|MODE pin (2 settings)|OCP_LVL (2 settings)|OCP_LVL (2 settings)|
|OCP blanking time|Fixed to 0.2 us|OCP_TBLANK (4 settings)|OCP_TBLANK (4 settings)|
|OCP deglitch time|Fixed to 1 us|OCP_DEG (4 settings)|OCP_DEG (4 settings)|
|OCP mode|Fast retry with 5-ms automatic<br>retry|OCP_MODE (4 settings),<br>Configurable retry time|OCP_MODE (4 settings),<br>Configurable retry time|
|Dead time|Fixed based on SLEW pin setting|TDEAD_CTRL (8 settings)|TDEAD_CTRL (8 settings)|
|Propagation delay|Fixed based on SLEW pin setting|Fixed based on SLEW pin setting|Fixed based on SLEW pin setting|
|Driver delay compensation|Disabled|DLYCMP_EN (2 settings)|DLYCMP_EN (2 settings)|
|Spread Spectrum Modulation for<br>internal Oscillator|Enabled|SSC_DIS (2 settings)|SSC_DIS (2 settings)|
|Undervoltage lockout|VINAVDD, CP and AVDD<br>undervoltage protection enabled,<br>CSAREF_UV disabled, tRETRY<br>is configured for 5 ms fast<br>automatic retry|VINAVDD, CP and AVDD<br>undervoltage protection enabled,<br>CSAREF_UV (2 settings),<br>Configurable tRETRY using<br>UVP_MODE|VINAVDD, CP and AVDD<br>undervoltage protection enabled,<br>CSAREF_UV (2 settings),<br>Configurable tRETRY using<br>UVP_MODE|
|SPI fault mode|NA|SPIFLT_MODE (2 settings)|SPIFLT_MODE (2 settings)|
|Texas Instruments SPI (tSPI)|NA|NA|Available|
|Over temperature shutdown<br>(OTSD) mode|Fast retry with 5-ms automatic<br>retry|OTSD_MODE (2 settings)|OTSD_MODE (2 settings)|



Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 3


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**6 Pin Configuration and Functions**



19 INLB




SOB


SOA


CP

nFAULT


SOC

CSAREF













INLA


AVDD





AGND


INHA





INHB


INHC



VIN_AVDD 7



**Figure 6-1. DRV8311S 24-Pin WQFN With Exposed Thermal Pad Top View**



19 INLB




SOB


SOA


CP

nFAULT


SOC

CSAREF





INLA


AVDD


AGND


INHA


INHB


INHC







VIN_AVDD 7



**Figure 6-2. DRV8311H 24-Pin WQFN With Exposed Thermal Pad Top View**


4 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)

19 PWM_SYNC




SOB


SOA


CP

nFAULT


SOC

CSAREF

















NC


AVDD


AGND


AD0


AD1


NC



VIN_AVDD 7



**Figure 6-3. DRV8311P 24-Pin WQFN With Exposed Thermal Pad Top View**


**Table 6-1. Pin Functions**



















|PIN|24 -pin Package|Col3|Col4|TYPE(1)|DESCRIPTION|
|---|---|---|---|---|---|
|**NAME**|**DRV8311**<br>**H**|**DRV8311P**|** DRV8311S**|** DRV8311S**|** DRV8311S**|
|AD0|—|15|—|I|Only on tSPI device DRV8311P. Address selection for tSPI.|
|AD1|—|14|—|I|Only on tSPI device DRV8311P. Address selection for tSPI.|
|AGND|16|16|16|PWR|Device analog ground. Connect to system ground.|
|AVDD|17|17|17|PWR|3.3V regulator output. Connect a X5R or X7R, 0.7-µF to 7-µF, 6.3-V ceramic<br>capacitor between the AVDD and AGND pins. This regulator can source up<br>to 100 mA externally.|
|CP|6|6|6|PWR|Charge pump output. Connect a X5R or X7R, 0.1-µF, 16-V ceramic capacitor<br>between the VCP and VM pins.|
|CSAREF|2|2|2|PWR|Current sense amplifier power supply input and reference. Connect a X5R or<br>X7R, 0.1-µF, 6.3-V ceramic capacitor between the CSAREF and AGND pins.|
|GAIN|21|—|—|I|Only on Hardware devices (DRV8311H). Current sense amplifier gain<br>setting. The pin is a 4 level input pin configured by an external resistor<br>between GAIN and AVDD or AGND.|
|INHA|15|—|15|I|High-side driver control input for OUTA. This pin controls the state of the<br>high-side MOSFET in 6x/3x PWM Mode.|
|INHB|14|—|14|I|High-side driver control input for OUTB. This pin controls the state of the<br>high-side MOSFET in 6x/3x PWM Mode.|
|INHC|13|—|13|I|High-side driver control input for OUTC. This pin controls the state of the<br>high-side MOSFET in 6x/3x PWM Mode.|
|INLA|18|—|18|I|Low-side driver control input for OUTA. This pin controls the state of the<br>low-side MOSFET in 6x PWM Mode.|
|INLB|19|—|19|I|Low-side driver control input for OUTB. This pin controls the state of the<br>low-side MOSFET in 6x PWM Mode.|
|INLC|20|—|20|I|Low-side driver control input for OUTC. This pin controls the state of the<br>low-side MOSFET in 6x PWM Mode.|
|MODE|23|—|—|I|Only on Hardware devices (DRV8311H). PWM mode setting. This pin is a 4<br>level input pin configured by an external resistor between MODE and AVDD<br>or AGND.|
|nFAULT|1|1|1|O|Fault indication pin. Pulled logic-low with fault condition; open-drain output<br>requires an external pullup to AVDD.|


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 5


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**Table 6-1. Pin Functions (continued)**

























|PIN|24 -pin Package|Col3|Col4|TYPE(1)|DESCRIPTION|
|---|---|---|---|---|---|
|**NAME**|**DRV8311**<br>**H**|**DRV8311P**|** DRV8311S**|** DRV8311S**|** DRV8311S**|
|nSCS|—|20|24|I|Only on SPI (DRV8311S) and tSPI (DRV8311P) devices. Serial chip select.<br>A logic low on this pin enables serial interface communication (SPI devices).|
|nSLEEP|24|24|—|I|Only on DRV8311H and DRV8311P devices. When this pin is logic low the<br>device goes to a low-power sleep mode. A 15 to 50-µs low pulse on nSLEEP<br>pin can be used to reset fault conditions without entering sleep mode.|
|OUTA|10|10|10|O|Half bridge output A. Connect to motor winding.|
|OUTB|11|11|11|O|Half bridge output B. Connect to motor winding.|
|OUTC|12|12|12|O|Half bridge output C. Connect to motor winding.|
|PGND|9|9|9|PWR|Device power ground. Connect to system ground.|
|PWM_SY<br>NC|—|19|—|I|Only on tSPI device DRV8311P. Connect to the MCU signal to synchronize<br>the internally-generated PWM signals from DRV8311 to the MCU in PWM<br>generation mode.|
|SCLK|—|23|23|I|Only on SPI (DRV8311S) and tSPI (DRV8311P) devices. Serial clock input.<br>Serial data is shifted out on the rising edge and captured on the falling edge<br>of SCLK (SPI devices).|
|SDI|—|22|22|I|Only on SPI (DRV8311S) and tSPI (DRV8311P) devices. Serial data input.<br>Data is captured on the falling edge of the SCLK pin (SPI devices).|
|SDO|—|21|21|O|Only on SPI (DRV8311S) and tSPI (DRV8311P) devices. Serial data output.<br>Data is shifted out on the rising edge of the SCLK pin.|
|SLEW|22|—|—|I|Only on DRV8311H device. OUTx voltage slew rate control setting. This pin<br>is a 4 level input pin set by an external resistor between SLEW pin and<br>AVDD or AGND.|
|SOA|5|5|5|O|Current sense amplifier output for OUTA.|
|SOB|4|4|4|O|Current sense amplifier output for OUTB.|
|SOC|3|3|3|O|Current sense amplifier output for OUTC.|
|VM|8|8|8|PWR|Power supply for the motor. Connect to motor supply voltage. Connect a X5R<br>or X7R, 0.1-uF VM-rated ceramic bypass capacitor as well as a >=10-uF,<br>VM-rated bulk capacitor between VM and PGND. Additionally, connect a<br>X5R or X7R, 0.1-uF, 16-V ceramic capacitor between the VM and CP pins.|
|VIN_AVDD|7|7|7|PWR|Supply input for AVDD. Bypass to AGND with a X5R or X7R, 0.1-uF,<br>VIN_AVDD-rated ceramic capacitor as well as a >=10-uF, VIN_AVDD-rated<br>rated bulk capacitor between VIN_AVDD and PGND.|
|Thermal<br>pad||||PWR|Must be connected to PGND.|
|NC|—|13,18|—|—|No connect. Leave the pin floating.|


(1) I = input, O = output, PWR = power, NC = no connect


6 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**7 Specifications**
**7.1 Absolute Maximum Ratings**
over operating ambient temperature range (unless otherwise noted) [(1)]



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



|Col1|MIN MAX|UNIT|
|---|---|---|
|Power supply pin voltage (VM)|–0.3<br>24|V|
|AVDD regulator input pin voltage (VIN_AVDD)|–0.3<br>24|V|
|Voltage difference between ground pins (PGND, AGND)|–0.3<br>0.3|V|
|Charge pump voltage (CP)|–0.3<br>VM + 6|V|
|Analog regulator output pin voltage (AVDD)|–0.3<br>4|V|
|Logic pin input voltage (INHx, INLx, nSCS, nSLEEP, SCLK, SDI, ADx, GAIN, MODE, SLEW,<br>PWM_SYNC)|–0.3<br>6|V|
|Logic pin output voltage (nFAULT, SDO)|–0.3<br>6|V|
|Open drain output current range (nFAULT)|0<br>5|mA|
|Current sense amplifier reference supply input (CSAREF)|–0.3<br>4|V|
|Current sense amplifier output (SOx)|–0.3<br>4|V|
|Peak Output Current (OUTA, OUTB, OUTC)|5|A|
|Output pin voltage (OUTA, OUTB, OUTC)|–1<br>VM + 1(2)|V|
|Ambient temperature, TA|–40<br>125|°C|
|Junction temperature, TJ|–40<br>150|°C|
|Storage tempertaure, Tstg|–65<br>150|°C|


(1) _Operation outside the Absolute Maximum Ratings may cause permanent device damage. Absolute Maximum Ratings do not imply_
_functional operation of the device at these or any other conditions beyond those listed under Recommended Operating Conditions._
_If used outside the Recommended Operating Conditions but within the Absolute Maximum Ratings, the device may not be fully_
_functional, and this may affect device reliability, functionality, performance, and shorten the device lifetime._
(2) VM + 1 V or 24 V (whichever is smaller).


**7.2 ESD Ratings**

|Col1|Col2|Col3|VALUE|UNIT|
|---|---|---|---|---|
|V(ESD)|Electrostatic<br>discharge|Human body model (HBM), per ANSI/ESDA/JEDEC JS-001(1)|±1500|V|
|V(ESD)|Electrostatic<br>discharge|Charged device model (CDM), per ANSI/ESDA/JEDEC JS-002(2)|±750|V|



(1) JEDEC document JEP155 states that 500-V HBM allows safe manufacturing with a standard ESD control process.
(2) JEDEC document JEP157 states that 250-V CDM allows safe manufacturing with a standard ESD control process.


**7.3 Recommended Operating Conditions**
over operating ambient temperature range (unless otherwise noted)









|Col1|Col2|Col3|MIN NOM MAX|UNIT|
|---|---|---|---|---|
|VVM|Power supply voltage|VVM|3<br>12<br>20|V|
|VIN_AVDD|AVDD regulator input pin voltage|VVIN_AVDD|3<br>12<br>20|V|
|fPWM|Output PWM frequency|OUTA, OUTB, OUTC|200|kHz|
|IOUT (1)|Peak output current|OUTA, OUTB, OUTC|5|A|
|VIN|Logic input voltage|INHx, INLx, nSCS, nSLEEP, SCLK,<br>SDI, ADx, GAIN, MODE, SLEW,<br>PWM_SYNC|-0.1<br>5.5|V|
|VOD|Open drain pullup voltage|nFAULT|-0.1<br>5.5|V|
|IOD|Open drain output sink current|nFAULT|5|mA|
|VCSAREF|CSA refernce input Voltage|CSAREF|2<br>3.6|V|
|ICSAREF|CSA refernce input Current|CSAREF|2.5<br>7.5|mA|


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 7


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


over operating ambient temperature range (unless otherwise noted)

|Col1|Col2|Col3|MIN NOM MAX|UNIT|
|---|---|---|---|---|
|TA|Operating ambient temperature||–40<br>125|°C|
|TJ|Operating Junction temperature||–40<br>150|°C|



(1) Power dissipation and thermal limits must be observed


**7.4 Thermal Information**







|THERMALMETRIC(1)|Col2|DRV8311|UNIT|
|---|---|---|---|
|**THERMAL METRIC**(1)|**THERMAL METRIC**(1)|**QFN (RRW)**|**QFN (RRW)**|
|**THERMAL METRIC**(1)|**THERMAL METRIC**(1)|**24 Pins**|**24 Pins**|
|RθJA|Junction-to-ambient thermal resistance|42.6|°C/W|
|RθJC(top)|Junction-to-case (top) thermal resistance|37.9|°C/W|
|RθJB|Junction-to-board thermal resistance|15.7|°C/W|
|ΨJT|Junction-to-top characterization parameter|0.5|°C/W|
|ΨJB|Junction-to-board characterization parameter|15.6|°C/W|
|RθJC(bot)|Junction-to-case (bottom) thermal resistance|4.8|°C/W|


(1) [For more information about traditional and new thermal metrics, see the Semiconductor and IC Package Thermal Metrics application](http://www.ti.com/lit/SPRA953)
report.


**7.5 Electrical Characteristics**

at TJ = –40°C to +150°C, VVM = 3 to 20 V (unless otherwise noted). Typical limits apply for TA = 25°C, VVM = 12 V











|PARAMETER|Col2|TESTCONDITIONS|MIN TYP MAX|UNIT|
|---|---|---|---|---|
|**POWER SUPPLIES**|**POWER SUPPLIES**|**POWER SUPPLIES**|**POWER SUPPLIES**|**POWER SUPPLIES**|
|IVMQ|VM sleep mode current|VVM= 12 V, nSLEEP = 0, TA = 25 °C|1.5<br>3|µA|
|IVMQ|VM sleep mode current|nSLEEP = 0, TA = 125 °C|9|µA|
|IVMS|VM standby mode current|VVM= 12 V, nSLEEP = 1, INHx = INLx =<br>0, SPI = 'OFF', TA = 25 °C|7<br>12|mA|
|IVMS|VM standby mode current|nSLEEP = 1, INHx = INLx = 0, SPI =<br>'OFF'|8<br>12|mA|
|IVM|VM operating mode current|VVM= 12 V, nSLEEP = 1, fPWM = 25 kHz,<br>TA = 25 °C|10<br>13|mA|
|IVM|VM operating mode current|VVM= 12 V, nSLEEP = 1, fPWM = 200<br>kHz, TA = 25 °C|12<br>14|mA|
|IVM|VM operating mode current|nSLEEP =1, fPWM = 25 kHz|10<br>15|mA|
|IVM|VM operating mode current|nSLEEP =1, fPWM = 200 kHz|12<br>15|mA|
|VAVDD|Analog regulator voltage|VVM> 4V, VVIN_AVDD> 4.5V, 0 mA ≤<br>IAVDD≤ 100 mA|3.15<br>3.3<br>3.45|V|
|VAVDD|VAVDD|VVM> 3.5V, 3.5V ≤VVIN_AVDD≤ 4.5V, 0<br>mA ≤ IAVDD≤ 35 mA|3<br>3.3<br>3.6|V|
|VAVDD|VAVDD|2.5V ≤VVIN_AVDD ≤ 3.5V, 0 mA ≤ IAVDD≤ <br>10 mA|2.2VIN_AVDD<br>-0.3<br>3.4|V|
|VAVDD|VAVDD|VVM< 4V, VVIN_AVDD> 4.5V, 0 mA ≤<br>IAVDD≤ 40 mA|3<br>3.3<br>3.6|V|
|VAVDD|VAVDD|VVM< 3.5V, 3.5V ≤VVIN_AVDD≤ 4.5V, 0<br>mA ≤ IAVDD≤ 20 mA|3<br>3.3<br>3.6|V|
|IAVDD_LIM|External analog regulator current limit||148<br>200<br>250|mA|


8 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



at TJ = –40°C to +150°C, VVM = 3 to 20 V (unless otherwise noted). Typical limits apply for TA = 25°C, VVM = 12 V





















|PARAMETER|Col2|TESTCONDITIONS|MIN TYP MAX|UNIT|
|---|---|---|---|---|
|IAVDD|External analog regulator load|VVM> 4V, VVIN_AVDD> 4.5V|100|mA|
|IAVDD|External analog regulator load|VVM< 4V, VVIN_AVDD> 4.5V|40|mA|
|IAVDD|External analog regulator load|VVM> 3.5V, 3.6V ≤VVIN_AVDD≤ 4.5V|35|mA|
|IAVDD|External analog regulator load|VVM< 3.5V, 3.6V ≤VVIN_AVDD≤ 4.5V|20|mA|
|IAVDD|External analog regulator load|2.5V ≤VVIN_AVDD≤ 3.6V|10|mA|
|CAVDD|Capacitance on AVDD pin|IAVDD≤ 25 mA;|0.7<br>1<br>7|µF|
|CAVDD|Capacitance on AVDD pin|IAVDD≥ 25 mA;|3.3<br>4.7<br>7|µF|
|RAVDD|AVDD Output Voltage Regulation|VVIN_AVDD> 4.5V; IAVDD≤ 20 mA;|-3<br>3|%|
|RAVDD|AVDD Output Voltage Regulation|VVIN_AVDD> 4.5V; 20 mA ≤ IAVDD≤ 40<br>mA;|-2<br>2|%|
|RAVDD|AVDD Output Voltage Regulation|VVIN_AVDD> 4.5V; IAVDD≥ 40 mA;|-3<br>3|%|
|VVCP|Charge pump regulator voltage|VCP with respect to VM|3<br>5<br>5.6|V|
|tWAKE|Wakeup time|VVM > VUVLO, nSLEEP = 1 to Output<br>ready|1<br>3|ms|
|tWAKE_CSA|Wakeup time for CSA|VCSAREF > VCSAREF_UVto SOx ready,<br>when nSLEEP = 1|30<br>50|µs|
|tSLEEP|Turn-off time|nSLEEP = 0 to driver tri-stated|100<br>200|µs|
|tRST|Reset Pulse time|nSLEEP = 0 period to reset faults|10<br>65|µs|
|**LOGIC-LEVEL INPUTS (INHx, INLx, nSLEEP, SCLK, SDI)**|**LOGIC-LEVEL INPUTS (INHx, INLx, nSLEEP, SCLK, SDI)**|**LOGIC-LEVEL INPUTS (INHx, INLx, nSLEEP, SCLK, SDI)**|**LOGIC-LEVEL INPUTS (INHx, INLx, nSLEEP, SCLK, SDI)**|**LOGIC-LEVEL INPUTS (INHx, INLx, nSLEEP, SCLK, SDI)**|
|VIL|Input logic low voltage||0<br>0.6|V|
|VIH|Input logic high voltage||1.65<br>5.5|V|
|VHYS|Input logic hysteresis||100<br>300<br>660|mV|
|IIL|Input logic low current|VPIN (Pin Voltage) = 0 V|–1<br>1|µA|
|IIH|Input logic high current|nSLEEP, VPIN (Pin Voltage) = 5 V|30|µA|
|IIH|Input logic high current|Other pins, VPIN (Pin Voltage) = 5 V|50|µA|
|RPD|Input pulldown resistance|nSLEEP|230<br>300|kΩ|
|RPD|Input pulldown resistance|Other pins|160<br>200|kΩ|
|CID|Input capacitance||30|pF|
|**LOGIC-LEVEL INPUTS (nSCS)**|**LOGIC-LEVEL INPUTS (nSCS)**|**LOGIC-LEVEL INPUTS (nSCS)**|**LOGIC-LEVEL INPUTS (nSCS)**|**LOGIC-LEVEL INPUTS (nSCS)**|
|VIL|Input logic low voltage||0<br>0.6|V|
|VIH|Input logic high voltage||1.5<br>5.5|V|
|VHYS|Input logic hysteresis||200<br>500|mV|
|IIL|Input logic low current|VPIN (Pin Voltage) = 0 V|90|µA|
|IIH|Input logic high current|VPIN (Pin Voltage) = 5 V|70|µA|
|RPU|Input pullup resistance||48<br>90|kΩ|
|CID|Input capacitance||30|pF|
|**FOUR-LEVEL INPUTS (GAIN, MODE, SLEW)**|**FOUR-LEVEL INPUTS (GAIN, MODE, SLEW)**|**FOUR-LEVEL INPUTS (GAIN, MODE, SLEW)**|**FOUR-LEVEL INPUTS (GAIN, MODE, SLEW)**|**FOUR-LEVEL INPUTS (GAIN, MODE, SLEW)**|
|VL1|Input mode 1 voltage|Tied to AGND|0<br>0.21*AV<br>DD|V|
|VL2|Input mode 2 voltage|47 kΩ +/- 5% tied to GND|0.25*AV<br>DD<br>0.5*AVDD<br>0.55*AV<br>DD|V|
|VL3|Input mode 3 voltage|Hi-Z|0.606*AV<br>DD<br>0.757*AVD<br>D<br>0.909*AV<br>DD|V|
|VL4|Input mode 4 voltage|Tied to AVDD|0.94*AV<br>DD<br>AVDD|V|
|RPU|Input pullup resistance|To AVDD|48<br>70|kΩ|
|RPD|Input pulldown resistance|To AGND|160<br>200|kΩ|


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 9


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


at TJ = –40°C to +150°C, VVM = 3 to 20 V (unless otherwise noted). Typical limits apply for TA = 25°C, VVM = 12 V





























|PARAMETER|Col2|TESTCONDITIONS|MIN TYP MAX|UNIT|
|---|---|---|---|---|
|**OPEN-DRAIN OUTPUTS (nFAULT)**|**OPEN-DRAIN OUTPUTS (nFAULT)**|**OPEN-DRAIN OUTPUTS (nFAULT)**|**OPEN-DRAIN OUTPUTS (nFAULT)**|**OPEN-DRAIN OUTPUTS (nFAULT)**|
|VOL|Output logic low voltage|IOD = -5 mA|0.4|V|
|IOH|Output logic high current|VOD = 5 V|–1<br>1|µA|
|COD|Output capacitance||30|pF|
|**PUSH-PULL OUTPUTS (SDO)**|**PUSH-PULL OUTPUTS (SDO)**|**PUSH-PULL OUTPUTS (SDO)**|**PUSH-PULL OUTPUTS (SDO)**|**PUSH-PULL OUTPUTS (SDO)**|
|VOL|Output logic low voltage|IOP = -5 mA, 2.2V ≤ VAVDD ≤ 3V|0<br>0.55|V|
|VOL|Output logic low voltage|IOP = -5 mA, 3V ≤ VAVDD ≤ 3.6V|0<br>0.5|V|
|VOH|Output logic high voltage|IOP = 5 mA, 2.2V ≤ VAVDD ≤ 3V|VAVDD -<br>0.86<br>3|V|
|VOH|Output logic high voltage|IOP = 5 mA, 3V ≤ VAVDD ≤ 3.6V|VAVDD -<br>0.5<br>3.6|V|
|IOL|Output logic low current|VOP = 0 V|–1<br>1|µA|
|IOH|Output logic high current|VOP = 5 V|–1<br>1|µA|
|COD|Output capacitance||30|pF|
|**DRIVER OUTPUTS**|**DRIVER OUTPUTS**|**DRIVER OUTPUTS**|**DRIVER OUTPUTS**|**DRIVER OUTPUTS**|
|RDS(ON)|Total MOSFET on resistance (High-side<br>+ Low-side)|6V ≥ VVM ≥ 3 V, IOUT = 1 A, TJ = 25°C|300<br>350|mΩ|
|RDS(ON)|Total MOSFET on resistance (High-side<br>+ Low-side)|6V ≥ VVM ≥ 3 V, IOUT = 1 A, TJ = 150°C|450<br>500|mΩ|
|RDS(ON)|Total MOSFET on resistance (High-side<br>+ Low-side)|VVM ≥ 6 V, IOUT = 1 A, TJ = 25°C|210<br>250|mΩ|
|RDS(ON)|Total MOSFET on resistance (High-side<br>+ Low-side)|VVM ≥ 6 V, IOUT = 1 A, TJ = 150°C|330<br>375|mΩ|
|SR|Phase pin slew rate switching low to high<br>(Rising from 20 % to 80 % of VM)|VVM= 12V; SLEW = 00b (SPI Variant)<br>or SLEW pin tied to AGND (HW Variant)|18<br>35<br>55|V/us|
|SR|SR|VVM= 12V; SLEW = 01b (SPI Variant)<br>or SLEW pin to 47 kΩ +/- 5% tied to<br>AGND (HW Variant)|35<br>75<br>100|V/us|
|SR|SR|VVM= 12V; SLEW = 10b (SPI Variant)<br>or SLEW pin to Hi-Z (HW Variant)|90<br>180<br>225|V/us|
|SR|SR|VVM= 12V; SLEW = 11b (SPI Variant)<br>or SLEW pin tied to AVDD (HW Variant)|140<br>230<br>355|Vus|
|SR|Phase pin slew rate switching high to low<br>(Falling from 80 % to 20 % of VM)|VVM= 12V; SLEW = 00b (SPI Variant)<br>or SLEW pin tied to AGND (HW Variant)|20<br>35<br>50|V/us|
|SR|Phase pin slew rate switching high to low<br>(Falling from 80 % to 20 % of VM)|VVM= 12V; SLEW = 01b (SPI Variant)<br>or SLEW pin to 47 kΩ +/- 5% tied to<br>AGND (HW Variant)|35<br>75<br>100|V/us|
|SR|Phase pin slew rate switching high to low<br>(Falling from 80 % to 20 % of VM)|VVM= 12V; SLEW = 10b (SPI Variant)<br>or SLEW pin to Hi-Z (HW Variant)|80<br>180<br>225|V/us|
|SR|Phase pin slew rate switching high to low<br>(Falling from 80 % to 20 % of VM)|VVM = 12V; SLEW = 11b (SPI Variant)<br>or SLEW pin tied to AVDD (HW Variant)|125<br>270<br>350|V/us|


10 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



at TJ = –40°C to +150°C, VVM = 3 to 20 V (unless otherwise noted). Typical limits apply for TA = 25°C, VVM = 12 V





























|PARAMETER|Col2|TESTCONDITIONS|MIN TYP MAX|UNIT|
|---|---|---|---|---|
|tDEAD|Output dead time (high to low / low to<br>high)|VVM= 12V, SLEW = 00b (SPI Variant)<br>or SLEW pin tied to AGND (HW Variant),<br>DEADTIME = 000b, Handshake only|500<br>1200|ns|
|tDEAD|Output dead time (high to low / low to<br>high)|VVM= 12V, SLEW = 01b (SPI Variant)<br>or SLEW pin to 47 kΩ +/- 5% tied<br>to AGND (HW Variant), DEADTIME =<br>000b, Handshake only|450<br>760|ns|
|tDEAD|Output dead time (high to low / low to<br>high)|VVM= 12V, SLEW = 10b (SPI Variant)<br>or SLEW pin to Hi-Z (HW Variant),<br>DEADTIME = 000b, Handshake only|425<br>720|ns|
|tDEAD|Output dead time (high to low / low to<br>high)|VVM = 12V, SLEW = 11b (SPI Variant)<br>or SLEW pin tied to AVDD (HW Variant),<br>DEADTIME = 000b; Handshake only|425<br>710|ns|
|tDEAD|Output dead time (high to low / low to<br>high)|VVM = 12 V, DEADTIME = 001b|200<br>540|ns|
|tDEAD|Output dead time (high to low / low to<br>high)|VVM = 12 V, DEADTIME = 010b|400<br>550|ns|
|tDEAD|Output dead time (high to low / low to<br>high)|VVM = 12 V, DEADTIME = 011b|600<br>760|ns|
|tDEAD|Output dead time (high to low / low to<br>high)|VVM = 12 V, DEADTIME = 100b|800<br>900|ns|
|tDEAD|Output dead time (high to low / low to<br>high)|VVM = 12 V, DEADTIME = 101b|1000<br>1100|ns|
|tDEAD|Output dead time (high to low / low to<br>high)|VVM = 12 V, DEADTIME = 110b|1200<br>1300|ns|
|tDEAD|Output dead time (high to low / low to<br>high)|VVM = 12 V, DEADTIME = 111b|1400<br>1500|ns|
|tPD|Propagation delay (high-side / low-side<br>ON/OFF)|INHx = 1 to OUTx transisition, VVM= <br>12V, SLEW = 00b (SPI Variant) or SLEW<br>pin tied to AGND (HW Variant)|1000<br>1500|ns|
|tPD|Propagation delay (high-side / low-side<br>ON/OFF)|INHx = 1 to OUTx transisition, VVM<br>= 12V, SLEW = 01b (SPI Variant)<br>or SLEW pin to 47 kΩ +/- 5% tied to<br>AGND (HW Variant)|650<br>1100|ns|
|tPD|Propagation delay (high-side / low-side<br>ON/OFF)|INHx = 1 to OUTx transisition, VVM= <br>12V, SLEW = 10b (SPI Variant) or SLEW<br>pin to Hi-Z (HW Variant)|550<br>950|ns|
|tPD|Propagation delay (high-side / low-side<br>ON/OFF)|INHx = 1 to OUTx transisition, VVM<br>= 12V, SLEW = 11b (SPI Variant)<br>or SLEW pin tied to AVDD (HW Variant)|500<br>910|ns|
|tMIN_PULSE|Minimum output pulse width|SLEW = 11b|500|ns|
|**CURRENT SENSE AMPLIFIER**|**CURRENT SENSE AMPLIFIER**|**CURRENT SENSE AMPLIFIER**|**CURRENT SENSE AMPLIFIER**|**CURRENT SENSE AMPLIFIER**|
|GCSA|Current sense gain (SPI Device)|CSA_GAIN = 00 (SPI Variant) or GAIN<br>pin tied to AGND (HW Variant)|0.25|V/A|
|GCSA|Current sense gain (SPI Device)|CSA_GAIN = 01 (SPI Variant) or GAIN<br>pin to 47 kΩ +/- 5% tied to GND (HW<br>Variant)|0.5|V/A|
|GCSA|Current sense gain (SPI Device)|CSA_GAIN = 10 (SPI Variant) or GAIN<br>pin to Hi-Z (HW Variant)|1|V/A|
|GCSA|Current sense gain (SPI Device)|CSA_GAIN = 11 (SPI Variant) or GAIN<br>pin tied to AVDD (HW Variant)|2|V/A|
|GCSA_ERR|Current sense gain error|TJ = 25°C, IPHASE < 2.5 A|–4<br>4|%|
|GCSA_ERR|Current sense gain error|TJ = 25°C, IPHASE > 2.5 A|–5<br>5|%|
|GCSA_ERR|Current sense gain error|IPHASE< 2.5 A|–5.5<br>5.5|%|
|GCSA_ERR|Current sense gain error|IPHASE> 2.5 A|–7<br>7|%|
|IMATCH|Current sense gain error matching<br>between phases A, B and C|TJ = 25°C|–5<br>5|%|
|IMATCH|Current sense gain error matching<br>between phases A, B and C||–5<br>5|%|
|FSPOS|Full scale positive current measurement||5|A|
|FSNEG|Full scale negative current measurement||–5|A|


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 11


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


at TJ = –40°C to +150°C, VVM = 3 to 20 V (unless otherwise noted). Typical limits apply for TA = 25°C, VVM = 12 V


















































|PARAMETER|Col2|TESTCONDITIONS|MIN TYP MAX|UNIT|
|---|---|---|---|---|
|VLINEAR|SOX output voltage linear range||0.25<br>VCSAREF<br>– 0.25|V|
|IOFFSET_RT|Current sense offset low side current in<br>(Room Temperature)|TJ = 25°C, Phase current = 0 A, GCSA =<br>0.25 V/A|–50<br>50|mA|
|IOFFSET_RT|Current sense offset low side current in<br>(Room Temperature)|TJ = 25°C, Phase current = 0 A, GCSA =<br>0.5 V/A|–50<br>50|mA|
|IOFFSET_RT|Current sense offset low side current in<br>(Room Temperature)|TJ = 25°C, Phase current = 0 A, GCSA =<br>1 V/A|–30<br>30|mA|
|IOFFSET_RT|Current sense offset low side current in<br>(Room Temperature)|TJ = 25°C, Phase current = 0 A, GCSA =<br>2 V/A|–30<br>30|mA|
|IOFFSET|Current sense offset referred to low side<br>current in|Phase current = 0 A, GCSA = 0.25 V/A|–70<br>70|mA|
|IOFFSET|Current sense offset referred to low side<br>current in|Phase current = 0 A, GCSA = 0.5 V/A|–50<br>50|mA|
|IOFFSET|Current sense offset referred to low side<br>current in|Phase current = 0 A, GCSA = 1 V/A|–50<br>50|mA|
|IOFFSET|Current sense offset referred to low side<br>current in|Phase current = 0 A, GCSA = 2 V/A|–50<br>50|mA|
|tSET|Settling time to ±1%, 30 pF on SOx pin|Step on SOx = 1.2 V, GCSA = 0.25 V/A|1|μs|
|tSET|Settling time to ±1%, 30 pF on SOx pin|Step on SOx = 1.2 V, GCSA = 0.5 V/A|1|μs|
|tSET|Settling time to ±1%, 30 pF on SOx pin|Step on SOx = 1.2 V, GCSA = 1 V/A|1|μs|
|tSET|Settling time to ±1%, 30 pF on SOx pin|Step on SOx = 1.2 V, GCSA = 2 V/A|1|μs|
|VDRIFT|Drift offset|Phase current = 0 A|–150<br>150|µA/℃|
|ICSAREF|CSAREF input current|CSAREF = 3.0 V|1.7<br>3|mA|
|**PROTECTION CIRCUITS**|**PROTECTION CIRCUITS**|**PROTECTION CIRCUITS**|**PROTECTION CIRCUITS**|**PROTECTION CIRCUITS**|
|VUVLO|Supply undervoltage lockout (UVLO)|VM rising|2.6<br>2.7<br>2.8|V|
|VUVLO|Supply undervoltage lockout (UVLO)|VM falling|2.5<br>2.6<br>2.7|V|
|VUVLO_HYS|Supply undervoltage lockout hysteresis|Rising to falling threshold|60<br>125<br>210|mV|
|tUVLO|Supply undervoltage deglitch time||5<br>7.5<br>13|µs|
|VVINAVDD_UV|AVDD supply input undervoltage lockout<br>(VINAVDD_UV)|VIN_AVDD rising|2.6<br>2.7<br>2.8|V|
|VVINAVDD_UV|AVDD supply input undervoltage lockout<br>(VINAVDD_UV)|VIN_AVDD falling|2.5<br>2.6<br>2.7|V|
|VVINAVDD_UV<br>_HYS|AVDD supply input undervoltage lockout<br>hysteresis|Rising to falling threshold|100<br>125<br>150|mV|
|tVINAVDD_UV|AVDD supply input undervoltage deglitch<br>time||2.5<br>4<br>5|µs|
|VCPUV|Charge pump undervoltage lockout<br>(voltage with respect to VM)|VCPrising|2<br>2.3<br>2.5|V|
|VCPUV|Charge pump undervoltage lockout<br>(voltage with respect to VM)|VCP falling|2<br>2.2<br>2.4|V|
|VCPUV_HYS|Charge pump undervoltage lockout<br>hysteresis|Rising to falling threshold|65<br>100<br>125|mV|
|tCPUV|Charge pump undervoltage lockout<br>deglitch time||0.2<br>0.5|µs|
|VCSAREF_UV|CSA reference undervoltage lockout|VCSAREF rising|1.68<br>1.8<br>1.95|V|
|VCSAREF_UV|CSA reference undervoltage lockout|VCSAREFfalling|1.6<br>1.7<br>1.85|V|
|VCSAREF_<br>UV_HYS|CSA reference undervoltage lockout<br>hysteresis|Rising to falling threshold|70<br>90<br>110|mV|
|VAVDD_UV|Analog regulator undervoltage lockout|VAVDD rising|1.8<br>2<br>2.2|V|
|VAVDD_UV|Analog regulator undervoltage lockout|VAVDD falling|1.7<br>1.8<br>1.95|V|
|IOCP|Overcurrent protection trip point|OCP_LVL = 0 (SPI Variant) or MODE pin<br>tied to AGND or MODE pin to Hi-Z (HW<br>Variant)|5.8<br>9<br>11.5|A|
|IOCP|Overcurrent protection trip point|OCP_LVL = 1 (SPI Variant) or MODE pin<br>tied to AVDD or MODE pin 47 kΩ +/- 5%<br>tied to AGND  (HW Variant)|3.4<br>5<br>7.5|A|



12 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



at TJ = –40°C to +150°C, VVM = 3 to 20 V (unless otherwise noted). Typical limits apply for TA = 25°C, VVM = 12 V





















|PARAMETER|Col2|TESTCONDITIONS|MIN TYP MAX|UNIT|
|---|---|---|---|---|
|tBLANK|Overcurrent protection blanking time<br>(SPI Variant)|OCP_TBLANK = 00b|0.2|µs|
|tBLANK|Overcurrent protection blanking time<br>(SPI Variant)|OCP_TBLANK = 01b|0.5|µs|
|tBLANK|Overcurrent protection blanking time<br>(SPI Variant)|OCP_TBLANK = 10b|0.8|µs|
|tBLANK|Overcurrent protection blanking time<br>(SPI Variant)|OCP_TBLANK = 10b|1|µs|
|tBLANK|Overcurrent protection blanking time<br>(HW Variant)||0.2|µs|
|tOCP_DEG|Overcurrent protection deglitch time (SPI<br>Variant)|OCP_DEG = 00b|0.2|µs|
|tOCP_DEG|Overcurrent protection deglitch time (SPI<br>Variant)|OCP_DEG = 01b|0.5|µs|
|tOCP_DEG|Overcurrent protection deglitch time (SPI<br>Variant)|OCP_DEG = 10b|0.8|µs|
|tOCP_DEG|Overcurrent protection deglitch time (SPI<br>Variant)|OCP_DEG = 11b|1|µs|
|tOCP_DEG|Overcurrent protection deglitch time (HW<br>Variant)||1|µs|
|tRETRY|Overcurrent protection retry time (SPI<br>Variant)|FAST_RETRY = 00b|0.24<br>0.5<br>0.65|ms|
|tRETRY|Overcurrent protection retry time (SPI<br>Variant)|FAST_RETRY = 01b|0.7<br>1<br>1.2|ms|
|tRETRY|Overcurrent protection retry time (SPI<br>Variant)|FAST_RETRY = 10b|1.6<br>2<br>2.2|ms|
|tRETRY|Overcurrent protection retry time (SPI<br>Variant)|FAST_RETRY = 11b|4.4<br>5<br>5.3|ms|
|tRETRY|Overcurrent protection retry time (SPI<br>Variant)|SLOW_RETRY = 00b|390<br>500<br>525|ms|
|tRETRY|Overcurrent protection retry time (SPI<br>Variant)|SLOW_RETRY = 01b|840<br>1000<br>1050|ms|
|tRETRY|Overcurrent protection retry time (SPI<br>Variant)|SLOW_RETRY = 10b|1700<br>2000<br>2200|ms|
|tRETRY|Overcurrent protection retry time (SPI<br>Variant)|SLOW_RETRY = 11b|4400<br>5000<br>5400|ms|
|tRETRY|Overcurrent protection retry time (HW<br>Variant)||5|ms|
|TOTW|Thermal warning temperature|Die temperature (TJ) Rising|170<br>178<br>185|°C|
|TOTW_HYS|Thermal warning hysteresis|Die temperature (TJ)|25<br>30|°C|
|TTSD|Thermal shutdown temperature|Die temperature (TJ) Rising|180<br>190<br>200|°C|
|TTSD_HYS|Thermal shutdown hysteresis|Die temperature (TJ)|25<br>30|°C|
|TTSD|Thermal shutdown temperature (LDO)|Die temperature (TJ) Rising|180<br>190<br>200|°C|
|TTSD_HYS|Thermal shutdown hysteresis (LDO)|Die temperature (TJ)|25<br>30|°C|


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 13


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


at TJ = –40°C to +150°C, VVM = 3 to 20 V (unless otherwise noted). Typical limits apply for TA = 25°C, VVM = 12 V



|PARAMETER|Col2|TESTCONDITIONS|MIN TYP MAX|UNIT|
|---|---|---|---|---|
|**PWM OUTPUT ACCURACY (tSPI)**|**PWM OUTPUT ACCURACY (tSPI)**|**PWM OUTPUT ACCURACY (tSPI)**|**PWM OUTPUT ACCURACY (tSPI)**|**PWM OUTPUT ACCURACY (tSPI)**|
|RPWM|Output PWM Resolution|PWM FREQUENCY = 20 kHz|10|bits|
|APWM|Output PWM Accuracy|VVM< 4.5V, PWM_SYNC and Clock<br>Tuning Disabled|-7.5<br>7.5|%|
|APWM|Output PWM Accuracy|VVM >4.5V, PWM_SYNC and Clock<br>Tuning Disabled|-4<br>4|%|
|APWM|Output PWM Accuracy|PWM_SYNC Enabled and Clock Tuning<br>Disabled|-1<br>1|%|
|APWM|Output PWM Accuracy|PWM_SYNC Disabled and<br>SPISYNC_ACRCY = 11b|-2<br>2|%|
|APWM|Output PWM Accuracy|PWM_SYNC Disabled and<br>SPISYNC_ACRCY = 10b|-1<br>1|%|
|APWM|Output PWM Accuracy|PWM_SYNC Disabled and<br>SPISYNC_ACRCY = 01b|-1<br>1|%|
|APWM|Output PWM Accuracy|PWM_SYNC Disabled and<br>SPISYNC_ACRCY = 00b|-1<br>1|%|


**7.6 SPI Timing Requirements**





|Col1|Col2|MIN NOM MAX|UNIT|
|---|---|---|---|
|tREADY|SPI ready after power up|1|ms|
|tHI_nSCS|nSCS minimum high time|300|ns|
|tSU_nSCS|nSCS input setup time|25|ns|
|tHD_nSCS|nSCS input hold time|25|ns|
|tSCLK|SCLK minimum period|100|ns|
|tSCLKH|SCLK minimum high time|50|ns|
|tSCLKL|SCLK minimum low time|50|ns|
|tSU_SDI|SDI input data setup time|25|ns|
|tHD_SDI|SDI input data hold time|25|ns|
|tDLY_SDO|SDO output data delay time|75|ns|
|tEN_SDO|SDO enable delay time|65|ns|
|tDIS_SDO|SDO disable delay time|50|ns|


14 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**7.7 SPI Secondary Device Mode Timings**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)











|t t t|Col2|Col3|
|---|---|---|
|tHI_nSCS<br>tSU_nSCS<br>tSCLK<br>tSCLKH<br>tSCLKL<br>MSB<br>LSB<br>tHD_SDI<br>tSU_SDI<br>Z<br>Z<br>MSB<br>LSB<br>tHD_nSCS<br>tDIS_SDO<br>X<br>X<br>tEN_SDO<br>tDLY_SDO|tHI_nSCS<br>tSU_nSCS<br>tSCLK<br>tSCLKH<br>tSCLKL<br>MSB<br>LSB<br>tHD_SDI<br>tSU_SDI<br>Z<br>Z<br>MSB<br>LSB<br>tHD_nSCS<br>tDIS_SDO<br>X<br>X<br>tEN_SDO<br>tDLY_SDO||
|X|X|X|
|Z|||
||||


**Figure 7-1. SPI Secondary Device Mode Timing Diagram**


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 15


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**7.8 Typical Characteristics**










|Col1|Col2|Col3|Col4|Col5|Col6|Col7|Col8|Col9|Col10|
|---|---|---|---|---|---|---|---|---|---|
|||||||||||
|||||||||||
|||||||||||
|||||||||||
||||||||||o|
||||||~~F~~<br>F<br>|~~PWM =~~<br>PWM =<br>|~~  5kHz,~~<br>  25kHz,<br>|~~   TJ = -~~<br>   TJ = 2<br>|~~  0C~~<br>  5oC<br> ~~o~~|
|||||||||||
||||||~~F~~<br>F<br>F|PWM~~ =~~<br>PWM = <br> =|~~  5kHz,~~<br> 200kHz<br>  00kHz|~~   T~~J~~ = 1~~<br>, TJ = -<br>   T =|~~  0C~~<br>40oC<br>  5~~o~~C|
||||||~~F~~|WM <br>~~PWM =~~|<br>~~  200kHz~~|,J <br>~~ , TJ =~~|<br>~~  150~~o~~C~~|
|||||||||||



9


8


7


6


5


4


3


2


1





3.4


3.38


3.36


3.34


3.32


3.3


3.28


3.26





0

|Col1|TJ = -4|0oC<br>o|Col4|Col5|Col6|Col7|Col8|Col9|
|---|---|---|---|---|---|---|---|---|
|<br>|J~~ = 2~~<br> TJ = 1|~~C~~<br> 50oC|||||||
||||||||||
||||||||||
||||||||||
||||||||||
||||||||||
||||||||||
||||||||||



2 4 6 8 10 12 14 16 18 20

VM Supply Voltage (V)


**Figure 7-4. Sleep current over supply voltage**



3.24

|Col1|Col2|Col3|Col4|VM =|VINA|VDD =|12V,|T J = -|40oC<br>o|
|---|---|---|---|---|---|---|---|---|---|
|||||||||||
|||||~~VM~~<br>VM =|~~ VINA~~<br> VINA|~~ DD~~<br> VDD =|~~  12V,~~<br>  12V,|~~ J =~~<br>   T J = 1|~~ 5C~~<br> 50oC|
|||||||||||
|||||||||||
|||||||||||
|||||||||||
|||||||||||
|||||||||||
|||||||||||



0 0.01 0.02 0.03 0.04 0.05 0.06 0.07 0.08 0.09 0.1

AVDD Output Load Current (A)


**Figure 7-5. AVDD regulator output voltage over**



**load current**


16 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**8 Detailed Description**

**8.1 Overview**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



The DRV8311 is an integrated MOSFET driver for 3-phase motor-drive applications. The combined high-side
and low-side FET's on-state resistance is 210-mΩ typical. The device reduces system component count, cost,
and complexity by integrating three half-bridge MOSFETs, gate drivers, charge pump, current sense amplifier
and linear regulator for an external load. For the DRV8311S, a standard serial peripheral interface (SPI) provides
a simple method for configuring the various device settings and reading fault diagnostic information through an
external controller. For the DRV8311H, a hardware interface (H/W) allows for configuring the most commonly
used settings through fixed external resistors. For the DRV8311P, Texas Instruments SPI (tSPI) provides the
ability to configure various device settings and adjust the PWM duty cycle and frequency to control multiple
motors at a time.


The architecture uses an internal state machine to protect against short-circuit events, and protect against dV/dt
parasitic turn on of the internal power MOSFETs.


The DRV8311 device integrates three bidirectional low side current-shunt amplifiers for monitoring the current
through each of the half-bridges using a built-in current sense and no external current sense resistors are
needed. The gain setting of the shunt amplifier can be adjusted through the SPI, tSPI or hardware interface.


In addition to the high level of device integration, the DRV8311 device provides a wide range of integrated
protection features. These features include power supply undervoltage lockout (UVLO), charge pump
undervoltage lockout (CPUV), overcurrent protection (OCP), AVDD undervoltage lockout (AVDD_UV) and
overtemperature shutdown (OTW and OTSD). Fault events are indicated by the nFAULT pin with detailed
information available in the registers on the SPI and tSPI device versions.


The DRV8311H, DRV8311P and DRV8311S devices are available in 0.4-mm pin pitch, WQFN surface-mount
packages. The WQFN package size is 3.00 mm × 3.00 mm.


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 17


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**8.2 Functional Block Diagram**


VM




























|Col1|Col2|
|---|---|
|||
|||














|Col1|Col2|Col3|Col4|Col5|
|---|---|---|---|---|
|SOC<br>CCSAREF|SOC<br>CCSAREF||||
|SOC<br>CCSAREF|SOC<br>CCSAREF|||Output Offset<br>Bias|



**Figure 8-1. DRV8311S Block Diagram**


18 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**





**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)


VM




























|Col1|Col2|Col3|Col4|Col5|
|---|---|---|---|---|
||||||
||||||
||||||
||||||
||||||
||||||
||||||
||||||
||||||
||||||
||||||
||||||
||||||
||||||












|CCSAREF<br>SOC|Col2|Col3|Col4|
|---|---|---|---|
|SOC<br>CCSAREF|||Output Offset<br>Bias|



**Figure 8-2. DRV8311H Block Diagram**


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 19


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


VM




























|Col1|Col2|
|---|---|
|||
|||
|||
|||
|||














|CCSAREF<br>SOC|Col2|Col3|Col4|
|---|---|---|---|
|SOC<br>CCSAREF|||Output Offset<br>Bias|



**Figure 8-3. DRV8311P Block Diagram**


20 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


