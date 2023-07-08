#ifndef BLOCOINDIRETO_H
#define BLOCOINDIRETO_H

#include <stdlib.h>
#include <stdio.h>
#include "EntradaDiretorio.h"
#include "BlocoConteudo.h"

typedef enum{
	entradaDiretorio, blocoConteudo
}EnumBlocoIndireto;

typedef struct {
    int enderecoBloco;
    EnumBlocoIndireto enumBlocoIndireto;
    union {
        EntradaDiretorio *entradaDiretorio;
        BlocoConteudo *blocoConteudo;
    }unionBlocoIndireto;
}BlocoIndireto;

BlocoIndireto criaBlocoIndireto(EnumBlocoIndireto enumBloco, int tanhoBloco, int enderecoBloco);

int getEnderecoBlocoIndireto(BlocoIndireto blocoIndireto);

#endif // BLOCOINDIRETO_H