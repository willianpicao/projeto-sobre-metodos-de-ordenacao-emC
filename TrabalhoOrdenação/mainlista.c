#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include <time.h>

#include <sys/types.h> //Bib que define o registro TMS
#include <unistd.h> //Biblioteca necessaria para descobrir os ciclos de clock


//inclusão de biblioteca proprias
#include"listaestatica.c"
#include"ordenacao.c"

	
int main(int argc, char *argv[])
{
	

	tipoLista lista;
	FILE *arquivo;
	int num;
	
	if( argc !=2 )
	{
		printf("FALHA NA QUANTIDADE DE ARGUMENTOS\n");
		return 0;
	}
	else
	{
		inicializaLista(&lista, 1000);
		
		arquivo = fopen ("1000-arq1.txt", "r");
		if( arquivo == NULL)
		{
			printf("IMPOSSIVEL ABRIR O ARQUIVO");
			return 0;
		}
		while(EOF != fscanf(arquivo, "%d", &num) )
			insereFim(&lista, num);
	}
			
	
	printf("\nimprimindo a lista\n");
	
	imprime(&lista);
	
	printf("\n");

	//bubbleSort(&lista);
	
	//shellSort(&lista, 1000);


	
	mergeSort(&lista, 1000);
	
	printf("\nIMPRIMINDO LISTA ORDENADA\n");
	
	imprime(&lista);
	
	printf("\n");
	
	
	return 1;
}