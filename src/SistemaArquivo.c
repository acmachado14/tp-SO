#include "Headers/SistemaArquivo.h"

InformacoesSA criaInformacoesSA(int tamanhoParticaoDisco, int tamanhoBloco);

int comparaString(char *str1, char *str2);

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
    sistemaArquivo.listaINode[enderecoINode] = criaINodeDiretorio();
    sistemaArquivo.navegacaoDiretorio = criaNavegacaoDiretorio(enderecoINode);
    return sistemaArquivo;
}

int comparaString(char *str1, char *str2){
    return strcmp(str1, str2);
}


void criarDiretorio(SistemaArquivo *sistemaArquivo, char *nomeDiretorio){
    int enderecoAtualINode, novoEnderecoINode, quantINode;
    quantINode = sistemaArquivo->informacoesSA.quantidadeINode;
    enderecoAtualINode = getUltimoEnderecoINodeNavegacaoDiretorio(sistemaArquivo->navegacaoDiretorio);
    novoEnderecoINode = primeiraPossicaoComValor0(sistemaArquivo->informacoesSA.mapaBitINode, quantINode);
    modficaValorBit(sistemaArquivo->informacoesSA.mapaBitINode, novoEnderecoINode, 1);
    EnumTipo tipo = diretorio;
    ListaEntradaDiretorio *listaED;
    listaED = (sistemaArquivo->listaINode[enderecoAtualINode]->armazena.listaED);
    inserirEntradaDiretorio(listaED, tipo, nomeDiretorio, novoEnderecoINode);
    sistemaArquivo->listaINode[novoEnderecoINode] = criaINodeDiretorio();
    setQuantidadeArmazena(sistemaArquivo->listaINode[novoEnderecoINode], getQuantidadeArmazena(sistemaArquivo->listaINode[novoEnderecoINode]) + 1);

}

bool renomearDiretorio(SistemaArquivo *sistemaArquivo, char *novoNome, char *antigoNome){
    int enderecoAtualINode;
    enderecoAtualINode = getUltimoEnderecoINodeNavegacaoDiretorio(sistemaArquivo->navegacaoDiretorio);
    ListaEntradaDiretorio *listaED;
    listaED = (sistemaArquivo->listaINode[enderecoAtualINode]->armazena.listaED);

    while (listaED != NULL){
        if(comparaString(listaED->entradaDiretorio.nome, antigoNome) == 0){
            alteraNomeDiretorio(&(listaED->entradaDiretorio), novoNome);
            return true;
        }
        listaED = listaED->proximo;
    }
    return false;
}

bool apagarDiretorio(SistemaArquivo *sistemaArquivo, char *nomeDiretorio){
    int enderecoAtualINode;
    enderecoAtualINode = getUltimoEnderecoINodeNavegacaoDiretorio(sistemaArquivo->navegacaoDiretorio);
    ListaEntradaDiretorio *listaED;
    listaED = (sistemaArquivo->listaINode[enderecoAtualINode]->armazena.listaED);
    apontadorListaED aux;
    while (listaED != NULL){
        if(comparaString(listaED->entradaDiretorio.nome, nomeDiretorio) == 0){
            int enderecoINodeDiretorio;
            enderecoINodeDiretorio = getEnderecoINode(listaED->entradaDiretorio);
            setQuantidadeArmazena(sistemaArquivo->listaINode[enderecoAtualINode], getQuantidadeArmazena(sistemaArquivo->listaINode[enderecoAtualINode]) - 1);
            modficaValorBit(sistemaArquivo->informacoesSA.mapaBitINode, enderecoINodeDiretorio, 0);
            aux->proximo = listaED->proximo;
            free(sistemaArquivo->listaINode[enderecoINodeDiretorio]);
            sistemaArquivo->listaINode[enderecoINodeDiretorio] = NULL;
            free(listaED);
            return true;
        }
        aux = listaED;
        listaED = listaED->proximo;
    }
    return false;
}

