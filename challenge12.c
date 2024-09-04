#include <stdio.h>
int main() {
    int a, i;
    int found = 0;
    printf("Veuiler entre le nombre de case de ce tableau:");
    scanf("%d", &a);
    int tableau[a];
    for (int i=0; i < a; i++){
        int b=i+1;
        printf("Veuiller entre le nombre que vous voullez dans la case %d :",b);
        scanf("%d", &tableau[i]);
    }
    printf("Affichage des elements paires: \n");
    for(i=0; i<a; i++){
        if(tableau[i] % 2 == 0 ){
            printf("%d ", tableau[i]);
            found = 1;
        }
    }
    if(!found){
        printf("Il n'y a pas d'element pairs.\n");
    }
    printf("\n");
    return 0;
}