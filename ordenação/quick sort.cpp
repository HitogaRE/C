#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dividir 
void quick(int vetor, int esq, int dir){
	 int posicao
	if(esq<dir){
	   posicao = dividir(vetor,esq,dir);
	   quick(vetor, esq, pos-1);
	   quick(vetor, pos+1 ,dir);
	   	
	}
}

int main(){
    
    int vetor[] = {3,4,5,78,2,5};
    int tam = 6;
    
	quick(vetor,tam);
	
    for(int i=0; i<tam;i++)
        printf("&d - ", vetor[i]);
        
    printf("\n\n\n");
	
	system("pause");
	retun0    
    
	
	
}
    
