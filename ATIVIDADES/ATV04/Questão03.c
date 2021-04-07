#include <stdio.h>
#include <stdlib.h>


int fatorial(int a){
  int resultado = 0;
  if(a < 1){
   return 0; 
  }
   else{
    for(int fat=1; a > 1; a = a - 1){
      fat = fat * a;
      resultado = fat;
    }
    
   }
   return resultado;
}

int main(){

  int a, resultado;


  printf("Insira o numero que vc deseja saber o fatorial\n");
  scanf("%d", &a);

   if(a > 0)
   {
  

  resultado =fatorial(a);

  


  printf("o fatorial do numero eh %d\n", resultado);
   }
   else
   {
     
   printf("O numero nao tem fatorial");
   }
}