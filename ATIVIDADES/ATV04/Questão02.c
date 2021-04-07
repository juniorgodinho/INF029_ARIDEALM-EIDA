#include <stdio.h>
#include <stdlib.h>

int subtracao(int a, int b, int c){
  return a - b - c;
};

int main(){

  int resultado = 0, a, b, c;


  printf("Insira o valor de a\n");
  scanf("%d", &a);
  printf("Insira o valor de b\n");
  scanf("%d", &b);
  printf("Insira o valor de c\n");
  scanf("%d", &c);
  
  resultado = subtracao(a,b,c);


  printf("O valor da subtracao eh %d\n", resultado);



}