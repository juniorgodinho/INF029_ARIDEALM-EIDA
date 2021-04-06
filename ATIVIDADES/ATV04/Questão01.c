#include <stdio.h>
#include <stdlib.h>

int soma(int a, int b){
  return a +b;
};

int main(){

  int resultado = 0, a, b;


  printf("Insira o valor de a\n");
  scanf("%d", &a);
  printf("Insira o valor de b\n");
  scanf("%d", &b);

  resultado = soma(a,b);


  printf("O valor da soma eh %d\n", resultado);



}