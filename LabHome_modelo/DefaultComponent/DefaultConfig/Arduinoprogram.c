/*********************************************************************
	Rhapsody in C	: 9.0 
	Login		: Victor Hayashi
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Arduinoprogram
//!	Generated Date	: Sat, 18, Jul 2020  
	File Path	: DefaultComponent/DefaultConfig/Arduinoprogram.c
*********************************************************************/

/*## auto_generated */
#include "Arduinoprogram.h"
/*## package Default */

/*## class Arduinoprogram */
void Arduinoprogram_Init(Arduinoprogram* const me) {
}

void Arduinoprogram_Cleanup(Arduinoprogram* const me) {
}

struct Arduinoprogram* Arduinoprogram_getColetor(const Arduinoprogram* const me) {
    return (struct Arduinoprogram*)&(me->coletor);
}

struct var* Arduinoprogram_getDados_coletados(const Arduinoprogram* const me) {
    return (struct var*)&(me->dados_coletados);
}

struct filesystem* Arduinoprogram_getFiles(const Arduinoprogram* const me) {
    return (struct filesystem*)&(me->files);
}

struct var* Arduinoprogram_getParam(const Arduinoprogram* const me) {
    return (struct var*)&(me->param);
}

struct webserver* Arduinoprogram_getServer(const Arduinoprogram* const me) {
    return (struct webserver*)&(me->server);
}

Arduinoprogram * Arduinoprogram_Create(void) {
    Arduinoprogram* me = (Arduinoprogram *) malloc(sizeof(Arduinoprogram));
    if(me!=NULL)
        {
            Arduinoprogram_Init(me);
        }
    return me;
}

void Arduinoprogram_Destroy(Arduinoprogram* const me) {
    if(me!=NULL)
        {
            Arduinoprogram_Cleanup(me);
        }
    free(me);
}

/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/Arduinoprogram.c
*********************************************************************/
