#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void criarArquivo(char *nomeArquivo) {
    printf("Criando arquivo: %s\n", nomeArquivo);
    // Implemente a lógica para criar um arquivo com o nome fornecido
}

void deletarArquivo(char *nomeArquivo) {
    printf("Deletando arquivo: %s\n", nomeArquivo);
    // Implemente a lógica para deletar um arquivo com o nome fornecido
}

void listarDiretorio(char *diretorio) {
    printf("Listando diretório: %s\n", diretorio);
    // Implemente a lógica para listar um diretório com o nome fornecido
}

void criarDiretorio(char *nomeDiretorio) {
    printf("Criando diretório: %s\n", nomeDiretorio);
    // Implemente a lógica para criar um diretório com o nome fornecido
}

void renomearDiretorio(char *nomeDiretorio, char *novoNomeDiretorio) {
    printf("Renomeando diretório: %s para %s\n", nomeDiretorio, novoNomeDiretorio);
    // Implemente a lógica para renomear um diretório com o nome fornecido para o novo nome fornecido
}

void apagarDiretorio(char *nomeDiretorio) {
    printf("Apagando diretório: %s\n", nomeDiretorio);
    // Implemente a lógica para apagar um diretório com o nome fornecido
}

void renomearArquivo(char *nomeArquivo, char *novoNomeArquivo) {
    printf("Renomeando arquivo: %s para %s\n", nomeArquivo, novoNomeArquivo);
    // Implemente a lógica para renomear um arquivo com o nome fornecido para o novo nome fornecido
}

void moverArquivo(char *nomeArquivo, char *diretorioAtual, char *novoDiretorio) {
    printf("Movendo arquivo: %s de %s para %s\n", nomeArquivo, diretorioAtual, novoDiretorio);
    // Implemente a lógica para mover um arquivo com o nome fornecido do diretório atual para o novo diretório fornecido
}


int leituraIterativa() {
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
                    criarArquivo(parametro1);
                }
            } else if (strcmp(comando, "delete") == 0 || strcmp(comando, "Delete") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    deletarArquivo(parametro1);
                }
            } else if (strcmp(comando, "list") == 0 || strcmp(comando, "List") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    listarDiretorio(parametro1);
                }
            } else if (strcmp(comando, "createdir") == 0 || strcmp(comando, "Createdir") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    criarDiretorio(parametro1);
                }
            } else if (strcmp(comando, "renamedir") == 0 || strcmp(comando, "Renamedir") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    token = strtok(NULL, " \t\n");
                    if (token != NULL) {
                        strcpy(parametro2, token);
                        renomearDiretorio(parametro1, parametro2);
                    }
                }
            } else if (strcmp(comando, "deletedir") == 0 || strcmp(comando, "Deletedir") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    apagarDiretorio(parametro1);
                }
            } else if (strcmp(comando, "renamefile") == 0 || strcmp(comando, "Renamefile") == 0) {
                token = strtok(NULL, " \t\n");
                if (token != NULL) {
                    strcpy(parametro1, token);
                    token = strtok(NULL, " \t\n");
                    if (token != NULL) {
                        strcpy(parametro2, token);
                        renomearArquivo(parametro1, parametro2);
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
