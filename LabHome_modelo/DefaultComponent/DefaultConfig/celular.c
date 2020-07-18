/*********************************************************************
	Rhapsody in C	: 9.0 
	Login		: Victor Hayashi
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: celular
//!	Generated Date	: Sat, 18, Jul 2020  
	File Path	: DefaultComponent/DefaultConfig/celular.c
*********************************************************************/

/*## auto_generated */
#include "celular.h"
/*## package Default */

/*## class celular */
void celular_Init(celular* const me) {
}

void celular_Cleanup(celular* const me) {
}

struct htm* celular_getPagina(const celular* const me) {
    return (struct htm*)&(me->pagina);
}

celular * celular_Create(void) {
    celular* me = (celular *) malloc(sizeof(celular));
    if(me!=NULL)
        {
            celular_Init(me);
        }
    return me;
}

void celular_Destroy(celular* const me) {
    if(me!=NULL)
        {
            celular_Cleanup(me);
        }
    free(me);
}

/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/celular.c
*********************************************************************/
