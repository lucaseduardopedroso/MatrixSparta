#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(int argc, char const *argv[])
{
	Matriz* m1 = matriz_criar(4, 4);

		    matriz_inserir(m1, 0, 3, 2);
			matriz_inserir(m1, 1, 2, 5);
			matriz_inserir(m1, 3, 0, 9);
			matriz_inserir(m1, 3, 3, 6);

	matriz_imprimir(m1);


	



	return 0;
}