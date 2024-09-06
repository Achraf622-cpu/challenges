#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

typedef struct {
    char titre[100];
    char auteur[100];
    float prix;
    int qnt;
} library;
void pause_and_clear() {
    printf("Appuyer sur Enter pour continue:");
    getchar();
    system(CLEAR);
}

library livre[100];
int nombre = 0;
int choix;

int main() {
    char titles[100];
    int rep;

    do {
        printf("\n1-Entrez un livre.\n");
        printf("2-Affichez les livres disponibles.\n");
        printf("3-Rechercher un livre.\n");
        printf("4-Mettre à jour un livre.\n");
        printf("5-Supprimer un livre en stock.\n");
        printf("6-Afficher le nombre total de livres en stock.\n");
        printf("7-Quitter le programme.\n");
        scanf("%d", &choix);
        getchar(); // Pour éviter les problèmes de retour à la ligne dans scanf

        switch (choix) {
            case 1: {
                if (nombre >= 100) {
                    printf("Il n'y a plus de place.\n");
                    pause_and_clear();
                    break;
                }
                library livres;
                printf("Entrez le titre du livre: ");
                fgets(livres.titre, sizeof(livres.titre), stdin);
                livres.titre[strcspn(livres.titre, "\n")] = '\0';

                printf("Entrez le nom de l'auteur: ");
                fgets(livres.auteur, sizeof(livres.auteur), stdin);
                livres.auteur[strcspn(livres.auteur, "\n")] = '\0';

                printf("Entrez le prix: ");
                scanf("%f", &livres.prix);
                getchar();

                printf("Entrez la quantité en stock: ");
                scanf("%d", &livres.qnt);
                getchar();

                livre[nombre] = livres;
                nombre++;
                printf("Livre ajouté avec succès.\n");
                break;
            }

            case 2: {
                if (nombre == 0) {
                    printf("Pas de livre en ce moment.\n");
                } else {
                    printf("Voici les livres ajoutés :\n");
                    for (int i = 0; i < nombre; i++) {
                        printf("Titre: %s\n", livre[i].titre);
                        printf("Auteur: %s\n", livre[i].auteur);
                        printf("Prix: %.2f\n", livre[i].prix);
                        printf("Quantité: %d\n", livre[i].qnt);
                    }
                }
                break;
            }

            case 3: {
                printf("Entrez le titre du livre que vous voulez chercher: ");
                fgets(titles, sizeof(titles), stdin);
                titles[strcspn(titles, "\n")] = '\0';

                int found = 0;
                for (int i = 0; i < nombre; i++) {
                    if (strcmp(livre[i].titre, titles) == 0) {
                        printf("Livre trouvé!\n");
                        printf("Titre: %s\n", livre[i].titre);
                        printf("Auteur: %s\n", livre[i].auteur);
                        printf("Prix: %.2f\n", livre[i].prix);
                        printf("Quantité en stock: %d\n", livre[i].qnt);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Livre non trouvé.\n");
                }
                break;
            }

            case 4: {
                printf("Entrez le titre du livre que vous voulez modifier : ");
                fgets(titles, sizeof(titles), stdin);
                titles[strcspn(titles, "\n")] = '\0';

                int found = 0;
                for (int i = 0; i < nombre; i++) {
                    if (strcmp(livre[i].titre, titles) == 0) {
                        printf("Livre trouvé!\n");
                        printf("Que voulez-vous changer ?\n");
                        printf("A-Titre\nB-Auteur\nC-Prix\nD-Quantité\n");

                        char xihaja;
                        scanf(" %c", &xihaja);  // L'espace avant %c pour consommer le caractère de nouvelle ligne
                        getchar();

                        if (xihaja == 'A' || xihaja == 'a') {
                            printf("Le titre actuel: %s\n", livre[i].titre);
                            printf("Entrez le nouveau titre: \n");
                            fgets(livre[i].titre, sizeof(livre[i].titre), stdin);
                            livre[i].titre[strcspn(livre[i].titre, "\n")] = '\0';
                            printf("Le titre a été mis à jour.\n");
                        } else if (xihaja == 'B' || xihaja == 'b') {
                            printf("L'auteur actuel: %s\n", livre[i].auteur);
                            printf("Entrez le nouvel auteur: \n");
                            fgets(livre[i].auteur, sizeof(livre[i].auteur), stdin);
                            livre[i].auteur[strcspn(livre[i].auteur, "\n")] = '\0';
                            printf("L'auteur a été mis à jour.\n");
                        } else if (xihaja == 'C' || xihaja == 'c') {
                            printf("Le prix actuel: %.2f\n", livre[i].prix);
                            printf("Entrez le nouveau prix: \n");
                            scanf("%f", &livre[i].prix);
                            getchar();
                            printf("Le prix a été mis à jour.\n");
                        } else if (xihaja == 'D' || xihaja == 'd') {
                            printf("La quantité actuelle: %d\n", livre[i].qnt);
                            printf("Entrez la nouvelle quantité: \n");
                            scanf("%d", &livre[i].qnt);
                            getchar();
                            printf("La quantité a été mise à jour.\n");
                        } else {
                            printf("Choix invalide.\n");
                        }
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Livre non trouvé.\n");
                }
                break;
            } case 5: {
    printf("Entrez le titre du livre à supprimer: ");
    fgets(titles, sizeof(titles), stdin);
    titles[strcspn(titles, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < nombre; i++) {
        if (strcmp(livre[i].titre, titles) == 0) {
            found = 1;
            for (int j = i; j < nombre - 1; j++) {
                livre[j] = livre[j + 1];
            }
            nombre--;
            printf("Le livre '%s' a été supprimé avec succès.\n", titles);
            break;
        }
    }
    if (!found) {
        printf("Livre non trouvé.\n");
    }
    break;
} case 6:{
    printf("le nombre total de livre en stock est : %d\n", nombre);
    break;
} case 7:{
    //printf("fermeture de programme.");
    //exit(0);
    printf("fermeture de programme.\n");
    break;
}
            default:
                printf("Choix invalide.\n");
                break;
        }
    } while (choix != 7);

    return 0;
}