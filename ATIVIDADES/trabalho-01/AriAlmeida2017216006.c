// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Ari de ALmeida Godinho Junior
//  email: junior.godinho0@gmail.com		
//  Matrícula: 2017216006
//  Semestre: 2-3-4.

//  Copyright © 2016 Renato Novais. All rights reserved.

//  
// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct DATA{
	int dia;
	int mes;
	int ano;
};
typedef struct DATA dma;

/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y){
  int soma = 0;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x){ //função utilizada para testes
  int fat = 1;
  return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char *data){
    int i_cont, j_cont, k_cont, data_valida;
    char string_dia[3], string_mes[3], string_ano[5];
    int dia=0, mes=0, ano=0;

    // QUEBRANDO A STRING

    for(i_cont=0; data[i_cont] != '/'; i_cont++){
        string_dia[i_cont] = data[i_cont];

    }



    for(i_cont = i_cont+1, j_cont=0; data[i_cont] != '/'; j_cont++, i_cont++){
        string_mes[j_cont] = data[i_cont];
    }

    for(i_cont = i_cont+1, k_cont=0; data[i_cont] != '\0'; k_cont++, i_cont++){
        string_ano[k_cont] = data[i_cont];
    }

    // CONVERTENDO DE CARACTERE PARA INTEIRO

    dia = atoi(string_dia);
    mes = atoi(string_mes);
    ano = atoi(string_ano);

    // VALIDANDO DATA



    if(dia > 31)
        return data_valida = 0;

	if(ano >= 0000 && ano <= 9999){
        	if (mes >= 1 && mes <= 12){
            		if (dia >= 1 && dia <= 31 && mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
                        data_valida = 1;
            		else if (dia >= 1 && dia <= 30 && mes == 4 || mes == 6 || mes == 9 || mes == 11)
                		data_valida = 1;
            		else if (dia >= 1 && dia <= 28 && mes == 2)
                		data_valida = 1;
            		else if (dia == 29 && mes == 2 && ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0)
                        data_valida = 1;
               		else
                		data_valida = 0;
       		}else{
                    data_valida = 0;
        	}
	}else{
		data_valida = 0;
	}

    return data_valida;


}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */

void DataConverter(char *data, int *dia, int *mes, int *ano){

    int i = 0, j, cont, parada = 0, condicao = 0;
    char string[5];

     for(j = 0; j < 3; j++){
        cont = 0;
        while(i < strlen(data)){

            if(data[i] - 47 == 0)
                break;
            if(((data[i] - 48 < 0) && (data[i] - 48 > 9)) || (data[i] - 48 < 0) || (data[i] - 48 > 9)){
                  parada = 1;
                  break;
            } else if(data[i] - 48 >= 0 && data[i] - 48 <= 9){
                string[cont++] = data[i];
            }
            i++;
        }

        if(parada){
          condicao = 1;
          break;
        }

        string[cont] = '\0'; //?para não pegar lixo

        if(j == 0 && cont <= 2) //?cont <= 2 para limitar a quantidade de casas
            *dia = atoi(string);
        else if(j == 1 && cont <= 2)
            *mes = atoi(string);
        else if(j == 2 && (cont == 2 || cont == 4))
            *ano = atoi(string);
        else
          condicao = 1;

        i++;
    }

    if(condicao)
      *dia = *mes = *ano = 0;
}

int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    int dias, meses, anos, nDias;
    int validador = 0;
    int inicioDia, inicioMes, inicioAno, finalDia, finalMes, finalAno;
    dma entraDATA;
    dma finalDATA;


 //data valida == 1, data invalida == 2;
    if(q1(datainicial) == 1){
        DataConverter(datainicial, &entraDATA.dia, &entraDATA.mes, &entraDATA.ano);
        inicioDia = entraDATA.dia;
        inicioMes = entraDATA.mes;
        inicioAno = entraDATA.ano;
    } else
        return 2;

 //data valida == 1, data invalida = 3
    if(q1(datafinal) == 1){
        DataConverter(datafinal, &finalDATA.dia, &finalDATA.mes, &finalDATA.ano);
        finalDia = finalDATA.dia;
        finalMes = finalDATA.mes;
        finalAno = finalDATA.ano;
    } else
        return 3;

 //data inicial > datafinal retorna '4'
    if((inicioAno > finalAno) || (inicioAno == finalAno && ((inicioMes > finalMes) ||  ((inicioMes == finalMes) && (inicioDia > finalDia))))){
        return 4;
    }

 //calculo diferenca valido == 1
    else{
        anos = finalAno - inicioAno;

    if(finalMes >= inicioMes){
        meses = finalMes - inicioMes;
        if(finalDia >= inicioDia){
            dias = finalDia - inicioDia;
        } else
            if(finalDia < inicioDia){
                dias = inicioDia - finalDia;
                meses = meses -1;
                if(((finalAno % 400 == 0 || (finalAno % 4 == 0 && finalAno % 100 != 0)) 
		    && (finalAno % 400 == 0 || (inicioAno % 4 == 0 && inicioAno % 100 != 0))) 
		   || ((finalAno % 400 == 0 || (finalAno % 4 == 0 && finalAno % 100 != 0)) 
		       && (finalAno % 400 != 0 || (finalAno % 4 != 0 && finalAno % 100 == 0)))){
                    if((finalMes == 2) || (inicioMes == 2)){
                        dias = 29 - dias;
                    } else
                        if(((finalMes == 4) || (finalMes == 6) || (finalMes == 9) || (finalMes == 11)) 
			   || ((inicioMes == 4) || (inicioMes == 6) || (inicioMes == 9) || (inicioMes == 11))){
                            dias = 30 - dias;
                        } else
                            if((finalMes == 1 || finalMes == 3 || finalMes == 5 || finalMes == 7 || finalMes == 8 
				|| finalMes == 10 || finalMes == 12) || (inicioMes == 1 || inicioMes == 3 
				|| inicioMes == 5 || inicioMes == 7 || inicioMes == 8 || inicioMes == 10 || inicioMes == 12)){
                                dias = 31 - dias;
                            }
                } else{
                    if((finalMes == 2) || (inicioMes == 2)){
                        dias = 28 - dias;
                    } else
                        if(((finalMes == 4) || (finalMes == 6) || (finalMes == 9) || (finalMes == 11)) 
			   || ((inicioMes == 4) || (inicioMes == 6) || (inicioMes == 9) || (inicioMes == 11))){
                            dias = 30 - dias;
                        } else
                            if((finalMes == 1 || finalMes == 3 || finalMes == 5 || finalMes == 7 
				|| finalMes == 8 || finalMes == 10 || finalMes == 12) || (inicioMes == 1 
				|| inicioMes == 3 || inicioMes == 5 || inicioMes == 7 || inicioMes == 8 
				|| inicioMes == 10 || inicioMes == 12)){                            
				    nDias = 31 - nDias;
                            }
                }
            }

        else if(finalMes < inicioMes){
                meses = inicioMes - finalMes;
                anos = anos - 1;
                meses = 12 - meses;

            if(finalDia >= inicioDia){
                dias = finalDia - inicioDia;
            } else
                if(finalDia < inicioDia){
                    dias = inicioDia - finalDia;
                    meses = meses -1;
                    if(((finalAno % 400 == 0 || (finalAno % 4 == 0 && finalAno % 100 != 0)) && (inicioAno % 400 == 0 
			|| (inicioAno % 4 == 0 && inicioAno % 100 != 0))) || ((finalAno % 400 == 0 
			|| (finalAno % 4 == 0 && finalAno % 100 != 0)) && (inicioAno % 400 != 0 
			|| (inicioAno % 4 != 0 && inicioAno % 100 == 0)))){
                        if((finalMes == 2) || (inicioMes == 2)){
                            dias = 29 - dias;
                        } else

                        if((((finalMes == 4) || (finalMes == 6) || (finalMes == 9) || finalMes == 11)) 
			   || ((inicioMes == 4) || (inicioMes == 6) || (inicioMes == 9) || (inicioMes == 11))){
                            dias = 30 - dias;
                        } else

                        if((finalMes == 1 || finalMes== 3 || finalMes == 5 || finalMes == 7 || finalMes == 8 
			    	|| finalMes == 10 || finalMes == 12) || (inicioMes == 1 || inicioMes == 3 || inicioMes == 5 
				|| inicioMes == 7 || inicioMes == 8 || inicioMes == 10 || inicioMes == 12)){
                            	dias = 31 - dias;
                        }
                    }
                else{
                    if((finalMes == 2) || (inicioMes == 2)){
                        dias = 28 - dias;
                    } else

                    if(((finalMes == 4) || (finalMes == 6) || (finalMes == 9) || (finalMes == 11)) || ((inicioMes == 4) 
			|| (inicioMes == 6) || (inicioMes == 9) || (inicioMes == 11))){
                        dias = 30 - dias;
                    } else

                    if((finalMes == 1 || finalMes == 3 || finalMes == 5 || finalMes == 7 || finalMes == 8 
			|| finalMes == 10 || finalMes == 12) || (inicioMes == 1 || inicioMes == 3 
			|| inicioMes == 5 || inicioMes == 7 || inicioMes == 8 || inicioMes == 10 || inicioMes == 12)){
                        dias = 31 - dias;
                    }
                }
            }
        }
    }
    validador = 1;
  }
 //validador == 1, return diferenca das datas
    if(validador == 1){
        *qtdDias = dias;
        *qtdMeses = meses;
        *qtdAnos = anos;
        return 1;
  }
}
/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    
    int i_cont, qtd_ocorrencias=0;
    
    if(isCaseSensitive==0){
        for(i_cont=0; texto[i_cont] != '\0'; i_cont++){
            if(texto[i_cont]==c-32 || texto[i_cont]==c+32 || texto[i_cont]==c)
                qtd_ocorrencias++;
        }
    }
    else if(isCaseSensitive==1){
        for(i_cont=0; texto[i_cont] != '\0'; i_cont++){
            if(texto[i_cont]==c)
                qtd_ocorrencias++;
        }
    }
    return qtd_ocorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    
    int i_cont=0, j_cont=0, k_cont=0, l_cont=0;
    int contador1=0, contador2=0, posicao=0;
    int numero_ocorrencias=0;
    
    if(strlen(strBusca)==1){
        for(i_cont=0; strTexto[i_cont] != '\0'; i_cont++){
            if(strTexto[i_cont]==strBusca[0])
                contador1++;
        }
        return contador1;
        
    }
    
    for(i_cont=0; strTexto[i_cont] != '\0'; i_cont++){
        contador1=0;
        if(strTexto[i_cont]==-61){
            contador2++;
        }
        if(strTexto[i_cont] == strBusca[j_cont]){
            for(k_cont= i_cont+1, l_cont= j_cont+1; strBusca[l_cont] == strTexto[k_cont]; k_cont++, l_cont++)
                contador1++;
        }
        if(contador1==strlen(strBusca)-1){
            posicoes[posicao++]=(i_cont+1) - contador2;
            posicoes[posicao++]=k_cont - contador2;
            numero_ocorrencias++;
        }
    }
    return numero_ocorrencias;
}
    
    
       

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){
    
    int valor_auxiliar=0, valor_invertido=0;
    
    while(num > 0){
        valor_auxiliar = num % 10;
        valor_invertido = valor_invertido * 10 + valor_auxiliar;
        num = num/10;
    }
    return valor_invertido;
    
}

/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numero_base, int numero_busca){
    
        
    int numero_auxiliar=0, numero_ocorrencias=0, tamanho_inteiro=1;
    
    
    numero_auxiliar = numero_busca;
    
    while(numero_auxiliar != 0){
        tamanho_inteiro = tamanho_inteiro * 10;
        numero_auxiliar = numero_auxiliar / 10;
    }
    
    numero_auxiliar = numero_base;
    
    while(numero_auxiliar != 0){
        if(numero_auxiliar % tamanho_inteiro == numero_busca){
            numero_ocorrencias++;
            numero_auxiliar = numero_auxiliar / 10;
        }else
            numero_auxiliar = numero_auxiliar / 10;
    }
    
    return numero_ocorrencias;
}