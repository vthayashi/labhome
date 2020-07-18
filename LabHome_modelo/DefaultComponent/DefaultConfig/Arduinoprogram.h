/*********************************************************************
	Rhapsody in C	: 9.0 
	Login		: Victor Hayashi
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Arduinoprogram
//!	Generated Date	: Sat, 18, Jul 2020  
	File Path	: DefaultComponent/DefaultConfig/Arduinoprogram.h
*********************************************************************/

#ifndef Arduinoprogram_H
#define Arduinoprogram_H

/*## auto_generated */
#include <oxf/Ric.h>
/*## auto_generated */
#include "Default.h"
/*## classInstance files */
#include "filesystem.h"
/*## classInstance dados_coletados */
#include "var.h"
/*## classInstance server */
#include "webserver.h"
/*## package Default */

/*## class Arduinoprogram */
typedef struct Arduinoprogram Arduinoprogram;
struct Arduinoprogram {
    struct var dados_coletados;		/*## classInstance dados_coletados */
    struct filesystem files;		/*## classInstance files */
    struct var param;		/*## classInstance param */
    struct webserver server;		/*## classInstance server */
    struct Arduinoprogram coletor;		/*## classInstance coletor */
};

/***    User implicit entries    ***/

/* Constructors and destructors:*/

/*## auto_generated */
void Arduinoprogram_Init(Arduinoprogram* const me);

/*## auto_generated */
void Arduinoprogram_Cleanup(Arduinoprogram* const me);

/*## auto_generated */
struct Arduinoprogram* Arduinoprogram_getColetor(const Arduinoprogram* const me);

/*## auto_generated */
struct var* Arduinoprogram_getDados_coletados(const Arduinoprogram* const me);

/*## auto_generated */
struct filesystem* Arduinoprogram_getFiles(const Arduinoprogram* const me);

/*## auto_generated */
struct var* Arduinoprogram_getParam(const Arduinoprogram* const me);

/*## auto_generated */
struct webserver* Arduinoprogram_getServer(const Arduinoprogram* const me);

/*## auto_generated */
Arduinoprogram * Arduinoprogram_Create(void);

/*## auto_generated */
void Arduinoprogram_Destroy(Arduinoprogram* const me);

#endif
/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/Arduinoprogram.h
*********************************************************************/
