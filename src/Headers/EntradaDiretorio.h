#ifndef ENTRADADIRETORIO_H
#define ENTRADADIRETORIO_H

//#include "INodes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum{
	arquivo, diretorio
}EnumTipo;

typedef struct {
    EnumTipo tipo;
    int enderecoINode;
    char *nome;
}EntradaDiretorio;

typedef struct ListaED *apontadorListaED;
typedef struct ListaED{
    apontadorListaED proximo;
    EntradaDiretorio entradaDiretorio;
}ListaEntradaDiretorio;


EntradaDiretorio criaEntradaDiretorio(EnumTipo tipo, char *nome, int enderecoINode);

ListaEntradaDiretorio* criaListaEntradaDiretorio(EnumTipo tipo, char *nome, int enderecoINode);

void inserirEntradaDiretorio(ListaEntradaDiretorio *listaED, EnumTipo tipo, char *nome, int enderecoINode);

void alteraNomeArquivo(EntradaDiretorio *entradaDiretorio, char *novoNomeArquivo);

void alteraNomeDiretorio(EntradaDiretorio *entradaDiretorio, char *novoNomeDiretorio);

int getEnderecoINode(EntradaDiretorio entradaDiretorio);

char* getNome(EntradaDiretorio entradaDiretorio);

EnumTipo getEnemTipo(EntradaDiretorio entradaDiretorio);


#endif // ENTRADADIRETORIO_H