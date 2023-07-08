#include "EnderecoBloco.h"
#include "INodes.h"

typedef enum{
	arquivo, diretorio
}Tipo;

typedef struct {
    Tipo tipo;
    union {
         struct{
            char nomeArquivo[28];
            EnderecoBloco enderecoBloco;
        }Arquivo;
        struct{
            char nomeDiretorio[28];
            INodes iNodes;
        }Diretorio;
    }unionEntradaDiretorio;
    
}EntradaDiretorio;
