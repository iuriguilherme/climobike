/*
 *  ClimoBike v0.0.2.1
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

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <climobikeLog.hpp>
#include <climobikeBluetooth.hpp>
#include <climobikeWifi.hpp>
#include <climobikeGps.hpp>
#include <climobikeAnal.hpp>
#include <climobikeDht.hpp>
#include <climobikeMario.hpp>
/* depende de Log */
#include <climobikeRelogio.hpp>
/* depende de Log */
#include <climobikePersistencia.hpp>
/* depende de Log, Relogio, Persistencia */
#include <climobikeTestes.hpp>

void setup(){
  delay(300);
  Serial.begin(9600);
//  setupAnal();
//  setupBluetooth();
  setupRelogio();
//  setupDht();
//  setupWifi();
  setupSd();
//  setupHttp();
//  setupGps();
}

void loop() {
//  teste0();
//  teste1();
  teste2();
}

