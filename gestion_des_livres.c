#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//structure de nouvelle type que sappele livre :

typedef struct
{
    char titre[100];
    char euteur[100];
    float  prix;
    int quantite;
}library;

library livre[100];

int menu ;
int compteur = 0;

//un fonction de menu : ajoute , modifier , supremer , rechercher , trier , static , quit :

int menu_principal()
{
    int choix;
    printf("menu : \n");
    printf("1 => ajoute\n2 => modifier \n3 => supremer \n4 => rechercher \n5 => trie\n 6 => static\n7 => quit\n");
    printf("veuilles entrer votre choix : ");
    scanf("%d", &choix);
    return choix;

}

//un fonction de ajouter : le titre , le euteur , le prix , le quantite:

void ajoute()
{
        int menu_ajoute;
        int taille;
        printf("1 => ajoute un element \n2 => ajoute plusieur \n3 => reteur=> : ");
        scanf("%d", &menu_ajoute);
        if(menu_ajoute == 1)
        {
            taille = 1;
        }
        else if(menu_ajoute == 2)
        {
            printf("veuillez entrer combiene livre ajouter : ");
            scanf("%d", &taille);
        }


        for(int i=0;i<taille;i++)
        {
            printf("veuillez entrer le titere de livre : ");
            scanf("%s", livre[i].titre);
            printf("veuillez entrer le euteur de livre : ");
            scanf("%s", livre[i].euteur);
            printf("veuillez entrer le prix de livre  : ");
            scanf("%f", &livre[i].prix);
            printf("veuillez entrer le quantite : ");
            scanf("%d", &livre[i].quantite);
            compteur++;
        }
}


//un fonction de modifier : modifier le quantite :
void modifier ()
{
    char titre_modif[100];
    printf("veuille entrer le titre : ");
    scanf("%s", titre_modif);
    for(int i=0 ; i<compteur;i++)
    {
        if(strcmp(titre_modif,livre[i].titre)==0)
        {
            printf("veuillez entrer le nouvelle quantite : ");
            scanf("%d", &livre[i].quantite);
        }
    }

}
//un fonction de supremer : supreme un element et rechercher par titre:
void supremer()
{
    char titre_supr[100];
    printf("veuillez entrer le titre qeu vous supr");
    scanf("%s", titre_supr);
    for(int i=0; i<compteur;i++)
    {

        if(strcmp(titre_supr,livre[i].titre)==0)
        {
            livre[i] = livre[i + 1];
        }
    }
}
//un fonction de trie : tri par croisson , ordr croisson :
void tri()
{
    int choix ;
    library tmp;
    printf("1 => croisson \n2 => decroisson \n");
   printf("veuillez entrer voter choix : ");
   scanf("%d", &choix);
   if(choix == 1)
   {

       for(int i =0 ; i<compteur -1 ; i++)
       {
           for(int j = i+1 ; j < compteur ;j++)
           {
                if(strcmp(tolower(livre[i].titre),tolower(livre[j].titre))>0)
                {
                 tmp = livre[i];
                 livre[i]=livre[j];
                 livre[j]=tmp;
                }
           }
       }
   }


}

//un fonction de static:
void statistics()
{
    float prix_general;
    float sum = 0;
    for(int i=0 ; i<compteur;i++)
    {
        sum = sum+livre[i].prix;
    }
    prix_general = sum/compteur;
printf("le qauntite general des livres est : %d", compteur);
printf("le moyane general de prix est : %d", prix_general);
}

//un fonction de afichage : aficher le titre , le euteur , le prix , le quantite :
void afficher ()
{
    for(int i=0;i<compteur;i++)
    {
        printf("le titre : %s | l'auteur : %s | le prix : %f | le quantite : %d |\n", livre[i].titre, livre[i].euteur , livre[i].prix , livre[i].quantite);
    }
}

int main ()
{
    char x[]={"Ismail"};
    printf("%s", to_lowercase(x));
    
    
    
    
    
    
    
    return 0;
}