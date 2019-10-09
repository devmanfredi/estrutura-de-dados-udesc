#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


int main(){
    int i;
    Pilha p;

    inicializa_pilha(&p,10);
    for(i=1;i<=p.capacidade;i++){
        empilha(&p,i);
    }
    mostra_pilha(p);



    desaloca_pilha(&p);

    return 0;
}
