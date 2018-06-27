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

//Esta funcionando com as matrizes 4x4, para funcionar nas demais, deve-se alterar o contador "i" das funções InserirNaLinha/InserirNaColuna

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

	No* n = (No*) malloc(sizeof(No));
	n->linha = linha;
	n->coluna = coluna;
	n->valor = valor;
	n->direita = n;
	n->baixo = n;
	n->esquerda = n;
	n->cima = n;

	return n;

}

// Cria uma matriz vazia e devolve seu endereço de memória.
Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas) {

    int i, j;

	Matriz* m = (Matriz*) malloc(sizeof(Matriz));
	m->numLinhas = qtdeLinhas;
	m->numColunas = qtdeColunas;

	m->linhas = (No**) malloc(qtdeLinhas*sizeof(No*));
	m->colunas = (No**) malloc(qtdeColunas*sizeof(No*));

	for(i=0; i<qtdeLinhas; i++){
        m->linhas[i]=createNo(0, 0, 0);
	}

	for(j=0; j<qtdeColunas; j++){
        m->colunas[j]=createNo(0, 0, 0);
	}

	return m;
}

int InserirNaLinha(Matriz* m, int linha, No* novo){

    if((m == NULL) || (linha>m->numLinhas) || (linha<0)){
        return -1;
    }

    int i = 0;
    No* aux = m->linhas[linha];
    while(i<=m->numLinhas){
        aux = aux->direita;
        i++;
    }

    novo->direita = aux->direita;
    novo->esquerda = aux;
    aux->direita->esquerda = novo;
    aux->direita = novo;

    return 1;
}

int InserirNaColuna(Matriz* m, int coluna, No* novo){
	
    if((m == NULL) || (coluna>m->numColunas) || (coluna<0)){
        return -1;
    }

    int i = 0;
    No* aux = m->colunas[coluna];
    while(i<=m->numColunas){
        aux = aux->baixo;
        i++;
    }

    novo->baixo = aux->baixo;
    novo->cima = aux;
    aux->baixo->cima = novo;
    aux->baixo = novo;

    return 1;
}

// Insere o <valor> na matriz <m> na linha <linha> e coluna <coluna>. Caso a posição já exista, substitua o valor da célula.
int matriz_inserir(Matriz* m, int linha, int coluna, int valor) {

	No* novo = createNo(valor, linha, coluna);
	InserirNaLinha(m, linha, novo);
	InserirNaColuna(m, coluna, novo);
	int matriz_inserir(Matriz* m, int linha, int coluna, int valor);

	return 1;

}

void matriz_imprimir(Matriz* m){
	No* aux;
	int l,c;
	for(l=0; l < m->numLinhas; l++){
		aux = m->linhas[l]->direita;
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

			if(aux != m->linhas[l] && c == aux->coluna){
				printf("%d ", aux->valor);
				aux = aux->direita;
			}else{
				printf("%d ", 0);
			}

		}
		printf("\n", 0);
	}
}

void desalocar_matriz(Matriz* m) {

	int i, j;

	for(i=0; i<qtdeLinhas; i++){
        free(m->linhas[i]);
	}

	for(j=0; j<qtdeColunas; j++){
		free(m->colunas[j]); 
	}

	free(m);


}
