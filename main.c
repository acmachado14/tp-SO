#include "src/Headers/SistemaArquivo.h"

//#include <unistd.h>

int main(int argc, char const *argv[]){
    printf("\n");
    printf("-------------------------------------------------------------------\n");
    int tamanhoBloco = 4096; // Em KB
    int tamanhoParticaoDisco = 10; // Em MB
    SistemaArquivo sistemaArquivo;
    sistemaArquivo = inicializaSistemaArquivo(tamanhoParticaoDisco, tamanhoBloco);
    bool parar = true;
    while (parar == false){
        int qualOpcao = 0;
        //SistemaArquivo *sistemaArquivo == (&sistemaArquivo)
        //Entrar em um diretorio
        //void entrarDiretorio(SistemaArquivo *sistemaArquivo, char *nomeDiretorio);

        //Sair de um Diretorio
        //void sairDiretorio(SistemaArquivo *sistemaArquivo);
        switch (qualOpcao) {
        case 1:
            //criar diretório
            //void criarDiretorio(SistemaArquivo *sistemaArquivo, char *nomeDiretorio);
            break;
        case 2:
            //renomear diretório
            //bool renomearDiretorio(SistemaArquivo *sistemaArquivo, char *novoNome, char *antigoNome);
            break;
        case 3:
            //apagar diretório
            //bool apagarDiretorio(SistemaArquivo *sistemaArquivo, char *nomeDiretorio);
            break;
        case 4:
            //listar conteúdo do diretório
            //char* listarConteudoDiretorio(SistemaArquivo *sistemaArquivo);
            break;
        case 5:
            //criar arquivo
            //ListaBlocoConteudo* criarArquivo(SistemaArquivo *sistemaArquivo, char *nomeArquico);
            //void inserirConteudoArquivo(SistemaArquivo *sistemaArquivo, ListaBlocoConteudo *listaBlocoConteudo, char *conteudo);
            break;
        case 6:
            //renomear arquivo
            //bool renomearArquivo(SistemaArquivo *sistemaArquivo, char *novoNome, char *antigoNome);
            break;
        case 7:
            //mover arquivo
            //ListaEntradaDiretorio* obterEntradaDiretorio(SistemaArquivo *sistemaArquivo, char *nomeArquivo);
            //void moverArquivo(SistemaArquivo *sistemaArquivo, ListaEntradaDiretorio *listaEntradaDiretorio);
            break;
        case 8:
            //apagar arquivo
            //bool apagarArquivo(SistemaArquivo *sistemaArquivo, char *nomeArquivo);
            break;
        case 9:
            // listar conteúdo do arquivo.
            //char* listarConteudoArquivo(SistemaArquivo *sistemaArquivo, char *nomeArquivo)
            break;
        default:
            parar = false;
            break;
    }
    }
    
    
    printf("-------------------------------------------------------------------\n");
    return 0;
}
