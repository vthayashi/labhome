/*********************************************************************
	Rhapsody in C	: 9.0 
	Login		: Victor Hayashi
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: class_3
//!	Generated Date	: Sat, 18, Jul 2020  
	File Path	: DefaultComponent/DefaultConfig/class_3.c
*********************************************************************/

/*## auto_generated */
#include "class_3.h"
/*## package Default */

/*## class class_3 */
void class_3_Init(class_3* const me) {
}

void class_3_Cleanup(class_3* const me) {
}

class_3 * class_3_Create(void) {
    class_3* me = (class_3 *) malloc(sizeof(class_3));
    if(me!=NULL)
        {
            class_3_Init(me);
        }
    return me;
}

void class_3_Destroy(class_3* const me) {
    if(me!=NULL)
        {
            class_3_Cleanup(me);
        }
    free(me);
}

/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/class_3.c
*********************************************************************/
