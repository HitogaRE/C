#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostra(char vetor [][5],int NumPa){
     for(int pos=0;pos<NumPa;pos++) 
         printf("%s\n",vetor[pos]);
     printf("\n\n");    
}

void bubblesort(char vetor[][5],int ma){
	char temp[5];
	int pos, trocou;
	ma--;
	do{
		trocou=0;
		for(pos=0;pos<ma;pos++){
		    if(strcmp(vetor[pos],vetor[pos+1])>0){
		       strcpy(temp,vetor[pos]);
		       strcpy(vetor[pos],vetor[pos+1]);
		       strcpy(vetor[pos+1],temp);
		       trocou=1;
			}
	    }
	}while(trocou);
}
int main(){
    char vetor[][5]={"casa","rola","faca","sopa"};
    int NumPa=4;
    bubblesort(vetor,NumPa);
    mostra(vetor,NumPa);
    
    return 0;
}


