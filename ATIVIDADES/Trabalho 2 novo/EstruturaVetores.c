#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstruturaVetores.h"

#define TAM 10
#define MAX_TAM 100


typedef struct estrutura{
    int size;
    int qtd_numbers;
    int *aux_array;
    
}list;

list main_array[TAM];

void info_status(int value){
    
    if(value == SUCESSO){
                        
        clear_screen();
        puts("Verifying....Status SUCESS!");
                        
    }else if(value == SEM_ESPACO){
                        
        clear_screen();
        puts("Verifying...Status FAIL -> Struct full.");
                        
    }else if(value == SEM_ESTRUTURA_AUXILIAR){
                        
        clear_screen();
        puts("Verifying...Status FAIL -> Doesn't exist struct.");
        
    }else if(value == JA_TEM_ESTRUTURA_AUXILIAR){
        
        clear_screen();
        puts("Verifying...Status FAIL -> Struct already created.");
        
    }else if(value == TAMANHO_INVALIDO){
        
        clear_screen();
        puts("Verifying...Status FAIL -> Invalide size.");
        
    }else if(value == NOVO_TAMANHO_INVALIDO){
        
        clear_screen();
        puts("Verifying...Status FAIL -> Invalid new size.");
            
    }else if(value == SEM_ESPACO_DE_MEMORIA){
        
        clear_screen();
        puts("Verifying...Status FAIL -> Memory full.");
        
    }else if(value == ESTRUTURA_AUXILIAR_VAZIA){
        
        clear_screen();
        puts("Verifying...Status FAIL -> Struct is empty.");
        
    }else if(value == NUMERO_INEXISTENTE){
        
        clear_screen();
        puts("Verifying...Status FAIL -> Doesn't existe number");
                         
    }else{
                        
        clear_screen();
        puts("Verifying...Status FAIL -> Invalid position.");
        
    }
}                  
void show_menu(){  

    puts(" ======================================");
    puts("|            BEM VINDO                 |");
    puts("| Digite a opcao desejada:             |");
    puts("| 0 - Sair                             |");
    puts("| 1 - Inserir valor                    |");
    puts("| 2 - Excluir valor final da estrutura |");
    puts("| 3 - Excluir um valor da estrurura    |");
    puts("| 4 - Listar uma estrutura             |");
    puts("| 5 - Listar todas as estruturas       |");
    puts("| 6 - Listar e ordenar uma estrutura   |");
    puts("| 7 - Listar e ordenar tudo            |");
    puts("| 8 - Modificar tamanho da estrutura   |");
    puts("| 9 - Criar estrutura auxiliar         |");
    puts(" ======================================");
}
void inicializar(){
    
    int i_cont=0;
    
    while(i_cont<TAM){
        
        main_array[i_cont].aux_array = NULL;
        main_array[i_cont].size = 0;
        main_array[i_cont].qtd_numbers = 0;        
        i_cont++;
    }
}
void finalizar(){
    
    int i_cont=0;
    
    while(i_cont<TAM){
        
    free(main_array[i_cont].aux_array);
    i_cont++;
    }
}
void clear_screen(){
    
    system("clear");
}
int search_number(int value, int position){
    
    int i_cont=0;
        
    while(i_cont < main_array[position-1].qtd_numbers){
        
        if(value == main_array[position-1].aux_array[i_cont]){
            
            return i_cont;            
        }
        i_cont++;
    }
    
    return NUMERO_INEXISTENTE;
}        
void get_value(int *value){
    
    int number=0;
    
    puts("Informe o valor:");
    scanf("%d", &number);
    
    *value = number;
    
}
void get_position(int *position){
    
    int number=0;
    
    puts("Informe a posicao:");
    scanf("%d", &number);
    
    *position = number;
}
void get_size(int *size){
    
    int number=0;
    
    puts("Informe o tamanho da estrutura:");
    scanf("%d", &number);
    
    *size = number;
}
void get_new_size(int *new_size){
    
    int number=0;
    
    puts("Informe o novo tamanho da estrutura:");
    scanf("%d", &number);
    
    *new_size = number;
}
int test_position(int position){
    
    if(position<1 || position>10){
        
        return POSICAO_INVALIDA;
        
    }else{
        
        return SUCESSO;
        
    }
}
int inserirNumeroEmEstrutura(int value, int position){

    if(test_position(position) != SUCESSO){
        
        return POSICAO_INVALIDA;
        
    }else if(main_array[position-1].aux_array == NULL){
        
        return SEM_ESTRUTURA_AUXILIAR;
        
    }else if(main_array[position-1].qtd_numbers >= main_array[position-1].size){
        
        return SEM_ESPACO;
        
    }else{
        
        main_array[position-1].aux_array[main_array[position-1].qtd_numbers] = value;        
        main_array[position-1].qtd_numbers++;
        
        return SUCESSO;
    }
}
int criarEstruturaAuxiliar(int size, int position){
    
    
    if(test_position(position) != SUCESSO){
        
        return POSICAO_INVALIDA;
        
    }else if(main_array[position-1].aux_array != NULL){
        
        return JA_TEM_ESTRUTURA_AUXILIAR;
        
    }else if(size<1){
        
        return TAMANHO_INVALIDO;
        
    }else if(size>MAX_TAM){
        
        return SEM_ESPACO_DE_MEMORIA;
        
    }else{
        
        main_array[position-1].aux_array = (int*) malloc(size * sizeof(int));
        main_array[position-1].size = size;
        return SUCESSO;
        
    }
}
int excluirNumeroDoFinaldaEstrutura(int position){
    
    if(test_position(position) != SUCESSO){
        
        return POSICAO_INVALIDA;
        
    }else if(main_array[position-1].aux_array == NULL){
        
        return SEM_ESTRUTURA_AUXILIAR;
        
    }else if(main_array[position-1].qtd_numbers < 1){
        
        return ESTRUTURA_AUXILIAR_VAZIA;
        
    }else{
        
        main_array[position-1].qtd_numbers--;
        return SUCESSO;
        
    }
}
int excluirNumeroEspecificoDeEstrutura(int value, int position){
    
    int valid_search=0;
    
    if(test_position(position) != SUCESSO){
        
        return POSICAO_INVALIDA;
        
    }else if(main_array[position-1].aux_array == NULL){
        
        return SEM_ESTRUTURA_AUXILIAR;
        
    }else if(main_array[position-1].qtd_numbers < 1){
        
        return ESTRUTURA_AUXILIAR_VAZIA;
        
    }else{
        
        valid_search = search_number(value, position);
        
        if(valid_search == NUMERO_INEXISTENTE){
            
            return NUMERO_INEXISTENTE;
            
        }else{
            
            delete_number(position, valid_search);
            return SUCESSO;
        }
    }
}
void delete_number(int position, int position_search){
    
    int i_cont=0;
    
    for(i_cont = position_search; i_cont < main_array[position-1].size; i_cont++){
        
        main_array[position-1].aux_array[i_cont] = main_array[position-1].aux_array[i_cont+1];
    }
    main_array[position-1].qtd_numbers--;
    
    for(i_cont=0; i_cont < main_array[position-1].qtd_numbers; i_cont++){
        
        printf("%d\n", main_array[position-1].aux_array[i_cont]);
    }
}
int getDadosEstruturaAuxiliar(int position, int vetorAux[]){
    
    int i_cont=0;
    
    if(test_position(position) != SUCESSO){
        
        return POSICAO_INVALIDA;
        
    }else if(main_array[position-1].aux_array == NULL){
        
        return SEM_ESTRUTURA_AUXILIAR;
        
    }else if(main_array[position-1].qtd_numbers < 1){
        
        return ESTRUTURA_AUXILIAR_VAZIA;
        
    }else{
        
        for(i_cont=0; i_cont < main_array[position-1].qtd_numbers; i_cont++){
        
        vetorAux[i_cont] = main_array[position-1].aux_array[i_cont];
        }
        
        return SUCESSO;
        
    }
    
    
}
void print_struct(int position, int *vetorAux){
    
    int i_cont=0;
    
    printf("Estrutura nº %d:\n", position);
    
    for(i_cont=0; i_cont < main_array[position-1].qtd_numbers; i_cont++){
        
        printf("%d ", vetorAux[i_cont]);
    }
    puts("");
    
}
int getDadosOrdenadosEstruturaAuxiliar(int position, int *vetorAux){
    
    int i_cont=0, j_cont=0, aux_value=0;;
    
    if(test_position(position) != SUCESSO){
        
        return POSICAO_INVALIDA;
        
    }else if(main_array[position-1].aux_array == NULL){
        
        return SEM_ESTRUTURA_AUXILIAR;
        
    }else if(main_array[position-1].qtd_numbers < 1){
        
        return ESTRUTURA_AUXILIAR_VAZIA;
        
    }else{
        // Atribuindo o vetor auxiliar com os dados
        for(i_cont=0; i_cont < main_array[position-1].qtd_numbers; i_cont++){
            vetorAux[i_cont] = main_array[position-1].aux_array[i_cont];
        }
        
        // ordenando com insertion sort 
        insertionSort(vetorAux, main_array[position-1].qtd_numbers);
 
        return SUCESSO;
    }
}
void insertionSort(int *array, int size){

	int i_cont=0, j_cont=0, aux_value=0;

	for(i_cont=1; i_cont<size; i_cont++){

		aux_value=array[i_cont];

		for(j_cont=i_cont-1; j_cont>=0 && array[j_cont]>aux_value; j_cont--){

			array[j_cont+1]=array[j_cont];
		}

		array[j_cont+1]=aux_value;
	}
}
int modificarTamanhoEstruturaAuxiliar(int position, int new_size){
    
    int realloc_size=0;
    
    realloc_size = main_array[position-1].size + new_size;
    
    if(test_position(position) != SUCESSO){
        
        return POSICAO_INVALIDA;
        
    }else if(main_array[position-1].aux_array == NULL){
        
        return SEM_ESTRUTURA_AUXILIAR;
        
    }else if(realloc_size<1){
        
        return NOVO_TAMANHO_INVALIDO;
        
    }else if(realloc_size>MAX_TAM){
        
        return SEM_ESPACO_DE_MEMORIA;
        
    }else{
        
        main_array[position-1].aux_array = (int*) realloc(main_array[position-1].aux_array, sizeof(int) * new_size);
        main_array[position-1].size = new_size;
        if(main_array[position-1].qtd_numbers < main_array[position-1].size){
            
            main_array[position-1].qtd_numbers = new_size;
        }
        return SUCESSO;
    }
}
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){ 
    
    int i_cont=0, j_cont=0, k_cont=0;
    
       
    while(i_cont < TAM){
        
        if(main_array[i_cont].aux_array == NULL){
            i_cont++;
        
        }else if(main_array[i_cont].qtd_numbers > 0 ){
            
            for(j_cont=0; j_cont < main_array[i_cont].qtd_numbers; j_cont++){
                
                vetorAux[k_cont] = main_array[i_cont].aux_array[j_cont];
                k_cont++;
            }
            i_cont++;
        }else{
            i_cont++;
        }
    }
    return SUCESSO;
      
}
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){ // INCOMPLETO

    int i_cont=0, j_cont=0, k_cont=0;
    
       
    while(i_cont < TAM){
        
        if(main_array[i_cont].aux_array == NULL){
            i_cont++;
        
        }else if(main_array[i_cont].qtd_numbers > 0 ){
            
            for(j_cont=0; j_cont < main_array[i_cont].qtd_numbers; j_cont++){
                
                vetorAux[k_cont] = main_array[i_cont].aux_array[j_cont];
                k_cont++;
            }
            i_cont++;
        }else{
            i_cont++;
        }
    }
    insertionSort(vetorAux, k_cont); 
    return SUCESSO;
}
int getQuantidadeElementosEstruturaAuxiliar(int position){
    
    int value=0;
    
    if(test_position(position) != SUCESSO){
        
        return POSICAO_INVALIDA;
        
    }else if(main_array[position-1].aux_array == NULL){
        
        return SEM_ESTRUTURA_AUXILIAR;
        
    }else if(main_array[position-1].qtd_numbers < 1){
        
        return ESTRUTURA_AUXILIAR_VAZIA;
    
    }else{
        
        value = main_array[position-1].qtd_numbers;        
        return value;
        
    }
}