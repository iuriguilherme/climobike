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
#define PROJECT_DATA "0.2.0.2";
#define FILETYPE_NAME "json";
#define FILETYPE_DATA "0.2";
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

int limite = 3;
int loopContador = 0;
bool criarDiretorio(String caminho);
bool loopTeste2RelogioBool();
String loopTeste2RelogioString();
//Sd2Card cartao;
//SdVolume volume;
//SdFile sd;
bool setupTeste2SdBool();
//void listarArquivos();

void setupTeste2() {
  setupRelogio();
  /* setupSd() hipotético */
  if (!setupTeste2SdBool()) {
    falha("Falha tentando usar o cartão SD");
  }
//  else {
//    listarArquivos();
//  }
}

void loopTeste2() {
  delay(500);

  /* Nome do arquivo */
  String caminho = "/sd";
  String nome = "/rawData.dat";

  caminho = "dados";
  criarDiretorio(caminho);
  caminho += "/";
  caminho += "teste2";
  criarDiretorio(caminho);
  caminho += "/";
  if (loopTeste2RelogioBool()) {
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
    caminho += "/";
    caminho += datetime.minute;
    criarDiretorio(caminho);
  } else {
    caminho += "erro";
    criarDiretorio(caminho);
  }
  criarDiretorio(caminho);

  nome = datetime.second;
  nome += ".";
  nome += "txt";

  String completo = "";
  completo += "/";
  completo += caminho;
  completo += "/";
  completo += nome;

  /* Linha que será gravada em arquivo */
  String linha = "";
  linha += "{";
  if (loopTeste2RelogioBool()) linha += loopTeste2RelogioString();
  linha += "}";

  /* Escreve linha no cartão */
  log("Tentando escrever no cartão...");
  if (!SD.exists(caminho)) {
    log("Caminho %s não existe!", caminho);
  }
  if (!SD.exists(completo)) {
    log("Arquivo %s não existe!", completo);
  }
  File arquivo = SD.open(completo, FILE_WRITE);
  log("Escrevendo %s", linha);
  log(" no arquivo %s\n", completo);
  if (!arquivo) {
    log("Erro tentando abrir o arquivo!");
  } else if (arquivo.println(linha)) {
    log("Arquivo gravado no cartão!");
  } else {
    log("Erro tentando escrever no arquivo!");
  }

  loopContador++;
  if (loopContador >= limite) {
    arquivo.close();
    log("Lendo conteúdo do arquivo...");
    arquivo = SD.open(completo, FILE_READ);
    while (arquivo.available()) {
      Serial.write(arquivo.read());
    }
    while(true);
  }
}

bool criarDiretorio(String caminho) {
  if (SD.mkdir(caminho)) {
    log("Criado diretório %s\n", caminho);
    return true;
  }
  log("Erro tentando criar diretório %s\n", caminho);
  return false;
}

bool loopTeste2RelogioBool() {
  Wire.beginTransmission(0x68);
  if (Wire.endTransmission() == 0) {
    datetime = relogio.getDateTime();
    return true;
  } else {
    falha("Não conseguimos ver que horas são");
    return false;
  }
  return false;
}

String loopTeste2RelogioString() {
  String retorno = "";
  retorno += '"';
  retorno += DATETIME_NAME;
  retorno += '"';
  retorno += ":";
  retorno += '"';
  retorno += datetime.unixtime;
  retorno += '"';
  retorno += ",";
  return retorno;
}

bool setupTeste2SdBool() {
  logSerial("Tentando iniciar SD...");
  if (!SD.begin()) {
    falha(" falhou! Tentando inicializar módulo SD");
  }
//  if (!cartao.init()) {
//    falha(" falhou! Tentando inicializar cartão SD");
//  }
//  if (cartao.type() == CARD_NONE) {
//    falha(" falhou! Nenhum cartão SD detectado");
//  }
//  if (!volume.init(cartao)) {
//    falha(" falhou! Cartão SD não formatado ou problema inicializando volume");
//  }
  log(" sucesso!");
  return true;
}

//void listarArquivos() {
//  sd.openRoot(volume);
//  sd.ls(LS_R | LS_DATE | LS_SIZE);
//}

#endif

