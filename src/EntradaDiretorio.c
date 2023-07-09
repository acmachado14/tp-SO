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
    listaED->proximo = NULL;
    listaED->entradaDiretorio = criaEntradaDiretorio(tipo, nome, enderecoINode);
    return listaED;
}

void inserirEntradaDiretorio(ListaEntradaDiretorio *listaED, EnumTipo tipo, char *nome, int enderecoINode){
    apontadorListaED aux;
    aux = listaED;
    while (aux != NULL){
        aux = aux->proximo;
    }
    aux = (apontadorListaED)malloc(sizeof(ListaEntradaDiretorio));
    aux->proximo = NULL;
    aux->entradaDiretorio = criaEntradaDiretorio(tipo, nome, enderecoINode);
    //aux = criaListaEntradaDiretorio(tipo, nome, enderecoINode);
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

char* getNome(EntradaDiretorio entradaDiretorio){
    return entradaDiretorio.nome;
}

EnumTipo getEnemTipo(EntradaDiretorio entradaDiretorio){
    return entradaDiretorio.tipo;
}

/*INodes getINodes(EntradaDiretorio entradaDiretorio){
    return entradaDiretorio.iNodes;
}

void salvarINodes(EntradaDiretorio *entradaDiretorio, INodes iNodes){
    entradaDiretorio->iNodes = iNodes;
}*/
