//thiago Pereira dos SAntos
#include <stdio.h>
#include <stdlib.h>


int main()
{
	// Conexão com os arquivos de entrada

	FILE *produtos;
	FILE *vendas;

	produtos = fopen("PRODUTOS.txt", "r");

	if(produtos==NULL){
		printf("Tabela Produtos nao localizada\n");
		return 0;
	}
	else
		printf("Conexao com a tabela Produtos bem sucedida\n");

	vendas = fopen("VENDAS.txt", "r");

	if(vendas==NULL){
		printf("Tabela Vendas nao localizada\n");
		return 0;
	}
	else
		printf("Conexao com a tabela Produtos bem sucedida\n");

	// Armazenar dados em vetores

	int tam=0;
	int aux[4];

	int *Cod;
	Cod=NULL;

	int *QtCO;
	QtCO=NULL;

	int *QtMin;
	QtMin=NULL;

	while(fscanf(produtos,"%d;%d;%d\n", &aux[0], &aux[1], &aux[2]) != EOF) {
		tam++;

		Cod=(int *)realloc(Cod, sizeof(int) * tam);
		QtCO=(int *)realloc(QtCO, sizeof(int) * tam);
		QtMin=(int *)realloc(QtMin, sizeof(int) * tam);

		Cod[tam-1]= aux[0];
		QtCO[tam-1]= aux[1];
		QtMin[tam-1]= aux[2];

	}

	// QtdVendas

	int *Cod_Vendas;
	Cod_Vendas=NULL;

	int *Situacao_Venda;
	Situacao_Venda=NULL;

	int i=0, i2=0, i3=0, tam2=0;

	int Qtd_Vend[tam];
	int linha_errada[tam2];
	int Valor_errado[tam2];


	for(i=0;i<tam;i++){
		Qtd_Vend[i]=0;
	}

	while(fscanf(vendas,"%d;%d;%d;%d\n", &aux[0], &aux[1], &aux[2], &aux[3]) != EOF) {
		tam2++;
		
		
		Cod_Vendas=(int *)realloc(Cod_Vendas, sizeof(int) * tam2);
		Cod_Vendas[tam2-1]= aux[0];

		Situacao_Venda=(int *)realloc(Situacao_Venda, sizeof(int) * tam2);
		Situacao_Venda[tam2-1] = aux[2];

		




		if (Situacao_Venda[i2] == 135){
			linha_errada[i2] = i2+1;
			printf("\nValor de linha errada em 135:%d",linha_errada[i2]);
			//printf("\nValor de i2:%d",i2);


		}
		
		if (Situacao_Venda[i2] == 190){
			linha_errada[i2] = i2+1;
			printf("\nValor de linha errada em 190:%d",linha_errada[i2]);
			//printf("\nValor de i2:%d",i2);

		}
		
		if (Situacao_Venda[i2] == 999){
			linha_errada[i2] = i2+1;
			printf("\nValor de linha errada em 999:%d",linha_errada[i2]);
			//printf("\nValor de i2:%d",i2);

		}
		
		
	for(i=0;i<tam;i++){
		if(Cod_Vendas[i2] == Cod[i]){
				if(Situacao_Venda[i2] == 100 || Situacao_Venda[i2] == 102 ){
					Qtd_Vend[i] = Qtd_Vend[i] + aux[1];
				}
			}
	}
		
		
	i2++;
 }
	
    

	// Escrever arquivo de saida "Transfere"

	FILE * transfere;

	transfere = fopen("TESTE.txt", "w");

	fprintf(transfere,"Necessidade de Transferência Armazém para CO\n\nProduto   QtCO   QtMin   QtVendas   Estq.após   Necess   Transf. de\n                                    Vendas               Arm p/ CO\n");

	int posicao_linha=0;
	int estq_restante, necessidade, transferencia;

	i=0;

	while(i < tam){

		estq_restante = QtCO[posicao_linha]-Qtd_Vend[posicao_linha];
			
		if(estq_restante < QtMin[posicao_linha]){
		    necessidade = QtMin[posicao_linha]-estq_restante;
		}else{
			necessidade=0;
		}
		
		if(necessidade>1 && necessidade<10){
			transferencia=10;
		}else{
			transferencia=necessidade;
		}
			
		fprintf(transfere,"%4d     %4d     %4d     %4d         %4d         %4d         %4d\n", Cod[posicao_linha], QtCO[posicao_linha], QtMin[posicao_linha], Qtd_Vend[posicao_linha], estq_restante, necessidade, transferencia);
		i++;
		posicao_linha++;
	}

	FILE * diver;

	diver = fopen("DIVERGENCIAS.txt", "w");

	//Construção para verificar divergencia 
	
	//Situação de venda
	 
	for(i=0;i<tam2;i++){
		
		if(Situacao_Venda[i] == 135){
		fprintf (diver, "\nLinha %d - Venda Cancelada", i+1);
		//printf("\nValor de linha errada em 135:%d",linha_errada[i2]);

		//printf("\n%d",i);

	}
		if(Situacao_Venda[i] == 190 ){
		fprintf (diver, "\nLinha %d - Venda nao finalizada", i+1);
		//printf("\nValor de linha errada em 190:%d",linha_errada[i]);

		//printf("\n%d",i);

	}
		if(Situacao_Venda[i] == 999 ){
		fprintf (diver, "\nLinha %d - Erro-desconhecido", i+1);
		//printf("\nValor de linha errada em 999:%d",linha_errada[i]);

		
	}
	
	} 

	// Finalizacao do Programa

	fclose(diver);
	fclose(transfere);
	fclose(produtos);
	fclose(vendas);

	printf("\nOperacao Concluida!");

	return 0;
}
