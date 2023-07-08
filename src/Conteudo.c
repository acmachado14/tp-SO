#include "Headers/Conteudo.h"


Conteudo* criaConteudo(){
    Conteudo *conteudo;
    conteudo = (Conteudo*)malloc(sizeof(Conteudo));
    return conteudo;
}

void inserirConteudo(Conteudo *conteudo, char *string){
    int tamanhoBloco = strlen(string);
    conteudo->conteudo = (char*)malloc(tamanhoBloco * sizeof(char));
    strcpy(conteudo->conteudo, string);
}

char* getConteudo(Conteudo *conteudo){
    return conteudo->conteudo;
}
