

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define num 500

struct dados{
	char nome[256], mat[12], cpf[12], sexo[2];
	int dat, mes, ano;
};

struct disciplina{
	char n[256], semt[3], cod[10], prof[256];
};

int linha=10;
int coluna=10;

void menu(int *n);
void menu2(int *n);
int relatorio(int op2);
void menu_Disc(int *n);
int vald_data(int d, int m, int a);
int val_CPF(char ex[]);
void in_aluno(struct dados *t, struct dados x[], int *n, int *ptr);
void ex_aluno(char ex[256],struct dados a[], int *cont);
void at_aluno(char ex[256], struct dados a[], int *n);
void in_prof(struct dados p[],int *n, int *ptr);
void ex_prof(char ex[256], struct dados p[], int *cont);
void at_prof(char ex[256], struct dados p[], int *n);
void in_Disc(struct disciplina d[], int *n, int *ptr);
void ex_Disc(char ex[256], struct disciplina d[], int *cont);
void at_Disc(char ex[256], struct disciplina d[], int *n);
void in_Aldisc(char ex[256], int aluno[][coluna], struct disciplina d[], int *cont, int *n);
void ex_Aldisc(char ex[256], struct disciplina d[], int *cont, int aluno[][coluna], int *n);
void busca(char ex[256], struct dados *a, struct dados p[], int *ptr, int *cont);
int compara_data(const void *a, const void *b);
int compara_nome(const void *a, const void *b);
void listar(struct dados x[], int *cont);
void listar_disc(struct disciplina d[], int *cont);
void listar_PorSexo(struct dados *x, int *cont);
void listar_PordNome(struct dados x[], int *cont);
void listar_PordData(struct dados x[], int *cont);
void listar_UmaDis(int aluno[][coluna], int *cont, int *n, int *ptr, struct dados *a, struct disciplina d[]);
void aniversariantes(struct dados p[],struct dados a[], int *ptr, int *cont);

int main(){
	
	struct dados *a, *ptr;
	struct dados p[num];
	struct disciplina d[num];
	int op, op2, op3,tam, tam2, tam3, tam4;
	int aluno[linha][coluna];
	char ex[256];
  
	a=(struct dados*)malloc(num*sizeof(struct dados));
	
	printf("\t*****Cadastro escolar****\n\n");
	
	do{
		printf("******\n");
		menu(&op);
	
		setbuf(stdin, NULL);
		system("cls");
		switch(op){
		  
			case 1: //cadastro aluno
			printf("\tCadastro aluno\n");
			do{
					menu2(&op2);	
					setbuf(stdin, NULL);
					system("cls");
					
				//inserir	
				if(op2==1){
					a=(struct dados*)realloc(a,num*sizeof(struct dados));
					in_aluno(ptr, a,&op2, &tam);//alterei aqui
					//tam eh o tamanho do vetor
				//excluir	
				}else if(op2==2){
				  
					ex_aluno(ex,a, &tam);//colocando &tam j?? pega de todas as fun????es o endere??o onde est?? e sem ela ?? o valor
				
				//atualizar
				}else if(op2==3){
				  
				  at_aluno(ex, a, &tam);
				  
				}
				
			}while(op2!=0);
			break;
			
			case 2: //cadastro professor
			printf("\tCadastro professor\n");
			do{
					menu2(&op2);
					setbuf(stdin, NULL);
					system("cls");
					
				//inserir	
				if(op2==1){
				
					in_prof(p,&op2, &tam2);
					
				//excluir	
				}else if(op2==2){
				  
					ex_prof(ex,p, &tam2);
				
				//atualizar
				}else if(op2==3){
				  
				  at_prof(ex, p, &tam2);
				  
				}
				
			}while(op2!=0);
			break;
			
			case 3: //disciplina
			  printf("\tCadastro disciplina\n");
			  do{
			    menu_Disc(&op2);
			    setbuf(stdin, NULL);
					system("cls");
			    if(op2==1)//inserir
			      in_Disc(d, &op2, &tam3);
			     
		        else if(op2==2)//excluir
		            ex_Disc(ex, d, &tam3);
		            
		        else if(op2==3)//atualizar
		            at_Disc(ex, d, &tam3);
          
          	    else if(op2==4)//inserir aluno
          	   		in_Aldisc(ex, aluno, d, &tam3, &tam4);
          
               else if(op2==5)//excluir aluno
               
               		ex_Aldisc(ex, d, &tam3, aluno, &tam4);
			    
			  }while(op2!=0);
			  	
			break;
				
			case 4: //relatorio
			do{
			  
			  op2=relatorio(op2);
			
			    if(op2==1){//listar alunos
			      printf("\nLista de alunos: \n\n");
			      listar(a, &tam);
			      
			    }else if(op2==2){//listar professores
			    	printf("\nLista de professores: \n\n");
			      	listar(p, &tam2);
			     
			   }else if(op2==3)//listar disciplinas
			      listar_disc(d, &tam3);
			      
			   else if(op2==4)//listar uma disciplina e os alunos
			   	  listar_UmaDis(aluno, &tam3, &tam4, &tam, a, d);
			   
			   else if(op2==5)//listar alunos por sexo
			      listar_PorSexo(a, &tam);
			
			   else if(op2==6)//listar alunos por ordem alfabetica
			      listar_PordNome(a, &tam);
			      
			   else if(op2==7)//listar alunos por data de nascimento
			   	  listar_PordData(a, &tam);
			      
			   else if(op2==8)//listar professores por sexo
			   	  listar_PorSexo(p, &tam2);
			      
			   else if(op2==9)//listar professores por ordem alfabetica
			      listar_PordNome(p, &tam2);
			   
			   else if(op2==10)//listar professores por data de nascimento
			      listar_PordData(p, &tam2);
			      
			   else if(op2==11)//listar aniversariantes
			      aniversariantes(p,a,&tam2,&tam);
			      
			   else if(op2==12)//listar de acordo com uma string de busca
				  busca(ex,a,p, &tam, &tam2);
				  	      
			}while(op2!=0);  
			break;
			
			default:
				break;
		}
		
	
	}while(op!=0);
	
	free(a);
	//free(p);
	//free(d);
	
	printf("\nCADASTRO ESCOLAR FINALIZADO!!\n");
	
	return 0;
}

void menu(int *n){
	
	printf("1-Cadastrar aluno;\n");
	printf("2-Cadastrar professor;\n");
	printf("3-Cadastrar disciplina;\n");
	printf("4-Relat??rio;\n");
	printf("0-Sair;\n");
	scanf("%d", &*n);
	
}//menu 1

void menu2(int *n){
	printf("1-Inserir;\n");
	printf("2-Excluir;\n");
	printf("3-Atualizar;\n");
	printf("0-Sair;\n");
	scanf("%d", &*n);
}//menu 2

int relatorio(int op2){
  printf("\n**********RELATORIO*********\n");
  printf("\n1-Listar Alunos;\n");
  printf("2-Listar Professores;\n");
  printf("3-Listar Disciplinas;\n");
  printf("4-Listar uma disciplina;\n");
  printf("5-Listas Alunos por sexo;\n");
  printf("6-Listar Alunos ordernados por nome;\n");
  printf("7-Listar Alunos ordenados por data de nascimento;\n");
  printf("8-Listar Professores por sexo;\n");
  printf("9-Listar Professores ordenados por nome;\n");
  printf("10-Listar Professores ordenados por data de nascimento;\n");
  printf("11-Aniversariantes do m??s;\n");
  printf("12-Lista de pessoas a partir de, m??nimo 3 letras;\n");
  printf("0-Sair;\n");
  scanf("%d", &op2);
  system("cls");
  
  return op2;
  
}//relatorio

void menu_Disc(int *n){
  printf("1-Inserir;\n");
	printf("2-Excluir;\n");
	printf("3-Atualizar;\n");
	printf("4-Inserir aluno;\n");
	printf("5-Excluir aluno;\n");
	printf("0-Sair;\n");
	scanf("%d", &*n);
}//menu da disciplina

int vald_data(int d, int m, int a){//valida????o da data
	
	int b=0;
	
	if(d<0 || d>31 || m<1 || m>12 || a<1900){
		b=0;
	}else{
		if(a%4==0 && a%100!=0 && a%400==0){
			if(m==2){
				if(d>=1 && d<=29)
					b=1;
				else 
					b=0;
			}
		}else{
			if(m==2){
				if(d>=1 && d<=28)
					b=1;
				else 
					b=0;
			}else if(m==4 || m==6 || m==9 || m==11){
				if(d>=1 && d<=30)
					b=1;
				else 
					b=0;
			}else{
				if(d>=1 && d<=31)
					b=1;
				else 
					b=0;
			}
		}
	}	
	
 return b;
}

int val_CPF(char ex[]){//validar cpf
	
	int i, j, d1=0, d2=0;
	int qtd=strlen(ex);
	
	if(qtd!=11){
		return 0;
		printf(" %d\n", qtd);
	}	
	else if((strcmp(ex,"00000000000")==0) || (strcmp(ex,"11111111111") == 0) || (strcmp(ex,"22222222222") == 0) ||
            (strcmp(ex,"33333333333") == 0) || (strcmp(ex,"44444444444") == 0) || (strcmp(ex,"55555555555") == 0) ||
            (strcmp(ex,"66666666666") == 0) || (strcmp(ex,"77777777777") == 0) || (strcmp(ex,"88888888888") == 0) ||
            (strcmp(ex,"99999999999") == 0))
            return 0;
	else{
		for(i=qtd-3, j=2; i>=0; j++, i--)
			d1+=(ex[i]-48)*j;
			
		d1%=11;
		
		if(d1<2)
			d1=0;
		else
			d1=11-d1;
		if((ex[9]-48)!=d1)
			return 0;
		else{
			for(i=qtd-2, j=2; i>=0; j++, i--)
				d2+=(ex[i]-48)*j;//-48 ?? relacionado ao tabela ascii
		
			d2%=11;
		
			if(d2<2)
				d2=0;
			else
				d2=11-d2;
			if((ex[10]-48)!=d2)
				return 0;
		}	
	}
	return 1;
		
}

void in_aluno(struct dados *t, struct dados x[], int *n, int *ptr){//inserir aluno
	//adicionei int *ptr para ser o tamanho do vetor
  static int j=0;//acumulativa
  int op;
  t=x;
  
  do{
    setbuf(stdin, NULL);
    printf("Nome: ");
		scanf("%s", t[j].nome);
		setbuf(stdin, NULL);
		printf("Matricula: ");
		scanf("%s",t[j].mat);
		setbuf(stdin, NULL);
		printf("Sexo [apenas letra]: ");
		scanf("%s",t[j].sexo);
		setbuf(stdin, NULL);
		printf("Data de nascimento [dd/mm/aaaa]: ");
		do{
			setbuf(stdin, NULL);
			scanf("%d/%d/%d", &t[j].dat, &t[j].mes, &t[j].ano);
			op=vald_data(t[j].dat, t[j].mes, t[j].ano);
			if(op==0)
				printf("\nData errada, digite novamente\n");
		}while(op!=1);
		setbuf(stdin, NULL);
		printf("CPF [apenas numeros]: ");
		do{
			setbuf(stdin, NULL);
			scanf("%s", t[j].cpf);
			op=val_CPF(t[j].cpf);
			if(op==0)
				printf("\nCPF errada, digite novamente\n");
		}while(op!=1);
		j++;
		printf("\n1-Continuar Cadastro\n0-Sair\n");
		do{
			scanf("%d", &*n);
			if(*n<0 || *n>1)
				printf("Opcao errada, digite novamente: \n\n");
		}while(*n<0 || *n>1);
		
		setbuf(stdin, NULL);
		system("cls");
		
  
  }while(*n!=0);
  
  t=(struct dados*)realloc(t,j*sizeof(struct dados));

	*ptr=j;//conteudo que ptr esta apontando de j
	//*ptr=&j; ta certo tb
	//ptr=&j;... isso n??o vai o valor 
	//printf(" *ptr = %d\n", *ptr);//conteudo da j apontada por ptr 
	//printf(" &ptr= %d\n", &ptr);//endere??o de um ptr, sem ser o ponteiro
	//printf(" ptr= %d\n", ptr);//endere??o de ptr
	//printf(" &j= %d\n", &j);//endere??o de j
	//printf(" j= %d\n", j);// conteduo de j
  //global=j;
  //return j;
}

void ex_aluno(char ex[256],struct dados a[], int *cont){//excluir aluno
  
  //struct copia *qtd;
  int i, op, x, pos;
  //qtd=(struct copia *)malloc(*cont*sizeof(struct copia));
  
  do{
      setbuf(stdin, NULL);
      printf("\nQuem deseja excluir: ");
      scanf("%s", ex);
      
      //comparar os nomes e pegar a posi????o que ?? igual
      for(i=0; i<*cont; i++){
        int b=0;
        if(strcmp(ex, a[i].nome)==0){
          pos=i;
          b=1;
        }
          if(b==1){
            *cont-=1;
            break;
          }
            
     }
     //mudar data de nascimento
     for(x=pos; x<*cont; x++){
			a[x].dat=a[x+1].dat;
			a[x].mes=a[x+1].mes;
			a[x].ano=a[x+1].ano;	
	}
     
     //mudar a posi????o 
     for(x=pos; x<*cont; x++){
       //qtd[x].NOME=strlen(a[x].nome);
       //qtd[x].MAT=strlen(a[x].mat);
       //qtd[x].CPF=strlen(a[x].cpf);
       //qtd[x].SEXO=strlen(a[x].sexo);
       strncpy(a[x].nome, a[x+1].nome, strlen(a[x].nome));//NOME
       strncpy(a[x].mat, a[x+1].mat, strlen(a[x].mat));//MATRICULA
       strncpy(a[x].cpf, a[x+1].cpf, strlen(a[x].cpf));//CPF
       strncpy(a[x].sexo, a[x+1].sexo, strlen(a[x].sexo));//SEXO
     }
     
      printf("\n1-Outra Exclus??o\n0-Sair\n");
  	  do{
			scanf("%d", &op);
			if(op<0 || op>1)
				printf("Opcao errada, digite novamente: \n\n");
		}while(op<0 || op>1);
  		setbuf(stdin, NULL);
  		system("cls");
		
    
  }while(op!=0);
  
  
}

void at_aluno(char ex[256], struct dados a[], int *n){//atualizar
  
   int b, i, pos, op2, op3, op;
   //n=global;
   
   do{
     setbuf(stdin, NULL);
     printf("\nQuem deseja atualizar: ");
     scanf("%s", ex);
     
     //comparar os nomes e pegar a posi????o que ?? igual
      for(i=0; i<*n; i++){
        int b=0;
        if(strcmp(ex, a[i].nome)==0){
          pos=i;
          b=1;
        }
          if(b==1)
            break;
     }
     
     do{
       setbuf(stdin, NULL);
       printf("1-Nome\n2-Matricula\n3-Data de nascimento\n4-Sexo\n5-CPF\n0-Sair\n");
       scanf("%d", &op2);
       
       if(op2==1){
          setbuf(stdin, NULL);
          printf("Digite nome atualizado: ");
				  scanf("%s",a[pos].nome);
       }else if(op2==2){
         setbuf(stdin, NULL);
         printf("Digite matricula atualizada: ");
				 scanf("%s",a[pos].mat);
       }else if(op2==3){
         setbuf(stdin, NULL);
         printf("Digite data de nascimento atualizada: ");
         scanf("%d/%d/%d", &a[pos].dat, &a[pos].mes, &a[pos].ano);
       }else if(op2==4){
         setbuf(stdin, NULL);
         printf("Digite sexo atualizado: ");
					scanf("%s",a[pos].sexo);
       }else if(op2==5){
         setbuf(stdin, NULL);
         printf("Digite CPF atualizado: ");
				 scanf("%s",a[pos].cpf);
       }else if(op2==0)
        break;
        printf("\n1-Continuar Atualiza????o do aluno %s\n0-Sair\n", a[pos].nome);
        do{
			scanf("%d", &op);
			if(op<0 || op>1)
				printf("Opcao errada, digite novamente: \n\n");
		}while(op<0 || op>1);
      setbuf(stdin, NULL);
  	  system("cls");
       
     }while(op!=0);
     
     printf("\n1-Atualizar outro aluno\n0-Sair\n");//ver se tira
     do{
		scanf("%d", &op3);
		if(op3<0 || op3>1)
			printf("Opcao errada, digite novamente: \n\n");
		}while(op3<0 || op3>1);
  	 scanf("%d", &op3);
     setbuf(stdin, NULL);
  	 system("cls");
  		
   }while(op3!=0);
  
}

void in_prof(struct dados p[],int *n, int *ptr){//inserir aluno
	//adicionei int *ptr para ser o tamanho do vetor
  static int j=0;//acumulativa
  int op;
  do{
    setbuf(stdin, NULL);
    printf("Nome: ");
		scanf("%s",p[j].nome);
		setbuf(stdin, NULL);
		printf("Matricula: ");
		scanf("%s",p[j].mat);
		setbuf(stdin, NULL);
		printf("Sexo [apenas letra]: ");
		scanf("%s",p[j].sexo);
		setbuf(stdin, NULL);
		printf("Data de nascimento [dd/mm/aaaa]: ");
		do{
			setbuf(stdin, NULL);
			scanf("%d/%d/%d", &p[j].dat, &p[j].mes, &p[j].ano);
			op=vald_data(p[j].dat, p[j].mes, p[j].ano);
			if(op==0)
				printf("\nData errada, digite novamente\n");
		}while(op!=1);
		setbuf(stdin, NULL);
		printf("CPF: ");
		do{
			setbuf(stdin, NULL);
			scanf("%s",p[j].cpf);
			op=val_CPF(p[j].cpf);
			if(op==0)
				printf("\nCPF errada, digite novamente\n");
		}while(op!=1);
		j++;
		printf("\n1-Continuar Cadastro\n0-Sair\n");
		do{
			scanf("%d", &*n);
			if(*n<0 || *n>1)
				printf("Opcao errada, digite novamente: \n\n");
		}while(*n<0 || *n>1);
		setbuf(stdin, NULL);
		system("cls");
  
  }while(*n!=0);
  
	//ptr= &j;//ponteiro pega valor de j que ?? o numero de alunos
	*ptr=j;
  //global=j;
  //return j;
}

void ex_prof(char ex[256], struct dados p[], int *cont){//exclus??o professor
  
  //struct copia *qtd;
  //int n;
  //n=global;
  int i, op, x, pos;
  //qtd=(struct copia *)malloc(*cont*sizeof(struct copia));
  
  do{
      setbuf(stdin, NULL);
      printf("\nQuem deseja excluir: ");
      scanf("%s",ex);
      
      //comparar os nomes e pegar a posi????o que ?? igual
      for(i=0; i<*cont; i++){
        int b=0;
        if(strcmp(ex, p[i].nome)==0){
          pos=i;
          b=1;
        }
          if(b==1){
            *cont-=1;
            break;
          }
            
     }
     
     //mudar data de nascimento
     for(x=pos; x<*cont; x++){
				p[x].dat=p[x+1].dat;
				p[x].mes=p[x+1].mes;
				p[x].ano=p[x+1].ano;	
			}
     
     //mudar a posi????o 
     for(x=pos; x<*cont; x++){
       //qtd[x].NOME=strlen(p[x].nome);
       //qtd[x].MAT=strlen(p[x].mat);
       //qtd[x].CPF=strlen(p[x].cpf);
      // qtd[x].SEXO=strlen(p[x].sexo);
       strncpy(p[x].nome, p[x+1].nome, strlen(p[x].nome));//NOME
       strncpy(p[x].mat, p[x+1].mat, strlen(p[x].mat));//MATRICULA
       strncpy(p[x].cpf, p[x+1].cpf, strlen(p[x].cpf));//CPF
       strncpy(p[x].sexo, p[x+1].sexo, strlen(p[x].sexo));//SEXO
     }
     
     
      printf("\n1-Outra Exclus??o\n0-Sair\n");
  	  do{
			scanf("%d", &op);
			if(op<0 || op>1)
				printf("Opcao errada, digite novamente: \n\n");
		}while(op<0 || op>1);
  		setbuf(stdin, NULL);
  		system("cls");
		
  }while(op!=0);
}

void at_prof(char ex[256], struct dados p[], int *n){//atualiza????o professor
 int b, i, pos, op2, op3, op;
   //n=global;
   
   do{
     setbuf(stdin, NULL);
     printf("\nQuem deseja atualizar: ");
    scanf("%s",ex);
     
     //comparar os nomes e pegar a posi????o que ?? igual
      for(i=0; i<*n; i++){
        int b=0;
        if(strcmp(ex, p[i].nome)==0){
          pos=i;
          b=1;
        }
          if(b==1)
            break;
     }
     
     do{
       setbuf(stdin, NULL);
       printf("1-Nome\n2-Matricula\n3-Data de nascimento\n4-Sexo\n5-CPF\n0-Sair\n");
       scanf("%d", &op2);
       
       if(op2==1){
          setbuf(stdin, NULL);
          printf("Digite nome atualizado: ");
				  scanf("%s",p[pos].nome);
       }else if(op2==2){
         setbuf(stdin, NULL);
         printf("Digite matricula atualizada: ");
				 scanf("%s",p[pos].mat);
       }else if(op2==3){
         setbuf(stdin, NULL);
         printf("Digite data de nascimento atualizada: ");
         scanf("%d/%d/%d", &p[pos].dat, &p[pos].mes, &p[pos].ano);
       }else if(op2==4){
         setbuf(stdin, NULL);
         printf("Digite sexo atualizado: ");
					scanf("%s",p[pos].sexo);
       }else if(op2==5){
         setbuf(stdin, NULL);
         printf("Digite CPF atualizado: ");
				 scanf("%s",p[pos].cpf);
       }else if(op2==0)
        break;
        
       printf("\n1-Continuar Atualiza????o do Professor %s\n0-Sair\n", p[pos].nome);
  	  do{
			scanf("%d", &op3);
			if(op3<0 || op3>1)
				printf("Opcao errada, digite novamente: \n\n");
		}while(op3<0 || op3>1);
      setbuf(stdin, NULL);
  	  system("cls");
       
     }while(op3!=0);
     
     
     printf("\n1-Atualizar outro Professor\n0-Sair\n");//ver se tira
  	 do{
			scanf("%d", &op);
			if(op<0 || op>1)
				printf("Opcao errada, digite novamente: \n\n");
		}while(op<0 || op>1);
     setbuf(stdin, NULL);
  	 system("cls");
  		
   }while(op!=0);

}

void in_Disc(struct disciplina d[], int *n, int *ptr){//inserir disciplina
  
  static int j=0;
  do{
    	setbuf(stdin, NULL);
    	printf("Nome: ");
		scanf("%s",d[j].n);
		setbuf(stdin, NULL);
		printf("Semestre: ");
		scanf("%s",d[j].semt);
		setbuf(stdin, NULL);
		printf("C??digo: ");
		scanf("%s",d[j].cod);
		setbuf(stdin, NULL);
		printf("Professor: ");
		scanf("%s",d[j].prof);
		setbuf(stdin, NULL);
		j++;
		printf("\n1-Continuar Cadastro\n0-Sair\n");
		do{
			scanf("%d", &*n);
			if(*n<0 || *n>1)
				printf("Opcao errada, digite novamente: \n\n");
		}while(*n<0 || *n>1);
		setbuf(stdin, NULL);
		system("cls");
	
  }while(*n!=0);

	int linha=j;
	*ptr=j;
}

void ex_Disc(char ex[256], struct disciplina d[], int *cont){//excluir disciplina
  
  //struct copia *qtd;
  int i, op, pos;
  
  //qtd=(struct copia *)malloc(*cont*sizeof(struct copia));
  do{
      setbuf(stdin, NULL);
      printf("\nDisciplina a excluir: ");
      scanf("%s",ex);
      
      //comparar os nomes e pegar a posi????o que ?? igual
      for(i=0; i<*cont; i++){
        int b=0;
        if(strcmp(ex, d[i].n)==0){
          pos=i;
          b=1;
        }
          if(b==1){
            *cont-=1;
            break;
          }
            
     }
     
     //mudar a posi????o 
     for(i=pos; i<*cont; i++){
       //qtd[i].N=strlen(d[i].n);
       //qtd[i].SEMT=strlen(d[i].semt);
       //qtd[i].COD=strlen(d[i].cod);
       //qtd[i].PROF=strlen(d[i].prof);
       strncpy(d[i].n, d[i+1].n, strlen(d[i].n));//NOME
       strncpy(d[i].semt, d[i+1].semt, strlen(d[i].semt));//SEMESTRE
       strncpy(d[i].cod, d[i+1].cod, strlen(d[i].cod));//CODIGO
       strncpy(d[i].prof, d[i+1].prof, strlen(d[i].prof));//PROFESSOR
     }
     
     
      printf("\n1-Outra Exclus??o\n0-Sair\n");
  	  do{
			scanf("%d", &op);
			if(op<0 || op>1)
				printf("Opcao errada, digite novamente: \n\n");
		}while(op<0 || op>1);
  		setbuf(stdin, NULL);
  		system("cls");
		
    
  }while(op!=0);
  
 // free(qtd);
  
}

void at_Disc(char ex[256], struct disciplina d[], int *n){//atualizar disciplina
 
  int b, i, pos, op2, op3, op;
   
   do{
     setbuf(stdin, NULL);
     printf("\nDisciplina a atualizar: ");
     scanf("%s",ex);
     
     //comparar os nomes e pegar a posi????o que ?? igual
      for(i=0; i<*n; i++){
        int b=0;
        if(strcmp(ex, d[i].n)==0){
          pos=i;
          b=1;
        }
          if(b==1)
            break;
     }
     
     do{
       setbuf(stdin, NULL);
       printf("1-Nome\n2-Semestre\n3-Codigo\n4-Professor\n0-Sair\n");
       scanf("%d", &op2);
       
       if(op2==1){
          setbuf(stdin, NULL);
          printf("Digite nome atualizado: ");
				  scanf("%s",d[pos].n);
       }else if(op2==2){
         setbuf(stdin, NULL);
         printf("Digite semestre atualizado: ");
				 scanf("%s",d[pos].semt);
       }else if(op2==3){
         setbuf(stdin, NULL);
         printf("Digite codigo atualizado: ");
         scanf("%s",d[pos].cod);
       }else if(op2==4){
         setbuf(stdin, NULL);
         printf("Digite professor atualizado: ");
					scanf("%s",d[pos].prof);
       }else if(op2==0)
        break;
        
       printf("\n1-Continuar Atualiza????o da disciplina %s\n0-Sair\n", d[pos].n);
  	  do{
			scanf("%d", &op3);
			if(op3<0 || op3>1)
				printf("Opcao errada, digite novamente: \n\n");
		}while(op3<0 || op3>1);
      setbuf(stdin, NULL);
  	  system("cls");
       
     }while(op3!=0);
     
     
     printf("\n1-Atualizar outra Disciplina\n0-Sair\n");//ver se tira
  	 do{
			scanf("%d", &op);
			if(op<0 || op>1)
				printf("Opcao errada, digite novamente: \n\n");
		}while(op<0 || op>1);
     setbuf(stdin, NULL);
  	 system("cls");
  		
   }while(op!=0);
  
}

void in_Aldisc(char ex[256], int aluno[][coluna], struct disciplina d[], int *cont, int *n){//inserir aluno na disciplina
  
  int i, b, pos, op;
  static int j=0;
  
  do{
      setbuf(stdin, NULL);
      printf("\nDisciplina a inserir aluno: ");
      scanf("%s",ex);
      
      //comparar os nomes e pegar a posi????o que ?? igual
      for(i=0; i<*cont; i++){
         b=0;
        if(strcmp(ex, d[i].n)==0){
          pos=i;
          b=1;
        }
          if(b==1)
            break;
     }
     
     //vai inserir alunos pelo numero da matricula
			printf("Digite a matricula dos alunos para %s: \n", d[pos].n);
			do{
				printf("Aluno %d> ", j+1);
				scanf("%d", &aluno[i][j]);
				j++;
				printf("\n1-Continuar\n0-Sair\n");
				scanf("%d", &op);
			}while(op!=0);
			
     setbuf(stdin, NULL);
     printf("1-Inserir aluno em outra disciplina\n0-Sair\n");
     do{
			scanf("%d", &op);
			if(op<0 || op>1)
				printf("Opcao errada, digite novamente: \n\n");
		}while(op<0 || op>1);
  	 system("cls");
      
  }while(op!=0);
  
  coluna=j;
  *n=j;
  
}

void ex_Aldisc(char ex[256], struct disciplina d[], int *cont, int aluno[][coluna], int *n){//excluir aluno de disciplina
  //int *cont= qtd de disciplinas
  //int *n= qtd de alunos
  int i,j, op, pos, matricula, pos2;
  
  do{
      setbuf(stdin, NULL);
      printf("\nDisciplina que deseja excluir aluno: ");
      scanf("%s",ex);
      
      //comparar os nomes e pegar a posi????o que ?? igual
      for(i=0; i<*cont; i++){
        int b=0;
        if(strcmp(ex, d[i].n)==0){
          pos=i;
          b=1;
        }
          if(b==1){
            break;
          }   
     }
     //pega a posi????o da matricula e pede para digitar o aluno que deseja excluir e come??a dele
     printf("\nDigite a matricula do aluno que deseja exluir: ");
     scanf("%d", &matricula);
     	
     	for(j=0; j<*n; j++){
     		int c=0;
     		if(matricula==aluno[pos][j]){
     			pos2=j;
     			c=1;
			 }
			 if(c==1){
			 	*n-=1;
			 	break;
			 }		
		 }
	 
     //mudar a posi????o 
     for(i=pos2; i<*n; i++){
		aluno[pos][i]=aluno[pos][i+1];
     }
     
     
      printf("\n1-Outra Exclus??o\n0-Sair\n");
  	  do{
			scanf("%d", &op);
			if(op<0 || op>1)
				printf("Opcao errada, digite novamente: \n\n");
		}while(op<0 || op>1);
  	  setbuf(stdin, NULL);
  	  system("cls");
		
    
  }while(op!=0);
  
  coluna=*n;
}

void busca(char ex[256], struct dados *a, struct dados p[], int *ptr, int *cont){
	
	int n, i, j, t, count, b, k;
	
	printf("\nInforme um grupo de letras (minimo 3): ");
	
	do{
		setbuf(stdin, NULL);
		scanf("%s",ex);
		n=strlen(ex);
		if(n<3)
			printf("\nMenor que 3 letras, digite novamente: ");
	}while(n<3);
	b=0;
	printf("\nAlunos:\n");//alunos
	for(i=0; i<*ptr; i++){
		t=strlen(a[i].nome);
		count=0;
		for(j=0; j<n; j++){
			for(k=0; k<t; k++){
				if(ex[j]==a[i].nome[k]){
					count++;
					break;
				}	
			}
		}
		if(count>=n)
			printf("%s\n", a[i].nome);
		else
			b++;
	}
	if(b==*ptr)
		printf("\nNao ha nomes de alunos com essas letras\n");
		
	b=0;
	printf("\nProfessores:\n");//professores
	for(i=0; i<*cont; i++){
		t=strlen(p[i].nome);
		count=0;
		for(j=0; j<n; j++){
			for(k=0; k<t; k++){
				if(ex[j]==p[i].nome[k]){
					count++;
					break;
				}	
			}
		}
		if(count>=n)
			printf("%s\n", p[i].nome);
		else
			b++;
	}
	if(b==*cont)
		printf("\nNao ha nomes de professores com essas letras\n");
	
}

int compara_data(const void *a, const void *b){//comparar data
	if((*(struct dados*)a).ano < (*(struct dados*)b).ano)
		return -1;
	else if((*(struct dados*)a).ano > (*(struct dados*)b).ano)
			return 1;
	else if((*(struct dados*)a).ano == (*(struct dados*)b).ano){
		
		if((*(struct dados*)a).mes == (*(struct dados*)b).mes){
			if((*(struct dados*)a).dat == (*(struct dados*)b).dat)
				return 0;
			else if((*(struct dados*)a).dat < (*(struct dados*)b).dat)
				return -1;
			else if((*(struct dados*)a).dat > (*(struct dados*)b).dat)
				return 1;
		}else if((*(struct dados*)a).mes < (*(struct dados*)b).mes)
			return -1;
		else
			return 1;	
		
	}
		
}//compara data

int compara_nome(const void *a, const void *b){//comparar nome
  
  int r=strcmp((*(struct dados*)a).nome, (*(struct dados*)b).nome);
	if(r==0)
		return 0;//iguais
	else if(r<0)
			return -1;//vem antes
	else 
			return 1;//vem depois
}

void listar(struct dados x[], int *cont){//listar alunos e professores

  int i;
  //printf("Alunos\tMatricula\tCPF\tData de Nasc\tSexo\n");
  //printf("\nLista de alunos\n\n");
  for(i=0; i<*cont; i++){
     for(i=0; i<*cont; i++)
      printf("%s\t%s\t%s\t%d/%d/%d\t%s \n", x[i].nome,x[i].mat,x[i].cpf, x[i].dat, x[i].mes,x[i].ano, x[i].sexo);
  }
  

}

void listar_disc(struct disciplina d[], int *cont){//listar disciplinas
  
  int i;
  //printf("Alunos\tMatricula\tCPF\tData de Nasc\tSexo\n");
  printf("\nLista de Disciplinas\n\n");
  for(i=0; i<*cont; i++){
    printf("%s\t%s\t%s\t%s\n", d[i].n,d[i].semt,d[i].cod,d[i].prof);
  }
}

void listar_PorSexo(struct dados *x, int *cont){//listar alunos e professores por sexo
  
  int i, contF=0, contM=0;
  
  printf("\nPessoas do sexo feminino\n\n");
  for(i=0; i<*cont; i++){
    if(strcmp(x[i].sexo,"F")==0 || strcmp(x[i].sexo,"f")==0){
    	contF++;
        printf("%s\t%s\t%s\t%d/%d/%d\t%s \n", x[i].nome,x[i].mat,x[i].cpf, x[i].dat, x[i].mes,x[i].ano, x[i].sexo);
	} 	
  }
  if(contF==0)
  	printf("\nNao ha pessoas do sexo feminino\n");
    
  printf("Pessoas do sexo masculino\n\n");
  for(i=0; i<*cont; i++){
    if(strcmp(x[i].sexo,"M")==0 || strcmp(x[i].sexo,"m")==0){
    	contM++;
        printf("%s\t%s\t%s\t%d/%d/%d\t%s \n", x[i].nome,x[i].mat,x[i].cpf,  x[i].dat, x[i].mes,x[i].ano, x[i].sexo);
	}
    	
  }  
  if(contM==0)
  	printf("\nNao ha pessoas do sexo masculino\n");

}

void listar_PordNome(struct dados x[], int *cont){//ordenando alunos e professores por nome
  int i;
  qsort(x, *cont, sizeof(struct dados), compara_nome);
 
  for(i=0; i<*cont; i++)
      printf("%s\t%s\t%s\t%d/%d/%d\t%s \n", x[i].nome,x[i].mat,x[i].cpf,  x[i].dat, x[i].mes,x[i].ano, x[i].sexo);
  
}

void listar_PordData(struct dados x[], int *cont){//ordenar alunos e professores por datas
  int i;
  qsort(x, *cont, sizeof(struct dados), compara_data);
  //printf("\nLista de alunos\n\n");
  for(i=0; i<*cont; i++)
     printf("%s\t%s\t%s\t%d/%d/%d\t%s \n", x[i].nome,x[i].mat,x[i].cpf, x[i].dat, x[i].mes,x[i].ano, x[i].sexo);
}

void listar_UmaDis(int aluno[][coluna], int *cont, int *n, int *ptr, struct dados *a, struct disciplina d[]){//listar alunos por disciplina
	//int *cont= qtd de disciplinas cadastrada
	//int *n=numero de matriculas cadastrada
	//int *ptr= numero de alunos cadastrado
	char ex[256];
	int i, j, pos, b, op, matricula, z;
	
	do{
		setbuf(stdin, NULL);
		printf("Disciplina que deseja listar alunos: ");
		scanf("%s",ex);
		
		for(i=0; i<*cont; i++){
			b=0;
			if(strcmp(ex, d[i].n)==0){
				pos=i;
				b=1;
			}
			if(b==1)	
				break;
		}
		
		printf("\nDisciplina: %s\tSemestre: %s\tCodigo: %s\tProfessor: %s\t\n", d[pos].n, d[pos].semt, d[pos].cod, d[pos].prof);
		for(z=0; z<*ptr; z++){
		
			matricula= atoi(a[z].mat);
			
			for(j=0; j<*n; j++){
				if(matricula==aluno[pos][j])//ver se d?? pra colocar pela tabela ascii
					printf("%s\n", a[z].nome);
			}
		}
				
		printf("\n1-Lista alunos de outra disciplina\n0-Sair\n");
		do{
			scanf("%d", &op);
			if(op<0 || op>1)
				printf("Opcao errada, digite novamente: \n\n");
		}while(op<0 || op>1);	
		system("cls");
		
	}while(op!=0);
	
}

void aniversariantes(struct dados p[],struct dados a[], int *ptr, int *cont){//listar aniversariantes
  
  int i, n, contP=0,contA=0;
  
  printf("Mes dos aniversariantes (numero): ");
  scanf("%d", &n);
  
  printf("Profesores aniversariantes do mes %d: \n", n);
  for(i=0; i<*ptr; i++){
    if(p[i].mes==n){
    	contP++;
      	printf("%s\n", p[i].nome);
	  }
       
  }
  
   if(contP==0)
    printf("Nao ha aniversariantes\n");
  
  printf("Alunos aniversariantes do mes %d: \n", n);
  for(i=0; i<*cont; i++){
    if(a[i].mes==n){
    	contA++;
    	printf("%s\n", a[i].nome);
	  }
      
  }
  
  if(contA==0)
    printf("N??o h?? aniversariantes\n");
    
}




	/*for(i=0; i<tam;i++){//tam sem o & vai indicar valor, se pasou por referencia, vai permanecer o valor que alterou na fun????o, emtao aqui pega o valor, mesmo esquema na impress??o do exemplo
	  printf(" %s - %s - %s - %s - %s \n\n", a[i].nome,  a[i].data, a[i].mat, a[i].cpf, a[i].sexo);
	}*/
	
		/*for(i=0; i<tam2;i++){//tam sem o & vai indicar valor
	  printf(" %s - %s - %s - %s - %s \n\n", p[i].nome,  p[i].data, p[i].mat, p[i].cpf, p[i].sexo);
	}*/
	
	


