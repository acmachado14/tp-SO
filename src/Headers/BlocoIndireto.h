#ifndef BLOCOINDIRETO_H
#define BLOCOINDIRETO_H

#include <stdlib.h>
#include <stdio.h>
#include "EntradaDiretorio.h"
#include "EnderecoBloco.h"

typedef enum{
	entradaDiretorio, enderecoBloco
}EnumBlocoIndireto;

typedef struct {
    int enderecoBloco;
    EnumBlocoIndireto enumBlocoIndireto;
    union {
        EntradaDiretorio *entradaDiretorio;
        EnderecoBloco *enderecoBloco;
    }unionBlocoIndireto;
}BlocoIndireto;



#endif // BLOCOINDIRETO_H