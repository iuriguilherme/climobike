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
#define CLIMOBIKETTP_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <WiFiClient.h>

//const char * httpHost = "192.168.0.100"; // AlissonTop
//const char * httpHost = "192.168.0.198"; // mineiro-2
const char * httpHost = "192.168.0.195"; // precisao
//const char * httpHost = "cb1.r.velivery.com.br"; // op1
/* Phant */
const char * streamId   = "1DygKVeN0luAy3mPZdDWudlPXWB";
const char * privateKey = "a70nN8gMz3uwN8peYjEbTvG6PWa";
//const int httpPort = 8080; // Phant
const int httpPort = 5001; // ipfs-1

String url;
String data;

WiFiClient server;

void printServer(String keyword, float data);
void printServer(String keyword, String data);
void ipfsObject(String dict);

void setupHttp() {
  Serial.print("Tentando conectar no servidor http...");
  Serial.print(httpHost);
  Serial.print(":");
  Serial.print(httpPort);
  Serial.print("...");
  if (server.connect(httpHost, httpPort)) {
    Serial.println(" sucesso");
  } else {
    Serial.println(" falhou");
  }
//  Serial.print(" mentira"); //mentira
  Serial.println("!");
}

void loopHttp() {
  server.println("GET /api/v0/swarm/peers HTTP/1.0");
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

#endif

