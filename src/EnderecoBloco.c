#include "Headers/EnderecoBloco.h"

EnderecoBloco* criaEnderecoBloco(){
    EnderecoBloco *enderecoBloco;
    enderecoBloco = (EnderecoBloco*)malloc(sizeof(EnderecoBloco));
    enderecoBloco->conteudo = criaConteudo();
    return enderecoBloco;
}

void inserirEnderecoBloco(EnderecoBloco *enderecoBloco, char *string, int endereco){
    enderecoBloco->endereco = endereco;
    inserirConteudo(enderecoBloco->conteudo, string);
}

int getEndereco(EnderecoBloco *enderecoBloco){
    return enderecoBloco->endereco;
}
