#include <stdio.h>

int main() {
    int tableau[5] = {1,2,3,4,5};
    for(int i=0;i<5;i++){
        int a=i+1;
        printf("pour la case %d on a %d \n",a ,tableau[i]);
    }
}