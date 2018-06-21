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

typedef struct No{
	int linha;
	int coluna;
	int valor;
	struct No* direita;
	struct No* baixo;	
}No;

typedef struct{
	No** linhas;	//ponteiro para o vetor cujas células são ponteiros de nós
	No** colunas;	//ponteiro para o vetor cujas células são ponteiros de nós
	int numLinhas;	//Quantidade de linhas da matriz
	int numColunas;	//Quantidade de colunas da matriz
}Matriz;

/* Protótipos */

Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas);
int matriz_inserir(Matriz* m, int linha, int coluna, int valor);
int matriz_acessar(Matriz* m, int linha, int coluna);
void matriz_imprimir(Matriz* m);
void desalocar(Matriz* m);


/* Implementação */

No* createNo(int valor) {
	No* n = (No*) malloc(sizeof(No));
	n->linha = qtdeLinhas;
	n->coluna = 0;
	n->linha = 0;
	n->valor = valor;
	n->direita = NULL;
	n->baixo = NULL;

	return n;

}

// Cria uma matriz vazia e devolve seu endereço de memória.
Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas) {

	Matriz* m = (Matriz*) malloc(sizeof(Matriz));
	m->numLinhas = qtdeLinhas;
	m->numColunas = qtdeColunas;


	m->linhas = (No**) malloc (qtdeColunas* sizeof(No*));
	m->colunas = (No**) malloc(qtdeLinhas* sizeof(No*));

	int i, j;

	for (i = 0; i < m->qtdeLinhas; i++)
	{

		for (j = 0; j < m->qtdeColunas; j++)
		{
	

		m->linhas[i] = m->linhas[i] = NULL;

		}

	}



	return m;
}

// Insere o <valor> na matriz <m> na linha <linha> e coluna <coluna>. Caso a posição já exista, substitua o valor da célula.
int matriz_inserir(Matriz* m, int linha, int coluna, int valor) {

	No* novo = createNo(valor);
	novo->linha = linha;
	novo->coluna = coluna;
	

	//m[m->linhas[novo->linha] * m->numColunas + m->colunas[novo->coluna]] = novo;


	return 1;

}

// Devolve o valor correspondente a linha e coluna solicitada. Faça a validação dos índices. Caso a posição solicitada esteja fora do intervalo, devolva zero.
int matriz_acessar(Matriz* m, int linha, int coluna);

// Imprime os valores da matriz na tela. Cada linha deve ser impressa em uma linha diferente e os elementos separados por espaço ou tabulação. Os elementos não representados na matriz (valor zero), também devem ser impressos.
void matriz_imprimir(Matriz* m) {

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
					printf("%d ", 0);
				}
			}

		}
		printf("\n ", 0);
	}


// Libera toda memória alocada dinamicamente para a matriz.
void desalocar(Matriz* m);

