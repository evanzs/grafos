#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


// Trabalho de ed2 sobre grafos e buscas

/*-------------------------------------
				INTERFACE	     	   |
-------------------------------------*/
int interface ()
{

	int op =0;
	char opp;	
	
	//limpa tela
	system("cls");

	printf ("\t\t\t\t Grafos\n\n\n");
	
	
	
	// opções
	printf ("\t1.\t Busca em profundidade\n");
	printf ("\t2.\t Busca em Largura\n");
	printf ("\t3.\t Dijkstra\n");
	printf ("\t4.\t Ordenacao Topologica\n");
	printf ("\t0. \t Sair\n\n\n\n");
	
	
	
		
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
		
			if ((toupper(opp) == 'S'))		
				return 0;	
			
			if ((toupper(opp) == 'N'))		
				interface();		
		}while (opp == 0);	
	}	
	
	
}
//------------------------- Fecha interface ---------------------------//

/*-------------------------------------
			CRIANDO GRAFO        	   |
-------------------------------------*/
CreadeG(node head[])// Possivelmente esse nome precise ser editado 
{
   int cont            = 0; 
   int tamanho 		   = 0; 
   int tamanho_adja    = 0;
   node p;
   
   
   //|vertices| Vertices adja|......| ..... |Tamanho__adja|
   //..
   //.
   //.
   //.
   //.
   //.
   //|tamanho|....... | ........| tamanho_adja|
   
   
   
   
   
   
   
   printf  (Qual o numero de Verticies: ");
   scanf  ("%d",tamanho);
   
   
   
   //iniciando o head
   for (cont = 0; cont < tamanho; cont++)
        head[i] = NULL;

    for (cont = 0; cont < tamanho; cont++)
	 {
        head[i] = (node) malloc (sizeof(struct head));
        head[i]->num = i++;
        head[i]->next = NULL;
        head[i]->visitado= 0;
    }
   
	printf ("Qual numero de adjacentes: ");
	//incluir errors
	scanf  ("%d",&tamanho_adja);	
	insertNode(&head,tamanho_adja,tamanho){
	
	
	
	

	
	
}






int main ()
{
	
	

	interface();
	

	
	
	
	
	
	
	
	
	
	
}
