#ifndef INODES_H
#define INODES_H

#include "Atributos.h"
#include "Conteudo.h"
//#include "EntradaDiretorio.h"
#include "BlocoIndireto.h"
//#include "EnderecoBloco.h"

typedef enum{
	entradaDiretorio, blocoIndireto, enderecoBloco
}EnumINode;

typedef struct{
    EnumINode enumINode;
    union {
        EntradaDiretorio *entradaDiretorio;
        BlocoIndireto blocoIndireto;
        EnderecoBloco *enderecoBloco;
    }unionINode;
}INodeArmazena;

typedef struct {
    int enderecoINode;
    int enderecoBloco;
    Atributos *atributos;
    INodeArmazena armazena;
}INodes;



#endif //INODES_H