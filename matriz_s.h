#include <stdio.h>
#include <stdlib.h>

/* 
####################################
## PRACTICE ED1 - MATRIZ ESPARSA  ##
## @maralucilg                    ##
## Lucas Eduardo				  ##
## Thaise Nakao					  ##
####################################
*/

typedef struct no{
	int linha;
	int coluna;
	int valor;
	struct no* direita;
	struct no* esquerda;
	struct no* cima;	
	struct no* baixo;	
}No;

typedef struct{
	No** linhas;	//ponteiro para o vetor cujas células são ponteiros de nós
	No** colunas;	//ponteiro para o vetor cujas células são ponteiros de nós
	int numLinhas;	//Quantidade de linhas da matriz
	int numColunas;	//Quantidade de colunas da matriz
}Matriz;


No* createNo(int valor, int linha, int coluna) {

	No* n = (No*) malloc (sizeof(No));
	n->linha = linha;
	n->coluna = coluna;
	n->valor = valor;
	n->direita = n->direita;
	n->esquerda = n->esquerda;
	n->cima = n->cima;
	n->baixo = n->baixo;


	return n;

}

// Cria uma matriz vazia e devolve seu endereço de memória.
Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas) {

	Matriz* m = (Matriz*) malloc (sizeof(Matriz));
	m->numColunas = qtdeColunas;
	m->numLinhas = qtdeLinhas;

	m->linhas = (No**) malloc(qtdeLinhas*sizeof(No));
	m->colunas = (No**) malloc (qtdeColunas*sizeof(No));

	int i;

	for (i = 0; i < qtdeLinhas; i++)
	{
		m->linhas[i] = createNo(0, i, 0);
	}

	for (i = 0; i < qtdeColunas; i++)
	{
		m->colunas[i] = createNo(0, 0, i);
	}


	return m;

}

// Insere o <valor> na matriz <m> na linha <linha> e coluna <coluna>. Caso a posição já exista, substitua o valor da célula.
int matriz_inserir(Matriz* m, int linha, int coluna, int valor);

// Devolve o valor correspondente a linha e coluna solicitada. Faça a validação dos índices. Caso a posição solicitada esteja fora do intervalo, devolva zero.
int matriz_acessar(Matriz* m, int linha, int coluna);

// Imprime os valores da matriz na tela. Cada linha deve ser impressa em uma linha diferente e os elementos separados por espaço ou tabulação. Os elementos não representados na matriz (valor zero), também devem ser impressos.
void matriz_imprimir(Matriz* m);

// Libera toda memória alocada dinamicamente para a matriz.
void matriz_desalocar(Matriz* m);

Matriz* matriz_ler(char* arquivo);

// IMPLEMENTACAO

void matriz_imprimir(Matriz* m){ 
	No* aux;
	int l,c;
	for(l=0; l < m->numLinhas; l++){
		aux = m->linhas[l];
		for(c = 0; c < m->numColunas; c++){
			// if(aux != NULL){
			// 	if(c == aux->coluna){
			// 		printf("%d ", aux->valor);				
			// 		aux = aux->direita;
			// 	}else{
			// 		printf("%d ", 0);
			// 	}
			// }else{
			// 	printf("%d ", 0);
			// }

			
				if(aux != NULL && c == aux->coluna){
					printf("%d ", aux->valor);				
					aux = aux->direita;
					
				}else{
					//printf("%d ", 0);
				}
			}

		}
		printf("\n ");
	}

