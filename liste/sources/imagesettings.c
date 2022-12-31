#include "../headers/imagesettings.h"


pixel** Read(char* image){  //double pointer??
    FILE *filed;
    filed = fopen(image, "r"); // on attribue à filed
    char NombreMagique[3];
    char largeurImage[TAILLE];  // On store la largeur et la hauteur donnée par la deuxième ligne du fichier PBM
    char hauteurImage[TAILLE];

    if(filed==NULL)    // if file exists
    {
        raler(1,"image inexistante");
    }

    fscanf(filed,"%s",NombreMagique); // take Magic key
    if(strcmp(NombreMagique,MAGICPBM)!=0)    // compare magic key of image
    {
        raler(0,"ceci n'est pas un PBM");
    }

    fscanf(filed,"%s %s",largeurImage,hauteurImage);
    hauteur[0]= atoi(hauteurImage);
    largeur[0]= atoi(largeurImage);


    pixel **bidpx=(pixel**)malloc(hauteur[0]*sizeof(pixel*)); // 2D array allocation

    for (int i = 0; i < hauteur[0]; i++) {
        bidpx[i] =(pixel*) malloc(largeur[0] * sizeof(pixel));    // methode 2d array
    }

    int tmp;
    for (int i = 0; i <hauteur[0] ; i++) {
        for (int j = 0; j <largeur[0] ; j++) {
            fscanf(filed,"%1d",&tmp); // one value at a time

             if(tmp!=0 && tmp!=1)
             {
                 raler(1,"pixel couleur");
             }

             makeset(&bidpx[i][j],tmp);
        }
    }
    fclose(filed);
    return bidpx;
}



void Write(pixel** dpx, int hauteur, int largeur, char* image) {    // tableau bidimensionnel
    FILE* filed;
    int Red,Green,Blue; // var to hold the values of color

    filed = fopen(image, "w");
    if (filed == NULL)
        raler(1, " error: fopen ");

    fprintf(filed,MAGICPPM);
    fprintf(filed,"\n%d %d\n",largeur,hauteur);
    fprintf(filed,"255\n");    // color bound

    for(int col=0;col<hauteur;col++){
        for(int row=0;row<largeur;row++){
            if(row%70==0){    // if more than 70 chars
                fprintf(filed,"\n");
            }

            Red=Findset(&dpx[col][row])->couleur[0];
            Green=Findset(&dpx[col][row])->couleur[1];
            Blue=Findset(&dpx[col][row])->couleur[2];
            fprintf(filed,"%d %d %d ",Red,Green,Blue);  // print inside the image file
        }
    }
    fclose(filed);
}




void Generate(int n,int m,char* image)
{
    FILE* filed;
    filed=fopen(image,"w");

    if(filed==NULL)
    {
        raler(1,"Erreur lors de la création du fichier ");
    }
    fprintf(filed,"%s\n", MAGICPBM);
    fprintf(filed,"%d %d\n", n,m);

    for (int row = 0; row < n ;row++) { // height
        for (int col = 0; col <m ; col++) { // width
            if(col%70==0) {    // if more than 70 chars
                fprintf(filed, "\n");
            }
            fprintf(filed,"%d", rand()%2);
        }
    }
    fclose(filed);
}



void Coloriage(pixel** array)
{   // we iterate through the bidimensionnal table

    for (int i = 0; i < hauteur[0]; i++)
    {   // we iterate through the heigth

        for (int j = 0; j < largeur[0]; j++)
        {   // we iterate through the width

            if ((array[i][j].couleur[0] != 0) && (array[i][j].couleur[1] != 0) && (array[i][j].couleur[2] != 0))   //First check
            {   // if the pixel is colored different than black , do the following

                if (i < hauteur[0] - 1)
                {
                    // Check Connexes Horizontal
                    if (((array[i + 1][j].couleur[0] != 0) && (array[i + 1][j].couleur[1] != 0)
                         && (array[i + 1][j].couleur[2] != 0))
                        && Findset(&array[i][j]) != Findset(&array[i + 1][j]))
                    {
                        // if the two pixels are not in the same set , we do union of those two
                        Union(&array[i][j], &array[i + 1][j]);
                    }
                }


                if (j < largeur[0] - 1)
                {

                    // Check Connexes Vertical
                    if (((array[i][j + 1].couleur[0] != 0) && (array[i][j + 1].couleur[1] != 0) // if not black
                         && (array[i][j + 1].couleur[2] != 0))
                        && Findset(&array[i][j]) != Findset(&array[i][j + 1]))
                    {
                        // if the two pixels are not in the same set , we do union of those two
                        Union(&array[i][j], &array[i][j + 1]);
                    }
                }
            }
        }
    }
}


void liberer(pixel**bd)
{
    for (int i = 0; i < hauteur[0]; i++) {
        free(bd[i]);
    }
    free(bd);
}
