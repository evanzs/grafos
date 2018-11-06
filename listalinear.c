#include <stdio.h>
#include <stdlib.h>

/*------------------------
	Criação dos nodes     |
------------------------*/
struct reg{
	int num;
	struct reg *next;
};
typedef struct reg *node;

/*-------------------------------------
	Funções inserção e remoção		   |
-------------------------------------*/

// cria uma lista vazia
void createHead(node *head){
	*head = NULL;
}

// insere um elemento na primeira posição da lista
void insertFirst(node *head, int num){
	node p;
	p = (node) malloc(sizeof(node));
	p->num = num;
	p->next = *head;
	*head = p;
}

// insere um elemento levando em conta a ordem da lista
int insertOrdered(node *head, int num){
	node p;
	p = (node) malloc(sizeof(node));
	p->num = num;
	if(!*head){
		*head = p;
		p->next = NULL;
		return 1;
	}
	node q = *head;
	if(num < q->num){
		p->next = q;
		*head = p;
		return 1;
	} else {
		node r;
		while(q != NULL && q->num < num){
			r = q;
			q = q->next;
		}
		p->next = q;
		r->next = p;
	}
}

// insere um elemento no final da lista
void insertLast(node *head, int num){
	node p = (node) malloc(sizeof(node));
	p->num = num;
	p->next = NULL;
	if(*head == NULL){
		*head = p;
	} else {
		node q = *head;
		while(q->next){
			q = q->next;
		}
		q->next = p;
	}
}

// remove o primeiro elemento da lista
int removeFirst(node *head){
	if(!*head){
		return 0;
	}
	node p = *head;
	*head = p->next;
	free(p);
	return 1;
}

// remove o ultimo elemento da lista
int removeLast(node *head){
	if(!*head){
		return 0;
	}
	node p = *head;
	node q;
	do{
		q = p;
		p = p->next;
	} while(p->next);
	q->next = NULL;
	free(p);
	return 1;
}

// remove um elemento especifico da lista
int removeElement(node *head, int num){
	if(!*head){
		return 0;
	}
	node q = *head;
	if(num == q->num){
		*head = q->next;
		free(q);
		return 1;
	} else {
		node r;
		while(q != NULL && q->num != num){
			r = q;
			q = q->next;
		}
		r->next = q->next;
		free(q);
		return 1;
	}
	return 0;
}

// remove todas as ocorrencias de um elemento especifico da lista
int removeElementAll(node *head, int num){
	if(!*head){
		return 0;
	}
	node q = *head;
	if(num == q->num){
		*head = q->next;
		free(q);
	} else {
		node r;
		while(q != NULL){
			r = q;
			q = q->next;
		}
		r->next = q->next;
		free(q);
		return 1;
	}
	return 0;
}

// remove todos os elementos da lista
int removeAll(node *head){
	node q = *head;
	node r;
	while(q){
		r = q;
		q = q->next;
		free(r);
	}
	*head = NULL;
}

/*--------------------------------------
	Funções que não alteram a lista		|
--------------------------------------*/

// verifica se um elemento especifico existe na lista
int checkExist(node head, int num){
	node p = head;
	while(p){
		if(p->num == num){
			return 1;
		}
		p = p->next;
	}
	return 0;
}

// verifica quantas ocorrencias de um elemento existe na lista
int checkQuantity(node head, int num){
	node p = head;
	int count = 0;
	while(p){
		if(p->num == num){
			count++;
		}
		p = p->next;
	}
	return count;
}

// mostra o elemento na ultima posição da lista
int lastElement(node head){
	node p = head;
	if(!p){
		return 0;
	}
	while(p->next){
		p = p->next;
	}
	return p->num;
}

// mostra quantos elementos existem na lista
int countElements(node head){
	node p = head;
	int n = 0;
	while(p){
		p = p->next;
		n++;
	}
	return n;
}

// mostra todos os elementos da lista
void showList(node head){
	node p = head;
	while(p){
		printf("%d ", *&p->num);
		p = p->next;
	}
}

