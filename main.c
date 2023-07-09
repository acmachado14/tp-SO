#include "src/Headers/SistemaArquivo.h"

//#include <unistd.h>

int main(int argc, char const *argv[]){
    printf("\n");
    printf("-------------------------------------------------------------------\n");
    SistemaArquivo SistemaArquivo;
    SistemaArquivo = inicializaSistemaArquivo(1, 1024);
    
    printf("-------------------------------------------------------------------\n");
    return 0;
}
