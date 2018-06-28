/*
 * 	Climobike GPS + Sensors RAW Code
 * 	Authors:	Alisson Claudino (https://inf.ufrgs.br/~acjesus)
 * 				Desobediente Civil (https://notabug.org/desci)
 *	License:	GNU GPLv3
*/

#include <Arduino.h>
#include <driver/adc.h>
#include <DHT.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#include <DS1307.h>
//#include <NMEAGPS.h>
//#include <GPSport.h>
#include <FS.h>
#include <SD.h>
#include <SPI.h>
//#include "BluetoothSerial.h"

#define DHTTYPE DHT22
#define DHTPIN 27

// Foi o Alisson
//pdelete key 40BaPA7qvxhwda0XOorVfO6wlVZ
const char * networkName = "Velivery 2";
const char * networkPswd = "salvaroplaneta";
const char* host = "192.168.0.100";
const char* streamId   = "1DygKVeN0luAy3mPZdDWudlPXWB";
const char* privateKey = "a70nN8gMz3uwN8peYjEbTvG6PWa";
const int httpPort = 8080;
int iteract=0;

// The serial connection to the GPS module
HardwareSerial ss(1);
String url;
String data;
byte gpsData;

float metan;
DHT dht(DHTPIN,DHTTYPE);
File file;
DS1307 relogio;  //Inicialização de objetos de tipos relógio, data e Serial
RTCDateTime date;

//BluetoothSerial SerialBT;
WiFiClient server;

void printServer(String keyword,float data);

void writeFile(const char * message) {
  Serial.printf("Writing file: %s\n", "/rawData.dat");
  if (!file) {
    Serial.println("Failed to open file for writing");
    return;
  }
  if (file.println(message)) {
    Serial.println("File written");
  } else {
    Serial.println("Write failed");
  }
}

void configureSD() {
  uint8_t cardType = SD.cardType();

  if (!SD.begin()) {
    Serial.println("Card Mount Failed");
    return;
  }
  if (cardType == CARD_NONE) {
    Serial.println("No SD card attached");
    return;
  }

  Serial.print("SD Card Type: ");
  if (cardType == CARD_MMC) {
    Serial.println("MMC");
  } else if (cardType == CARD_SD) {
    Serial.println("SDSC");
  } else if (cardType == CARD_SDHC) {
    Serial.println("SDHC");
  } else {
    Serial.println("UNKNOWN");
  }

  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  Serial.printf("SD Card Size: %lluMB\n", cardSize);
}

void setup() {
  adc1_config_width(ADC_WIDTH_12Bit);
  adc1_config_channel_atten(ADC1_CHANNEL_6,ADC_ATTEN_0db);

  Serial.begin(9600);
  //SerialBT.begin("clo");
  relogio.begin();
  ss.begin(9600, SERIAL_8N1, 16, 17);
  dht.begin();
  WiFi.begin(networkName, networkPswd);
  delay(5000);
  configureSD();
  file = SD.open("/rawData.dat", FILE_WRITE);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("connecting to ");
  Serial.println(host);

  if (!server.connect(host, httpPort)) {
    Serial.println("connection failed");
  }

  date = relogio.getDateTime();
  Serial.print("\nData de inicio da aquisição: ");
  Serial.print(date.year);
  Serial.print("-");
  Serial.print(date.month);
  Serial.print("-");
  Serial.print(date.day);
  Serial.print(" ");
  Serial.print(date.hour);
  Serial.print(":");
  Serial.print(date.minute);
  Serial.println();
}

void loop() {
  Serial.print("Local IP:");
  Serial.println(WiFi.localIP());

  // Imprime dados GPS
  while (ss.available() > 0) {
    gpsData = ss.read();
    Serial.write(gpsData);
  }

  // Imprime dados DHT
  Serial.println();
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
  metan = adc1_get_voltage(ADC1_CHANNEL_6);
  Serial.print(metan);
  Serial.println();

  printServer("metan",metan);
}

void printServer(String keyword,float data) {
  if (iteract==20) {
    if(file) {
      file.close();
    }
  } else {
    String url="";
    String sdData="\n";
    sdData+=keyword;
    sdData+="=";
    sdData+=data;
    if (!server.connect(host, httpPort)) {
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

    server.print(String("GET ") +
      url +
      " HTTP/1.1\r\n" +
      "Host: " +
      host +
      "\r\n" +
      "Connection: close\r\n\r\n");

    while (server.available()) {
      String line = server.readStringUntil('\n');
      Serial.print(line);
    }

    writeFile(sdData.c_str());
    delay(1000);
    iteract++;
  }
}

