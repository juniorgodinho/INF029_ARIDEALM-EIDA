#include <stdio.h>
#include <stdlib.h>

void printCres(int n);

int main(void){
    
    int n;
    
    puts("Informe um valor");
    scanf("%d", &n);  
    
    printCres(n);
    puts("");
    
    return 0;
}

void printCres(int n){
        
    if(n < 0)
        return;
    
    printCres(n-1);
    printf("%d ", n);    
}