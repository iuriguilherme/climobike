/*
 *  ClimoBike Módulo Http v0.2.0.2
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

#ifndef CLIMOBIKEHTTP_H
#define CLIMOBIKEHTTP_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <WiFiClient.h>

//const char * connectIp = "192.168.0.100"; // AlissonTop
//const char * connectIp = "192.168.0.198"; // mineiro-2
const char * connectIp = "192.168.0.195"; // precisao
String connectUrl = "cb1.r.velivery.com.br"; // op1

/* Phant */
//const char * streamId   = "1DygKVeN0luAy3mPZdDWudlPXWB";
//const char * privateKey = "a70nN8gMz3uwN8peYjEbTvG6PWa";

//const int connectPort = 8080; // Phant@AlissonTop
const int connectPort = 5001; // ipfs-1@precisao

//String url;
//String data;

WiFiClient client;
ClimobikeLog LogHttp;

void printServer(String keyword, float data);
void printServer(String keyword, String data);
void ipfsObject(String dict);
void setupHttpIp();
void setupHttpUrl();

void setupHttp() {
  setupHttpIp();
//  setupHttpUrl();
  Serial.print("Tentando conectar no servidor http...");
  Serial.print(connectIp);
  Serial.print(":");
  Serial.print(connectPort);
  Serial.print("...");
  if (client.connect(connectIp, connectPort)) {
    Serial.print(" sucesso");
  } else {
    Serial.print(" falhou");
  }
  Serial.println("!");
}

void loopHttp() {
  client.println("GET /api/v0/swarm/peers HTTP/1.0");
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

void setupHttpIp() {
  LogHttp.logSerial("Tentando conectar no ip ");
  LogHttp.logSerial(connectIp);
  LogHttp.logSerial(", porta ");
  LogHttp.logSerial(String(connectPort));
  LogHttp.logSerial("...");
  if (client.connect(connectIp, connectPort)) {
    LogHttp.logSerial(" sucesso");
  } else {
    LogHttp.logSerial(" falhou");
  }
  LogHttp.logSerialLn("!");
}

void setupHttpUrl() {
  LogHttp.logSerial("Tentando conectar no URL ");
  LogHttp.logSerial(connectUrl.c_str());
  LogHttp.logSerial(", porta ");
  LogHttp.logSerial(String(connectPort));
  LogHttp.logSerial("...");
  if (client.connect(connectUrl.c_str(), connectPort)) {
    LogHttp.logSerial(" sucesso");
  } else {
    LogHttp.logSerial(" falhou");
  }
  LogHttp.logSerialLn("!");
}

#endif

