/*
 *  ClimoBike Módulo de testes v0.0.2.1
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

/*
 *  Teste 0
 *  Faz todos os loops do teste original de 3 de julho de 2018
 *  Depende de:
 *    climobikeLog.hpp
 *    climobikeWifi.hpp
 *    climobikeGps.hpp
 *    climobikeRelogio.hpp
 *    climobikeAnal.hpp
 *    climobikeDht.hpp
 *    climobikePersistencia.hpp
*/
void teste0() {
  loopWifi();
  loopRelogio();
  loopDht();
  loopAnal();
  loopGps();
  loopSd();
}

/*
 *  Teste 1
 *  Faz todos os loops do teste original de 3 de julho de 2018
 *  Quando o sistema inicia, toca a música do Mario
 *  Depende de:
 *    climobikeLog.hpp
 *    climobikeWifi.hpp
 *    climobikeGps.hpp
 *    climobikeRelogio.hpp
 *    climobikeAnal.hpp
 *    climobikeDht.hpp
 *    climobikePersistencia.hpp
 *    climobikeMario.hpp
*/
void teste1() {
  /* Se tudo deu certo */
  setupMario();
  loopMario();
  /* trollface */
  teste0();
}

/*
 *  Teste 2
 *  Grava dados no cartão SD de acordo com o modelo proposto em 
 *  doc/modeloDeDados.md
 *  Depende de:
 *    climobikeLog.hpp
 *    climobikeRelogio.hpp
 *    climobikePersistencia.hpp
*/
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
void teste2() {
  RTCDateTime tempo = agora();

  String arquivoNome = "/climobike/dados/teste2/";
  arquivoNome += tempo.year;
  arquivoNome += "-";
  arquivoNome += tempo.month;
  arquivoNome += "-";
  arquivoNome += tempo.day;
  arquivoNome += "-";
  arquivoNome += tempo.hour;
  arquivoNome += "-";
  arquivoNome += tempo.minute;
  arquivoNome += ".";
  arquivoNome += "txt";

  String linha = "";
  linha += "{";
  linha += '"';
  linha += DATETIME_NAME;
  linha += '"';
  linha += ":";
  linha += '"';
  linha += tempo.unixtime;
  linha += '"';
  linha += "}";
  linha += "\n";

  arquivo = escreveLinhaAbreArquivo(arquivoNome);
  escreveLinha(linha.c_str(), arquivo);
}

#endif

