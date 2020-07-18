/*********************************************************************
	Rhapsody in C	: 9.0 
	Login		: Victor Hayashi
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: celular
//!	Generated Date	: Sat, 18, Jul 2020  
	File Path	: DefaultComponent/DefaultConfig/celular.h
*********************************************************************/

#ifndef celular_H
#define celular_H

/*## auto_generated */
#include <oxf/Ric.h>
/*## auto_generated */
#include "Default.h"
/*## classInstance pagina */
#include "htm.h"
/*## package Default */

/*## class celular */
typedef struct celular celular;
struct celular {
    struct htm pagina;		/*## classInstance pagina */
};

/***    User implicit entries    ***/


/* Constructors and destructors:*/

/*## auto_generated */
void celular_Init(celular* const me);

/*## auto_generated */
void celular_Cleanup(celular* const me);

/*## auto_generated */
struct htm* celular_getPagina(const celular* const me);

/*## auto_generated */
celular * celular_Create(void);

/*## auto_generated */
void celular_Destroy(celular* const me);

#endif
/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/celular.h
*********************************************************************/
