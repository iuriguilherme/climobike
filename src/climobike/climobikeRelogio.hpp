/*
 *  ClimoBike Módulo Relógio v0.2.0.2
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

#ifndef CLIMOBIKERELOGIO_HPP
#define CLIMOBIKERELOGIO_HPP

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define EPOCH "1970-01-01 00:00:00"

/* TODO incluir no platformio.ini */
#include <DS1307.h>
#include <Wire.h>

DS1307 relogio;
RTCDateTime datetime;

void atualizaHora();

void setupRelogio() {
  logSerial("Tentando iniciar Relógio...");
  relogio.begin();
  logSerial(" deu ");
  Wire.beginTransmission(0x68);
  if (Wire.endTransmission() == 0) {
    relogio.begin();
    logSerial("certo");
//    Serial.print("Atualizando hora...");
//    atualizaHora();
//    Serial.println(" feito!");
  } else {
    logSerial("errado");
  }
  logSerialLn("!");
}

void loopRelogio() {
  String timestamp = "";
  timestamp += "{";
  timestamp += "timestamp";
  timestamp += ":";
  timestamp += "'";

  Wire.beginTransmission(0x68);
  if (Wire.endTransmission() == 0) {
    datetime = relogio.getDateTime();
    if ((int)datetime.year > 0) {
      timestamp += datetime.year;
      timestamp += "-";
      timestamp += datetime.month;
      timestamp += "-";
      timestamp += datetime.day;
      timestamp += " ";
      timestamp += datetime.hour;
      timestamp += ":";
      timestamp += datetime.minute;
      timestamp += ":";
      timestamp += datetime.second;
      timestamp += " ";
      timestamp += "(";
      timestamp += datetime.unixtime;
      timestamp += ")";
    }
  } else {
    timestamp += EPOCH; //mentira
  }

  timestamp += "'";
  timestamp += "}";
  log(timestamp);
}

void loopRelogio() {
  String timestamp = "";
  timestamp += "{";
  timestamp += "datetime";
  timestamp += ":";
  timestamp += "'";
  timestamp += "2018";
  timestamp += "-";
  timestamp += "07";
  timestamp += "-";
  timestamp += "03";
  timestamp += " ";
  timestamp += "18";
  timestamp += ":";
  timestamp += "00";
  timestamp += ":";
  timestamp += "00";
  timestamp += " ";
  timestamp += "(";
  timestamp += "0";
  timestamp += ")";
  timestamp += "'";
  timestamp += "}";
  logSerialLn(timestamp);
}

/* Grava a data atual do computador no momento da compilação no relógio */
void atualizaHora() {
  relogio.setDateTime(__DATE__, __TIME__);
}

#endif

