#include "Headers/EntradaDiretorio.h"


EntradaDiretorio criaEntradaDiretorio(EnumTipo tipo, char *nome, int enderecoINode, int enderecoBloco){
    EntradaDiretorio entradaDiretorio;
    entradaDiretorio.tipo = tipo;
    entradaDiretorio.enderecoINode = enderecoINode;
    entradaDiretorio.nome = (char*)malloc(28 * sizeof(char));
    strcpy(entradaDiretorio.nome, nome);
    //entradaDiretorio.iNodes = ;// Funçaõ a ser criada ainda
    return entradaDiretorio;
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

INodes getINodes(EntradaDiretorio entradaDiretorio){
    return entradaDiretorio.iNodes;
}

void salvarINodes(EntradaDiretorio *entradaDiretorio, INodes iNodes){
    entradaDiretorio->iNodes = iNodes;
}
