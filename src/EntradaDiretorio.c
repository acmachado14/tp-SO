#include "Headers/EntradaDiretorio.h"


EntradaDiretorio criaEntradaDiretorio(EnumTipo tipo, char *nome, int enderecoINode){
    EntradaDiretorio entradaDiretorio;
    entradaDiretorio.tipo = tipo;
    entradaDiretorio.enderecoINode = enderecoINode;
    entradaDiretorio.nome = (char*)malloc(28 * sizeof(char));
    strcpy(entradaDiretorio.nome, nome);
    return entradaDiretorio;
}

ListaEntradaDiretorio* criaListaEntradaDiretorio(EnumTipo tipo, char *nome, int enderecoINode){
    ListaEntradaDiretorio *listaED;
    listaED = (ListaEntradaDiretorio*)malloc(sizeof(ListaEntradaDiretorio));
    listaED->proximo = NULL;
    listaED->entradaDiretorio = criaEntradaDiretorio(tipo, nome, enderecoINode);
    return listaED;
}

void inserirEntradaDiretorio(ListaEntradaDiretorio **listaED, EnumTipo tipo, char *nome, int enderecoINode){
    apontadorListaED aux;
    aux = *listaED;
    while (aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->proximo = (apontadorListaED)malloc(sizeof(ListaEntradaDiretorio));
    aux = aux->proximo;
    aux->proximo = NULL;
    aux->entradaDiretorio = criaEntradaDiretorio(tipo, nome, enderecoINode);
}

void alteraNomeArquivo(EntradaDiretorio *entradaDiretorio, char *novoNomeArquivo){
    strcpy(entradaDiretorio->nome, novoNomeArquivo);
}

void alteraNomeDiretorio(EntradaDiretorio *entradaDiretorio, char *novoNomeDiretorio){
    strcpy(entradaDiretorio->nome, novoNomeDiretorio);
}

int getEnderecoINode(EntradaDiretorio entradaDiretorio){
    return entradaDiretorio.enderecoINode;
}

char* getNome(EntradaDiretorio *entradaDiretorio){
    printf("--0000----\n");
    printf("%s\n", entradaDiretorio->nome);
    return entradaDiretorio->nome;
}

EnumTipo getEnemTipo(EntradaDiretorio entradaDiretorio){
    return entradaDiretorio.tipo;
}

