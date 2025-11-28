//=============================================================================
/* 
 * Чтение данных с трех разных BMP085: 
 * два по программному, третий по аппаратному интерфейсу.
 * используется модифцированная библиотека Adfrt_BMP085
 */
//=============================================================================

#include "BB_Adfrt_BMP085.h"
#include "BitBang_I2C.h"

// Arbitrary pins I used for testing with an ATmega328p

//#define SDA_PIN -1
//#define SCL_PIN -1

#define SDA_PIN_1 17
#define SCL_PIN_1 16

#define SDA_PIN_2 15
#define SCL_PIN_2 14
 
BB_Adfrt_BMP085 bmp1;
BB_Adfrt_BMP085 bmp2;
BB_Adfrt_BMP085 bmp3;

#define ERR1 "Could not find a valid BMP085 "
#define ERR2 " check wiring!"
#define OK " OK!"

void setup() {
  Serial.begin(9600);
  
  #define SENSOR "_SW1_"
   /* | oversampling | speed | SDA pin |  SCL pin | 
                  |      |         |          |     */
  if (!bmp1.begin(1, 10000L, SDA_PIN_1, SCL_PIN_1)){
    Serial.print(ERR1); Serial.print(SENSOR); Serial.println(ERR2);}
  else
    {Serial.print(SENSOR); Serial.println(OK);}

  #define SENSOR "_SW2_"
  if (!bmp2.begin(1, 100000L, SDA_PIN_2, SCL_PIN_2)){
    Serial.print(ERR1); Serial.print(SENSOR); Serial.println(ERR2);}
  else
    {Serial.print(SENSOR); Serial.println(OK);}
  
  #define SENSOR "_HW_"
  if (!bmp3.begin(1)){
    Serial.print(ERR1); Serial.print(SENSOR); Serial.println(ERR2);}
  else
    {Serial.print(SENSOR); Serial.println(OK);}

  delay(100); // allow devices to power up
}

void loop() {
uint8_t ret[2]={0xf4,0x2e};
uint8_t out[2];
uint8_t rett[1]={0xf4};
uint8_t outt[1];

int32_t pres1, pres2, pres3, diff;

  #define Sensor bmp1
  Serial.print("Temperature = ");
  Serial.print(Sensor.readTemperature());
  Serial.println(" *C");
  
  Serial.print("Pressure = ");
  Serial.print(Sensor.readPressure());
  Serial.println(" Pa"); 
  Serial.println("");

  #define Sensor bmp2
  Serial.print("Temperature = ");
  Serial.print(Sensor.readTemperature());
  Serial.println(" *C");
  
  Serial.print("Pressure = ");
  Serial.print(Sensor.readPressure());
  Serial.println(" Pa"); 
  Serial.println("");

  #define Sensor bmp3
  Serial.print("Temperature = ");
  Serial.print(Sensor.readTemperature());
  Serial.println(" *C");
  
  Serial.print("Pressure = ");
  Serial.print(Sensor.readPressure());
  Serial.println(" Pa"); 
  Serial.println("");


  delay(1000);
}
