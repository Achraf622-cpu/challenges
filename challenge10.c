#include<stdio.h>
int main(){
   int a;
   int found = 0;
   printf("Entrez le nombre de case:");
   scanf("%d", &a);
   int tab[a];
   for(int i=0;i<a;i++){
      printf("Pour la case %d : ",i+1);
      scanf("%d", &tab[i]);
   }
   int recherche;
   printf("Entrez le chiffre que vous voullez cherchez: ");
   scanf("%d", &recherche);
   for(int i=0;i<a;i++){
      if(recherche==tab[i]){
         printf("Element trouve! le chiffre est : %d\n et d indice : %d",recherche,i);
         found = 1;
         break;
      } 
   }
   if(!found) {
         printf("Element pas trouve.\n");
      }
   return 0;
}