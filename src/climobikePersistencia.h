/*
 *  ClimoBike Módulo Armazenamento v0.0.2.0
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

#ifndef CLIMOBIKEPERSISTENCIA_H
#define CLIMOBIKEPERSISTENCIA_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <FS.h>
#include <SD.h>
#include <SPI.h>

File file;

void writeFile(const char * message, String arquivo);

void setupSd() {
  Serial.print("Tentando iniciar cartão SD...");

  uint8_t cardType = SD.cardType();
  if (!SD.begin()) {
    Serial.println("falhou!");
  } else if (cardType == CARD_NONE) {
    Serial.println("nenhum cartão detectado!");
  } else {
    Serial.print("Sucesso! Tipo de cartão:");
    if (cardType == CARD_MMC) {
      Serial.print("MMC");
    } else if (cardType == CARD_SD) {
      Serial.print("SDSC");
    } else if (cardType == CARD_SDHC) {
      Serial.print("SDHC");
    } else {
      Serial.print("UNKNOWN");
    }
    Serial.println(".");
    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    Serial.printf("Tamanho do cartão: %lluMB\n", cardSize);
  }

/*  Serial.print(" mentira"); //mentira*/
/*  Serial.println("!");*/
}

void loopSd() {
  String arquivo = "/rawData.dat";
  String gravarDados = "";
  gravarDados += "tempo=";
  gravarDados += millis();

  Serial.print("Testando escrita no cartão...");
  /* TODO testar cartão para ver se está funcionando aqui, e tratar erros */
  writeFile(gravarDados.c_str(), arquivo);
/*  writeFile("Gravei nada em lugar nenhum!"); //mentira*/

}

void writeFile(const char * message, String arquivo) {
  /* TODO testar cartão para ver se está funcionando aqui, e tratar erros */
  file = SD.open(arquivo, FILE_WRITE);
  Serial.println();
  Serial.printf("Escrevendo %s no arquivo: %s\n", message, arquivo.c_str());
  if (!file) {
    Serial.println("Erro tentando abrir o arquivo!");
  } else if (file.println(message)) {
    file.close();
    Serial.println("Sucesso!");
  } else {
    Serial.println("Erro tentando escrever no arquivo");
  }
  file.close();
}

#endif

