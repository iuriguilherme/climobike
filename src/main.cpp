/*
 *  ClimoBike v0.2.0.2
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

#include <climobike/climobikeLog.hpp>
#include <climobike/climobikeBluetooth.hpp>
#include <climobike/climobikeWifi.hpp>
#include <climobike/climobikeHttp.hpp>
#include <climobike/climobikeGps.hpp>
#include <climobike/climobikeAnal.hpp>
#include <climobike/climobikeDht.hpp>
#include <climobike/climobikeMario.hpp>
/* depende de Log */
#include <climobike/climobikeRelogio.hpp>
/* depende de Log */
#include <climobike/climobikePersistencia.hpp>
/*
 *  depende de Log, Bluetooth, Wifi, Gps, Anal, Dht, Relogio, Persistencia, 
 *  Mario
*/
#include <climobike/climobikeTestes.hpp>

void setup(){
  delay(1000);
  Serial.begin(9600);

//  setupAnal();
//  setupBluetooth();
//  setupRelogio();
//  setupDht();
//  setupWifi();
//  setupSd();
//  setupHttp();
//  setupGps();

//  setupTeste0();
//  setupTeste1();
//  setupTeste2();
//  setupTeste3();
//  setupTeste4();
  setupTeste5();
}

void loop() {
//  loopTeste0();
//  loopTeste1();
//  loopTeste2();
//  loopTeste3();
//  loopTeste4();
  loopTeste5();
}

