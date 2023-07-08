#include "src/Headers/Atributos.h"
#include "src/Headers/BlocoConteudo.h"
#include "src/Headers/EntradaDiretorio.h"
//#include <unistd.h>

int main(int argc, char const *argv[]){
    //src/BlocoConteudo.c
    printf("-------------------------------------------------------------------\n");
    Atributos atributos;
    atributos = criaAtributo();
    printf("%s\n", getDataCriacao(atributos));
    printf("%s\n", getDataUltimaModificacao(atributos));
    printf("%s\n", getDataUltimoAcesso(atributos));
    printf("-----------\n");
    //sleep(2);
    setDataUltimaModificacao(&atributos);
    setDataUltimoAcesso(&atributos);
    printf("%s\n", getDataCriacao(atributos));
    printf("%s\n", getDataUltimaModificacao(atributos));
    printf("%s\n", getDataUltimoAcesso(atributos));
    printf("\n");
    printf("------------------------------------\n");
    BlocoConteudo blocoConteudo;
    blocoConteudo = criaBlocoConteudo("Tamo Indo", 11, 10);
    printf("Endereco: %d\n", getEndereco(blocoConteudo));
    printf("Conteudo: %s\n", getConteudoBloco(blocoConteudo));
    printf("------------------------------------\n");

    EntradaDiretorio entradaDiretorio;
    EnumTipo enumTipo;
    enumTipo = arquivo;
    entradaDiretorio = criaEntradaDiretorio(enumTipo, "Teste01", 17, 57);
    printf("Nome: %s\n", getNome(entradaDiretorio));
    printf("Endereco: %d\n", getEnderecoINode(entradaDiretorio));
    if(entradaDiretorio.tipo == arquivo){
        printf("Tipo: Arquivo\n");
    }
    if(entradaDiretorio.tipo == diretorio){
        printf("Tipo: diretorio\n");
    }
    printf("-------------------------------------------------------------------\n");
    
    return 0;
}
