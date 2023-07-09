#include "Headers/SistemaArquivo.h"

InformacoesSA criaInformacoesSA(int tamanhoParticaoDisco, int tamanhoBloco);

InformacoesSA criaInformacoesSA(int tamanhoParticaoDisco, int tamanhoBloco){
    InformacoesSA informacoesSA;
    informacoesSA.tamanhoSistemaArquivo = tamanhoParticaoDisco * 1024 * 1024;
    informacoesSA.tamanhoBloco = tamanhoBloco;
    informacoesSA.quantidadeINodes = (int)((informacoesSA.tamanhoSistemaArquivo / tamanhoBloco) / 100 * 2);
    informacoesSA.quantidadeBlocosConteudo = (informacoesSA.tamanhoSistemaArquivo / tamanhoBloco) - informacoesSA.quantidadeINodes;
    informacoesSA.mapaBitBlocoConteudo = (int*)calloc(informacoesSA.quantidadeBlocosConteudo, sizeof(int));
    informacoesSA.mapaBitINode = (int*)calloc(informacoesSA.quantidadeINodes, sizeof(int));
    return informacoesSA;
}

SistemaArquivo inicializaSistemaArquivo(int tamanhoParticaoDisco, int tamanhoBloco){
    SistemaArquivo sistemaArquivo;
    EnumTipo tipo = diretorio;
    sistemaArquivo.informacoesSA = criaInformacoesSA(tamanhoParticaoDisco, tamanhoBloco);
    int enderecoINode = primeiraPossicaoComValor0(sistemaArquivo.informacoesSA.mapaBitINode, sistemaArquivo.informacoesSA.quantidadeINodes);
    modficaValorBit(sistemaArquivo.informacoesSA.mapaBitINode, enderecoINode, 1);
    sistemaArquivo.entradaDiretorio = criaEntradaDiretorio(tipo, "/", enderecoINode);
    return sistemaArquivo;
}

