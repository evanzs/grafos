#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/* Estruturas usadas para a construcao dos algoritmos */
typedef struct listaAdj {
    int dest, peso, marcado;
    // dest salva o nome do vertice adjacente
    // peso armazena o peso nao-negativos das arestas que ligam os vertices adjacentes
    // marcado salva se o vertice foi visitado 
    struct listaAdj *prox; 
} *def_listaAdj;

typedef struct listaEnc {
    int info;
    struct listaEnc *prox;
} *def_listaEnc;

typedef struct fila {
    int item;
    struct fila *prox;
} *def_fila;

typedef struct pilha {
	int item;
	struct pilha *prox;
} *def_pilha;

/* Funcoes para alteracao da pilha */
void push(def_pilha *p, int x) { // insere elemento na pilha 
    def_pilha q = (def_pilha) malloc (sizeof(struct pilha));
    q->item = x;
    q->prox = (*p);
    (*p) = q;
}

int pop(def_pilha *p, int *x) { // remove elemento da pilha 
    def_pilha q;
    if(!(*p))
        return 1; // erro
    q = (*p);
    *x = q->item;
    (*p) = (*p)->prox;
    free(q);
    return 0; // sucesso
}

/* Funcoes para alteracao da fila */
void enqueue(def_fila *fila, int x) { // enfileira elemento na fila
    def_fila p = (def_fila) malloc (sizeof (struct fila));
    p->item = x;
    p->prox = NULL;

    if ((*fila) == NULL) {
        *fila = p;
        return;
    }

    def_fila q = (*fila);
    while (q->prox != NULL) {
        q = q->prox;
    }

    q->prox = p;   
}

void dequeue(def_fila *fila, int *x) { // desenfileira elemento da fila
    if(!(*fila)) {
        printf("\nFila vazia");
        return;
    }
    def_fila p = (*fila);
    *x = p->item;
    (*fila) = p->prox;
    free(p);
    return;
}

/* Funcoes para impressao na tela*/
void imprimeListaAdj(def_listaAdj listaAdj[], int n) { // imprime todos os dados da lista adjacente
    int i;
    def_listaAdj p;

    for (i = 0; i < n; i++) {
        p = listaAdj[i];
        printf("%d|%d", p->dest, p->marcado); // printf do identificador do vertice
        p = p->prox;
        if (p)
            printf(" - ");
        while (p != NULL){
            printf("%d(%d)|%d", p->dest, p->peso, p->marcado); // printf dos vertices adjacentes
            p = p->prox;
            if(p)
                printf(" - ");
        }
        printf("\n");
    }
}

void imprimeListaAdj2(def_listaAdj lista) { // imprime somente identificador e vertices adjacentes da lista adjacente
    def_listaAdj p = lista;

    while (p) { 
        printf("%d - ", p->dest);
        p = p->prox;
    }
}

void imprimeListaEnc(def_listaEnc listaEnc) { // imprime lista encadeada
    printf("\n");

    while (listaEnc != NULL) {
        printf("%d - ", listaEnc->info);
        listaEnc = listaEnc->prox;
    }
}

void imprimePilha(def_pilha p) { // imprime elementos da pilha 
	while(p) {
		printf("%d ", p->item);
		p = p->prox;
	}
	printf("\n");
}

void imprimeFila(def_fila fila) { // imprime dados da fila
    def_fila p = fila;

    while (p != NULL) {
        printf("%d", p->item);
        p = p->prox;
        if(p)
            printf(" - ");
    }
    printf("\n");
}

void imprimeVetor(int dist[], int n) { // imprime dados do vetor
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }

    printf("\n");
}

/* Funcoes para alteracao da listaAdj*/
void inicializaListaAdj(def_listaAdj listaAdj[], int tamanho) { // inicializa lista adjacente
    int i;

    for (i = 0; i < tamanho; i++)
        listaAdj[i] = NULL;
}

void criaListaAdj(def_listaAdj listaAdj[], int tamanho) { // cria os identificadores do vertices na lista adjacente
    int i, id;

    for (i = 0; i < tamanho; i++) {
        listaAdj[i] = (def_listaAdj) malloc (sizeof(struct listaAdj));
        listaAdj[i]->dest = i+1;
        listaAdj[i]->prox = NULL;
        listaAdj[i]->marcado = 0;
    }
}

void insereListaAdj(def_listaAdj listaAdj[], int tamanho, int ponderado) { // insercao dos vertices adjacentes
    int i, verticeAdj, peso;
    def_listaAdj p;

    for (i = 0; i < tamanho; i++) {
        p = listaAdj[i];
        printf("\nInsira os vertices adjacentes ao vertice %d (0 para Sair): ", p->dest);
        scanf("%d", &verticeAdj);
        while (verticeAdj != 0) {
            p->prox = (def_listaAdj) malloc (sizeof (struct listaAdj));
            p = p->prox;
            p->dest = verticeAdj;
            p->marcado = 0;
            if (ponderado) { // se ponderado, solicita ao usuario entrada do peso nao negativo
                printf("Entre com o peso da aresta entre %d e %d: ", (i+1), verticeAdj);
                do { // loop do-while para impedir entrada de pesos negativos
                    scanf("%d", &peso);
                    if (peso < 0)
                        printf("Peso negativo. Entre com o peso da aresta entre %d e %d: ", (i+1), verticeAdj);
                } while (peso < 0);
                p->peso = peso;
            }   
            else
                p->peso = 1; // peso padrao para grafos nao ponderados
            p->prox = NULL;
            printf("\nVertice adjacente %d inserido. Insira o proximo (0 para Sair): ", verticeAdj);
            scanf("%d", &verticeAdj);
        }
    }
}

/* Funcoes para alteracao da listaEnc */
void insereListaEnc(def_listaEnc *lista, int info) { // insere elemento na lista encadeada
    def_listaEnc p = (def_listaEnc) malloc (sizeof (struct listaEnc));
    p->info = info;
    p->prox = NULL;

    if (*lista == NULL) {
        *lista = p;
        return;
    }

    def_listaEnc q = *lista;

    while (q->prox != NULL) {
        q = q->prox;
    }

    q->prox = p;
}

void inicializaListaEnc(def_listaEnc *listaEnc, int n) { // inicializa lista encadeada 
    int i;

    for (i = 0; i < n; i++)
        insereListaEnc(listaEnc, i+1); // lista recebe valores de 1 a n
}

void removeListaEnc(def_listaEnc *listaEnc, int elem) { // remove elemento da lista encadeada
    if (*listaEnc == NULL)
        return;
    
    def_listaEnc q = *listaEnc;
    if (elem == q->info) {
        *listaEnc = q->prox;
        free(q);
        return;
    }

    def_listaEnc p;
    while (q != NULL && q->info != elem) {
        p = q;
        q = q->prox;
    }

    if (q == NULL)
        return;

    p->prox = q->prox;
    free(q);
}

/* Funcao para alteracao de Vetor */
void inicializaVetor(int dist[], int n) { // inicializa vetor com maior valor inteiro positivo 
    int i;

    for (i = 0; i < n; i++)
        dist[i] = INT_MAX;
}

/* Algoritmos das Buscas */
void BuscaProfundidade(def_listaAdj listaAdj[], int origem, int tamanho, int *contagem) {
    int i, vertice;

    printf("Visitado: %d\n", origem); // exibir numero
    listaAdj[origem-1]->marcado = *contagem; // marcar numero da visita com o numero da contagem
    def_listaAdj p = listaAdj[origem-1]; // elemento sendo visitado
    def_listaAdj *q = listaAdj; // ponteiro para inicio da lista de adj
    p = p->prox; // proximo elemento
    while(p) { // loop ate visitar todos os vizinhos
        p->marcado = ++(*contagem);
        vertice = p->dest; // numero do proximo vizinho
        if(q[vertice-1]->marcado == 0) { // se elemento ainda nao foi visitado
            printf("    Proximo vertice: %d.\n", vertice);
            BuscaProfundidade(listaAdj, vertice, tamanho, contagem); // visitar primeiro elemento da lista de adj por recursao
        }
        else { // elemento ja foi visitado, 
            printf("    %d ja foi visitado antes. Ir para proximo.\n", vertice);    
        }
        p = p->prox; // ir para o proximo da lista de adj
    }
}

void BuscaLargura(def_listaAdj listaAdj[], int origem, int dist[]) {
    int vertice; // armazena posicao do vertice atual 
    int dest; // armazena proxima posicao de vertice a ser analisada
    int cont = 0; // contador de marcacao durante a busca
    def_fila fila = NULL; // fila para controle da busca
    def_listaAdj *q = listaAdj; // ponteiro para vetor listaAdj
    def_listaAdj p; // ponteiro para lista de vertices adjacentes de cada posicao do vetor listaAdj

    origem--; // equaliza valor de origem em relacao a posicao no vetor
    q[origem]->marcado = ++cont; // marca origem da busca como visitado
    dist[origem] = 0; // armazena distancia da origem
    enqueue(&fila, origem+1); // enfileira origem na fila
    imprimeFila(fila);
    while (fila != NULL) {
        // printf("\n");
        // imprimeFila(fila);        
        dequeue(&fila, &vertice); // retira vertice a ser visitado da fila
        printf("Visitado: %d\n", vertice); // exibe vertice
        vertice--; // equaliza valor de vertice em relacao a posicao no vetor
        // imprimeFila(fila);
        // printf("\n");
        p = q[vertice]->prox; // atribui a p a lista de vertices adjacentes correspondente a variavel 'vertice'
        // imprimeListaAdj2(p);
        // printf("\n");
        while(p != NULL) { // loop de leitura da lista de vertice adjacentes
            dest = p->dest - 1; // identificador do vertice adjacente equalizado em relacao a posicao do vetor
            if (q[dest]->marcado == 0) { // verifica se o vertice identificador (posicao inicial do vetor listaAdj) foi visitado
                q[dest]->marcado = ++cont; // marca vertice identificador como visitado
                p->marcado = cont; // marca vertice como visitado na lista de adjacentes
                // dest = p->dest;
                dist[dest] = dist[vertice] + 1; // calcula distancia de dest com relacao a 'vertice'
                enqueue(&fila, dest+1); // enfileira dest na fila
                printf("\tProximo vertice a ser visitado: %d\n", dest+1);
            }
            else { // marca somente vertice como visitado na lista de adjacentes
                p->marcado = ++cont;
                if (q[vertice]->marcado < q[dest]->marcado)
                    printf("\tVertice %d sera visitado. Ir para o proximo.\n", dest+1);
                else
                    printf("\tVertice %d ja foi visitado. Ir para o proximo.\n", dest+1);                    
            }
            p = p->prox; // caminha pela lista de vertices adjacentes
        }
    }
}

void Dijkstra(def_listaAdj listaAdj[], int origem, int dist[], int n) {
    int i; // iterador
    int vertice; // salva vertice atual que esta sendo analisado
    int dest; // salva identificador do vertice adjacente em relacao a variavel 'vertice'
    int menor; // salva peso do vertice de menor peso da lista
    def_listaAdj *q = listaAdj; // ponteiro para vetor listaAdj
    def_listaAdj p; // ponteiro para lista de vertices adjacentes
    def_listaEnc listaEnc = NULL; // lista encadeada usada no algoritmo

    inicializaListaEnc(&listaEnc, n); // inicializa listaEnc com valores de 1 a n
    inicializaVetor(dist, n); // inicializa vetor de distancias

    vertice = origem-1; // equaliza valor de vertice atual em relacao a posicao no vetor
    q[vertice]->marcado = 1; // marca vertice como visitado
    dist[vertice] = 0; // atribui distancia da origem como zero
    while (listaEnc != NULL) { // loop enquanto listaEnc nao for vazia
        removeListaEnc(&listaEnc, vertice+1); // remove vertice a ser visitado da listaEnc
        q[vertice]->marcado = 1; // marca vertice como visitado
        printf("\nVisitado: %d\n", vertice+1); // exibe vertice visitado
        p = q[vertice]->prox; // atribui a p a lista de vertices adjacentes a 'vertice'
        while (p != NULL) { // loop para analisar todos os vertices adjacentes
            dest = p->dest-1; // equaliza valor de vertice adjacente a posicao no vetor
            if (dist[dest] > dist[vertice] + p->peso)
                dist[dest] = dist[vertice] + p->peso;
            // se distancia de vertice adjacente for menor que distancia do vertice mais o peso da aresta entre vertice e dest
            // atribui a distancia de vertice adjcente

            p = p->prox; // caminha pela lista de vertices adjacentes
        }

        menor = INT_MAX; // menor inicializa sempre com o maior valor inteiro positivo
        for (i = 0; i < n; i++) {
            if (q[i]->marcado == 0 && dist[i] < menor) {
                menor = dist[i];
                vertice = i;
                // se vertice identificador (posicao inicial do vetor q) nao estiver marcado e distancia for menor que
                // valor da variavel 'menor', atribui a menor a distancia e salva em vertice a posicao no vetor referente 
                // ao vertice com menor distancia
            }
        }
        if (listaEnc != NULL)
            printf("\tProximo vertice: %d", vertice+1); // imprime proximo vertice a ser analisado
    }
}

void ordenacaoTopologicaZiviani(def_listaAdj listaAdj[], int origem, int tamanho, int *contagem, def_pilha *topologica) { // ordenacaoTopologicaZiviani 
    int i, vertice;

    printf("Visitado: %d\n", origem); // exibir numero
    listaAdj[origem-1]->marcado = *contagem; // marcar numero da visita com o numero da contagem
    def_listaAdj p = listaAdj[origem-1]; // elemento sendo visitado
    def_listaAdj *q = listaAdj; // ponteiro para inicio da lista de adj
    p = p->prox; // proximo elemento
    while(p) { // loop ate visitar todos os vizinhos
        p->marcado = ++(*contagem);
        vertice = p->dest; // numero do proximo vizinho
        if(q[vertice-1]->marcado == 0) { // se elemento ainda nao foi visitado
            printf("    Proximo vertice: %d.\n", vertice);
            ordenacaoTopologicaZiviani(listaAdj, vertice, tamanho, contagem, topologica); // topologica visitar primeiro elemento da lista de adj por recursao
        }
        else { // elemento ja foi visitado, 
            printf("    %d ja foi visitado antes. Ir para proximo.\n", vertice);    
        }
        p = p->prox; // ir para o proximo da lista de adj
    }
    push(topologica, origem);
}

void ordenacaoTopologicaPreiss(def_listaAdj listaAdj[], int graus[], int tamanho, def_fila *zeros, def_fila *ordenada) { //ordenacaoTopologicaPreiss
    if(*zeros) {
        int i, primElemFila;
        def_listaAdj p;

        dequeue(zeros, &primElemFila); // remove fila dos zeros (fila com vertices de grau zero)
        enqueue(ordenada, primElemFila); // insere lista ordenada

        primElemFila--; // equalizar indices real e do vetor
        graus[primElemFila]--;
        p = listaAdj[primElemFila]->prox; 
        // printf("\nVisitado: %d", primElemFila+1);
        while(p) {
            graus[p->dest - 1]--;
            if(!graus[p->dest - 1]) {
                enqueue(zeros, p->dest);
            }
            p = p->prox;
        }
        ordenacaoTopologicaPreiss(listaAdj, graus, tamanho, zeros, ordenada);
    }
}

/* Funcoes para preparacao dos algoritmos e criacao do menu */
void testaListaAdj(def_listaAdj **listaAdj, int *tamanho, int *ponderado) { // funcao para preparacao da insercao da listaAdj
    char op;

    printf("\nEntre com o numero de vertices: ");
    scanf("%d", tamanho);
    do {
        printf("\nO grafo eh ponderado? [S/n] ");
        scanf("\n%c", &op);
        op = toupper(op);
        switch (op) {
            case 'S': *ponderado = 1;
            break;
            case 'N': *ponderado = 0;
            break;
            default: printf("Opcao incorreta.\n");
        }
    } while (op != 'S' && op != 'N');

    (*listaAdj) = (def_listaAdj*) malloc ((*tamanho) * sizeof(struct listaAdj));
    
    inicializaListaAdj((*listaAdj), (*tamanho));
    criaListaAdj((*listaAdj), *tamanho);   
    insereListaAdj((*listaAdj), *tamanho, *ponderado);
    printf("\n");
    imprimeListaAdj((*listaAdj), *tamanho);
}

void testaBuscaProf(def_listaAdj listaAdj[], int tamanho, int origem) { // preparacao para busca em Profundidade
    int contagem = 1; // indicador do numero da visita
    BuscaProfundidade(listaAdj, origem, tamanho, &contagem);
    printf("Fim da busca.\n");
}

void testaBuscaLarg(def_listaAdj listaAdj[], int tamanho, int origem) { // funcao para preparacao da busca emm largura
    int dist[tamanho];
    inicializaVetor(dist, tamanho);

    BuscaLargura(listaAdj, origem, dist);
    printf("\nFim da Busca. Lista Adjacente:\n");
    imprimeListaAdj(listaAdj, tamanho);
    printf("\nDistancias:\n");
    imprimeVetor(dist, tamanho);
}

void testaDijkstra(def_listaAdj listaAdj[], int tamanho, int origem) { // funcao para preparacao do algoritmo de Dijkstra
    int dist[tamanho];

    Dijkstra(listaAdj, origem, dist, tamanho);
    printf("\nFim da Busca. Distancias: ");
    imprimeVetor(dist, tamanho);
}

int verificaOrdenaTopZiviani(def_listaAdj listaAdj[], int n) { // retorna se busca teve sucesso ou nao em visitar todos os vertices
    int i;
    def_listaAdj p; // ponteiro para lista de vertices adjacentes

    for (i = 0; i < n; i++) {
        p = listaAdj[i]; // atribui lista de vertices adjacentes da posicao i do vetor listaAdj
        while (p) {
            if (!p->marcado) // verifica se vertice foi visitado 
                return 0; // sem sucesso
            p = p->prox;
        }
    }

    return 1; // com sucesso
}

void testaOrdenaTopZiviani(def_listaAdj listaAdj[], int tamanho, int origem) { // preparacao para Ordenacao Topoligica por Ziviani
    int contagem = 1; // indicador do numero da visita
    def_pilha topologica = NULL; // pilha que armazenara vertices a serem visitados
    ordenacaoTopologicaZiviani(listaAdj, origem, tamanho, &contagem, &topologica);
    printf("Fim da busca.\n");
    if (verificaOrdenaTopZiviani(listaAdj, tamanho)) {
        printf("Ordenacao Topologica: ");
        imprimePilha(topologica);
    }
    else {
        printf("Busca nao conseguiu passar por todos os vertices.\n");
    }
}

void calculaGraus(def_listaAdj listaAdj[], int graus[], int tamanho, def_fila *zeros) { // calcula graus dos vertices da lista Adjacente
    int i, j; // iteradores
    def_listaAdj *q = listaAdj; // ponteiro para inicio da lista adj
    def_listaAdj p; // ponteiro para armazenar elemento atual

    for(i = 0; i < tamanho; i++) {
        graus[i] = 0;
        for(j = (i+1)%tamanho; j != i; j = (j+1)%tamanho) {
            p = q[j]->prox;
            while(p) {
                if((p->dest - 1) == i)
                    graus[i]++;
                p = p->prox;
            }
        }
        if(!graus[i])
            enqueue(zeros, (i+1));
    }
}

void testaOrdenaTopPreiss(def_listaAdj listaAdj[], int tamanho) {
    def_fila zeros = NULL, ordenada = NULL;
    int graus[tamanho];
    calculaGraus(listaAdj, graus, tamanho, &zeros);
    // printf("Fila zeros: ");
    // imprimeFila(zeros);
    ordenacaoTopologicaPreiss(listaAdj, graus, tamanho, &zeros, &ordenada);
    printf("Lista Ordenada: ");
    imprimeFila(ordenada);
}

int entradaOrigem(int n) { // entrada que retorna origem para comecar a busca
	int origem;

	printf("Qual a origem? ");
	do {
		scanf("%d", &origem);
		if (origem < 1 || origem > n)
			printf("Valor invalido. Qual a origem? ");
	} while (origem < 1 || origem > n);

	return origem;
}

void menu() { // cria menu e chama as funcoes de preparacao para execucao das buscas
    int tamanho, ponderado, origem, controle = 0;
    char op;
    def_listaAdj *listaAdj;

    do {
        do {
            system("cls");
            printf("----------  GRAFOS  ----------\n");
            printf("1. Inserir Lista de Adjacencia\n");
            printf("2. Busca em Largura\n");
            printf("3. Busca em Profundidade\n");
            printf("4. Dijkstra\n");
            printf("5. Ordenacao Topologica (por Ziviani)\n");
            printf("6. Ordenacao Topologica (por Preiss)\n");
            printf("0. Sair\n");
            printf("Opcao -> ");
            scanf("\n%c", &op);
        } while (op < '0' && op > '6');

        switch(op) {
            case '0': return;
            case '1':
            	controle = 1; 
                testaListaAdj(&listaAdj, &tamanho, &ponderado);
                break;
            case '2':
                if (!controle) { 
                    printf("\nNenhuma lista de Adjacencia inserida.\n");
                    break;
                }
                origem = entradaOrigem(tamanho);
                testaBuscaLarg(listaAdj, tamanho, origem);
                break;
            case '3': 
                if (!controle) { 
                    printf("\nNenhuma lista de Adjacencia inserida.\n");
                    break;
                }
                origem = entradaOrigem(tamanho);
                testaBuscaProf(listaAdj, origem, tamanho);
                break;
            case '4':
                if (!controle) { 
                    printf("\nNenhuma lista de Adjacencia inserida.\n");
                    break;
                }
                origem = entradaOrigem(tamanho);
                testaDijkstra(listaAdj, tamanho, origem);
                break;
            case '5':
            	if (!controle) { 
                    printf("\nNenhuma lista de Adjacencia inserida.\n");
                    break;
                }
				origem = entradaOrigem(tamanho);
                testaOrdenaTopZiviani(listaAdj, tamanho, origem);
                break;
            case '6':
            	if (!controle) { 
                    printf("\nNenhuma lista de Adjacencia inserida.\n");
                    break;
                }
                testaOrdenaTopPreiss(listaAdj, tamanho);
                break;  	
        }
        do {
            printf("Voce quer continuar? [S/n] ");
            scanf("\n%c", &op);
            op = toupper(op);
            if (op != 'S' && op != 'N')
                printf("\nOpcao incorreta.\n");
        } while (op != 'S' && op != 'N');
    } while (op == 'S');
}

int main() {
    menu();
    printf("\nFim do programa. []'s");
    return 0;
}