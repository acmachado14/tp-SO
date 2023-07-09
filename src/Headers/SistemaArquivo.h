#ifndef SISTEMAARQUIVO_H
#define SISTEMAARQUIVO_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "EntradaDiretorio.h"

typedef struct{
    int *mapaBitBlocoConteudo;
    int *mapaBitINode;
    int quantidadeBlocosConteudo;
    int quantidadeINodes;
    long long int tamanhoSistemaArquivo;
    int tamanhoBloco;
}InformacoesSA;

typedef struct{
    InformacoesSA informacoesSA;
    EntradaDiretorio entradaDiretorio;
}SistemaArquivo;

SistemaArquivo inicializaSistemaArquivo(int tamanhoParticaoDisco, int tamanhoBloco);


#endif //SISTEMAARQUIVO_H