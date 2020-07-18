/*********************************************************************
	Rhapsody in C	: 9.0 
	Login		: Victor Hayashi
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: data
//!	Generated Date	: Sat, 18, Jul 2020  
	File Path	: DefaultComponent/DefaultConfig/data.c
*********************************************************************/

/*## auto_generated */
#include "data.h"
/*## package Default */

/*## class data */
void data_Init(data* const me) {
}

void data_Cleanup(data* const me) {
}

data * data_Create(void) {
    data* me = (data *) malloc(sizeof(data));
    if(me!=NULL)
        {
            data_Init(me);
        }
    return me;
}

void data_Destroy(data* const me) {
    if(me!=NULL)
        {
            data_Cleanup(me);
        }
    free(me);
}

/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/data.c
*********************************************************************/
