#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // Create an object

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);     // Starting the serial communication

  bmp.begin();      // Start the sensor

  /* Default settings from datasheet.  */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500);  /* Standby time. */
}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.print(F("Temperature  = "));
   Serial.print(bmp.readTemperature());
   Serial.println(" *C");

   Serial.print(F("Pressure = "));
   Serial.print(bmp.readPressure()/100);  //displaying the Pressure in hPa, you can change the unit
   Serial.println("  hPa");

   Serial.print(F("Approx altitude = "));
   Serial.print(bmp.readAltitude(1019.66));  //The "1019.66" is the pressure(hPa) at sea level in day in your region
   Serial.println("  m");                    //If you don't know it, modify it until you get your current  altitude

   Serial.println();
   delay(2000);
}
