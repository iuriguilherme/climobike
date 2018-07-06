/*
 *  ClimoBike Módulo Wifi v0.2.0.2
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

/* Foi o Alisson que botou as senhas de todas as redes do Velivery aqui */
const char * networkName = "Velivery 2";
const char * networkPswd = "salvaroplaneta";

void setupWifi() {
  Serial.print("Tentando iniciar Wifi");
  Serial.print(" em ");
  Serial.print(networkName);
  Serial.print(" com ");
  Serial.print(networkPswd);

  WiFi.begin(networkName, networkPswd);
  while (WiFi.status() == WL_IDLE_STATUS) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println();
}

void loopWifi() {
  switch (WiFi.status()) {
    case WL_CONNECTED:
      Serial.println("assigned when connected to a WiFi network");
      break;
    case WL_NO_SHIELD:
      Serial.println("assigned when no WiFi shield is present");
      break;
    case WL_IDLE_STATUS:
      Serial.println("it is a temporary status assigned when WiFi.begin() is called and remains active until the number of attempts expires (resulting in WL_CONNECT_FAILED) or a connection is established (resulting in WL_CONNECTED)");
      break;
    case WL_NO_SSID_AVAIL:
      Serial.println("assigned when no SSID are available");
      break;
    case WL_SCAN_COMPLETED:
      Serial.println("assigned when the scan networks is completed");
      break;
    case WL_CONNECT_FAILED:
      Serial.println("assigned when the connection fails for all the attempts");
      break;
    case WL_CONNECTION_LOST:
      Serial.println("assigned when the connection is lost");
      break;
    case WL_DISCONNECTED:
      Serial.println("assigned when disconnected from a network");
      break;
    default:
      Serial.println("nunca deveria aparecer isto");
  }
  delay(3000);
}

#endif

