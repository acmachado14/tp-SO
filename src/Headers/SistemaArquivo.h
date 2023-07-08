#include <stdlib.h>
#include <stdio.h>
#include "EntradaDiretorio.h"

typedef struct{
    int *mapaBit;
    int *tabelaINode;
    int quantidadeBlocos, quantidadeINodes;
    EntradaDiretorio *entradaDiretorio;
}SistemaArquivo;
