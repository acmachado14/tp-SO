#include "src/Headers/SistemaArquivo.h"

//#include <unistd.h>

int main(int argc, char const *argv[]){
    printf("-------------------------------------------------------------------\n");
    /*SistemaArquivo SistemaArquivo;
    SistemaArquivo = criaSistemaArquivo("Teste01", 10, 3, 5);
    printf("QuantidadeBlocos: %d\n", getQuantidadeBlocos(SistemaArquivo));
    printf("QuantidadeINodes: %d\n", getQuantidadeINodes(SistemaArquivo));
    printf("DataCriacao: %s\n", getDataCriacao(SistemaArquivo.atributos));
    printf("DataUltimaModificacao: %s\n", getDataUltimaModificacao(SistemaArquivo.atributos));
    printf("DataUltimoAcesso: %s\n", getDataUltimoAcesso(SistemaArquivo.atributos));
    printf("EnderecoBloco: %d\n", getEndereco(SistemaArquivo.blocoConteudo));
    printf("Conteudo: %s\n", getConteudoBloco(SistemaArquivo.blocoConteudo));
    printf("-------------------------------------------------------------------\n");
    //sleep(2);
    setDataUltimaModificacao(&(SistemaArquivo.atributos));
    setDataUltimoAcesso(&(SistemaArquivo.atributos));
    printf("QuantidadeBlocos: %d\n", getQuantidadeBlocos(SistemaArquivo));
    printf("QuantidadeINodes: %d\n", getQuantidadeINodes(SistemaArquivo));
    printf("DataCriacao: %s\n", getDataCriacao(SistemaArquivo.atributos));
    printf("DataUltimaModificacao: %s\n", getDataUltimaModificacao(SistemaArquivo.atributos));
    printf("DataUltimoAcesso: %s\n", getDataUltimoAcesso(SistemaArquivo.atributos));
    printf("EnderecoBloco: %d\n", getEndereco(SistemaArquivo.blocoConteudo));
    printf("Conteudo: %s\n", getConteudoBloco(SistemaArquivo.blocoConteudo));*/
    
    SistemaArquivo SistemaArquivo;
    SistemaArquivo = inicializaSistemaArquivo(1, 1024);

    return 0;
}
