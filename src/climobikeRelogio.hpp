/*
 *  ClimoBike Módulo Relógio v0.0.2.1
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

/* TODO incluir no platformio.ini */
#include <DS1307.h>
#include <Wire.h>

DS1307 relogio;
RTCDateTime datetime;

void atualizaHora();
RTCDateTime agora();

void setupRelogio() {
  Serial.print("Tentando iniciar Relógio...");
  Serial.print(" deu ");

  Wire.beginTransmission(0x67);
  if (Wire.endTransmission() == 0) {
    relogio.begin();
    Serial.print("certo");
    Serial.println("!");
    Serial.print("Atualizando hora...");
    atualizaHora();
    Serial.println(" feito!");
  } else {
    Serial.print("merda");
    Serial.println("!");
  }
/*  Serial.print("mentira"); //mentira*/
/*  Serial.println("!"); //mentira*/
}

void loopRelogio() {
  String timestamp = "";
  Serial.print("timestamp: ");
  timestamp += "'";

  Wire.beginTransmission(0x67);
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
    }
  } else {
    timestamp += "2018-07-03 18:00"; //mentira
  }

  timestamp += "'";
  Serial.print(timestamp);
  Serial.println();
}

/* Grava a data atual do computador no momento da compilação no relógio */
void atualizaHora() {
  relogio.setDateTime(__DATE__, __TIME__);
}

/* Que horas? */
RTCDateTime agora() {
  Wire.beginTransmission(0x67);
  if (Wire.endTransmission()==0) {
    return relogio.getDateTime();
  }
  log("Erro tentando obter hora do relógio DS1307");
  return datetime;
}
uint32_t agoraU() {
  Wire.beginTransmission(0x67);
  if (Wire.endTransmission()==0) {
    return relogio.getDateTime().unixtime;
  }
  log("Erro tentando obter unixtime do relógio DS1307");
  return datetime.unixtime;
}


#endif

