#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED


typedef struct Matiere Matiere;
struct Matiere {
    char nom[20];
    int coefficient;
};

void AjouterMatiere();
void ListerMatiere();
void RemplirNotes();
void ListerNotes();
void Resultat();
int EstVide(char chaine[]);

typedef struct Eleve Eleve;
typedef struct Eleve {
    char matricule[10];
    char nom[20];
    char sexe;
    char date_naissance[20];
    float Notes[20];
};
void AjouterEleve();
void ListerELeve();
typedef struct BaseDeDonnees BaseDeDonnees;
struct BaseDeDonnees {
    Eleve eleves[20];
    Matiere matieres[20];
};

//void EnregistreEleve(Eleve eleve);
#endif // MAIN_H_INCLUDED
