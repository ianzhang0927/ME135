
#include "SparkFunLSM6DSO.h"
#include "Wire.h"
//#include "SPI.h"

LSM6DSO myIMU;

void setup() {

  Serial.begin(9600);
  delay(500); 
  
  Wire.begin();
  delay(10);
  if( myIMU.begin() )
    Serial.println("Ready.");
  else { 
    Serial.println("Could not connect to IMU.");
    Serial.println("Freezing");
  }

  if(myIMU.initialize(BASIC_SETTINGS))
    Serial.println("Loaded Settings.");
}

void loop()
{
  
  Serial.print("X:");
  Serial.print(myIMU.readFloatGyroX(), 3);
  Serial.print(" ");
  Serial.print("Y:");
  Serial.print(myIMU.readFloatGyroY(), 3);
  Serial.print(" ");
  Serial.print("Z:");
  Serial.println(myIMU.readFloatGyroZ(), 3);
  
  delay(50);
}

