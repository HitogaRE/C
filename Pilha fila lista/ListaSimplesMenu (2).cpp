#include <stdio.h>
#include <stdlib.h>
#include "lista2a.h"
//programa principal
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("------------------------------\n");
     printf("1. Insere na lista\n");     //Lista *lista_insere(Lista *l, int dado)  
     printf("2. Retira da lista\n");	 //Lista *lista_retira(Lista *l, int dado) 
     printf("3. Mostra a lista\n");      //void *lista_mostra(Lista *l) 
     printf("4. Busca na lista\n");		 //Lista *lista_busca(Lista *l, int dado) 
     printf("5. Conta elementos\n"); // int contaElementos(Lista * lst)
     printf("6. Soma Elementos\n"); // int somaElementos(Lista * lst)
     printf("7. Ultimo da lista\n"); // int ultimo(Lista * lst)
     printf("8. Primeiro da lista\n");  // int primeiro(Lista * lts)
     printf("9. Maior da lista\n"); // int maiorNumero (Lista *Li)
     printf("10. Lista pares\n"); // 
     printf("11. Busca Recursiva\n"); // 
     printf("0. Fim\n");
     printf("==> ");
}

//-------------------------------------------------
//conta
//-------------------------------------------------
int contaElementos(Lista * lst){
	int cont=0;
	Lista *aux;//variável usada para percorrer a lista
     for(aux=lst;aux!=NULL;aux=aux->prox)
     	cont++;
    return cont;
}
//-------------------------------------------------
//soma
//-------------------------------------------------
int somaElementos(Lista * lst){
	int soma;
	Lista *aux;//variável usada para percorrer a lista
     for(aux=lst;aux!=NULL;aux=aux->prox)
     	soma+=aux->info;
    return soma;
}
//-------------------------------------------------
//ultimo
//-------------------------------------------------
int ultimo(Lista * lst){ // o item prox=null
	Lista *aux;
	for(aux=lst;aux->prox!=NULL;aux=aux->prox);
	return aux->info;
	
}
//--------------------------------------------------     
//primeiro     
//---------------------------------------------------
int primeiro(Lista * lst){
	Lista *aux; //variável usada para percorrer a lista
     for(aux=lst;aux->prox==NULL;aux=aux->prox);
	return aux->info;
	
}
//--------------------------------------------------     
//maior     
//---------------------------------------------------
int maiorNumero(Lista *Li){
	int m = Li->info;
	while(Li != NULL)
	{
		if(Li->info > m)
            m = Li->info;
        Li= Li->prox;
	}
	return m;		
}
//--------------------------------------------------     
//par    
//---------------------------------------------------
Lista *lista_pares(Lista *L1){
	Lista *par=lista_cria();
	while(L1 != NULL)
	{
		if(L1->info % 2==0)
			par=lista_ordenada(par,L1->info);
        L1= L1->prox;
	}
	
	lista_mostra(par);
	return par;
	
}


int gravaLista(FILE *arq, lista *li) { 
	Lista* aux;
    int cont=0;
    for(aux = li; aux != NULL; aux=aux->prox){
    	fprintf(arq, "%d;", aux->info);
    	cont++;
	}
	 fclose(arq);   
return cont;
}

//--------------------------------------------------     
//busca recursiva    
//---------------------------------------------------
void buscalista(Lista *l, int valor){
	Lista *a=l; //variável auxiliar usada para percorrer a lista
	if(a==NULL){
		printf("%d nao encontrado!\n");
		return;
	}	
	if(a->info == valor){
		printf("%d encontrado na lista!\n", valor);
		return;
	} 	
	return buscalista(a=a->prox,valor);
}
//--------------------------------------------------     
//programa principal       
//---------------------------------------------------
main(){
  int opmenu, item;
  Lista *li=lista_cria();//inicializa a lista com NULL
  FILE *p;
  Lista *aux;//ponteiro auxiliar - necessário para a busca
  do{
     menu();   
     scanf("%d",&opmenu);
     switch(opmenu){
        case 1: //insere
               printf("Informe o item que deseja adicionar: ");
               scanf("%d",&item);
               //li=lista_insere(li,item);
               aux=lista_busca(li,item);
               if(aux==NULL)
               		li=lista_ordenada(li,item);
               	else
               		printf("O item %d ja consta na lista!\n", item);
               break;
        case 2:  //retira
             printf("Informe o item que deseja retirar: ");
             scanf("%d",&item);
             li=lista_retira(li,item); 
             break;
        case 3://mostra
		    if(lista_vazia(li))
			   printf("Lista vazia\n");
			else {
		  		  printf("\nLista:\n");
		          lista_mostra(li);
		      }
            break;
        case 4://busca
        	   printf("Informe o item que deseja buscar: ");
               scanf("%d",&item);
               aux=lista_busca(li,item);
               if (aux==NULL)
                   printf("%d NAO encontrado!\n",item);
                else
                	printf("%d Encontrado!\n",aux->info);
               break;
        case 5: // conta
        		int x;
				x = contaElementos(li);
        		printf("A lista tem %d elementos!\n", x);
        		break;
        case 6: //soma
        		int soma;
        		soma = somaElementos(li);
        		printf("Soma dos elementos da lista: %d!\n", soma);
        		break;
        case 7: // Ultimo
        		int ult;
        		ult =  ultimo(li);
        		if(lista_vazia(li))
			   		printf("Lista vazia\n");
				else
        			printf("Ultimo elemento: %d\n", ult);
        		break;
        case 8: // Primeiro
        	int pri;
        	pri = primeiro(li);
        	if(lista_vazia(li))
			   		printf("Lista vazia\n");
				else
        			printf("Primeiro elemento: %d\n", pri);
        		break;
		case 9 : //maior
			if(lista_vazia(li))
			   		printf("Lista vazia\n");
				else
        			printf("O maior elemento da lista: %d\n", maiorNumero(li));
        		break;
		case 10 : //pares
			if(lista_vazia(li))
			   		printf("Lista vazia\n");
				else
        			lista_pares(li);
        		break;
		case 11 : // busca recursiva
        	p=fopen("arq.txt", "wt");

		    gravaLista(p,li);
			
			break;
				
				
        }//fim switch
        
        //fim switch
   printf("\n");
   system("pause");
   }while(opmenu!=0);
   lista_libera(li);
}
