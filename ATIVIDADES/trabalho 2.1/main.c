#include <stdio.h> 
#include <stdlib.h>

#include "EstruturasVetores.h"

#define TAM_AUX 50

int main(){
    
    int exit=0;
    int op=0;
    int ret=0;
    int value=0, position=0, size=0, new_size=0;
    int vetorAux[TAM_AUX];
    int tamanho;
    
    start_program(); // Atribuindo NULL;
    
    while(!exit){
        
        show_menu(); // Mostrando o menu de opcoes;
        scanf("%d", &op);
        switch(op){
            case 0:
                clear_screen(); // Limpando tela;
                end_program();  // Liberando memoria;
                exit=1;
                break;
            case 1:
                clear_screen();
                get_value(&value); // Capturando valor;
                get_position(&position); // Capturando posicao;
                ret = inserirNumeroEmEstrutura(value, position); // Inserindo valor na estrutura;
                info_status(ret); // informando status ao usuario;
                break;
            case 2:
                clear_screen();
                get_position(&position);
                ret = excluirNumeroDoFinaldaEstrutura(position); // Excluindo o ultimo numero da estrutura
                info_status(ret);
                break;
            case 3:
                clear_screen();
                get_position(&position);
                get_value(&value);
                ret = excluirNumeroEspecificoDeEstrutura(value, position); // Excluindo um numero especifico da estrutura
                info_status(ret);
                break;
            case 4:
                clear_screen();
                get_position(&position);
                ret = getDadosEstruturaAuxiliar(position, vetorAux); // Pegando os dados de uma estrutura auxiliar
                info_status(ret);
                if(ret == SUCESSO){
                    print_struct(position, vetorAux); // Informando os dados da estrutura;
                }
                break;
            case 5:
                clear_screen();
                ret = getDadosDeTodasEstruturasAuxiliares(vetorAux);
                info_status(ret);
                break;
            case 6:
                clear_screen();
                get_position(&position);
                ret = getDadosOrdenadosEstruturaAuxiliar(position, vetorAux);
                info_status(ret);
                if(ret == SUCESSO){
                    print_struct(position, vetorAux);
                }
                break;
            case 7:
                clear_screen();
                ret = getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorAux);
                info_status(ret);
                printf("%d\n", vetorAux[0]);
                printf("%d\n", vetorAux[1]);
                printf("%d\n", vetorAux[2]);
                printf("%d\n", vetorAux[3]);
                printf("%d\n", vetorAux[4]);              
                break;
            case 8:
                clear_screen();
                get_position(&position);
                get_new_size(&new_size); // Pegando novo tamanho;
                ret = modificarTamanhoEstruturaAuxiliar(position, new_size); // Modificando tamanho da estrutura auxiliar
                info_status(ret);
                break;
            case 9:
                clear_screen();
                get_position(&position);
                get_size(&size); // Pegando o tamanho da estrutura
                ret = criarEstruturaAuxiliar(size, position); // Criando a estrutura auxiliar
                info_status(ret);
                break;
            }
    }
    return 0;
}