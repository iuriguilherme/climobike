/*
 *  ClimoBike Módulo de testes v0.2.0.2
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

#ifndef CLIMOBIKETESTES_HPP
#define CLIMOBIKETESTES_HPP

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/* Pausa o programa */
void fim() {
  while(true);
}

#include <climobike/testes/climobikeTeste0.hpp>
/* depende de Teste0 */
#include <climobike/testes/climobikeTeste1.hpp>
#include <climobike/testes/climobikeTeste2.hpp>
#include <climobike/testes/climobikeTeste3.hpp>

#endif

