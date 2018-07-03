/*
 *  ClimoBike Módulo DHT v0.0.2.0
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

#ifndef CLIMOBIKEDHT_H
#define CLIMOBIKEDHT_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <DHT.h>

#define DHTTYPE DHT22
#define DHTPIN 27

DHT dht(DHTPIN,DHTTYPE);

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

#endif

