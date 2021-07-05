#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int langage_L2(char* w)
{

    int i=0;
    int test=1 ;
    int longeur=strlen(w);

    if (w[i] != 'a' || w[longeur]!= 'b')
    { // si permier caracatere != a , ou la dernier caractere != b return 0
            test = 0;
    }

    for (i = 0; i <= longeur - 1; i = i + 2)
    {
        if (w[i]=='a' && w[i+1]=='b')
        { // si chaque a est suivi d'un b return 2
            test = 2;

        }

        else
        {
            return 0;
        }
    }
    return test;

}

/*----------------------------------------------------------------------------------------------------------------------------------------*/
void langage_L2_option()
{
    char w1[25];
    printf("Entrez un mot que contient l'alphabet {a,b} svp : ");
    scanf("%s",w1);

    if ( langage_L2(w1) == 2)
    {   // si la deuxieme conditon vrai
        printf (" Ce mot (%s) appartient a la langage L2 ",w1);
    }

    else
    {   // les autre cases
        printf (" Ce mot (%s) n'appartient pas a la langage L2 !!!  ",w1);}
    }

int main()
{
    langage_L2_option();

    return 0;
}
