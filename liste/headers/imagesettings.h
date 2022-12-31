#include "liste.h"
//#include "structarbre.h"



#define TAILLE 8

int hauteur[1];
int largeur[1];

//void raler (int sys, const char * msg);

/**
 * @brief reads attributes of the image given
 *        such as the ---- magic key --- the height and width of the table
 *        and the table itself. then the function stores the table in another
 *        table bidimensionel assigning each white pixel a randomly generated color.
 *
 * @param image given argv[1].
 * @return new table bidimensional.
 */
pixel** Read(char* image);

/**
 * @brief  the function creates a new PPM ASCII file image with attributes
 *         such as the magic key --- the bidimensional table we created---
 *
 * @param pixels thee newly created bidimensionel table
 * @param hauteur  height of the image argv[1]
 * @param largeur  width of the image read before argv[1]
 * @param image
 * @return none
 */
void Write(pixel** dpx, int hauteur, int largeur, char* image);

/**
 * @brief  The function generates an PBMASCII image in black and white randomly.
 *
 * @param n width of the image
 * @param m height of the image
 * @param image the name of the image that will be generated.
 * @return none
 */
void Generate(int n,int m,char* image);



/**
 * @brief The coloriage function calls the functions that are needed to color the image
 * The function first goes through the bidimensionnal table of pixels ,
 * then unites the neighbors of the pixels when the conditions detailed in the commentaries of the function are met.
 *
 * @param array the bidimensional table that was initialized in Read.
 * @return null
 */
void Coloriage(pixel**array);



/**
 *@brief free the bidimensionnal table and the pixel sets
 *@param bd the bidimensional table
 *@return null
 */
void liberer(pixel**bd);


