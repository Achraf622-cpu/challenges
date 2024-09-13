#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
void delete(){
printf("appuyer sur entrez pour continuer");
getchar();
system(CLEAR);
}
typedef struct {
    char carte_natio[100];  
    char nom[100];          
    char prenom[100];       
    char ddn[100];          
    char depar[100];        
    float note;    
} Etudiant;
Etudiant etudiants[100];
int nombreEtudiants = 0;
int count_math = 0, count_pc = 0, count_economie = 0, count_autre = 0;
float sum_math = 39.71, sum_pc = 44.71, sum_economie = 37.71, sum_autre = 37.65;
Etudiant nvEtudiant; 
void ajouterEtudiant() {
    if (nombreEtudiants >= MAX_ETU) {
        printf("Il ny a plus de place.\n");
        return;
    }
    printf("Choisissez le departement \n1-sc math.\n 2-sc pc.\n 3-economie : ");
    int choix;
    scanf("%d", &choix);
    getchar(); 
    switch (choix) {
        case 1:
            strcpy(nvEtudiant.depar, "sc math");
            count_math++;
            break;
        case 2:
            strcpy(nvEtudiant.depar, "sc physic");
            count_pc++;
            break;
        case 3:
            strcpy(nvEtudiant.depar, "economie");
            count_economie++;
            break;
        default:
            printf("Le departement sera defini sur 'Autre'.\n");
            strcpy(nvEtudiant.depar, "Autre");
            count_autre++;
    }
    printf("Carte nationale de l etudiant (CID): ");
    fgets(nvEtudiant.carte_natio, sizeof(nvEtudiant.carte_natio), stdin);
    nvEtudiant.carte_natio[strcspn(nvEtudiant.carte_natio, "\n")] = '\0'; 
    printf("Nom: ");
    fgets(nvEtudiant.nom, sizeof(nvEtudiant.nom), stdin);
    nvEtudiant.nom[strcspn(nvEtudiant.nom, "\n")] = '\0';
    printf("Prenom: ");
    fgets(nvEtudiant.prenom, sizeof(nvEtudiant.prenom), stdin);
    nvEtudiant.prenom[strcspn(nvEtudiant.prenom, "\n")] = '\0';
    printf("Date de naissance (YYYY-MM-DD): ");
    fgets(nvEtudiant.ddn, sizeof(nvEtudiant.ddn), stdin);
    nvEtudiant.ddn[strcspn(nvEtudiant.ddn, "\n")] = '\0';
    printf("Note generale: ");
    scanf("%f", &nvEtudiant.note);
    getchar();
    etudiants[nombreEtudiants] = nvEtudiant;
    nombreEtudiants++;
    if (strcmp(nvEtudiant.depar, "sc math") == 0) {
        sum_math += nvEtudiant.note;
    } else if (strcmp(nvEtudiant.depar, "sc physic") == 0) {
        sum_pc += nvEtudiant.note;
    } else if (strcmp(nvEtudiant.depar, "economie") == 0) {
        sum_economie += nvEtudiant.note;
    } else if (strcmp(nvEtudiant.depar, "Autre") == 0) {
        sum_autre += nvEtudiant.note;
    }
    printf("Etudiant ajoute avec succes!\n");
}
void afficherEtudiant(Etudiant etu) {
    printf("Carte nationale: %s\n", etu.carte_natio);
    printf("Nom: %s\n", etu.nom);
    printf("Prenom: %s\n", etu.prenom);
    printf("Date de naissance: %s\n", etu.ddn);
    printf("Departement: %s\n", etu.depar);
    printf("Note generale: %.2f\n", etu.note);
    printf("----------------------------\n");
}
void afficherTousLesEtudiants() {
    int choix;
    printf("Choisissez le departement a afficher:\n");
    printf("1.sc maths\n");
    printf("2.sc physique\n");
    printf("3.economie\n");
    printf("3.Autre\n");
    printf("5.Tous les etudiants\n");
    printf("Votre choix: ");
    scanf("%d", &choix);
    getchar(); 
    switch (choix) {
        case 1:
            printf("Liste des etudiants du departement sc math:\n");
            for (int i = 0; i < nombreEtudiants; i++) {
                if (strcmp(etudiants[i].depar, "sc math") == 0) {
                    afficherEtudiant(etudiants[i]);
                }
            }
            break;
        case 2:
            printf("Liste des etudiants du departement sc physic:\n");
            for (int i = 0; i < nombreEtudiants; i++) {
                if (strcmp(etudiants[i].depar, "sc pc") == 0) {
                    afficherEtudiant(etudiants[i]);
                }
            }
            break;
        case 3:
            printf("Liste des etudiants du departement economie:\n");
            for (int i = 0; i < nombreEtudiants; i++) {
                if (strcmp(etudiants[i].depar, "economie") == 0) {
                    afficherEtudiant(etudiants[i]);
                }
            }
            break;
            case 4:
            printf("Liste des etudiants du departement Autre:\n");
            for(int i=0; i< nombreEtudiants; i++){
                if (strcmp(etudiants[i].depar, "Autre") == 0){
                    afficherEtudiant(etudiants[i]);
                }
            }
        case 5:
            printf("Liste de tous les etudiants:\n");
            for (int i = 0; i < nombreEtudiants; i++) {
                afficherEtudiant(etudiants[i]);
            }
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }
}
void trierEtudiants() {
    int choix;
    printf("DE quel facons voulez vous le triee:\n");
    printf("1. Trier par nom (Ordre alphabetique A-Z)\n");
    printf("2. Trier par moyenne generale (Decroissant)\n");
    printf("3. Trier par moyenne generale (Croissant )\n");
    printf("4. Trier par status (que les gens qui ont reussit 10 ou plus en note general)\n");
    printf("Votre choix: ");
    scanf("%d", &choix);
    getchar();
    for (int i = 0; i < nombreEtudiants - 1; i++) {
        for (int j = 0; j < nombreEtudiants - i - 1; j++) {
            if (choix == 1) {
                if (strcmp(etudiants[j].nom, etudiants[j+1].nom) > 0) {
                    Etudiant temp = etudiants[j];
                    etudiants[j] = etudiants[j+1];
                    etudiants[j+1] = temp;
                }
            } else if (choix == 2) {
                if (etudiants[j].note < etudiants[j+1].note) {
                    Etudiant temp = etudiants[j];
                    etudiants[j] = etudiants[j+1];
                    etudiants[j+1] = temp;
                }
            } else if (choix == 3) {
                if (etudiants[j].note > etudiants[j+1].note) {
                    Etudiant temp = etudiants[j];
                    etudiants[j] = etudiants[j+1];
                    etudiants[j+1] = temp;
                }
            } 
        }
    }
}
void modifierEtudiant() {
    char carteNatio[100];
    printf("Entrez la carte nationale de l etudiant a modifier: ");
    fgets(carteNatio, sizeof(carteNatio), stdin);
    carteNatio[strcspn(carteNatio, "\n")] = '\0';
    for (int i = 0; i < nombreEtudiants; i++) {
        if (strcmp(etudiants[i].carte_natio, carteNatio) == 0) {
            printf("Etudiant trouve Modifiez les informations suivantes:\n");
        
            printf("Nom (Clicker entree pour ne rien changer): ");
            char NV[100];
            fgets(NV, sizeof(NV), stdin);
            NV[strcspn(NV, "\n")] = '\0';
            if (strlen(NV) > 0) {
                strcpy(etudiants[i].nom, NV);
            }
            printf("Prenom (Clicker entree pour ne rien changer): ");
            fgets(NV, sizeof(NV), stdin);
            NV[strcspn(NV, "\n")] = '\0';
            if (strlen(NV) > 0) {
                strcpy(etudiants[i].prenom, NV);
            }
            printf("Date de naissance (Clicker entree pour ne rien changer): ");
            fgets(NV, sizeof(NV), stdin);
            NV[strcspn(NV, "\n")] = '\0';
            if (strlen(NV) > 0) {
                strcpy(etudiants[i].ddn, NV);
            }
            printf("Departement (Clicker entree pour ne rien changer): ");
            fgets(NV, sizeof(NV), stdin);
            NV[strcspn(NV, "\n")] = '\0';
            if (strlen(NV) > 0) {
                strcpy(etudiants[i].depar, NV);
            }
            printf("Note generale (Clicker entree pour ne rien changer): ");
            if (fgets(NV, sizeof(NV), stdin) != NULL) {
                if (strlen(NV) > 1) { 
                    etudiants[i].note = atof(NV);
                }
            }
            printf("Information modifie avec succes\n");
            return;
        }
    }
    printf("Etudiant avec la carte nationale %s non trouve.\n", carteNatio);
}
void supprimerEtudiant() {
    char carteNatio[100];
    printf("Entrez la carte nationale de l etudiant a suprimer: ");
    fgets(carteNatio, sizeof(carteNatio), stdin);
    carteNatio[strcspn(carteNatio, "\n")] = '\0'; 
    for (int i = 0; i < nombreEtudiants; i++) {
        if (strcmp(etudiants[i].carte_natio, carteNatio) == 0) {
            if (strcmp(etudiants[i].depar, "sc math") == 0) {
                sum_math -= etudiants[i].note;
                count_math--;
            } else if (strcmp(etudiants[i].depar, "sc physic") == 0) {
                sum_pc -= etudiants[i].note;
                count_pc--;
            } else if (strcmp(etudiants[i].depar, "economie") == 0) {
                sum_economie -= etudiants[i].note;
                count_economie--;
            }
            for (int j = i; j < nombreEtudiants - 1; j++) {
                etudiants[j] = etudiants[j + 1];
            }
            nombreEtudiants--;
            printf("Etudiant supprime avec succes\n");
            return;
        }
    }
    printf("Etudiant avec la carte nationale %s non trouve.\n", carteNatio);
}
void moyenneDepartement() {
    float moy_maths = sum_math / count_math;
    float moy_pc = sum_pc / count_pc;
    float moy_eco = sum_economie / count_economie;
    float moy_autre = sum_autre / count_autre;
    printf("Moyenne generale pour sc math: %f\n", moy_maths);
    printf("Moyenne generale pour sc physic: %f\n", moy_pc);
    printf("Moyenne generale pour economie: %f\n", moy_eco);
    float moy_uni = (moy_autre + moy_maths + moy_pc + moy_eco) / 4;
    printf("Moyenne generale de l universite: %f\n", moy_uni);
}
void afficherParDepartement() {
    char departement[100];
    printf("Choisissez le departement (sc math, sc physic, economie): ");
    fgets(departement, sizeof(departement), stdin);
    departement[strcspn(departement, "\n")] = '\0';
    printf("\n********** Étudiants du departement %s *********\n", departement);
    int found = 0;
    for (int i = 0; i < nombreEtudiants; i++) {
        if (strcmp(etudiants[i].depar, departement) == 0) {
            afficherEtudiant(etudiants[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Aucun etudiant trouve dans ce departement.\n");
    }
}
void rechercherParNom() {
    char nomRecherche[100];
    printf("Entrez le nom de l etudiant a rechercher: ");
    fgets(nomRecherche, sizeof(nomRecherche), stdin);
    nomRecherche[strcspn(nomRecherche, "\n")] = '\0'; 
    int found = 0;
    printf("\n********** Etudiants avec le nom '%s' ********\n", nomRecherche);
    for (int i = 0; i < nombreEtudiants; i++) {
        if (strcmp(etudiants[i].nom, nomRecherche) == 0) {
            afficherEtudiant(etudiants[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Aucun etudiant trouve avec le nom '%s'.\n", nomRecherche);
    }
}
void Stats(){
    
}
void afficherMenu() {
    int choix;
    do {
        printf("\n********* Menu Principal *******\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Modifier un etudiant\n");
        printf("3. Supprimer un etudiant\n");
        printf("4. Afficher tous les etudiants\n");
        printf("5. Trier les etudiants par ordre\n");
        printf("6. Moyenne generale de chaque departement et de l'universite\n");
        printf("7. Chercher par nom.\n");
        printf("8. Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);
        getchar(); 
        switch (choix) {
            case 1:
                ajouterEtudiant();
                delete();
                break;
            case 2:
                modifierEtudiant();
                delete();
                break;
            case 3:
                supprimerEtudiant();
                delete();
                break;
            case 4:
                afficherTousLesEtudiants();
                delete();
                break;
            case 5:
                trierEtudiants();
                afficherTousLesEtudiants();
                delete();
                break;
            case 6:
                moyenneDepartement();
                delete();
                break;
                case 7:
                rechercherParNom();
                delete();
                break;
            case 8:
                printf("Session termine.\n");
                break;
            default:
                printf("Option invalide. Veuillez reessayer.\n");
                delete();
        }
    } while (choix != 8);
}
int main() {
    //maths
    strcpy(etudiants[0].carte_natio, "HH5000");
    strcpy(etudiants[0].nom, "Nemli");
    strcpy(etudiants[0].prenom, "Aliaa");
    strcpy(etudiants[0].ddn, "2006-05-17");
    strcpy(etudiants[0].depar, "sc math");
    etudiants[0].note = 18.53;
    count_math++;
    nombreEtudiants++;
    strcpy(etudiants[1].carte_natio, "HH4000");
    strcpy(etudiants[1].nom, "Yzaa");
    strcpy(etudiants[1].prenom, "Wassim");
    strcpy(etudiants[1].ddn, "2006-05-01");
    strcpy(etudiants[1].depar, "sc math");
    etudiants[1].note = 16.25;
    count_math++;
    nombreEtudiants++;
    strcpy(etudiants[2].carte_natio, "HH7800");
    strcpy(etudiants[2].nom, "Laagal");
    strcpy(etudiants[2].prenom, "Aya");
    strcpy(etudiants[2].ddn, "2006-03-17");
    strcpy(etudiants[2].depar, "sc math");
    etudiants[2].note = 4.93;
    count_math++;
    nombreEtudiants++;
    //physique
    strcpy(etudiants[3].carte_natio, "HH7800");
    strcpy(etudiants[3].nom, "Hanzaz");
    strcpy(etudiants[3].prenom, "Imane");
    strcpy(etudiants[3].ddn, "2006-02-17");
    strcpy(etudiants[3].depar, "sc physic");
    etudiants[3].note = 17.53;
    count_pc++;
    nombreEtudiants++;
    strcpy(etudiants[4].carte_natio, "HH1530");
    strcpy(etudiants[4].nom, "Aanab");
    strcpy(etudiants[4].prenom, "Hossam");
    strcpy(etudiants[4].ddn, "2006-07-14");
    strcpy(etudiants[4].depar, "sc physic");
    etudiants[4].note = 14.25;
    count_pc++;
    nombreEtudiants++;
    strcpy(etudiants[5].carte_natio, "HH5040");
    strcpy(etudiants[5].nom, "Saoud");
    strcpy(etudiants[5].prenom, "Othman");
    strcpy(etudiants[5].ddn, "2006-03-17");
    strcpy(etudiants[5].depar, "sc physic");
    etudiants[5].note = 12.93;
    count_pc++;
    nombreEtudiants++;
    //economie
    strcpy(etudiants[6].carte_natio, "HH5000");
    strcpy(etudiants[6].nom, "Sehnani");
    strcpy(etudiants[6].prenom, "Zineb");
    strcpy(etudiants[6].ddn, "2004-06-19");
    strcpy(etudiants[6].depar, "economie");
    etudiants[6].note = 18.53;
    count_economie++;
    nombreEtudiants++;
    strcpy(etudiants[7].carte_natio, "HH4000");
    strcpy(etudiants[7].nom, "Bootahlil");
    strcpy(etudiants[7].prenom, "Yasmin");
    strcpy(etudiants[7].ddn, "2005-03-05");
    strcpy(etudiants[7].depar, "economie");
    etudiants[7].note = 6.25;
    count_economie++;
    nombreEtudiants++;
    strcpy(etudiants[8].carte_natio, "HH7800");
    strcpy(etudiants[8].nom, "Nghraoui");
    strcpy(etudiants[8].prenom, "Sami");
    strcpy(etudiants[8].ddn, "2004-08-27");
    strcpy(etudiants[8].depar, "economie");
    etudiants[8].note = 12.93;
    count_economie++;
    nombreEtudiants++;
    //autre
    strcpy(etudiants[9].carte_natio, "HH7800");
    strcpy(etudiants[9].nom, "Bahi");
    strcpy(etudiants[9].prenom, "Imane");
    strcpy(etudiants[9].ddn, "2007-01-12");
    strcpy(etudiants[9].depar, "Autre");
    etudiants[9].note = 8.64;
    count_autre++;
    nombreEtudiants++;
    strcpy(etudiants[10].carte_natio, "HH1530");
    strcpy(etudiants[10].nom, "Ikhwan");
    strcpy(etudiants[10].prenom, "Hosni");
    strcpy(etudiants[10].ddn, "2005-06-21");
    strcpy(etudiants[10].depar, "Autre");
    etudiants[10].note = 12.69;
    count_autre++;
    nombreEtudiants++;
    strcpy(etudiants[11].carte_natio, "HH5040");
    strcpy(etudiants[11].nom, "Lfeni");
    strcpy(etudiants[11].prenom, "Kaotar");
    strcpy(etudiants[11].ddn, "2006-12-19");
    strcpy(etudiants[11].depar, "Autre");
    etudiants[11].note = 16.32;
    count_autre++;
    nombreEtudiants++;

    afficherMenu();
    return 0;
}