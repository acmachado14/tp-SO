#include "src/Headers/SistemaArquivo.h"

//#include <unistd.h>

int main(int argc, char const *argv[]){
    printf("\n");
    printf("-------------------------------------------------------------------\n");
    /*->criar diretório 
     *->renomear diretório
     *->apagar diretório
     *->listar conteúdo do diretório
     *->criar arquivo
     *->renomear arquivo
     *->mover arquivo
     *->apagar arquivo
     *->listar conteúdo do arquivo.
    */

    SistemaArquivo SistemaArquivo;
    SistemaArquivo = inicializaSistemaArquivo(1, 1024);
    
    printf("-------------------------------------------------------------------\n");
    return 0;
}
