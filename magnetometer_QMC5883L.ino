/*
 * QMC5883L Magnetometer
 *   triple axis magnetometer compass sensor
 * 
 * note: the board is labeled HMC5883L, but it is not that chip,
 * its a QMC5883L, which uses a different library
 * 
 * use library:
 * https://github.com/mprograms/QMC5883LCompass
 * 
 * VCC - 3.3 or 5 VDC
 * GND - ground
 * SCL - i2c pins (on wemos: SDA => D2, SCL => D1)
 * SDA - ic2 pins
 * DRDY - Data Ready Pin Output. This pin is used to know that when data is ready to be read
 *        don't see a need for this pin 
 */

#include <QMC5883LCompass.h>

QMC5883LCompass compass;


void setup(void) {
  // start serial port
  Serial.begin(115200);
  Serial.println("\n\n\nQMC5883 Magnetometer Test");
  Serial.println("");
  
  compass.init(); 
}


void loop() {
int x, y, z, a, b;
  char myArray[3];
  
  compass.read();
  
  x = compass.getX();
  y = compass.getY();
  z = compass.getZ();
  a = compass.getAzimuth();
  b = compass.getBearing(a);
  compass.getDirection(myArray, a);
    
  Serial.print("X: ");
  Serial.print(x);

  Serial.print(" Y: ");
  Serial.print(y);

  Serial.print(" Z: ");
  Serial.print(z);

  Serial.print(" Azimuth: ");
  Serial.print(a);

  Serial.print(" Bearing: ");
  Serial.print(b);

  Serial.print(" Direction: ");
  Serial.print(myArray[0]);
  Serial.print(myArray[1]);
  Serial.print(myArray[2]);

  Serial.println();

  delay(250);
}
