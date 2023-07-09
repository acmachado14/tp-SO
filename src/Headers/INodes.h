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

#endif //INODES_H