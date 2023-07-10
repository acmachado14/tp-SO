#include "SistemaArquivo.h"

typedef struct {
    char **mensagens;
    int tamanho;
    int capacidade;
} Log;

Log* criarLog();
void adicionarMensagem(Log *log, const char *mensagem);
void imprimirLog(Log *log);
void liberarLog(Log *log);

void criarArquivo(char *nomeArquivo, Log *log);
void deletarArquivo(char *nomeArquivo, bool sucesso, Log *log);
void listarConteudoArquivo(char *arquivo, Log *log);
void criarDiretorio(char *nomeDiretorio, Log *log);
void renomearDiretorio(char *nomeDiretorio, char *novoNomeDiretorio, Log *log);
void apagarDiretorio(char *nomeDiretorio, bool sucesso, Log *log);
void renomearArquivo(char *nomeArquivo, char *novoNomeArquivo, bool sucesso, Log *log);
void moverArquivo(char *nomeArquivo, char *diretorioAtual, char *novoDiretorio, Log *log);
void listarConteudoDiretorio(char *diretorio, Log *log);

Log * leituraIterativa(SistemaArquivo *sistemaArquivo);