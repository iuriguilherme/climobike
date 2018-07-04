/*
 *  ClimoBike Módulo Armazenamento v0.0.2.1
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

#ifndef CLIMOBIKEPERSISTENCIA_HPP
#define CLIMOBIKEPERSISTENCIA_HPP

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/* TODO incluir no platformio.ini */
#include <FS.h>
#include <SD.h>
#include <SPI.h>

File arquivo;
void escreve(const char * mensagem, String nome);
File escreveLinhaAbreArquivo(String nome);
bool escreveLinhaFechaArquivo(File arquivo);
void escreveLinha(const char * mensagem, File arquivo);

void setupSd() {
  log("Tentando iniciar cartão SD...");
  /* TODO testar cartão para ver se está funcionando aqui, e tratar erros */
  uint8_t cardType = SD.cardType();
  if (!SD.begin()) {
    log("Falhou tentando inicializar cartão SD!");
  } else if (cardType == CARD_NONE) {
    log("Nenhum cartão SD detectado!");
  } else {
    Serial.print("\nSucesso! Tipo de cartão: ");
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
//  Serial.print(" mentira!"); // TODO mentira
}

void loopSd() {
  String arquivo = "/rawData.dat";
  String gravarDados = "";
  gravarDados += "tempo=";
  gravarDados += millis();

  Serial.println("Testando escrita no cartão...");
  /* TODO testar cartão para ver se está funcionando aqui, e tratar erros */
  escreve(gravarDados.c_str(), arquivo);
//  escreve("Gravei nada em lugar nenhum!"); // TODO mentira

}

/* Escreve no cartão de memória */
void escreve(const char * mensagem, String nome) {
  /* TODO testar cartão para ver se está funcionando aqui, e tratar erros */
  File arquivo = SD.open(nome, FILE_WRITE);
  Serial.printf("Escrevendo %s no arquivo: %s\n", mensagem, nome.c_str());
  if (!arquivo) {
    log("Erro tentando abrir o arquivo!");
  } else if (arquivo.println(mensagem)) {
    log("Arquivo gravado no cartão!");
  } else {
    log("Erro tentando escrever no arquivo!");
  }
  arquivo.close();
}
File escreveLinhaAbreArquivo(String nome){
  arquivo = SD.open(nome, FILE_WRITE);
  return arquivo;
}
bool escreveLinhaFechaArquivo(File arquivo){
  arquivo.close();
  return !arquivo;
}
void escreveLinha(const char * mensagem, File arquivo) {
  if (!arquivo) {
    log("Erro tentando abrir o arquivo!");
  } else if (arquivo.print(mensagem)) {
    log("Arquivo gravado no cartão!");
  } else {
    log("Erro tentando escrever no arquivo!");
  }
}

#endif

