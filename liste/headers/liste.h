#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define MAGICPPM "P3"
#define MAGICPBM "P1"

/**
* @brief Stops on error , system (open:etc.) or logic (incorrect magic /etc)
* function taken from the "Programmation Systeme" class.
*
* @param sys (0) ou (1)
* @param msg Message to display
* @return null_
*/
void raler (int sys, const char * msg);


 typedef struct pixel {
    int couleur[3];
    struct pixel* next;
    struct Liste* ensemble;    // pointe vers l'enssemble qu'il appartient
}pixel;


typedef struct Liste
{
    pixel* head;
    pixel* tail;
    // additional var maybe needed
    int size;
}Liste;



/**
* @brief creates a new set Sx giving a random color RGB[3] to the pixel
* @param pixel px
* @return null_
*/
void makeset(pixel* px,int color);



/**
 * @brief Returns the head of the set that px belongs too
 * @param px
 * @return pixel* Head of the set
 */
pixel* Findset(pixel* px);



/**
 * @brief Unites two sets of pixels in one set.
 * This function takes the two sets of pixels and assembles the content of the second one into the first one
 *
 * @param racpx1
 * @param racpx2
 * @return null_
 */

void Union(pixel* rpx1,pixel* rpx2);    // représentant d'ensemble





