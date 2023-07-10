#ifndef SISTEMAARQUIVO_H
#define SISTEMAARQUIVO_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "EntradaDiretorio.h"
#include "INode.h"
#include "BlocoConteudo.h"

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

char* listarConteudoDiretorio(SistemaArquivo *sistemaArquivo);

BlocoConteudo** criarArquivo(SistemaArquivo *sistemaArquivo, char *nomeArquico);

void inserirConteudoArquivo(SistemaArquivo *sistemaArquivo, BlocoConteudo **blocoConteudo, char *conteudo);

bool renomearArquivo(SistemaArquivo *sistemaArquivo, char *novoNome, char *antigoNome);

ListaEntradaDiretorio* obterEntradaDiretorio(SistemaArquivo *sistemaArquivo, char *nomeArquivo);

void moverArquivo(SistemaArquivo *sistemaArquivo, ListaEntradaDiretorio *listaEntradaDiretorio);

bool apagarArquivo(SistemaArquivo *sistemaArquivo, char *nomeArquivo);

char* listarConteudoArquivo(SistemaArquivo *sistemaArquivo, char *nomeArquivo);

void entrarDiretorio(SistemaArquivo *sistemaArquivo, char *nomeDiretorio);

void sairDiretorio(SistemaArquivo *sistemaArquivo);


#endif //SISTEMAARQUIVO_H