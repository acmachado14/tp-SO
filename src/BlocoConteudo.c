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

ListaBlocoConteudo* criaListaBlocoConteudo(char *string, int endereco, int tamanhoBloco){
    ListaBlocoConteudo *listaBlocoConteudo;
    listaBlocoConteudo->proximo = NULL;
    listaBlocoConteudo->blocoConteudo = criaBlocoConteudo(string, endereco, tamanhoBloco);
    return listaBlocoConteudo;
}

void inserirConteudo(ListaBlocoConteudo *listaBloco, char *string, int endereco, int tamanhoBloco){
    apontadorListaBC aux;
    aux = listaBloco->proximo;
    while (aux != NULL){
        aux = aux->proximo;
    }
    aux = (apontadorListaBC)malloc(sizeof(ListaBlocoConteudo));
    aux->proximo = NULL;
    aux->blocoConteudo = criaBlocoConteudo(string, endereco, tamanhoBloco);
    //aux = criaListaBlocoConteudo(string, endereco, tamanhoBloco);
}