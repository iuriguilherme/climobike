/*
 *  ClimoBike Módulo Gases v0.2.0.2
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

#ifndef CLIMOBIKEANAL_H
#define CLIMOBIKEANAL_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <driver/adc.h>

float metan,toxic,monca;
ClimobikeLog LogAnal;
void setupAnal() {
  Serial.print("Tentando iniciar sensores analógicos de gases tóxicos...");
  adc_power_on();
  adc_gpio_init(ADC_UNIT_1,ADC_CHANNEL_0);
  adc_gpio_init(ADC_UNIT_1,ADC_CHANNEL_6);
  adc_gpio_init(ADC_UNIT_1,ADC_CHANNEL_5);
  adc_gpio_init(ADC_UNIT_1,ADC_CHANNEL_4);
  adc1_config_width(ADC_WIDTH_12Bit);
  adc1_config_channel_atten(ADC1_CHANNEL_6,ADC_ATTEN_11db);
  adc1_config_channel_atten(ADC1_CHANNEL_5,ADC_ATTEN_11db);
  adc1_config_channel_atten(ADC1_CHANNEL_4,ADC_ATTEN_11db);
  adc1_config_channel_atten(ADC1_CHANNEL_0,ADC_ATTEN_11db);
  Serial.print(" feito");
  Serial.println("!");
}

float getMetan()
{
  return adc1_get_raw(ADC1_CHANNEL_5);
}

float getMonca()
{
  return adc1_get_raw(ADC1_CHANNEL_6);
}

float getToxic()
{
  return adc1_get_raw(ADC1_CHANNEL_4);
}

float getLdr()
{
  return adc1_get_raw(ADC1_CHANNEL_0);
}

void loopAnal() {
  /* Metano MQ4 */
  Serial.print("ch4: ");
  metan = adc1_get_raw(ADC1_CHANNEL_6);
  delay(300);
  Serial.print(metan);
/*  Serial.print("bastante"); //mentira*/
  Serial.println();
//  printServer("CH4",metan);
  /* Gases tóxicos */
  Serial.print("no: ");
  toxic = adc1_get_raw(ADC1_CHANNEL_5);
  delay(300);
  Serial.print(toxic);
/*  Serial.print("pouco"); //mentira*/
  Serial.println();
//  printServer("NO",toxic);
  Serial.print("co: ");
  monca = adc1_get_raw(ADC1_CHANNEL_4);
  delay(300);
  Serial.print(monca);
/*  Serial.print("mais ou menos"); //mentira*/
  Serial.println();
//  printServer("CO",monca);
}

void loopAnalFake() {
  String resultado = "";
  resultado += "{";
  /* Metano MQ4 */
  String metanNome = "ch4";
  metan = 42;
  resultado += "'";
  resultado += metanNome;
  resultado += "'";
  resultado += ":";
  resultado += "'";
  resultado += metan;
  resultado += "'";
  resultado += ",";
  delay(300);
  /* Gases tóxicos */
  String toxicNome = "no1";
  toxic = 42;
  resultado += "'";
  resultado += toxicNome;
  resultado += "'";
  resultado += ":";
  resultado += "'";
  resultado += toxic;
  resultado += "'";
  resultado += ",";
  delay(300);
  /* Dioxido de Carbono */
  String moncaNome = "co2";
  monca = 42;
  resultado += moncaNome;
  resultado += "'";
  resultado += ":";
  resultado += "'";
  resultado += monca;
  resultado += "'";
  resultado += ",";
  delay(300);
  resultado += "}";
  LogAnal.logSerialLn(resultado);
}

#endif
