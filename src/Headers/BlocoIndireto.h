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



#endif // BLOCOINDIRETO_H