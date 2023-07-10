#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/LeituraIterativa.h"
#include "Headers/SistemaArquivo.h"

#define TAMANHO_MAX_MENSAGEM 10000

#define CAPACIDADE_INICIAL 10


Log* criarLog() {
    Log *log = (Log*)malloc(sizeof(Log));
    log->tamanho = 0;
    log->capacidade = CAPACIDADE_INICIAL;
    log->mensagens = (char**)malloc(CAPACIDADE_INICIAL * sizeof(char*));

    return log;
}

void adicionarMensagem(Log *log, const char *mensagem) {
    if (log->tamanho == log->capacidade) {
        log->capacidade *= 2;
        log->mensagens = (char**)realloc(log->mensagens, log->capacidade * sizeof(char*));
    }

    log->mensagens[log->tamanho] = (char*)malloc((TAMANHO_MAX_MENSAGEM + 1) * sizeof(char));
    strncpy(log->mensagens[log->tamanho], mensagem, TAMANHO_MAX_MENSAGEM);
    log->mensagens[log->tamanho][TAMANHO_MAX_MENSAGEM] = '\0';
    log->tamanho++;
}

void imprimirLog(Log *log) {
    for (int i = 0; i < log->tamanho; i++) {
        printf("%s\n", log->mensagens[i]);
    }
}

void liberarLog(Log *log) {
    for (int i = 0; i < log->tamanho; i++) {
        free(log->mensagens[i]);
    }
    free(log->mensagens);
    free(log);
}

void criarArquivoIterativo(char *nomeArquivo,bool sucesso, Log *log) {
   if (sucesso) {
        adicionarMensagem(log, "Arquivo criado com sucesso\n");
    } else {
        adicionarMensagem(log, "Erro ao criar arquivo \n");
    }
}

void deletarArquivoIterativo(char *nomeArquivo, bool sucesso, Log *log) {
    if (sucesso) {
        adicionarMensagem(log, "Arquivo deletado com sucesso\n");
    } else {
        adicionarMensagem(log, "Erro ao deletar arquivo\n");
    }   
}

void listarConteudoArquivoIterativo(char *arquivo, Log *log) {
    adicionarMensagem(log, "Listando conteúdo do arquivo\n");
}

void criarDiretorioIterativo(char *nomeDiretorio, Log *log) {
    adicionarMensagem(log, "Criando diretório\n");
}

void renomearDiretorioIterativo(char *nomeDiretorio, char *novoNomeDiretorio, Log *log) {
    adicionarMensagem(log, "Renomeando diretório\n");
}

void apagarDiretorioIterativo(char *nomeDiretorio, bool sucesso, Log *log) {
    if (sucesso) {
        adicionarMensagem(log, "Diretório apagado com sucesso\n");
    } else {
        adicionarMensagem(log, "Erro ao apagar diretório\n");
    }
}

void renomearArquivoIterativo(char *nomeArquivo, char *novoNomeArquivo, bool sucesso, Log *log) {
    if (sucesso) {
        adicionarMensagem(log, "Arquivo renomeado com sucesso\n");
    } else {
        adicionarMensagem(log, "Erro ao renomear arquivo\n");
    }
}

void moverArquivoIterativo(char *nomeArquivo, Log *log) {
    adicionarMensagem(log, "Movendo arquivo \n");
}

void listarConteudoDiretorioIterativo(char *diretorio, Log *log) {
    adicionarMensagem(log, "Listando conteúdo do arquivo\n");
}


Log * leituraIterativa(SistemaArquivo *sistemaArquivo) {
    FILE *arquivo;
    char linha[100]; // Defina o tamanho máximo da linha
    char nome[20], comando[20], parametro1[20], parametro2[20], parametro3[20];
    char *token;

    printf("Entre com o nome do arquivo: ");
    scanf("%s", nome);

    arquivo = fopen(nome, "r"); // Abra o arquivo para leitura

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }

    Log *log = criarLog();

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        token = strtok(linha, " \t\n");
        if (token != NULL) {
            strcpy(comando, token);

            if (strcmp(comando, "createfile") == 0 || strcmp(comando, "Create") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    token = strtok(NULL, " \t\n");
                    if (token != NULL) {
                            strcpy(parametro2, token);
                            BlocoConteudo ** blocoConteudo = criarArquivo(sistemaArquivo, parametro1);
                            if (blocoConteudo != NULL) {
                                inserirConteudoArquivo(sistemaArquivo, blocoConteudo, parametro2);
                                criarArquivoIterativo(parametro1, true, log);
                                adicionarMensagem(log, "Conteúdo do arquivo\n");
                            } else {
                                criarArquivoIterativo(parametro1, false, log);
                            }
                    }
                }
            } else if (strcmp(comando, "deletefile") == 0 || strcmp(comando, "Delete") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    bool sucesso =  apagarArquivo(sistemaArquivo,parametro1);
                    deletarArquivoIterativo(parametro1, sucesso, log);
                }
            } else if (strcmp(comando, "listfile") == 0 || strcmp(comando, "Listfile") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    listarConteudoArquivoIterativo(parametro1, log);
                     char *conteudoArquivo;
                     conteudoArquivo = (char*)malloc( 10000 * sizeof(char));
                     conteudoArquivo = listarConteudoArquivo(sistemaArquivo, parametro1);
                     adicionarMensagem(log, conteudoArquivo);
                    
                }
             } else if (strcmp(comando, "movefile") == 0 || strcmp(comando, "Movefile") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    ListaEntradaDiretorio *listaEntradaDiretorio = obterEntradaDiretorio(sistemaArquivo, parametro1);
                    moverArquivo(sistemaArquivo, listaEntradaDiretorio);
                    moverArquivoIterativo(parametro1, log);
                } 
            } else if (strcmp(comando, "renamefile") == 0 || strcmp(comando, "Renamefile") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    token = strtok(NULL, " \t\n");
                    if (token != NULL) {
                        strcpy(parametro2, token);
                        bool sucesso = renomearArquivo(sistemaArquivo, parametro1, parametro2);
                        renomearArquivoIterativo(parametro1, parametro2, sucesso, log);
                    }
                }
            } else if (strcmp(comando, "createdir") == 0 || strcmp(comando, "Createdir") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    criarDiretorio(sistemaArquivo, parametro1);
                    criarDiretorioIterativo(parametro1, log);
                }
            } else if (strcmp(comando, "renamedir") == 0 || strcmp(comando, "Renamedir") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    token = strtok(NULL, " \t\n");
                    if (token != NULL) {
                        strcpy(parametro2, token);
                        renomearDiretorio(sistemaArquivo, parametro1, parametro2);
                        renomearDiretorioIterativo(parametro1, parametro2, log);
                    }
                }
            } else if (strcmp(comando, "deletedir") == 0 || strcmp(comando, "Deletedir") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    bool sucesso = apagarDiretorio(sistemaArquivo, parametro1);
                    apagarDiretorioIterativo(parametro1, sucesso, log);
                }
            } else if (strcmp(comando, "listdir") == 0 || strcmp(comando, "Listdir") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    listarConteudoDiretorioIterativo(parametro1, log);
                    char *conteudoDiretorio;
                    conteudoDiretorio = (char*)malloc(1000 * sizeof(char)); 
                    conteudoDiretorio = listarConteudoDiretorio(sistemaArquivo);
                    adicionarMensagem(log, conteudoDiretorio);
                }
             }
        }
    }

    fclose(arquivo); // Feche o arquivo

    return 0;
}
