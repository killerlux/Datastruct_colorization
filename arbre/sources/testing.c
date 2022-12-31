#include "../headers/structarbre.h"

void raler (int sys, const char * msg)
{
    if (sys == 0)
        fprintf (stderr, "erreur: %s\n", msg);
    else
        perror (msg);
    exit (EXIT_FAILURE);
}

void makeset(pixel* px,int color)// int color param
{
    px->father=px;
    px->rang=0;

    // color randomizer

    if (color!=1) // black nothing white do
    {
        px->couleur[0]=rand()%255+1;    // (R)->assign each color - rand(0-255)
        px->couleur[1]=rand()%255+1;    // (G)->assign each color - rand(0-255)
        px->couleur[2]=rand()%255+1;    // (B)->assign each color - rand(0-255)
    }
    else       // if black pixel leave it as it is
    {
        px->couleur[0]=0;   // (R)->assign each color - 0
        px->couleur[1]=0;   // (G)->assign each color - 0
        px->couleur[2]=0;   // (B)->assign each color - 0
    }
}


pixel* Findset(pixel* px)
{
    if(px==NULL)
    {
        return NULL;
    }
    pixel*tmp=px;
    while(tmp->father!=tmp)
    {
        tmp=tmp->father;
    }
    return tmp;  // head of list(racine de l'arbre)
}






void Union(pixel* racpx1,pixel* racpx2)    //  pixels
{

    if(racpx1==NULL || racpx2==NULL)    // if non existint -> return nothing
    {
        return;
    }

    if(Findset(racpx1)==Findset(racpx2))    // if disjoint -> return nothing
    {
        return;
    }

    pixel *tmpx= Findset(racpx1);
    pixel *tmpy= Findset(racpx2);

    tmpy->father=tmpx;

    if (tmpx->rang==tmpy->rang)
    {
        tmpx->rang++;
    }
    else if (tmpx->rang < tmpy->rang)
    {
        tmpx->rang= tmpx->rang=(tmpy->rang)+1;
    }

}


int main(){
    srand(time(NULL));

    pixel* px1= malloc(sizeof(pixel));
    makeset(px1,0);
    pixel* px2= malloc(sizeof(pixel));
    makeset(px2,0);
    pixel* px3= malloc(sizeof(pixel));
    makeset(px3,0);
    pixel* px4= malloc(sizeof(pixel));
    makeset(px4,0);
    printf("%d %d %d\n",  px1->couleur[0],px1->couleur[1],px1->couleur[2]);
    printf("%d %d %d\n",  px2->couleur[0],px2->couleur[1],px2->couleur[2]);
    printf("%d %d %d\n",  px3->couleur[0],px3->couleur[1],px3->couleur[2]);
    printf("%d %d %d\n",  px4->couleur[0],px4->couleur[1],px4->couleur[2]);



    Union(px1,px2);


    pixel* head = Findset(px2);
    printf("%d %d %d\n", head->couleur[0],head->couleur[1],head->couleur[2]);
    printf("%d %d %d\n",  px2->couleur[0],px2->couleur[1],px2->couleur[2]);
    
}

