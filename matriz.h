#include <stdio.h>
#include <stdlib.h>

/* 
#####################################
## PRACTICE ED1 - MATRIZ ESPARSA  ##
## @maralucilg                    ##
## Lucas Eduardo				  ##
## Thaise Nakao					  ##
#####################################
*/

typedef struct node{
	int linha;
	int coluna;
	int valor;
	struct node* direita;
	struct node* baixo;	
}Node;

typedef struct{
	Node** linhas;	//ponteiro para o vetor cujas células são ponteiros de nós
	Node** colunas;	//ponteiro para o vetor cujas células são ponteiros de nós
	int numLinhas;	//Quantidade de linhas da matriz
	int numColunas;	//Quantidade de colunas da matriz
}Matriz;

/* Protótipos */

Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas);
int matriz_inserir(Matriz* m, int linha, int coluna, int valor);
int matriz_acessar(Matriz* m, int linha, int coluna);
void imprimir(Matriz* m);
void desalocar(Matriz* m);
void ler(char* arquivo, Matriz* m);

/* Implementação */

Node* createNode(int valor) {
	Node* n = (Node*) malloc(sizeof(Node));
	n->linha = 0;
	n->coluna = 0;
	n->valor = valor;
	n->direita = NULL;
	n->baixo = NULL;

	return n;

}

// Cria uma matriz vazia e devolve seu endereço de memória.
Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas) {

	Matriz* m = (Matriz*) malloc(sizeof(Matriz));
	m->numLinhas = 0;
	m->numColunas = 0;
	m->linhas = (Node**) malloc (sizeof(Node*));
	m->colunas = (Node**) malloc(sizeof(Node*));

	return m;
}

// Insere o <valor> na matriz <m> na linha <linha> e coluna <coluna>. Caso a posição já exista, substitua o valor da célula.
int matriz_inserir(Matriz* m, int linha, int coluna, int valor) {

	Node* novo;
	novo->linha = linha;
	novo->coluna = coluna;

	m[m->linhas[novo->linha] * m->numColunas + m->colunas[novo->coluna]] = valor;


	return 1;

}

// Devolve o valor correspondente a linha e coluna solicitada. Faça a validação dos índices. Caso a posição solicitada esteja fora do intervalo, devolva zero.
int matriz_acessar(Matriz* m, int linha, int coluna);

// Imprime os valores da matriz na tela. Cada linha deve ser impressa em uma linha diferente e os elementos separados por espaço ou tabulação. Os elementos não representados na matriz (valor zero), também devem ser impressos.
void imprimir(Matriz* m);

// Libera toda memória alocada dinamicamente para a matriz.
void desalocar(Matriz* m);

void ler(char* arquivo, Matriz* m);
