/*
 *  ClimoBike Teste 0 v0.2.0.2
 *  Faz todos os loops do teste original de 3 de julho de 2018
 *  Depende de:
 *    climobikeLog.hpp
 *    climobikeWifi.hpp
 *    climobikeGps.hpp
 *    climobikeRelogio.hpp
 *    climobikeAnal.hpp
 *    climobikeDht.hpp
 *    climobikePersistencia.hpp
 *  Status: funcionando na esp32dev v2
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

#ifndef CLIMOBIKETESTE0_HPP
#define CLIMOBIKETESTE0_HPP

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

int count=0;

SdCard sd;
ClimobikeRelogio Relogio;
ClimobikeWiFi Wifi;
float aleartorio=0,dadoFicticio=0;
String dadoGps;
String nomeArquivo;
bool test=false;

int hour=25,minute=00;
String temp,hum;
void novoArquivoDados()
{
  if(sd.arquivo)
  {
    sd.fechaArquivo(sd.arquivo);
  }
  hour=Relogio.getHour();
  minute=Relogio.getMinute();
  nomeArquivo="/dados/";
  nomeArquivo+=Relogio.getDatetime();
  nomeArquivo+=".json";
  sd.abreArquivo(nomeArquivo);
}

void setupTeste0() {
  setupAnal();
  setupBluetooth();
  Relogio.setupRelogio();
  setupDht();
  Wifi.setupWifi();
  sd.setupSd();
  setupHttp();
  GPS.setupGps();
  novoArquivoDados();
}
void loopTeste0() {
  Wifi.loopWifi();
  Relogio.loopRelogio();
  //loopDht();
  //loopAnal();
  dadoGps=GPS.loopGps();
  if(!(Relogio.actualtime.minute==minute+10 && Relogio.actualtime.hour==hour)&&(sd.arquivo))
  {
    //delay(1000);
    aleartorio=millis();
    sd.loopSd("","init");
    sd.loopSd(Relogio.getTimeStamp(),"timestamp");

    sd.loopSd((String)getMetan(),"CH4");
    sd.loopSd((String)getMonca(),"CO");
    sd.loopSd((String)getToxic(),"NH3");
    temp=(String)dht.getTemperature();
    hum=(String)dht.getHumidity();
    if(temp!="nan")
      sd.loopSd(temp,"temp");
    if(hum!="nan")
      sd.loopSd(hum,"hum");
    dadoFicticio=aleartorio/3;

    dadoFicticio=aleartorio/5;

    if(dadoGps!="")
    {
      sd.loopSd(GPS.getLatitude(),"lat");
      sd.loopSd(GPS.getLongitude(),"long");
      //sd.loopSd(dadoGps,"GPS");
      //test=true;
      tocaGPS();
    }
    sd.loopSd((String)getLdr(),"ldr");


    count++;
  }
  else
  {
    Serial.println("deu");
    novoArquivoDados();
  }
}

#endif
