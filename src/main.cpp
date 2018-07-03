/*
 * 	ClimoBike v0.0.2.0
 *  Board:  esp32dev (v1, v2)
 * 	Authors:  Alisson Claudino (https://inf.ufrgs.br/~acjesus)
 *            Desobediente Civil (https://notabug.org/desci)
 *	License:  GNU GPLv3
*/



// Arduino
#include <Arduino.h>
// DHT
//#include <driver/adc.h>
//#include <DHT.h>
// WiFi
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
// Relógio
//#include <DS1307.h>
// SD
//#include <FS.h>
//#include <SD.h>
//#include <SPI.h>
// Bluetooth
//#include "BluetoothSerial.h"
// DHT
//#define DHTTYPE DHT22
//#define DHTPIN 27



// Wifi
// Foi o Alisson
//pdelete key 40BaPA7qvxhwda0XOorVfO6wlVZ
const char * networkName = "Velivery 2";
const char * networkPswd = "salvaroplaneta";

// HTTP
//const char* httpHost = "192.168.0.100"; // AlissonTop
//const char * httpHost = "192.168.0.198"; // mineiro-2
const char * httpHost = "192.168.0.195"; // precisao
//const int httpPort = 8080; // Phant
const int httpPort = 8081; // ipfs-1
WiFiClient server;
// Phant
//const char * streamId   = "1DygKVeN0luAy3mPZdDWudlPXWB";
//const char * privateKey = "a70nN8gMz3uwN8peYjEbTvG6PWa";
//int iteract=0;
//String url;
//String data;

// GPS
#include <climobikeGps.h>

// MQ4
//float metan;

// DHT
//DHT dht(DHTPIN,DHTTYPE);

// SD
//File file;

// Relógio
//DS1307 relogio;  //Inicialização de objetos de tipos relógio, data e Serial
//RTCDateTime date;

// Bluetooth
//BluetoothSerial SerialBT;



void printServer(String keyword, float data);
void printServer(String keyword, String data);

//void writeFile(const char * message) {
//  Serial.printf("Writing file: %s\n", "/rawData.dat");
//  if (!file) {
//    Serial.println("Failed to open file for writing");
//    return;
//  }
//  if (file.println(message)) {
//    Serial.println("File written");
//  } else {
//    Serial.println("Write failed");
//  }
//}

void setupSD() {
//  uint8_t cardType = SD.cardType();

//  if (!SD.begin()) {
//    Serial.println("Card Mount Failed");
//    return;
//  }
//  if (cardType == CARD_NONE) {
//    Serial.println("No SD card attached");
//    return;
//  }

  Serial.print("SD Card Type: ");
//  if (cardType == CARD_MMC) {
//    Serial.println("MMC");
//  } else if (cardType == CARD_SD) {
//    Serial.println("SDSC");
//  } else if (cardType == CARD_SDHC) {
//    Serial.println("SDHC");
//  } else {
//    Serial.println("UNKNOWN");
//  }

//  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
//  Serial.printf("SD Card Size: %lluMB\n", cardSize);

//  file = SD.open("/rawData.dat", FILE_WRITE);
}

void setupWifi() {
  WiFi.begin(networkName, networkPswd);
  //delay(5000);
  Serial.print("Tentando conectar em ");
  Serial.print(networkName);
  Serial.print(" com ");
  Serial.print(networkPswd);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi conectado!");
  Serial.print("Nosso IP: ");
  Serial.println(WiFi.localIP());
}

void setupHttp() {
  Serial.print("Tentando conectar em ");
  Serial.print(httpHost);
  Serial.print(":");
  Serial.print(httpPort);
  Serial.print("...");
  if (server.connect(httpHost, httpPort)) {
    Serial.println(" sucesso!");
  } else {
    Serial.println(" falhou!");
  }
}

void setupRelogio() {
//  relogio.begin();
//  date = relogio.getDateTime();
  Serial.print("\nData de inicio da aquisição: ");
//  Serial.print(date.year);
  Serial.print("-");
//  Serial.print(date.month);
  Serial.print("-");
//  Serial.print(date.day);
  Serial.print(" ");
//  Serial.print(date.hour);
  Serial.print(":");
//  Serial.print(date.minute);
  Serial.println();
}

void setupDHT() {
//  Serial.print("Tentando iniciar GPS com ");
//  dht.begin();
}

void setup() {
  // MQ4
  //adc1_config_width(ADC_WIDTH_12Bit);
  //adc1_config_channel_atten(ADC1_CHANNEL_6,ADC_ATTEN_0db);

  Serial.begin(9600);
  //SerialBT.begin("clo");

  //setupDHT();
  //setupSD();
  //setupWifi();
  //setupHttp();
  //setupRelogio();
  setupGps();
}

void loop() {
  // Debug
  //Serial.print("Local IP:");
  //Serial.println(WiFi.localIP());

  // Timestamp
  //Serial.print("timestamp: ");
  //Serial.print(relogio.getDateTime());
  //Serial.println();

  loopGps();

  // Imprime dados DHT
  //Serial.print("tempe: ");
  //Serial.print(dht.readTemperature());
  //Serial.println();
  //printServer("tempe",dht.readTemperature());    
  //Serial.print("humid: ");
  //Serial.print(dht.readHumidity());
  //Serial.println();
  //printServer("humid",dht.readHumidity());

  // Imprime dados do sensor de Metano MQ4
  //Serial.print("metan: ");
  //metan = adc1_get_voltage(ADC1_CHANNEL_6);
  //Serial.print(metan);
  //Serial.println();
  //printServer("metan",metan);

}

//void printServer(String keyword, float data) {
//  if (iteract==20) {
//    if(file) {
//      file.close();
//    }
//  } else {
//    String url="";
//    String sdData="\n";
//    sdData+=keyword;
//    sdData+="=";
//    sdData+=data;

//    if (!server.connect(httpHost, httpPort)) {
//      Serial.println("connection failed");
//    }

//    url = "/input/";
//    url += streamId;
//    url += "?private_key=";
//    url += privateKey;
//    url += "&";
//    url += keyword;
//    url += "=";
//    url += data;

//    server.print(String("GET ") +
//      url +
//      " HTTP/1.1\r\n" +
//      "Host: " +
//      httpHost +
//      "\r\n" +
//      "Connection: close\r\n\r\n");

//    while (server.available()) {
//      String line = server.readStringUntil('\n');
//      Serial.print(line);
//    }

//    writeFile(sdData.c_str());
//    delay(1000);
//    iteract++;
//  }
//}

void ipfsObject(String dict) {
    String url="";

    if (!server.connect(httpHost, httpPort)) {
      Serial.println("connection failed");
    }

    // ipfs-1
    url = "/ipfs/";
    url += "add";
    url += "?arg=";
    url += dict;

//    server.print(String("GET ") +
//      url +
//      " HTTP/1.1\r\n" +
//      "Host: " +
//      httpHost +
//      "\r\n" +
//      "Connection: close\r\n\r\n");

//    while (server.available()) {
//      String line = server.readStringUntil('\n');
//      Serial.print(line);
//    }

//    writeFile(sdData.c_str());
//    delay(1000);
//    iteract++;
//  }
}

