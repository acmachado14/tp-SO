#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef struct{
    char dataCriacao[20];
    char dataUltimaModificacao[20];
    char dataUltimoAcesso[20];
}Atributos;

void setDataCriacao(Atributos *atributos);
void setDataUltimaModificacao(Atributos *atributos);
void setDataUltimoAcesso(Atributos *atributos);

char* getDataCriacao(Atributos *atributos);
char* getDataUltimaModificacao(Atributos *atributos);
char* getDataUltimoAcesso(Atributos *atributos);

char* obtemHoraAtual();