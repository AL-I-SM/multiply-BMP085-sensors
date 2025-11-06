#include "BB_Adfrt_BMP085.h"
#include "BitBang_I2C.h"

// Arbitrary pins I used for testing with an ATmega328p
// Define as -1, -1 to use the Wire library over the default I2C interface
//#define SDA_PIN -1
//#define SCL_PIN -1

#define SDA_PIN 17
#define SCL_PIN 16


#define SDA_PIN_2 15
#define SCL_PIN_2 14

// If you don't need the explicit device names displayed, disable this code by
// commenting out the next line
 
BB_Adfrt_BMP085 bmp1;
BB_Adfrt_BMP085 bmp2;
BB_Adfrt_BMP085 bmp3;

#define SENSOR1 #SW_#1
#define SENSOR2 #SW_#2
#define SENSOR3 #SW

void setup() {
  Serial.begin(9600);
 

  if (!bmp1.begin(1, 100000L, SDA_PIN, SCL_PIN))
    Serial.println("Could not find a valid BMP085 SENSOR1 sensor, check wiring!");
  else
    Serial.println("SENSOR1 ОК!");
 
  if (!bmp2.begin(1, 50000L, SDA_PIN_2, SCL_PIN_2))
    Serial.println("Could not find a valid BMP085 SENSOR2 sensor, check wiring!");
  else
    Serial.println("SENSOR2 ОК!");

  if (!bmp3.begin(1))
    Serial.println("Could not find a valid BMP085 SENSOR3 sensor, check wiring!");
  else
    Serial.println("SENSOR3 OK!"); 
  
  delay(100); // allow devices to power up
}


void loop() {
uint8_t ret[2]={0xf4,0x2e};
uint8_t out[2];
uint8_t rett[1]={0xf4};
uint8_t outt[1];

int32_t pres1, pres2, pres3, diff;

  Serial.print("Temperature = ");
  Serial.print(bmp1.readTemperature());
  Serial.println(" *C");

  Serial.print("Pressure = ");
  pres1=bmp1.readPressure();
  Serial.print(pres1);
  Serial.println(" Pa"); 

  Serial.print("Temperature = ");
  Serial.print(bmp2.readTemperature());
  Serial.println(" *C");

  Serial.print("Pressure = ");
  pres2=bmp2.readPressure();
  Serial.print(pres2);
  Serial.println(" Pa");

  Serial.print("Temperature = ");
  Serial.print(bmp3.readTemperature());
  Serial.println(" *C");

  Serial.print("Pressure = ");
  pres3=bmp3.readPressure();
  Serial.print(pres3);
  Serial.println(" Pa");
/*  
  diff=pres1-pres2-300;
  Serial.println(diff);
*/



  delay(1000);
}
