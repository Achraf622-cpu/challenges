#include <stdio.h>
int main() {
    int a;
    printf("Veuiler entre le nombre de case de ce tableau:");
    scanf("%d", &a);
    int tableau[a];
    for (int i=0; i<a; i++){
        int b=i+1;
        printf("Veuiller entre le nombre que vous voullez dans la case %d :",b);
        scanf("%d", &tableau[i]);
    }for (int i=0 ; i<a ; i++){
        int c=i+1;
        printf("le chiffre %d est pour %d\n",c ,tableau[i]);
    }
}