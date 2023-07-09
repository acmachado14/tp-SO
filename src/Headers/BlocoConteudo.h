#ifndef BLOCOCONTEUDO_H
#define BLOCOCONTEUDO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int endereco;
    char *conteudo;
}BlocoConteudo;

/*typedef struct ListaBC *apontadorListaBC;
typedef struct ListaBC{
    apontadorListaBC proximo;
    BlocoConteudo blocoConteudo;
}ListaBlocoConteudo;*/

BlocoConteudo* criaBlocoConteudo(char *string, int endereco);

int getEnderecoBloco(BlocoConteudo *blocoConteudo);

char* getConteudoBloco(BlocoConteudo *blocoConteudo);

//ListaBlocoConteudo* criaListaBlocoConteudo(char *string, int endereco);

//void inserirConteudo(ListaBlocoConteudo *listaBlocoConteudo, char *string, int endereco);


#endif //BLOCOCONTEUDO_H