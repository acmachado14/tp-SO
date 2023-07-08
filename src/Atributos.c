#include "Headers/Atributos.h"

void setDataCriacao(Atributos *atributos);

char* obtemHoraAtual(){
    time_t tempo_atual;
    struct tm *info_tempo;
    char* data_hora = malloc(sizeof(char) * 20);
    tempo_atual = time(NULL);
    info_tempo = localtime(&tempo_atual);
    strftime(data_hora, 20, "%d/%m/%Y %H:%M:%S", info_tempo);
    return data_hora;
}

Atributos criaAtributo(){
    Atributos atributos;
    atributos.dataCriacao = (char*)malloc(19 * sizeof(char));
    atributos.dataUltimaModificacao = (char*)malloc(19 * sizeof(char));
    atributos.dataUltimoAcesso = (char*)malloc(19 * sizeof(char));
    setDataCriacao(&atributos);
    setDataUltimaModificacao(&atributos);
    setDataUltimoAcesso(&atributos);
    return atributos;
}

void setDataCriacao(Atributos *atributos){
    char *dataCriacao = obtemHoraAtual();
    strcpy(atributos->dataCriacao, dataCriacao);
}

void setDataUltimaModificacao(Atributos *atributos){
    char *dataUltimaModificacao = obtemHoraAtual();
    strcpy(atributos->dataUltimaModificacao, dataUltimaModificacao);
}

void setDataUltimoAcesso(Atributos *atributos){
    char *dataUltimoAcesso = obtemHoraAtual();
    strcpy(atributos->dataUltimoAcesso, dataUltimoAcesso);
}

char* getDataCriacao(Atributos atributos){
    return atributos.dataCriacao;
}

char* getDataUltimaModificacao(Atributos atributos){
    return atributos.dataUltimaModificacao;
}

char* getDataUltimoAcesso(Atributos atributos){
    return atributos.dataUltimoAcesso;
}
