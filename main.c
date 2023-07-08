#include "src/Headers/Atributos.h"
#include "src/Headers/BlocoConteudo.h"
#include <unistd.h>

int main(int argc, char const *argv[]){
    //src/BlocoConteudo.c
    printf("-------------------------------------------------------------------\n");
    Atributos atributos;
    atributos = criaAtributo();
    printf("%s\n", getDataCriacao(atributos));
    printf("%s\n", getDataUltimaModificacao(atributos));
    printf("%s\n", getDataUltimoAcesso(atributos));
    printf("-----------\n");
    sleep(2);
    setDataUltimaModificacao(&atributos);
    setDataUltimoAcesso(&atributos);
    printf("%s\n", getDataCriacao(atributos));
    printf("%s\n", getDataUltimaModificacao(atributos));
    printf("%s\n", getDataUltimoAcesso(atributos));
    printf("\n");
    BlocoConteudo blocoConteudo;
    blocoConteudo = criaBlocoConteudo("Tamo Indo", 11, 10);
    printf("Endereco: %d\n", getEndereco(blocoConteudo));
    printf("Conteudo: %s\n", getConteudoBloco(blocoConteudo));
    printf("-------------------------------------------------------------------\n");
    
    return 0;
}
