#include "Headers/BlocoIndireto.h"

BlocoIndireto criaBlocoIndireto(EnumBlocoIndireto enumBloco, int tanhoBloco, int enderecoBloco){
    BlocoIndireto blocoIndireto;
    blocoIndireto.enderecoBloco = enderecoBloco;
    blocoIndireto.enumBlocoIndireto = enumBloco;
    if(enumBloco == blocoConteudo){
        int quantidade = tanhoBloco / 8;
        BlocoConteudo *blocoConteudo;
        blocoConteudo = (BlocoConteudo*)malloc(quantidade * sizeof(BlocoConteudo));
        for (int i = 0; i < quantidade; i++){
            blocoConteudo[i] = (BlocoConteudo){0};
        }
        blocoIndireto.unionBlocoIndireto.blocoConteudo = blocoConteudo;
        free(blocoConteudo);
    }
    else if (enumBloco == entradaDiretorio){
        int quantidade = tanhoBloco / 16;
        EntradaDiretorio *entradaDiretorio;
        entradaDiretorio = (EntradaDiretorio*)malloc(sizeof(EntradaDiretorio));
         for (int i = 0; i < quantidade; i++){
            entradaDiretorio[i] = (EntradaDiretorio){0};
        }
        blocoIndireto.unionBlocoIndireto.entradaDiretorio = entradaDiretorio;
        free(entradaDiretorio);
    }
    return blocoIndireto;
}

int getEnderecoBlocoIndireto(BlocoIndireto blocoIndireto){
    blocoIndireto.enderecoBloco;
}