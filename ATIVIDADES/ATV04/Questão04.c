#include <stdio.h>
#include <stdlib.h>
void numeros()
{
    int vetor[3],i;
    printf("Digite os numeros a serem inseridos no vetor:\n");
    for(i = 0; i < 3; i++)
    {
        printf(" %d:\n",i+1);
        scanf("%d",&vetor[i]);
    }
    printf("Vetor:\n[ ");
    for(i = 0; i < 3; i++)
    {
        printf("%d ",vetor[i]);
    }
    printf("]\n");
}
int main()
{
    numeros();
    return 0;
}
