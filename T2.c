#include <stdio.h>
#include <stdlib.h>
#include "listalinear.c"

// Trabalho de ed2 sobre grafos e buscas
int main(){
	node head;
	createHead(&head);
	insertLast(&head, 10, 1);
	insertLast(&head, 15, 1);
	insertLast(&head, 20, 1);
	insertLast(&head, 25, 1);
	showList(head);
}
