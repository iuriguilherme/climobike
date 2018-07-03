/*
 *  ClimoBike v0.0.2.0
 *  Board:  esp32dev (v1, v2)
 *  Authors:
 *    Alisson Claudino (https://inf.ufrgs.br/~acjesus)
 *    Desobediente Civil (https://notabug.org/desci)
 *  License:  GNU GPLv3
 *
 * Este programa é distribuído na esperança de que possa ser útil,
 * mas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO a qualquer
 * MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a Licença Pública Geral GNU
 * para mais detalhes.
 *
 * Você deve ter recebido uma cópia da Licença Pública Geral GNU junto
 * com este programa (veja o arquivo LICENSE.md).
 * Se não, veja http://www.gnu.org/licenses/.
*/

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/* Sensores analógicos */
#include <driver/adc.h>

/* DHT */
#include <DHT.h>

/* WiFi */
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>

/* Relógio */
#include <DS1307.h>

/* SD */
#include <FS.h>
#include <SD.h>
#include <SPI.h>

/* Bluetooth */
//#include "BluetoothSerial.h"

/* DHT */
#define DHTTYPE DHT22
#define DHTPIN 27

/* Wifi */
/* Foi o Alisson que botou as senhas de todas as redes do Velivery aqui */
//pdelete key 40BaPA7qvxhwda0XOorVfO6wlVZ
const char * networkName = "Velivery 2";
const char * networkPswd = "salvaroplaneta";

/* HTTP */
//const char * httpHost = "192.168.0.100"; // AlissonTop
//const char * httpHost = "192.168.0.198"; // mineiro-2
//const char * httpHost = "192.168.0.195"; // precisao
const char * httpHost = "cb1.r.velivery.com.br"; // op1
/* Phant */
const char * streamId   = "1DygKVeN0luAy3mPZdDWudlPXWB";
const char * privateKey = "a70nN8gMz3uwN8peYjEbTvG6PWa";
//const int httpPort = 8080; // Phant
const int httpPort = 8081; // ipfs-1
int iteract=0;
String url;
String data;

/* Gases */
float metan,toxic,monca;

/* DHT */
DHT dht(DHTPIN,DHTTYPE);

/* SD */
File file;

/* Relógio */
DS1307 relogio;  //Inicialização de objetos de tipos relógio, data e Serial
RTCDateTime date;

/* Bluetooth */
//BluetoothSerial SerialBT;

/* Wifi */
WiFiClient server;

/* GPS */
#include <climobikeGps.h>

void printServer(String keyword, float data);
void printServer(String keyword, String data);
void writeFile(const char * message);
void ipfsObject(String dict);

void setupSd() {
  Serial.print("Tentando iniciar cartão SD...");
//  uint8_t cardType = SD.cardType();

//  if (!SD.begin()) {
//    Serial.println("Card Mount Failed");
//    return;
//  }
//  if (cardType == CARD_NONE) {
//    Serial.println("No SD card attached");
//    return;
//  }

//  Serial.print("SD Card Type: ");
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
  Serial.print(" mentira"); //mentira
  Serial.println("!");
}

void setupWifi() {
  Serial.print("Tentando conectar wifi...");
//  WiFi.begin(networkName, networkPswd);
//  Serial.print(" em ");
//  Serial.print(networkName);
//  Serial.print(" com ");
//  Serial.print(networkPswd);
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(1000);
//    Serial.print(".");
//  }
//  Serial.println();
//  Serial.print("Nosso IP: ");
//  Serial.print(WiFi.localIP());
//  Serial.print("WiFi conectado");
  Serial.print(" mentira"); //mentira
  Serial.println("!");
}

void setupHttp() {
  Serial.print("Tentando conectar no servidor http...");
//  Serial.print(httpHost);
//  Serial.print(":");
//  Serial.print(httpPort);
//  Serial.print("...");
//  if (server.connect(httpHost, httpPort)) {
//    Serial.println(" sucesso!");
//  } else {
//    Serial.println(" falhou!");
//  }
  Serial.print(" mentira"); //mentira
  Serial.println("!");
}

void setupAnal() {
  Serial.print("Tentando iniciar sensores analógicos...");
//  adc_power_on();
//  adc_gpio_init(ADC_UNIT_1,ADC_CHANNEL_6);
//  adc_gpio_init(ADC_UNIT_1,ADC_CHANNEL_5);
//  adc_gpio_init(ADC_UNIT_1,ADC_CHANNEL_4);
//  adc1_config_width(ADC_WIDTH_12Bit);
//  adc1_config_channel_atten(ADC1_CHANNEL_6,ADC_ATTEN_0db);
//  adc1_config_channel_atten(ADC1_CHANNEL_5,ADC_ATTEN_0db);
//  adc1_config_channel_atten(ADC1_CHANNEL_4,ADC_ATTEN_0db);
  Serial.print(" mentira"); //mentira
  Serial.println("!");
}

void setupRelogio() {
  Serial.print("Tentando iniciar Relógio...");
//  relogio.begin();
//  date = relogio.getDateTime();
//  Serial.print("\nData de inicio da aquisição: ");
//  Serial.print(date.year);
//  Serial.print("-");
//  Serial.print(date.month);
//  Serial.print("-");
//  Serial.print(date.day);
//  Serial.print(" ");
//  Serial.print(date.hour);
//  Serial.print(":");
//  Serial.print(date.minute);
  Serial.print(" mentira"); //mentira
  Serial.println("!");
}

void setupDht() {
  Serial.print("Tentando iniciar DHT...");
//  Serial.print(" deu ");
//  if (dht.begin()) {
//    Serial.print("certo");
//  } else {
//    Serial.print("merda");
//  }
  Serial.print(" mentira"); //mentira
  Serial.println("!");
}

void setupBluetooth() {
  Serial.print("Tentando iniciar Bluetooth...");
  //SerialBT.begin("clo");
  Serial.print(" mentira"); //mentira
  Serial.println("!");
}

void loopWifi() {
  Serial.print("ipv4: ");
  Serial.print(WiFi.localIP());
  Serial.println();
}

void loopRelogio() {
  Serial.print("timestamp: ");
  //Serial.print(relogio.getDateTime());
  Serial.print("2018-07-03 18:00"); //mentira
  Serial.println();
}

void loopDht() {
  /* Imprime dados DHT */

  Serial.print("tempe: ");
//  Serial.print(dht.readTemperature());
  Serial.print("25.0"); // mentira
  Serial.println();

//  printServer("tempe",dht.readTemperature());    

  Serial.print("humid: ");
//  Serial.print(dht.readHumidity());
  Serial.print("50.0"); // mentira
  Serial.println();

//  printServer("humid",dht.readHumidity());
}

void loopGases() {
  /* Metano MQ4 */
  Serial.print("ch4: ");
//  metan = adc1_get_raw(ADC1_CHANNEL_6);
  delay(300);
//  Serial.print(metan);
  Serial.print("bastante"); //mentira
  Serial.println();
//  printServer("CH4",metan);

  /* Gases tóxicos */
  Serial.print("no: ");
//  toxic = adc1_get_raw(ADC1_CHANNEL_5);
  delay(300);
//  Serial.print(toxic);
  Serial.print("pouco"); //mentira
  Serial.println();
//  printServer("NO",toxic);
  Serial.print("co: ");
//  monca = adc1_get_raw(ADC1_CHANNEL_4);
  delay(300);
//  Serial.print(monca);
  Serial.print("mais ou menos"); //mentira
  Serial.println();
//  printServer("CO",monca);
}

void setup(){

  delay(300);
//  setupAnal();

  Serial.begin(9600);

//  setupBluetooth();
//  setupRelogio();
//  setupDht();
//  setupWifi();
//  setupSd();
//  setupHttp();
  setupGps();

}

void loop() {

  loopWifi();
  loopRelogio();
  loopDht();
  loopGases();
  loopGps();

}

void printServer(String keyword, float data) {
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
}

void ipfsObject(String dict) {
//    String url="";

//    if (!server.connect(httpHost, httpPort)) {
//      Serial.println("connection failed");
//    }

//    // ipfs-1
//    url = "/ipfs/";
//    url += "add";
//    url += "?arg=";
//    url += dict;

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

void writeFile(const char * message) {
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
}

