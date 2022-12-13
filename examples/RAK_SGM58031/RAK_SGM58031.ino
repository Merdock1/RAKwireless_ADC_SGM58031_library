/**
   @file RAK_SGM58031.ino
   @author rakwireless.com
   @brief This code can get the voltage data
   @version 1.0
   @date 2022-09-21
   @copyright Copyright (c) 2022
*/

#include "ADC_SGM58031.h" //http://librarymanager/All#RAKwireless_ADC_SGM58031_library

//RAK_ADC_SGM58031 sgm58031;
RAK_ADC_SGM58031 sgm58031(SGM58031_SDA_ADDRESS);
// RAK_ADC_SGM58031 sgm58031(Wire);
// RAK_ADC_SGM58031 sgm58031(Wire,SGM58031_DEFAULT_ADDRESS);

bool  interrupt_flag = false;
void setup()
{
  // put your setup code here, to run once:
  pinMode(WB_IO2, OUTPUT);
  digitalWrite(WB_IO2, HIGH);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  delay(300);
  time_t timeout = millis();
  Serial.begin(115200);
  while (!Serial)
  {
    if ((millis() - timeout) < 5000)
    {
      delay(100);
    }
    else
    {
      break;
    }
  }
  sgm58031.begin();
  Serial.println("RAK12059 TEST");
  if (sgm58031.getChipID() != DEVICE_ID)
  {
    Serial.println("No CHIP found ... please check your connection");
    while (1)
    {
      delay(100);
    }
  }
  else
  {
    Serial.println("Found SGM58031 Chip");
  }
  sgm58031.setAlertLowThreshold(0x0000);  // Write  0x0000  to Lo_Thresh
  sgm58031.setAlertHighThreshold(0x7FFF); // Write 0x7FFF to Hi_Thresh
  sgm58031.setConfig(0xC2E0);             // Write config, OS=1, AIN0 to GND, G=(+/-4.096V input range)
  sgm58031.setVoltageResolution(SGM58031_FS_4_096);
  delay(1000);
}


void loop()
{
  float gVoltage = sgm58031.getVoltage();
  Serial.print(F("gVoltage="));
  Serial.print(gVoltage);
  Serial.println("V");
  delay(1000);
}