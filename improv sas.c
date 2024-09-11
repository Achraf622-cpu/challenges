#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ETU 100
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
Etudiant etudiants[MAX_ETU];
int nombreEtudiants = 0;
int count_math = 0, count_pc = 0, count_economie = 0, count_autre = 0;
float sum_math = 0, sum_pc = 0, sum_economie = 0, sum_autre = 0;
void ajouterEtudiant() {
    if (nombreEtudiants >= MAX_ETU) {
        printf("Il ny a plus de place.\n");
        return;
    }
    Etudiant nvEtudiant;
    printf("Choisissez le departement (1-sc math.\n 2-sc pc.\n 3-economie): ");
    int choix;
    scanf("%d", &choix);
    getchar(); 
    switch (choix) {
        case 1:
            strcpy(nvEtudiant.depar, "sc math");
            count_math++;
            break;
        case 2:
            strcpy(nvEtudiant.depar, "sc pc");
            count_pc++;
            break;
        case 3:
            strcpy(nvEtudiant.depar, "economie");
            count_economie++;
            break;
        default:
            printf("Le departement sera defini sur 'Autre'.\n");
            strcpy(nvEtudiant.depar, "autre");
            count_autre++;
    }
    printf("Carte nationale de l'etudiant: ");
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
    } else if (strcmp(nvEtudiant.depar, "sc pc") == 0) {
        sum_pc += nvEtudiant.note;
    } else if (strcmp(nvEtudiant.depar, "economie") == 0) {
        sum_economie += nvEtudiant.note;
    } else if (strcmp(nvEtudiant.depar, "economie") == 0) {
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
    if (nombreEtudiants == 0) {
        printf("Aucun etudiant enregistre.\n");
        return;
    }
    int choix;
    printf("Choisissez le departement a afficher:\n");
    printf("1.sc maths\n");
    printf("2.sc physique\n");
    printf("3.economie\n");
    printf("4.Tous les etudiants\n");
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
            printf("Liste des etudiants du departement sc pc:\n");
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
        for (int j = i + 1; j < nombreEtudiants; j++) {
            if (choix == 1) {
                if (strcmp(etudiants[i].nom, etudiants[j].nom) > 0) {
                    Etudiant temp = etudiants[i];
                    etudiants[i] = etudiants[j];
                    etudiants[j] = temp;
                }
            } else if (choix == 2) {
                if (etudiants[i].note < etudiants[j].note) {
                    Etudiant temp = etudiants[i];
                    etudiants[i] = etudiants[j];
                    etudiants[j] = temp;
                }
            } else if (choix == 3) {
                if (etudiants[i].note > etudiants[j].note) {
                    Etudiant temp = etudiants[i];
                    etudiants[i] = etudiants[j];
                    etudiants[j] = temp;
                }
            } 
        }
    }
    if (choix == 1) {
        printf("Etudiants tries par ordre alphabetique.\n");
    } else if (choix == 2) {
        printf("Etudiants tries par moyenne generale (du plus eleve au plus faible).\n");
    } else if (choix == 3) {
        printf("Etudiants tries par moyenne generale (du plus faible au plus eleve).\n");
    } else {
        printf("Choix de tri invalide.\n");
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
            char temp[100];
            fgets(temp, sizeof(temp), stdin);
            temp[strcspn(temp, "\n")] = '\0';
            if (strlen(temp) > 0) {
                strcpy(etudiants[i].nom, temp);
            }
            printf("Prenom (Clicker entree pour ne rien changer): ");
            fgets(temp, sizeof(temp), stdin);
            temp[strcspn(temp, "\n")] = '\0';
            if (strlen(temp) > 0) {
                strcpy(etudiants[i].prenom, temp);
            }
            printf("Date de naissance (Clicker entree pour ne rien changer): ");
            fgets(temp, sizeof(temp), stdin);
            temp[strcspn(temp, "\n")] = '\0';
            if (strlen(temp) > 0) {
                strcpy(etudiants[i].ddn, temp);
            }
            printf("Departement (Clicker entree pour ne rien changer): ");
            fgets(temp, sizeof(temp), stdin);
            temp[strcspn(temp, "\n")] = '\0';
            if (strlen(temp) > 0) {
                strcpy(etudiants[i].depar, temp);
            }
            printf("Note generale (Clicker entree pour ne rien changer): ");
            if (fgets(temp, sizeof(temp), stdin) != NULL) {
                if (strlen(temp) > 1) { 
                    etudiants[i].note = atof(temp);
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
            } else if (strcmp(etudiants[i].depar, "sc pc") == 0) {
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
    printf("Moyenne generale pour sc math: %.2f\n", (count_math > 0) ? sum_math / count_math : 0);
    printf("Moyenne generale pour sc physic: %.2f\n", (count_pc > 0) ? sum_pc / count_pc : 0);
    printf("Moyenne generale pour economie: %.2f\n", (count_economie > 0) ? sum_economie / count_economie : 0);

    float moyenne_universite = (count_math + count_pc + count_economie > 0) ?
        (sum_math + sum_pc + sum_economie) / (count_math + count_pc + count_economie) : 0;
    printf("Moyenne generale de l universite: %.2f\n", moyenne_universite);
}
void afficherParDepartement() {
    char departement[100];
    printf("Choisissez le departement (sc math, sc pc, economie): ");
    fgets(departement, sizeof(departement), stdin);
    departement[strcspn(departement, "\n")] = '\0';
    printf("\n=== Étudiants du departement %s ===\n", departement);
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
    printf("\n=== Etudiants avec le nom '%s' ===\n", nomRecherche);
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
void afficherMenu() {
    int choix;
    do {
        printf("\n=== Menu Principal ===\n");
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
    afficherMenu();
    return 0;
}
