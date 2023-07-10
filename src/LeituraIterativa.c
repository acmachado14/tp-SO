#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SistemaArquivo.h"

void criarArquivo(char *nomeArquivo) {
    printf("Criando arquivo: %s\n", nomeArquivo);
    // Implemente a lógica para criar um arquivo com o nome fornecido
}

void deletarArquivo(char *nomeArquivo, bool sucesso) {
    if (sucesso) {
        printf("Arquivo %s deletado com sucesso\n", nomeArquivo);
    } else {
        printf("Erro ao deletar arquivo %s\n", nomeArquivo);
    }   
}

void listarDiretorio(char *diretorio) {
    printf("Listando diretório: %s\n", diretorio);
    // Implemente a lógica para listar um diretório com o nome fornecido
}

void criarDiretorio(char *nomeDiretorio) {
    printf("Criando diretório: %s\n", nomeDiretorio);
}

void renomearDiretorio(char *nomeDiretorio, char *novoNomeDiretorio) {
    printf("Renomeando diretório: %s para %s\n", nomeDiretorio, novoNomeDiretorio);
}

void apagarDiretorio(char *nomeDiretorio, bool sucesso) {
    if (sucesso) {
        printf("Diretório %s apagado com sucesso\n", nomeDiretorio);
    } else {
        printf("Erro ao apagar diretório %s\n", nomeDiretorio);
    }
}

void renomearArquivo(char *nomeArquivo, char *novoNomeArquivo, bool sucesso) {
    if (sucesso) {
        printf("Arquivo %s renomeado com sucesso para %s\n", nomeArquivo, novoNomeArquivo);
    } else {
        printf("Erro ao renomear arquivo %s para %s\n", nomeArquivo, novoNomeArquivo);
    }
}

void moverArquivo(char *nomeArquivo, char *diretorioAtual, char *novoDiretorio) {
    printf("Movendo arquivo: %s de %s para %s\n", nomeArquivo, diretorioAtual, novoDiretorio);
}


int leituraIterativa(SistemaArquivo *sistemaArquivo) {
    FILE *arquivo;
    char linha[100]; // Defina o tamanho máximo da linha
    char nome[20], comando[20], parametro1[20], parametro2[20], parametro3[20];
    char *token;

    printf("Entre com o nome do arquivo: ");
    scanf("%s", nome);

    arquivo = fopen(nome, "r"); // Abra o arquivo para leitura

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        token = strtok(linha, " \t\n");
        if (token != NULL) {
            strcpy(comando, token);

            if (strcmp(comando, "create") == 0 || strcmp(comando, "Create") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    //TODO: fazer bolocoConteudo aqui ou receber como parametro?
                }
            } else if (strcmp(comando, "delete") == 0 || strcmp(comando, "Delete") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    bool sucesso =  apagarArquivo(sistemaArquivo,&parametro1);
                    deletarArquivo(parametro1, sucesso);
                }
            } else if (strcmp(comando, "list") == 0 || strcmp(comando, "List") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token); //TODO: tipo de lista de diretorios?
                    listarDiretorio(parametro1);
                }
            } else if (strcmp(comando, "createdir") == 0 || strcmp(comando, "Createdir") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    criarDiretorio(sistemaArquivo, &parametro1);
                    criarDiretorio(parametro1);
                }
            } else if (strcmp(comando, "renamedir") == 0 || strcmp(comando, "Renamedir") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    token = strtok(NULL, " \t\n");
                    if (token != NULL) {
                        strcpy(parametro2, token);
                        renomearDiretorio(sistemaArquivo, &parametro1, &parametro2);
                        renomearDiretorio(parametro1, parametro2);
                    }
                }
            } else if (strcmp(comando, "deletedir") == 0 || strcmp(comando, "Deletedir") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    bool sucesso = apagarDiretorio(sistemaArquivo, &parametro1);
                    apagarDiretorio(parametro1, sucesso);
                }
            } else if (strcmp(comando, "renamefile") == 0 || strcmp(comando, "Renamefile") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    token = strtok(NULL, " \t\n");
                    if (token != NULL) {
                        strcpy(parametro2, token);
                        bool sucesso = renomearArquivo(sistemaArquivo, &parametro1, &parametro2);
                        renomearArquivo(parametro1, parametro2, sucesso);
                    }
                }
            } else if (strcmp(comando, "movefile") == 0 || strcmp(comando, "Movefile") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    token = strtok(NULL, " \t\n");
                    if (token != NULL) {
                        strcpy(parametro2, token);
                        if (token != NULL) {
                            strcpy(parametro3, token);
                            //TODO: parametro listaEntradaDiretorio, receber de fora da função ou criar?
                            moverArquivo(parametro1, parametro2, parametro3);
                        }
                    }
                }
            }
        }
    }

    fclose(arquivo); // Feche o arquivo

    return 0;
}
