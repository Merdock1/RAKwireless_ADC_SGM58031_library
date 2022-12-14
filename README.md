| <center><img src="./assets/rakstar.jpg" alt="RAKstar" width=25%></center> | ![RAKWireless](./assets/RAK-Whirls.png) | [![Build Status](https://github.com/RAKWireless/RAKwireless_ADC_SGM58031_library/workflows/RAK%20Library%20Build%20CI/badge.svg)](https://github.com/RAKWireless/RAKwireless_ADC_SGM58031_library/actions) |
| ------------------------------------------------------------ | --------------------------------------- | ------------------------------------------------------------ |

# RAKwireless_ADC_SGM58031_library

Simple Arduino Library for the WisBlock I2C ADC Sensor version from [RAKwireless].

[RAKwireless RAK12023/RAK12035 Soil Moisture Sensor](https://store.rakwireless.com/products/soil-moisture-sensor-rak12023)

# Documentation

* **[Product Repository](https://github.com/RAKWireless/RAKwireless_ADC_SGM58031_library)** - Product repository for the RAKwireless_ADC_SGM58031_library.
* **[Documentation](https://docs.rakwireless.com/Product-Categories/WisBlock/RAKwireless_ADC_SGM58031_library/Overview/)** - Documentation and Quick Start Guide for the RAKwireless_ADC_SGM58031_library.

# Installation

In Arduino IDE open Sketch->Include Library->Manage Libraries then search for RAKwireless_ADC_SGM58031_library.    

In PlatformIO open PlatformIO Home, switch to libraries and search for RAKwireless_ADC_SGM58031_library. 
Or install the library project depend by adding 

```log
lib_deps =
  rakwireless/RAKwireless_ADC_SGM58031_library
```
into **`platformio.ini`**

For manual installation download the archive, unzip it and place the RAKwireless_ADC_SGM58031_library folder into the library directory.    
In Arduino IDE this is usually <arduinosketchfolder>/libraries/    
In PlatformIO this is usually <user/.platformio/lib>     


# Usage

The library provides an interface class, which allows communication to the RAKwireless_ADC_SGM58031_library over I2C. 
- [RAK_SGM58031](./examples/RAK_SGM58031) simply reads the voltage values and prints them over USB Serial

## This class provides the following methods:

**`RAK_ADC_SGM58031()`**    
Create the interface object using hardware IIC  
Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
|  return |  | none  |

**` uint16_t getChipID()`**    
Gets the chip ID.          
Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
| return    |   | the chip Id |

**`void setAlertLowThreshold(uint16_t threshold)`**    
Sets the lower limit threshold used to determine the alert condition         
Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
| in          | threshold | the lower limit threshold |

**`uint16_t readAlertLowThreshold()`**      
Read the lower limit threshold value  
Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
| return      |      |the lower limit threshold value|

**`void setAlertHighThreshold(uint16_t threshold)`**    
Sets the upper limit threshold used to determine the alert condition
Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
| in          | threshold | the upper limit threshold |

**`uint16_t readAlertHighThreshold()`**    
 Read the upper limit threshold value
Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
| return      |      |the upper limit threshold value|

**`void setConfig(uint16_t data)`**    

set the 16-bit register can be used to control the SGM58031 operating mode, input selection, data rate, PGA settings and comparator modes

Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
| in          | data | the config data |
| return      | none |none|

**` uint16_t getConfig()`**    
Gets the value of config Register
Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
| return      |      |the value of config Register|

**`void set_GN_Trim1(uint16_t data)`**    
ADC gain coefficient for user selecting Config1 register EXT_REF bit as reference    
Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
| in    | data |the GN_Trim1 data|

**`uint16_t get_GN_Trim1()`**    
Gets the value of GN_Trim1 Register  
Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
| return      |  |the value of GN_Trim1 Register|

**` void setVoltageResolution(float value)`**    
 Set the resolution voltage 
Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
| in    | value |the resolution voltage value|

**`float getVoltageResolution()`**    
get the resolution voltage 
Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
| return      |  |the resolution voltage|

**`float getVoltage()`**    
Read the voltage of sensor output  
Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
| return      |  |Voltage value after conversion|

## Version History

### v1.0.0
- Initial Release

