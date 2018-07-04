/*
 *  ClimoBike Teste 0 v0.2.0.1
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

void setupTeste0() {
  setupAnal();
  setupBluetooth();
  setupRelogio();
  setupDht();
  setupWifi();
  setupSd();
  setupHttp();
  setupGps();
}
void loopTeste0() {
  loopWifi();
  loopRelogio();
  loopDht();
  loopAnal();
  loopGps();
  loopSd();
}

#endif

