#include <stdio.h>
#include <stdlib.h>

// Trabalho de ed2 sobre grafos e buscas


menus ()
{
	printf ("\t\t\t\t Grafos\n\n\n");
	
	
	
	
	printf ("\t1.\t Busca em profundidade\n");
	printf ("\t2.\t Busca em Largura\n");
	printf ("\t3.\t Dijkstra\n");
	printf ("\t4.\t Ordenacao Topologica\n");
	printf ("\t0. \t Sair\n\n\n\n");
}



int main ()
{
	
	
	int op =0;
	char opp;
	Menus();
	
	
	//controlando entrada de dados validas
	do	
	{
		printf ("Escolha a opcao desejada: ");
		scanf ("%d",&op);
		if (( op > 4) || (op < 0))
			printf ("Nao existe essa opcao!!\n\n");		
		
	}while (( op > 4) || (op< 0));
	
	
	
	
	//sair do programa
	if ( op == 0)
	{
		do				
		{
		printf ("Tem certeza que deseja sair? S/N");
		scanf ("%c",&opp);
	
		if ((opp == "S" ) || (opp== "s"))
		{
			exit();	
		}
		if ((opp == "N") || (opp=="n"))
		{
			system("cls");
			menus();
			opp =1;
		}
		
		}while (opp == 0);
	
		
		
		
		
	}
			
	
	
	
	
	
	
}
