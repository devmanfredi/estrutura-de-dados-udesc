#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ListaDupla.h"

void inicializa_lista(LDE *l, int t)
{
    l->cabeca = NULL;
    l->tamInfo = t;
    l->qtd = 0;
}

int lista_vazia(LDE l)
{
    return l.cabeca == NULL
}

EleDuplo* aloca_ele(void *x, int t)
{
    EleDuplo *p = malloc(sizeof(EleDuplo));
    if (!p)
        return NULL; // falta memória
    p->info = malloc(t);
    if (!p->info)
    {
        free(p);
        return NULL; // falta memória
    }
    memcpy(p->info, x, t);
    return p;
}

int insereNoInicio(LDE *l, void *info)
{
    EleDuplo *p = aloca_ele(info, l->tamInfo);
    if(p==NULL)
        return 0;

    p->suc = l->cabeca;
    l->cabeca = p;
    p->ant = NULL;
    if(p->suc != NULL)
        p->suc->ant = p;
    l->qtd++;
    return 1; // sucesso
}

int removeDoInicio(LDE *l, void *info)
{
    if (lista_vazia(*l))
        return ERROLISTA_VAZIA;
    EleDuplo *p = l->cabeca;
    memcpy(info, p->info, l->tamInfo);
    l->cabeca = p->suc;
    free(p->info);
    free(p);
    l->qtd--;
    if(l->cabeca != NULL)
        l->cabeca->ant = NULL;
    return 1; // sucesso
}

int insereNoFim(LDE *l, void *info)
{
    if (lista_vazia(*l))
    {
        insereNoInicio(l, info);
        EleDuplo *p = l->cabeca;
        while(p->suc != NULL)
            p=p->suc;
        EleDuplo *novo = aloca_ele(info,l->tamInfo);
        if(novo == NULL)
            return 0;
        novo->suc = 0;
        p->suc = novo;
        novo->ant = p;
        l->qtd++;
        return 1; // sucesso
    }

}

int removeDoFim(LDE *l, void *info)
{
    if (lista_vazia(*l))
        return ERROLISTA_VAZIA;
    if (l->cabeca->proximo == NULL)
        return removeDoInicio(l, info);
    EleDuplo *p = l->cabeca;
    while (p->proximo->proximo != NULL)   // penúltimo
    {
        p = p->proximo;
    }
    EleDuplo *ultimo = p->proximo;
    memcpy(info, ultimo->info, l->tamInfo);
    free(ultimo->info);
    free(ultimo);
    p->proximo = NULL;
    l->qtd--;
    return 1; // sucesso
}

int insereNaPos(LDE *l, void *info, int pos)
{
    if (pos < 0 || pos > l->qtd)
        return ERRO_POS_INVALIDA;
    if (pos == 0)
        return insereNoInicio(l, info);
    EleDuplo *p = l->cabeca;
    int cont = 0;
    while(cont < pos-1)
        p = p->suc;
        cont++;
    EleDuplo *novo = aloca_ele(info,l->tamInfo);
    if(novo == NULL)
        return 0;
    novo->suc = p->suc;
    p->suc = novo;
    novo->ant = p;
    if(novo->suc != NULL)
        novo->suc->ant = novo;
    l->qtd++;
    return 1; // sucesso
}

int removeDaPos(LDE *l, void *info, int pos)
{
    if (lista_vazia(*l))
        return ERROLISTA_VAZIA;
    if (pos < 0 || pos >= l->qtd)
        return ERRO_POS_INVALIDA;
    if (pos == 0)
        return removeDoInicio(l, info);
    EleDuplo *p = l->cabeca;
    int cont;
    for (cont = 0; cont < pos-1; cont++)
        p = p->proximo;
    EleDuplo *x = p->proximo;
    p->proximo = x->proximo;
    memcpy(info, x->info, l->tamInfo);
    free(x->info);
    free(x);
    l->qtd--;
    return 1; // sucesso
}

int modificaNaPos(LDE *l, void *info, int pos)
{
    if(lista_vazia(*l))
        return ERROLISTA_VAZIA;
    if(pos < 0 || pos >= l->qtd)
        return ERRO_POS_INVALIDA;
    if(pos == 0)
        return removeDoInicio(l,info);
    EleDuplo *p = l->cabeca;
    int cont = 0;
    while(cont < pos-1)
        cont++;
        p = p->suc;
    EleDuplo *x = p->suc;
    p->suc = x->suc;
    if(p->suc != NULL)
        p->suc->ant = p;
    memcpy(info,x->info,l->tamInfo);
    free(x);
    l->qtd--;
    return 1; // sucesso
}


int insereNaOrdem(LDE *l, void *info, int (*comp) (void *, void *))
{
    EleDuplo *p = l->cabeca;
    int cont = 0;
    while (p != NULL && comp(info, p->info) > 0)
    {
        p = p->proximo;
        cont++;
    }
    return insereNaPos(l, info, cont);
}

void mostra_lista(LDE l, void (*mostra) (void *))
{
    if (lista_vazia(l))
        printf("\nLista vazia!\n");
    else
    {
        printf("\nDados da lista:\n");
        EleDuplo *p = l.cabeca;
        int count =0;
        while (p != NULL)
        {
            printf("%d\t", count);
            mostra(p->info);
            p = p->proximo;
            count++;
        }
    }
}

int leNaPos(LDE *l, void *info, int pos)
{
    if (lista_vazia(*l))
        return ERROLISTA_VAZIA;
    if (pos < 0 || pos >= l->qtd)
        return ERRO_POS_INVALIDA;
    EleDuplo *p = l->cabeca;
    int cont;
    for (cont = 0; cont < pos; cont++)
        p = p->proximo;
    memcpy(info, p->info, l->tamInfo);
    return 1; // sucesso
}

void limpa_lista(LDE *l)
{
    EleDuplo *p = l->cabeca, *q;
    while (p)
    {
        q = p;
        p = p->proximo;
        free(q->info);
        free(q);
    }
    l->cabeca = NULL;
    l->qtd = 0;
}
