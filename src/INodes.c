#include "Headers/INodes.h"

INodes criaINodesArquivo(EnumINode enumINode, int enderecoBloco, char *string, int enderecoBlocoConteudo){
    INodes iNodes;
    iNodes.enderecoBloco = enderecoBloco;
    iNodes.enderecoBlocoAux = -1;
    iNodes.quantidadeArmazena = 1;
    iNodes.enumINode = enumINode;
    iNodes.atributos = criaAtributo();
    iNodes.armazena.listaBC = criaListaBlocoConteudo(string, enderecoBlocoConteudo);
    return iNodes;
}

INodes criaINodesDiretorio(EnumTipo tipo, EnumINode enumINode, int enderecoBlocoINode, char *nome, int enderecoINode, int enderecoBlocoDiretorio){
    INodes iNodes;
    iNodes.enderecoBloco = enderecoBlocoINode;
    iNodes.enderecoBlocoAux = -1;
    iNodes.quantidadeArmazena = 1;
    iNodes.enumINode = enumINode;
    iNodes.atributos = criaAtributo();
    iNodes.armazena.listaED = criaListaEntradaDiretorio(tipo, nome, enderecoINode, enderecoBlocoDiretorio);
    return iNodes;
}