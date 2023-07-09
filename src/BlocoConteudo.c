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

/*ListaBlocoConteudo* criaListaBlocoConteudo(char *string, int endereco){
    printf("%s\n", string);
    ListaBlocoConteudo *listaBC;
    printf("---------->1\n");
    listaBC = (ListaBlocoConteudo*)malloc(sizeof(ListaBlocoConteudo));
    printf("---------->2\n");
    listaBC->proximo = NULL;
    printf("---------->3\n");
    listaBC->blocoConteudo = criaBlocoConteudo(string, endereco);
    printf("---------->4\n");
    return listaBC;
}*/

/*void inserirConteudo(ListaBlocoConteudo *listaBloco, char *string, int endereco){
    apontadorListaBC aux;
    aux = listaBloco;
    while (aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->proximo = (apontadorListaBC)malloc(sizeof(ListaBlocoConteudo));
    aux = aux->proximo;
    aux->proximo = NULL;
    aux->blocoConteudo = criaBlocoConteudo(string, endereco);
    //aux = criaListaBlocoConteudo(string, endereco);
}*/