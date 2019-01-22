/**
 *  TITLE       : Assignment for C Programming for MSc
 *  EXAM NUMBER : Y3863809
 ************************************************************************************/

#include "golf.h"

int main(void) {

    GOLF golf;

    golf_init(&golf);

    //golf_update returns 0 when the game shall quit. Ex. User clicked Exit button
    while(golf_update(&golf)) {

        golf_paint(&golf);

        pausefor(1);
    }

    golf_destroy(&golf);

    return 0;
}
