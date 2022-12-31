 
#include "../headers/imagesettings.h"



int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        fprintf (stderr, "Usage: %s\n", argv[0]);
        return EXIT_FAILURE;
    }
    else {
        clock_t start =clock(); // pour le test de performances

        srand(time(NULL));
        pixel **pixel;

        pixel = Read(argv[1]);
        Coloriage(pixel);
        Write(pixel,hauteur[0],largeur[0],argv[2]);
        liberer(pixel);
        clock_t end =clock();
        printf("\nTIME:%f\n",(double)(end-start)/CLOCKS_PER_SEC);


    }

        return (EXIT_SUCCESS);


}