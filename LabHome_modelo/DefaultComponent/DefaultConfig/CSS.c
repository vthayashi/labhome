/*********************************************************************
	Rhapsody in C	: 9.0 
	Login		: Victor Hayashi
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CSS
//!	Generated Date	: Sat, 18, Jul 2020  
	File Path	: DefaultComponent/DefaultConfig/CSS.c
*********************************************************************/

/*## auto_generated */
#include "CSS.h"
/*## package Default */

/*## class CSS */
void CSS_Init(CSS* const me) {
}

void CSS_Cleanup(CSS* const me) {
}

CSS * CSS_Create(void) {
    CSS* me = (CSS *) malloc(sizeof(CSS));
    if(me!=NULL)
        {
            CSS_Init(me);
        }
    return me;
}

void CSS_Destroy(CSS* const me) {
    if(me!=NULL)
        {
            CSS_Cleanup(me);
        }
    free(me);
}

/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/CSS.c
*********************************************************************/
