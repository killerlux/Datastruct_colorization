#include "../headers/liste.h"


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
    Liste* liste;
    liste=malloc(sizeof(Liste));
    liste->head=px;
    liste->tail=px;


    px->next=NULL;
    px->ensemble=liste;

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
    liste->size=1;
}




pixel* Findset(pixel* px)
{
    if(px==NULL)
    {
        return NULL;
    }
    return px->ensemble->head;  // head of list(enssemble)
}





void Union(pixel* rpx1,pixel* rpx2)    // pixels
{                                        // {p}{p2}->{p,p2}
                                        // {p,p1,p2}{p5}->{p,p1,p2,p5}
    struct Liste* set1;
    struct Liste* set2;
    set1 = rpx1->ensemble;
    set2 = rpx2->ensemble;


    if(Findset(rpx1)==Findset(rpx2))    // if disjoint -> return nothing
    {
        return;
    }


    if (set1->size>=set2->size)
    {
        set1->tail->next=set2->head;    // pointing Tail of set(rpx1) to the head of set(rpx2)
        pixel* tmp = set2->head;

        while(tmp->next!=NULL)  // traverse set(rpx2) till meeting (Tail)
        {
            tmp->ensemble=set1;    // assigning to all pixels from set(px2) to the set(rpx1)
            tmp=tmp->next;
        }

        tmp->ensemble=set1; // asigning the last element of the set2 to the set1
        rpx1->ensemble->tail=tmp;   // making the tail of set1 point to the last eleement of set2 -> tmp
        set1->size+=set2->size; // add size(update)

        free(set2);

    }else
    {
        set2->tail->next=set1->head;    // pointing Tail of set(rpx1) to the head of set(rpx2)
        pixel* tmp = set1->head;

        while(tmp->next!=NULL)  // traverse set(rpx2) till meeting (Tail)
        {
            tmp->ensemble=set2;    // assigning to all pixels from set(px2) to the set(rpx1)
            tmp=tmp->next;
        }

        tmp->ensemble=set2; // asigning the last element of the set2 to the set1
        set2->tail=tmp;   // making the tail of set1 point to the last eleement of set2 -> tmp
        set2->size+=set1->size; // add size(update)

        free(set1);
    }
}


