#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

void inicializa_fila(Fila *f, int c)
{
    f->dados = malloc(sizeof(int) * c);
    f->capacidade = c;
    f->inicio = 0;
    f->fim = 0;
    f->num_ele = 0;
}

int fila_vazia(Fila f)
{
    return f.num_ele == 0;
}

int fila_cheia(Fila f)
{
    return f.num_ele == f.capacidade;
}

int inserir(Fila *f, int info)
{
    if (fila_cheia(*f)){
       return ERRO_FILA_CHEIA;
    }

    f->num_ele++;
    f->dados[f->fim] = info;
    f->fim = (f->fim + 1) % f->capacidade; // incremento circular
    return 1; //sucesso
}

int remover(Fila *f, int *info)
{
    if (fila_vazia(*f))
        return ERRO_FILA_VAZIA;
    f->num_ele--;
    *info = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->capacidade; // incremento circular
    return 1; // sucesso
}

void mostra_fila(Fila f)
{
    if (fila_vazia(f))
        printf("Fila vazia!\n");
    else
    {
        int i;
        printf("Dados da fila:\n");
        if (f.inicio < f.fim)
        {
            for(i = f.inicio; i < f.fim; i++)
            {
                printf("%d\n", f.dados[i]);
            }
        }
        else
        {
            for(i = f.inicio; i < f.capacidade; i++)
                printf("%d\n", f.dados[i]);
            for(i = 0; i < f.fim; i++)
                printf("%d\n", f.dados[i]);
        }
    }
}
