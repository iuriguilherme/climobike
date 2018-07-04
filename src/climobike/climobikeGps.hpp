/*
 *  ClimoBike Módulo GPS v0.2.0.2
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

#ifndef CLIMOBIKEGPS_H
#define CLIMOBIKEGPS_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/*
 * SoftwareSerial para ESP32 ou não funcionando conforme nossa expectativa, ou
 * não conseguimos fazer funcionar. Na ausência do SoftwareSerial, vamos usar
 * HardwareSerial que deveria estar contida na biblioteca Arduino.
*/
//#include <SoftwareSerial.h>

#include <TinyGPS++.h>

//SoftwareSerial ss(RXPin, TXPin);
HardwareSerial ss(1);
TinyGPSPlus gps;

/* ESP32 */
static const int gpsRxPin = 16;
static const int gpsTxPin = 17;
static const uint32_t gpsBaud = 9600;

String dadosGps() {
  String dadosGpsString = "";
  while (ss.available() > 0) {
    gps.encode(ss.read());
  }
  if (gps.location.isUpdated()) {
    dadosGpsString += "{";
    dadosGpsString += "date";
    dadosGpsString += ":";
    dadosGpsString += gps.date.value();
    dadosGpsString += ",";
    dadosGpsString += "time";
    dadosGpsString += ":";
    dadosGpsString += gps.time.value();
    dadosGpsString += ",";
    dadosGpsString += "speed";
    dadosGpsString += ":";
    dadosGpsString += gps.speed.mps();
    dadosGpsString += ",";
    dadosGpsString += "altitude";
    dadosGpsString += ":";
    dadosGpsString += gps.altitude.meters();
    dadosGpsString += ",";
    dadosGpsString += "latitude";
    dadosGpsString += ":";
    dadosGpsString += gps.location.lat();
    dadosGpsString += ",";
    dadosGpsString += "longitude";
    dadosGpsString += ":";
    dadosGpsString += gps.location.lng();
    dadosGpsString += ",";
    dadosGpsString += "satellites";
    dadosGpsString += ":";
    dadosGpsString += gps.satellites.value();
    dadosGpsString += ",";
    dadosGpsString += "hdop";
    dadosGpsString += ":";
    dadosGpsString += gps.hdop.value();
    dadosGpsString += ",";
    dadosGpsString += "}";
  }
  return dadosGpsString;
}

void setupGps() {
  /* Escolher UMA dessas opções */
  /* SoftwareSerial */
  //ss.begin(gpsBaud);
  /* HardwareSerial */
  ss.begin(gpsBaud, SERIAL_8N1, gpsRxPin, gpsTxPin, false);

  Serial.print("Tentando iniciar GPS com ");
  Serial.print(gpsBaud);
  do {
    Serial.print(".");
    delay(1000);
  } while (false);
  if (!(ss.available() > 0)) {
    Serial.print(" não ");
  }
  Serial.println(" deu certo!");
}

void loopGps() {
  String nossosDadosGps = dadosGps();
  if (nossosDadosGps != "") {
    Serial.println(nossosDadosGps);
  }
}

#endif

