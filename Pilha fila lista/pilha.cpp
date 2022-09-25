//pilha com vetor
#include <stdio.h>
#include <stdlib.h>
#include "pilha2.h"

int conta (pilha*p){
	int cont=0;
	pilha *aux=pilha_cria();
	float v;
	
	while(pilha_vazia(p)==0){
		v=pilha_pop(p);
		cont++;
		pilha_push(aux,v);
	}
	while(pilha_vazia(aux)==0){
		v=pilha_pop(aux);
		pilha_push(p, v);
	}
	pilha_libera(aux);
	return cont;
}

float soma (pilha *p){
	float soma=0;
	pilha *aux=pilha_cria();
	float v;
	
	while(pilha_vazia(p)==0){
		v=pilha_pop(p);
		soma+=v;
		pilha_push(aux,v);
	}
	
	while(pilha_vazia(aux)==0){
		v=pilha_pop(aux);
		pilha_push(p, v);
	}
	
	pilha_libera(aux);
	return soma;	
}

void base(pilha *p){
	pilha *aux=pilha_cria();
	float v;
	
	while(pilha_vazia(p)==0){
		v=pilha_pop(p);
		pilha_push(aux,v);
	}
	
	printf("Base dos elementos: %.1f\n", v);
	
	while(pilha_vazia(aux)==0){
		v=pilha_pop(aux);
		pilha_push(p, v);
	}
	pilha_libera(aux);
}

void topo(pilha *p){
	pilha *aux=pilha_cria();
	float v;
	
	while(pilha_vazia(p)==0){
		v=pilha_pop(p);
		pilha_push(aux,v);
	}

	while(pilha_vazia(aux)==0){
		v=pilha_pop(aux);
		pilha_push(p, v);
	}
	
	printf("Topo dos elementos: %.1f\n", v);
	
	pilha_libera(aux);
}

void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Empilha (push)\n");
     printf("2. Retira (pop)\n");
     printf("3. Mostra a pilha\n");
     printf("4. Mostra a quantidade da pilha\n");
     printf("5. Mostra a soma dos elementos na pilha\n");
     printf("6. Mostra a Base dos elementos\n");
     printf("7. Mostra o Topo dos elementos\n");
     
     
     printf("9. Fim\n");
}
main(){
      Pilha *pi=pilha_cria();
      int opmenu;
      float item;
      do{
         menu();
         scanf("%d", &opmenu);
         switch (opmenu){
         case 1 : //insere
                printf("Digite o valor a ser empilhado: ");
                scanf("%f", &item);
                pilha_push(pi,item);
                break;
        case 2 : //retira
               if(pilha_vazia(pi))//verifica antes se está vazia
                   printf("Pilha vazia.\n");
               else
                   printf("Elemento retirado = %.0f\n",pilha_pop(pi));
               break;
        case 3 : //mostra
                if(pilha_vazia(pi))
                   printf("pilha vazia!\n");
                else
                   pilha_mostra(pi);
                break;
        case 4 : //mostra quantidade
        	if(pilha_vazia(pi))
        	printf("pilha vazia!\n");
                else
                   printf("Numero de elementos: %d\n", conta(pi));
                break;
        case 5 : //mostra soma
        	if(pilha_vazia(pi))
        	printf("pilha vazia!\n");
                else
                   printf("Soma dos elementos: %.1f\n", soma(pi));
                break;
        case 6 : //mostra base
        	if(pilha_vazia(pi))
        	printf("pilha vazia!\n");
                else
                   base(pi);
                break;
        case 7 : //mostra topo
        	if(pilha_vazia(pi))
        	printf("pilha vazia!\n");
                else
                   topo(pi);
                break;
                
       }//switch
       printf("\n");
       system("pause");
       
     } while(opmenu!=9);
     pilha_libera(pi);
   }

