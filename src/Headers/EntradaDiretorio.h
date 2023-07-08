#ifndef ENTRADADIRETORIO_H
#define ENTRADADIRETORIO_H

#include "INodes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct ListaED *apontadorListaED;
typedef struct ListaED{
    apontadorListaED proximo;
    EntradaDiretorio entradaDiretorio;
}ListaEntradaDiretorio;

typedef enum{
	arquivo, diretorio
}EnumTipo;

typedef struct {
    EnumTipo tipo;
    int enderecoINode;
    char *nome;
    INodes iNodes;
    
}EntradaDiretorio;

EntradaDiretorio criaEntradaDiretorio(EnumTipo tipo, char *nome, int enderecoINode, int enderecoBloco);

ListaEntradaDiretorio* criaListaEntradaDiretorio(EnumTipo tipo, char *nome, int enderecoINode, int enderecoBloco);

void inserirEntradaDiretorio(ListaEntradaDiretorio *listaED, EnumTipo tipo, char *nome, int enderecoINode, int enderecoBloco);

void alteraNomeArquivo(EntradaDiretorio *entradaDiretorio, char *novoNomeArquivo);

void alteraNomeDiretorio(EntradaDiretorio *entradaDiretorio, char *novoNomeDiretorio);

void salvarINodes(EntradaDiretorio *entradaDiretorio, INodes iNodes);

int getEnderecoINode(EntradaDiretorio entradaDiretorio);

char* getNome(EntradaDiretorio entradaDiretorio);

EnumTipo getEnemTipo(EntradaDiretorio entradaDiretorio);

INodes getINodes(EntradaDiretorio entradaDiretorio);


#endif // ENTRADADIRETORIO_H