**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011

## **12-Bit, 1MSPS, 4-/8-Channel, Bipolar-Input, SAR Analog-to-Digital Converter** **with Software-Selectable Ranges**

**[Check for Samples: ADS8634, ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html#samples)**



**1FEATURES** **DESCRIPTION**


- The ADS8634 and ADS8638 (ADS8634/8) are 12-bit



**23** - **Selectable Input Range:**



± **10V,** ± **5V,** ± **2.5V, 0V to 10V, or** analog-to-digital converters (ADCs) capable of
**0V to 5V** measuring inputs up to ± 10V at 1MSPS. Using a
successive approximation register (SAR) core, these
**Up to** ± **12V with External Reference**
ADCs provide a sample-and-hold front-end with no

- **No Latent Conversions Up to 1MSPS** latency in conversions. The ADS8634 includes an

- **Outstanding Performance:** input multiplexer (mux) for measuring up to four

**12 Bits No Missing Codes** inputs. The ADS8638 can measure up to eight inputs.
**INL:** ± **0.9LSB** In addition to the input multiplexer, the ADS8634/8
**SNR: 71.8dB** feature an internal temperature sensor, voltage

- **Highly Integrated:** reference, and a digital comparator for setting alarm



**4- or 8-Channel Input Mux** thresholds on each input; therefore, a minimal



amount of external components are required. A
**Temperature Sensor**
simple SPI-compatible interface provides for
**Internal Voltage Reference**
communication and control. The digital supply
**Alarm Thresholds for Each Channel**
operates from 5V all the way down to 1.8V for direct

- **Low Power:** connection to a wide range of processors and
**14.45mW at 1MSPS** controllers.
**5.85mW at 0.1MSPS**
Ideal for demanding industrial measurement
**Flexible Power-Down Mode**
applications, the ADS8634/8 are fully specified over

- **SPI** ™ **-Compatible Serial Interface** the extended industrial temperature range of – 40 ° C

°

- **Extended Temperature Range:** to +125 C and are available in a small form-factor



– **40** ° **C to +125** ° **C** QFN-24 package.

- **Small Footprint: 4mm** × **4mm QFN Package**



**APPLICATIONS**


- **Industrial Process Controls (PLC)**

- **Data Acquisition Systems**

- **High-Speed, Closed-Loop Systems**

- **Digital Power Supplies**


HVDD AVDD REF DVDD



AVDD REF DVDD









HVDD





AIN0


AIN1


AIN2


AIN3


AINGND







AIN0


AIN1


AIN2


AIN3


AIN4


AIN5


AIN6


AIN7


AINGND







CS, SCLK,
DIN, DOUT



CS, SCLK,
DIN, DOUT


|Comparator|Col2|Col3|
|---|---|---|
|||SPI|


|Comparator|Col2|Col3|
|---|---|---|
|||SPI|






|Col1|Col2|Col3|MUX|
|---|---|---|---|
|||||
|||||
|||||
|Temp<br>Sensor|Temp<br>Sensor|Temp<br>Sensor|Temp<br>Sensor|
|Temp<br>Sensor|Temp<br>Sensor|||
|Temp<br>Sensor|Temp<br>Sensor|Temp<br>Sensor||


|Alarm<br>REF Threshold<br>Comparator<br>MUX<br>ADC<br>SPI<br>ST ee nm sop ADS8638<br>r|Col2|Col3|AL<br>CS<br>DI|
|---|---|---|---|
|MUX<br>SPI<br>REF<br>Alarm<br>Threshold<br>Comparator<br>ADC<br>**ADS8638**<br>Temp<br>Sensor|MUX<br>SPI<br>REF<br>Alarm<br>Threshold<br>Comparator<br>ADC<br>**ADS8638**<br>Temp<br>Sensor|MUX|MUX|
|||||
|||||
|||||
|||||
|||||
|||||
|||||
|||||
|Temp<br>Sensor|Temp<br>Sensor|||
|||||



HVSS



AGND



REFGND



DGND



HVSS



AGND



REFGND



DGND



1


Please be aware that an important notice concerning availability, standard warranty, and use in critical applications of Texas
Instruments semiconductor products and disclaimers thereto appears at the end of this data sheet.

2SPI is a trademark of Motorola.

3All other trademarks are the property of their respective owners.


PRODUCTION DATA information is current as of publication date. Copyright © 2011, Texas Instruments Incorporated
Products conform to specifications per the terms of the Texas
Instruments standard warranty. Production processing does not
necessarily include testing of all parameters.


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


This integrated circuit can be damaged by ESD. Texas Instruments recommends that all integrated circuits be handled with
appropriate precautions. Failure to observe proper handling and installation procedures can cause damage.


ESD damage can range from subtle performance degradation to complete device failure. Precision integrated circuits may be more
susceptible to damage because very small parametric changes could cause the device not to meet its published specifications.


**DEVICE COMPARISON** **[(1)]**

|PRODUCT|RESOLUTION|CHANNELS|SAMPLERATE|
|---|---|---|---|
|ADS8634|12-Bit|4|1MSPS|
|ADS8638|ADS8638|8|8|



(1) For the most current package and ordering information, see the Package Option Addendum at the end of this document, or visit the
[device product folder at www.ti.com.](http://www.ti.com)


**ABSOLUTE MAXIMUM RATINGS**


Over operating free-air temperature range, unless otherwise noted. [(1)]

|Col1|Col2|VALUE|UNIT|
|---|---|---|---|
|AINn to AGND or AINGND to AGND|AINn to AGND or AINGND to AGND|HVSS – 0.3 to HVDD + 0.3|V|
|AVDD to AGND or DVDD to DGND|AVDD to AGND or DVDD to DGND|–0.3 to 7|V|
|HVDD to AGND|HVDD to AGND|–0.3 to 18|V|
|HVSS to AGND|HVSS to AGND|–18 to 0.3|V|
|HVDD to HVSS|HVDD to HVSS|–0.3 to 33|V|
|Digital input voltage to DGND|Digital input voltage to DGND|–0.3 to DVDD + 0.3|V|
|Digital output to DGND|Digital output to DGND|–0.3 to DVDD + 0.3|V|
|Operating temperature range|Operating temperature range|–40 to +125|°C|
|Storage temperature range|Storage temperature range|–65 to +150|°C|
|ESD ratings, all pins|Human body model(HBM)|±2000|V|
|ESD ratings, all pins|Charged device model(CDM)|±500|V|



(1) Stresses beyond those listed under _absolute maximum ratings_ may cause permanent damage to the device. These are stress ratings
only, and functional operation of the device at these or any other conditions beyond those indicated under _recommended operating_
_conditions_ is not implied. Exposure to absolute – maximum – rated conditions for extended periods may affect device reliability. These are
stress ratings only and functional operation of the device at these or any other conditions beyond those specified in the Electrical
Characteristics table is not implied.


2 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**ELECTRICAL CHARACTERISTICS: ADS8634, ADS8638**


° °
Minimum/maximum specifications at TA = – 40 C to +125 C, fSAMPLE = 1MSPS, HVDD = 10V to 15V, HVSS = – 10V to – 15V,
AVDD = 4.75V to 5.25V, DVDD = 2.7V to 3.6V, and VREF = 2.5V, unless otherwise noted. Typical specifications at +25 ° C,
fSAMPLE = 1MHz, HVDD = 10V, HVSS = – 10V, AVDD = 3.3V, DVDD = 3.3V, and VREF = 2.5V, unless otherwise noted.

|PARAMETER|Col2|TESTCONDITIONS|ADS8634 ADS8638<br>,|UNIT|
|---|---|---|---|---|
|**PARAMETER**|**PARAMETER**|**TEST CONDITIONS**|**MIN**<br>**TYP**<br>**MAX**|**MIN**<br>**TYP**<br>**MAX**|
|**ANALOG INPUT**|**ANALOG INPUT**|**ANALOG INPUT**|**ANALOG INPUT**|**ANALOG INPUT**|
|Full-scale input span(1)|Full-scale input span(1)|Bipolar ranges, VREF = 2.5V|±2.5|V|
|Full-scale input span(1)|Full-scale input span(1)|Bipolar ranges, VREF = 2.5V|±5|V|
|Full-scale input span(1)|Full-scale input span(1)|Bipolar ranges, VREF = 2.5V|±10|V|
|Full-scale input span(1)|Full-scale input span(1)|Unipolar ranges, VREF = 2.5V|0 to 5|V|
|Full-scale input span(1)|Full-scale input span(1)|Unipolar ranges, VREF = 2.5V|0 to 10|V|
|AINx absolute input range|AINx absolute input range||HVSS<br>HVDD|V|
|AINGND absolute input range|AINGND absolute input range||–0.2<br>0.2|V|
|Input capacitance|Input capacitance||8|pF|
|Input leakage current|Input leakage current|At +125°C|200|nA|
|**SYSTEM PERFORMANCE**|**SYSTEM PERFORMANCE**|**SYSTEM PERFORMANCE**|**SYSTEM PERFORMANCE**|**SYSTEM PERFORMANCE**|
|Resolution|Resolution||12|Bits|
|No missing codes|No missing codes||12|Bits|
|Integral linearity|Integral linearity||–1.5<br>+0.9/–0.9<br>1.5|LSB(2)|
|Differential linearity|Differential linearity||–1.0<br>+0.9/–0.5<br>1.6|LSB|
|Offset error(3)|Offset error(3)||–3<br>±0.8<br>3|LSB|
|Offset error drift|Offset error drift||0.75|ppmFS/°C(<br>4)|
|Gain error(5)|Gain error(5)||–8<br>±2<br>8|LSB|
|Gain error drift|Gain error drift||1.2|ppm/°C|
|Noise|Noise||0.33|LSB|
|Power-supply rejection|Power-supply rejection|At FFCh output code with<br>250mVPP and 480Hz ripple on AVDD|–87|dB|
|Crosstalk|Isolation<br>crosstalk|Crosstalk on channel 0 with channel 0 permanently selected,<br>2kHz full-scale sine wave on channel 1, all other channels<br>grounded|–110|dB|
|Crosstalk|Memory crosstalk|Crosstalk on channel 0, 2kHz full-scale sine wave on channel 1,<br>all other channels grounded, device scans channel 0 and<br>channel 1 alternately|–81|dB|
|**SAMPLING DYNAMICS**|**SAMPLING DYNAMICS**|**SAMPLING DYNAMICS**|**SAMPLING DYNAMICS**|**SAMPLING DYNAMICS**|
|Conversion time|Conversion time|At 20MHz SCLK, DVDD = 2.7V to 5.25V|750|ns|
|Acquisition time|Acquisition time|AVDD = 2.7V to 5.25V|250|ns|
|Maximum throughput rate|Maximum throughput rate|At 20MHz SCLK, DVDD = 2.7V to 5.25V|1<br>1|MSPS|
|Aperture delay|Aperture delay||13|ns|
|Step response|Step response||250|ns|



(1) Ideal input span; does not include gain or offset error.
(2) LSB means least significant bit.
(3) Measured relative to an ideal full-scale input.
(4) ppmFS/ ° C is drift measured in parts per million of full-scale range per degree centigrade.
(5) Does not include reference drift.


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 3


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**ELECTRICAL CHARACTERISTICS: ADS8634, ADS8638 (continued)**


° °
Minimum/maximum specifications at TA = – 40 C to +125 C, fSAMPLE = 1MSPS, HVDD = 10V to 15V, HVSS = – 10V to – 15V,
AVDD = 4.75V to 5.25V, DVDD = 2.7V to 3.6V, and VREF = 2.5V, unless otherwise noted. Typical specifications at +25 ° C,
fSAMPLE = 1MHz, HVDD = 10V, HVSS = – 10V, AVDD = 3.3V, DVDD = 3.3V, and VREF = 2.5V, unless otherwise noted.

|PARAMETER|Col2|TESTCONDITIONS|ADS8634 ADS8638<br>,|UNIT|
|---|---|---|---|---|
|**PARAMETER**|**PARAMETER**|**TEST CONDITIONS**|**MIN**<br>**TYP**<br>**MAX**|**MIN**<br>**TYP**<br>**MAX**|
|**DYNAMIC CHARACTERISTICS**|**DYNAMIC CHARACTERISTICS**|**DYNAMIC CHARACTERISTICS**|**DYNAMIC CHARACTERISTICS**|**DYNAMIC CHARACTERISTICS**|
|Total harmonic distortion(6) (THD)|Total harmonic distortion(6) (THD)|At 1kHz|–81|dB|
|Total harmonic distortion(6) (THD)|Total harmonic distortion(6) (THD)|At 100kHz|–80|dB|
|Signal-to-noise ratio (SNR)|Signal-to-noise ratio (SNR)|At 1kHz|71<br>71.8|dB|
|Signal-to-noise ratio (SNR)|Signal-to-noise ratio (SNR)|At 100kHz|71.1|dB|
|Signal-to-noise and distortion ratio<br>(SINAD)|Signal-to-noise and distortion ratio<br>(SINAD)|At 1kHz|70.1<br>71.3|dB|
|Signal-to-noise and distortion ratio<br>(SINAD)|Signal-to-noise and distortion ratio<br>(SINAD)|At 100kHz|70.5|dB|
|Spurious-free dynamic range (SFDR)|Spurious-free dynamic range (SFDR)|At 1kHz|–83|dB|
|Spurious-free dynamic range (SFDR)|Spurious-free dynamic range (SFDR)|At 100kHz|–80|dB|
|Full-power bandwidth|Full-power bandwidth|At –3dB|1|MHz|
|**DIGITAL INPUT/OUTPUT**|**DIGITAL INPUT/OUTPUT**|**DIGITAL INPUT/OUTPUT**|**DIGITAL INPUT/OUTPUT**|**DIGITAL INPUT/OUTPUT**|
|Logic family|Logic family||CMOS|V|
|Logic level|VIH||0.7 DVDD|V|
|Logic level|VIL||0.3 DVDD|V|
|Logic level|VOH|With 20pF load on SDO|0.8 DVDD|V|
|Logic level|VOL|With 20pF load on SDO|0.2 DVDD|V|
|**EXTERNAL VOLTAGE REFERENCE**|**EXTERNAL VOLTAGE REFERENCE**|**EXTERNAL VOLTAGE REFERENCE**|**EXTERNAL VOLTAGE REFERENCE**|**EXTERNAL VOLTAGE REFERENCE**|
|Reference input<br>voltage range|VREF||3.0 or<br>AVDD,<br>2.0<br>whichever<br>is less|V|
|**INTERNAL VOLTAGE REFERENCE**|**INTERNAL VOLTAGE REFERENCE**|**INTERNAL VOLTAGE REFERENCE**|**INTERNAL VOLTAGE REFERENCE**|**INTERNAL VOLTAGE REFERENCE**|
|Reference output voltage|Reference output voltage||2.5|V|
|Initial accuracy|Initial accuracy||–1.2<br>1.2|%|
|Temperature drift|Temperature drift||20|ppm/°C|
|Drive current, source(7)|Drive current, source(7)||750|µA|
|Drive current, sink|Drive current, sink||20|µA|
|Driver output impedance|Driver output impedance||1|Ω|
|Turn-on settling time|Turn-on settling time|With 10µF decoupling capacitor from REF to REFGND|9|ms|
|**INTERNAL TEMPERATURE SENSOR**|**INTERNAL TEMPERATURE SENSOR**|**INTERNAL TEMPERATURE SENSOR**|**INTERNAL TEMPERATURE SENSOR**|**INTERNAL TEMPERATURE SENSOR**|
|Absolute accuracy|Absolute accuracy||5|% of FSR|



(6) Calculated on the first nine harmonics of the input frequency.
(7) Internal reference output is short-circuit protected. In case of short-circuit to ground, the drive current is limited to this value.


4 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**ELECTRICAL CHARACTERISTICS: ADS8634, ADS8638 (continued)**


° °
Minimum/maximum specifications at TA = – 40 C to +125 C, fSAMPLE = 1MSPS, HVDD = 10V to 15V, HVSS = – 10V to – 15V,
AVDD = 4.75V to 5.25V, DVDD = 2.7V to 3.6V, and VREF = 2.5V, unless otherwise noted. Typical specifications at +25 ° C,
fSAMPLE = 1MHz, HVDD = 10V, HVSS = – 10V, AVDD = 3.3V, DVDD = 3.3V, and VREF = 2.5V, unless otherwise noted.

|PARAMETER|Col2|TESTCONDITIONS|ADS8634 ADS8638<br>,|UNIT|
|---|---|---|---|---|
|**PARAMETER**|**PARAMETER**|**TEST CONDITIONS**|**MIN**<br>**TYP**<br>**MAX**|**MIN**<br>**TYP**<br>**MAX**|
|**POWER-SUPPLY REQUIREMENTS**|**POWER-SUPPLY REQUIREMENTS**|**POWER-SUPPLY REQUIREMENTS**|**POWER-SUPPLY REQUIREMENTS**|**POWER-SUPPLY REQUIREMENTS**|
|Supply voltage|VAVDD||2.7<br>3.3<br>5.25|V|
|Supply voltage|VDVDD||1.65<br>3.3<br>5.25|V|
|Supply voltage|VHVDD|10V < VHVDD – VHVSS < 30V|5<br>10<br>15|V|
|Supply voltage|VHVSS|10V < VHVDD – VHVSS < 30V|–15<br>–10<br>0|V|
|AVDD supply<br>current|IAVDD(dynamic)|At VAVDD = 2.7V to 3.6V and 1MHz throughput, normal mode<br>with internal reference and temperature sensor off|2.5|mA|
|AVDD supply<br>current|IAVDD(dynamic)|At VAVDD = 4.75V to 5.25V and 1MHz throughput, normal mode<br>with internal reference and temperature sensor off|3.1<br>3.6|mA|
|AVDD supply<br>current|IAVDD(static)|At VAVDD = 2.7V to 3.6V and SCLK off, normal mode with<br>internal reference and temperature sensor off|1.45|mA|
|AVDD supply<br>current|IAVDD(static)|At VAVDD = 4.75V to 5.25V and SCLK off, normal mode with<br>internal reference and temperature sensor off|1.5<br>1.9|mA|
|AVDD supply<br>current|IAVDD(ref)<br>(8)|At VAVDD = 2.7V to 5.25V, additional AVDD current with internal<br>reference on and temperature sensor off|180|µA|
|AVDD supply<br>current|IAVDD(temp)<br>(9)|At VAVDD = 2.7V to 5.25V, additional AVDD current with internal<br>temperature sensor on and internal reference off|400|µA|
|HVDD supply<br>current|IHVDD(dynamic)|HVDD = 15V and 1MSPS throughput|270<br>350|µA|
|HVDD supply<br>current|IHVDD(static)|HVDD = 15V and device static with SCLK off|5|µA|
|HVSS supply<br>current|IHVSS(dynamic)|HVSS = –15 V and 1MSPS throughput|520|µA|
|HVSS supply<br>current|IHVSS(static)|HVSS = –15V and device static with SCLK off|5|µA|
|DVDD supply<br>current(10)|IDVDD|DVDD = 3.3V, fSAMPLE = 1MSPS, DOUT load = 20pF|2.5|mA|
|Power-down state|AVDD current|SCLK off, internal reference and temperature sensor off|10|µA|
|Power-down state|AVDD current|SCLK on, internal reference and temperature sensor off|160|µA|
|Power-down state|HVDD current||5|µA|
|Power-down state|HVSS current||5|µA|
|**TEMPERATURE RANGE**|**TEMPERATURE RANGE**|**TEMPERATURE RANGE**|**TEMPERATURE RANGE**|**TEMPERATURE RANGE**|
|Specified performance|Specified performance||–40<br>+125|°C|



(8) Add IAVDD(ref) to IAVDD(dynamic) or IAVDD(static)(as applicable), if internal reference is selected.
(9) Add IAVDD(temp) to IAVDD(dynamic) or IAVDD(static)(as applicable), if internal temperature sensor is enabled.
(10) IDVDD consumes only dynamic current. IDVDD = CLOAD × VDVDD × number of 0 → 1 transitions in DOUT × fSAMPLE. IDVDD is a

load-dependent current; there is no current when the output is not toggling.

|THERMAL INFORMATION|Col2|Col3|
|---|---|---|
|**THERMAL METRIC(1)**|**ADS8634/8RGE**|**UNITS**|
|**THERMAL METRIC(1)**|**RGE**|**RGE**|
|**THERMAL METRIC(1)**|**24 PINS**|**24 PINS**|
|θJA<br>Junction-to-ambient thermal resistance|32.6|°C/W|
|θJCtop<br>Junction-to-case(top) thermal resistance|30.5|30.5|
|θJB<br>Junction-to-board thermal resistance|3.3|3.3|
|ψJT<br>Junction-to-top characterizationparameter|0.4|0.4|
|ψJB<br>Junction-to-board characterizationparameter|9.3|9.3|
|θJCbot<br>Junction-to-case(bottom) thermal resistance|2.6|2.6|



(1) For more information about traditional and new thermal metrics, see the _IC Package Thermal Metrics_ [application report, SPRA953.](http://www.ti.com/lit/pdf/spra953)


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 5


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**PARAMETER MEASUREMENT INFORMATION**


**TIMING DIAGRAM**


CS


SCLK





|Col1|1/f<br>SAMPLE|Col3|Col4|Col5|
|---|---|---|---|---|
|||tsu(CS-SCLK)|tsu(CS-SCLK)||
|||tsu(CS-SCLK)|||
||||||
|td(CS-DO)<br>1R<br>1F<br>2<br>3<br>4<br>5<br>12<br>13<br>14<br>15<br>16R 16F<br>th(SCLK-DOUT)<br>tw(SCLK_H)<br>tw(SCLK_L)<br>td(CS-DOHZ)<br>tsu(DIN-SCLK)<br>th(SCLK-DIN)<br>td(SCLK-DOUT)|td(CS-DO)<br>1R<br>1F<br>2<br>3<br>4<br>5<br>12<br>13<br>14<br>15<br>16R 16F<br>th(SCLK-DOUT)<br>tw(SCLK_H)<br>tw(SCLK_L)<br>td(CS-DOHZ)<br>tsu(DIN-SCLK)<br>th(SCLK-DIN)<br>td(SCLK-DOUT)|td(CS-DO)<br>1R<br>1F<br>2<br>3<br>4<br>5<br>12<br>13<br>14<br>15<br>16R 16F<br>th(SCLK-DOUT)<br>tw(SCLK_H)<br>tw(SCLK_L)<br>td(CS-DOHZ)<br>tsu(DIN-SCLK)<br>th(SCLK-DIN)<br>td(SCLK-DOUT)|td(CS-DO)<br>1R<br>1F<br>2<br>3<br>4<br>5<br>12<br>13<br>14<br>15<br>16R 16F<br>th(SCLK-DOUT)<br>tw(SCLK_H)<br>tw(SCLK_L)<br>td(CS-DOHZ)<br>tsu(DIN-SCLK)<br>th(SCLK-DIN)<br>td(SCLK-DOUT)||


|Col1|Col2|t(ACQ)|Col4|
|---|---|---|---|
||~~tc~~|~~tc~~||


**Table 1. Timing Requirements** **[(1)(2)(3)]**



DOUT


DIN


Acquisition
(Internal)



|PARAMETER|Col2|TEST<br>CONDITIONS|ADS8634 ADS8638<br>,|UNIT|
|---|---|---|---|---|
|**PARAMETER**|**PARAMETER**|**TEST**<br>**CONDITIONS**|**MIN**<br>**TYP**<br>**MAX**|**MIN**<br>**TYP**<br>**MAX**|
|tc|Conversion time|DVDD = 1.8V|15|SCLK|
|tc|Conversion time|DVDD = 3V|15|SCLK|
|tc|Conversion time|DVDD = 5V|15|SCLK|
|t(ACQ)|Acquisition time|DVDD = 1.8V|250|ns|
|t(ACQ)|Acquisition time|DVDD = 3V|250|ns|
|t(ACQ)|Acquisition time|DVDD = 5V|250|ns|
|td(CS-DO)|Delay time, CS low to first data (D0 to D15) out|DVDD = 1.8V|52.5|ns|
|td(CS-DO)|Delay time, CS low to first data (D0 to D15) out|DVDD = 3V|40.0|ns|
|td(CS-DO)|Delay time, CS low to first data (D0 to D15) out|DVDD = 5V|30.5|ns|
|tsu(CS-SCLK)|Setup time, CS low to first SCLK rising edge|DVDD = 1.8V|26.0|ns|
|tsu(CS-SCLK)|Setup time, CS low to first SCLK rising edge|DVDD = 3V|18.5|ns|
|tsu(CS-SCLK)|Setup time, CS low to first SCLK rising edge|DVDD = 5V|15.5|ns|
|td(SCLK-DOUT)|Delay time, SCLK falling to DOUT|DVDD = 1.8V|51.5|ns|
|td(SCLK-DOUT)|Delay time, SCLK falling to DOUT|DVDD = 3V|33.0|ns|
|td(SCLK-DOUT)|Delay time, SCLK falling to DOUT|DVDD = 5V|25.3|ns|
|th(SCLK-DOUT)|Hold time, SCLK falling to DOUT valid|DVDD = 1.8V|5.5|ns|
|th(SCLK-DOUT)|Hold time, SCLK falling to DOUT valid|DVDD = 3V|5.0|ns|
|th(SCLK-DOUT)|Hold time, SCLK falling to DOUT valid|DVDD = 5V|4.7|ns|
|td(CS-DOHZ)|Delay time CS high to DOUT high-z|DVDD = 1.8V|7.3<br>31.0|ns|
|td(CS-DOHZ)|Delay time CS high to DOUT high-z|DVDD = 3V|6.4<br>22.0|ns|
|td(CS-DOHZ)|Delay time CS high to DOUT high-z|DVDD = 5V|5.9<br>16.4|ns|


° °
(1) All specifications at – 40 C to +125 C, unless otherwise noted.
(2) 1.8V specifications apply from 1.65V to 1.95V; 3V specifications apply from 2.7V to 3.6V; and 5V specifications apply from 4.75V to
5.25V.
(3) With 20pF load on DOUT.


6 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**PARAMETER MEASUREMENT INFORMATION (continued)**

|PARAMETER MEASURE Table 1. Timing Re|Col2|EMENT INFORM equirements(1)(2)(|MATION (continued) (3) (continued)|Col5|
|---|---|---|---|---|
|**PARAMETER**|**PARAMETER**|**TEST**<br>**CONDITIONS**|**ADS8634, ADS8638**|**UNIT**|
|**PARAMETER**|**PARAMETER**|**TEST**<br>**CONDITIONS**|**MIN**<br>**TYP**<br>**MAX**|**MIN**<br>**TYP**<br>**MAX**|
|tsu(DIN-SCLK)|Setup time, DIN valid to SCLK rising edge|DVDD = 1.8V|7.0|ns|
|tsu(DIN-SCLK)|Setup time, DIN valid to SCLK rising edge|DVDD = 3V|6.0|ns|
|tsu(DIN-SCLK)|Setup time, DIN valid to SCLK rising edge|DVDD = 5V|5.0|ns|
|th(SCLK-DIN)|Hold time, SCLK rising to DIN valid|DVDD = 1.8V|9.0|ns|
|th(SCLK-DIN)|Hold time, SCLK rising to DIN valid|DVDD = 3V|8.0|ns|
|th(SCLK-DIN)|Hold time, SCLK rising to DIN valid|DVDD = 5V|7.0|ns|
|tW(SCLK_H)|Pulse duration, SCLK high|DVDD = 1.8V|25|ns|
|tW(SCLK_H)|Pulse duration, SCLK high|DVDD = 3V|20|ns|
|tW(SCLK_H)|Pulse duration, SCLK high|DVDD = 5V|20|ns|
|tW(SCLK_L)|Pulse duration, SCLK low|DVDD = 1.8V|25|ns|
|tW(SCLK_L)|Pulse duration, SCLK low|DVDD = 3V|20|ns|
|tW(SCLK_L)|Pulse duration, SCLK low|DVDD = 5V|20|ns|
|fSCLK|SCLK frequency|DVDD = 1.8V|16|MHz|
|fSCLK|SCLK frequency|DVDD = 3V|20|MHz|
|fSCLK|SCLK frequency|DVDD = 5V|20|MHz|
|fSAMPLE|Sampling frequency|DVDD = 1.8V|0.84|MSPS|
|fSAMPLE|Sampling frequency|DVDD = 3V|1|MSPS|
|fSAMPLE|Sampling frequency|DVDD = 5V|1|MSPS|



**POWER-UP TIMING REQUIREMENTS**


CS



1 2 16



SCLK


AL_PD

Programmed as PD


Power-Down State
(Internal)


DOUT



Invalid Data Invalid Data Invalid Data


**Table 2. TIMING REQUIREMENTS** **[(1)]**



1 2 16 1 2 16



Valid Data





1 2 16


Valid Data



|PARAMETER|Col2|ADS8634 ADS8638<br>,|UNIT|
|---|---|---|---|
|**PARAMETER**|**PARAMETER**|**MIN**<br>**TYP**<br>**MAX**|**MIN**<br>**TYP**<br>**MAX**|
|td(PWRUP)(2)|Power-up delay from first CS afterpower-up command|1|µs|
|Invalid conversions after device is active(powered up)|Invalid conversions after device is active(powered up)|1|Conversion|


° °
(1) All specifications at – 40 C to +125 C, unless otherwise noted.
(2) Power-up time excludes internal reference and temperature sensor.


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 7


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**PIN CONFIGURATIONS**


**RGE PACKAGE**
**4mm** × **4mm QFN-24**

**(TOP VIEW)**





AVDD


AGND


AGND


NC


AINGND


NC











DIN


SCLK


CS


HVSS


HVDD


NC







**Figure 1. ADS8634 Pin Configuration**


**ADS8634 PIN ASSIGNMENTS**

|PINNUMBER|NAME|FUNCTION|DESCRIPTION|
|---|---|---|---|
|1|AVDD|Analog power supply|Analog power supply|
|2, 3|AGND|Analog power supply|Analog ground|
|4, 6, 7, 12, 13|NC|—|These pins are not internally connected; do not float these pins.<br>It is recommended to connect these pins to AGND.|
|5|AINGND|Input|Common for all analog input channels; acts as ground sense terminal|
|8|AIN3|Analog input|Analog input channel 3|
|9|AIN2|Analog input|Analog input channel 2|
|10|AIN1|Analog input|Analog input channel 1|
|11|AIN0|Analog input|Analog input channel 0|
|14|HVDD|High-voltage power supply|High-voltage positive supply for multiplexer channels|
|15|HVSS|High-voltage power supply|High-voltage negative supply for multiplexer channels|
|16|CS|Digital input|Chip select input|
|17|SCLK|Digital input|Serial clock input|
|18|DIN|Digital input|Serial data input|
|19|DOUT|Digital output|Serial data output|
|20|DGND|Digital power supply|Digital ground|
|21|DVDD|Digital power supply|Digital I/O supply|
|22|AL_PD|Digital output|Active high, output indicates alarm (programmed as an output pin)|
|22|AL_PD|Digital input|Active low, asynchronous power-down.<br>The device features an internal, weak pull-up resistor from the AL_PD pin to DVDD. The<br>AL_PD pin can also be floated when programmed as a power-down input.<br>(The default condition for this pin is programmed as a power-down input pin.)|
|23|REFGND|Analog input|Reference ground input to device when an external reference is selected.<br>This pin acts as a reference decoupling ground terminal when an internal reference is<br>selected.|
|24|REF|Analog input|Reference input to device when an external reference is selected.<br>This pin acts as a reference decoupling terminal when an internal reference is selected.|



8 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**RGE PACKAGE**
**4mm** × **4mm QFN-24**

**(TOP VIEW)**





AVDD


AGND


AGND


NC


AINGND


AIN7











DIN


SCLK


CS


HVSS


HVDD


AIN0







**Figure 2. ADS8638 Pin Configuration**


**ADS8638 PIN ASSIGNMENTS**

|PINNUMBER|NAME|FUNCTION|DESCRIPTION|
|---|---|---|---|
|1|AVDD|Analog power supply|Analog power supply|
|2, 3|AGND|Analog power supply|Analog ground|
|4|NC|—|This pin is not internally connected; do not float this pin.<br>It is recommended to connect this pin to AGND.|
|5|AINGND|Input|Common for all analog input channels; acts as ground sense terminal|
|6|AIN7|Analog input|Analog input channel 7|
|7|AIN6|Analog input|Analog input channel 6|
|8|AIN5|Analog input|Analog input channel 5|
|9|AIN4|Analog input|Analog input channel 4|
|10|AIN3|Analog input|Analog input channel 3|
|11|AIN2|Analog input|Analog input channel 2|
|12|AIN1|Analog input|Analog input channel 1|
|13|AIN0|Analog input|Analog input channel 0|
|14|HVDD|High-voltage power supply|High-voltage positive supply for multiplexer channels|
|15|HVSS|High-voltage power supply|High-voltage negative supply for multiplexer channels|
|16|CS|Digital input|Chip select input|
|17|SCLK|Digital input|Serial clock input|
|18|DIN|Digital input|Serial data input|
|19|DOUT|Digital output|Serial data output|
|20|DGND|Digital power supply|Digital ground|
|21|DVDD|Digital power supply|Digital I/O supply|
|22|AL_PD|Digital output|Active high, output indicating alarm (programmed as an output pin)|
|22|AL_PD|Digital input|Active low, asynchronous power-down<br>(programmed as an input pin, default condition)|
|23|REFGND|Analog input|Reference ground input to device when an external reference is selected.<br>This pin acts as reference decoupling ground terminal when an internal reference is<br>selected.|
|24|REF|Analog input|Reference input to device when an external reference is selected.<br>This pin acts as reference decoupling terminal when an internal reference is selected.|



Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 9


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**TYPICAL CHARACTERISTICS**

At TA = +25 ° C, internal reference = 2.5V, channel 0, range = ± 2.5V, AVDD = 2.7V, DVDD = 1.8V, HVDD = 10V, HVSS

= – 10V, and fSAMPLE = 1MSPS, unless otherwise noted.


**DNL vs ANALOG SUPPLY VOLTAGE** **DNL vs SIGNAL RANGE**



1.6

1.4

1.2

1

0.8

0.6

0.4

0.2

0

−0.2

−0.4

−0.6

−0.8

−1





1.6

1.4

1.2

1

0.8

0.6

0.4

0.2

0

−0.2

−0.4

−0.6

−0.8

−1




|Col1|Col2|Col3|Col4|Col5|Col6|
|---|---|---|---|---|---|
|||||||
|||~~Maxim~~|~~um DNL~~|||
|||||||
|||||||
|||||||
|||||||
|||||||
|||||||
|||~~Minim~~|~~um DNL~~|||
|||||||
|||||||
|||||||


|Col1|Col2|Col3|Col4|
|---|---|---|---|
|||||
|||Maxi|mum DNL|
|||||
|||||
|||||
|||||
|||||
|||~~Mini~~|~~um DNL~~|
|||||
|||||
|||||
|||||



2.7 3.2 3.7 4.2 4.7 5.2 5.7



±2.5V ±5V ±10V 0−5V 0−10V



G014



AVDD (V)



G013



Signal Range



**Figure 3.** **Figure 4.**


**DNL vs REFERENCE VOLTAGE** **DNL vs CHANNEL NUMBER**



1.6

1.4

1.2

1

0.8

0.6

0.4

0.2

0

−0.2

−0.4

−0.6

−0.8

−1


1.6

1.4

1.2

1

0.8

0.6

0.4

0.2

0

−0.2

−0.4

−0.6

−0.8

−1



|Col1|Col2|Col3|Col4|Col5|
|---|---|---|---|---|
||||||
||||Maximum|DNL|
||||||
||||||
||||||
||||||
||||||
||||~~Minimum~~|~~ DNL~~|
||||||
||||||
||||||
||||||


2 2.2 2.4 2.6 2.8 3



1.6

1.4

1.2

1

0.8

0.6

0.4

0.2

0

−0.2

−0.4

−0.6

−0.8

−1


|Col1|Col2|Col3|Col4|Col5|Col6|Col7|
|---|---|---|---|---|---|---|
||||||||
||||~~aximum~~|~~ DNL~~|||
||||||||
||||||||
||||||||
||||||||
||||||||
|||~~M~~|~~inimum~~|~~ DNL~~|||
||||||||
||||||||
||||||||
||||||||



0 1 2 3 4 5 6 7





G016



Reference Voltage (V)



G015



Channel Number



**Figure 5.** **Figure 6.**


**DNL vs FREE-AIR TEMPERATURE** **DNL vs POSITIVE HIGH-VOLTAGE SUPPLY**





1.6

1.4

1.2

1

0.8

0.6

0.4

0.2

0

−0.2

−0.4

−0.6

−0.8

−1




|Col1|Col2|Col3|Col4|Col5|Col6|Col7|Col8|Col9|Col10|Col11|
|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||
||||~~Max~~|~~imum~~|~~ DNL~~||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||~~Mii~~||~~ DNL~~||||||
||||~~n~~|~~mum~~|||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||


|Col1|Col2|Col3|Col4|Col5|
|---|---|---|---|---|
|||Maximum|DNL||
||||||
||||||
||||||
||||||
||||||
||||||
||||||
|||~~Minimum~~|~~ DNL~~||
||||||
||||||
||||||



−40 −25 −10 5 20 35 50 65 80 95 110 125



2.5 5 7.5 10 12.5 15



Free-Air Temperature (°C)



G017



G018



HVDD, Positive High-Voltage Supply (V)



**Figure 7.** **Figure 8.**


10 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**TYPICAL CHARACTERISTICS (continued)**

At TA = +25 ° C, internal reference = 2.5V, channel 0, range = ± 2.5V, AVDD = 2.7V, DVDD = 1.8V, HVDD = 10V, HVSS
= – 10V, and fSAMPLE = 1MSPS, unless otherwise noted.


**INL vs ANALOG SUPPLY VOLTAGE** **INL vs SIGNAL RANGE**



1.5


1.2


0.9


0.6


0.3





0


−0.3


−0.6


−0.9


−1.2


−1.5

|Col1|Col2|Col3|Col4|Col5|Col6|
|---|---|---|---|---|---|
|||~~M~~|~~aximum IN~~|~~ L~~||
|||||||
|||||||
|||||||
|||M|inimum IN|L||
|||||||
|||||||
|||||||
|||||||


2.7 3.2 3.7 4.2 4.7 5.2 5.7



1.5


1.2


0.9


0.6


0.3


0


−0.3


−0.6


−0.9


−1.2


−1.5


|Col1|Col2|Col3|Col4|
|---|---|---|---|
|||~~Maximum I~~|~~ L~~|
|||||
|||||
|||||
|||Minimum IN|L|
|||||
|||||
|||||
|||||



±2.5V ±5V ±10V 0−5V 0−10V





G020



AVDD (V)



G019



Signal Range



**Figure 9.** **Figure 10.**


**INL vs REFERENCE VOLTAGE** **INL vs CHANNEL NUMBER**



1.5


1.2


0.9


0.6


0.3


0


−0.3


−0.6


−0.9


−1.2


−1.5


1.5


1.2


0.9


0.6


0.3


0


−0.3


−0.6


−0.9


−1.2


−1.5



|Col1|Col2|Col3|Col4|Col5|
|---|---|---|---|---|
||||Maximum|INL|
||||||
||||||
||||||
||||Minimum|INL|
||||||
||||||
||||||
||||||


2 2.2 2.4 2.6 2.8 3



1.5


1.2


0.9


0.6


0.3


0


−0.3


−0.6


−0.9


−1.2


−1.5


|Col1|Col2|Col3|Col4|Col5|Col6|Col7|
|---|---|---|---|---|---|---|
|||~~M~~|~~aximum~~|~~ INL~~|||
||||||||
||||||||
||||||||
|||~~M~~|~~inimum~~|~~ INL~~|||
||||||||
||||||||
||||||||
||||||||



0 1 2 3 4 5 6 7





G022



Reference Voltage (V)



G021



Channel Number



**Figure 11.** **Figure 12.**


**INL vs FREE-AIR TEMPERATURE** **INL vs POSITIVE HIGH-VOLTAGE SUPPLY**





1.5


1.2


0.9


0.6


0.3


0


−0.3


−0.6


−0.9


−1.2


−1.5




|Col1|Col2|Col3|M|i|INL|Col7|Col8|Col9|Col10|Col11|
|---|---|---|---|---|---|---|---|---|---|---|
||||~~ax~~|~~mum~~|||||||
||||||||||||
||||||||||||
||||||||||||
||||Mini|mum|INL||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||


|Col1|Col2|Maximum|INL|Col5|
|---|---|---|---|---|
||||||
||||||
||||||
||||||
|||~~Minimum~~|~~ INL~~||
||||||
||||||
||||||
||||||



−40 −25 −10 5 20 35 50 65 80 95 110 125



2.5 5 7.5 10 12.5 15



Free-Air Temperature (°C)



G023



G024



HVDD, Positive High-Voltage Supply (V)



**Figure 13.** **Figure 14.**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 11


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**TYPICAL CHARACTERISTICS (continued)**

At TA = +25 ° C, internal reference = 2.5V, channel 0, range = ± 2.5V, AVDD = 2.7V, DVDD = 1.8V, HVDD = 10V, HVSS
= – 10V, and fSAMPLE = 1MSPS, unless otherwise noted.


**OFFSET ERROR vs ANALOG SUPPLY VOLTAGE** **OFFSET ERROR vs SIGNAL RANGE**



2.5


2


1.5


1


0.5


0


−0.5


−1


−1.5


−2


−2.5



2.5


2


1.5


1


0.5


0


−0.5


−1


−1.5


−2


−2.5



2.7 3.2 3.7 4.2 4.7 5.2 5.7
AVDD (V) G025



±2.5V ±5V ±10V 0−5V 0−10V
Signal Range G026



2.5


2


1.5


1


0.5


0


−0.5


−1


−1.5


−2


−2.5


2.5


2


1.5


1


0.5


0


−0.5


−1


−1.5


−2


−2.5



**Figure 17.** **Figure 18.**


**OFFSET ERROR vs FREE-AIR TEMPERATURE** **OFFSET ERROR vs POSITIVE HIGH-VOLTAGE SUPPLY**


2.5


2


1.5


1


0.5


0


−0.5


−1


−1.5


−2


−2.5



**Figure 15.** **Figure 16.**


**OFFSET ERROR vs REFERENCE VOLTAGE** **OFFSET ERROR vs CHANNEL NUMBER**


2.5


2


1.5


1


0.5


0


−0.5


−1


−1.5


−2


−2.5



2 2.2 2.4 2.6 2.8 3
Reference Voltage (V) G027



0 1 2 3 4 5 6 7
Channel Number G028



−40 −25 −10 5 20 35 50 65 80 95 110 125
Free-Air Temperature (°C) G029



2.5 5 7.5 10 12.5 15
HVDD, Positive High-Voltage Supply (V) G030



**Figure 19.** **Figure 20.**


12 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**TYPICAL CHARACTERISTICS (continued)**

At TA = +25 ° C, internal reference = 2.5V, channel 0, range = ± 2.5V, AVDD = 2.7V, DVDD = 1.8V, HVDD = 10V, HVSS
= – 10V, and fSAMPLE = 1MSPS, unless otherwise noted.


**GAIN ERROR vs ANALOG SUPPLY VOLTAGE** **GAIN ERROR vs SIGNAL RANGE**



8


6


4


2


0


−2


−4


−6


−8



8


6


4


2


0


−2


−4


−6


−8



2.7 3.2 3.7 4.2 4.7 5.2 5.7
AVDD (V) G031



±2.5V ±5V ±10V 0−5V 0−10V
Signal Range G032



8


6


4


2


0


−2


−4


−6


−8


8


6


4


2


0


−2


−4


−6


−8



**Figure 23.** **Figure 24.**


**GAIN ERROR vs FREE-AIR TEMPERATURE** **GAIN ERROR vs POSITIVE HIGH-VOLTAGE SUPPLY**


8


6


4


2


0


−2


−4


−6


−8



**Figure 21.** **Figure 22.**


**GAIN ERROR vs REFERENCE VOLTAGE** **GAIN ERROR vs CHANNEL NUMBER**


8


6


4


2


0


−2


−4


−6


−8



2 2.2 2.4 2.6 2.8 3
Reference Voltage (V) G033



0 1 2 3 4 5 6 7
Channel Number G034



−40 −25 −10 5 20 35 50 65 80 95 110 125
Free-Air Temperature (°C) G035



2.5 5 7.5 10 12.5 15
HVDD, Positive High-Voltage Supply (V) G036



**Figure 25.** **Figure 26.**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 13


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**TYPICAL CHARACTERISTICS (continued)**

At TA = +25 ° C, internal reference = 2.5V, channel 0, range = ± 2.5V, AVDD = 2.7V, DVDD = 1.8V, HVDD = 10V, HVSS
= – 10V, and fSAMPLE = 1MSPS, unless otherwise noted.


**SNR vs ANALOG SUPPLY VOLTAGE** **SNR vs SIGNAL RANGE**



72


71.8


71.6


71.4


71.2


71


70.8


70.6


70.4


70.2


70



72


71.8


71.6


71.4


71.2


71


70.8


70.6


70.4


70.2


70



2.7 3.2 3.7 4.2 4.7 5.2 5.7
AVDD (V) G037



±2.5V ±5V ±10V 0−5V 0−10V
Signal Range G038



72


71.8


71.6


71.4


71.2


71


70.8


70.6


70.4


70.2


70


72


71.8


71.6


71.4


71.2


71


70.8


70.6


70.4


70.2


70



**Figure 29.** **Figure 30.**


**SNR vs FREE-AIR TEMPERATURE** **SNR vs POSITIVE HIGH-VOLTAGE SUPPLY**


72


71.8


71.6


71.4


71.2


71


70.8


70.6


70.4


70.2


70



**Figure 27.** **Figure 28.**


**SNR vs REFERENCE VOLTAGE** **SNR vs CHANNEL NUMBER**


72


71.8


71.6


71.4


71.2


71


70.8


70.6


70.4


70.2


70



2 2.2 2.4 2.6 2.8 3
Reference Voltage (V) G039



0 1 2 3 4 5 6 7
Channel Number G040



−40 −25 −10 5 20 35 50 65 80 95 110 125
Free-Air Temperature (°C) G041



2.5 5 7.5 10 12.5 15
HVDD, Positive High-Voltage Supply (V) G042



**Figure 31.** **Figure 32.**


14 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**TYPICAL CHARACTERISTICS (continued)**

At TA = +25 ° C, internal reference = 2.5V, channel 0, range = ± 2.5V, AVDD = 2.7V, DVDD = 1.8V, HVDD = 10V, HVSS
= – 10V, and fSAMPLE = 1MSPS, unless otherwise noted.


**SNR vs INPUT FREQUENCY** **SINAD vs ANALOG SUPPLY VOLTAGE**



72


71.8


71.6


71.4


71.2


71


70.8


70.6


70.4


70.2


70


72


71.8


71.6


71.4


71.2


71


70.8


70.6


70.4


70.2


70



**Figure 33.** **Figure 34.**


**SINAD vs SIGNAL RANGE** **SINAD vs REFERENCE VOLTAGE**


72


71.5


71


70.5


70


69.5


69


68.5


68



72


71.8


71.6


71.4


71.2


71


70.8


70.6


70.4


70.2


70



0 15 30 45 60 75 90 105

fIN, Input Frequency (kHz) G043



2.7 3.2 3.7 4.2 4.7 5.2 5.7
AVDD (V) G044



±2.5V ±5V ±10V 0−5V 0−10V
Signal Range G045



2 2.2 2.4 2.6 2.8 3
Reference Voltage (V) G046



72


71.5


71


70.5


70


69.5


69


68.5


68



**Figure 35.** **Figure 36.**


**SINAD vs CHANNEL NUMBER** **SINAD vs FREE-AIR TEMPERATURE**


72


71.5


71


70.5


70


69.5


69


68.5


68



0 1 2 3 4 5 6 7
Channel Number G047



−40 −25 −10 5 20 35 50 65 80 95 110 125
Free-Air Temperature (dB) G048



**Figure 37.** **Figure 38.**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 15


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**TYPICAL CHARACTERISTICS (continued)**

At TA = +25 ° C, internal reference = 2.5V, channel 0, range = ± 2.5V, AVDD = 2.7V, DVDD = 1.8V, HVDD = 10V, HVSS
= – 10V, and fSAMPLE = 1MSPS, unless otherwise noted.


**SINAD vs POSITIVE HIGH-VOLTAGE SUPPLY** **SINAD vs INPUT FREQUENCY**



72


71.5


71


70.5


70


69.5


69


68.5


68



72


71.5


71


70.5


70


69.5


69


68.5


68



2.5 5 7.5 10 12.5 15
HVDD, Positive High-Voltage Supply (V) G049



0 15 30 45 60 75 90 105

fIN, Input Frequency (kHz) G050



−82


−82.5


−83


−83.5


−84


−84.5


−85


−85.5


−86


−86.5


−87



**Figure 39.** **Figure 40.**


**THD vs ANALOG SUPPLY VOLTAGE** **THD vs SIGNAL RANGE**


−75


−76

−77

−78


−79


−80

−81

−82


−83

−84


−85


−86

−87



2.7 3.2 3.7 4.2 4.7 5.2 5.7
AVDD (V) G051



±2.5V ±5V ±10V 0−5V 0−10V
Signal Range G052



−75


−76

−77

−78

−79


−80


−81

−82


−83


−84

−85


−86

−87



**Figure 41.** **Figure 42.**


**THD vs REFERENCE VOLTAGE** **THD vs CHANNEL NUMBER**


−75


−76

−77

−78

−79


−80


−81

−82


−83


−84

−85


−86

−87



2 2.2 2.4 2.6 2.8 3
Reference Voltage (V) G053



0 1 2 3 4 5 6 7
Channel Number G054



**Figure 43.** **Figure 44.**


16 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**TYPICAL CHARACTERISTICS (continued)**

At TA = +25 ° C, internal reference = 2.5V, channel 0, range = ± 2.5V, AVDD = 2.7V, DVDD = 1.8V, HVDD = 10V, HVSS
= – 10V, and fSAMPLE = 1MSPS, unless otherwise noted.


**THD vs FREE-AIR TEMPERATURE** **THD vs POSITIVE HIGH-VOLTAGE SUPPLY**



−75


−76

−77

−78


−79


−80

−81

−82

−83

−84


−85

−86

−87



−75


−77


−79


−81


−83


−85


−87



−40 −25 −10 5 20 35 50 65 80 95 110 125
Free-Air Temperature (°C) G055



2.5 5 7.5 10 12.5 15
HVDD, Positive High-Voltage Supply (V) G056



−75


−76

−77

−78


−79


−80

−81

−82


−83

−84


−85


−86

−87


88


87.5

87

86.5

86


85.5


85

84.5


84


83.5

83


82.5

82



**Figure 45.** **Figure 46.**


**THD vs INPUT FREQUENCY** **SFDR vs ANALOG SUPPLY VOLTAGE**


88


87.5


87


86.5


86


85.5


85


84.5


84



**Figure 47.** **Figure 48.**


**SFDR vs SIGNAL RANGE** **SFDR vs REFERENCE VOLTAGE**


88


87.5

87

86.5

86


85.5


85

84.5


84


83.5

83


82.5

82



0 15 30 45 60 75 90 105

fIN, Input Frequency (kHz) G057



2.7 3.2 3.7 4.2 4.7 5.2 5.7
AVDD (V) G058



±2.5V ±5V ±10V 0−5V 0−10V
Signal Range G059



2 2.2 2.4 2.6 2.8 3
Reference Voltage (V) G060



**Figure 49.** **Figure 50.**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 17


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**TYPICAL CHARACTERISTICS (continued)**

At TA = +25 ° C, internal reference = 2.5V, channel 0, range = ± 2.5V, AVDD = 2.7V, DVDD = 1.8V, HVDD = 10V, HVSS
= – 10V, and fSAMPLE = 1MSPS, unless otherwise noted.


**SFDR vs CHANNEL NUMBER** **SFDR vs FREE-AIR TEMPERATURE**



88


87.5


87


86.5


86


85.5


85


84.5


84



88


87


86


85


84


83


82



0 1 2 3 4 5 6 7
Channel Number G061



−40 −25 −10 5 20 35 50 65 80 95 110 125
Free-Air Temperature (°C) G062



88


87


86


85


84


83


82



**Figure 51.** **Figure 52.**


**SFDR vs POSITIVE HIGH-VOLTAGE SUPPLY** **SFDR vs INPUT FREQUENCY**


90


89


88


87


86


85


84



2.5 5 7.5 10 12.5 15
HVDD, Positive High-Voltage Supply (V) G063



0 15 30 45 60 75 90 105

fIN, Input Frequency (kHz) G064



−70


−80


−90


−100


−110


−120



**Figure 53.** **Figure 54.**


**ANALOG SUPPLY CURRENT (Dynamic)**
**CROSSTALK vs INPUT FREQUENCY** **vs ANALOG SUPPLY VOLTAGE**


3.5





3


2.5


2


1.5


1




|Col1|Col2|Col3|Memo|ryCross|talk|Col7|
|---|---|---|---|---|---|---|
||||||||
||||Isolati|on Cross|talk||
||||||||
||||||||


|Col1|Col2|Col3|Col4|Col5|Col6|
|---|---|---|---|---|---|
|||||||
|||||||
|||||||
|||||HVD<br>HVS|D = 15V<br>S = −15V|



0 15 30 45 60 75 90 105



fIN, Input Frequency (kHz)



G065



2.7 3.2 3.7 4.2 4.7 5.2 5.7
AVDD (V) G001



**Figure 55.** **Figure 56.**


18 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**TYPICAL CHARACTERISTICS (continued)**

At TA = +25 ° C, internal reference = 2.5V, channel 0, range = ± 2.5V, AVDD = 2.7V, DVDD = 1.8V, HVDD = 10V, HVSS
= – 10V, and fSAMPLE = 1MSPS, unless otherwise noted.


**ANALOG SUPPLY CURRENT (Dynamic)** **ANALOG SUPPLY CURRENT (Dynamic)**
**vs FREE-AIR TEMPERATURE** **vs SAMPLE RATE**



2.4


2.35


2.3


2.25


2.2





3.5


3


2.5


2


1.5


1


0.5


0




|HV<br>HV|DD =<br>SS =|15V<br>15V<br>−|Col4|Col5|Col6|Col7|Col8|Col9|Col10|Col11|
|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||
||||||||||||
||||||||||||


|HVDD = 1<br>HVSS =|5V<br>15V<br>−|Col3|Col4|Col5|
|---|---|---|---|---|
||||||
||||||
||||||
||||||
||||||
||||||



−40 −25 −10 5 20 35 50 65 80 95 110 125
Free-Air Temperature (°C) G002



0 0.2 0.4 0.6 0.8 1

fSAMPLE, Sample Rate (MSPS) G003



1.8


1.6


1.4


1.2


1



**Figure 57.** **Figure 58.**


**ANALOG SUPPLY CURRENT (Static)** **POSITIVE HIGH-VOLTAGE SUPPLY CURRENT (Dynamic)**
**vs ANALOG SUPPLY VOLTAGE** **vs ANALOG SUPPLY VOLTAGE**


0.5





0.45


0.4


0.35


0.3


0.25


0.2


|HVDD =<br>HVSS =|15V<br>15V<br>−|Col3|Col4|Col5|Col6|
|---|---|---|---|---|---|
|||||||
|||||||
|||||||



2.7 3.2 3.7 4.2 4.7 5.2 5.7
AVDD (V) G004



2.7 3.2 3.7 4.2 4.7 5.2 5.7
AVDD (V) G005



**Figure 59.** **Figure 60.**


**POSITIVE HIGH-VOLTAGE SUPPLY CURRENT (Dynamic)** **POSITIVE HIGH-VOLTAGE SUPPLY CURRENT (Dynamic)**
**vs FREE-AIR TEMPERATURE** **vs POSITIVE HIGH-VOLTAGE SUPPLY**



0.5


0.45


0.4


0.35


0.3


0.25


0.2





1


0.8


0.6


0.4


0.2


0




|HV<br>HV|DD =<br>SS =|15V<br>15V<br>−|Col4|Col5|Col6|Col7|Col8|Col9|Col10|Col11|
|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||


|HVDD = 1<br>HVSS = −|5V<br>15V|Col3|Col4|Col5|
|---|---|---|---|---|
||||||
||||||
||||||
||||||



−40 −25 −10 5 20 35 50 65 80 95 110 125
Free-Air Temperature (°C) G006



5 7 9 11 13 15
HVDD, Positive High-Voltage Supply (V) G007



**Figure 61.** **Figure 62.**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 19


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**TYPICAL CHARACTERISTICS (continued)**

At TA = +25 ° C, internal reference = 2.5V, channel 0, range = ± 2.5V, AVDD = 2.7V, DVDD = 1.8V, HVDD = 10V, HVSS
= – 10V, and fSAMPLE = 1MSPS, unless otherwise noted.


**POSITIVE HIGH-VOLTAGE SUPPLY CURRENT (Dynamic)** **NEGATIVE HIGH-VOLTAGE SUPPLY CURRENT (Dynamic)**
**vs SAMPLE RATE** **vs ANALOG SUPPLY VOLTAGE**



0.5


0.4


0.3


0.2


0.1


0



|HVDD = 1<br>HVSS = −|5V<br>15V|Col3|Col4|Col5|
|---|---|---|---|---|
||||||
||||||
||||||
||||||


0 0.2 0.4 0.6 0.8 1

fSAMPLE, Sample Rate (MSPS) G008



−0.2


−0.25


−0.3


−0.35


−0.4


−0.45


−0.5



2.7 3.2 3.7 4.2 4.7 5.2 5.7
AVDD (V) G009



**Figure 63.** **Figure 64.**


**NEGATIVE HIGH-VOLTAGE SUPPLY CURRENT (Dynamic)** **NEGATIVE HIGH-VOLTAGE SUPPLY CURRENT (Dynamic)**
**vs FREE-AIR TEMPERATURE** **vs NEGATIVE HIGH-VOLTAGE SUPPLY**



−0.3


−0.35


−0.4


−0.45


−0.5





0


−0.05


−0.1


−0.15


−0.2


−0.25


−0.3


−0.35


−0.4


−0.45


−0.5


|HV|DD =|15V|Col4|Col5|Col6|Col7|Col8|Col9|Col10|Col11|
|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||
||||||||||||
||||||||||||



−40 −25 −10 5 20 35 50 65 80 95 110 125
Free-Air Temperature (°C) G010



−15 −12 −9 −6 −3 0
HVSS, Negative High-Voltage Supply (V) G011



**Figure 65.** **Figure 66.**


**NEGATIVE HIGH-VOLTAGE SUPPLY CURRENT (Dynamic)**

**vs SAMPLE RATE** **DNL**



0


−0.1


−0.2


−0.3


−0.4


−0.5



|Col1|Col2|Col3|HV<br>HV|DD = 15V<br>SS = −15V|
|---|---|---|---|---|
||||||
||||||
||||||
||||||


0 0.2 0.4 0.6 0.8 1

fSAMPLE, Sample Rate (MSPS) G012



1.6

1.4

1.2

1

0.8

0.6

0.4

0.2

0

−0.2

−0.4

−0.6

−0.8

−1



0 512 1024 1536 2048 2560 3072 3584 4095
ADC Output Code (LSB) G066



**Figure 67.** **Figure 68.**


20 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**TYPICAL CHARACTERISTICS (continued)**

At TA = +25 ° C, internal reference = 2.5V, channel 0, range = ± 2.5V, AVDD = 2.7V, DVDD = 1.8V, HVDD = 10V, HVSS
= – 10V, and fSAMPLE = 1MSPS, unless otherwise noted.


**INL** **SPECTRAL RESPONSE**



1.5


1.2


0.9


0.6


0.3


0


−0.3


−0.6


−0.9


−1.2


−1.5



0

−10

−20

−30

−40

−50

−60

−70

−80

−90

−100

−110

−120

−130



0 512 1024 1536 2048 2560 3072 3584 4095
ADC Output Code (LSB) G067





**Figure 69.** **Figure 70.**


**TEMPERATURE SENSOR OUTPUT vs FREE-AIR TEMPERATURE**

3900


3875


3850


3825


3800


3775


3750


3725


3700



−40 −25 −10 5 20 35 50 65 80 95 110 125
Free-Air Temperature (°C) G069



**Figure 71.**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 21


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**OVERVIEW**


The ADS8634 and ADS8638 are 12-bit, 4- and 8-channel devices, respectively. The ADS8634/8 feature
software-selectable bipolar and unipolar ranges, an internal reference with an option to use an external
reference, and an internal temperature sensor. Independent power-down control for the internal reference and
temperature sensor blocks allows for optimal power based on application. The following sections describe the
individual blocks and operation.


**MULTIPLEXER AND ANALOG INPUT**


The ADS8634/8 feature single ended inputs with ground sense and a 4-/8-channel, single-pole multiplexer,
respectively. The ADC samples the difference voltage between analog input pins _AINx_ and the ground sense pin
_AINGND_ . The ADS8634/8 can scan these analog inputs in either manual or auto-scan mode. In manual mode,
the channel is selected for every sample via a register write; in auto-scan mode, the channel number is
incremented automatically on every CS falling edge after the present channel is sampled. It is possible to select
the analog inputs for an auto scan with register settings. The devices automatically scan only the selected analog
inputs in ascending order.


The ADS8634/8 offer multiple software-programmable ranges ± 10V, ± 5V, ± 2.5V, 0V to 5V, and 0V to 10V with a
2.5V reference. Any of these ranges can be assigned to any analog input (for instance, ± 10V can be assigned to
AIN1, ± 2.5V to AIN2, 0V to 10V can be assigned to AIN3, and so on). During a scan (either auto or manual), the
programmed signal range is assigned to the selected channel. The range selection, however, can be temporarily
overridden using the DIN line for a particular scan. This feature is useful for zooming into a narrow range when
needed. Refer to Table 11 for configuration register settings.


22 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


Figure 72 shows electrostatic discharge (ESD) diodes connected to the HVDD and HVSS supplies. Make sure
these diodes do not turn on by keeping the analog inputs within the specified range.


AIN0





AIN1


AIN3/7


AINGND







**Figure 72. Analog Inputs**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 23


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


The ADS8634/8 sample the voltage difference (VAINx – VAINGND) between the selected analog input channel and
the AINGND pin. The ADS8634/8 allow a ± 0.2V range on AINGND. This feature is useful in modular systems
where the sensor/signal conditioning block is removed from the ADC and when there could be a difference in the
ground potential of the sensor/signal condioner from the ADC ground. In such cases, it is recommended to run
separate wires from the AINGND terminal of the device to the sensor/signal conditioner ground.


**REFERENCE**


The ADS8634/8 measure the analog input signals relative to the voltage reference using either an internal
precision 2.5V voltage reference (Figure 73) or an external voltage reference (Figure 74). Binary-weighted
capacitors are switched onto the reference terminal during conversion. The switching frequency is the same as
the SCLK frequency. Whether it is an internal or external reference, be sure to decouple the REF terminal to
REFGND with a 10 µ F capacitor. Place the capacitor close to the REFP and REFGND pins.


AVDD AGND







10 F





**Figure 73. Operation Using The Internal Reference**
**(Refer to Table 11 for more details on the configuration register settings)**


AVDD AGND















**Figure 74. Operation Using an External Reference**
**(Refer to Table 11 for more details on the configiguration register settings)**


24 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


These devices allow the use of an external reference in the range of 2.0V to 3.0V. The nominal input ranges
± 10V, ± 5V, ± 2.5V, 0V to 5V, and 0V to 10V assume a 2.5V reference; a different reference voltage scales the
full-scale ranges proportionately. For example, if a 3.0V reference is used and the ± 10V range is selected, the
actual input range is scaled by (3.0/2.5) for a full-scale range of ± 12V.


The internal reference can be enabled/disabled through the configuration register. The reference block is
powered down when the internal reference is disabled. Ensure that the internal reference is disabled when the
external reference is connected. The external reference is the default selection after power-on or reset.


**TEMPERATURE SENSOR**


The ADS8634/8 feature an on-chip temperature sensoras shown in Figure 75. The device temperature can be
read at any time during a scan, either in auto or manual mode.There are three registers associated with the
temperature sensor operation. The temperature sensor can be enabled/disabled through the Aux-Config
configuration register. Disabling the temperature sensor powers down the temperature block. It is necessary to
enable (power up) the temperature sensor at least one cycle before the device temperature sensor is selected
with the channel sequencing control registers (manual/auto). This selection overrides the input channel scan
sequence and range selection and connects the ADC input to an internal temperature sensor. The temperature
sensor must be deselected with channel sequencing control registers (manual/auto) to resume normal scanning.
In case of auto-sequencing, the device starts scanning from where it left off before the temperature
measurement. The temperature sensor is disabled by default after power-on or reset.


AVDD AGND









AIN0


AIN1


AIN2


AIN3/7


AINGND





**Figure 75. Reading the ADS8634/8 Temperature**
**(Refer to Table 11 for more details on configuration register settings)**


The temperature sensor transfer function follows a straight line, as shown in Equation 1:
Output Code = mREF × Device Temperature in ° C + CREF (1)


Equation 1 can be re-written as Equation 2:
Device Temperature in ° C = (Output Code – CREF)/mREF


where:


mREF = the slope,


and CREF = the offset (in ADC output code) of the temperature sensor transfer function (2)


Both mREF and CREF change with the reference voltage. The initial values of mREF and CREF at a 2.5V reference
are: mREF_2.5 = 0.47 and CREF_2.5 = 3777.2


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 25


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


Values of mREF and CREF for any reference voltage other than 2.5V can be calculated using Equation 3 and
Equation 4:
mREF = mREF_2.5 × 2.5/VREF (3)
CREF = (CREF_2.5 – 3584) × 2.5/VREF + 3584 (4)


For example, at a 2V reference:

mREF_2 = 0.47 × 2.5/2 = 0.59 and
CREF_2 = (3777.2 – 3584) × 2.5/2 + 3584 = 3825.5


For the reference voltage used, Equation 2 can be rewritted using mREF and CREF as calculated in Equation 3
and Equation 4.


Table 3 can be used as quick reference for temperature sensor transfer function at typical reference values.


**Table 3. Temperature Sensor Transfer Function at Typical Reference Values**

|REFERENCEVOLTAGE(V)|TRANSFERFUNCTION|
|---|---|
|2|Device temperature in °C =(output code – 3825.5)/0.59|
|2.5|Device temperature in °C =(output code – 3777.2)/0.47|
|3|Device temperature in °C =(output code – 3745.0)/0.39|



**DATA FORMAT**


The ADS8634/8 output 12-bits of ADC conversion results in binary format (MSB first) for all ranges, as shown in
Table 4. Figure 76 shows the ADC transfer function for bipolar signal ranges. The unipolar range output is shown
in Table 5 and Figure 77 shows the transfer function.


**Table 4. Bipolar Range Ideal Output Codes** **[(1)]**

|INPUT SIGNAL (AINx AINGND)<br>–|Col2|Col3|IDEALOUTPUTCODE|
|---|---|---|---|
|±**10V RANGE(V)**|±**5V RANGE(V)**|±**2.5V RANGE(V)**|±**2.5V RANGE(V)**|
|≥10 × (211– 1)/211(2)|≥5 × (211– 1)/211|≥2.5 × (211– 1)/211|FFFh|
|10/211|5/211|2.5/211|801h|
|0|0|0|800h|
|–10 /211|–5/211|–2.5/211|7FFh|
|≤–10 × (211– 1)/211|≤–5 × (211– 1)/211|≤–2.5 × (211– 1)/211|000h|



(1) Excludes noise, offset and gain errors.
(2) LSB size for the bipolar ranges = positive (or negative) full-scale/2 [11] . The ADS8634/8 offer 12-bit resolution across the entire range from
positive full-scale to negative full-scale; in other words, the resolution for half range from ' 0 ' to positive (or negative) full-scale is 11 bits.
For example, a 1LSB for a ± 10V range is 10/2 [11] .


**Table 5. Unipolar Range Ideal Output Codes** **[(1)]**

|INPUT SIGNAL (AINx AINGND)<br>–|Col2|IDEALOUTPUTCODE|
|---|---|---|
|**0V TO 10V RANGE(V)**|**0V TO 5V RANGE(V)**|**0V TO 5V RANGE(V)**|
|≥10 × (212– 1)/212|≥5 × (212– 1)/212|FFFh|
|10/212|5/212|001h|
|< 10/212|< 5/212|000h|



(1) Excludes noise, offset and gain errors.


26 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


FFFh


800h


001h


Negative 0 Positive
FSR + 1LSB FSR 1LSB


Analog Input (AINx AINGND)


**Figure 76. Transfer Function for Bipolar Signal Ranges**


FFFh


800h


001h


1LSB FSR/2 FSR – 1LSB


Analog Input (AINx AINGND)


**Figure 77. Transfer Function for Unipolar Signal Ranges**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 27


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**AL_PD: USER-CONFIGURABLE PIN**


The ADS8634/8 feature a user-configurable AL_PD pin. This pin can either be configured as an alarm output
(AL) or as a power-down control pin (PD). Refer to the _Page 0, Register Descriptions for the ADS8638_ and _Page_
_0, Register Descriptions for the ADS8634_ sections for details.


When programmed as an alarm output, an active-high alarm is flagged on this pin if there is a high or low alarm
on any channel. The _Alarm Functionality_ section describes the pin details.


When programmed as PD, the AL_PD pin functions as an active-low power-down input pin. Powering down
through this pin is asynchronous. The devices power down immediately after the pin goes low. The _Power-Down_
_Functionality_ section describes the pin details.


This pin is configured as a PD input by default after power-on or reset.


**Alarm Functionality**


The ADS8634/8 output an active-high alarm on the AL_PD pin when it is programmed as an AL. AL is
synchronous and changes its state on the 16th SCLK rising edge. A high level on AL indicates there is an active
alarm on one or more channels. This pin can be wired to interrupt the host input. When an alarm interrupt is
received, the alarm flag registers are read to determine which channels have an alarm.


The ADS8634/8 feature independently-programmable alarms for each channel. There are two alarms per
channel (low and high alarm) and each alarm threshold has a separate hysteresis setting.


The ADS8634/8 set a high alarm when the digital output for a particular channel exceeds the high alarm upper
limit (high alarm threshold _T_ + hysteresis _H_ ). The alarm resets when the digital output for the channel is less than
or equal to the high alarm lower limit (high alarm T – H). This function is shown in Figure 78.



(T – H) (T + H + 1)



ADC Output



NOTE: T = alarm threshold and H = hysteresis.



**Figure 78. High-Alarm Hysteresis**


Similarly, the lower alarm is triggered when the digital output for a particular channel falls below the low alarm
lower limit (low alarm threshold T – H). The alarm resets when the digital output for the channel is greater than or
equal to the low alarm higher limit (low alarm T + H). This function is shown in Figure 79.



(T – H – 1) (T + H)



ADC Output



NOTE: T = alarm threshold and H = hysteresis.



**Figure 79. Low-Alarm Hysteresis**


28 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


Figure 80 shows a functional block diagram for a single-channel alarm. For each high and low alarm there are
two flags: Active Alarm Flag and Tripped Alarm Flag; refer to the _Alarm Flags for the ADS8638 (Read-Only)_ and
_Alarm Flags for the ADS8634 (Read-Only)_ sections for more details. The active alarm flag is triggered when an
alarm condition is encountered for a particular channel; the active alarm flag resets when the alarm shuts off. A
tripped alarm flag sets an alarm condition in the same manner as it does for an active alarm flag; however, it
remains latched and resets only when the appropriate alarm flag register is read.























**Figure 80. Alarm Functionality**


**Power-Down Functionality**


The ADS8634/8 feature a power-down/up control through the programmable AL_PD pin or the channel
sequencing control registers; see the _Channel Sequencing Control Registers for the ADS8638_ and _Channel_
_Sequencing Control Registers for the ADS8634_ sections for more details. This feature is extremely useful for
saving power while running the ADS8634/8 at a slower speed, or for acquiring data at full-speed in bursts and
then waiting in a power-down state for the next acquisition start event. Figure 81 through Figure 84 describe
entry to and exit from the power-down state.


The AL_PD pin can be programmed as a power-down control pin. The AL_PD pin, when programmed as PD, is
shown in Figure 81. A low on AL_PD powers down the device immediately; this action is asynchronous
operation. Data on DOUT are not valid when the device is in a power-down state.


AL_PD


Programmed as PD



Power-Down State
Active
(Internal)



Power-Down



DOUT


Valid data terminates on power down.


**Figure 81. Power-Down Using the AL_PD Pin**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 29


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


A high level on AL_PD acts as a power-up request and the power-up sequence begins on the next CS falling
edge. The device is active after td(PWRUP). The first valid acquisition initiates in the first data frame (with a CS
falling edge) after a power-up delay. The first valid data are presented in the second data frame after the device
attains an active state, as shown in Figure 82.


CS



1 2 16



SCLK


AL_PD

Programmed as PD


Power-Down State
(Internal)


DOUT



Invalid Data Invalid Data Invalid Data


**Figure 82. Power-Up Via the AL_PD Pin**



1 2 16 1 2 16



Valid Data





1 2 16


Valid Data



The power-down/up operation can also be controlled with register settings. See the _Channel Sequencing Control_
_Registers for the ADS8638_ and _Channel Sequencing Control Registers for the ADS8634_ sections for details.
Figure 83 illustrates power-down and power-up commands for quick reference.


CS


1 2 15 16


SCLK



DIN


Power-Down State
(Internal)



Active



Power-Down



**Figure 83. Power-Down Via Register Write**


After receiving a valid power-down command, the device enters a power-down state on 16th SCLK falling edge.
An example of this command is given in Table 6.


**Table 6. Power-Down Command Example**

|PIN|REGISTERADDRESS|Col3|Col4|Col5|Col6|Col7|Col8|RD/<br>WR|DATA|Col11|Col12|Col13|Col14|Col15|Col16|Col17|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**PIN**|**Bit 15**|**Bit 14**|**Bit 13**|**Bit 12**|**Bit 11**|**Bit 10**|**Bit 9**|**Bit 8**|**Bit 7**|**Bit 6**|**Bit 5**|**Bit 4**|**Bit 3**|**Bit 2**|**Bit 1**|**Bit 0**|
|DIN|0|0|0|0|1|0|X|0|0|X|X|X|1|1|1|X|
||Auto/manual sequence|Auto/manual sequence|Auto/manual sequence|Auto/manual sequence|Auto/manual sequence|Auto/manual sequence|Auto/manual sequence|W|0|X|X|X|Power-down|Power-down|Power-down|X|



30 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


The serial interface is active even during a device power-down state. Commands can be issued via the DIN pin
during a power-down state.


A power-up command (through DIN) is acknowledged on the next CS falling edge and a power-up sequence
initiates. An example of this command is given in Table 7. The device is in an active state after td(PWRUP) and
initiates a valid acquisition in the first data frame (initiated with a CS falling edge) after a power-up delay. The
first valid data are presented in the second data frame after the device attains an active state, as shown in
Figure 84.


**Table 7. Power-Up Command Example**

|PIN|REGISTERADDRESS|Col3|Col4|Col5|Col6|Col7|Col8|RD/<br>WR|DATA|Col11|Col12|Col13|Col14|Col15|Col16|Col17|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**PIN**|**Bit 15**|**Bit 14**|**Bit 13**|**Bit 12**|**Bit 11**|**Bit 10**|**Bit 9**|**Bit 8**|**Bit 7**|**Bit 6**|**Bit 5**|**Bit 4**|**Bit 3**|**Bit 2**|**Bit 1**|**Bit 0**|
|DIN|0|0|0|0|1|0|X|0|0|X|X|X|Any combination from<br>000 to 110, except 111|Any combination from<br>000 to 110, except 111|Any combination from<br>000 to 110, except 111|X|
||Auto/manual sequence|Auto/manual sequence|Auto/manual sequence|Auto/manual sequence|Auto/manual sequence|Auto/manual sequence|Auto/manual sequence|W|0|X|X|X|Power-up|Power-up|Power-up|X|



CS



1 2 16 1 2 16 1 2



16



1 2 16



SCLK


DIN


Power-Down State
(Internal)


DOUT



Invalid Data Invalid Data Invalid Data


**Figure 84. Power-Up Via Register Write**



Valid Data





1 2 16


Valid Data











Use only one method (DIN pin or register settings) for power-down/up control. Do not combine these two
methods or the results may be confusing. Do not issue a power-down command through DIN while using the
AL_PD pin. Similarly, do not pull the AL_PD pin low while using the register write method for power-down/up
control.


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 31


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**DEVICE OPERATION**


The ADS8634/8 are 12-bit, 4-/8-channel devices. Each frame begins with a CS falling edge. The ADS8634/8
sample the input signal from the selected channel on the CS falling edge and initiate conversion. SCLK is used
for conversion and data are output on the DOUT line while conversion is in process. The 16-bit data word
contains a 4-bit channel address followed by the 12-bit conversion result in MSB-first format. The MSB of the
4-bit channel address is output on the CS falling edge; the remaining address bits are clocked out serially for
three SCLK falling edges. The MSB of the 12-bit conversion result is output on the fourth SCLK falling edge.
Afterwards, the next lower data bits are ouput serially on every subsequen SCLK falling edge. Each data bit can
be read (latched) immediately on the next SCLK falling edge from the SCLK falling edge on which the respective
data bits are output. For example, if the MSB of a 12-bit data word is output on the fourth SCLK falling edge then
the same word can be latched on the fifth SCLK falling edge. Refer to the _Hold time_, _SCLK falling to DOUT valid_,
and _Delay time, SCLK falling to DOUT_ parameters in the _Timing Requirements_ section.


The 16-bit word is read on the DIN pin while the data are output on the DOUT pin. DIN data are latched on every
SCLK rising edge, starting with the first clock, as shown in Figure 85.


Sample n Sample n + 1


CS


SCLK



DOUT


DIN


ADC Phase
(Internal)


AL_PD
(Programmed as
an alarm



|Col1|Col2|Col3|Col4|Col5|Col6|Col7|Col8|Col9|Col10|Col11|Col12|Col13|Col14|Col15|Col16|Col17|Col18|Col19|Col20|Col21|Col22|Col23|Col24|Col25|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||||||||||||A3|A3|A3|A3|
||||||||||||||||||||||||||
||||||||||||||||||||||||||
||||||A0|D11||||||||||||D0|D0|D0|D0|D0|D0|D0|
||||||||||||||||||||||||||
|||||||Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|||||||||
|||||||Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|Conversion Result For Sample n|||||||||
|||B15|||||||||||||||B|0|||B15||||
||||||||||||||||||||||||||
|||Conversion n|Conversion n|Conversion n|Conversion n|Conversion n|Conversion n|Conversion n|Conversion n|Conversion n|Conversion n|Conversion n|Conversion n|Conversion n|Conversion n|Conversion n||Acquisition n+1|Acquisition n+1|Acquisition n+1|Conversion n+1|Conversion n+1|Conversion n+1|Conversion n+1|
||||||||||||||||||||||||||
||||||||||||||||||||||||||


**Figure 85. ADS8634/8 Operation**









Device configuration and operation mode are controlled through register settings. It is recommended to write to
the configuration registers after powering on the device. The configuration information is retained until the
devices are powered off or reset. Note that powering down the device with either the AL_PD pin or a register
write does not erase the device configuration.


The ADS8634/8 feature an AL_PD pin that functions as a alarm output/power-down pin. The pin can be
programmed as an alarm output (AL) or it can be programmed as a power-down control pin (PD). When AL_PD
is programmed as an alarm output, it is refreshed on every 16th SCLK rising edge.


32 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**CHANNEL SEQUENCING MODES**


The ADS8634/8 offer two channel sequencing modes: auto and manual. In auto-scan mode, the channel number
automatically increments every frame. In manual mode, the channel is selected for every frame of a register
write. The analog inputs can be selected for an automatic scan with a register setting. The device automatically
scans only the selected analog inputs in ascending order.


The auto-mode sequence can be reset at any time during an automatic scan (refer to the _Auto_ register in the
_PAGE-0 Register Map for the ADS8638_ section ). When the reset command has been received, the ongoing
auto-mode sequence is reset and restarts it from the lowest selected channel in the sequence.


Figure 86 shows the DIN command sequence for transitions from auto to manual mode. Figure 87 shows the
DIN command sequence for transitions from manual to auto-scan mode. Note that each DIN command is
executed on the next CS falling edge.


Ch 5 Ch 0 Ch 5 Ch 1 Ch 0
Sample Sample Sample Sample Sample


CS


SCLK



DOUT


DIN


Selected

Channel


|Col1|Ch5Data|Col3|Ch0Data|Col5|Ch5Data|Col7|Ch1Data|Col9|Ch0Data|Col11|
|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||



Ch 0 Ch 5 Ch 1 Ch 0 Ch 3



Auto/0000h



Man Ch 1



Man Ch 0



Man Ch 3



Man Ch 7



**Figure 86. Transition from Auto to Manual Mode (Channels 0 and 5 are selected for auto sequence)**


Ch n 1 Ch n Ch 3 Ch 2 Ch 5
Sample Sample Sample Sample Sample


CS


SCLK



DOUT


DIN


Selected

Channel


|Col1|Chn 1Data|Col3|ChnData|Col5|Ch3Data|Col7|Ch2Data|Col9|Ch5Data|Col11|
|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||





0000h



0000h



0000h



Man Ch3



Auto


|Chn|Ch3|Ch2|Ch5|Ch2|
|---|---|---|---|---|
|Manual Scan|Manual Scan|Auto Scan|Auto Scan|Auto Scan|



**Figure 87. Transition from Manual to auto-scan mode (Channels 2 and 5 are selected for auto sequence)**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 33


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**DEVICE TEMPARATURE READ**


The ADS8634/8 feature an internal temperature sensor. The device temperature can be read at any time during
any scan. It is essential to enable (power-up) the internal temperature at least one cycle before selecting the
temperature sensor for the device temperature measurement. The temperature sensor must be deselected after
temperature measurement. The device resumes the channel sequence from where it left the scan after
deselection of the temperature sensor. Do not disable (power-down) the temperature sensor before it is
deselected. Figure 88 illustrates a typical command sequence for device temperature measurement during an
auto scan.


Ch 3 Ch 0 Ch 3 Ch 0 Temperature
Sample Sample Sample Sample Sample


CS


SCLK



DOUT


DIN


Selected

Channel



|Col1|Ch3Data|Col3|Ch0Data|Col5|Ch3Data|Col7|Ch0Data|Col9|TempData|Col11|
|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||


Auto/0000h



Aux (TS Enable)



Sel Temp Sensor



Deselect Temp Sensor Auto/0000h



Ch 0 Ch 3 Ch 0 Temp Sensor Ch 3







**Figure 88. Reading Temperature During Auto Scan (Channels 0 and 3 are selected for auto sequence)**


**SPI INTERFACE**


The ADS8634/8 employ a four-wire SPI-compatible interface. Apart from the interface, CS and SCLK also
perform an ADC control function.


The data frame is synchronized with the CS falling edge. A low level on CS releases the DOUT pin from
three-state and the ADC conversion results are output on the DOUT line. Data bits are clocked out on the falling
edges of SCLK. The ADS8634/8 sample the analog input signal on the falling edge of CS and conversion is
performed using SCLK.


DOUT is the serial data output line. Depending on register settings,the ADC conversion results are output along
with the selected channel address or register data on the DOUT pin. The data output frame always consists of 16
bits. The SDO line goes to three-state after all the 16-bits of data frame are output or after CS goes high.


DIN is a serial data input line. It is used to program various registers for either device configuration or for
dynamic changes applicable on the next immediate CS falling edge.


34 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**DOUT DATA FORMAT**


The device outputs 16-bit data in every cycle. Table 8 shows the DOUT data format.

|Col1|Col2|Col3|Col4|Col5|Table 8. DOUT Data Format|Col7|Col8|Col9|Col10|Col11|Col12|Col13|Col14|Col15|Col16|Col17|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**PIN**|**CHANNEL ADDRESS**|**CHANNEL ADDRESS**|**CHANNEL ADDRESS**|**CHANNEL ADDRESS**|**CONVERSION RESULT**|**CONVERSION RESULT**|**CONVERSION RESULT**|**CONVERSION RESULT**|**CONVERSION RESULT**|**CONVERSION RESULT**|**CONVERSION RESULT**|**CONVERSION RESULT**|**CONVERSION RESULT**|**CONVERSION RESULT**|**CONVERSION RESULT**|**CONVERSION RESULT**|
|**PIN**|**Bit 15**|**Bit 14**|**Bit 13**|**Bit 12**|**Bit 11**|**Bit 10**|**Bit 9**|**Bit 8**|**Bit 7**|**Bit 6**|**Bit 5**|**Bit 4**|**Bit 3**|**Bit 2**|**Bit 1**|**Bit 0**|
|DOUT|ADDR<br>3|ADDR<br>2|ADDR<br>1|ADDR<br>0|D11<br>(MSB)|D10|D9|D8|D7|D6|D5|D4|D3|D2|D1|D0<br>(LSB)|



**Bit Description for the ADS8638 DOUT Data**


**Bits[15:12]** **Channel/temperature sensor address**


These bits represent the adress of channel or temperature sensor.


0000 = Channel 0
0001 = Channel 1
0010 = Channel 2
0011 = Channel 3
0100 = Channel 4
0101 = Channel 5
0110 = Channel 6
0111 = Channel 7
1111 = Temperature sensor


**Bits[11:0]** **Conversion result for the channel/temperature sensor represented by bits[15:12], in MSB-first format**


**Bit Description for the ADS8634 DOUT Data**


**Bits[15:12]** **Channel/temperature sensor address**


These bits represent the adress of channel or temperature sensor.


000X = Channel 0
001X = Channel 1
010X = Channel 2
011X = Channel 3
1111 = Temperature sensor


**Bits[11:0]** **Conversion result for the channel/temperature sensor represented by bits[15:12], in MSB-first format**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 35


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**DIN DATA FORMAT (SPI COMMAND WORD)**


Device registers can be written to and read from. There must be a minimum of 16 SCLKs after the CS falling
edge for any read or write operation. The device receives the command (as shown in Table 9 and Table 10)
through DIN where the first seven bits (bits[15:9]) represent the register address and the eighth bit (bit 8) is the
read/write instruction. For a write cycle, the next eight bits (bits[7:0]) in the DIN are the desired data for the
addressed register (Table 9). For a read cycle, the next eight bits (bits[7:0]) in the DIN are _don_ ’ _t care_ . DOUT
outputs the 8-bit data from the addressed register (Table 10) during these eight clocks, corresponding to
bits[7:0].


**Table 9. Write Cycle Command Word**

|PIN|REGISTERADDRESS|Col3|Col4|Col5|Col6|Col7|Col8|RD/<br>WR|DATA|Col11|Col12|Col13|Col14|Col15|Col16|Col17|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**PIN**|**Bit 15**|**Bit 14**|**Bit 13**|**Bit 12**|**Bit 11**|**Bit 10**|**Bit 9**|**Bit 8**|**Bit 7**|**Bit 6**|**Bit 5**|**Bit 4**|**Bit 3**|**Bit 2**|**Bit 1**|**Bit 0**|
|DIN|ADDR<br>6|ADDR<br>5|ADDR<br>4|ADDR<br>3|ADDR<br>2|ADDR<br>1|ADDR<br>0|R/W|DIN7|DIN6|DIN5|DIN4|DIN3|DIN2|DIN1|DIN0|



**Table 10. Read Cycle Command Word**

|PIN|REGISTERADDRESS|Col3|Col4|Col5|Col6|Col7|Col8|RD/<br>WR|DATA|Col11|Col12|Col13|Col14|Col15|Col16|Col17|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**PIN**|**Bit 15**|**Bit 14**|**Bit 13**|**Bit 12**|**Bit 11**|**Bit 10**|**Bit 9**|**Bit 8**|**Bit 7**|**Bit 6**|**Bit 5**|**Bit 4**|**Bit 3**|**Bit 2**|**Bit 1**|**Bit 0**|
|DIN|ADDR<br>6|ADDR<br>5|ADDR<br>4|ADDR<br>3|ADDR<br>2|ADDR<br>1|ADDR<br>0|R/W|X|X|X|X|X|X|X|X|
|DOUT|X|X|X|X|X|X|X|X|DOUT<br>7|DOUT<br>6|DOUT<br>5|DOUT<br>4|DOUT<br>3|DOUT<br>2|DOUT<br>1|DOUT<br>0|



36 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**SPI REGISTER WRITE CYCLE**


Figure 89 shows a timing diagram of the SPI write cycle. The device executes the command on the first CS
falling edge after a command write cycle. The only exception to this command execution timing is the
power-down command. The power-down command (through a register write) is executed on the 16th falling edge
of SCLK. This falling edge occurs immediately after the last command bit is written to the device.


CS


SCLK



DIN


DOUT





**Figure 89. Write Cycle**


**SPI REGISTER READ CYCLE**


Figure 90 shows a timing diagram of the SPI read cycle.


CS


SCLK



DIN


DOUT







**Figure 90. Read Cycle**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 37


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**REGISTER MAP: ADS8638**


The ADS8638 internal registers are mapped in two pages: page 0 and page 1. Page 0 is selected by default at
power-up and after reset. Any register read/write operation performed while on page 0 addresses the page 0
registers. Writing 01h to register address 7Fh selects page 1 for any further register operations.


Page 0 registers are used to select the channel sequencing mode, program the configuration registers, and read
the alarm flags. Page 1 resisters are used to program alarm thresholds for each channel and for the temperature
sensor. Table 11 details page 0 and Table 12 details page 1.


**Table 11. ADS8638 Page 0 Register Map**

|REGISTER|REGISTER<br>ADDRESS<br>BITS[15:9]|DEFAULT<br>VALUE(1)|BIT7|BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0|
|---|---|---|---|---|---|---|---|---|---|---|
|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|
|Manual|04h|00h|0|Channel Select[2:0]|Channel Select[2:0]|Channel Select[2:0]|Range Select[2:0]|Range Select[2:0]|Range Select[2:0]|Sel Temp<br>Sensor|
|Auto|05h|00h|Reset-Seq|0|0|0|Range Select[2:0]|Range Select[2:0]|Range Select[2:0]|Sel Temp<br>Sensor|
|Holding the DIN line low continuously (equivalent to writing '0' to all 16 bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto or<br>manual).|Holding the DIN line low continuously (equivalent to writing '0' to all 16 bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto or<br>manual).|Holding the DIN line low continuously (equivalent to writing '0' to all 16 bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto or<br>manual).|Holding the DIN line low continuously (equivalent to writing '0' to all 16 bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto or<br>manual).|Holding the DIN line low continuously (equivalent to writing '0' to all 16 bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto or<br>manual).|Holding the DIN line low continuously (equivalent to writing '0' to all 16 bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto or<br>manual).|Holding the DIN line low continuously (equivalent to writing '0' to all 16 bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto or<br>manual).|Holding the DIN line low continuously (equivalent to writing '0' to all 16 bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto or<br>manual).|Holding the DIN line low continuously (equivalent to writing '0' to all 16 bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto or<br>manual).|Holding the DIN line low continuously (equivalent to writing '0' to all 16 bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto or<br>manual).|Holding the DIN line low continuously (equivalent to writing '0' to all 16 bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto or<br>manual).|
|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|
|Reset-Device|01h|00h|0|0|0|0|0|0|0|Reset-Dev|
|Aux-Config|06h|08h|0|0|0|0|AL_PD<br>Control|Int VREF<br>Enable|Temp<br>Sensor<br>Enable|0|
|Auto-Md Ch-Sel|0Ch|00h|Sel Ch0|Sel Ch1|Sel Ch2|Sel Ch3|Sel Ch4|Sel Ch5|Sel Ch6|Sel Ch7|
|Ch0-1 Range|10h|11h|0|Range Select Ch0[2:0]|Range Select Ch0[2:0]|Range Select Ch0[2:0]|0|Range Select Ch1[2:0]|Range Select Ch1[2:0]|Range Select Ch1[2:0]|
|Ch2-3 Range|11h|11h|0|Range Select Ch2[2:0]|Range Select Ch2[2:0]|Range Select Ch2[2:0]|0|Range Select Ch3[2:0]|Range Select Ch3[2:0]|Range Select Ch3[2:0]|
|Ch4-5 Range|12h|11h|0|Range Select Ch4[2:0]|Range Select Ch4[2:0]|Range Select Ch4[2:0]|0|Range Select Ch5[2:0]|Range Select Ch5[2:0]|Range Select Ch5[2:0]|
|Ch6-7 Range|13h|11h|0|Range Select Ch6[2:0]|Range Select Ch6[2:0]|Range Select Ch6[2:0]|0|Range Select Ch7[2:0]|Range Select Ch7[2:0]|Range Select Ch7[2:0]|
|**Alarm Flag Registerss (Read-Only)**|**Alarm Flag Registerss (Read-Only)**|**Alarm Flag Registerss (Read-Only)**|**Alarm Flag Registerss (Read-Only)**|**Alarm Flag Registerss (Read-Only)**|**Alarm Flag Registerss (Read-Only)**|**Alarm Flag Registerss (Read-Only)**|**Alarm Flag Registerss (Read-Only)**|**Alarm Flag Registerss (Read-Only)**|**Alarm Flag Registerss (Read-Only)**|**Alarm Flag Registerss (Read-Only)**|
|Temp-Flag|20h|00h|Tripped<br>Alarm Flag<br>Temperature<br>Low|Tripped<br>Alarm Flag<br>Temperature<br>High|Active Alarm<br>Flag<br>Temperature<br>Low|Active Alarm<br>Flag<br>Temperature<br>High|0|0|0|0|
|Ch0-3 Tripped-Flag|21h|00h|Tripped<br>Alarm Flag<br>Ch0 Low|Tripped<br>Alarm Flag<br>Ch0 High|Tripped<br>Alarm Flag<br>Ch1 Low|Tripped<br>Alarm Flag<br>Ch1 High|Tripped<br>Alarm Flag<br>Ch2 Low|Tripped<br>Alarm Flag<br>Ch2 High|Tripped<br>Alarm Flag<br>Ch3 Low|Tripped<br>Alarm Flag<br>Ch3 High|
|Ch0-3 Active-Flag|22h|00h|Active Alarm<br>Flag Ch0<br>Low|Active Alarm<br>Flag Ch0<br>High|Active Alarm<br>Flag Ch1<br>Low|Active Alarm<br>Flag Ch1<br>High|Active Alarm<br>Flag Ch2<br>Low|Active Alarm<br>Flag Ch2<br>High|Active Alarm<br>Flag Ch3<br>Low|Active Alarm<br>Flag Ch3<br>High|
|Ch4-7 Tripped-Flag|23h|00h|Tripped<br>Alarm Flag<br>Ch4 Low|Tripped<br>Alarm Flag<br>Ch4 High|Tripped<br>Alarm Flag<br>Ch5 Low|Tripped<br>Alarm Flag<br>Ch5 High|Tripped<br>Alarm Flag<br>Ch6 Low|Tripped<br>Alarm Flag<br>Ch6 High|Tripped<br>Alarm Flag<br>Ch7 Low|Tripped<br>Alarm Flag<br>Ch7 High|
|Ch4-7 Active-Flag|24h|00h|Active Alarm<br>Flag Ch4<br>Low|Active Alarm<br>Flag Ch4<br>High|Active Alarm<br>Flag Ch5<br>Low|Active Alarm<br>Flag Ch5<br>High|Active Alarm<br>Flag Ch6<br>Low|Active Alarm<br>Flag Ch6<br>High|Active Alarm<br>Flag Ch7<br>Low|Active Alarm<br>Flag Ch7<br>High|
|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|
|Page|7Fh|00h|0|0|0|0|0|0|0|Page Addr|



(1) All registers are reset to the default values at power-on or at device reset using the register settings method.


38 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**Table 12. ADS8638 Page 1 Register Map**

|REGISTER|REGISTER<br>ADDRESS<br>BITS[15:9]|DEFAULT<br>VALUE(1)|BIT7|BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0|
|---|---|---|---|---|---|---|---|---|---|---|
|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|
|TLA MSB|00h|00h|TLA Hysteresis[3:0]|TLA Hysteresis[3:0]|TLA Hysteresis[3:0]|TLA Hysteresis[3:0]|TLA[11:8]|TLA[11:8]|TLA[11:8]|TLA[11:8]|
|TLA LSB|01h|00h|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|
|THA MSB|02h|00h|THA Hysteresis[3:0]|THA Hysteresis[3:0]|THA Hysteresis[3:0]|THA Hysteresis[3:0]|THA[11:8]|THA[11:8]|THA[11:8]|THA[11:8]|
|THA LSB|03h|00h|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|
|Ch0LA MSB|04h|00h|Ch0-LA Hysteresis[3:0]|Ch0-LA Hysteresis[3:0]|Ch0-LA Hysteresis[3:0]|Ch0-LA Hysteresis[3:0]|Ch0-LA[11:8]|Ch0-LA[11:8]|Ch0-LA[11:8]|Ch0-LA[11:8]|
|Ch0LA LSB|05h|00h|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|
|Ch0HA MSB|06h|00h|Ch0-HA Hysteresis[3:0]|Ch0-HA Hysteresis[3:0]|Ch0-HA Hysteresis[3:0]|Ch0-HA Hysteresis[3:0]|Ch0-HA[11:8]|Ch0-HA[11:8]|Ch0-HA[11:8]|Ch0-HA[11:8]|
|Ch0HA LSB|07h|00h|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|
|Ch1LA MSB|08h|00h|Ch1-LA Hysteresis[3:0]|Ch1-LA Hysteresis[3:0]|Ch1-LA Hysteresis[3:0]|Ch1-LA Hysteresis[3:0]|Ch1-LA[11:8]|Ch1-LA[11:8]|Ch1-LA[11:8]|Ch1-LA[11:8]|
|Ch1LA LSB|09h|00h|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|
|Ch1 HA MSB|0Ah|00h|Ch1-HA Hysteresis[3:0]|Ch1-HA Hysteresis[3:0]|Ch1-HA Hysteresis[3:0]|Ch1-HA Hysteresis[3:0]|Ch1-HA[11:8]|Ch1-HA[11:8]|Ch1-HA[11:8]|Ch1-HA[11:8]|
|Ch1 HA LSB|0Bh|00h|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|
|Ch2 LA MSB|0Ch|00h|Ch2-LA Hysteresis[3:0]|Ch2-LA Hysteresis[3:0]|Ch2-LA Hysteresis[3:0]|Ch2-LA Hysteresis[3:0]|Ch2-LA[11:8]|Ch2-LA[11:8]|Ch2-LA[11:8]|Ch2-LA[11:8]|
|Ch2 LA LSB|0Dh|00h|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|
|Ch2 HA MSB|0Eh|00h|Ch2-HA Hysteresis[3:0]|Ch2-HA Hysteresis[3:0]|Ch2-HA Hysteresis[3:0]|Ch2-HA Hysteresis[3:0]|Ch2-HA[11:8]|Ch2-HA[11:8]|Ch2-HA[11:8]|Ch2-HA[11:8]|
|Ch2 HA LSB|0Fh|00h|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|
|Ch3 LA MSB|10h|00h|Ch3-LA Hysteresis[3:0]|Ch3-LA Hysteresis[3:0]|Ch3-LA Hysteresis[3:0]|Ch3-LA Hysteresis[3:0]|Ch3-LA[11:8]|Ch3-LA[11:8]|Ch3-LA[11:8]|Ch3-LA[11:8]|
|Ch3 LA LSB|11h|00h|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|
|Ch3 HA MSB|12h|00h|Ch3-HA Hysteresis[3:0]|Ch3-HA Hysteresis[3:0]|Ch3-HA Hysteresis[3:0]|Ch3-HA Hysteresis[3:0]|Ch3-HA[11:8]|Ch3-HA[11:8]|Ch3-HA[11:8]|Ch3-HA[11:8]|
|Ch3 HA LSB|13h|00h|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|
|Ch4 LA MSB|14h|00h|Ch4-LA Hysteresis[3:0]|Ch4-LA Hysteresis[3:0]|Ch4-LA Hysteresis[3:0]|Ch4-LA Hysteresis[3:0]|Ch4-LA[11:8]|Ch4-LA[11:8]|Ch4-LA[11:8]|Ch4-LA[11:8]|
|Ch4 LA LSB|15h|00h|Ch4-LA[7:0]|Ch4-LA[7:0]|Ch4-LA[7:0]|Ch4-LA[7:0]|Ch4-LA[7:0]|Ch4-LA[7:0]|Ch4-LA[7:0]|Ch4-LA[7:0]|
|Ch4 HA MSB|16h|00h|Ch4-HA Hysteresis[3:0]|Ch4-HA Hysteresis[3:0]|Ch4-HA Hysteresis[3:0]|Ch4-HA Hysteresis[3:0]|Ch4-HA[11:8]|Ch4-HA[11:8]|Ch4-HA[11:8]|Ch4-HA[11:8]|
|Ch4 HA LSB|17h|00h|Ch4-HA[7:0]|Ch4-HA[7:0]|Ch4-HA[7:0]|Ch4-HA[7:0]|Ch4-HA[7:0]|Ch4-HA[7:0]|Ch4-HA[7:0]|Ch4-HA[7:0]|
|Ch5 LA MSB|18h|00h|Ch5-LA Hysteresis[3:0]|Ch5-LA Hysteresis[3:0]|Ch5-LA Hysteresis[3:0]|Ch5-LA Hysteresis[3:0]|Ch5-LA[11:8]|Ch5-LA[11:8]|Ch5-LA[11:8]|Ch5-LA[11:8]|
|Ch5 LA LSB|19h|00h|Ch5-LA[7:0]|Ch5-LA[7:0]|Ch5-LA[7:0]|Ch5-LA[7:0]|Ch5-LA[7:0]|Ch5-LA[7:0]|Ch5-LA[7:0]|Ch5-LA[7:0]|
|Ch5 HA MSB|1Ah|00h|Ch5-HA Hysteresis[3:0]|Ch5-HA Hysteresis[3:0]|Ch5-HA Hysteresis[3:0]|Ch5-HA Hysteresis[3:0]|Ch5-HA[11:8]|Ch5-HA[11:8]|Ch5-HA[11:8]|Ch5-HA[11:8]|
|Ch5 HA LSB|1Bh|00h|Ch5-HA[7:0]|Ch5-HA[7:0]|Ch5-HA[7:0]|Ch5-HA[7:0]|Ch5-HA[7:0]|Ch5-HA[7:0]|Ch5-HA[7:0]|Ch5-HA[7:0]|
|Ch6 LA MSB|1Ch|00h|Ch6-LA Hysteresis[3:0]|Ch6-LA Hysteresis[3:0]|Ch6-LA Hysteresis[3:0]|Ch6-LA Hysteresis[3:0]|Ch6-LA[11:8]|Ch6-LA[11:8]|Ch6-LA[11:8]|Ch6-LA[11:8]|
|Ch6 LA LSB|1Dh|00h|Ch6-LA[7:0]|Ch6-LA[7:0]|Ch6-LA[7:0]|Ch6-LA[7:0]|Ch6-LA[7:0]|Ch6-LA[7:0]|Ch6-LA[7:0]|Ch6-LA[7:0]|
|Ch6 HA MSB|1Eh|00h|Ch6-HA Hysteresis[3:0]|Ch6-HA Hysteresis[3:0]|Ch6-HA Hysteresis[3:0]|Ch6-HA Hysteresis[3:0]|Ch6-HA[11:8]|Ch6-HA[11:8]|Ch6-HA[11:8]|Ch6-HA[11:8]|
|Ch6 HA LSB|1Fh|00h|Ch6-HA[7:0]|Ch6-HA[7:0]|Ch6-HA[7:0]|Ch6-HA[7:0]|Ch6-HA[7:0]|Ch6-HA[7:0]|Ch6-HA[7:0]|Ch6-HA[7:0]|
|Ch7 LA MSB|20h|00h|Ch7-LA Hysteresis[3:0]|Ch7-LA Hysteresis[3:0]|Ch7-LA Hysteresis[3:0]|Ch7-LA Hysteresis[3:0]|Ch7-LA[11:8]|Ch7-LA[11:8]|Ch7-LA[11:8]|Ch7-LA[11:8]|
|Ch7 LA LSB|21h|00h|Ch7-LA[7:0]|Ch7-LA[7:0]|Ch7-LA[7:0]|Ch7-LA[7:0]|Ch7-LA[7:0]|Ch7-LA[7:0]|Ch7-LA[7:0]|Ch7-LA[7:0]|
|Ch7 HA MSB|22h|00h|Ch7-HA Hysteresis[3:0]|Ch7-HA Hysteresis[3:0]|Ch7-HA Hysteresis[3:0]|Ch7-HA Hysteresis[3:0]|Ch7-HA[11:8]|Ch7-HA[11:8]|Ch7-HA[11:8]|Ch7-HA[11:8]|
|Ch7 HA LSB|23h|00h|Ch7-HA[7:0]|Ch7-HA[7:0]|Ch7-HA[7:0]|Ch7-HA[7:0]|Ch7-HA[7:0]|Ch7-HA[7:0]|Ch7-HA[7:0]|Ch7-HA[7:0]|
|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|
|Page|7Fh|00h|0|0|0|0|0|0|0|Page Addr|



(1) All registers are reset to the default values at power-on or at device reset using the register settings method.


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 39


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**PAGE 0 REGISTER DESCRIPTIONS: ADS8638**


This section provides bit-by-bit descriptions of each page 0 register.


**Channel Sequencing Control Registers for the ADS8638**


There are two modes for channel sequencing: auto and manual mode. In auto-scan mode, the device
automatically scans the preselected channels in sequential order with a new channel selected for every
conversion. In manual mode, the channel is manually selected for the next conversion. In both modes, the
preselected signal range is considered for each channel independently. Note that the range can be temporarily
overriden.


_**Manual: Manual Mode Register (Address = 04h; Page 0)**_


7 6 5 4 3 2 1 0

0 Channel Select[2:0] Range Select[2:0] Sel TempSensor


This register selects device operation in manual scan mode, selects the channel for the next conversion, allows
the preselected signal range to be temporarily overriden for the next conversion, and enables the device
temperature to be read.


**Bit 7** **Must always be set to '0'**


**Bits[6:4]** **Channel Select[2:0]**


These bits select the channel for acquisition during the next frame.
For example, if this register is written in frame number _n_, then the addressed channel signal is acquired in frame
number _n + 1_ and the conversion result is available in frame number _n + 2_ .


000 = Channel 0
001 = Channel 1
010 = Channel 2
011 = Channel 3
100 = Channel 4
101 = Channel 5
110 = Channel 6
111 = Channel 7


**Bits[3:1]** **Range Select[2:0]**


These bits select the signal range for the channel acquired in the next frame.
For example, if this register is written in frame number _n_, then the selected range is applicable for frame number _n_
_+ 1_ . This is a dynamic range selection and overrides selection through the configuration registers (address 10h to
13h, page 0) only for the next frame.


000 = Ranges as selected through the configuration registers (address 10h to 13h, page 0)
001 = Range is set to ± 10V
010 = Range is set to ± 5V
011 = Range is set to ± 2.5V
100 = Reserved; do not use this setting
101 = Range is set to 0V to 10V
110 = Range is set to 0V to 5V
111 = Powers down the device immediately after the 16th SCLK falling edge


**Bit 0** **Sel Temp Sensor**


This bit selects the temperature sensor for acquisition in the next frame. This selection overrides channel selection
through bits[6:4]. Range selection is not applicable for the temperature sensor.


0 = Next conversion as per selection through bits[3:1]
1 = The temperature sensor is selected for acquisition in the next frame


40 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


_**Auto: Auto-Scan Mode Register (Address = 05h; Page 0)**_


7 6 5 4 3 2 1 0

Reset-Seq 0 0 0 Range Select[2:0] Sel TempSensor


This register selects device operation in auto-scan mode, allows the preselected signal range to be temporarily
overriden for the next conversion, and enables the device temperature to be read.


**Bit 7** **Reset-Seq**


This bit resets the auto-mode sequence counter.
The counter is reset to the lowest channel number in the selected sequence.
For example, if the Auto-Md Ch-Sel register is programmed to _01101100_ (the auto-mode sequence channels are 2,
3, 5, 6, 2, 3, 5, 6 … 2, 3, 5, 6), and, if the Reset-Seq bit is programmed to '1' in frame _n_ while channel 3 is sampled,
then the auto-mode sequence counter is reset to channel 2 in frame _n + 1_ . This setting means that channel 2 is
sampled instead of channel 5 in frame _n + 1_ .


0 = No reset (continue the sequence from the present channel number)
1 = Reset the channel sequncing counter


**Bits[6:4]** **Must always be set to '0'**


**Bits[3:1]** **Range Select[2:0]**


These bits select the signal range for the channel acquired in the next frame.
For example, if this register is written in frame number _n_, then the selected range is applicable for frame number
_n + 1_ . This is a dynamic range selection and overrides selection through the configuration registers (address 10h to
13h, page 0) only for the next frame.


000 = Ranges as selected through the configuration registers (address 10h to 13h)
001 = Range is set to ± 10V
010 = Range is set to ± 5V
011 = Range is set to ± 2.5V
100 = Reserved; do not use this setting
101 = Range is set to 0V to 10V
110 = Range is set to 0V to 5V
111 = Powers down the device immediately after the 16th SCLK falling edge


**Bit 0** **Sel Temp Sensor**


This bit selects the temperature sensor for acquisition in the next frame.
This selection overrides the channel selection through the auto sequence only for the next frame. The auto-mode
sequence continues from where it was interrupted after the temperature sensing frame.
For example, if the programmed auto sequence is channels 0, 1, 3, 0, 1, 3 … 0, 1, 3, and if the temperature sensor
is selected in frame number _n_ while channel 0 is sampled, then the temperature sensor is sampled in frame _n + 1_ .
The auto sequence resumes from frame _n + 2_ sampling channel 1.
Range selection is not applicable for the temperature sensor.


0 = Next conversion as selected through bits[3:1]
1 = The temperature sensor is selected for acquisition in the next frame


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 41


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**Continued Operation in the Selected Mode for the ADS8638**


Holding the DIN line low continuously (equivalent to writing '0' to all 16 bits) during device operation as per
Figure 85, continues device operation in the last selected mode (auto or manual). The device follows the range
selection from the configuration registers (address 10h to 13h). The the internal temperature sensor continues to
be read if the temperature sensor was selected during the last auto/manual mode frame.


**Configuration Registers for the ADS8638**


The configuration registers allow device configuration (signal range selection for individual channels, selection of
channels for auto sequence, enabling/disabling of the internal reference and temperature sensor, and
configuration of the AL_PD pin as either an alarm output or a power-down input). All registers can be reset to the
default values using the configuration register.


_**Reset-Device: Device Reset Register (Address = 01h; Page 0)**_


7 6 5 4 3 2 1 0


0 0 0 0 0 0 0 Reset-Dev


This register resets the device and assigns default values to all internal registers. The reset value for this register
is 00h; as a result, this bit is self-clearing.


**Bits[7:1]** **Must always be set to '0'**


**Bit 0** **Reset-Dev**


This bit initiates a software reset immediately after the 16th SCLK falling edge.
All registers in the device are assigned the reset values mentioned in Table 11 and Table 12.


0 = No reset
1 = Device reset


_**Aux-Config: Device Auxiliary Blocks Enable/Disable Control Register (Address = 06h; Page 0)**_


7 6 5 4 3 2 1 0


0 0 0 0 AL_PD Control Int VREF Enable Temp Sensor Enable 0


This register controls the functionality of the AL_PD pin and enables/disables blocks such as the internal
reference and internal temperature sensor.


**Bits[7:4]** **Must always be set to '0'**


**Bit 3** **AL_PD Control**


This bit controls the functionality of the AL_PD pin.


0 = AL_PD pin functions as an alarm output pin
1 = AL_PD pin functions as a power-down control pin


**Bit 2** **Int VREF Enable**


This bit powers up the internal VREF.


0 = Internal reference block is powered down at the next frame
1 = Internal reference block is powered up at the next frame


**Bit 1** **Temp Sensor Enable**


This bit powers up the internal temperature sensor.


0 = Internal temperature sensor block is powered down from the next frame
1 = Internal temperature sensor block is powered up from the next frame


**Bit 0** **Must always be set to'0'**


42 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


_**Auto-Md Ch-Sel: Channel Selection Register for Auto-Scan Mode (Address = 0Ch; Page 0)**_


7 6 5 4 3 2 1 0


Sel Ch0 Sel Ch1 Sel Ch2 Sel Ch3 Sel Ch4 Sel Ch5 Sel Ch6 Sel Ch7


This register selects the channels for the auto-mode sequence. The device scans only the selected channels in
ascending order during auto-scan mode, starting with the lowest channel selected. For example, if the Auto-Md
Ch-Sel register is programmed to _01100100_, then the auto-mode sequence is channels 2, 5, 6, 2, 5, 6 … 2, 5, 6.
In this case, the sequence always starts at channel 2. Channel 0 is selected if this register is programmed to
_00000000_ .


**Bit 7** **Sel Ch0**


This bit selects channel 0.


0 = Channel 0 not selected
1 = Channel 0 selected


**Bit 6** **Sel Ch1**


This bit selects channel 1.


0 = Channel 1 not selected
1 =Channel 1 selected


**Bit 5** **Sel Ch2**


This bit selects channel 2.


0 = Channel 2 not selected
1 = Channel 2 selected


**Bit 4** **Sel Ch3**


This bit selects channel 3.


0 = Channel 3 not selected
1 = Channel 3 selected


**Bit 3** **Sel Ch4**


This bit selects channel 4.


0 = Channel 4 not selected
1 = Channel 4 selected


**Bit 2** **Sel Ch5**


This bit selects channel 5.


0 = Channel 5 not selected
1 = Channel 5 selected


**Bit 1** **Sel Ch6**


This bit selects channel 6.


0 = Channel 6 not selected
1 = Channel 6 selected


**Bit 0** **Sel Ch7**


This bit selects channel 7.


0 = Channel 7 not selected
1 = Channel 7 selected


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 43


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


_**Ch0-1 Range to Ch6-7 Range: Range Selection Registers for Channels 0 to 7**_
_**(Address = 10h to 13h; Page 0)**_

|REGISTER|ADDRESSONPAGE0|Bit7|Bit6|Bit5|Bit4|Bit3|Bit2|Bit1|Bit0|
|---|---|---|---|---|---|---|---|---|---|
|Ch0-1 Range|10h|0|Range Select Ch0[2:0]|Range Select Ch0[2:0]|Range Select Ch0[2:0]|0|Range Select Ch1[2:0]|Range Select Ch1[2:0]|Range Select Ch1[2:0]|
|Ch2-3 Range|11h|0|Range Select Ch2[2:0]|Range Select Ch2[2:0]|Range Select Ch2[2:0]|0|Range Select Ch3[2:0]|Range Select Ch3[2:0]|Range Select Ch3[2:0]|
|Ch4-5 Range|12h|0|Range Select Ch4[2:0]|Range Select Ch4[2:0]|Range Select Ch4[2:0]|0|Range Select Ch5[2:0]|Range Select Ch5[2:0]|Range Select Ch5[2:0]|
|Ch6-7 Range|13h|0|Range Select Ch6[2:0]|Range Select Ch6[2:0]|Range Select Ch6[2:0]|0|Range Select Ch7[2:0]|Range Select Ch7[2:0]|Range Select Ch7[2:0]|



A selection of signal ranges are featured for each channel. The selected range is automatically assigned for a
channel during conversion, regardless of the channel scan mode (auto or manual). These registers (Ch0-1
Range to Ch6-7 Range) allow for range selection of all channels.


**Bit 7** **Must always be set to '0'**


**Bits[6:4]** **Range Select Chn[2:0]**


These bits select the signal range for channel _n_, where _n_ is 0, 2, 4, or 6, depending on the register address.


000 = Reserved; do not use this setting
001 = Range is set to ± 10V
010 = Range is set to ± 5V
011 = Range is set to ± 2.5V
100 = Reserved; do not use this setting
101 = Range is set to 0V to 10V
110 = Range is set to 0V to 5V
111 = Reserved; do not use this setting


**Bit 3** **Must always be set to '0'**


**Bits[2:0]** **Range Select Chm[2:0]**


These bits select the signal range for channel _m_, where _m_ is 1, 3, 5, or 7, depending on the register address.


000 = Reserved; do not use this setting
001 = Range is set to ± 10V
010 = Range is set to ± 5V
011 = Range is set to ± 2.5V
100 = Reserved; do not use this setting
101 = Range is set to 0V to 10V
110 = Range is set to 0V to 5V
111 = Reserved; do not use this setting


44 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**Alarm Flag Registers for the ADS8638 (Read-Only)**


The alarm conditions related to individual channels are stored in these registers. The flags can be read when an
alarm interrupt is received on the AL_PD pin. There are two types of flag for every alarm: active and tripped. The
active flag is set to '1' under the alarm condition (when data cross the alarm limit) and remains so as long as the
alarm condition persists. The tripped flag turns on the alarm condition similar to the active flag, but it remains set
until it is read. This feature relieves the device from having to track alarms.


_**Temp Flag: Alarm Flags Register for Temperature Sensor (Address = 20h; Page 0)**_


7 6 5 4 3 2 1 0


Tripped Alarm Flag Tripped Alarm Flag Active Alarm Flag Active Alarm Flag 0 0 0 0
Temperature Low Temperature High Temperature Low Temperature High


The Temp Flag register stores the alarm flags for the temperature sensor. There are two alarm thresholds, and
for each threshold there are two flags. An active alarm flag is enabled when an alarm is triggered (when data
cross the alarm threshold) and remains enabled as long as the alarm condition persists. A tripped alarm flag is
enabled in the same manner as an active alarm flag, but it remains latched until it is read.


**Bit 7** **Tripped Alarm Flag Temperature Low**


This bit indicates the tripped low alarm flag status for the temperature sensor.


0 = No alarm detected
1 = Alarm detected


**Bit 6** **Tripped Alarm Flag Temperature High**


This bit indicates the tripped high alarm flag status for the temperature sensor.


0 = No alarm detected
1 = Alarm detected


**Bit 5** **Active Alarm Flag Temperature Low**


This bit indicates the active low alarm flag status for the temperature sensor.


0 = No alarm
1 = Alarm detected


**Bit 4** **Active Alarm Flag Temperature High**


This bit indicates the active-high alarm flag status for the temperature sensor.


0 = No alarm detected
1 = Alarm detected


**Bits[3:0]** **Always read '0'**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 45


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


_**Ch0-3 Tripped-Flag to Ch4-7 Active-Flag: Alarm Flags Register for Channels 0 to 7**_
_**(Address = 21h to 24h; Page 0)**_

|REGISTER|ADDRESS<br>ONPAGE0|Bit7|Bit6|Bit5|Bit4|Bit3|Bit2|Bit1|Bit0|
|---|---|---|---|---|---|---|---|---|---|
|Ch0-3<br>Tripped-<br>Flag|21h|Tripped<br>Alarm Flag<br>Ch0 Low|Tripped<br>Alarm Flag<br>Ch0 High|Tripped<br>Alarm Flag<br>Ch1 Low|Tripped<br>Alarm Flag<br>Ch1 High|Tripped<br>Alarm Flag<br>Ch2 Low|Tripped<br>Alarm Flag<br>Ch2 High|Tripped<br>Alarm Flag<br>Ch3 Low|Tripped<br>Alarm Flag<br>Ch3 High|
|Ch0-3<br>Active-Flag|22h|Active<br>Alarm Flag<br>Ch0 Low|Active<br>Alarm Flag<br>Ch0 High|Active<br>Alarm Flag<br>Ch1 Low|Active<br>Alarm Flag<br>Ch1 High|Active<br>Alarm Flag<br>Ch2 Low|Active<br>Alarm Flag<br>Ch2 High|Active<br>Alarm Flag<br>Ch3 Low|Active<br>Alarm Flag<br>Ch3 High|
|Ch4-7<br>Tripped-<br>Flag|23h|Tripped<br>Alarm Flag<br>Ch4 Low|Tripped<br>Alarm Flag<br>Ch4 High|Tripped<br>Alarm Flag<br>Ch5 Low|Tripped<br>Alarm Flag<br>Ch5 High|Tripped<br>Alarm Flag<br>Ch6 Low|Tripped<br>Alarm Flag<br>Ch6 High|Tripped<br>Alarm Flag<br>Ch7 Low|Tripped<br>Alarm Flag<br>Ch7 High|
|Ch4-7<br>Active-Flag|24h|Active<br>Alarm Flag<br>Ch4 Low|Active<br>Alarm Flag<br>Ch4 High|Active<br>Alarm Flag<br>Ch5 Low|Active<br>Alarm Flag<br>Ch5 High|Active<br>Alarm Flag<br>Ch6 Low|Active<br>Alarm Flag<br>Ch6 High|Active<br>Alarm Flag<br>Ch7 Low|Active<br>Alarm Flag<br>Ch7 High|



There are two alarm thresholds (high and low) per channel, with two flags for each threshold. An active alarm
flag is enabled when an alarm is triggered (when data cross the alarm threshold) and remains enabled as long
as the alarm condition persists. A tripped alarm flag is enabled in the same manner as an active alarm flag, but it
remains latched until it is read. Registers 21h to 24h on page 0 store the active and tripped alarm flags for all
eight channels.


**Bits[7:0]** **Active/Tripped Alarm Flag Chn High/Low**


Each individual bit indicates an active/tripped, high/low alarm flag status for each channel, as per the Alarm Flags
Register for channels 0 to 7.


0 = No alarm detected
1 = Alarm detected


**Page Selection Register for the ADS8638**


The registers are arranged on two pages: page 0 and page 1. The page register selects the register page.


_**Page: Page Selection Register (Address = 7Fh; Page 0)**_


7 6 5 4 3 2 1 0


0 0 0 0 0 0 0 Page Addr


**Bits[7:1]** **Must always be set to '0'**


**Bit 0** **Page Addr**


This bit selects the page address.


0 = Selects page 0 for the next register read or write command; all register read/write operations after this are
performed on the page 0 registers until page 1 is selected
1 = Selects page 1 for the next register read or write command; all register read/write operations after this are
performed on the page 1 registers until page 0 is selected


46 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**PAGE 1 REGISTER DESCRIPTIONS: ADS8638**


This section provides bit-by-bit descriptions of each page 1 register. As described earlier, the device registers are
mapped to two pages. Page 0 is selected by default at power-up and after reset. Page 1 can be selected by
writing 01h to register address 7Fh. After selecting page 1, any register read/write action addresses the page 1
registers. Writing 00h to register address 7Fh selects page 0 for any further register operations.


**Alarm Threshold Setting Registers for the ADS8638**


The ADS8634/8 feature high and low alarms individually for the temperature sensor and each of the eight
channels. Each alarm threshold is 12 bits wide with a 4-bit hysteresis. This 16-bit setting is accomplished through
two 8-bit registers associated with every high/low alarm.


_**TLA MSB to THA LSB: Temperature Alarm Registers (Address = 00h to 03h; Page 1)**_

|REGISTER|ADDRESSON<br>PAGE1|Bit7|Bit6|Bit5|Bit4|Bit3|Bit2|Bit1|Bit0|
|---|---|---|---|---|---|---|---|---|---|
|TLA MSB||TLA Hysteresis[3:0]|TLA Hysteresis[3:0]|TLA Hysteresis[3:0]|TLA Hysteresis[3:0]|TLA[11:8]|TLA[11:8]|TLA[11:8]|TLA[11:8]|
|TLA LSB||TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|
|THA MSB||THA Hysteresis[3:0]|THA Hysteresis[3:0]|THA Hysteresis[3:0]|THA Hysteresis[3:0]|THA[11:8]|THA[11:8]|THA[11:8]|THA[11:8]|
|THA LSB||THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|



**THA/LA MSB REGISTER**


**Bits[7:4]** **THA/LA Hysteresis[3:0]**


These bits set the temperature high/low alarm hysteresis.


0000 = No hyeteresis
0001 = ± 1LSB hystetesis
0010 to 1110 = ± 2LSB to ± 14LSB hystetesis
1111 = ± 15LSB hystetesis


**Bits[3:0]** **THA/LA[11:8]**


These bits set the MSB nibble for the 12-bit temperature high/low alarm.
For example, the temperature high alarm threshold is AFFh when the THA MSB register (address 02h, page 1)
setting is Ah and the THA LSB register (address 03h, page 1) register setting is FFh.


0000 = MSB nibble is 0h
0001 = MSB nibble is 1h
0010 to 1110 = MSB nibble is 2h to Eh
1111 = MSB nibble is Fh


**THA/LA LSB REGISTER**


**Bits[7:0]** **THA/LA[7:0]**


These bits set the LSB byte for the 12-bit temperature high alarm.
For example, the temperature low alarm threshold is F02h when the TLA LSB register (address 01h) setting is 02h
and the TLS MSB register (address 00h, page 1) register setting is Fh.


0000 0000 = LSB byte is 0h
0000 0001 = LSB byte is 1h
0000 0010 to 1110 1111 = LSB byte is 02h to EFh
1111 1111 = LSB byte is FFh


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 47


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


_**Ch0LA MSB to Ch7HA LSB: Channels 0 to 7 Alarm Registers (Address = 04h to 23h; Page 1)**_

|REGISTER|ADDRESSON<br>PAGE1|Bit7|Bit6|Bit5|Bit4|Bit3|Bit2|Bit1|Bit0|
|---|---|---|---|---|---|---|---|---|---|
|Ch0LA MSB|04h|Ch0-LA Hysteresis[3:0]|Ch0-LA Hysteresis[3:0]|Ch0-LA Hysteresis[3:0]|Ch0-LA Hysteresis[3:0]|Ch0-LA[11:8]|Ch0-LA[11:8]|Ch0-LA[11:8]|Ch0-LA[11:8]|
|Ch0LA LSB|05h|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|
|Ch0HA MSB|06h|Ch0-HA Hysteresis[3:0]|Ch0-HA Hysteresis[3:0]|Ch0-HA Hysteresis[3:0]|Ch0-HA Hysteresis[3:0]|Ch0-HA[11:8]|Ch0-HA[11:8]|Ch0-HA[11:8]|Ch0-HA[11:8]|
|Ch0HA LSB|07h|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|
|Ch1LA MSB|08h|Ch1-LA Hysteresis[3:0]|Ch1-LA Hysteresis[3:0]|Ch1-LA Hysteresis[3:0]|Ch1-LA Hysteresis[3:0]|Ch1-LA[11:8]|Ch1-LA[11:8]|Ch1-LA[11:8]|Ch1-LA[11:8]|
|Ch1LA LSB|09h|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|
|Ch1HA MSB|0Ah|Ch1-HA Hysteresis[3:0]|Ch1-HA Hysteresis[3:0]|Ch1-HA Hysteresis[3:0]|Ch1-HA Hysteresis[3:0]|Ch1-HA[11:8]|Ch1-HA[11:8]|Ch1-HA[11:8]|Ch1-HA[11:8]|
|Ch1HA LSB|0Bh|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|
|Ch2LA MSB|0Ch|Ch2-LA Hysteresis[3:0]|Ch2-LA Hysteresis[3:0]|Ch2-LA Hysteresis[3:0]|Ch2-LA Hysteresis[3:0]|Ch2-LA[11:8]|Ch2-LA[11:8]|Ch2-LA[11:8]|Ch2-LA[11:8]|
|Ch2LA LSB|0Dh|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|
|Ch2HA MSB|0Eh|Ch2-HA Hysteresis[3:0]|Ch2-HA Hysteresis[3:0]|Ch2-HA Hysteresis[3:0]|Ch2-HA Hysteresis[3:0]|Ch2-HA[11:8]|Ch2-HA[11:8]|Ch2-HA[11:8]|Ch2-HA[11:8]|
|Ch2HA LSB|0Fh|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|
|Ch3LA MSB|10h|Ch3-LA Hysteresis[3:0]|Ch3-LA Hysteresis[3:0]|Ch3-LA Hysteresis[3:0]|Ch3-LA Hysteresis[3:0]|Ch3-LA[11:8]|Ch3-LA[11:8]|Ch3-LA[11:8]|Ch3-LA[11:8]|
|Ch3LA LSB|11h|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|
|Ch3HA MSB|12h|Ch3-HA Hysteresis[3:0]|Ch3-HA Hysteresis[3:0]|Ch3-HA Hysteresis[3:0]|Ch3-HA Hysteresis[3:0]|Ch3-HA[11:8]|Ch3-HA[11:8]|Ch3-HA[11:8]|Ch3-HA[11:8]|
|Ch3HA LSB|13h|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|
|Ch4LA MSB|14h|Ch4-LA Hysteresis[3:0]|Ch4-LA Hysteresis[3:0]|Ch4-LA Hysteresis[3:0]|Ch4-LA Hysteresis[3:0]|Ch4-LA[11:8]|Ch4-LA[11:8]|Ch4-LA[11:8]|Ch4-LA[11:8]|
|Ch4LA LSB|15h|Ch4-LA[7:0]|Ch4-LA[7:0]|Ch4-LA[7:0]|Ch4-LA[7:0]|Ch4-LA[7:0]|Ch4-LA[7:0]|Ch4-LA[7:0]|Ch4-LA[7:0]|
|Ch4HA MSB|16h|Ch4-HA Hysteresis[3:0]|Ch4-HA Hysteresis[3:0]|Ch4-HA Hysteresis[3:0]|Ch4-HA Hysteresis[3:0]|Ch4-HA[11:8]|Ch4-HA[11:8]|Ch4-HA[11:8]|Ch4-HA[11:8]|
|Ch4HA LSB|17h|Ch4-HA[7:0]|Ch4-HA[7:0]|Ch4-HA[7:0]|Ch4-HA[7:0]|Ch4-HA[7:0]|Ch4-HA[7:0]|Ch4-HA[7:0]|Ch4-HA[7:0]|
|Ch5LA MSB|18h|Ch5-LA Hysteresis[3:0]|Ch5-LA Hysteresis[3:0]|Ch5-LA Hysteresis[3:0]|Ch5-LA Hysteresis[3:0]|Ch5-LA[11:8]|Ch5-LA[11:8]|Ch5-LA[11:8]|Ch5-LA[11:8]|
|Ch5LA LSB|19h|Ch5-LA[7:0]|Ch5-LA[7:0]|Ch5-LA[7:0]|Ch5-LA[7:0]|Ch5-LA[7:0]|Ch5-LA[7:0]|Ch5-LA[7:0]|Ch5-LA[7:0]|
|Ch5HA MSB|1Ah|Ch5-HA Hysteresis[3:0]|Ch5-HA Hysteresis[3:0]|Ch5-HA Hysteresis[3:0]|Ch5-HA Hysteresis[3:0]|Ch5-HA[11:8]|Ch5-HA[11:8]|Ch5-HA[11:8]|Ch5-HA[11:8]|
|Ch5HA LSB|1Bh|Ch5-HA[7:0]|Ch5-HA[7:0]|Ch5-HA[7:0]|Ch5-HA[7:0]|Ch5-HA[7:0]|Ch5-HA[7:0]|Ch5-HA[7:0]|Ch5-HA[7:0]|
|Ch6LA MSB|1Ch|Ch6-LA Hysteresis[3:0]|Ch6-LA Hysteresis[3:0]|Ch6-LA Hysteresis[3:0]|Ch6-LA Hysteresis[3:0]|Ch6-LA[11:8]|Ch6-LA[11:8]|Ch6-LA[11:8]|Ch6-LA[11:8]|
|Ch6LA LSB|1Dh|Ch6-LA[7:0]|Ch6-LA[7:0]|Ch6-LA[7:0]|Ch6-LA[7:0]|Ch6-LA[7:0]|Ch6-LA[7:0]|Ch6-LA[7:0]|Ch6-LA[7:0]|
|Ch6HA MSB|1Eh|Ch6-HA Hysteresis[3:0]|Ch6-HA Hysteresis[3:0]|Ch6-HA Hysteresis[3:0]|Ch6-HA Hysteresis[3:0]|Ch6-HA[11:8]|Ch6-HA[11:8]|Ch6-HA[11:8]|Ch6-HA[11:8]|
|Ch6HA LSB|1Fh|Ch6-HA[7:0]|Ch6-HA[7:0]|Ch6-HA[7:0]|Ch6-HA[7:0]|Ch6-HA[7:0]|Ch6-HA[7:0]|Ch6-HA[7:0]|Ch6-HA[7:0]|
|Ch7LA MSB|20h|Ch7-LA Hysteresis[3:0]|Ch7-LA Hysteresis[3:0]|Ch7-LA Hysteresis[3:0]|Ch7-LA Hysteresis[3:0]|Ch7-LA[11:8]|Ch7-LA[11:8]|Ch7-LA[11:8]|Ch7-LA[11:8]|
|Ch7LA LSB|21h|Ch7-LA[7:0]|Ch7-LA[7:0]|Ch7-LA[7:0]|Ch7-LA[7:0]|Ch7-LA[7:0]|Ch7-LA[7:0]|Ch7-LA[7:0]|Ch7-LA[7:0]|
|Ch7HA MSB|22h|Ch7-HA Hysteresis[3:0]|Ch7-HA Hysteresis[3:0]|Ch7-HA Hysteresis[3:0]|Ch7-HA Hysteresis[3:0]|Ch7-HA[11:8]|Ch7-HA[11:8]|Ch7-HA[11:8]|Ch7-HA[11:8]|
|Ch7HA LSB|23h|Ch7-HA[7:0]|Ch7-HA[7:0]|Ch7-HA[7:0]|Ch7-HA[7:0]|Ch7-HA[7:0]|Ch7-HA[7:0]|Ch7-HA[7:0]|Ch7-HA[7:0]|



48 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**CHANNEL N HA/LA MSB REGISTER**


**Bits[7:4]** **Chn-HA/LA Hysteresis[3:0]**


These bits set the channel _n_ high/low alarm hysteresis.
For example, bits[7:4] of the channel 6 HA MSB register (address 1Eh, page 1) set the channel 6 high alarm
hysteresis.


0000 = No hyeteresis
0001 = ± 1LSB hystetesis
0010 to 1110 = ± 2LSB to ± 14LSB hystetesis
1111 = ± 15-LSB hystetesis


**Bits[3:0]** **Chn-HA/LA[11:8]**


These bits set the MSB nibble for the 12-bit channel _n_ high/low alarm.
For example, the channel 7 high alarm threshold is AFFh when bits[3:0] of the channel 7 HA MSB register (address
22h, page 1) are set to Ah and the channel 7 HA LSB (address 23h, page 1) register setting is FFh.


0000 = MSB nibble is 0h
0001 = MSB nibble is 1h
0010 to 1110 = MSB nibble is 2h to Eh
1111 = MSB nibble is Fh


**CHANNEL N HA/LA LSB REGISTER**


**Bits[7:0]** **Chn HA[7:0]**


These bits set the LSB byte for the 12-bit channel _n_ high/low alarm.
For example, the channel 2 low alarm threshold is F01h when the channel 2 LA LSB register (address 0Dh, page 1)
setting is 01h and bits[3:0] of the channel 2 LA MSB (address 0Ch, page 1) are set to Fh.


0000 0000 = LSB byte is 0h
0000 0001 = LSB byte is 1h
0000 0010 to 1110 1111 = LSB byte is 02h to EFh
1111 1111 = LSB byte is FFh


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 49


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**REGISTER MAP: ADS8634**


The ADS8634 internal registers are mapped in two pages: page 0 and page 1. Page 0 is selected by default at
power-up and after reset. Any register read/write action while on page 0 addresses the page 0 registers. Writing
01h to register address 7Fh selects page 1 for any further register operations.


Page 0 registers are used to select the channel sequencing mode, program the configuration registers, and to
read the alarm flags. Page 1 resisters are used to program the alarm thresholds for each channel and for the
temperature sensor. Table 13 details page 0 and Table 14 details page 1.


**Table 13. Page 0 Register Map for the ADS8634**

|REGISTER|REGISTER<br>ADDRESS<br>BITS[15:9]|DEFAULT<br>VALUE(1)|BIT7|BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0|
|---|---|---|---|---|---|---|---|---|---|---|
|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|**Channel Sequencing Control Registers**|
|Manual|04h|00h|0|Channel Select[1:0]|Channel Select[1:0]|X(2)|Range Select[2:0]|Range Select[2:0]|Range Select[2:0]|Sel Temp<br>Sensor|
|Auto|05h|00h|Reset-Seq|0|0|0|Range Select[2:0]|Range Select[2:0]|Range Select[2:0]|Sel Temp<br>Sensor|
|Holding DIN line continuously (equivalent to writing zero to all sixteen bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto/manual)|Holding DIN line continuously (equivalent to writing zero to all sixteen bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto/manual)|Holding DIN line continuously (equivalent to writing zero to all sixteen bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto/manual)|Holding DIN line continuously (equivalent to writing zero to all sixteen bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto/manual)|Holding DIN line continuously (equivalent to writing zero to all sixteen bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto/manual)|Holding DIN line continuously (equivalent to writing zero to all sixteen bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto/manual)|Holding DIN line continuously (equivalent to writing zero to all sixteen bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto/manual)|Holding DIN line continuously (equivalent to writing zero to all sixteen bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto/manual)|Holding DIN line continuously (equivalent to writing zero to all sixteen bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto/manual)|Holding DIN line continuously (equivalent to writing zero to all sixteen bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto/manual)|Holding DIN line continuously (equivalent to writing zero to all sixteen bits) during device operation as per Figure 85 continues device operation in the last selected mode (auto/manual)|
|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|**Configuration Registers**|
|Reset-Device|01h|00h|0|0|0|0|0|0|0|Reset-Dev|
|Aux-Config|06h|08h|0|0|0|0|AL_PD<br>Control|Int VREF<br>Enable|Temp<br>Sensor<br>Enable|0|
|Auto-Md Ch-Sel|0Ch|00h|Sel Ch0|X|Sel Ch1|X|Sel Ch2|X|Sel Ch3|X|
|Ch0 Range|10h|11h|0|Range Select Ch0[2:0]|Range Select Ch0[2:0]|Range Select Ch0[2:0]|0|X|X|X|
|Ch1 Range|11h|11h|0|Range Select Ch1[2:0]|Range Select Ch1[2:0]|Range Select Ch1[2:0]|0|X|X|X|
|Ch2 Range|12h|11h|0|Range Select Ch2[2:0]|Range Select Ch2[2:0]|Range Select Ch2[2:0]|0|X|X|X|
|Ch3 Range|13h|11h|0|Range Select Ch3[2:0]|Range Select Ch3[2:0]|Range Select Ch3[2:0]|0|X|X|X|
|**Alarm Flags (Read-Only)**|**Alarm Flags (Read-Only)**|**Alarm Flags (Read-Only)**|**Alarm Flags (Read-Only)**|**Alarm Flags (Read-Only)**|**Alarm Flags (Read-Only)**|**Alarm Flags (Read-Only)**|**Alarm Flags (Read-Only)**|**Alarm Flags (Read-Only)**|**Alarm Flags (Read-Only)**|**Alarm Flags (Read-Only)**|
|Temp-Flag|20h|00h|Tripped<br>Alarm Flag<br>Temperature<br>Low|Tripped<br>Alarm Flag<br>Temperature<br>High|Active Alarm<br>Flag<br>Temperature<br>Low|Active Alarm<br>Flag<br>Temperature<br>High|0|0|0|0|
|Ch0-1 Tripped-Flag|21h|00h|Tripped<br>Alarm Flag<br>Ch0 Low|Tripped<br>Alarm Flag<br>Ch0 High|X|X|Tripped<br>Alarm Flag<br>Ch1 Low|Tripped<br>Alarm Flag<br>Ch1 High|X|X|
|Ch0-1 Active-Flag|22h|00h|Active Alarm<br>Flag Ch0<br>Low|Active Alarm<br>Flag Ch0<br>High|X|X|Active Alarm<br>Flag Ch1<br>Low|Active Alarm<br>Flag Ch1<br>High|X|X|
|Ch2-3 Tripped-Flag|23h|00h|Tripped<br>Alarm Flag<br>Ch2 Low|Tripped<br>Alarm Flag<br>Ch2 High|X|X|Tripped<br>Alarm Flag<br>Ch3 Low|Tripped<br>Alarm Flag<br>Ch3 High|X|X|
|Ch2-3 Active-Flag|24h|00h|Active Alarm<br>Flag Ch2<br>Low|Active Alarm<br>Flag Ch2<br>High|X|X|Active Alarm<br>Flag Ch3<br>Low|Active Alarm<br>Flag Ch3<br>High|X|X|
|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|
|Page|7Fh|00h|0|0|0|0|0|0|0|Page Addr|



(1) All registers are reset to the default values at power-on or at device reset using the register settings method.
(2) X = don ' t care.


50 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**Table 14. Page 1 Register Map for the ADS8634**

|REGISTER|REGISTER<br>ADDRESS<br>BITS[15:9]|DEFAULT<br>VALUE(1)|BIT7|BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0|
|---|---|---|---|---|---|---|---|---|---|---|
|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|**Alarm Threshold Registers**|
|TLA MSB|00h|00h|TLA Hysteresis[3:0]|TLA Hysteresis[3:0]|TLA Hysteresis[3:0]|TLA Hysteresis[3:0]|TLA[11:8]|TLA[11:8]|TLA[11:8]|TLA[11:8]|
|TLA LSB|01h|00h|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|
|THA MSB|02h|00h|THA Hysteresis[3:0]|THA Hysteresis[3:0]|THA Hysteresis[3:0]|THA Hysteresis[3:0]|THA[11:8]|THA[11:8]|THA[11:8]|THA[11:8]|
|THA LSB|03h|00h|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|
|Ch0LA MSB|04h|00h|Ch0-LA Hysteresis[3:0]|Ch0-LA Hysteresis[3:0]|Ch0-LA Hysteresis[3:0]|Ch0-LA Hysteresis[3:0]|Ch0-LA[11:8]|Ch0-LA[11:8]|Ch0-LA[11:8]|Ch0-LA[11:8]|
|Ch0LA LSB|05h|00h|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|
|Ch0HA MSB|06h|00h|Ch0-HA Hysteresis[3:0]|Ch0-HA Hysteresis[3:0]|Ch0-HA Hysteresis[3:0]|Ch0-HA Hysteresis[3:0]|Ch0-HA[11:8]|Ch0-HA[11:8]|Ch0-HA[11:8]|Ch0-HA[11:8]|
|Ch0HA LSB|07h|00h|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|
|No function|08h to 0Bh|00h|X(2)|X|X|X|X|X|X|X|
|Ch1LA MSB|0Ch|00h|Ch1-LA Hysteresis[3:0]|Ch1-LA Hysteresis[3:0]|Ch1-LA Hysteresis[3:0]|Ch1-LA Hysteresis[3:0]|Ch1-LA[11:8]|Ch1-LA[11:8]|Ch1-LA[11:8]|Ch1-LA[11:8]|
|Ch1LA LSB|0Dh|00h|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|
|Ch1 HA MSB|0Eh|00h|Ch1-HA Hysteresis[3:0]|Ch1-HA Hysteresis[3:0]|Ch1-HA Hysteresis[3:0]|Ch1-HA Hysteresis[3:0]|Ch1-HA[11:8]|Ch1-HA[11:8]|Ch1-HA[11:8]|Ch1-HA[11:8]|
|Ch1 HA LSB|0Fh|00h|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|
|No function|10h to 13h|00h|X|X|X|X|X|X|X|X|
|Ch2 LA MSB|14h|00h|Ch2-LA Hysteresis[3:0]|Ch2-LA Hysteresis[3:0]|Ch2-LA Hysteresis[3:0]|Ch2-LA Hysteresis[3:0]|Ch2-LA[11:8]|Ch2-LA[11:8]|Ch2-LA[11:8]|Ch2-LA[11:8]|
|Ch2 LA LSB|15h|00h|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|
|Ch2 HA MSB|16h|00h|Ch2-HA Hysteresis[3:0]|Ch2-HA Hysteresis[3:0]|Ch2-HA Hysteresis[3:0]|Ch2-HA Hysteresis[3:0]|Ch2-HA[11:8]|Ch2-HA[11:8]|Ch2-HA[11:8]|Ch2-HA[11:8]|
|Ch2 HA LSB|17h|00h|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|
|No function|18h to 1Bh|00h|X|X|X|X|X|X|X|X|
|Ch3 LA MSB|1Ch|00h|Ch3-LA Hysteresis[3:0]|Ch3-LA Hysteresis[3:0]|Ch3-LA Hysteresis[3:0]|Ch3-LA Hysteresis[3:0]|Ch3-LA[11:8]|Ch3-LA[11:8]|Ch3-LA[11:8]|Ch3-LA[11:8]|
|Ch3 LA LSB|1Dh|00h|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|
|Ch3 HA MSB|1Eh|00h|Ch3-HA Hysteresis[3:0]|Ch3-HA Hysteresis[3:0]|Ch3-HA Hysteresis[3:0]|Ch3-HA Hysteresis[3:0]|Ch3-HA[11:8]|Ch3-HA[11:8]|Ch3-HA[11:8]|Ch3-HA[11:8]|
|Ch3 HA LSB|1Fh|00h|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|
|No function|20h to 23h|00h|X|X|X|X|X|X|X|X|
|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|**Page Selection Register**|
|Page|7Fh|00h|0|0|0|0|0|0|0|Page Addr|



(1) All registers are reset to the default values at power-on or at device reset using the register settings method.
(2) X = don ' t care.


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 51


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**PAGE 0 REGISTER DESCRIPTIONS (ADS8634)**


This section provides bit-by-bit descriptions of each page 0 register. As described earlier, the device registers are
mapped to two pages: page 0 and page 1. Page 0 is selected by default at power-up and after reset. Any
register read/write action while on page 0 addresses the page 0 registers. Writing 01h to register address 7Fh
selects page 1 for any further register operations.


**Channel Sequencing Control Registers for the ADS8634**


There are two modes for channel sequencing: auto and manual mode. In auto-scan mode, the device
automatically scans the preselected channels in chronological order; a new channel is selected for every
conversion. In manual mode, the channel is selected for the next conversion. In both modes, the preselected
signal range is considered for each channel independently; however, the range can be temporarily overriden.


_**Manual: Manulal Mode Register (Address = 04h; Page 0)**_


7 6 5 4 3 2 1 0

0 Channel Select[1:0] X [(1)] Range Select[2:0] Sel TempSensor


(1) X = don ' t care.


This register selects device operation in manual scan mode, selects channel for next conversion, allows the
preselected signal range for the next conversion to be temporarialy overridden, and enables the device
temperature to be read.


**Bit 7** **Must always be set to '0'**


**Bits[6:5]** **Channel Select[1:0]**


These bits select the channel for acquisition during the next frame.
For example, if this register is written in frame number _n_, then the addressed channel signal is acquired in frame
number _n + 1_ and the conversion result is available in frame number _n + 2_ .


00 = Channel 0
01 = Channel 1
10 = Channel 2
11 = Channel 3


**Bit 4** **Don't care (can be 1 or 0); this bit has no function assigned**


**Bits[3:1]** **Range Select[2:0]**


These bits select the signal range for the channel acquired in the next frame.
For example, if this register is written in frame number _n_, then the selected range is applicable for frame number _n_
_+ 1_ . This is a dynamic range selection and overrides selection through the configuration registers (addresses 10h to
13h, page 0) only for the next frame.


000 = Ranges as selected through the configuration registers (address 10h to 13h, page 0)
001 = Range is set to ± 10V
010 = Range is set to ± 5V
011 = Range is set to ± 2.5V
100 = Reserved; do not use this setting
101 = Range is set to 0V to 10V
110 = Range is set to 0V to 5V
111 = Powers down the device immediately after the 16th SCLK falling edge


**Bit 0** **Sel Temp Sensor**


This bit selects the temperature sensor for acquisition in the next frame.
This selection overrides channel selection through bits[6:4]. Range selection is not applicable for the temperature

sensor.


0 = Next conversion as per selection through bits[3:1]
1 = Device selects the temperature sensor for acquisition in the next frame


52 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


_**Auto: Auto-Scan Mode Register (Address = 05h; Page 0)**_


7 6 5 4 3 2 1 0

Reset-Seq 0 0 0 Range Select[2:0] Sel TempSensor


This register selects device operation in auto-scan mode, allows the preselected signal range for the next
conversion to be temporarily overriden, and enables the device temperature to be read.


**Bit 7** **Reset-Seq**


This bit resets the auto-mode sequence counter. The counter is reset to the lowest channel number in the selected
sequence.
For example, if the Auto-Md Ch-Sel register is programmed to _01101100_ (auto-mode sequence channels 2, 3, 5, 6,
2, 3, 5, 6 … 2, 3, 5, 6) and, if the auto register bit 7 is programmed to '1' in frame _n_ while channel 3 is sampled, then
the auto-mode sequence counter resets to channel 2 in frame _n + 1_ . This setting means channel 2 is sampled
instead of channel 5 in frame _n + 1_ .


0 = No reset (continue sequence from the present channel number)
1 = Reset channel sequncing counter


**Bits[6:4]** **Must always be set to '0'**


**Bits[3:1]** **Range Select[2:0]**


These bits select the signal range for the channel acquired in the next frame.
For example, if this register is written in frame number _n_, then the selected range is applicable for frame number _n_
_+ 1_ . This is a dynamic range selection and overrides selection through the configuration registers (address 10h to
13h, page 0) only for the next frame.


000 = Ranges as selected through the configuration registers (addresses 10h to 13h)
001 = Range is set to ± 10V
010 = Range is set to ± 5V
011 = Range is set to ± 2.5V
100 = Reserved; do not use this setting
101 = Range is set to 0V to 10V
110 = Range is set to 0V to 5V
111 = Powers down the device immediately after the 16th SCLK falling edge


**Bit 0** **Sel Temp Sensor**


This bit selects the temperature sensor for acquisition in the next frame.
This selection overrides channel selection through the auto sequence only for the next frame. The auto sequence
continues from where it was interrupted after the temperature sensing frame.
For example, if the programmed auto sequence is channels 0, 1, 3, 0, 1, 3 … 0, 1, 3 and, if the temperature sensor
is selected in frame number _n_ while channel 0 is sampled, then the temperature sensor is sampled in frame _n + 1_ .
The auto sequence resumes from frame _n + 2_ sampling channel 1. Range selection is not applicable for the
temperature sensor.


0 = Next conversion as per selection through bits[3:1]
1 = The temperature sensor is selected for acquisition in the next frame


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 53


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**Continued Operation in the Selected Mode for the ADS8634**


Holding the DIN line low continuously (equivalent to writing '0' to all 16 bits) during device operation as per
Figure 85 continues device operation in the last selected mode (auto or manual). The device follows range
selection through the configuration registers (address 10h to 13h). The internal temperature sensor continues to
be read if the temperature sensor was selected during the last auto/manual mode frame.


**Configuration Registers for the ADS8634**


These registers allow device configuration (such as signal range selection for individual channels, selection of
channels for auto sequence, enabling/disabling of internal reference and temperature sensor, and configuration
of the AL_PD pin as an alarm output or as a power-down input). All of the registers can be reset to the default
values using the configuration register.


_**Reset-Device: Device Reset Register (Address = 01h; Page 0)**_


7 6 5 4 3 2 1 0


0 0 0 0 0 0 0 Reset-Dev


This register resets the device and assigns default values to all internal registers. The reset value for this register
is 00h; as a result, this bit is self-clearing.


**Bits[7:1]** **Must always be set to '0'**


**Bit 0** **Reset-Dev**


This bit initiates a software reset immediately after the 16th SCLK falling edge.
All registers in the device are assigned the reset values mentioned in and Table 11 and Table 12.


0 = No reset
1 = Reset device


_**Aux-Config: Device Auxiliary Blocks Enable/Disable Control Register (Address = 06h; Page 0)**_


7 6 5 4 3 2 1 0


0 0 0 0 AL_PD Control Int VREF Enable Temp Sensor Enable 0


This register controls functionality of the AL_PD pin and enables/disables blocks such as the internal reference
and the internal temperature sensor.


**Bits[7:4]** **Must always be set to '0'**


**Bit 3** **AL_PD Control**


This bit controls the functionality of the AL_PD pin.


0 = The AL_PD pin functions as an alarm output pin
1 = The AL_PD pin functions as a power-down control pin


**Bit 2** **Int VREF Enable**


This bit powers up the internal VREF.


0 = Internal reference block is powered down from the next frame
1 = Internal reference block is powered up from the next frame


**Bit 1** **Temp Sensor Enable**


This bit powers up the internal temperature sensor.


0 = Internal temperature sensor block is powered down from the next frame
1 = Internal temperature sensor block is powered up from the next frame


**Bit 0** **Must always be set to '0'**


54 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


_**Auto-Md Ch-Sel: Channel Selection Registers for Auto-Scan Mode (Address = 0Ch; Page 0)**_


7 6 5 4 3 2 1 0


Sel Ch0 X [(1)] Sel Ch1 X Sel Ch2 X Sel Ch3 X


(1) X = don ' t care.


This register selects channels for the auto-mode sequence. The device scans only the selected channels in
ascending order during auto-scan mode, starting with the lowest channel selected. For example, if the Auto-Md
Ch-Sel register is programmed to _01100100_, then the auto-mode sequence is channels 2, 5, 6, 2, 5, 6 … 2, 5, 6,
and in this case, the sequence always starts from channel 2. Channel 0 is selected if this register is programmed
to _00000000_ .


**Bit 7** **Sel Ch0**


This bit selects channel 0.


0 = Channel 0 not selected
1 = Channel 0 selected


**Bit 6** **Don't care (can be 1 or 0); this bit has no function assigned**


**Bit 5** **Sel Ch1**


This bit selects channel 1.


0 = Channel 1 not selected
1 = Channel 1 selected


**Bit 4** **Don't care (can be 1 or 0); this bit has no function assigned**


**Bit 3** **Sel Ch2**


This bit selects channel 2.


0 = Channel 2 not selected
1 = Channel 2 selected


**Bit 2** **Don't care (can be 1 or 0); this bit has no function assigned**


**Bit 1** **Sel Ch3**


This bit selects channel 3.


0 = Channel 3 not selected
1 = Channel 3 selected


**Bit 0** **Don't care (can be 1 or 0); this bit has no function assigned**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 55


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


_**Ch0 Range to Ch3 Range: Range Selection Registers for Channels 0 to 3 (Address = 10h to 13h; Page 0)**_

|REGISTER|ADDRESSONPAGE0|Bit7|Bit6|Bit5|Bit4|Bit3|Bit2|Bit1|Bit0|
|---|---|---|---|---|---|---|---|---|---|
|Ch0 Range|10h|0|Range Select Ch0[2:0]|Range Select Ch0[2:0]|Range Select Ch0[2:0]|0|X(1)|X|X|
|Ch1 Range|11h|0|Range Select Ch1[2:0]|Range Select Ch1[2:0]|Range Select Ch1[2:0]|0|X|X|X|
|Ch2 Range|12h|0|Range Select Ch2[2:0]|Range Select Ch2[2:0]|Range Select Ch2[2:0]|0|X|X|X|
|Ch3 Range|13h|0|Range Select Ch3[2:0]|Range Select Ch3[2:0]|Range Select Ch3[2:0]|0|X|X|X|



(1) X = don ' t care.


A selection of signal ranges are featured for each channel. The selected range is automatically assigned for a
channel during conversion, regardless of the channel scan mode (auto or manual). These registers (Ch0 Range
to Ch3 Range) allow for selection of ranges for all channels.


**Bit 7** **Must always be set to '0'**


**Bits[6:4]** **Range Select Chn[2:0]**


These bits select the signal range for channel _n_, where n is 0, 1, 2, or 3, depending on the register address.


000 = Reserved; do not use this setting
001 = Range is set to ± 10V
010 = Range is set to ± 5V
011 = Range is set to ± 2.5V
100 = Reserved; do not use this setting
101 = Range is set to 0V to 10V
110 = Range is set to 0V to 5V
111 = Reserved; do not use this setting


**Bit 3** **Must always be set to '0'**


**Bit 2 : 0** **Don't care (can be 1 or 0); this bit has no function assigned**


56 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**Alarm Flag Registers for the ADS8634 (Read-Only)**


The alarm conditions related to individual channels are stored in these registers. When an alarm interrupt is
received, the flags can be read on the AL_PD pin. There are two types of flag for every alarm: active and tripped.
An active alarm flag is enabled when an alarm is triggered (when data cross the alarm threshold) and remains
enabled as long as the alarm condition persists. A tripped alarm flag is enabled in the same manner as an active
alarm flag, but it remains latched until it is read. This feature relieves the device from having to track alarms.


_**Temp Flag: Alarm Flags Register for the Temperature Sensor (Address = 20h; Page 0)**_


7 6 5 4 3 2 1 0


Tripped Alarm Flag Tripped Alarm Flag Active Alarm Flag Active Alarm Flag 0 0 0 0
Temperature Low Temperature High Temperature Low Temperature High


The Temp Flag register stores alarm flags for the temperature sensor. There are two alarm thresholds, with two
flags for each threshold. An active alarm flag is enabled when an alarm is triggered (when data cross the alarm
threshold) and remains enabled as long as the alarm condition persists. A tripped alarm flag is enabled in the
same manner as an active alarm flag, but it remains latched until it is read.


**Bit 7** **Tripped Alarm Flag Temperature Low**


This bit indicates the tripped low alarm flag for the temperature sensor.


0 = No alarm detected
1 = Alarm detected


**Bit 6** **Tripped Alarm Flag Temperature High**


This bit indicates the tripped high alarm flag for the temperature sensor.


0 = No alarm detected
1 = Alarm detected


**Bit 5** **Active Alarm Flag Temperature Low**


This bit indicates the active low alarm flag for the temperature sensor.


0 = No alarm
1 = Alarm detected


**Bit 4** **Active Alarm Flag Temperature High**


This bit indicates the active-high alarm flag for the temperature sensor.


0 = No alarm detected
1 = Alarm detected


**Bits[3:0]** **Always read '0'**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 57


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


_**Ch0-1 Tripped-Flag to Ch2-3 Active-Flag: Alarm Flags Register for Channels 0 to 3**_
_**(Address = 21h to 24h; Page 0)**_

|REGISTER|ADDRESSON<br>PAGE0|Bit7|Bit6|Bit5|Bit4|Bit3|Bit2|Bit1|Bit0|
|---|---|---|---|---|---|---|---|---|---|
|Ch0-1 Tripped-Flag|21h|Tripped<br>Alarm<br>Flag Ch0<br>Low|Tripped<br>Alarm<br>Flag Ch0<br>High|X(1)|X|Tripped<br>Alarm<br>Flag Ch1<br>Low|Tripped<br>Alarm<br>Flag Ch1<br>High|X|X|
|Ch0-1 Active-Flag|22h|Active<br>Alarm<br>Flag Ch0<br>Low|Active<br>Alarm<br>Flag Ch0<br>High|X|X|Active<br>Alarm<br>Flag Ch1<br>Low|Active<br>Alarm<br>Flag Ch1<br>High|X|X|
|Ch2-3 Tripped-Flag|23h|Tripped<br>Alarm<br>Flag Ch2<br>Low|Tripped<br>Alarm<br>Flag Ch2<br>High|X|X|Tripped<br>Alarm<br>Flag Ch3<br>Low|Tripped<br>Alarm<br>Flag Ch3<br>High|X|X|
|Ch2-3 Active-Flag|24h|Active<br>Alarm<br>Flag Ch2<br>Low|Active<br>Alarm<br>Flag Ch2<br>High|X|X|Active<br>Alarm<br>Flag Ch3<br>Low|Active<br>Alarm<br>Flag Ch3<br>High|X|X|



(1) X = don ' t care.


There are two alarm thresholds (High and Low) per channel and for each threshold there are two flags. An active
alarm flag is enabled when an alarm is triggered (when data cross the alarm threshold) and remains enabled as
long as the alarm condition persists. A tripped alarm flag is enabled in the same manner as an active alarm flag,
but it remains latched until it is read. Registers addressed 21h to 24h on page 0 store active and tripped alarm
flags for all four channels.


**Bits[7:6]** **Active/Tripped Alarm Flag Chn High/Low**


Each individual bit indicates an active/tripped, high/low alarm flag for each channel, as per the Ch0-1 Tripped-Flag
to Ch2-3 Active-Flag register.


0 = No alarm detected
1 = Alarm detected


**Bits[5:4]** **Don't care (1 or 0), these bits do not have any function assigned**


**Bits[3:2]** **Active/Tripped Alarm Flag Chn High/Low**


Each individual bit indicates an active/tripped, high/low alarm flag for each channel, as per the Ch0-1 Tripped-Flag
to Ch2-3 Active-Flag register.


0 = No alarm detected
1 = Alarm detected


**Bits[1:0]** **Don't care (1 or 0), these bits do not have any function assigned**


**Page Selection Register for the ADS8634**


The registers are arranged on two pages: page 0 and page 1. The page register selects the register page.


_**Page: Page Selection Register (Address = 7Fh; Page 0)**_


7 6 5 4 3 2 1 0


0 0 0 0 0 0 0 Page Addr


**Bits[7:1]** **Must always be set to '0'**


**Bit 0** **Page Addr**


This bit selects the page address.


0 = Selects page 0 for the next register read or write command; all register read/write operations after this are
performed on the page 0 registers until page 1 is selected
1 = Selects page 1 for the next register read or write command; all register read/write operations after this are
performed on the page 1 registers until page 0 is selected


58 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**PAGE 1 REGISTER DESCRIPTIONS (ADS8634)**


This section provides bit-by-bit descriptions of each page 1 register. As described earlier, the device registers are
mapped to two pages: page 0 and page 1. Page 0 is selected by default at power-up and after reset. Page 1 can
be selected by writing 01h to register address 7Fh. After selecting page 1, any register read/write action
addresses page 1 registers after a page 1 selection. Writing 00h to register address 7Fh selects page 0 for any
further register operations.


**Alarm Threshold Setting Registers for the ADS8634**


The device features high and low alarms individually for the temperature sensor and each of the four channels.
Each alarm threshold is 12-bits wide with 4-bit hysteresis. This 16-bit setting is accomplished with two 8-bit
registers associated with every high/low alarm.


_**TLA MSB to THA LSB: Temperature Alarm Registers (Address = 00h to 03h; Page 1)**_

|REGISTER|ADDRESSON<br>PAGE1|Bit7|Bit6|Bit5|Bit4|Bit3|Bit2|Bit1|Bit0|
|---|---|---|---|---|---|---|---|---|---|
|TLA MSB||TLA Hysteresis[3:0]|TLA Hysteresis[3:0]|TLA Hysteresis[3:0]|TLA Hysteresis[3:0]|TLA[11:8]|TLA[11:8]|TLA[11:8]|TLA[11:8]|
|TLA LSB||TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|TLA[7:0]|
|THA MSB||THA Hysteresis[3:0]|THA Hysteresis[3:0]|THA Hysteresis[3:0]|THA Hysteresis[3:0]|THA[11:8]|THA[11:8]|THA[11:8]|THA[11:8]|
|THA LSB||THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|THA[7:0]|



**THA/LA MSB Register**


**Bits[7:4]** **THA/LA Hysteresis[3:0]**


These bits set the temperature high/low alarm hysteresis.


0000 = No hyeteresis
0001 = ± 1LSB hystetesis
0010 to 1110 = ± 2LSB to ± 14LSB hystetesis
1111 = ± 15LSB hystetesis


**Bits[3:0]** **THA/LA[11:8]**


These bits set the MSB nibble for the 12-bit temperature high/low alarm.
For example, the temperature high alarm threshold is AFFh when the THA MSB register (address 02h, page 1)
setting is Ah and the THA LSB register (address 03h, page 1) register setting is FFh.


0000 = MSB nibble is 0h
0001 = MSB nibble is 1h
0010 to 1110 = MSB nibble is 2h to Eh
1111 = MSB nibble is Fh


**THA/LA LSB Register**


**Bits[7:0]** **THA/LA[7:0]**


These bits set the LSB byte for the 12-bit temperature high alarm.
For example, the temperature low alarm threshold is F02h when the TLA LSB register (address 01h) setting is 02h
and the TLS MSB register (address 00h, page 1) register setting is Fh.


0000 0000 = LSB byte is 0h
0000 0001 = LSB byte is 1h
0000 0010 to 1110 1111 = LSB byte is 02h to EFh
1111 1111 = LSB byte is FFh


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 59


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


_**Ch0LA MSB to Ch3HA LSB: Channels 0 to 3 Alarm Registers (Address = 04h to 23h; Page 1)**_

|REGISTER|ADDRESSON<br>PAGE1|Bit7|Bit6|Bit5|Bit4|Bit3|Bit2|Bit1|Bit0|
|---|---|---|---|---|---|---|---|---|---|
|Ch0LA MSB|04h|Ch0-LA Hysteresis[3:0]|Ch0-LA Hysteresis[3:0]|Ch0-LA Hysteresis[3:0]|Ch0-LA Hysteresis[3:0]|Ch0-LA[11:8]|Ch0-LA[11:8]|Ch0-LA[11:8]|Ch0-LA[11:8]|
|Ch0LA LSB|05h|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|Ch0-LA[7:0]|
|Ch0HA MSB|06h|Ch0-HA Hysteresis[3:0]|Ch0-HA Hysteresis[3:0]|Ch0-HA Hysteresis[3:0]|Ch0-HA Hysteresis[3:0]|Ch0-HA[11:8]|Ch0-HA[11:8]|Ch0-HA[11:8]|Ch0-HA[11:8]|
|Ch0HA LSB|07h|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|Ch0-HA[7:0]|
|No function|08h to 0Bh|X(1)|X|X|X|X|X|X|X|
|Ch1LA MSB|0Ch|Ch1-LA Hysteresis[3:0]|Ch1-LA Hysteresis[3:0]|Ch1-LA Hysteresis[3:0]|Ch1-LA Hysteresis[3:0]|Ch1-LA[11:8]|Ch1-LA[11:8]|Ch1-LA[11:8]|Ch1-LA[11:8]|
|Ch1LA LSB|0Dh|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|Ch1-LA[7:0]|
|Ch1HA MSB|0Eh|Ch1-HA Hysteresis[3:0]|Ch1-HA Hysteresis[3:0]|Ch1-HA Hysteresis[3:0]|Ch1-HA Hysteresis[3:0]|Ch1-HA[11:8]|Ch1-HA[11:8]|Ch1-HA[11:8]|Ch1-HA[11:8]|
|Ch1HA LSB|0Fh|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|Ch1-HA[7:0]|
|No function|10h to 13h|X|X|X|X|X|X|X|X|
|Ch2LA MSB|14h|Ch2-LA Hysteresis[3:0]|Ch2-LA Hysteresis[3:0]|Ch2-LA Hysteresis[3:0]|Ch2-LA Hysteresis[3:0]|Ch2-LA[11:8]|Ch2-LA[11:8]|Ch2-LA[11:8]|Ch2-LA[11:8]|
|Ch2LA LSB|15h|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|Ch2-LA[7:0]|
|Ch2HA MSB|16h|Ch2-HA Hysteresis[3:0]|Ch2-HA Hysteresis[3:0]|Ch2-HA Hysteresis[3:0]|Ch2-HA Hysteresis[3:0]|Ch2-HA[11:8]|Ch2-HA[11:8]|Ch2-HA[11:8]|Ch2-HA[11:8]|
|Ch2HA LSB|17h|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|Ch2-HA[7:0]|
|No function|18h to 1Bh|X|X|X|X|X|X|X|X|
|Ch3LA MSB|1Ch|Ch3-LA Hysteresis[3:0]|Ch3-LA Hysteresis[3:0]|Ch3-LA Hysteresis[3:0]|Ch3-LA Hysteresis[3:0]|Ch3-LA[11:8]|Ch3-LA[11:8]|Ch3-LA[11:8]|Ch3-LA[11:8]|
|Ch3LA LSB|1Dh|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|Ch3-LA[7:0]|
|Ch3HA MSB|1Eh|Ch3-HA Hysteresis[3:0]|Ch3-HA Hysteresis[3:0]|Ch3-HA Hysteresis[3:0]|Ch3-HA Hysteresis[3:0]|Ch3-HA[11:8]|Ch3-HA[11:8]|Ch3-HA[11:8]|Ch3-HA[11:8]|
|Ch3HA LSB|1Fh|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|Ch3-HA[7:0]|
|No function|20h to 23h|X|X|X|X|X|X|X|X|



(1) X = don ' t care.


**Channel N HA/LA MSB Register**


**Bits[7:4]** **Chn-HA/LA Hysteresis[3:0]**


These bits set the channel _n_ high/low alarm hysteresis.
For example, bits[7:4] of the channel 2 HA MSB register (address 16h, page 1) set the channel 2 high alarm
hysteresis.


0000 = No hyeteresis
0001 = ± 1LSB hystetesis
0010 to 1110 = ± 2LSB to ± 14LSB hystetesis
1111 = ± 15LSB hystetesis


**Bits[3:0]** **Chn-HA/LA[11:8]**


These bits set the MSB nibble for the 12-bit channel _n_ high/low alarm.
For example, the channel 3 high alarm threshold is AFFh when bits[3:0] of the channel 3 HA MSB register (address
1Eh, page 1) are set to Ah and the channel 3 HA LSB (address 1Fh, page 1) register setting is FFh.


0000 = MSB nibble is 0h
0001 = MSB nibble is 1h
0010 to 1110 = MSB nibble is 2h to Eh
1111 = MSB nibble is Fh


**Channel N HA/LA LSB Register**


**Bits[7:0]** **Chn HA[7:0]**


These bits set the LSB byte for the 12-bit channel _n_ high/low alarm.
For example, the channel 1 low alarm threshold is F01h when the channel 1 LA LSB register (address 0Dh, page 1)
setting is 01h and bits[3:0] of the channel 1 LA MSB (address 0Ch, page 1) are set to Fh.


0000 0000 = LSB byte is 0h
0000 0001 = LSB byte is 1h
0000 0010 to 1110 1111 = LSB byte is 02h to EFh
1111 1111 = LSB byte is FFh


60 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**APPLICATION INFORMATION**


**DRIVING ANALOG SIGNAL INPUT**


The ADS8634/8 employ a sample-and-hold stage at the input. An 8pF sampling capacitor is connected during
sampling. This configuration results in a glitch at the input terminals of the device at the start of the sample. The
external circuit must be designed in such a way that the input can settle to the required accuracy during the
chosen sampling time. Figure 91 shows a reccomended driving circuit for the analog inputs.


VOPA+











Analog
Signal















VOPA


**Figure 91. Reccomended Driving Circuit**


The 8pF capacitor across the AINx and AINGND terminals decouples the driving op amp from the sampling
glitch. The low-pass filter at the input limits noise bandwidth of the driving op amp. Select the filter bandwidth so
that the full-scale step at the input can settle to the required accuracy during the sampling time. Equation 5,
Equation 6, and Equation 7 are useful for filter component selection.

Sampling�Time

Filter�Time�Constant�(tAU)�=
Settling�Resolution � ln(2)


Where:


Settling resolution is the accuracy in LSB to which the input must settle. A typical settling resolution for
the 12-bit device is 13 or 14. (5)



Filter�Time�Constant�(tAU)�=�R � C


1

Filter�Bandwidth�=
2 ��� tAU



(6)


(7)



Also, make sure the driving op amp bandwidth does not limit the signal bandwidth to below the filter bandwidth.
In many applications, signal bandwidth may be much lower than filter bandwidth. In this case, an additional
low-pass filter may be used at the input of the driving op amp. This signal and filter bandwidth can be selected in
accordance with the input signal bandwidth.


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 61


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**POWER MANAGEMENT AT LOWER SPEEDS**


There are multiple data acquisition applications that require sampling speeds much lower than 1MSPS. The
ADS8634/8 offer power saving while running at lower speeds. As shown in Figure 92, the ADS8634/8 consume
dynamic power from a CS rising edge until the 16th SCLK falling edge. While using the ADS8634/8 at lower
sampling speeds, it is recommended to use SCLK at the maximum specified frequency. This setting allows the
maximum static period tSTATIC at any given sampling speed. The ADS8634/8 consume considerably lower static
current (current during tSTATIC) from all three power supplies (AVDD, HVDD, and HVSS). This consumption helps
lower the average currents from each of the supplies, resulting in a lower average power consumption while
using the device at lower sampling speeds.





CS


SCLK


AVDD, HVDD,
HVSS Current



IDYNAMIC



ISTATIC



**Figure 92. Supply Current Profile at Speeds Below 1MSPS**


Table 15 shows tFRAME, tDYNAMIC, and tSTATIC at a 0.1MSPS sampling speed.


**Table 15. Typical Static/Dynamic Time Distribution at Lower Speeds (0.1MSPS)**

|fSAMPLE (MSPS)|tFRAME (µs)|tDYNAMIC (µs)|tSTATIC (µs)|
|---|---|---|---|
|0.1|10|1|9|



The average device power consumption can be calculated with Equation 8 and Equation 9:
Average Current, IAVERAGE = (IDYNAMIC × tDYNAMIC + ISTATIC × tSTATIC)/(tDYNAMIC + tSTATIC) (8)

Average Power = Supply Voltage × IAVERAGE (9)


Table 16 shows the average power calculations at 0.1MSPS.


**Table 16. Average Power Calculations at 0.1MSPS**

|PARAMETER|AVDD|HVDD|HVSS|
|---|---|---|---|
|Typical supply voltage (V)|3.3|10|10|
|IDYNAMIC (mA)|2.50|0.27|0.35|
|tDYNAMIC (µs)|1.0|1.0|1.0|
|ISTATIC (mA)|1.45|0.005|0.005|
|tSTATIC (µs)|9.0|9.0|9.0|
|Average current, IAVERAGE (mA)|1.555|0.032|0.040|
|Average power(mW)|5.132|0.315|0.395|
|Total average power(mW) = PAVDD + PHVDD + PHVSS|5.842|5.842|5.842|



62 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


**PROGRAMMING SEQUENCE**


A typical programming sequence for the ADS8634/8 is shown in Figure 93.


|inD 1e 0v ai Vnc e aP o uMw re adr nes U ehp<br>Starts M u pl o c .annel 0,<br>± in t g|Col2|
|---|---|
|||







































Continue


**Figure 93. Programming Flowchart**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 63


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**DRIVING ANALOG SIGNAL INPUT WITHOUT AN OPERATIONAL AMPLIFIER**


There are some low input signal bandwidth applications, such as general-purpose programmable logic controllers
(PLCs) I/O, where it is not required to operate an ADC at high sampling rates and it is desirable to avoid using a
dedicated driving op amp from a cost perspective. In this case, the ADC input recognizes the impedance of the
signal source (such as signal conditioning circuit, PGA, or sensor). This section elaborates on the effects of
source impedance on sampling frequency.


Equation 5 can be rewritten as Equation 10:
Sampling Time = Filter Time Constant × Settling Resolution × ln(2) (10)


As shown in Figure 94, it is recommended to use a bypass capacitor across the positive and negative ADC input
terminals.


AVDD













GND


**Figure 94. Driving Without an Operational Amplifier**


64 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


The source impedance (RSOURCE + R1) combined with (CBYPASS + CSAMPLE) acts as a low-pass filter with
Equation 11:
Filter Time Constant = (RSOURCE + R1) × (CBYPASS + CSAMPLE)


Where:


CSAMPLE is the internal sampling capacitance of the ADC (equal to 32pF). (11)


Table 17 lists the recommended bypass capacitor values and the filter-time constant for different source
resistances. It is recommended to use a bypass capacitor with a minimum value of 100pF. Table 17 assumes R1
= 20 Ω ; however, depending on the application, R1 can be bypassed (by shorting R1) and the extra 20 Ω margin
can be used for source resistance.


**Table 17. Filter-Time Constant versus Source Resistance**

|RSOURCE (Ω)|RSOURCE + R 1|APPROXIMATE C<br>BYPASS<br>(pF)|C BYPASS + C SAMPLE (pF)|FILTERTIME<br>CONSTANT(ns)|
|---|---|---|---|---|
|0|20|1200|1208|25|
|32|52|470|478|25|
|90|110|220|228|25|
|210|230|100|108|25|
|500|520|100|108|56|
|1000|1020|100|108|110|
|5000|5020|100|108|542|



Typically, the settling resolution is selected as (ADC resolution + 2). For the ADS8634/8 (12-bit), the ideal settling
resolution is 14. Using Equation 6 and Equation 7, the sampling time can be easily determined for a given source
impedance. For source impedances greater than 210 Ω, the filter-time constant continues to increase beyond the
25ns required for a 250ns sampling time. This incrementation increases the minimum permissible sampling time
for 12-bit settling and the device must be operated at a lower sampling rate.


The device sampling rate can be maximized by using a 20MHz clock for even lower throughputs. Table 18
shows typical calculations for the ADS8634/8 (12-bit).


**Table 18. Sampling Frequency versus Source Impedance for the ADS8634/8**

|RSOURCE (Ω)|C BYPASS (pF)|SAMPLINGTIME<br>,<br>tACQ (ns)|CONVERSIONTIME<br>,<br>tCONV (ns)|CYCLETIME<br>,<br>tACQ + tCONV (ns)|SAMPLINGRATE<br>(MSPS)|
|---|---|---|---|---|---|
|210|100|250|750<br>(with 20MHz clock)|1000|1|
|500|100|545|750<br>(with 20MHz clock)|1295|0.8|
|1000|100|1070|750<br>(with 20MHz clock)|1820|0.5|
|5000|100|5260|750<br>(with 20MHz clock)|6010|0.2|



Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 65


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


**PCB LAYOUT SCHEMATIC RECCOMENDATIONS**


ADCs are mixed-signal devices. For maximum performance, proper decoupling, grounding, and proper
termination of digital signals is essential. Figure 95 and Figure 96 show the essential components around the
ADC. All capacitors shown are ceramic. These decoupling capacitors must be placed close to the respective
signal pins.





















Analog
Supply


Reference


Digital
To/From

Host


Digital
Supply

















Bipolar Power Supply


**Figure 95. Reccomended Schematic for the ADS8638**


66 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


**[www.ti.com](http://www.ti.com)** SBAS541A – MAY 2011 – REVISED AUGUST 2011


There is a 50 Ω source series termination resistor shown on the DOUT signal. This resistor must be placed as
close to DOUT as possible. Series terminations for SCLK and CS must be placed close to the host.



















Analog
Supply


Reference


Digital
To/From

Host


Digital
Supply

















Bipolar Power Supply


**Figure 96. Reccomended Schematic for the ADS8634**


Copyright © 2011, Texas Instruments Incorporated _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ 67


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


**[ADS8634](http://focus.ti.com/docs/prod/folders/print/ads8634.html)**
**[ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8638.html)**


SBAS541A – MAY 2011 – REVISED AUGUST 2011 **[www.ti.com](http://www.ti.com)**


A common ground plane for both analog and digital often gives better results. Typically, the second printed circuit
board (PCB) layer is the ground plane. The ADC ground pins are returned to the ground plane through multiple
vias (PTH). It is a good practice to place analog components on one side and digital components on other side of
the ADC (or ADCs). All signals must be routed, assuming there is a split ground plane for analog and digital.
Furthermore, it is better to split the ground initially during layout. Route all analog and digital traces so that the
traces see the respective ground all along the second layer. Then, short both grounds to form a common ground
plane. Figure 97 Figure 98 show the reccomended layout around the ADS8638. The ADS8634 pinout is a subset
of the ADS8638 pinout. It is possible to make a common layout for the ADS8634/8 . Or, one can delete the
traces and components associated with the additional four channels of the ADS8638 to generate the ADS8634
layout.


**Figure 97. Reccomended Layout for the ADS8638** **Figure 98. Reccomended Layout for the ADS8638**
**(Top layer)** **(Bottom layer)**


68 _[Submit Documentation Feedback](http://www.go-dsp.com/forms/techdoc/doc_feedback.htm?litnum=SBAS541A&partnum=ADS8634)_ Copyright © 2011, Texas Instruments Incorporated


Product Folder Link(s): _[ADS8634 ADS8638](http://focus.ti.com/docs/prod/folders/print/ads8634.html)_


## **PACKAGE OPTION ADDENDUM**

www.ti.com 31-Oct-2025


**PACKAGING INFORMATION**





















**(1) Status:** [For more details on status, see our product life cycle.](https://www.ti.com/support-quality/quality-policies-procedures/product-life-cycle.html)


**(2) Material type:** When designated, preproduction parts are prototypes/experimental devices, and are not yet approved or released for full production. Testing and final process, including without limitation quality assurance,
reliability performance testing, and/or process qualification, may not yet be complete, and this item is subject to further changes or possible discontinuation. If available for ordering, purchases will be subject to an additional
waiver at checkout, and are intended for early internal evaluation purposes only. These items are sold without warranties of any kind.


**(3) RoHS values:** [Yes, No, RoHS Exempt. See the TI RoHS Statement for additional information and value definition.](https://www.ti.com/lit/szzq088)


**(4) Lead finish/Ball material:** Parts may have multiple material finish options. Finish options are separated by a vertical ruled line. Lead finish/Ball material values may wrap to two lines if the finish value exceeds the maximum
column width.


**(5) MSL rating/Peak reflow:** The moisture sensitivity level ratings and peak solder (reflow) temperatures. In the event that a part has multiple moisture sensitivity ratings, only the lowest level per JEDEC standards is shown.
Refer to the shipping label for the actual reflow temperature that will be used to mount the part to the printed circuit board.


**(6) Part marking:** There may be an additional marking, which relates to the logo, the lot trace code information, or the environmental category of the part.

Multiple part markings will be inside parentheses. Only one part marking contained in parentheses and separated by a "~" will appear on a part. If a line is indented then it is a continuation of the previous line and the two
combined represent the entire part marking for that device.


Addendum-Page 1


## **PACKAGE OPTION ADDENDUM**

www.ti.com 31-Oct-2025


**Important Information and Disclaimer:** The information provided on this page represents TI's knowledge and belief as of the date that it is provided. TI bases its knowledge and belief on information provided by third parties, and
makes no representation or warranty as to the accuracy of such information. Efforts are underway to better integrate information from third parties. TI has taken and continues to take reasonable steps to provide representative
and accurate information but may not have conducted destructive testing or chemical analysis on incoming materials and chemicals. TI and TI suppliers consider certain information to be proprietary, and thus CAS numbers
and other limited information may not be available for release.

In no event shall TI's liability arising out of such information exceed the total purchase price of the TI part(s) at issue in this document sold by TI to Customer on an annual basis.


Addendum-Page 2


## **PACKAGE MATERIALS INFORMATION**

www.ti.com 18-Jun-2025


**TAPE AND REEL INFORMATION**



**REEL DIMENSIONS**


*All dimensions are nominal







**TAPE DIMENSIONS**


|K0|Col2|P1|Col4|Col5|Col6|Col7|
|---|---|---|---|---|---|---|
|||||||B0W|
||||||||
||||||||
|vity|vity|vity|A0|A0|||






|A0|Dimension designed to accommodate the component width A0 Cavity|
|---|---|
|A0|Dimension designed to accommodate the component width|
|B0|Dimension designed to accommodate the component length|
|K0|Dimension designed to accommodate the component thickness|
|W|Overall width of the carrier tape|
|P1|Pitch between successive cavity centers|



Reel Width (W1)


**QUADRANT ASSIGNMENTS FOR PIN 1 ORIENTATION IN TAPE**


Sprocket Holes

|Q1|Q2|
|---|---|
|Q3|Q4|


|Q1|Q2|
|---|---|
|Q3|Q4|



Pocket Quadrants























|Device|Package<br>Type|Package<br>Drawing|Pins|SPQ|Reel<br>Diameter<br>(mm)|Reel<br>Width<br>W1(mm)|A0<br>(mm)|B0<br>(mm)|K0<br>(mm)|P1<br>(mm)|W<br>(mm)|Pin1<br>Quadrant|
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|ADS8634SRGER|VQFN|RGE|24|3000|330.0|12.4|4.25|4.25|1.15|8.0|12.0|Q2|
|ADS8634SRGERG4|VQFN|RGE|24|3000|330.0|12.4|4.25|4.25|1.15|8.0|12.0|Q2|
|ADS8634SRGET|VQFN|RGE|24|250|180.0|12.4|4.25|4.25|1.15|8.0|12.0|Q2|
|ADS8638SRGER|VQFN|RGE|24|3000|330.0|12.4|4.25|4.25|1.15|8.0|12.0|Q2|
|ADS8638SRGET|VQFN|RGE|24|250|180.0|12.4|4.25|4.25|1.15|8.0|12.0|Q2|
|ADS8638SRGETG4|VQFN|RGE|24|250|180.0|12.4|4.25|4.25|1.15|8.0|12.0|Q2|


Pack Materials-Page 1


## **PACKAGE MATERIALS INFORMATION**

www.ti.com 18-Jun-2025





*All dimensions are nominal

|Device|PackageType|PackageDrawing|Pins|SPQ|Length(mm)|Width(mm)|Height(mm)|
|---|---|---|---|---|---|---|---|
|ADS8634SRGER|VQFN|RGE|24|3000|346.0|346.0|33.0|
|ADS8634SRGERG4|VQFN|RGE|24|3000|346.0|346.0|33.0|
|ADS8634SRGET|VQFN|RGE|24|250|210.0|185.0|35.0|
|ADS8638SRGER|VQFN|RGE|24|3000|346.0|346.0|33.0|
|ADS8638SRGET|VQFN|RGE|24|250|210.0|185.0|35.0|
|ADS8638SRGETG4|VQFN|RGE|24|250|210.0|185.0|35.0|



Pack Materials-Page 2


## **GENERIC PACKAGE VIEW**

# **RGE 24 VQFN - 1 mm max height**

PLASTIC QUAD FLATPACK - NO LEAD


Images above are just a representation of the package family, actual package may vary.
Refer to the product data sheet for package details.


4204104/H


# **PACKAGE OUTLINE** **RGE0024H VQFN - 1 mm max height**

PLASTIC QUAD FLATPACK- NO LEAD






















|2X 7|2X 7|2.5 12|
|---|---|---|
||||
|||25|
||||






|Col1|01<br>.|C|Col4|A|B|
|---|---|---|---|---|---|
||0.05|0.05|C|C|C|





NOTES:


1. All linear dimensions are in millimeters. Any dimensions in parenthesis are for reference only. Dimensioning and tolerancing
per ASME Y14.5M.
2. This drawing is subject to change without notice.
3. The package thermal pad must be soldered to the printed circuit board for thermal and mechanical performance.


**www.ti.com**


# **EXAMPLE BOARD LAYOUT** **RGE0024H VQFN - 1 mm max height**

PLASTIC QUAD FLATPACK- NO LEAD





























NOTES: (continued)


4. This package is designed to be soldered to a thermal pad on the board. For more information, see Texas Instruments
literature number SLUA271 (www.ti.com/lit/slua271).
5. Solder mask tolerances between and around signal pads can vary based on board fabrication site.


**www.ti.com**


# **EXAMPLE STENCIL DESIGN** **RGE0024H VQFN - 1 mm max height**

PLASTIC QUAD FLATPACK- NO LEAD























NOTES: (continued)


6. Laser cutting apertures with trapezoidal walls and rounded corners may offer better paste release. IPC-7525 may have alternate

design recommendations..


**www.ti.com**


**IMPORTANT NOTICE AND DISCLAIMER**


TI PROVIDES TECHNICAL AND RELIABILITY DATA (INCLUDING DATASHEETS), DESIGN RESOURCES (INCLUDING REFERENCE
DESIGNS), APPLICATION OR OTHER DESIGN ADVICE, WEB TOOLS, SAFETY INFORMATION, AND OTHER RESOURCES “AS IS”
AND WITH ALL FAULTS, AND DISCLAIMS ALL WARRANTIES, EXPRESS AND IMPLIED, INCLUDING WITHOUT LIMITATION ANY
IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT OF THIRD
PARTY INTELLECTUAL PROPERTY RIGHTS.


These resources are intended for skilled developers designing with TI products. You are solely responsible for (1) selecting the appropriate
TI products for your application, (2) designing, validating and testing your application, and (3) ensuring your application meets applicable
standards, and any other safety, security, regulatory or other requirements.


These resources are subject to change without notice. TI grants you permission to use these resources only for development of an
application that uses the TI products described in the resource. Other reproduction and display of these resources is prohibited. No license
is granted to any other TI intellectual property right or to any third party intellectual property right. TI disclaims responsibility for, and you fully
indemnify TI and its representatives against any claims, damages, costs, losses, and liabilities arising out of your use of these resources.


[TI’s products are provided subject to TI’s Terms of Sale, TI’s General Quality Guidelines, or other applicable terms available either on](https://www.ti.com/legal/terms-conditions/terms-of-sale.html)
[ti.com or provided in conjunction with such TI products. TI’s provision of these resources does not expand or otherwise alter TI’s applicable](https://www.ti.com)
warranties or warranty disclaimers for TI products. Unless TI explicitly designates a product as custom or customer-specified, TI products
are standard, catalog, general purpose devices.


TI objects to and rejects any additional or different terms you may propose.


IMPORTANT NOTICE


Copyright © 2025, Texas Instruments Incorporated


Last updated 10/2025


