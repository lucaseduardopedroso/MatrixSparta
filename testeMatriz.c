#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(int argc, char const *argv[])
{
	Matriz* m1 = matriz_criar(4, 4);

	int r = matriz_inserir(m1, 3, 5, 2);

	printf("%d", r );



	return 0;
}