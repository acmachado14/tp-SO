#ifndef ENTRADADIRETORIO_H
#define ENTRADADIRETORIO_H

#include "INodes.h"

typedef enum{
	arquivo, diretorio
}Tipo;

typedef struct {
    Tipo tipo;
    union {
         struct{
            int enderecoINode;
            char nomeArquivo[28];
            INodes iNodes;
        }Arquivo;
        struct{
            int enderecoINode;
            char nomeDiretorio[28];
            INodes iNodes;
        }Diretorio;
    }unionEntradaDiretorio;
    
}EntradaDiretorio;



#endif // ENTRADADIRETORIO_H