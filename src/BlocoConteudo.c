#include "Headers/BlocoConteudo.h"

BlocoConteudo criaBlocoConteudo(char *string, int endereco, int tamanhoBloco){
    BlocoConteudo blocoConteudo;
    blocoConteudo.endereco = endereco;
    blocoConteudo.conteudo = (char*)malloc(tamanhoBloco * sizeof(char));
    strcpy(blocoConteudo.conteudo, string);
    return blocoConteudo;
}

int getEndereco(BlocoConteudo blocoConteudo){
    return blocoConteudo.endereco;
}


char* getConteudoBloco(BlocoConteudo blocoConteudo){
    return blocoConteudo.conteudo;
}
