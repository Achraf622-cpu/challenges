#include <stdio.h>
int main() {
    int a, i;
    printf("Veuiler entre le nombre de case de ce tableau:");
    scanf("%d", &a);
    int tableau1[a];
    int tableau2[a];
    for (int i=0; i < a; i++){
        int b=i+1;
        printf("Veuiller entre le nombre que vous voullez dans la case %d :",b);
        scanf("%d", &tableau1[i]);
    }for(int i=0 ; i<a ;i++){
        tableau2[i]=tableau1[i];
    } printf("Le tableau original :\n");
    for(int i=0; i<a;i++){
        printf("%d-", tableau1[i]);
    }
    printf("\n");
    printf("la copie est :\n");
    for(int i=0; i<a ; i++){
        printf("%d-", tableau2[i]);
    }
    printf("\n");
    return 0;
}
    
    