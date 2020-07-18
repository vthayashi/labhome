/*********************************************************************
	Rhapsody in C	: 9.0 
	Login		: Victor Hayashi
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: class_2
//!	Generated Date	: Sat, 18, Jul 2020  
	File Path	: DefaultComponent/DefaultConfig/class_2.c
*********************************************************************/

/*## auto_generated */
#include "class_2.h"
/*## package Default */

/*## class class_2 */
void class_2_Init(class_2* const me) {
}

void class_2_Cleanup(class_2* const me) {
}

class_2 * class_2_Create(void) {
    class_2* me = (class_2 *) malloc(sizeof(class_2));
    if(me!=NULL)
        {
            class_2_Init(me);
        }
    return me;
}

void class_2_Destroy(class_2* const me) {
    if(me!=NULL)
        {
            class_2_Cleanup(me);
        }
    free(me);
}

/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/class_2.c
*********************************************************************/
