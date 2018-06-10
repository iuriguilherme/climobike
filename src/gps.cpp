/*	Climobike GPS RAW Code
	Author: Alisson Claudino (https://inf.ufrgs.br/acjesus)
	License: GNU GPLv3
*/


#include <SoftwareSerial.h>

// The serial connection to the GPS module
SoftwareSerial ss(4, 3);
byte gpsData;

void setup(){
  Serial.begin(9600);
  ss.begin(9600);
}

void loop(){
  while (ss.available() > 0)
  {
    // get the byte data from the GPS
    gpsData = ss.read();
    Serial.write(gpsData);
  }
}
