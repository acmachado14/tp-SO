#include "Headers/INode.h"

INode* criaINodeArquivo(EnumINode enumINode){
    INode *iNode;
    iNode->enderecoBlocoAux = -1;
    iNode->quantidadeArmazena = 0;
    iNode->enumINode = enumINode;
    iNode->atributos = criaAtributo();
    iNode->armazena.listaBC = NULL;
    return iNode;
}

INode* criaINodeDiretorio(EnumINode enumINode){
    INode *iNode;
    iNode->enderecoBlocoAux = -1;
    iNode->quantidadeArmazena = 0;
    iNode->enumINode = enumINode;
    iNode->atributos = criaAtributo();
    iNode->armazena.listaED = NULL;
    return iNode;
}

int primeiraPossicaoComValor0(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(vetor[i] == 0){
            return i;
        }
    }
    return -1;
}

void modficaValorBit(int *vetor, int posicao, int novoValor){
    vetor[posicao] = novoValor;
}

NavegacaoDiretorio* criaNavegacaoDiretorio(int enderecoINode){
    NavegacaoDiretorio *navegacaoDiretorio;
    navegacaoDiretorio->enderecoINodeAtual = enderecoINode;
    navegacaoDiretorio->proximo = NULL;
    return navegacaoDiretorio;
}

void adicionaEnderecoINodeNavegacaoDiretorio(NavegacaoDiretorio *navegacaoDiretorio, int enderecoINode){
    apontadorNavegacaoDiretorio aux;
    aux = navegacaoDiretorio;
    while (aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux = (apontadorNavegacaoDiretorio)malloc(sizeof(NavegacaoDiretorio));
    aux->proximo = NULL;
    aux->enderecoINodeAtual = enderecoINode;
}
