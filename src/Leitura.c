#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void leArquivo()
{
    FILE *arquivo;
    char linha[100]; // Defina o tamanho máximo da linha
    char nome[20], comando[20];
    char *token;

    printf("Entre com o nome do arquivo: ");
    scanf("%c", &nome);

    arquivo = fopen(nome, "r"); // Abra o arquivo para leitura

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        token = strtok(linha, "\t\n");
        if (token != NULL)
        {
            strcpy(comando, token); //  escreve a primeira palavra de cada frase na variavel comando

            if (comando == "create" || "Create")
            {
                printf("Estou aqui");
                // chama a funcao de criar
            }
            if (comando == "delete" || "Delete")
            {
                printf("Estou aqui");
                // chama funcao de deletar
            }
            if (comando == "list" || "List")
            {
                printf("Estou aqui");
                // chama funcao de listar
            }
        }
    }

    fclose(arquivo); // Feche o arquivo

}