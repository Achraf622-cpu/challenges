// Fonction pour afficher les étudiants d'un département spécifique
void afficherParDepartement() {
    char departement[100];
    printf("Choisissez le département (sc_math, sc_pc, economie): ");
    fgets(departement, sizeof(departement), stdin);
    departement[strcspn(departement, "\n")] = '\0'; // Supprimer le \n

    printf("\n=== Étudiants du département %s ===\n", departement);
    int found = 0;
    for (int i = 0; i < nombreEtudiants; i++) {
        if (strcmp(etudiants[i].depar, departement) == 0) {
            afficherEtudiant(etudiants[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Aucun étudiant trouvé dans ce département.\n");
    }
}

// Fonction pour afficher les 3 meilleurs étudiants en termes de notes
void afficherTop3Etudiants() {
    if (nombreEtudiants < 3) {
        printf("Il y a moins de 3 étudiants inscrits.\n");
        return;
    }

    // Copie du tableau d'étudiants pour ne pas modifier l'original lors du tri
    Etudiant tempEtudiants[MAX_ETU];
    memcpy(tempEtudiants, etudiants, sizeof(etudiants));

    // Tri des étudiants par note décroissante
    for (int i = 0; i < nombreEtudiants - 1; i++) {
        for (int j = i + 1; j < nombreEtudiants; j++) {
            if (tempEtudiants[i].note < tempEtudiants[j].note) {
                Etudiant temp = tempEtudiants[i];
                tempEtudiants[i] = tempEtudiants[j];
                tempEtudiants[j] = temp;
            }
        }
    }

    // Affichage des 3 meilleurs étudiants
    printf("\n=== Top 3 des étudiants par note ===\n");
    for (int i = 0; i < 3; i++) {
        afficherEtudiant(tempEtudiants[i]);
    }
}

// Modification du menu pour ajouter les nouvelles options
void afficherMenu() {
    int choix;
    do {
        printf("\n=== Menu Principal ===\n");
        printf("1. Ajouter un étudiant\n");
        printf("2. Modifier un étudiant\n");
        printf("3. Supprimer un étudiant\n");
        printf("4. Afficher tous les étudiants\n");
        printf("5. Trier les étudiants par ordre alphabétique\n");
        printf("6. Moyenne générale de chaque département et de l'université\n");
        printf("7. Afficher les étudiants par département\n");  // Nouvelle option
        printf("8. Afficher le top 3 des meilleurs étudiants\n");  // Nouvelle option
        printf("9. Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);
        getchar(); // Consommer le '\n' après scanf

        switch (choix) {
            case 1:
                ajouterEtudiant();
                break;
            case 2:
                modifierEtudiant();
                break;
            case 3:
                supprimerEtudiant();
                break;
            case 4:
                afficherTousLesEtudiants();
                break;
            case 5:
                trierEtudiants();
                afficherTousLesEtudiants();
                break;
            case 6:
                moyenneDepartement();
                break;
            case 7:
                afficherParDepartement();  // Nouvelle fonctionnalité
                break;
            case 8:
                afficherTop3Etudiants();  // Nouvelle fonctionnalité
                break;
            case 9:
                printf("Quitter l'application.\n");
                break;
            default:
                printf("Option invalide. Veuillez réessayer.\n");
        }
    } while (choix != 9);
}

int main() {
    afficherMenu();
    return 0;
}