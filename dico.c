#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dico.h"

int piocherMot(char *motPioche)
{
    FILE* dico=NULL;
    int nombreMots=0,numMotsChoisi=0,i=0;
    int caractereLu=0;
    dico=fopen("dico.txt","r");
    if (dico==NULL){

        printf("impossible de cheger le dictioner des mots");
    }
    do{ caractereLu=fgetc(dico);
        if (caractereLu=='\n')
            nombreMots++;
      }while(caractereLu!=EOF);

    numMotsChoisi=nombreAleatoire(nombreMots);
    rewind(dico);
    while(numMotsChoisi>0)
        {
         caractereLu=fgetc(dico);
         numMotsChoisi--;


        }
        fgets(motPioche,100,dico);
        motPioche[strlen(motPioche)-1]='\0';
        fclose(dico);
        return 1;


}

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return(rand()%nombreMax);
}
