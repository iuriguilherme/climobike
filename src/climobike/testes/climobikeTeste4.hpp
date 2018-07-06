/*
 *  ClimoBike Teste 6 v0.2.0.2
 *  Envia dados para servidor HTTP
 *  Depende de:
 *    climobikeLog.hpp
 *    climobikeWifi.hpp
 *    climobikeHttp.hpp
 *  Status: Testando na esp32dev v1
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

#ifndef CLIMOBIKETESTE4_HPP
#define CLIMOBIKETESTE4_HPP

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

void setupTeste4() {
  setupWifi();
  setupHttp();
}

void loopTeste4() {
//  loopWifi();
  loopHttp();
}

#endif

