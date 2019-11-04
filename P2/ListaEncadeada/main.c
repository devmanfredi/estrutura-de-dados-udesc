#include "lista.h"
#include <stdio.h>

void mostra_float(void *x);
int compara_float(void *x, void *y);

int main()
{
    printf("\t_=_=_=_= LISTA ENCADEADA _=_=_=_=_=\t\n");
    Lista l;
    float x = 123.8;
    char r[2][11] = {"falhou!", "deu certo!"};

    inicializa_lista(&l, sizeof(float));

    printf("\nA insercao no inicio de %.2f %s\n", x, r[insereNoInicio(&l, &x)]);



    return 0;
}

void mostra_float(void *x)
{
    printf("%f\n", *(float*) x);
}

int compara_float(void *x, void *y)
{
    float *a = x, *b = y;
    if (*a > *b)
        return 1;
    if (*a < *b)
        return -1;
    return 0;
}
