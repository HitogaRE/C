//ordenação por troca
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostra(char vet[][8],int n){
	for(int i=0;i<n;i++)
        printf("%s\n",vet[i]);
    printf("\n\n");
} 

void bolha(char v[][8], int t)
{	 char temp[8];
     int i, trocou;
     t--;
     do{
     	trocou=0;
     	for(i=0;i<t;i++){
     		if(strcmp(v[i],v[i+1])>0){
     		  strcpy(temp,v[i]);
     		  strcpy(v[i],v[i+1]);
     		  strcpy(v[i+1],temp);
              trocou=1;	
			 }
		}
	}while(trocou);
}
                  
int main(){
    char vet[][8]={"vidro","cadeira","mesa","janela","porta",
	                "lousa","faca","vaso","cama"};
    int n=9;
    
    bolha(vet,n);
    mostra(vet,n);                              
    //exibe o vetor ordenado
    return 0;
}        

