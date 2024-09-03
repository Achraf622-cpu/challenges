#include <stdio.h>
int main() {
    int a,min;
    printf("Veuiler entre le nombre de case de ce tableau:");
    scanf("%d", &a);
    int tableau[a];
    for (int i=0; i < a; i++ ){
        int b=i+1;
        printf("Veuiller entre le nombre que vous voullez dans la case %d :",b);
        scanf("%d", &tableau[i]);
    }
    min=tableau[0];
    for (int i=1; i<a; i++){
        if(tableau[i]< min){
            min=tableau[i];
        }
    }
    printf("Le plus petit elemet est %d", min);
    return 0;
    
}