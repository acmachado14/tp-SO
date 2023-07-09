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
    if(listaED == NULL){
        listaED = criaListaEntradaDiretorio(tipo, nomeDiretorio, novoEnderecoINode);
    }
    else{
        inserirEntradaDiretorio(listaED, tipo, nomeDiretorio, novoEnderecoINode);
    }
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

char* listarConteudoDiretorio(SistemaArquivo *sistemaArquivo){
    int enderecoAtualINode;
    enderecoAtualINode = getUltimoEnderecoINodeNavegacaoDiretorio(sistemaArquivo->navegacaoDiretorio);
    ListaEntradaDiretorio *listaED;
    listaED = (sistemaArquivo->listaINode[enderecoAtualINode]->armazena.listaED);
    char *conteudoDiretorio;
    conteudoDiretorio = (char*)malloc(sizeof(char));
    while (listaED != NULL){
        strcpy(conteudoDiretorio, listaED->entradaDiretorio.nome); // Copia a primeira string para o resultado
        strcat(conteudoDiretorio, "\n"); // Adiciona o caractere de nova linha
        listaED = listaED->proximo;
    }
    return conteudoDiretorio;
}

ListaBlocoConteudo* criarArquivo(SistemaArquivo *sistemaArquivo, char *nomeArquico){
    int enderecoAtualINode, novoEnderecoINode, quantINode;
    quantINode = sistemaArquivo->informacoesSA.quantidadeINode;
    enderecoAtualINode = getUltimoEnderecoINodeNavegacaoDiretorio(sistemaArquivo->navegacaoDiretorio);
    novoEnderecoINode = primeiraPossicaoComValor0(sistemaArquivo->informacoesSA.mapaBitINode, quantINode);
    modficaValorBit(sistemaArquivo->informacoesSA.mapaBitINode, novoEnderecoINode, 1);
    EnumTipo tipo = arquivo;
    ListaEntradaDiretorio *listaED;
    listaED = (sistemaArquivo->listaINode[enderecoAtualINode]->armazena.listaED);
    if(listaED == NULL){
        listaED = criaListaEntradaDiretorio(tipo, nomeArquico, novoEnderecoINode);
    }
    else{
        inserirEntradaDiretorio(listaED, tipo, nomeArquico, novoEnderecoINode);
    }
    sistemaArquivo->listaINode[novoEnderecoINode] = criaINodeArquivo();
    setQuantidadeArmazena(sistemaArquivo->listaINode[novoEnderecoINode], getQuantidadeArmazena(sistemaArquivo->listaINode[novoEnderecoINode]) + 1);
    return sistemaArquivo->listaINode[novoEnderecoINode]->armazena.listaBC;
}

void inserirConteudoArquivo(SistemaArquivo *sistemaArquivo, ListaBlocoConteudo *listaBlocoConteudo, char *conteudo){
    int tamanhoParte = sistemaArquivo->informacoesSA.tamanhoBloco;
    int tamanhoOriginal = strlen(conteudo);

    int numPartes = tamanhoOriginal / tamanhoParte;
    if (tamanhoOriginal % tamanhoParte != 0) {
        numPartes++;
    }
    int i, j;
    char **partes = (char**)malloc(sizeof(char*));
    for(i = 0; i < numPartes; i++){
        partes[i] = (char*)malloc(sizeof(char));
    }
    for (i = 0, j = 0; i < numPartes; i++, j += tamanhoParte) {
        strncpy(partes[i], conteudo + j, tamanhoParte);
        partes[i][tamanhoParte] = '\0'; // Adiciona o caractere nulo terminador
    }

    int enderecoBloco, quantBlocos;

    enderecoBloco = primeiraPossicaoComValor0(sistemaArquivo->informacoesSA.mapaBitBlocoConteudo, quantBlocos);
    modficaValorBit(sistemaArquivo->informacoesSA.mapaBitBlocoConteudo, enderecoBloco, 1);
    listaBlocoConteudo = criaListaBlocoConteudo(partes[0], enderecoBloco);
    for(i = 1; i < numPartes; i++){
        enderecoBloco = primeiraPossicaoComValor0(sistemaArquivo->informacoesSA.mapaBitBlocoConteudo, quantBlocos);
        modficaValorBit(sistemaArquivo->informacoesSA.mapaBitBlocoConteudo, enderecoBloco, 1);
        inserirConteudo(listaBlocoConteudo, partes[0], enderecoBloco);
    }
}

bool renomearArquivo(SistemaArquivo *sistemaArquivo, char *novoNome, char *antigoNome){
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

ListaEntradaDiretorio* obterEntradaDiretorio(SistemaArquivo *sistemaArquivo, char *nomeArquivo){
    int enderecoAtualINode;
    enderecoAtualINode = getUltimoEnderecoINodeNavegacaoDiretorio(sistemaArquivo->navegacaoDiretorio);
    ListaEntradaDiretorio *listaED;
    listaED = (sistemaArquivo->listaINode[enderecoAtualINode]->armazena.listaED);
    apontadorListaED aux;
    while (listaED != NULL){
        if(comparaString(listaED->entradaDiretorio.nome, nomeArquivo) == 0){
            int enderecoINodeDiretorio;
            enderecoINodeDiretorio = getEnderecoINode(listaED->entradaDiretorio);
            setQuantidadeArmazena(sistemaArquivo->listaINode[enderecoAtualINode], getQuantidadeArmazena(sistemaArquivo->listaINode[enderecoAtualINode]) - 1);
            modficaValorBit(sistemaArquivo->informacoesSA.mapaBitINode, enderecoINodeDiretorio, 0);
            aux->proximo = listaED->proximo;
            free(sistemaArquivo->listaINode[enderecoINodeDiretorio]);
            sistemaArquivo->listaINode[enderecoINodeDiretorio] = NULL;
            return listaED;
        }
        aux = listaED;
        listaED = listaED->proximo;
    }
    return NULL;
}

void moverArquivo(SistemaArquivo *sistemaArquivo, ListaEntradaDiretorio *listaEntradaDiretorio){
    int enderecoAtualINode;
    enderecoAtualINode = getUltimoEnderecoINodeNavegacaoDiretorio(sistemaArquivo->navegacaoDiretorio);
    ListaEntradaDiretorio *listaED;
    listaED = (sistemaArquivo->listaINode[enderecoAtualINode]->armazena.listaED);
    while (listaED != NULL){
        listaED = listaED->proximo;
    }
    listaED = (apontadorListaED)malloc(sizeof(ListaEntradaDiretorio));
    listaED = listaEntradaDiretorio;
    listaED->proximo = NULL;
}

bool apagarArquivo(SistemaArquivo *sistemaArquivo, char *nomeArquivo){
    int enderecoAtualINode;
    enderecoAtualINode = getUltimoEnderecoINodeNavegacaoDiretorio(sistemaArquivo->navegacaoDiretorio);
    ListaEntradaDiretorio *listaED;
    listaED = (sistemaArquivo->listaINode[enderecoAtualINode]->armazena.listaED);
    apontadorListaED aux;
    while (listaED != NULL){
        if(comparaString(listaED->entradaDiretorio.nome, nomeArquivo) == 0){
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

char* listarConteudoArquivo(SistemaArquivo *sistemaArquivo, char *nomeArquivo){
    int enderecoAtualINode;
    enderecoAtualINode = getUltimoEnderecoINodeNavegacaoDiretorio(sistemaArquivo->navegacaoDiretorio);
    ListaEntradaDiretorio *listaED;
    listaED = (sistemaArquivo->listaINode[enderecoAtualINode]->armazena.listaED);
    char *conteudoArquivo;
    conteudoArquivo = (char*)malloc(sizeof(char));
    int enderecoArquivo; 
    while (listaED != NULL){
        if(comparaString(listaED->entradaDiretorio.nome, nomeArquivo) == 0){
            enderecoArquivo = listaED->entradaDiretorio.enderecoINode;
            break;
        }
        listaED = listaED->proximo;
    }
    ListaBlocoConteudo *listaBC;
    listaBC = sistemaArquivo->listaINode[enderecoArquivo]->armazena.listaBC;
    while (listaBC != NULL){
        strcpy(conteudoArquivo, listaBC->blocoConteudo.conteudo);
        listaBC = listaBC->proximo;
    }
    return conteudoArquivo;
}

void entrarDiretorio(SistemaArquivo *sistemaArquivo, char *nomeDiretorio){
    int enderecoAtualINode, enderecoDiretorio;
    enderecoAtualINode = getUltimoEnderecoINodeNavegacaoDiretorio(sistemaArquivo->navegacaoDiretorio);
    ListaEntradaDiretorio *listaED;
    listaED = (sistemaArquivo->listaINode[enderecoAtualINode]->armazena.listaED);
    while (listaED != NULL){
        if(comparaString(listaED->entradaDiretorio.nome, nomeDiretorio) == 0){
            enderecoDiretorio = listaED->entradaDiretorio.enderecoINode;
            adicionaEnderecoINodeNavegacaoDiretorio(sistemaArquivo->navegacaoDiretorio, enderecoDiretorio);
            break;
        }
        listaED = listaED->proximo;
    }
}

void sairDiretorio(SistemaArquivo *sistemaArquivo){
    apagarEnderecoINodeNavegacaoDiretorio(sistemaArquivo->navegacaoDiretorio);
}

