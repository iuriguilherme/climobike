/*
 *  ClimoBike Módulo Relógio v0.0.2.0
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

#ifndef CLIMOBIKERELOGIO_H
#define CLIMOBIKERELOGIO_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <DS1307.h>

DS1307 relogio;  //Inicialização de objetos de tipos relógio, data e Serial
RTCDateTime datetime;

void setupRelogio() {
  Serial.print("Tentando iniciar Relógio...");
/*  Serial.print(" deu ");*/
/*  relogio.begin();*/
/*  datetime = relogio.getDateTime();*/
/*  if ((int)datetime.year > 0) {*/
/*    Serial.print(" certo");*/
/*  } else {*/
/*    Serial.print(" merda");*/
/*  }*/
  Serial.print(" mentira"); //mentira
  Serial.println("!");
}

void loopRelogio() {
  Serial.print("timestamp: ");
/*  datetime = relogio.getDateTime();*/
  String timestamp = "";
  timestamp += "'";
/*  if ((int)datetime.year > 0) {*/
/*    timestamp += datetime.year;*/
/*    timestamp += "-";*/
/*    timestamp += datetime.month;*/
/*    timestamp += "-";*/
/*    timestamp += datetime.day;*/
/*    timestamp += " ";*/
/*    timestamp += datetime.hour;*/
/*    timestamp += ":";*/
/*    timestamp += datetime.minute;*/
/*  }*/
  timestamp += "2018-07-03 18:00"; //mentira
  timestamp += "'";
  Serial.print(timestamp);
  Serial.println();
}

#endif

