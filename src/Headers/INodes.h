#ifndef INODES_H
#define INODES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Atributos.h"
#include "EntradaDiretorio.h"
#include "BlocoConteudo.h"

typedef enum{
	entradaDiretorio, blocoConteudo
}EnumINode;

typedef struct {
    int enderecoBloco;
    int enderecoBlocoAux;
    int quantidadeArmazena;
    EnumINode enumINode;
    Atributos atributos;
    union {
        ListaBlocoConteudo *listaBC;
        ListaEntradaDiretorio *listaED;
    }armazena;
}INodes;

INodes criaINodesArquivo(EnumINode enumINode, int enderecoBloco, char *string, int enderecoBlocoConteudo);

INodes criaINodesDiretorio(EnumTipo tipo, EnumINode enumINode, int enderecoBlocoINode, char *nome, int enderecoINode, int enderecoBlocoDiretorio);

int primeiraPossicaoComValor0(int *vetor, int tamanho);

void modficaValorBit(int *vetor, int posicao, int novoValor);

#endif //INODES_H