#ifndef ENDERECOBLOCO_H
#define ENDERECOBLOCO_H

#include <stdlib.h>
#include <stdio.h>
#include "Conteudo.h"

typedef struct {
    int endereco;
    Conteudo *conteudo;
}EnderecoBloco;

EnderecoBloco* criaEnderecoBloco();

void inserirEnderecoBloco(EnderecoBloco *enderecoBloco, char *string, int endereco);

int getEndereco(EnderecoBloco *enderecoBloco);



#endif //ENDERECOBLOCO_H