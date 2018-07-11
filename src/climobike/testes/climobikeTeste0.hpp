/*
 *  ClimoBike Teste 0 v0.2.0.2
 *  Faz todos os loops do teste original de 3 de julho de 2018
 *  Depende de:
 *    climobikeLog.hpp
 *    climobikeWifi.hpp
 *    climobikeGps.hpp
 *    climobikeRelogio.hpp
 *    climobikeAnal.hpp
 *    climobikeDht.hpp
 *    climobikePersistencia.hpp
 *  Status: funcionando na esp32dev v2
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

#ifndef CLIMOBIKETESTE0_HPP
#define CLIMOBIKETESTE0_HPP

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

int count=0;

SdCard sd;
ClimobikeRelogio Relogio;
ClimobikeWiFi Wifi;

void setupTeste0() {
  setupAnal();
  setupBluetooth();
  Relogio.setupRelogio();
  setupDht();
  Wifi.setupWifi();
  sd.setupSd();
  setupHttp();
  GPS.setupGps();
}
void loopTeste0() {
  Wifi.loopWifi();
  Relogio.loopRelogio();
  //loopDht();
  loopAnal();
  GPS.loopGps();
  if(count<20)
  {
    sd.loopSd(loopDht());
    count++;
  }
  else
  {
    sd.escreveLinhaFechaArquivo(sd.arquivo);
    Serial.println("deu");
  }
}

#endif

