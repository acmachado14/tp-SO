#ifndef BLOCOCONTEUDO_H
#define BLOCOCONTEUDO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct bloco* apontadorBlocoConteudo;
typedef struct bloco{
    int endereco;
    char *conteudo;
}BlocoConteudo;


BlocoConteudo* criaBlocoConteudo(char *string, int endereco);

int getEnderecoBloco(BlocoConteudo *blocoConteudo);

char* getConteudoBloco(BlocoConteudo *blocoConteudo);


#endif //BLOCOCONTEUDO_H