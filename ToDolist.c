#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ID;
    char titre[100];
    char des[100];
    char deadline[100];
    char stats[100];
} Task;

int main() {
    Task ToDo[100];
    int choix;
    int cmb;
    int nombre = 0;
    int nmb = 0; 
    int choi;
    char nom[100];
    int rech;
    int fake_ID;
    int found = 0;
    
    printf("********Projet ToDo list :********** \n");
    printf("1. Ajouter une nouvelle tâche\n");
    printf("2. Afficher toutes les tâches\n");
    printf("3. Modifier une tâche\n");
    printf("4. Supprimer une tâche\n");
    printf("5. Statut d'une tâche\n");
    printf("6. Quitter le programme\n");    
    scanf("%d", &choix);
    getchar();
    
    switch (choix) {
        case 1: {
            if (nmb >= 1000) {
                printf("Il n'y a plus de place :( Essayez de supprimer une tâche pour en ajouter une nouvelle.\n");
                break;
            } else {
                printf("Combien de tâches voulez-vous ajouter : ");
                scanf("%d", &cmb);
                getchar();
                for (int i = 0; i < cmb; i++) {
                    printf("Entrer le nom de la tâche %d : ", i + 1);
                    fgets(ToDo[nmb].titre, sizeof(ToDo[nmb].titre), stdin);
                    ToDo[nmb].titre[strcspn(ToDo[nmb].titre, "\n")] = '\0';

                    printf("Entrer la description de la tâche %d : ", i + 1);
                    fgets(ToDo[nmb].des, sizeof(ToDo[nmb].des), stdin);
                    ToDo[nmb].des[strcspn(ToDo[nmb].des, "\n")] = '\0';

                    printf("Entrez le deadline (exemple 2024-09-14) : ");
                    fgets(ToDo[nmb].deadline, sizeof(ToDo[nmb].deadline), stdin);
                    ToDo[nmb].deadline[strcspn(ToDo[nmb].deadline, "\n")] = '\0';

                    printf("Le statut de cette tâche (exemple : à faire, en cours de réalisation, finalisé) : ");
                    fgets(ToDo[nmb].stats, sizeof(ToDo[nmb].stats), stdin);
                    ToDo[nmb].stats[strcspn(ToDo[nmb].stats, "\n")] = '\0';

                    ToDo[nmb].ID = nmb + 1;

                    nmb++;
                    printf("Tâche ajoutée avec succès.\n");
                }
            }
            break;
        }
        case 2: {
            if( nmb == 0 ){
                printf("Pas de taches a ajouter. (essayer dajouter une tache)");
                break;
            }
            for(int i=0;i<nmb;i++){
                printf("ID de la tache: %d\n",ToDo[i].ID);
                printf("Nom de task : %s\n",ToDo[i].titre);
                printf("Descriptiom de la tache: %s\n",ToDo[i].des);
                printf("Deadline: %s\n",ToDo[i].deadline);
                printf("%s\n",ToDo[i].stats);
            }
            break;
        }
        case 3: {
            printf("Par titre (1) ou par ID (2) ?");
            scanf("%d", &choi);
            switch(choi){
            case 1 : {
                printf("Entrer le titre que vous voullez chercher: ");
                fgets(nom,sizeof(nom), stdin);
                nom[strcspn(nom, "\n")] = '\0';
                for(int i=0; i<nmb;i++){
                    found =0;
                    if(strcmp(ToDo[i].titre, nom) == 0){
                        printf("Tache trouve!\n");
                        printf("Que voulez-vous changer ?\n");
                        printf("A-Titre\nB-Description\nC-Deadline\nD-Status\n");

                        char xihaja;
                        scanf(" %c", &xihaja); 
                        getchar();

                        if (xihaja == 'A' || xihaja == 'a') {
                            printf("Le titre actuel: %s\n", ToDo[i].titre);
                            printf("Entrez le nouveau titre: \n");
                            fgets(ToDo[i].titre, sizeof(ToDo[i].titre), stdin);
                            ToDo[i].titre[strcspn(ToDo[i].titre, "\n")] = '\0';
                            printf("Le titre a été mis à jour.\n");
                        } else if (xihaja == 'B' || xihaja == 'b') {
                            printf("La description actuel: %s\n", ToDo[i].des);
                            printf("Entrez la nouvel description: \n");
                            fgets(ToDo[i].des, sizeof(ToDo[i].des), stdin);
                            ToDo[i].des[strcspn(ToDo[i].des, "\n")] = '\0';
                            printf("L'auteur a été mis à jour.\n");
                        } else if (xihaja == 'C' || xihaja == 'c') {
                            printf("Le description est actuel: %s\n", ToDo[i].deadline);
                            printf("Entrez la nouveau Deadline: \n");
                            fgets(ToDo[i].deadline,sizeof(ToDo[i].deadline), stdin);
                            ToDo[i].deadline[strcspn(ToDo[i].deadline, "\n")] = '\0';
                            printf("Le prix a été mis à jour.\n");
                        } else if (xihaja == 'D' || xihaja == 'd') {
                            printf("Le stat actuelle: %d\n", ToDo[i].status);
                            printf("Entrez la nouvelle quantité: \n");
                            fgets(ToDo[i].status,sizeof(ToDo[i].status), stdin);
                            ToDo[i].status[strcspn(ToDo[i].status, "\n")] = '\0';
                            printf("La quantité a été mise à jour.\n");
                        } else {
                            printf("Choix invalide.\n");
                        }
                        found = 1;
                        break;
                    }
                }
            } if(!found){
                    printf("Elememt pas trouve :(.\n");
                }
                break;
                
            }
                case 2 : {
                    printf("Entrez l ID que vous rechercher: ");
                    scanf("%d", &fake_ID);
                    getchar();
                    for(int i=0;i<nmb;i++){
                        found=0;
                        if(fake_ID == ToDo[i].ID){
                            printf("Id : %d\n", ToDo[i].ID);
                            printf("Titre : %s\n", ToDo[i].titre);
                            printf("description : %s\n", ToDo[i].des);
                            printf("Deadline : %s\n", ToDo[i].deadline);
                            printf("Status: %s", ToDo[i].stats);
                            found=1;
                            break;
                        }
                        
                    }
                    if(!found){
                        printf("element pas trouve :(.\n");
                    }
                    break;
                }
                
            }
        }

        default:
            printf("Option non valide.\n");
            break;
    }
    
    return 0;
}