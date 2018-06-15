

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>


const int chipSelect = 4;

File dataFile;
String dataString;

int configure()
{
	Serial.begin(9600);
	dataFile = SD.open("log.txt", FILE_WRITE);
	if (! dataFile) 
	{
    	Serial.println("error opening datalog.txt");
    	return 0;
    }
    else
    	return 1;
}

int main()
{
	init();
	if(!configure())
	{
		Serial.print("\nDeu ruim\n");
	}

	while(1)
	{
		dataString="Vai  pra porra \n";
		Serial.println(dataString);
		dataFile.println(dataString);
	}
}