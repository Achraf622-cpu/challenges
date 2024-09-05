#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
 {
    char titre[100];
    char auteur[100];
    float prix;
    int qnt;
} Library;
Library livre[100];
int nombre = 0;
int i;
int main(){
    int rep;

    do {
        printf("\n1-Ajoutez un livre\n");
        printf("2-Afficher tous les livres disponibles.\n");
        printf("3-Rechercher un livre par son titre.\n");
        printf("4-Mettre à jour la quantité d'un livre.\n");
        printf("5-Supprimer un livre du stock.\n");
        printf("6-Afficher le nombre total de livres en stock.\n");
        printf("7-Pour quitte.\n");
        printf("Veuillez entrez un un chiffre de cette liste: ");
        scanf("%d", &rep);
        getchar();
        switch (rep)
        {
        case 1:{
            if (nombre >= 100){
             printf("Il n'y a plus de place\n");
             break;
            } 
            Library livres;
            printf("Entrez le titre du livre: ");
            fgets(livres.titre,sizeof(livres.titre), stdin);
            livres.titre[strcspn(livres.titre, "\n")] = '\0';
            printf("Entrez le nom de l auteur: ");
            fgets(livres.auteur,sizeof(livres.auteur), stdin);
            livres.auteur[strcspn(livres.auteur, "\n")] = '\0';
            printf("Entrez le prix du livre: ");
            scanf("%f", &livres.prix);
            getchar();
            printf("Entrez la quantite en stock: ");
            scanf("%d", &livres.qnt);
            getchar();
            livre[nombre] = livres;
            nombre++;
            printf("Livre ajoute avec succes!\n");
            break;
            
        }
        case 2:{
            if (nombre == 0){
                printf("Il n'y a pas de livre en ce moment.");
                break;
            } else {
            printf("Livres disponibles: \n");
            for(int i = 0; i < nombre ;i++) {
                printf("Titre: %s\n", livre[i].titre);
                printf("Auteur: %s\n",livre[i].auteur);
                printf("Prix: %.2f\n",livre[i].prix);
                printf("Quantite: %d\n\n",livre[i].qnt);
                  }
            }
            break;
        }
        case 3: {
             char titre[100];
            printf("Entrez le titre du livre à rechercher: ");
            fgets(titre, sizeof(titre), stdin);
            titre[strcspn(titre, "\n")] = '\0';
            int found = 0;
            for (int i = 0; i < nombre; i++){
            if (strcmp(livre[i].titre, titre) == 0) {
                    printf("Livre trouvé:\n");
                    printf("Titre: %s\n", livre[i].titre);
                    printf("Auteur: %s\n", livre[i].auteur);
                    printf("Prix: %.2f\n", livre[i].prix);
                    printf("Quantité en stock: %d\n", livre[i].qnt);
                    found = 1;
                    break;
            }
                    
            
        }
        if (!found) {
            printf("Livre pas trouve.\n");
              }
        break;
        }
        
        
        
            break;
        
        default:
            break;
        }
    }while (rep != 7 );
    printf("Thanks for using the programme");
    return 0;

}