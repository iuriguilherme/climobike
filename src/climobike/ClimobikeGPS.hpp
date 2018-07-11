/*
 *  ClimoBike Módulo GPS v0.2.0.2
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

#ifndef CLIMOBIKEGPS_H
#define CLIMOBIKEGPS_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/*
 * SoftwareSerial para ESP32 ou não funcionando conforme nossa expectativa, ou
 * não conseguimos fazer funcionar. Na ausência do SoftwareSerial, vamos usar
 * HardwareSerial que deveria estar contida na biblioteca Arduino.
*/
//#include <SoftwareSerial.h>

#include <TinyGPS++.h>

class ClimobikeGPS
{
public:
  //SoftwareSerial ss(RXPin, TXPin);
  
  TinyGPSPlus gps;

  /* ESP32 */
  static const int gpsRxPin = 16;
  static const int gpsTxPin = 17;
  static const uint32_t gpsBaud = 9600;

  String dadosGps();

  void setupGps();

  void loopGps();
};
#endif

