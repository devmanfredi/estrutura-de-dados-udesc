#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    Fila f;
    int n,i;
    scanf("%i",&n);
    inicializa_fila(&f,n);


    //mostra_fila(f);

    printf("%i\n",f.capacidade);
    return 0;


}
