/*
 *  ClimoBike Módulo Wifi v0.0.2.0
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

#ifndef CLIMOBIKEWIFI_H
#define CLIMOBIKEWIFI_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>

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

WiFiClient server;

void printServer(String keyword, float data);
void printServer(String keyword, String data);
void ipfsObject(String dict);

void setupWifi() {
  Serial.print("Tentando iniciar Wifi...");
  WiFi.begin(networkName, networkPswd);
  Serial.print(" em ");
  Serial.print(networkName);
  Serial.print(" com ");
  Serial.print(networkPswd);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Nosso IP: ");
  Serial.print(WiFi.localIP());
  Serial.println();
  Serial.print("WiFi conectado");
/*  Serial.print(" mentira"); //mentira*/
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

void loopWifi() {
  Serial.print("ipv4: ");
  Serial.print(WiFi.localIP());
  Serial.println();
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

