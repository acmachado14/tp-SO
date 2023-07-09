#include "Headers/SistemaArquivo.h"

InformacoesSA criaInformacoesSA(int tamanhoParticaoDisco, int tamanhoBloco);

InformacoesSA criaInformacoesSA(int tamanhoParticaoDisco, int tamanhoBloco){
    InformacoesSA informacoesSA;
    informacoesSA.tamanhoSistemaArquivo = tamanhoParticaoDisco * 1024 * 1024;
    informacoesSA.tamanhoBloco = tamanhoBloco;
    informacoesSA.quantidadeINode = (int)((informacoesSA.tamanhoSistemaArquivo / tamanhoBloco) / 100 * 2);
    informacoesSA.quantidadeBlocosConteudo = (informacoesSA.tamanhoSistemaArquivo / tamanhoBloco) - informacoesSA.quantidadeINode;
    informacoesSA.mapaBitBlocoConteudo = (int*)calloc(informacoesSA.quantidadeBlocosConteudo, sizeof(int));
    informacoesSA.mapaBitINode = (int*)calloc(informacoesSA.quantidadeINode, sizeof(int));
    return informacoesSA;
}

SistemaArquivo inicializaSistemaArquivo(int tamanhoParticaoDisco, int tamanhoBloco){
    SistemaArquivo sistemaArquivo;
    EnumTipo tipo = diretorio;
    sistemaArquivo.informacoesSA = criaInformacoesSA(tamanhoParticaoDisco, tamanhoBloco);
    int quantINode = sistemaArquivo.informacoesSA.quantidadeINode;
    sistemaArquivo.listaINode = (INode**)malloc(quantINode * sizeof(INode*));
    for(int i = 0; i < quantINode; i++){
        sistemaArquivo.listaINode[i] = NULL;
    }
    int enderecoINode = primeiraPossicaoComValor0(sistemaArquivo.informacoesSA.mapaBitINode, quantINode);
    modficaValorBit(sistemaArquivo.informacoesSA.mapaBitINode, enderecoINode, 1);
    sistemaArquivo.entradaDiretorio = criaEntradaDiretorio(tipo, "/", enderecoINode);
    EnumINode enumINode = entradaDiretorio;
    sistemaArquivo.listaINode[enderecoINode] = criaINodeDiretorio(enumINode);
    sistemaArquivo.navegacaoDiretorio = criaNavegacaoDiretorio(enderecoINode);
    return sistemaArquivo;
}

