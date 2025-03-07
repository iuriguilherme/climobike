/*
 *  ClimoBike Módulo de log v0.2.0.2
 *  Board:  esp32dev (v1, v2)
 *  Authors:
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

#ifndef CLIMOBIKELOG_H
#define CLIMOBIKELOG_H


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
class ClimobikeLog
{
public:
/* Escreve no USB */
	void logSerial(String mensagem);
	void logSerialF(char * mensagem, String formato);
	void logSerialLn(String mensagem);
	void log(String mensagem);
	void log(char * mensagem, String formato);
};
#endif

