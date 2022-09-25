//fila com vetor
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void concatena_fila(Fila *f1, Fila *f2){
	Fila *aux=fila_cria();
	float v;
	
	while(!fila_vazia(f2)){
		v=fila_retira(f2);
		fila_insere(aux, v);
		fila_insere(f1, v);
	}
	while(!fila_vazia(aux))
      fila_insere(f2,fila_retira(aux));
	
	fila_libera(aux);
}
int contaElementos(Fila* f){
    int cont=0;
    Fila *aux=fila_cria();
    float v;
    //esvazia a fila original para contar
    while(!fila_vazia(f)){
      v=fila_retira(f);
      cont++;
      fila_insere(aux,v);
    }
    //restaura a fila original
    while(!fila_vazia(aux))
      fila_insere(f,fila_retira(aux));
      
    fila_libera(aux);
    return cont;
}
//--------------------------------------------------------------------
float somaElementos(Fila* f){
	float soma=0;
	Fila *aux=fila_cria();
	float v;
	while(!fila_vazia(f)){
      v=fila_retira(f);
      soma+=v;
      fila_insere(aux,v);
    }
    while(!fila_vazia(aux))
      fila_insere(f,fila_retira(aux));
      
    fila_libera(aux);
    return soma;
}
//--------------------------------------------------------------------	
float primeiro(Fila* f){
	Fila *aux=fila_cria();
	float v;
	
	v=fila_retira(f);
	fila_insere(aux, v);
	while(!fila_vazia(f)){
	  fila_insere(aux, fila_retira(f));
    }
    
    
    while(!fila_vazia(aux)){
		fila_insere(f,fila_retira(aux));
	}
      
    fila_libera(aux);
    return v;
}
//--------------------------------------------------------------------
float ultimo(Fila* f){
	Fila *aux=fila_cria();
	float v;
	while(!fila_vazia(f)){
      v=fila_retira(f);
      fila_insere(aux,v);
    }
    
    while(!fila_vazia(aux))
      fila_insere(f,fila_retira(aux));
      
    fila_libera(aux);
    return v;
	
}
//--------------------------------------------------------------------
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Enfileira\n");       
     printf("2. Retira\n");
     printf("3. Mostra a fila\n");
     printf("4. Conta Elementos\n");
     printf("5. Somar Elementos\n");
     printf("6. Primeiro da Fila\n");
     printf("7. Ultimo da Fila\n");
     printf("8. Enfilera Fila 2\n");
     printf("9. Concatena\n");
     printf("10. Mosta Fila 2\n");
     printf("11. Fim\n");
}     
int main(){
 Fila *fi=fila_cria();
 Fila *f2=fila_cria();
 int opmenu; 
 float item;
 do{
    menu(); 
    scanf("%d", &opmenu);
    switch (opmenu){
    case 1 : //insere
          printf("Digite o valor a ser enfileirado: ");
          scanf("%f", &item);
          fila_insere(fi,item); break;
    case 2 : //retira
          if(fila_vazia(fi)) 
              printf("fila vazia.\n");
          else
              printf("Elemento retirado = %.0f\n",fila_retira(fi));
          break;    
    case 3 : //mostra
    	  if(fila_vazia(fi))	
    	     printf("Fila vazia!\n");
    	  else
            fila_mostra(fi);
	      break;
    case 4: //conta elementos
          printf("Numero de elementos: %d\n", contaElementos(fi));
          break;
    case 5: //soma elementos
    	printf("Soma dos Elementos: %f\n", somaElementos(fi));
    	break;
    case 6: // primeiro da fila
    	printf("Primeiro da Fila: %.0f\n", primeiro(fi));
    	break;
    case 7: // ultimo da fila
    	printf("Ultimo da Fila: %.0f\n", ultimo(fi));
    	break;
    case 8 :
    	printf("Digite o valor a ser enfileirado: ");
        scanf("%f", &item);
        fila_insere(f2,item); 
		break;
    case 9 :
    	concatena_fila(fi, f2);
    	break;
    case 10 :
    	if(fila_vazia(f2))	
    	     printf("Fila vazia!\n");
    	  else
            fila_mostra(f2);
	      break;
    }//switch
   printf("\n");
   system("pause"); 
 } while(opmenu!=11);
}
                                          
