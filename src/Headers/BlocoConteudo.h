#ifndef BLOCOCONTEUDO_H
#define BLOCOCONTEUDO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int endereco;
    char *conteudo;
}BlocoConteudo;

BlocoConteudo criaBlocoConteudo(char *string, int endereco, int tamanhoBloco);

int getEndereco(BlocoConteudo blocoConteudo);



#endif //BLOCOCONTEUDO_H