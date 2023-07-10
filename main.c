#include "src/Headers/SistemaArquivo.h"
//#include <unistd.h>
//#include <unistd.h>

int main(int argc, char const *argv[]){
    printf("\n");
    printf("-------------------------------------------------------------------\n");
    int tamanhoBloco = 4096; // Em KB
    int tamanhoParticaoDisco = 10; // Em MB
    SistemaArquivo sistemaArquivo;
    sistemaArquivo = inicializaSistemaArquivo(tamanhoParticaoDisco, tamanhoBloco);
    //sleep(2);
    BlocoConteudo **blocoConteudo;
    ListaEntradaDiretorio *listaEntradaDiretorio;
    int qualOpcao = 0;
    bool parar = true;
    char string1[50];
    char string2[50];
    
    while (parar == true){
        printf("\n");
        printf("1 - Criar diretorio\n");
        printf("2 - Renomear diretorio\n");
        printf("3 - Apagar diretorio\n");
        printf("4 - Lista conteudo diretorio\n");
        printf("5 - Criar Arquivo\n");
        printf("6 - Renomear Arquivo\n");
        printf("7 - Apagar Arquivo\n");
        printf("8 - Mover Arquivo\n");
        printf("9 - Lista conteudo arquivo\n");
        printf("10 - Entrar diretorio\n");
        printf("11 - Voltar diretorio\n");
        printf("12 - Sair programa\n");
        printf("\nDigite um numero inteiro: ");
        scanf("%d", &qualOpcao);
        printf("\n");
        switch (qualOpcao) {
        case 1:
            printf("Digite nome diretorio: ");
            scanf("%s", string1);
            criarDiretorio(&sistemaArquivo, string1);
            //sleep(2);
            break;
        case 2:
            printf("Digite novo nome diretorio: ");
            //fgets(string1, sizeof(string1), stdin);
            scanf("%s", string1);
            printf("Digite antigo nome diretorio: ");
            //fgets(string2, sizeof(string2), stdin);
            scanf("%s", string2);
            bool a = renomearDiretorio(&sistemaArquivo, string1, string2);
            break;
        case 3:
            printf("Digite novo nome diretorio: ");
            //fgets(string1, sizeof(string1), stdin);
            scanf("%s", string1);
            bool b = apagarDiretorio(&sistemaArquivo, string1);
            break;
        case 4:
            printf("%s", listarConteudoDiretorio(&sistemaArquivo));
            break;
        case 5:
            printf("Digite nome arquivo: ");
            //fgets(string1, sizeof(string1), stdin);
            scanf("%s", string1);
            blocoConteudo = criarArquivo(&sistemaArquivo, string1);
            printf("Conteudo arquivo: ");
            //fgets(string2, sizeof(string2), stdin);
            scanf("%s", string2);
            inserirConteudoArquivo(&sistemaArquivo, blocoConteudo, string2);
            break;
        case 6:
            printf("Digite novo nome arquivo: ");
            //fgets(string1, sizeof(string1), stdin);
            scanf("%s", string1);
            printf("Digite antigo nome arquivo: ");
            scanf("%s", string2);
            //fgets(string2, sizeof(string2), stdin);
            bool c = renomearArquivo(&sistemaArquivo, string1, string2);
            break;
        case 7:
            printf("Digite novo nome arquivo: ");
            //fgets(string1, sizeof(string1), stdin);
            scanf("%s", string1);
            bool d = apagarArquivo(&sistemaArquivo, string1);
        case 8:
            printf("Digite novo nome arquivo: ");
            //fgets(string1, sizeof(string1), stdin);
            scanf("%s", string1);
            listaEntradaDiretorio = obterEntradaDiretorio(&sistemaArquivo, string1);
            moverArquivo(&sistemaArquivo, listaEntradaDiretorio);
            break;
        case 9:
            printf("Digite novo nome arquivo: ");
            //fgets(string1, sizeof(string1), stdin);
            scanf("%s", string1);
            printf("%s\n",  listarConteudoArquivo(&sistemaArquivo, string1));
        case 10:
            printf("Digite novo nome diretorio: ");
            //fgets(string1, sizeof(string1), stdin);
            scanf("%s", string1);
            entrarDiretorio(&sistemaArquivo, string1);
            break;
        case 11:
            sairDiretorio(&sistemaArquivo);
            break;
        case 12:
            parar = false;
            break;
        default:
            parar = false;
            break;
    }
    }
    
    printf("-------------------------------------------------------------------\n");
    return 0;
}
