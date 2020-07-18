/*********************************************************************
	Rhapsody in C	: 9.0 
	Login		: Victor Hayashi
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: coletor
//!	Generated Date	: Sat, 18, Jul 2020  
	File Path	: DefaultComponent/DefaultConfig/coletor.c
*********************************************************************/

/*## auto_generated */
#include "coletor.h"
/*## package Default */

/*## class Arduinoprogram::coletor */
void coletor_Init(struct coletor_t* const me) {
}

void coletor_Cleanup(struct coletor_t* const me) {
}

struct coletor_t * coletor_Create(void) {
    struct coletor_t* me = (struct coletor_t *) malloc(sizeof(struct coletor_t));
    if(me!=NULL)
        {
            coletor_Init(me);
        }
    return me;
}

void coletor_Destroy(struct coletor_t* const me) {
    if(me!=NULL)
        {
            coletor_Cleanup(me);
        }
    free(me);
}

/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/coletor.c
*********************************************************************/
