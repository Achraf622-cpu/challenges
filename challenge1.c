#include <stdio.h>
int main() {
    int tableau[] = {1,2,3,4,5};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    printf("Elements du tabeau : \n");
    for (int i=0; i < taille; i++)
    {
        printf("Element %d : %d\n", i + 1, tableau[i]);

    }
return 0;
}