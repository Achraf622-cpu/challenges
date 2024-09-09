#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TACHES 100
#define TAILLE_TITRE 50
#define TAILLE_DESCRIPTION 200

typedef struct {
    int id;
    char titre[TAILLE_TITRE];
    char description[TAILLE_DESCRIPTION];
    struct tm deadline;
    char statut[20];
} Tache;

Tache taches[MAX_TACHES];
int compteurTaches = 0;

void ajouterNouvelleTache() {
    if (compteurTaches >= MAX_TACHES) { printf("Limite atteinte.\n"); return; }
    Tache t; t.id = compteurTaches + 1;
    printf("Titre: "); getchar(); fgets(t.titre, TAILLE_TITRE, stdin); t.titre[strcspn(t.titre, "\n")] = '\0';
    printf("Description: "); fgets(t.description, TAILLE_DESCRIPTION, stdin); t.description[strcspn(t.description, "\n")] = '\0';
    printf("Deadline (jj mm aaaa): "); scanf("%d %d %d", &t.deadline.tm_mday, &t.deadline.tm_mon, &t.deadline.tm_year);
    t.deadline.tm_mon--; t.deadline.tm_year -= 1900; strcpy(t.statut, "à réaliser");
    taches[compteurTaches++] = t; printf("Tâche ajoutée.\n");
}

void afficherTaches() {
    printf("Liste des tâches:\n");
    for (int i = 0; i < compteurTaches; i++) {
        printf("ID:%d Titre:%s Desc:%s Deadline:%02d/%02d/%d Statut:%s\n",
               taches[i].id, taches[i].titre, taches[i].description,
               taches[i].deadline.tm_mday, taches[i].deadline.tm_mon + 1, taches[i].deadline.tm_year + 1900, taches[i].statut);
    }
}

int comparerParTitre(const void *a, const void *b) { return strcmp(((Tache*)a)->titre, ((Tache*)b)->titre); }
void trierTachesParTitre() { qsort(taches, compteurTaches, sizeof(Tache), comparerParTitre); printf("Trié par titre.\n"); }

int comparerParDeadline(const void *a, const void *b) { return difftime(mktime(&((Tache*)a)->deadline), mktime(&((Tache*)b)->deadline)); }
void trierTachesParDeadline() { qsort(taches, compteurTaches, sizeof(Tache), comparerParDeadline); printf("Trié par deadline.\n"); }

void afficherTachesUrgentes() {
    time_t maintenant = time(NULL); struct tm *dateActuelle = localtime(&maintenant);
    printf("Tâches urgentes (3 jours ou moins):\n");
    for (int i = 0; i < compteurTaches; i++) {
        double difference = difftime(mktime(&taches[i].deadline), mktime(dateActuelle)) / (60 * 60 * 24);
        if (difference <= 3 && difference >= 0) {
            printf("ID:%d Titre:%s Deadline:%02d/%02d/%d Statut:%s\n",
                   taches[i].id, taches[i].titre, taches[i].deadline.tm_mday,
                   taches[i].deadline.tm_mon + 1, taches[i].deadline.tm_year + 1900, taches[i].statut);
        }
    }
}

void modifierTache(int id) {
    for (int i = 0; i < compteurTaches; i++) {
        if (taches[i].id == id) {
            printf("Nouvelle description: "); getchar(); fgets(taches[i].description, TAILLE_DESCRIPTION, stdin);
            taches[i].description[strcspn(taches[i].description, "\n")] = '\0';
            printf("Nouveau statut: "); fgets(taches[i].statut, 20, stdin); taches[i].statut[strcspn(taches[i].statut, "\n")] = '\0';
            printf("Nouveau deadline (jj mm aaaa): "); scanf("%d %d %d", &taches[i].deadline.tm_mday, &taches[i].deadline.tm_mon, &taches[i].deadline.tm_year);
            taches[i].deadline.tm_mon--; taches[i].deadline.tm_year -= 1900; printf("Tâche modifiée.\n");
            return;
        }
    }
    printf("Tâche non trouvée.\n");
}

void supprimerTache(int id) {
    int found = 0;
    for (int i = 0; i < compteurTaches; i++) {
        if (taches[i].id == id) found = 1;
        if (found && i < compteurTaches - 1) taches[i] = taches[i + 1];
    }
    if (found) compteurTaches--; else printf("Tâche non trouvée.\n");
}

void rechercherTacheParId(int id) {
    for (int i = 0; i < compteurTaches; i++) {
        if (taches[i].id == id) {
            printf("ID:%d Titre:%s Desc:%s Deadline:%02d/%02d/%d Statut:%s\n",
                   taches[i].id, taches[i].titre, taches[i].description, taches[i].deadline.tm_mday,
                   taches[i].deadline.tm_mon + 1, taches[i].deadline.tm_year + 1900, taches[i].statut);
            return;
        }
    }
    printf("Tâche non trouvée.\n");
}

void rechercherTacheParTitre(char *titre) {
    for (int i = 0; i < compteurTaches; i++) {
        if (strcmp(taches[i].titre, titre) == 0) {
            printf("ID:%d Titre:%s Desc:%s Deadline:%02d/%02d/%d Statut:%s\n",
                   taches[i].id, taches[i].titre, taches[i].description, taches[i].deadline.tm_mday,
                   taches[i].deadline.tm_mon + 1, taches[i].deadline.tm_year + 1900, taches[i].statut);
            return;
        }
    }
    printf("Tâche non trouvée.\n");
}

void afficherStatistiques() {
    int completees = 0, incompletes = 0;
    time_t maintenant = time(NULL);
    for (int i = 0; i < compteurTaches; i++) {
        if (strcmp(taches[i].statut, "finalisée") == 0) completees++; else incompletes++;
        double difference = difftime(mktime(&taches[i].deadline), maintenant) / (60 * 60 * 24);
        printf("ID:%d Jours restants:%f\n", taches[i].id, difference);
    }
    printf("Total:%d Complètes:%d Incomplètes:%d\n", compteurTaches, completees, incompletes);
}

int main() {
    int choix, id;
    char titre[TAILLE_TITRE];
    do {
        printf("Menu:\n1. Ajouter tâche\n2. Afficher tâches\n3. Trier par titre\n4. Trier par deadline\n5. Tâches urgentes\n6. Modifier tâche\n7. Supprimer tâche\n8. Rechercher par ID\n9. Rechercher par titre\n10. Statistiques\n0. Quitter\n");
        scanf("%d", &choix);
        switch (choix) {
            case 1: ajouterNouvelleTache(); break;
            case 2: afficherTaches(); break;
            case 3: trierTachesParTitre(); break;
            case 4: trierTachesParDeadline(); break;
            case 5: afficherTachesUrgentes(); break;
            case 6: printf("ID à modifier: "); scanf("%d", &id); modifierTache(id); break;
            case 7: printf("ID à supprimer: "); scanf("%d", &id); supprimerTache(id); break;
            case 8: printf("ID: "); scanf("%d", &id); rechercherTacheParId(id); break;
            case 9: printf("Titre: "); getchar(); fgets(titre, TAILLE_TITRE, stdin); titre[strcspn(titre, "\n")] = '\0'; rechercherTacheParTitre(titre); break;
            case 10: afficherStatistiques(); break;
        }
    } while (choix != 0);
    return 0;
}
