/*
 * 	Climobike GPS RAW Code
 * 	Authors:	Alisson Claudino (https://inf.ufrgs.br/acjesus)
 * 				Desobediente Civil (https://notabug.org/desci)
 *	License:	GNU GPLv3
*/
#include <driver/adc.h>
#include <Arduino.h>
#include "DHT.h"
#include <WiFi.h>
#include <WiFiUdp.h>

#define DHTTYPE DHT22
#define DHTPIN 25

const char * networkName = "Velivery 2";
const char * networkPswd = "salvaroplaneta";

// The serial connection to the GPS module
HardwareSerial ss(1);

byte gpsData;
DHT dht(DHTPIN,DHTTYPE);

void setup(){
	Serial.begin(9600);
	ss.begin(9600, SERIAL_8N1, 16, 17);
	dht.begin();
	
}


void loop(){
	
	
	// Imprime dados GPS
	while (ss.available() > 0) {
		gpsData = ss.read();
		Serial.write(gpsData);
	}

	// Imprime dados DHT
	Serial.print("$TEMPE,");
	Serial.print(dht.readTemperature());
	Serial.println();

	Serial.print("$HUMID,");
	Serial.print(dht.readHumidity());
	Serial.println();

	// Imprime dados do sensor de Metano
	Serial.print("$METAN,");
	Serial.print(analogRead(27));
	Serial.println();
}



