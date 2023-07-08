#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char *conteudo;
}Conteudo;

Conteudo* criaConteudo();

void inserirConteudo(Conteudo *conteudo, char *string);

char* getConteudo(Conteudo *conteudo);