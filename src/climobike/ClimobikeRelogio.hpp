/*
 *  ClimoBike Módulo Relógio v0.2.0.2
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

#ifndef CLIMOBIKERELOGIO_HPP
#define CLIMOBIKERELOGIO_HPP

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define EPOCH "1970-01-01 00:00:00"

/* TODO incluir no platformio.ini */
#include <DS1307.h>
#include <Wire.h>
#include "ClimobikeLog.hpp"



class ClimobikeRelogio
{
  public:
  	DS1307 relogio;
	RTCDateTime actualtime;
	ClimobikeLog LogRelogio;

    void setupRelogio() ;

    void loopRelogio() ;

    /* Grava a data atual do computador no momento da compilação no relógio */
    void atualizaHora() ;
    String getDatetime();
    String getTimeStamp();
    int getHour();
    int getMinute();

};
#endif
