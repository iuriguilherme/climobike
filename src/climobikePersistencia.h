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

void writeFile(const char * message);

void setupSd() {
  Serial.print("Tentando iniciar cartão SD...");
//  uint8_t cardType = SD.cardType();

//  if (!SD.begin()) {
//    Serial.println("Card Mount Failed");
//    return;
//  }
//  if (cardType == CARD_NONE) {
//    Serial.println("No SD card attached");
//    return;
//  }

//  Serial.print("SD Card Type: ");
//  if (cardType == CARD_MMC) {
//    Serial.println("MMC");
//  } else if (cardType == CARD_SD) {
//    Serial.println("SDSC");
//  } else if (cardType == CARD_SDHC) {
//    Serial.println("SDHC");
//  } else {
//    Serial.println("UNKNOWN");
//  }

//  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
//  Serial.printf("SD Card Size: %lluMB\n", cardSize);

//  file = SD.open("/rawData.dat", FILE_WRITE);
  Serial.print(" mentira"); //mentira
  Serial.println("!");
}

void loopSd() {
  writeFile("Gravei nada em lugar nenhum!");
}

void writeFile(const char * message) {
//  Serial.printf("Writing file: %s\n", "/rawData.dat");
//  if (!file) {
//    Serial.println("Failed to open file for writing");
//    return;
//  }
//  if (file.println(message)) {
//    Serial.println("File written");
//  } else {
//    Serial.println("Write failed");
//  }
  Serial.println(message); //mentira
}

#endif

