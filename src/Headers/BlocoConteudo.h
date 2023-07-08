#ifndef BLOCOCONTEUDO_H
#define BLOCOCONTEUDO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct ListaBC *apontadorListaBC;
typedef struct ListaBC{
    apontadorListaBC proximo;
    BlocoConteudo blocoConteudo;
}ListaBlocoConteudo;
typedef struct {
    int endereco;
    char *conteudo;
}BlocoConteudo;

BlocoConteudo criaBlocoConteudo(char *string, int endereco, int tamanhoBloco);

int getEndereco(BlocoConteudo blocoConteudo);

char* getConteudoBloco(BlocoConteudo blocoConteudo);

ListaBlocoConteudo* criaListaBlocoConteudo(char *string, int endereco, int tamanhoBloco);

void inserirConteudo(ListaBlocoConteudo *lstaBlocoConteudo, char *string, int endereco, int tamanhoBloco);


#endif //BLOCOCONTEUDO_H