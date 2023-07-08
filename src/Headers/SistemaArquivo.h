#ifndef SISTEMAARQUIVO_H
#define SISTEMAARQUIVO_H

#include <stdlib.h>
#include <stdio.h>
#include "EntradaDiretorio.h"

typedef struct{
    int *mapaBit;
    int *tabelaINode;
    int quantidadeBlocos, quantidadeINodes;
    EntradaDiretorio *entradaDiretorio;
}SistemaArquivo;



#endif //SISTEMAARQUIVO_H