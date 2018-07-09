/*
 *  ClimoBike Teste 5 v0.2.0.2
 *  Faz todos os loops do teste original de 3 de julho de 2018,
 *  com dados falsos, e toca Mario no final
 *  Depende de:
 *    climobikeLog.hpp
 *    climobikeBluetooth.hpp
 *    climobikeWifi.hpp
 *    climobikeGps.hpp
 *    climobikeRelogio.hpp
 *    climobikeAnal.hpp
 *    climobikeDht.hpp
 *    climobikePersistencia.hpp
 *    climobikeMario.hpp
 *  Status: nao testado
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

#ifndef CLIMOBIKETESTE5_HPP
#define CLIMOBIKETESTE5_HPP

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

void setupTeste5() {
  setupAnal();
  setupBluetooth();
  setupRelogio();
  setupDht();
  setupWifi();
  setupSd();
  setupHttp();
  setupGps();
  setupMario();
}

void loopTeste5() {
  loopRelogioFake();
  loopDhtFake();
  loopAnalFake();
  loopGpsFake();
  loopMario();
}

#endif

