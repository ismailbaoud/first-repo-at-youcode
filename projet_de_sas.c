#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int annee;
    int jour;
    int mois;

} date;

typedef struct
{
    char nom[100];
    char prenom[100];
    char departement[100];
    float note_general;
    date date_de_naissance;
    int nombre_uniqeu;
} Etudiant;

//*******************************************************************************************************************************
/*fonction de etudiant */
//*******************************************************************************************************************************
Etudiant les_etudiant[500] = {
    {"ismail", "baoud", "mathematiques", 19.5, {2004, 20, 10}, 1},
    {"baoud", "ismail", "mathematiques", 17.0, {2000, 27, 9}, 2},
    {"ahmad", "ali", "physique", 7.8, {2007, 11, 12}, 3},
    {"ilyas", "banani", "chimie", 16.2, {2002, 9, 10}, 4},
    {"achraf", "hamouda", "physique", 13.7, {2003, 6, 2}, 5},
    {"karim", "alaoui", "chimie", 18.5, {2001, 10, 7}, 6},
    {"haitam", "abod", "chimie", 9.4, {2002, 19, 1}, 7},
    {"hatim", "karim", "mathematiques", 15.9, {2005, 12, 2}, 8},
    {"salma", "hasson", "physique", 14.3, {2003, 21, 9}, 9},
    {"sanaa", "mallali", "mathematiques", 3.6, {2008, 30, 8}, 10}
    };
int compteur = 10;


// *********************************************************************************************************************************
/*fonction de ajouter*/
//**********************************************************************************************************************************
// fonction de ajoute : numero unique , nom , prenom , date de naissance , departement , note general :
/*void les_etudient()
{*/
void reusse()
{
    for(int i = 0 ; i<compteur;i++)
    {
        if(strcmp(les_etudiant[i].departement, "mathematiques")==0 && les_etudiant[i].note_general>=10)
        {
            printf(" les etudient reusse en mathematiques est : %s\n", les_etudiant[i].nom);
        }
    }
    for(int i = 0 ; i<compteur;i++)
    {
        if(strcmp(les_etudiant[i].departement, "physique")==0 && les_etudiant[i].note_general>=10)
        {
            printf("les etudient reusse physique est : %s\n", les_etudiant[i].nom);
        }
    }
    for(int i = 0 ; i<compteur;i++)
    {
        if(strcmp(les_etudiant[i].departement, "chimie")==0 && les_etudiant[i].note_general>=10)
        {
            printf("les etudient reusse chimie est: %s\n", les_etudiant[i].nom);

        }
    }
}


void ajouter()
{

    int taille;
    int nombre_detudiant;
    int test = 0 ;
    printf("menu : \n");
    printf("1 => ajouter un etudiant \n2 => ajouter plusieur \n3 => reteur\n ");
    printf("veuillez entrer votre choix : ");
    scanf("%d", &nombre_detudiant);
    switch (nombre_detudiant)
    {
    case 1:
        taille = 1;
        break;

    case 2:
        printf("veuillez entrer combien des etudiants: ");
        scanf("%d", &taille);
        break;
    case 3:
        test = 1;
        break;
    default:
        printf("non choix ...");
        break;
    }
    if (test == 0)
    {
        for (int i = compteur; i < compteur + taille; i++)
        {
            int choix;
            printf("veuillez entrer le nom: ");
            scanf("%s", les_etudiant[i].nom);
            printf("veuillez entrer le prenom: ");
            scanf("%s", les_etudiant[i].prenom);
            do
            {
                printf("veuillez entrer la note general: ");
                scanf("%f", &les_etudiant[i].note_general);
            } while (les_etudiant[i].note_general < 0 || les_etudiant[i].note_general > 20);
            printf("veuillez entrer la date de nessons(YYYY/MM/DD): \n");

            do
            {
                printf("=> l'anne de naissance(YYYY) : ");
                scanf("%d", &les_etudiant[i].date_de_naissance.annee);
            } while (les_etudiant[i].date_de_naissance.annee > 2020 || les_etudiant[i].date_de_naissance.annee < 1900);

            do
            {
                printf("=> le mois de naissance (MM): ");
                scanf("%d", &les_etudiant[i].date_de_naissance.mois);
            } while (les_etudiant[i].date_de_naissance.mois > 12 || les_etudiant[i].date_de_naissance.mois < 1);

            do
            {
                printf("=> le jour de naissance (JJ): ");
                scanf("%d", &les_etudiant[i].date_de_naissance.jour);
            } while (les_etudiant[i].date_de_naissance.jour > 31 || les_etudiant[i].date_de_naissance.jour < 1);

            printf("veuillez entrer votre departempent : \n");
            printf("1=> mathematiques \n2=> physique \n3=> chimie: ");
            scanf("%d", &choix);
            switch (choix)
            {
            case 1:
                strcpy(les_etudiant[i].departement, "mathematiques");
                break;
            case 2:
                strcpy(les_etudiant[i].departement, "physique");
                break;
            case 3:
                strcpy(les_etudiant[i].departement, "chimie");
                break;
            default:
                printf("ne pas trouve");
                break;
            }
            les_etudiant[i].nombre_uniqeu = i + 1;
        }
    }
    compteur += taille;
}

//*******************************************************************************************************************************
/*fonction de affichage*/
//*******************************************************************************************************************************
void afficher()
{
    if (compteur != 0)
    {            

        for (int i = 0; i < compteur; i++)
        {
            printf("|le nombre d'Etudient : %d \n", les_etudiant[i].nombre_uniqeu);
            printf("|le nom : %s - le prenom : %s \n", les_etudiant[i].nom, les_etudiant[i].prenom);
            printf("|la note general est : %.2f  \n", les_etudiant[i].note_general);
            printf("|la date de naissance est :  \n");
            printf("|jour : %d / mois : %d / annee : %d \n", les_etudiant[i].date_de_naissance.jour, les_etudiant[i].date_de_naissance.mois, les_etudiant[i].date_de_naissance.annee);
            printf("|le departement est : %s |", les_etudiant[i].departement);
            printf("\n|******************************");
            printf("\n|******************************");
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
// fonction modifier :
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
    if (compteur != 0)
    {
        for (int i = 0; i < compteur; i++)
        {
            if (id == les_etudiant[i].nombre_uniqeu)
            {
                switch (choix)
                {
                case 1:
                    printf("veuillez entrer le nouvelle nom : ");
                    scanf("%s", les_etudiant[i].nom);
                    break;
                case 2:
                    printf("veuillez entrer le nouvelle prenom : ");
                    scanf("%s", les_etudiant[i].prenom);
                    break;
                case 3:
                    printf("veuillez entrer le nouvelle note general : ");
                    scanf("%s", les_etudiant[i].note_general);
                    break;
                case 4:
                    printf("entrer votre choix : \n");
                    printf("1 => modifier anne\n2 => modifier mois\n3 => modifier jour");
                    scanf("%d", &choix);
                    switch (choix)
                    {
                    case 1:
                        printf("veuillez entrer la nouvelle annee : ");
                        scanf("%d", &les_etudiant[i].date_de_naissance.annee);
                        break;
                    case 2:
                        printf("veuillez entrer la nouvelle mois : ");
                        scanf("%d", &les_etudiant[i].date_de_naissance.mois);
                        break;
                    case 3:
                        printf("veuillez entrer la nouvelle jour : ");
                        scanf("%d", &les_etudiant[i].date_de_naissance.jour);
                        break;
                    default:
                        printf("no trouve pas...");
                        break;
                    }

                    break;
                case 5:
                    printf("veuillez entrer le nouvelle choix : \n");
                    printf("1=> svt \n2=> chariaa \n3=> fst: ");
                    scanf("%d", &choix);
                    switch (choix)
                    {

                    case 1:
                        strcpy(les_etudiant[i].departement, "svt");
                        break;
                    case 2:
                        strcpy(les_etudiant[i].departement, "chariaa");
                        break;
                    case 3:
                        strcpy(les_etudiant[i].departement, "fst");
                        break;
                    default:
                        printf("ne pas trouve");
                        break;
                    }
                    break;

                default:
                    printf("non choix ...");
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
// fonction de supremer :
void supremer()
{
    char nom_detudiant[100];
    printf("veuille entrer le nom d'etudiant : ");
    scanf("%s", nom_detudiant);
    for (int i = 0; i < compteur; i++)
    {
        if (strcmp(nom_detudiant, les_etudiant[i].nom) == 0)
        {
            strcpy(les_etudiant[i].nom, les_etudiant[i + 1].nom);
            strcpy(les_etudiant[i].prenom, les_etudiant[i + 1].prenom);
            les_etudiant[i].date_de_naissance.annee = les_etudiant[i + 1].date_de_naissance.annee;
            les_etudiant[i].date_de_naissance.mois = les_etudiant[i + 1].date_de_naissance.mois;
            les_etudiant[i].date_de_naissance.jour = les_etudiant[i + 1].date_de_naissance.jour;
            compteur--;
        }
    }
}
//*******************************************************************************************************************************
/*fonction de moyenne general*/
//*******************************************************************************************************************************
float mathematiques = 0;
float physique = 0;
float chimie = 0;
float general = 0;

int compteur_mathematiques = 0;
int compteur_physique = 0;
int compteur_chimie = 0;

void calcule()
{

    float sum_1 = 0;
    float sum_2 = 0;
    float sum_3 = 0;
    float sum_general = 0;
    for (int i = 0; i < compteur; i++)
    {
        if (strcmp("mathematiques", les_etudiant[i].departement) == 0)
        {
            sum_1 = sum_1 + les_etudiant[i].note_general;
            compteur_mathematiques=compteur_mathematiques+1;
        }
        else if (strcmp("physique", les_etudiant[i].departement) == 0)
        {
            sum_2 = sum_2 + les_etudiant[i].note_general;
            compteur_physique=compteur_physique+1;;
        }
        else if (strcmp("chimie", les_etudiant[i].departement) == 0)
        {
            sum_3 = sum_3 + les_etudiant[i].note_general;
            compteur_chimie=compteur_chimie+1;
        }

        sum_general = sum_general + les_etudiant[i].note_general;
    }

    mathematiques = sum_1 / compteur_mathematiques;
    physique = sum_2 / compteur_physique;
    chimie = sum_3 / compteur_chimie;
    general = sum_general / compteur;
}

//*******************************************************************************************************************************
/*fonction de 3 note*/
//*******************************************************************************************************************************
void les_3_note()
{
    Etudiant tmp;
    for (int i = 0; i < compteur - i; i++)
    {
        for (int j = 0; i < compteur; i++)
        {
            if (les_etudiant[j].note_general < les_etudiant[j + 1].note_general)
            {
                tmp = les_etudiant[j];
                les_etudiant[j] = les_etudiant[j + 1];
                les_etudiant[j + 1] = tmp;
            }
        }
    }
    if (compteur > 2)
    {
        for (int i = 0; i < 3; i++)
        {
            printf("*************************\n");
            printf("*************************\n");
            printf("|le nom est : %s |\n", les_etudiant[i].nom);
            printf("|le prenom est : %s |\n", les_etudiant[i].prenom);
            printf("|la note est : %.2f |\n", les_etudiant[i].note_general);
            printf("la date de naissance est : \n");
            printf("|l'annee est : %d |\n", les_etudiant[i].date_de_naissance.annee);
            printf("|le jour est : %d |\n", les_etudiant[i].date_de_naissance.jour);
            printf("|le mois est : %d |\n", les_etudiant[i].date_de_naissance.mois);
            printf("*************************\n");
            printf("*************************\n");
        }
    }
}
//*******************************************************************************************************************************
/*fonction de statistics*/
//*******************************************************************************************************************************

void statistics()
{
    float choix_2;
    int choix;
    printf("******   le menu ******\n");
    printf("|1 => aficher le nombre total d'Etudiant inscrits \n");
    printf("|2 => aficher le nombre d'tudiant dans chaque departement \n");
    printf("|3 => aficher le nombre d'etudiant ayant une superieur a un certain ceul \n");
    printf("|4 => aficher les trois etudiant ayant les meilleures notes \n");
    printf("|5 => aficher le nombre d'etudiants ayant reussi dans chaque departement \n");
    printf("|veuillez entrer votre choix : ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        printf("le nombre totel d'etudiants inscrits est : %d ", compteur);
        break;
    case 2:
        calcule();
        printf("le nombre d'etudiants dans mathematiques est : %d \n", compteur_mathematiques);
        printf("le nombre d'etudiants dans physique est : %d \n", compteur_physique);
        printf("le nombre d'etudiants dans chimie est : %d ", compteur_chimie);
        break;
    case 3:  printf("veuillez entrer le seuil : ");
        scanf("%f", &choix_2);
        for(int i = 0; i<compteur;i++)
        {
            if(les_etudiant[i].note_general>=choix_2)
            {
                printf("|le nombre d'Etudient : %d \n", les_etudiant[i].nombre_uniqeu);
                printf("|le nom : %s - le prenom : %s \n", les_etudiant[i].nom, les_etudiant[i].prenom);
                printf("|la note general est : %.2f  \n", les_etudiant[i].note_general);
                printf("|la date de naissance est :  \n");
                printf("|jour : %d / mois : %d / annee : %d \n", les_etudiant[i].date_de_naissance.jour, les_etudiant[i].date_de_naissance.mois, les_etudiant[i].date_de_naissance.annee);
                printf("|le departement est : %s |", les_etudiant[i].departement);
                printf("\n|******************************");
                printf("\n|******************************");
            }
        }
        break;
    case 4:
        les_3_note();
        break;
    case 5: reusse();
        break;
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

    for (int i = 0; i < compteur; i++)
    {
        if (strcmp(choix, les_etudiant[i].nom) == 0)
        {
            printf("le nom : %s |le prenom : %s | la note general : %.2f |\n", les_etudiant[i].nom, les_etudiant[i].prenom, les_etudiant[i].note_general);
            printf("la date de naissance : %d / %d / %d|le nombre d'etudiant : %d|\n", les_etudiant[i].date_de_naissance.annee, les_etudiant[i].date_de_naissance.mois, les_etudiant[i].date_de_naissance.jour, les_etudiant[i].nombre_uniqeu);
            printf("le deoartement : %s |\n", les_etudiant[i].departement);
        }
    }
}

//*******************************************************************************************************************************
/*fonction de tris*/
//*******************************************************************************************************************************

void tri()
{
    Etudiant tmp;
    int choix;
    int choix_2;
    printf("menu de tri : \n");
    printf("1 => tri alphabitique : \n2 => tri par moyenne general : \n3 => tri par reussite : \n");
    printf("veuillez entrer votre choix : \n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        printf("1 => croissant (a-z) : \n2 => decroissant (z-a) : \n => : ");
        scanf("%d", &choix_2);
        switch (choix_2)
        {
            case 1:

            for (int i = 0; i < compteur - 1; i++)
            {
                int min=i;

                for (int j = i + 1; j < compteur; j++)
                {
                    if (strcmp(les_etudiant[j].nom, les_etudiant[min].nom) < 0)
                    {
                        min = j;
                    }
                }
                tmp = les_etudiant[min];
                les_etudiant[min] = les_etudiant[i];
                les_etudiant[i] = tmp;
            }
            
            break;
        case 2:
            for (int i = 0; i < compteur - 1; i++)
            {
                int min=i;

                for (int j = i + 1; j < compteur; j++)
                {
                    if (strcmp(les_etudiant[j].nom, les_etudiant[min].nom) > 0)
                    {
                        min = j;
                    }
                }
                tmp = les_etudiant[min];
                les_etudiant[min] = les_etudiant[i];
                les_etudiant[i] = tmp;
            }
            
            break;
        }
        break;
        case 2:
        printf("1 => plus eleve au plus faible (10-1)\n2 => plus faible au plus eleve (1-10) \n=>");
        scanf("%d", &choix_2);
        switch(choix_2)
        {
        case 1:
        
            for (int i = 0; i < compteur - 1; i++)
            {
                int min=i;

                for (int j = i + 1; j < compteur; j++)
                {
                    if (les_etudiant[j].note_general > les_etudiant[min].note_general)
                    {
                        min = j;
                    }
                }
                tmp = les_etudiant[min];
                les_etudiant[min] = les_etudiant[i];
                les_etudiant[i] = tmp;
            }
            
          
            break;
        case 2:
            for (int i = 0; i < compteur - 1; i++)
            {
                int min=i;

                for (int j = i + 1; j < compteur; j++)
                {
                    if (les_etudiant[j].note_general < les_etudiant[min].note_general)
                    {
                        min = j;
                    }
                }
                tmp = les_etudiant[min];
                les_etudiant[min] = les_etudiant[i];
                les_etudiant[i] = tmp;
            }
            
            break;
        }

    }
        
        
}

        
//*******************************************************************************************************************************
                                                 /*fonction de main*/
//*******************************************************************************************************************************

int main()
{

    int choix;
    do
    {

        printf("\n|****************************************|\n");
        printf("|               **le menu **             |\n");
        printf("|****************************************|\n");
        printf("|      veuillez entrer votre choix       |\n");
        printf("|****************************************|\n");

        printf("|1 => ajouter \n|2 => modifier \n|3 => supremer \n|4 => afficher \n|5 => le moyenne general\n|6 => statistics \n|7 => recherche \n|8 => tri \n|0 => exit \n");
        printf("veuillez entrer votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            ajouter();
            break;
        case 2:
            modifier();
            break;
        case 3:
            supremer();
            break;
        case 4:
            afficher();
            break;
        case 5:
            calcule();
            printf("|le moyenne general de fst est : %.2f\n", mathematiques);
            printf("|le moyenne general de svt est : %.2f\n", physique);
            printf("|le moyenne general de chariaa est : %.2f\n", chimie);
            printf("|le moyenne general de uneversity est : %.2f\n", general);
            break;
        case 6:
            statistics();
            break;
        case 7:
            recherche();
            break;
        case 8:
            tri();
            break;
        default:
            printf("veuillez entrer un choix entrer 1 et 8 or 0 for exit ");
            break;
        }
    } while (choix != 0);
}
