#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void empilhaPilha(Pilha *p1, Pilha *p2){
	int a, s, b;
	Pilha *aux1=pilha_cria();
	Pilha *aux2=pilha_cria();
	
	//esvazia a pilha 2
	while(!pilha_vazia(p2)){
		a=pilha_pop(p2);
		//salva nas auxiliares
		pilha_push(aux1, a); 
		pilha_push(aux2, a);
	}
	//empilha sobra a pilha 1
	while(!pilha_vazia(aux1)){
		s=pilha_pop(aux1);
		//printf("%d, ", s);
		pilha_push(p1, s);
	}
	while(!pilha_vazia(aux2)){
		pilha_push(p2, pilha_pop(aux2));
	}
	
	while(!pilha_vazia(p1)){
		pilha_push(aux2, pilha_pop(p1));
	}
	while(!pilha_vazia(aux2)){
		b=pilha_pop(aux2);
		printf("%d, ", b);
		pilha_push(p1, b);
	}
	pilha_libera(aux1);
	pilha_libera(aux2);
	
}

int conta (Pilha *p){
	int cont=0;
	Pilha *aux=pilha_cria();
	float v;
	
	while(pilha_vazia(p)==0){
		v=pilha_pop(p);
		cont++;
		pilha_push(aux, v);
	}
	
	//restaura a pilha original
	while(pilha_vazia(aux)==0){
		v=pilha_pop(aux);
		pilha_push(p, v);
	}
	
	pilha_libera(aux);
	return cont;
}

void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Empilha (push)\n");
     printf("2. Retira (pop)\n");
     printf("3. Mostra a pilha\n");
     printf("4. Conta elementos\n");
     printf("5. Empilha (push)\n");
     printf("6. EmpilhaPilha\n");
     printf("7. Mostra p2\n");
     
     printf("9. Fim\n");
}
main(){
      Pilha *p1=pilha_cria();
      Pilha *p2=pilha_cria();
      int opmenu;
      float item;
      do{
         menu();
         scanf("%d", &opmenu);
         switch (opmenu){
         case 1 : //insere
                printf("Digite o valor a ser empilhado: ");
                scanf("%f", &item);
                pilha_push(p1,item);
                break;
        case 2 : //retira
               if(pilha_vazia(p1))//verifica antes se está vazia
                   printf("Pilha vazia.\n");
               else
                   printf("Elemento retirado = %.0f\n",pilha_pop(p1));
               break;
        case 3 : //mostra
                if(pilha_vazia(p1))
                   printf("pilha vazia!\n");
                else
                   pilha_mostra(p1);
                break;
        case 4 :
	        	printf("Numero de elementos: %d\n", conta(p1));
	            break;
	    case 5 :
	    		printf("Digite o valor a ser empilhado: ");
                scanf("%f", &item);
                pilha_push(p2,item);
                break;
        case 6 :
        	empilhaPilha(p1,p2);
			break;
		case 7 :
			if(pilha_vazia(p2))
                   printf("pilha vazia!\n");
                else
                   pilha_mostra(p2);
                break;
       }//switch
       printf("\n");
       system("pause");
       
     } while(opmenu!=9);
     pilha_libera(p1);
     pilha_libera(p2);
   }
