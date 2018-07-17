/*
 *  ClimoBike Módulo Armazenamento v0.2.0.2
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

#ifndef SDCARD_HPP
#define SDCARD_HPP

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/* TODO incluir no platformio.ini */
#include <FS.h>
#include <SD.h>
#include <SPI.h>
#include "ClimobikeLog.hpp"
class SdCard
{
public:
  File arquivo;
  void escreve(const char * mensagem, String nome);
  File abreArquivo(String nome);
  bool fechaArquivo(File arquivo);
  void escreveLinha(const char * mensagem, File arquivo);
  void setupSd();
  void loopSd(String dado, String tipoDado);
};
#endif
