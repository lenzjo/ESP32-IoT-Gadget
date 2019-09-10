
#ifdef DEBUGLOG
	#define DEBUGPRINT(x)		Serial.print (x)
	#define DEBUGPRINTDEC(x)	Serial.print (x, DEC)
	#define DEBUGPRINTLN(x)		Serial.println (x)
#else
	#define DEBUGPRINT(x)
	#define DEBUGPRINTDEC(x)
	#define DEBUGPRINTLN(x)
#endif

#ifndef SETTINGS_H
	#define SETTINGS_H
	#define LED_BUILTIN 2

	#include <TFT_eSPI.h> 
#endif
