#ifndef LEITURAITERATIVA_H
#define LEITURAITERATIVA_H

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

void criarArquivoIterativo(char *nomeArquivo,bool sucesso, Log *log);

void deletarArquivoIterativo(char *nomeArquivo, bool sucesso, Log *log);

void listarConteudoArquivoIterativo(char *arquivo, Log *log);

void criarDiretorioIterativo(char *nomeDiretorio, Log *log);

void renomearDiretorioIterativo(char *nomeDiretorio, char *novoNomeDiretorio, Log *log);

void apagarDiretorioIterativo(char *nomeDiretorio, bool sucesso, Log *log);

void renomearArquivoIterativo(char *nomeArquivo, char *novoNomeArquivo, bool sucesso, Log *log);

void moverArquivoIterativo(char *nomeArquivo, Log *log);

void listarConteudoDiretorioIterativo(char *diretorio, Log *log);

Log * leituraIterativa(SistemaArquivo *sistemaArquivo);

#endif