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
    int couleur[3]; // premier param
    int rang;      // deuxieme param hauteur
    struct pixel *father;    // pixel pere
}pixel;

/**
* @brief creates a new set Sx giving a random color RGB[3] to the pixel
* @param pixel px
* @return null_
*/
void makeset(pixel* px,int color);


/**
 * @brief locates node with px and moves up tree to find root
 * @param px
 * @return pixel* Root of the tree
 */
pixel* Findset(pixel* px);


/**
 * @brief appends tree of second parameter as a child of tree of first parameter
 * This function takes the two sets of pixels and assembles the content of the second one into the first one
 *
 * @param racpx1
 * @param racpx2
 * @return null_
 */
void Union(pixel* racpx1,pixel* racpx2);    // représentant d'ensemble

