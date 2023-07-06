#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dico.h"
char lireCaractere()
{
    char caractere=0;
    caractere=getchar();
    caractere=toupper(caractere);
    while(getchar()!='\n');
    return caractere;
}

int gagne (int lettreTrouve[],int tailleMot)

{
    int i = 0;
    int joueurGagne=1;
      for(i=0;i<tailleMot;i++)
            {
            if (lettreTrouve[i]==0)
                {
                 joueurGagne=0;

                }
            }
 return joueurGagne;
}

int rechercheLettre(char lettre, char motSecret[],int lettreTrouvee[])
{
    int i=0;
    int bonneLettre=0;
    for (i=0;motSecret[i] !='\0';i++)
        {
          if (lettre == motSecret[i])
            {
             bonneLettre=1;
              lettreTrouvee[i]=1;

            }
        }
        return bonneLettre;
}
int main()
{
    char lettre = 0;
    char motSecret[100]={0};
    int *lettreTrouvee=NULL;
    int coupsRestants=10;
    int i=0;
    int tailleMot;
  if(!piocherMot(motSecret))
    exit(0);


   tailleMot=strlen(motSecret);
   lettreTrouvee=malloc(tailleMot *sizeof(int));
   if (lettreTrouvee==NULL)
    exit(0);
   for (i=0;i<tailleMot;i++)
    lettreTrouvee[i]=0;

    printf("bienvenue das le pendu ! \n\n");

    while(coupsRestants>0 && !gagne(lettreTrouvee,tailleMot))
        {
         printf("\n\n il vous reste %d coups a jouer ",coupsRestants);
        printf(" \n\n quel est le mot secret ? ");


        for(i=0;i<tailleMot;i++)
            {
            if (lettreTrouvee[i]==1)
                {
                 printf("%c",motSecret[i]);

                }else
                {
                 printf("*");

                }

            }

        printf("\n proposez une lettre : ");
        lettre=lireCaractere();
        if (rechercheLettre(lettre,motSecret,lettreTrouvee)==0)
            {

            coupsRestants--;
            }



        }
        if (gagne(lettreTrouvee,tailleMot)==1)

            {
              printf("\n\n gagne !!!! le mot secret etait bien : %s",motSecret);
            }
        else
            {
            printf("\n\n perdu !!!! le mot secret etait : %s",motSecret);

            }



return 0;
}

