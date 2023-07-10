#include "Headers/BlocoConteudo.h"

BlocoConteudo* criaBlocoConteudo(char *string, int endereco){
    BlocoConteudo *blocoConteudo;
    blocoConteudo = (BlocoConteudo*)malloc(sizeof(BlocoConteudo));
    blocoConteudo->endereco = endereco;
    blocoConteudo->conteudo = (char*)malloc(strlen(string) * sizeof(char));
    strcpy(blocoConteudo->conteudo, string);
    return blocoConteudo;
}

int getEnderecoBloco(BlocoConteudo *blocoConteudo){
    return blocoConteudo->endereco;
}


char* getConteudoBloco(BlocoConteudo *blocoConteudo){
    return blocoConteudo->conteudo;
}

