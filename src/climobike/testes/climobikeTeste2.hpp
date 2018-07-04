/*
 *  ClimoBike Teste 2 v0.2.0.2
 *  Grava dados no cartão SD de acordo com o modelo proposto em 
 *  doc/modeloDeDados.md
 *  Depende de:
 *    climobikeLog.hpp
 *    climobikeRelogio.hpp
 *    climobikePersistencia.hpp
 *  Status: FALHANDO na esp32dev v2
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

#ifndef CLIMOBIKETESTE2_HPP
#define CLIMOBIKETESTE2_HPP

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define PROJECT_NAME "climobike";
#define PROJECT_DATA "0.2.0.1";
#define FILETYPE_NAME "json";
#define FILETYPE_DATA "0.1";
#define DATETIME_NAME "datetime";
#define DATETIME_DATA "0";
#define DHT_TEMPERATURE_NAME "tmp";
#define DHT_TEMPERATURE_DATA "25.0";
#define DHT_HUMIDITY_NAME "hum";
/* TODO revalidar valores padrão, por exemplo umidade relativa do ar */
#define DHT_HUMIDITY_DATA "50.0";
#define MQ4_NAME "ch4";
#define MQ4_DATA "4096";
#define MQ135_NAME "tox";
#define MQ135_DATA "4096";
#define MQ7_NAME "co2";
#define MQ7_DATA "4096";
#define GPS_DATETIME_NAME "gpsdate";
#define GPS_DATETIME_DATA "1970-01-01 00:00:00";
#define GPS_LATITUDE_NAME "gpslat";
#define GPS_LATITUDE_DATA "-30.04";
#define GPS_LONGITUDE_NAME "gpslng";
#define GPS_LONGITUDE_DATA "-51.22";
#define GPS_SATELLITES_NAME "gpssat";
#define GPS_SATELLITES_DATA "0";
#define GPS_HDOP_NAME "gpshdop";
#define GPS_HDOP_DATA "9999";
void setupTeste2() {
  setupRelogio();
  /* setupSd() */
  log("Tentando iniciar cartão SD...");
  /* TODO testar cartão para ver se está funcionando aqui, e tratar erros */
  if (SD.begin()) {
    uint8_t cardType = SD.cardType();
    if (cardType == CARD_NONE) {
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
  } else {
    log("Falhou tentando inicializar cartão SD!");
  }
  /* /setupSd() */
}
int loopContador = 0;
bool criarDiretorio(String caminho) {
  if (SD.mkdir(caminho.c_str())) {
    Serial.printf("Criado diretório %s\n", caminho.c_str());
    return true;
  }
  Serial.printf("Erro tentando criar diretório %s\n", caminho.c_str());
  return false;
}
void loopTeste2() {
  delay(500);
  /* loopRelogio() */
  String timestamp = "";
  Serial.print("timestamp: ");
  timestamp += "'";

  Wire.beginTransmission(0x68);
  if (Wire.endTransmission() == 0) {
    datetime = relogio.getDateTime();
    if ((int)datetime.year > 0) {
      timestamp += datetime.year;
      timestamp += "-";
      timestamp += datetime.month;
      timestamp += "-";
      timestamp += datetime.day;
      timestamp += " ";
      timestamp += datetime.hour;
      timestamp += ":";
      timestamp += datetime.minute;
    }
  } else {
    timestamp += "1970-01-01 00:00:00:00"; //mentira
  }
  
  timestamp += "'";
  Serial.print(timestamp);
  Serial.println();
  /* /loopRelogio() */

  /* loopSd() */
  String caminho = "/";
  String nome = "rawData.dat";
  caminho = "/climobike";
  criarDiretorio(caminho);
  caminho += "/dados";
  criarDiretorio(caminho);
  caminho += "/teste2";
  criarDiretorio(caminho);
  caminho += "/";
  caminho += datetime.year;
  criarDiretorio(caminho);
  caminho += "/";
  caminho += datetime.month;
  criarDiretorio(caminho);
  caminho += "/";
  caminho += datetime.day;
  criarDiretorio(caminho);
  caminho += "/";
  caminho += datetime.hour;
  criarDiretorio(caminho);
  nome = datetime.minute;
  nome += ".";
  nome += "txt";
  String completo = "";
  completo += caminho;
  completo += "/";
  completo += nome;

  String mensagem = "";
  mensagem += "{";
  mensagem += '"';
  mensagem += DATETIME_NAME;
  mensagem += '"';
  mensagem += ":";
  mensagem += '"';
  mensagem += datetime.unixtime;
  mensagem += '"';
  mensagem += "}";

  Serial.println("Testando escrita no cartão...");
  if (criarDiretorio(caminho)) {
    File arquivo = SD.open(completo.c_str(), FILE_WRITE);
    Serial.printf("Escrevendo %s no arquivo %s\n", mensagem.c_str(), completo.c_str());
    if (!arquivo) {
      log("Erro tentando abrir o arquivo!");
    } else if (arquivo.println(mensagem.c_str())) {
      log("Arquivo gravado no cartão!");
    } else {
      log("Erro tentando escrever no arquivo!");
    }
  } else {
    Serial.printf("Erro tentando criar diretório %s\n", caminho.c_str());
  }
  /* /loopSd() */

  loopContador++;
  if (loopContador > 1) {
    arquivo.close();
    Serial.println("Lendo conteúdo do arquivo...");
    arquivo = SD.open(completo.c_str());
    while (arquivo.available()) {
      Serial.write(arquivo.read());
    }
    while(true);
  }
}

#endif

