#ifndef INODES_H
#define INODES_H

#include "Atributos.h"
#include "EntradaDiretorio.h"
#include "BlocoIndireto.h"
#include "BlocoConteudo.h"

typedef enum{
	entradaDiretorio, blocoIndireto, blocoConteudo
}EnumINode;

typedef struct{
    EnumINode enumINode;
    union {
        EntradaDiretorio entradaDiretorio;
        BlocoConteudo blocoConteudo;
        BlocoIndireto blocoIndireto;
    }unionINode;
}INodeArmazena;

typedef struct {
    int enderecoBloco;
    Atributos *atributos;
    INodeArmazena *armazena;
}INodes;



#endif //INODES_H