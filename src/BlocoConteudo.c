#include "Headers/BlocoConteudo.h"

BlocoConteudo criaBlocoConteudo(char *string, int endereco){
    BlocoConteudo blocoConteudo;
    blocoConteudo.endereco = endereco;
    blocoConteudo.conteudo = (char*)malloc(strlen(string) * sizeof(char));
    strcpy(blocoConteudo.conteudo, string);
    return blocoConteudo;
}

int getEnderecoBloco(BlocoConteudo blocoConteudo){
    return blocoConteudo.endereco;
}


char* getConteudoBloco(BlocoConteudo blocoConteudo){
    return blocoConteudo.conteudo;
}

ListaBlocoConteudo* criaListaBlocoConteudo(char *string, int endereco){
    ListaBlocoConteudo *listaBlocoConteudo;
    listaBlocoConteudo->proximo = NULL;
    listaBlocoConteudo->blocoConteudo = criaBlocoConteudo(string, endereco);
    return listaBlocoConteudo;
}

void inserirConteudo(ListaBlocoConteudo *listaBloco, char *string, int endereco){
    apontadorListaBC aux;
    aux = listaBloco;
    while (aux != NULL){
        aux = aux->proximo;
    }
    aux = (apontadorListaBC)malloc(sizeof(ListaBlocoConteudo));
    aux->proximo = NULL;
    aux->blocoConteudo = criaBlocoConteudo(string, endereco);
    //aux = criaListaBlocoConteudo(string, endereco);
}