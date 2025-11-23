**[www.ti.com](https://www.ti.com)**


**8.3.4 AVDD Linear Voltage Regulator**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



A 3.3-V, 100mA linear regulator is integrated into the DRV8311 family of devices and is available to power
external circuits. The AVDD regulator is used for powering up the internal digital functions of the DRV8311 and
can also provide the supply voltage for a low-power MCU or another circuitry up to 100 mA. The output of the
AVDD regulator should be bypassed near the AVDD and AGND pins with a X5R or X7R, up to 4.7-µF, 6.3-V
ceramic capacitor routed directly back to the adjacent AGND ground pin.


The AVDD nominal, no-load output voltage is 3.3 V.


VIN_AVDD



REF





AVDD



External Load


|+<br>±|Col2|Col3|
|---|---|---|
|+<br>±|||



**Figure 8-16. AVDD Linear Regulator Block Diagram**


Use Equation 1 to calculate the power dissipated in the device by the AVDD linear regulator.


P = (VVIN_AVDD - VAVDD) x IAVDD (1)


The supply input voltage for AVDD regulator (VIN_AVDD) can be same as VM supply voltage, or lower or higher
than VM supply voltage.


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 31


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**8.3.5 Charge Pump**


Because the output stages use N-channel FETs, the device requires a gate-drive voltage higher than the VM
power supply to enhance the high-side FETs fully. The DRV8311 integrates a charge pump circuit that generates
a voltage above the VM supply for this purpose.


The charge pump requires a single external capacitor for operation. See Table 8-1 for details on the capacitor
value.


The charge pump shuts down when nSLEEP is low.






|VM<br>Charge<br>CFLY Pump<br>Control|Col2|Col3|
|---|---|---|
|Charge<br>Pump<br>Control<br>VM<br>CFLY|VM<br>CFLY|Charge<br>Pump<br>Control|



**Figure 8-17. DRV8311 Charge Pump**


32 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**8.3.6 Slew Rate Control**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



An adjustable gate-drive current control to the MOSFETs allows for easy slew rate control. The MOSFET VDS
slew rates are a critical factor for optimizing radiated emissions, energy and duration of diode recovery spikes
and switching voltage transients related to parasitic. These slew rates are predominantly determined by the rate
of gate charge to internal MOSFETs as shown in Figure 8-18.


VM


CP


Slew Rate

Control



VLS



OUTx


PGND



Slew Rate

Control


|Col1|Col2|Col3|Col4|
|---|---|---|---|
|||||



**Figure 8-18. Slew Rate Circuit Implementation**


The slew rate of each half-bridge can be adjusted by SLEW pin in hardware device variant or by using SLEW
register settings in SPI device variant. The slew rate is calculated by the rise-time and fall-time of the voltage on
OUTx pin as shown in Figure 8-19.


VOUTx


VM





|Col1|VM<br>80% 80%<br>20%<br>20%|Col3|Col4|Col5|Col6|
|---|---|---|---|---|---|
|||||||
||||||Time|


trise



tfall





0





**Figure 8-19. Slew Rate Timings**


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 33


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**8.3.7 Cross Conduction (Dead Time)**


The device is fully protected from cross conduction of MOSFETs. The high-side and low-side MOSFETs are
operated to avoid any shoot through currents by inserting a dead time (tDEAD). This is implemented by sensing
the gate-source voltage (VGS) of the high-side and low-side MOSFETs and ensured that VGS of high-side
MOSFET has reached below turn-off levels before switching on the low-side MOSFET of same half-bridge
as shown in Figure 8-20 and Figure 8-21. The VGS of the high-side and low-side MOSFETs (VGS_HS and
VGS_LS) shown in Figure 8-21 are DRV8311 internal signals.


VM



OUTx



tDEAD







PGND

|Gate<br>Control<br>VGS +<br>–<br>Gate<br>Control<br>VGS +<br>–|Col2|Col3|
|---|---|---|
|Gate<br>Control<br>Gate<br>Control<br>–<br>+<br>–<br>+<br>VGS<br>VGS|||



**Figure 8-20. Cross Conduction Protection**



OUTx HS

Gate
(VGS_HS)


OUTx LS

Gate
(VGS_LS)







Time

|OUTxHSGate<br>10%<br>tDEAD<br>10%<br>OUTxLSGate|Col2|Col3|
|---|---|---|
|OUTx HS Gate<br>OUTx LS Gate<br>tDEAD<br>10%<br>10%|tDEAD|10%|
||||
|||Tim|



**Figure 8-21. Dead Time**


34 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**8.3.8 Propagation Delay**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



The propagation delay time (tpd) is measured as the time between an input logic edge to change in OUTx
voltage. The propagation delay time includes the input deglitch delay, analog driver delay, and depends on the
slew rate setting . The input deglitcher prevents high-frequency noise on the input pins from affecting the output
state of the gate drivers. To support multiple control modes, a small digital delay is added as the input command
propagates through the device.


INx





OUTx





|OUTxHigh<br>tPD<br>10%<br>OUTxLow|Col2|
|---|---|
|tPD<br>OUTx Low<br>OUTx High<br>10%|tPD<br>OUTx High<br>10%|
|OUTx Low|OUTx Low|
|||
|Time|Time|


**Figure 8-22. Propagation Delay**


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 35


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**8.3.9 Pin Diagrams**


This section presents the I/O structure of all digital input and output pins.


_**8.3.9.1 Logic Level Input Pin (Internal Pulldown)**_


Figure 8-23 shows the input structure for the logic levels pins INHx, INLx, nSLEEP, SCLK and SDI. The input
can be driven with an external resistor to GND or an external logic voltage supply. It is recommended to pull
these pins low in device sleep mode to reduce leakage current through the internal pull-down resistors.


AVDD











VIL Tied to GND Logic Low

|STATE|CONNECTION|
|---|---|
|VIH|Tied to AVDD|
|VIL|Tied to GND|


|VDD|Col2|Col3|Col4|
|---|---|---|---|
||RPD<br>ESD|RPD<br>ESD|RPD<br>ESD|
||RPD<br>ESD|D|RPD|



**Figure 8-23. Logic-Level Input Pin Structure**


_**8.3.9.2 Logic Level Input Pin (Internal Pullup)**_


Figure 8-24 shows the input structure for the logic level pin nSCS. The input can be driven with an external
resistor to GND or an external logic voltage supply .













VIL Tied to GND Logic Low




|STATE|CONNECTION|
|---|---|
|VIH|Tied to AVDD|
|VIL|Tied to GND|


|Col1|INPUT|
|---|---|
||Logic High|
||Logic Low|



**Figure 8-24. nSCS Input Pin Structure**


_**8.3.9.3 Open Drain Pin**_


Figure 8-25 shows the structure of the open-drain output pin nFAULT. The open-drain output requires an external
pullup resistor to a logic voltage supply to function properly.


AVDD












|STATE|STATUS|
|---|---|
|No Fault|Pulled-Up|
|Fault|Pulled-Down|


|RPU|ESD|Col3|
|---|---|---|
||||
||||
||||


|Col1|OUTPUT|
|---|---|
||Inactive|
||Active|



**Figure 8-25. Open Drain Output Pin Structure**


36 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


_**8.3.9.4 Push Pull Pin**_


Figure 8-26 shows the structure of the push-pull pin SDO.



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)


AVDD












|STATE|STATUS|
|---|---|
|VOH|Pulled-Up|
|VOL|Pulled-Down|
|Hi-Z|Open|


|Col1|ESD|Col3|
|---|---|---|
||ESD||
||ESD||
||ESD||
||ESD||


|Col1|OUTPUT|
|---|---|
||Logic High|
||Logic Low|
||Hi-Z|



**Figure 8-26. Push-Pull Output Pin Structure**


_**8.3.9.5 Four Level Input Pin**_


Figure 8-27 shows the structure of the four level input pins GAIN, MODE and SLEW on hardware interface
devices. The input can be set by tying the pin to AGND or AVDD, leaving the pin unconnected, or connecting an
external resistor from the pin to ground.


















|STATE|RESISTANCE|
|---|---|
|VL1|Tied to AGND|
|VL2|47 k ±5%<br>to AGND|
|VL3|Hi-Z|
|VL4|Tied to AVDD|


|+<br>–<br>+<br>–<br>+<br>–|CONTROL|
|---|---|
|+<br>–<br>+<br>–<br>+<br>–|Setting-1|
|+<br>–<br>+<br>–<br>+<br>–|Setting-2|
|+<br>–<br>+<br>–<br>+<br>–|Setting-3|
|+<br>–<br>+<br>–<br>+<br>–|Setting-4|



**Figure 8-27. Four Level Input Pin Structure**


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 37


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


(



**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


**8.3.10 Current Sense Amplifiers**


The DRV8311 integrate three high-performance low-side current sense amplifiers for current measurements
using built-in current sense. Low-side current measurements are commonly used to implement overcurrent
protection, external torque control, or brushless DC commutation with the external controller. All three amplifiers
can be used to sense the current in each of the half-bridge legs (low-side MOSFETs). The current sense
amplifiers include features such as programmable gain and an external voltage reference (VREF) provided on
the pin CSAREF.


_**8.3.10.1 Current Sense Amplifier Operation**_


The SOx pin on the DRV8311 outputs an analog voltage proportional to current flowing in the low side FETs
(IOUTx) multiplied by the gain setting (GCSA). The gain setting is adjustable between four different levels which
can be set by the GAIN pin (hardware device variant) or the CSA_GAIN bits (SPI or tSPI device variant).


Figure 8-28 shows the internal architecture of the current sense amplifiers. The current sense is implemented
with a sense FET on each low-side FET of the DRV8311 device. This current information is converted in to a
voltage, which generates the CSA output voltage on the SOx pin, based on the voltage on the CSAREF pin
(VREF) and the gain setting. The CSA output voltage can be calculated using Equation 2


(



SOx = (



VREF
2 ± G( CSA × IOUTx (2)



(



(



(

|VM|Col2|Col3|Col4|
|---|---|---|---|
|PGND<br>I/V Converter<br>Sense<br>FET<br>VREF|PGND<br>I/V Converter<br>Sense<br>FET<br>VREF|OUTx|OUTx|
|PGND<br>I/V Converter<br>Sense<br>FET<br>VREF||||
|PGND<br>I/V Converter<br>Sense<br>FET<br>VREF||||



SOx



(



(


**Figure 8-28. Integrated Current Sense Amplifier**


38 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



Figure 8-29 and Figure 8-30 show the details of the amplifier operational range. In bi-directional operation, the
amplifier output for 0-V input is set at VREF/2. Any change in the differential input results in a corresponding
change in the output times the GCSA factor. The amplifier has a defined linear region in which it can maintain
operation.


SOX


VREF


VVREF ± 0.25 V


±IOUTx

VSO(range±)


VSO(off)max


VVREF / 2 VOFF, VDRIFT 0 V


VSO(off)min


VSO(range+)
IOUTx


0.25 V


0 V


**Figure 8-29. Bidirectional Current Sense Output**


SOX (V)

|Col1|Col2|VREF|Col4|
|---|---|---|---|
|||||
|||||
||VLINEAR|VREF / 2||
||VLINEAR|||
|||||
|||||



IOUTx (A) (Current flowing into the FET)


**Figure 8-30. Bidirectional Current Sense Regions**


**Note**
The current sense amplifiers uses the external voltage reference (VREF) provided at the CSAREF pin.


_**8.3.10.2 Current Sense Amplifier Offset Correction**_


CSA output has an offset induced due to ground differences between the sense FET and output FET. When
running trapezoidal control or another single-shunt based control (sensored sine, for example) this CSA offset
has no impact to operation. When running sensorless sinusoidal or FOC control where two or three current
sense are required, some current distortion and noise may occur unless the user implements the corrective
action below.


**Corrective Action** : Implement the below equations in firmware to correct for any current induced offset:


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 39


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


(


(


(



**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


1. When all three current sense amplifiers are used:


ia = 1.001152*ia_sensed −0.003375*ib_sensed −0.003103*ic_sensed (3)


ib = 0.002369*iasensed + 1.000665*ib_sensed −0.019126*ic_sensed (4)


ic = 0.001234*iasensed + 0.001595*ibsensed + 0.998166*ic_sensed (5)


2. When only two of the three current sense amplifiers are used:
a. Current sensed in phases A & B:


ia = 1.004346*ia_sensed −0.000199*ib_sensed (6)


ib = 0.022060*iasensed + 1.020405*ib_sensed (7)


ic = − i( a + ib (8)


b. Current sensed in phases B & C:


ib = 0.998309*ib_sensed −0.021427*ic_sensed (9)


ic = 0.000368*ibsensed + 0.996967*ic_sensed (10)


ia = − i( b + ic (11)


c. Current sensed in phases C & A


ia = 1.004547*iasensed + 0.000195*ic_sensed (12)


ic = 0.000371*iasensed + 0.996975*ic_sensed (13)


ib = − i( a + ic (14)


40 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**8.3.11 Protections**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



The DRV8311 family of devices is protected against VM, VIN_AVDD, AVDD and CP undervoltage, overcurrent
and thermal events. Table 8-6 summarizes various faults details.


**Table 8-6. Fault Action and Response**


























|FAULT|CONDITION|CONFIGURATION|REPORT|H-BRIDGE|LOGIC|RECOVERY|
|---|---|---|---|---|---|---|
|VM undervoltage<br>(NPOR)|VVM < VUVLO|—|—|Hi-Z|Disabled|Automatic:<br>VVM > VUVLO_R<br>CLR_FLT, nSLEEP Reset Pulse (NPOR<br>bit)|
|VINAVDD<br>undervoltage<br>(VINAVDD_UV)|VVINAVDD < VVINAVDD_UV|—|nFAULT|Hi-Z|Active<br>(SPI disabled)|Configured using UVP_MODE|
|AVDD undervoltage<br>(AVDD_UV)|VAVDD < VAVDD_UV|—|nFAULT|Hi-Z|Active<br>(SPI disabled)|Configured using UVP_MODE|
|Charge pump<br>undervoltage<br>(CP_UV)|VCP < VCPUV|—|nFAULT|Hi-Z|Active|Configured using UVP_MODE|
|CSAREF<br>undervoltage<br>(CSAREF_UV)|VCSAREF < VCSAREF_UV|CSAREFUV_EN= 1b|nFAULT|Active<br>(CSA disabled)|Active|Configured using UVP_MODE|
|CSAREF<br>undervoltage<br>(CSAREF_UV)|VCSAREF < VCSAREF_UV|CSAREFUV_EN= 0b|None|Active|Active|No Action|
|Overcurrent<br>protection<br>(OCP)|IPHASE > IOCP|OCP_MODE = 000b|nFAULT|Hi-Z|Active|Automatic Retry:<br>SLOW_TRETRY|
|Overcurrent<br>protection<br>(OCP)|IPHASE > IOCP|OCP_MODE = 001b|nFAULT|Hi-Z|Active|Automatic Retry:<br>FAST_TRETRY|
|Overcurrent<br>protection<br>(OCP)|IPHASE > IOCP|OCP_MODE = 010b|nFAULT|Hi-Z|Active|Latched:<br>CLR_FLT, nSLEEP Reset Pulse|
|Overcurrent<br>protection<br>(OCP)|IPHASE > IOCP|OCP_MODE = 011b|nFAULT|Active|Active|No action|
|Overcurrent<br>protection<br>(OCP)|IPHASE > IOCP|OCP_MODE = 111b|None|Active|Active|No action|
|SPI fault<br>(SPI_FLT)|SCLK fault and ADDR<br>fault|SPIFLT_MODE = 0b|nFAULT|Active|Active|Automatic|
|SPI fault<br>(SPI_FLT)|SCLK fault and ADDR<br>fault|SPIFLT_MODE = 1b|None|Active|Active|No action|
|Thermal warning<br>(OTW)|TJ > TOTW|OTW_EN = 0b|None|Active|Active|No action|
|Thermal warning<br>(OTW)|TJ > TOTW|OTW_EN = 1b|nFAULT|Active|Active|Automatic:<br>TJ < TOTW – THYS|
|Thermal shutdown<br>(OTSD)|TJ > TOTSD|OTSD_MODE = 00b|nFAULT|Hi-Z|Active|Automatic<br>SLOW_TRETRY after<br>TJ < TOTSD – THYS|
|Thermal shutdown<br>(OTSD)|TJ > TOTSD|OTSD_MODE = 01b|nFAULT|Hi-Z|Active|Automatic<br>FAST_TRETRY after<br>TJ < TOTSD – THYS|



Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 41


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


_**8.3.11.1 VM Supply Undervoltage Lockout (NPOR)**_


If at any time the input supply voltage on the VM pin falls lower than the VUVLO threshold (VM UVLO falling
threshold), all of the integrated FETs, driver charge-pump and digital logic controller are disabled as shown in
Figure 8-31. Normal operation resumes (driver operation) when the VM undervoltage condition is removed. The
NPOR bit is reset and latched low in the device status (DEV_STS1) register once the device presumes VM. The
NPOR bit remains in reset condition until cleared through the CLR_FLT bit or an nSLEEP pin reset pulse (tRST).


VUVLO (max) rising

VUVLO (min) rising


VUVLO (max) falling



VUVLO (min) falling



|Col1|VVM<br>DEVICEON DEVICEOFF DEVICEON|Col3|Col4|
|---|---|---|---|
||VVM<br>DEVICE ON<br>DEVICE OFF|VVM<br>DEVICE ON<br>DEVICE OFF|VVM<br>DEVICE ON<br>DEVICE OFF|
||VVM<br>DEVICE ON<br>DEVICE OFF|VVM<br>DEVICE ON<br>DEVICE OFF|VVM<br>DEVICE ON<br>DEVICE OFF|
|||||
|||||
||DEVICE ON|||


Time


**Figure 8-31. VM Supply Undervoltage Lockout**



_**8.3.11.2 Under Voltage Protections (UVP)**_


Other than VM ULVO, DRV8311 family of devices has under voltage protections for VIN_AVDD, CSAREF,
AVDD and CP pins. VINAVDD_UV, CP_UV and AVDD_UV under voltage protections are enabled and cannot
be disabled, while CSAREF_UV is disabled by default and can be enabled in SPI variant by configuring
CSAREFUV_EN in SYSF_CTRL register.


In hardware device variants, AVDD_UV, VINAVDD_UV, CP_UV protections are enabled, while CSAREF_UV is
disabled and the tRETRY is configured for fast automatic retry time to 5 ms.


tRETRY configuration for SPI device variant for all UV protections

 - Slow retry time SLOW_TRETRY can be used for tRETRY period by configuring UVP_MODE to 000b

 - Fast retry time FAST_TRETRY can be used for tRETRY period by configuring UVP_MODE to 001b


**VINAVDD Under Voltage Protections (VINAVDD_UV)**


If at any time the voltage on VIN_AVDD pin falls lower than the VVINAVDD_UV threshold, all of the integrated FETs,
SPI communication is disabled, nFAULT pin is driven low, FAULT and UVP in DEV_STS1 and VINAVDD_UV
in SUP_STS are set high. Normal operation starts again automatically (driver operation, the nFAULT pin is
released and VINAVDD_UV bit is cleared) after VIN_AVDD pin rises above the VVINAVDD_UV threshold and the
tRETRY time elapses. The FAULT and UVP bits stay latched high until a clear fault command is issued either
through the CLR_FLT bit or an nSLEEP reset pulse (tRST).


**AVDD Under Voltage Protections (AVDD_UV)**


If at any time the voltage on AVDD pin falls lower than the VAVDD_UV threshold, all of the integrated FETs,
SPI communication is disabled, nFAULT pin is driven low, FAULT and UVP in DEV_STS1 and AVDD_UV
in SUP_STS are set high. Normal operation starts again automatically (driver operation, the nFAULT pin is
released and AVDD_UV bit is cleared) after AVDD pin rises above the VAVDD_UV threshold and the tRETRY time
elapses. The FAULT and UVP bits stay latched high until a clear fault command is issued either through the
CLR_FLT bit or an nSLEEP reset pulse (tRST).


42 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**CSAREF Under Voltage Protections (CSAREF_UV)**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



If at any time the voltage on CSAREF pin falls lower than the VCSAREF_UV threshold, CSAREF_UV is recognized.
CSA_UV can be enabled or disabled by configuring CSAREFUV_EN. When enabled, after CSAREF_UV event,
CSA are disabled, nFAULT pin is driven low, FAULT and UVP in DEV_STS1 and CSAREF_UV in SUP_STS
are set high. Normal operation starts again automatically (CSA operation, the nFAULT pin is released and
CSAREF_UV bit is cleared) after CSAREF_UV condition is cleared and the tRETRY time elapses. The FAULT and
UVP bits stay latched high until a clear fault command is issued either through the CLR_FLT bit or an nSLEEP
reset pulse (tRST).


**Note**


CSAREF_UV is disabled in hardware variant and by default in SPI variants


**CP Under Voltage Protections (CP_UV)**


If at any time the voltage on CP pin falls lower than the VCP_UV threshold, all of the integrated FETs and charge
pump operation is disabled, nFAULT pin is driven low, FAULT and UVP in DEV_STS1 and CP_UV in SUP_STS
are set high. Normal operation starts again automatically (driver and charge pump operation, the nFAULT pin is
released and CP_UV bit is cleared) after CP pin rises above the VCP_UV threshold and the tRETRY time elapses.
The FAULT and UVP bits stay latched high until a clear fault command is issued either through the CLR_FLT bit
or an nSLEEP reset pulse (tRST).


_**8.3.11.3 Overcurrent Protection (OCP)**_


A MOSFET overcurrent event is sensed by monitoring the current flowing through FETs. If the current through
a FET exceeds the IOCP threshold for longer than the tOCP deglitch time, a OCP event is recognized and action
is done according to the OCP_MODE bit. In order to avoid false trigger of OCP during PWM transition due to
ringing in phase voltage, there is tBLANK blanking time applied at each edge of PWM signals in digital. During
blanking time, OCP events are ignored.


On hardware device variants, the IOCP threshold is 5A or 9A (typ) based on MODE pin, the tOCP_DEG is fixed
at 1-µs, tBLANK is fixed at 0.2-µs and the OCP_MODE bit is configured with fast retry with 5-ms automatic retry.
On SPI devices, the IOCP threshold is set through the OCP_LVL, the tOCP_DEG is set through the OCP_DEG,
the tBLANK is set through the OCP_TBLANK and the OCP_MODE bit can operate in four different modes: OCP
latched shutdown, OCP automatic retry with fast and slow retry times, OCP report only, and OCP disabled.


**8.3.11.3.1 OCP Latched Shutdown (OCP_MODE = 010b)**


After a OCP event in this mode, all MOSFETs are disabled and the nFAULT pin is driven low. The FAULT, OCP,
and corresponding FET's OCP bits are latched high in the SPI registers. Normal operation starts again (driver
operation, FAULT, OCP, and corresponding FET's OCP bits are cleared and the nFAULT pin is released) when
the OCP condition clears and a clear faults command is issued either through the CLR_FLT bit or an nSLEEP
reset pulse (tRST).


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 43


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[DRV8311](https://www.ti.com/product/DRV8311)**
[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2) **[www.ti.com](https://www.ti.com)**


IOCP


IOUTx


nFAULT






|PeakCurrentdue<br>todeglitchtime<br>tOCP<br>nFAULT Pulled High Fault Condition nFAULT Released<br>Time ClearFault|PeakCurrentdue<br>todeglitchtime|Col3|Col4|
|---|---|---|---|
|tOCP<br><br>Time<br>nFAULT Pulled High<br>Fault Condition<br>nFAULT Released<br>Peak Current due<br>to deglitch time<br>Clear Fault|tOCP|Fault Condition|nFAULT Released|



**Figure 8-32. Overcurrent Protection - Latched Shutdown Mode**


**8.3.11.3.2 OCP Automatic Retry (OCP_MODE = 000b or 001b)**


After a OCP event in this mode, all the FETs are disabled and the nFAULT pin is driven low. The FAULT, OCP,
and corresponding FET's OCP bits are set high in the SPI registers. Normal operation starts again automatically
(driver operation, the nFAULT pin is released and corresponding FET's OCP bits are cleared) after the tRETRY
time elapses. The FAULT and OCP stays latched high until clear faults command is issued either through the
CLR_FLT bit or an nSLEEP reset pulse (tRST).


tRETRY configuration

 - Slow retry time SLOW_TRETRY can be used for tRETRY period by configuring OCP_MODE to 000b

 - Fast retry time FAST_TRETRY can be used for tRETRY period by configuring OCP_MODE to 001b


IOCP


IOUTx







nFAULT



|PeakCurrentdue<br>todeglitchtime<br>tRETRY<br>tOCP<br>nFAULT Pulled High Fault Condition nFAULT Released<br>Time|PeakCurrentdue<br>todeglitchtime|Col3|Col4|
|---|---|---|---|
|tOCP<br><br>Time<br>nFAULT Pulled High<br>Fault Condition<br>nFAULT Released<br>Peak Current due<br>to deglitch time<br>tRETRY|tOCP|Fault Condition<br>tRETRY|nFAULT Released|


**Figure 8-33. Overcurrent Protection - Automatic Retry Mode**



44 _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ Copyright © 2022 Texas Instruments Incorporated


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


**[www.ti.com](https://www.ti.com)**


**8.3.11.3.3 OCP Report Only (OCP_MODE = 011b)**



**[DRV8311](https://www.ti.com/product/DRV8311)**

[SLVSFN2B – SEPTEMBER 2021 – REVISED FEBRUARY 2022](https://www.ti.com/lit/pdf/SLVSFN2)



No protective action occurs after a OCP event in this mode. The overcurrent event is reported by driving the
nFAULT pin low and setting the FAULT, OCP, and corresponding FET's OCP bits high in the SPI registers.
DRV8311 continue to operate as usual. The external controller manages the overcurrent condition by acting
appropriately. The reporting clears (nFAULT pin is released, FAULT, OCP, and corresponding FET's OCP bits are
cleared) when the OCP condition clears and a clear faults command is issued either through the CLR_FLT bit or
an nSLEEP reset pulse (tRST).


**8.3.11.3.4 OCP Disabled (OCP_MODE = 111b)**


No action occurs after a OCP event in this mode.


_**8.3.11.4 Thermal Protections**_


DRV8311 family of devices has over temperature warning (OTW) and over temperature shutdown (OTSD) for
over temperature events.


**8.3.11.4.1 Thermal Warning (OTW)**


If the die temperature exceeds the trip point of the thermal warning (TOTW), the OT bit in the device status
(DEV_STS1) register and OTW bit in the OT_STS status register is set. The reporting of OTW on the nFAULT
pin can be enabled by setting the over-temperature warning reporting (OTW_EN) bit in the configuration control
register. The device performs no additional action and continues to function. In this case, the nFAULT pin
releases and OTW bit cleared when the die temperature decreases below the hysteresis point of the thermal
warning (TOTW_HYS). The OT bit remains latched until cleared through the CLR_FLT bit or an nSLEEP reset
pulse (tRST) and the die temperature is lower than thermal warning trip (TOTW).


In hardware device variants, Over Temperature warning is not reported on nFAULT pin by default.


**8.3.11.4.2 Thermal Shutdown (OTSD)**


If the die temperature exceeds the trip point of the thermal shutdown limit (TOTS), all the FETs are disabled, the
charge pump is shut down, and the nFAULT pin is driven low. In addition, the FAULT and OT bit in the OT bit
in the device status (DEV_STS1) register and OTSD bit in the OT_STS status register is set. Normal operation
starts again (driver operation the nFAULT pin is released and OTSD bit cleared) when the overtemperature
condition clears and after the tRETRY time elapses. The OT and FAUTL bits stay latched high indicating that a
thermal event occurred until a clear fault command is issued either through the CLR_FLT bit or an nSLEEP reset
pulse (tRST). This protection feature cannot be disabled.


On hardware device variants the tRETRY period is fixed to fast retry time of 5ms


tRETRY configuration for SPI device variant

 - Slow retry time SLOW_TRETRY can be used for tRETRY period by configuring OTSD_MODE to 00b

 - Fast retry time FAST_TRETRY can be used for tRETRY period by configuring OTSD_MODE to 01b


Copyright © 2022 Texas Instruments Incorporated _[Submit Document Feedback](https://www.ti.com/feedbackform/techdocfeedback?litnum=SLVSFN2B&partnum=DRV8311)_ 45


Product Folder Links: _[DRV8311](https://www.ti.com/product/drv8311?qgpn=drv8311)_


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


