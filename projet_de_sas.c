#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int annee;
    int jour;
    int mois;
    
}date;

typedef struct {
    char nom[100];

    char prenom[100];
    char departement[100];
    float note_general;
    date date_de_naissance;
    int nombre_uniqeu ;
}Etudiant;

Etudiant les_etudiant[100];
int compteur=0;

// *********************************************************************************************************************************
                                                   /*fonction de ajouter*/
//********************************************************************************************************************************** 
//fonction de ajoute : numero unique , nom , prenom , date de naissance , departement , note general :
void ajouter()
{

    int taille ;
    int nombre_detudiant; 
    int test = 0;
    printf("menu : \n");
    printf("1 => ajouter un etudiant \n2 => ajouter plusieur \n3 => reteur\n");
    printf("veuillez entrer votre choix");
    scanf("%d", &nombre_detudiant);
    switch(nombre_detudiant)
    {
        case 1 :  taille = 1;
            break;
    
    
        case 2 :  printf("veuillez entrer combien des etudiants: ");
                scanf("%d", &taille);
            break;
        case 3 : test = 1;
        break;
        default : printf("non choix ...");
        break;
    }
    if(test == 0)
    {
        for(int i = compteur ; i<compteur+taille; i++)
        {
            int choix;
            printf("veuillez entrer le nom: ");
            scanf("%s", les_etudiant[i].nom);
            printf("veuillez entrer le prenom: ");
            scanf("%s", les_etudiant[i].prenom);
            printf("veuillez entrer la note general: ");
            scanf("%f", &les_etudiant[i].note_general);
            printf("veuillez entrer la date de nessons(YYYY/MM/DD): \n");
            
            do
            {
                printf("=> l'anne de naissance(YYYY) : ");
                scanf("%d", &les_etudiant[i].date_de_naissance.annee);
            }while(les_etudiant[i].date_de_naissance.annee>2020 || les_etudiant[i].date_de_naissance.annee<1900);
            
            do
            {
                printf("=> le mois de naissance (MM): ");
                scanf("%d", &les_etudiant[i].date_de_naissance.mois);
            }while(les_etudiant[i].date_de_naissance.mois>12 || les_etudiant[i].date_de_naissance.mois<1);
            
            do
            {
                printf("=> le jour de naissance (JJ): ");
                scanf("%d", &les_etudiant[i].date_de_naissance.jour);
            }while(les_etudiant[i].date_de_naissance.jour>31 || les_etudiant[i].date_de_naissance.jour<1);
            
            printf("veuillez entrer votre departempent : \n");
            printf("1=> svt \n2=> chariaa \n3=> fst: ");
            scanf("%d", &choix);
            switch(choix)
            {
                case 1 : strcpy(les_etudiant[i].departement,"svt");
                break;
                case 2 : strcpy(les_etudiant[i].departement,"chariaa");
                break;
                case 3 : strcpy(les_etudiant[i].departement,"fst");
                break;
                default : printf("ne pas trouve");
                break;
            }
            les_etudiant[i].nombre_uniqeu = i+1;
        
        }
    }
    compteur+=taille;
}
//*******************************************************************************************************************************
                                                   /*fonction de affichage*/ 
//*******************************************************************************************************************************
void afficher()
{
    if(compteur != 0)
    {
        for(int i=0;i<compteur;i++)
        {
            printf("le nombre d'Etudient : %d   |\n", les_etudiant[i].nombre_uniqeu);
            printf("le nom : %s |le prenom : %s |\n",les_etudiant[i].nom,les_etudiant[i].prenom);
            printf("la note general est : %.2f  |\n",les_etudiant[i].note_general);
            printf("la date de naissance est :  |\n");
            printf("annee : %d /mois : %d /jour : %d|", les_etudiant[i].date_de_naissance.annee,les_etudiant[i].date_de_naissance.mois,les_etudiant[i].date_de_naissance.jour);

            
        }
    }
    else
    {
        printf("non etudient ....\n");
        
    }

}
//******************************************************************************************************************************* 
                                                   /*fonction de modifier*/
//*******************************************************************************************************************************
//fonction modifier : 
void modifier()
{
    int choix; 
    int id;
    printf("veuillez entrer qeu vous modifier : ");
    printf("1 => le nom \n2 => le prenom \n3 => la note general\n4 =>date de naissance \n5 => departement\n");
    printf("veuillez entrer votre chiox : ");
    scanf("%d", &choix);
    printf("entrer le id : ");
    scanf("%d", &id);
    if(compteur !=0)
    {
        for(int i = 0; i<compteur;i++)
        {
            if(id == les_etudiant[i].nombre_uniqeu)
            {
                switch(choix)
                {  
                    case 1 : printf("veuillez entrer le nouvelle nom : ");
                    scanf("%s", les_etudiant[i].nom );
                    break;
                    case 2 : printf("veuillez entrer le nouvelle prenom : ");
                    scanf("%s", les_etudiant[i].prenom );
                    break;
                    case 3 : printf("veuillez entrer le nouvelle note general : ");
                    scanf("%s", les_etudiant[i].note_general );
                    break;
                    case 4 : printf("entrer votre choix : \n");
                    printf("1 => modifier anne\n2 => modifier mois\n3 => modifier jour");
                    scanf("%d", &choix);
                        switch(choix)
                        {
                        case 1 : printf("veuillez entrer la nouvelle annee : ");
                            scanf("%d", &les_etudiant[i].date_de_naissance.annee);
                        break;
                        case 2 : printf("veuillez entrer la nouvelle mois : ");
                            scanf("%d", &les_etudiant[i].date_de_naissance.mois);
                        break;
                        case 3 : printf("veuillez entrer la nouvelle jour : ");
                            scanf("%d", &les_etudiant[i].date_de_naissance.jour);
                        break;
                        default : printf("no trouve pas...");
                        break;
                    }
                
                    break;
                    case 5 :
                    printf("veuillez entrer le nouvelle choix : \n");
                    printf("1=> svt \n2=> chariaa \n3=> fst: ");
                    scanf("%d", &choix);
                    switch(choix)
                    {

                        case 1 : strcpy(les_etudiant[i].departement,"svt");
                        break;
                        case 2 : strcpy(les_etudiant[i].departement,"chariaa");
                        break;
                        case 3 : strcpy(les_etudiant[i].departement,"fst");
                        break;
                        default : printf("ne pas trouve");
                        break;
                    }
                    break;

                    default : printf("non choix ...");
                    break;
                }
            }
        }
    }
    else 
    {
        printf("non etudiant....");
    }
    
}
//******************************************************************************************************************************* 
                                                   /*fonction de supremer*/
//*******************************************************************************************************************************
//fonction de supremer :
void supremer()
{
    char nom_detudiant[100];
    printf("veuille entrer le nom d'etudiant : ");
    scanf("%s", nom_detudiant);
    for(int i = 0; i<compteur;i++)
    {
        if(strcmp(nom_detudiant,les_etudiant[i].nom)==0)
        {
            strcpy(les_etudiant[i].nom,les_etudiant[i+1].nom);
            strcpy(les_etudiant[i].prenom,les_etudiant[i+1].prenom);
            les_etudiant[i].date_de_naissance.annee=les_etudiant[i+1].date_de_naissance.annee;
            les_etudiant[i].date_de_naissance.mois=les_etudiant[i+1].date_de_naissance.mois;
            les_etudiant[i].date_de_naissance.jour=les_etudiant[i+1].date_de_naissance.jour;
            compteur--;
        }
    }
    
}
//*******************************************************************************************************************************
                                                   /*fonction de moyenne general*/ 
//*******************************************************************************************************************************
float svt = 0;
float chariaa = 0;
float fst = 0;
float general = 0;

int compteur_svt = 0;
int compteur_chariaa = 0;
int compteur_fst = 0;

void moyenne_general()
{
    
    float sum_1 = 0;
    float sum_2 = 0;
    float sum_3 = 0;
    float sum_general = 0;
    for(int i = 0; i<compteur;i++)
    {
        if(strcmp("fst",les_etudiant[i].departement)==0)
        {
            sum_1 = sum_1+les_etudiant[i].note_general;
            compteur_fst++;
            
        }
        else if(strcmp("svt",les_etudiant[i].departement)==0)
        {
            sum_2 = sum_2+les_etudiant[i].note_general;
            compteur_svt++;
            
        }
        else if(strcmp("chariaa",les_etudiant[i].departement)==0)
        {
            sum_3 = sum_3+les_etudiant[i].note_general;
            compteur_chariaa++;
            
        }
    
      sum_general=sum_general+les_etudiant[i].note_general;

    }

    fst = sum_1/compteur_svt;
    svt = sum_2/compteur_chariaa;
    chariaa = sum_3/compteur_fst;
    general = sum_general/compteur;
}
//******************************************************************************************************************************* 
                                                   /*fonction de statistics*/
//******************************************************************************************************************************* 

void statistics()
{
    Etudiant tmp;
    int choix;
    int choix_2;
    printf("menu de tri : \n");
    printf("1 => tri alphabitique : \n2 => tri par moyenne general : \n3 => tri par reussite : \n");
    printf("veuillez entrer votre choix : \n");
    scanf("%d", &choix);
    switch(choix)
    {
       case 1 : 
       printf("1 => croissant (a-z): \n2 => decroissant (z-a) : \n => : ");
       scanf("%d", &choix_2);
        switch(choix_2)
        {
            case 1 :

            for(int i=0; i<compteur-1;i++)
            {
                for(int j=i+1;i<compteur;i++)
                {
                    if(strcmp(les_etudiant[i].nom,les_etudiant[j].nom)>0)
                    {
                        tmp = les_etudiant[i];
                        les_etudiant[i]=les_etudiant[j];
                        les_etudiant[j]=tmp;
                    }

                }
                
            }
            break;
            case 2 :
            for(int i=0; i<compteur-1;i++)
            {
                for(int j=i+1;i<compteur;i++)
                {
                    if(strcmp(les_etudiant[i].nom,les_etudiant[j].nom)<0)
                    {
                        tmp = les_etudiant[i];
                        les_etudiant[i]=les_etudiant[j];
                        les_etudiant[j]=tmp;
                    }

                }
            }
            break;
        }
        break;
        case 2 :
        printf("1 => plus eleve au plus faible (10-1)\n2 => plus faible au plus eleve (1-10) \n=>");
        scanf("%d",&choix_2);
        switch(choix_2)
        {
            case 1 : 
           
            for(int i=0; i<compteur-i;i++)
            {
                for(int j=0;i<compteur;i++)
                {
                    if(les_etudiant[j].note_general<les_etudiant[j+1].note_general)
                    {
                        tmp = les_etudiant[j];
                        les_etudiant[j]=les_etudiant[j+1];
                        les_etudiant[j+1]=tmp;
                        
                    }
                }
            }
            break;
            case 2 : 
            for(int i=0; i<compteur-1;i++)
            {
                for(int j=0;i<compteur - i -1;i++)
                {
                    if(les_etudiant[j].note_general>les_etudiant[j+1].note_general)
                    {
                        tmp = les_etudiant[j];
                        les_etudiant[j]=les_etudiant[j+1];
                        les_etudiant[j+1]=tmp;

                    }
                }
            }
            break;


        }
        case 3 : 
        

    }
}
//******************************************************************************************************************************* 
                                                   /*fonction de recherche*/
//*******************************************************************************************************************************
void recherche()
{
    char choix[100];
    printf("veuillez entrer le nom : ");
    scanf("%s", choix);

    for(int i = 0;i<compteur;i++)
    {
        if(strcmp(choix,les_etudiant[i].nom)==0)
        {
            printf("le nom : %s |le prenom : %s | la note general : %.2f |\n",les_etudiant[i].nom,les_etudiant[i].prenom,les_etudiant[i].note_general);
            printf("la date de naissance : %d / %d / %d|le nombre d'etudiant : %d|\n", les_etudiant[i].date_de_naissance.annee,les_etudiant[i].date_de_naissance.mois,les_etudiant[i].date_de_naissance.jour,les_etudiant[i].nombre_uniqeu);
            printf("le deoartement : %s |\n", les_etudiant[i].departement);

        }
    }
}
//******************************************************************************************************************************* 
                                                   /*fonction de 3 note*/
//*******************************************************************************************************************************
void les_3_note()
{
    Etudiant tmp;
    for(int i=0; i<compteur-i;i++)
    {
        for(int j=0;i<compteur;i++)
            {
            if(les_etudiant[j].note_general<les_etudiant[j+1].note_general)
            {
                tmp = les_etudiant[j];
                les_etudiant[j]=les_etudiant[j+1];
                les_etudiant[j+1]=tmp;
                        
            }
        }
    }
    if(compteur > 2)
    {
        for(int i = 0;i<3;i++)
        {
            printf("*************************");
            printf("*************************");
            printf("|le nom est : %s |\n", les_etudiant[i].nom);
            printf("|le prenom est : %s |\n", les_etudiant[i].prenom);
            printf("|la note est : %.2f |\n", les_etudiant[i].note_general);
            printf("la date de naissance est : \n");
            printf("|l'annee est : %d |\n", les_etudiant[i].date_de_naissance.annee);
            printf("|le jour est : %d |\n",les_etudiant[i].date_de_naissance.jour);
            printf("|le mois est : %d |\n",les_etudiant[i].date_de_naissance.mois);
            printf("*************************");
            printf("*************************");
        }
    }

}
//******************************************************************************************************************************* 
                                                   /*fonction de main*/
//*******************************************************************************************************************************
int main ()
{
    int choix;
    do{
        
        printf("|****************************************|\n");
        printf("|               **le menu **             |\n");
        printf("|****************************************|\n");
        printf("|      veuillez entrer votre choix       |\n");
        printf("|****************************************|\n");

        printf("1 => ajouter \n2 => modifier \n3 => supremer \n4 => afficher \n5 => le moyenne general\n6 => statistics \n7 => recherche \n8 => tri \n");
        printf("veuillez entrer votre choix : ");
        scanf("%d", &choix);
        switch(choix)
        {
            case 1 : ajouter();
            break;
            case 2 : modifier();
            break;
            case 3 : supremer();
            break;
            case 4 : afficher();
            break;
            case 5 :
            break;
            case 6 :
            break;
            case 7 :
            break;
            case 8 :
            break;
            default :
            break;
        }
    }while(choix != 0);
}

