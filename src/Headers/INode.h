#ifndef INODE_H
#define INODE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Atributos.h"
#include "EntradaDiretorio.h"
#include "BlocoConteudo.h"

typedef struct navegDire *apontadorNavegacaoDiretorio;
typedef struct navegDire{
    int enderecoINodeAtual;
    apontadorNavegacaoDiretorio proximo;
}NavegacaoDiretorio;

typedef enum{
	entradaDiretorio, blocoConteudo
}EnumINode;

typedef struct {
    int enderecoBlocoAux;
    int quantidadeArmazena;
    EnumINode enumINode;
    Atributos atributos;
    BlocoConteudo *blocoConteudo;
    ListaEntradaDiretorio *listaED;
}INode;

INode* criaINodeArquivo();

INode* criaINodeDiretorio();

int primeiraPossicaoComValor0(int *vetor, int tamanho);

void modficaValorBit(int *vetor, int posicao, int novoValor);

NavegacaoDiretorio* criaNavegacaoDiretorio(int enderecoINode);

void adicionaEnderecoINodeNavegacaoDiretorio(NavegacaoDiretorio *navegacaoDiretorio, int enderecoINode);

void apagarEnderecoINodeNavegacaoDiretorio(NavegacaoDiretorio *navegacaoDiretorio);

int getUltimoEnderecoINodeNavegacaoDiretorio(NavegacaoDiretorio *navegacaoDiretorio);

void setQuantidadeArmazena(INode *iNode, int novoValor);

int getQuantidadeArmazena(INode *iNode);

#endif //INODE_H