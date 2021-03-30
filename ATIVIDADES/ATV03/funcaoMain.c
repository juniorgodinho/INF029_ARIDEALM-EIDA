#include "funcaoMain.h"
#include <stdio.h>
#include <stdlib.h>


 int somar(){


   int x, y, resultado;


   printf("Insira o valor de x para realizar a soma\n");
   scanf("%d", &x);
   printf("Insira o Valor de y\n");
   scanf("%d", &y);

   resultado = x + y;
   
   return resultado;

 }

 int subtrair(){

int x, y ,resultado;


   printf("Insira o valor de x para realizar a subtracao\n");
   scanf("%d", &x);
   printf("Insira o Valor de y\n");
   scanf("%d", &y);

   resultado = x - y;

   return resultado;

  
 }



     
