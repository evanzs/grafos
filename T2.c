#include <stdio.h>
#include <stdlib.h>





int main ()
{
	
	
	int op =0;
	
	
	
	printf ("\t\t\t\t Grafos\n\n\n");
	
	
	
	
	printf ("\t1.\t Busca em profundidade\n");
	printf ("\t2.\t Busca em Largura\n");
	printf ("\t3.\t Dijkstra\n");
	printf ("\t4.\t Ordenacao Topologica\n\n\n\n");
	
	
	
	do
	{
		printf ("Escolha a opcao desejada: ");
		scanf ("%d",&op);
		if (( op > 4) || (op < 1))
			printf ("Nao existe essa opcao!!\n\n");
		
		
	}while (( op > 4) || (op< 1));
	
	
	
	
	
	
	
	
	
	
	
}
