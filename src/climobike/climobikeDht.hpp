/*
 *  ClimoBike Módulo DHT v0.2.0.2
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
#define DHTPIN 14

DHT dht(DHTPIN,DHTTYPE);

void setupDht() {
  Serial.print("Tentando iniciar DHT...");
  dht.begin();
  Serial.print(" feito");
/*  Serial.print(" mentira"); //mentira*/
  Serial.println("!");
}

String loopDht() {
  /* Imprime dados DHT */
  String dado="";
  dado+="\ntempe: ";
  dado+=(String)dht.readTemperature();
  dado+="\nhumid: ";
  dado+=(String)dht.readHumidity();
  dado+="\n";
  
  Serial.print(dado);
  return dado;
}

void loopDhtFake() {
  String resultado = "";
  resultado += "{";
  String tempNome = "temp";
  String humidNome = "humid";
  float temp = 25.0;
  float humid = 50.0;
  resultado += "'";
  resultado += tempNome;
  resultado += "'";
  resultado += ":";
  resultado += "'";
  resultado += temp;
  resultado += "'";
  resultado += ",";
  resultado += "'";
  resultado += humidNome;
  resultado += "'";
  resultado += ":";
  resultado += "'";
  resultado += humid;
  resultado += "'";
  resultado += ",";
  resultado += "}";
  logSerialLn(resultado);
}

#endif

