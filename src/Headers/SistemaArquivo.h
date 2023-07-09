#ifndef SISTEMAARQUIVO_H
#define SISTEMAARQUIVO_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "EntradaDiretorio.h"
#include "INode.h"

typedef struct{
    int *mapaBitBlocoConteudo;
    int *mapaBitINode;
    int quantidadeBlocosConteudo;
    int quantidadeINode;
    long long int tamanhoSistemaArquivo;
    int tamanhoBloco;
}InformacoesSA;

typedef struct{
    InformacoesSA informacoesSA;
    EntradaDiretorio entradaDiretorio;
    NavegacaoDiretorio *navegacaoDiretorio;
    INode **listaINode;
}SistemaArquivo;

SistemaArquivo inicializaSistemaArquivo(int tamanhoParticaoDisco, int tamanhoBloco);

void criarDiretorio(SistemaArquivo *sistemaArquivo, char *nomeDiretorio);

bool renomearDiretorio(SistemaArquivo *sistemaArquivo, char *novoNome, char *antigoNome);

bool apagarDiretorio(SistemaArquivo *sistemaArquivo, char *nomeDiretorio);

#endif //SISTEMAARQUIVO_H