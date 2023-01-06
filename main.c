#include <stdio.h>
#include <stdlib.h>
#include "Matiere.h"
#include "Eleve.h"
#include "Note.h"
#include "main.h"
#define NB_ELEMENTS(tableau)   (sizeof(tableau) / sizeof(*tableau))

BaseDeDonnees bd;// représente la base de données
int derniereleve = -1; //dernier element enregistré chez les éleves
int derniermatiere = -1; //dernier element enregistré dans les matière

int main()
{
    printf("---------- TP INFO 111 GESTION DES NOTES  ----------------- \n");
    printf("[+]Participants\n");
    printf("1-General Erock\n");
    printf("************** Bienvenu sur Moon School *******************\n");
    printf("Selectionner ce que vous effectuer \n");
    int choix = 0;
    while(1) {
    printf("-------- Eleves --------- \n");
    printf("1-Ajouter un ou des eleves \n");
    printf("2-Lister les eleves \n");
    printf("-------- Matieres --------- \n");
    printf("3-Ajouter une matiere \n");
    printf("4-Lister les matieres \n");
    printf("-------- Notes --------- \n");
    printf("5-Remplir les notes \n");
    printf("6-Lister les notes \n");
    printf("7-Afficher les resultats\n");
    scanf("%d", &choix);
    switch(choix) {
        case 1:
            AjouterEleve();
            break;
        case 2:
            ListerELeve();
            break;
        case 3:
            AjouterMatiere();
            break;
        case 4:
            ListerMatiere();
            break;
        case 5:
            RemplirNotes();
            break;
        case 6:
            ListerNotes();
            break;
        case 7:
            Resultat();
            break;


        default:
            return 0;
            break;
    }
    choix = 0;
    printf("\n");

    }

    return 0;
}




/* Zone de gestion des éleves */


void AjouterEleve() {
    Eleve eleve;
    int k; //nombre d'élève à créer
    printf("Combien d'eleves voulez vous enregistrer \n ");
    scanf("%d", &k);
    printf("********Enregistrement des eleves********\n");
    for(int i = 1; i <= k; i++) {
        printf("Entrer le nom du %de eleve ", i);
        scanf("%s", &eleve.nom);

        printf("\n Entrez le matricule de %s ", eleve.nom);
        scanf("%s", &eleve.matricule);


        printf("\n Entrer la date de Naissance de %s ", eleve.nom);
        scanf("%s", &eleve.date_naissance);

        printf("\n Entrer sexe de %s ", eleve.nom);
        scanf("%s", &eleve.sexe);
        printf("\n");

        // enregistrement à la dernière position
                    //soucis avec strcpy
        for(int x = 0; x < NB_ELEMENTS(eleve.nom); x++) {
             bd.eleves[derniereleve + 1].nom[x] = eleve.nom[x];
        }
        for(int x = 0; x < NB_ELEMENTS(eleve.date_naissance); x++) {
            bd.eleves[derniereleve + 1].date_naissance[x] = eleve.date_naissance[x];

       }
        for(int x = 0; x < NB_ELEMENTS(eleve.matricule); x++) {
             bd.eleves[derniereleve + 1].matricule[x] = eleve.matricule[x];
        }
                bd.eleves[derniereleve + 1].sexe = eleve.sexe;
       derniereleve++;


    }
    ListerELeve();
}


// fait la liste des élèves
void ListerELeve() {
    printf("******************* Liste des eleves ********************* \n");

    printf("Matricule   Noms   Sexe   Date naissance \n");
    for(int i = 0; i < NB_ELEMENTS(bd.eleves); i++) {
            if(bd.eleves[i].nom != NULL && EstVide(bd.eleves[i].nom) == 0)  {

                printf("%s      %s      %c      ", bd.eleves[i].matricule, bd.eleves[i].nom, bd.eleves[i].sexe);
                printf("%s \n", bd.eleves[i].date_naissance);
            }
    }
}



/* Fin de la zone de gestion des eleves*/
/*Gestion des Mati�res */
void AjouterMatiere() {
    Matiere matiere;
    int k; //nombre matiere � cr�er
    printf("Combien de matiere voulez vous enregistrer \n ");
    scanf("%d", &k);
    printf("********Enregistrement de matieres ********\n");
    for(int i = 1; i <= k; i++) {
        printf("Entrer le nom de la %de  matiere ", i);
        scanf("%s", &matiere.nom);

        printf("\n Entrez le coefficient de %s ", matiere.nom);
        scanf("%d", &matiere.coefficient);


        printf("\n");

        // enregistrement � la derni�re position
                    //soucis avec strcpy
        for(int x = 0; x < NB_ELEMENTS(matiere.nom); x++) {
             bd.matieres[derniermatiere + 1].nom[x] = matiere.nom[x];
        }
        bd.matieres[derniermatiere + 1].coefficient = matiere.coefficient;
       derniermatiere++;


    }
    ListerMatiere();
}


// fait la liste des �l�ves
void ListerMatiere() {
    printf("******************* Liste des matieres ********************* \n");

    printf("Nom   Coefficient \n");
    for(int i = 0; i < NB_ELEMENTS(bd.matieres); i++) {
        if(bd.matieres[i].nom != NULL && EstVide(bd.matieres[i].nom) == 0) {
            printf("%s      %d \n", bd.matieres[i].nom, bd.matieres[i].coefficient);
        }
    }
}
/*Fin de la gestion des mati�res*/
/* Gestion des Notes*/
void RemplirNotes() {
    printf("\n ********** Remplissage des notes ********* \n ");
    //Entrer la note en physique de toto:12
    for(int i = 0; i < NB_ELEMENTS(bd.matieres); i++) {
        if(bd.matieres[i].nom != NULL &&  EstVide(bd.matieres[i].nom) == 0) {
         for(int a = 0; a < NB_ELEMENTS(bd.eleves); a++) {
             if(bd.eleves[a].nom != NULL && EstVide(bd.eleves[a].nom) == 0) {
            printf("Entrer la note en %s de %s : ", bd.matieres[i].nom, bd.eleves[a].nom);
            scanf("%f", &bd.eleves[a].Notes[i]);
             }
            }
        }
    }
}

void ListerNotes() {
    int nbmat = 0; //nombre de matiere enregister
    printf("******************* Liste des notes ********************* \n");
    char ligne[200] = "Matricule   Noms   Sexe   Date naissance ";
    for(int i = 0; i < NB_ELEMENTS(bd.matieres); i++) {
            if(bd.matieres[i].nom != NULL &&  EstVide(bd.matieres[i].nom) == 0)  {
                strcat(ligne, "     ");
                strcat(ligne, bd.matieres[i].nom);
                nbmat++;
            }
    }
    printf("%s \n", ligne);
    for(int i = 0; i < NB_ELEMENTS(bd.eleves); i++) {
    //
    if(bd.eleves[i].nom != NULL && EstVide(bd.eleves[i].nom) == 0) {
    printf("     %s ", bd.eleves[i].matricule);
    printf("     %s ",  bd.eleves[i].nom);
    printf("     %c ", bd.eleves[i].sexe);
    printf("     %s ", bd.eleves[i].date_naissance);
    for(int a = 0; a < nbmat; a++) {
        printf("     %f", bd.eleves[i].Notes[a]);
    }

        printf("\n");
    }
    }

}

void Resultat() {

    int nbmat = 0; //nombre de matiere enregister
    printf("******************* Liste des notes ********************* \n");
    char ligne[200] = "Matricule   Noms   Sexe   Date naissance ";
    for(int i = 0; i < NB_ELEMENTS(bd.matieres); i++) {
            if(bd.matieres[i].nom != NULL &&  EstVide(bd.matieres[i].nom) == 0)  {
                strcat(ligne, "     ");
                strcat(ligne, bd.matieres[i].nom);
                nbmat++;
            }
    }
    printf("%s  Moy  Rang Decision\n", ligne);
    for(int i = 0; i < NB_ELEMENTS(bd.eleves); i++) {
    if(bd.eleves[i].nom != NULL && EstVide(bd.eleves[i].nom) == 0) {
    printf("     %s ", bd.eleves[i].matricule);
    printf("     %s ",  bd.eleves[i].nom);
    printf("     %c ", bd.eleves[i].sexe);
    printf("     %s ", bd.eleves[i].date_naissance);
    float somme = 0;
    for(int a = 0; a < nbmat; a++) {
        printf("     %f", bd.eleves[i].Notes[a]);
        somme += bd.eleves[i].Notes[a];
    }

    float moyenne =somme / nbmat;
    printf("    %f", moyenne);
    printf("    %d", (i + 1));
    if(moyenne >= 10) {
        printf("    Admis");
    }
    else {
        printf("    Refuser");
    }

        printf("\n");
    }
    }

}
/* Fin de la gestion des Notes*/
int EstVide(char chaine[]) {
    if(chaine[0] == '\0') {
        return 1;
    }
    else {
        return 0;
    }
}

