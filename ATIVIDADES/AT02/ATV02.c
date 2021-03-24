#include <stdio.h>
#include <stdlib.h>

void appRun();
void menu();
void tela();
void limparTela();
void somar();
void subtrair();
void multiplicar();
void dividir();

void appRun(){
	menu();
}
void menu(){
	
	int opcao = 1;
	int escolha = 0;
	while(opcao!=0){
		tela();
		scanf("%d", &escolha);
		switch(escolha){
			case 0:
				opcao=0;
				limparTela();
				break;
			case 1:
				limparTela();
				somar();
				break;
			case 2:
				limparTela();
				subtrair();
				break;
			case 3:
				limparTela();
				multiplicar();
				break;
			case 4:
				limparTela();
				dividir();
				break;
			default:
				limparTela();
				printf("Valor invalido, insira um valor valido\n");
				break;
		}
	}	
}
void limparTela(){
	system("cls");
}
void somar(){	
	int valorA = 0;
	int valorB = 0;
	printf("Informe o valor de a:\n");
	scanf("%d", &valorA);
	printf("Informe o valor de b:\n");
	scanf("%d", &valorB);
	printf("O resultado da soma e: %d\n", valorA + valorB);
}
void subtrair(){	
	int valorA = 0;
	int valorB = 0;
	printf("Informe o valor de a:\n");
	scanf("%d", &valorA);
	printf("Informe o valor de b:\n");
	scanf("%d", &valorB);
	printf("O resultado da subtracao e: %d\n", valorA - valorB);
}
void multiplicar(){	
	int valorA = 0;
	int valorB = 0;
	printf("Informe o valor de a:\n");
	scanf("%d", &valorA);
	printf("Informe o valor de b:\n");
	scanf("%d", &valorB);
	printf("O resultado da multiplicacao e: %d\n", valorA * valorB);
}
void dividir(){	
	int valorA = 0;
	int valorB = 0;
	printf("Informe o valor de a:\n");
	scanf("%d", &valorA);
	printf("Informe o valor de b:\n");
	scanf("%d", &valorB);
	printf("O resultado da divisao e: %d\n", valorA / valorB);
}
void tela(){
	printf("--------------------\n");
	printf("	Welcome		\n");
	printf("0 - SAIR			\n");
	printf("1 - SOMAR			\n");
	printf("2 - SUBTRAIR		\n");
	printf("3 - MULTIPLICAR		\n");
	printf("4 - DIVIDIR			\n");
	printf("--------------------\n");	
}
int main(){
	appRun();
  return 0;	
}
