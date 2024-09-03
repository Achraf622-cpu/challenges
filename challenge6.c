#include <stdio.h>
int main() {
    int a,facteur;
    printf("Veuiler entre le nombre de case de ce tableau:");
    scanf("%d", &a);
    int tableau[a];
    for (int i=0; i < a; i++ ){
        int b=i+1;
        printf("Veuiller entre le nombre que vous voullez dans la case %d :",b);
        scanf("%d", &tableau[i]);
    }
    printf("Veuiller entre le facteur que vous voullez : ");
    scanf("%d", &facteur);
    for(int i=0; i<a ; i++){
        tableau[i] = tableau[i] * facteur;
        
    } printf("le tableau est devenu: \n");
    for (int i= 0; i<a ; i++){
        int b=i+1;
        printf("Pour %d on a: %d \n",b, tableau[i]);
    }
    return 0;
}