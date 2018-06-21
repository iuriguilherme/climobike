/*
 * 	Climobike GPS + Sensors RAW Code
 * 	Authors:	Alisson Claudino (https://inf.ufrgs.br/~acjesus)
 * 				Desobediente Civil (https://notabug.org/desci)
 *	License:	GNU GPLv3
*/
#include <driver/adc.h>
#include "DHT.h"
#include "WiFi.h"
#include <WiFiClient.h>
#include <WiFiUdp.h>

#define DHTTYPE DHT22
#define DHTPIN 25
//pdelete key 40BaPA7qvxhwda0XOorVfO6wlVZ
const char * networkName = "Velivery 2";
const char * networkPswd = "salvaroplaneta";

const char* host = "192.168.0.100";
const char* streamId   = "1DygKVeN0luAy3mPZdDWudlPXWB";
const char* privateKey = "a70nN8gMz3uwN8peYjEbTvG6PWa";
const int httpPort = 8080;
// The serial connection to the GPS module
HardwareSerial ss(1);
String url;
String data;
byte gpsData;
DHT dht(DHTPIN,DHTTYPE);

WiFiClient client;

void printServer(String keyword,float data);

void setup(){
	Serial.begin(9600);
	ss.begin(9600, SERIAL_8N1, 16, 17);
	dht.begin();
	WiFi.begin(networkName, networkPswd);
	delay(5000);
	while (WiFi.status() != WL_CONNECTED) 
	{
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
	
	Serial.print("connecting to ");
    Serial.println(host);

    if (!client.connect(host, httpPort)) 
    {
        Serial.println("connection failed");
    }

}


void loop(){
	Serial.print("Local IP:");
	Serial.println(WiFi.localIP());

	// Imprime dados GPS
	while (ss.available() > 0) {
		gpsData = ss.read();
		Serial.write(gpsData);
	}
	
	// Imprime dados DHT
	Serial.print("$TEMPE,");
	Serial.print(dht.readTemperature());
	Serial.println();
	
	printServer("tempe",dht.readTemperature());    

	Serial.print("$HUMID,");
	Serial.print(dht.readHumidity());
	Serial.println();

	printServer("humid",dht.readHumidity());
	// Imprime dados do sensor de Metano
	Serial.print("$METAN,");
	Serial.print(analogRead(27));
	Serial.println();
	
	printServer("metan",analogRead(27));


	

    
}

void printServer(String keyword,float data)
{
	String url="";

	if (!client.connect(host, httpPort)) 
    {
        Serial.println("connection failed");
    }

	url = "/input/";
    url += streamId;
    url += "?private_key=";
    url += privateKey;
    url += "&";
    url += keyword;
    url += "=";
    url += data;

    client.print(String("GET ") + url+ " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");

    while(client.available()) {
        String line = client.readStringUntil('\n');
        Serial.print(line);
    }

    delay(5000);
}


