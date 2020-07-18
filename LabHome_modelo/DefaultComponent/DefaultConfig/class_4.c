/*********************************************************************
	Rhapsody in C	: 9.0 
	Login		: Victor Hayashi
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: class_4
//!	Generated Date	: Sat, 18, Jul 2020  
	File Path	: DefaultComponent/DefaultConfig/class_4.c
*********************************************************************/

/*## auto_generated */
#include "class_4.h"
/*## package Default */

/*## class class_4 */
void class_4_Init(class_4* const me) {
}

void class_4_Cleanup(class_4* const me) {
}

class_4 * class_4_Create(void) {
    class_4* me = (class_4 *) malloc(sizeof(class_4));
    if(me!=NULL)
        {
            class_4_Init(me);
        }
    return me;
}

void class_4_Destroy(class_4* const me) {
    if(me!=NULL)
        {
            class_4_Cleanup(me);
        }
    free(me);
}

/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/class_4.c
*********************************************************************/
