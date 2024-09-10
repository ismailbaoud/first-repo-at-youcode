#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure de nouvelle type que sappele livre :

typedef struct
{
    char titre[100];
    char auteur[100];
    float  prix;
    int quantite;
}library;

library livre[100];

int menu ;


//un fonction de menu : ajoute , modifier , supremer , rechercher , trier , static ,afficher , quit :

int menu_principal()
{
    int choix;
    printf("\nmenu : \n");
    printf("1 => ajoute\n2 => modifier \n3 => supremer \n4 => rechercher \n5 => trie\n6 => static\n7 => afficher \n8 => quit\n");
    printf("veuilles entrer votre choix : ");
    scanf("%d", &choix);
    return choix;

}

//un fonction de ajouter : le titre , l'auteur , le prix , le quantite:
int compteur = 0;

void ajoute()
{
    int menu_ajoute;
    int nombre;
    printf("1 => ajoute un element \n2 => ajoute plusieur \n3 => reteur\n=> : ");
    scanf("%d", &menu_ajoute);
    switch(menu_ajoute)
    {
    case 1 : nombre = 1;
    break;
    case 2 :  printf("veuillez entrer combiene livre ajouter : ");
            scanf("%d", &nombre);
            
    break;
    case 3 : printf("reture en ceur...\n");
    break;
    }
    for(int i=compteur;i<compteur+nombre;i++)
    {
        printf("veuillez entrer le titere de livre : ");
        scanf("%s", livre[i].titre);
        printf("veuillez entrer le euteur de livre : ");
        scanf("%s", livre[i].auteur);
        printf("veuillez entrer le prix de livre  : ");
        scanf("%f", &livre[i].prix);
        printf("veuillez entrer le quantite : ");
        scanf("%d", &livre[i].quantite);
    }
    compteur=compteur+nombre;
    

}



//un fonction de modifier : modifier le quantite :
void modifier ()
{
    afficher ();

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
    afficher ();

}
//un fonction de supremer : supreme un element et rechercher par titre:
void supremer()
{
    afficher ();

    char titre_supr[100];
    printf("veuillez entrer le titre qeu vous supr");
    scanf("%s", titre_supr);
    for(int i=0; i<compteur;i++)
    {

        if(strcmp(titre_supr,livre[i].titre)==0)
        {
            strcpy(livre[i].titre,livre[i+1].titre);
            strcpy(livre[i].auteur,livre[i+1].auteur);
            livre[i].prix=livre[i+1].prix;
            livre[i].quantite=livre[i+1].quantite;
           // livre[i] = livre[i + 1];
           compteur--;
            
        }
        
    }
    afficher ();
}
//un fonction de trie : tri par croisson , ordr croisson :
void tri()
{
    afficher ();
    int choix ;
    library tmp;
    printf("1 => croisson \n2 => decroisson \n3 => reture \n");
   printf("veuillez entrer voter choix : ");
   scanf("%d", &choix);
   switch(choix)
   {

      case 1 : for(int i =0 ; i<compteur -1 ; i++)
       {
           for(int j = i+1 ; j < compteur ;j++)
           {
                if(strcmp(strlwr(livre[i].titre),strlwr(livre[j].titre))>0)
                {
                    tmp = livre[i];
                    livre[i]=livre[j];
                    livre[j]=tmp;
                }
           }
       }
       break;
   
    case 2 : for(int i =0 ; i<compteur -1 ; i++)
            {
                for(int j = i+1 ; j > compteur ;j++)
                {
                    if(strcmp(strlwr(livre[i].titre),strlwr(livre[j].titre))>0)
                    {
                        tmp = livre[i];
                        livre[i]=livre[j];
                        livre[j]=tmp;
                    }
                }
              }
    case 3 : break;

   }
   afficher ();


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
printf("le qauntite general des livres est : %d\n", compteur);
printf("le moyane general de prix est : %.2f\n", prix_general);
}
//un fonction de recherche : titre :
void rechercher ()
{
    char titre_rechercher[100];
    printf("veuillez entrer le titre de votre recherche");
    scanf("%s", titre_rechercher);
    for(int i = 0; i<compteur; i++)
    {
        if(strcmp(titre_rechercher,livre[i].titre)==0)
        {
            printf("le titre : %s | l'auteur : %s | le prix : %.2f | le quantite : %d |\n", livre[i].titre, livre[i].auteur , livre[i].prix , livre[i].quantite);
        }
    }



}


//un fonction de afichage : aficher le titre , le euteur , le prix , le quantite :
void afficher ()
{
    for(int i=0;i<compteur;i++)
    {
        printf("le titre : %s | l'auteur : %s | le prix : %.2f | le quantite : %d |\n", livre[i].titre, livre[i].auteur , livre[i].prix , livre[i].quantite);
    }
}

int main ()
{
    
    do{
        int choix = menu_principal();
        switch(choix)
        {
            case 1 : ajoute();
            break;
            case 2 : modifier ();
            break;
            case 3 : supremer();
            break;
            case 4 : rechercher ();
            break;
            case 5 : tri();
            break;
            case 6 : statistics();
            break;
            case 7 : afficher ();
            break;
            case 8 : printf("exiting....");
            exit(0);
        }

        

    }while(1);

    return 0;
}
