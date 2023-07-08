#include "../headers/gtk.h"

//Configura evento de pesquisar arquivo, da primeira tela do gtk
void on_bt_pesquisar_clicked (GtkButton *bt_pesquisar, void *data) {
    AppWidgets *widgets = (AppWidgets *)data;
    const char *path = selecionar_arquivo();
    gtk_entry_set_text(GTK_ENTRY(widgets->entry_path), path);
}

//Verifica se o endereco path do arquivo é valido
int verificaPath(const char *path){
    //verificar se o arquivo existe
    FILE *arquivo = fopen(path, "r");
    if (arquivo == NULL) {
        return 0;
    }
    fclose(arquivo);
    return 1;
}

//Configura o evento para quando o usuario apertar ok dentro da primeira tela
 void on_bt_confirmar_clicked (GtkButton *bt_pesquisar, void *data) {

    AppWidgets *widgets = (AppWidgets *)data;
    //pegar o valor do entry_path e usar a funcao message para imprimir o arquivo
    const char *path = gtk_entry_get_text(GTK_ENTRY(widgets->entry_path));
    
    //fazer a variavel path_atual dentro de dadosinternos pegar o valor de path
   widgets->interno->path_atual = path;

    //Usar a funcao inicializaPrograma para a variavel widgets->path_atual, se a funcao retornar NULL, exibir mensagem de erro
    if (verificaPath(widgets->interno->path_atual) == 0|| strcmp(widgets->interno->path_atual, "") == 0) {
        mensagem("Arquivo nao encontrado", "O arquivo nao foi encontrado, tente novamente", "dialog-error");
        return;
    }
    
    else{
        mensagem("Arquivo encontrado", widgets->interno->path_atual, "dialog-information");

        if(Inicializa_geral(&(widgets->interno->raiz), &(widgets->interno->doc), &(widgets->interno->busca))){
            mensagem("Arvore inicializada", "A arvore foi inicializada com sucesso", "face-smile");
        }
        
        widgets->interno->verif_patricia=0;
        gtk_stack_set_visible_child_name(widgets->stack, "view_menu");
        
    }
 }

//Configura Evento para quando o botão voltar for apertado pelo usuario, fazendo com que ele volte para a o menu
void on_bt_voltar_clicked (GtkButton *bt_voltar1, void *data) {
    AppWidgets *widgets = (AppWidgets *)data;
    //exibir mensagem na tela, informando que o documento foi encontrado

    gtk_stack_set_visible_child_name(widgets->stack, "view_menu");
}

 //Configura Evento que Monta a Arvore Patricia, fazendo a leitura do arquivo, e armazenando esses valores dentro dos dadosinternos do GTK
void on_bt_MontarPatricia_clicked (GtkButton *bt_MontarPatricia, void *data) {
    AppWidgets *widgets = (AppWidgets *)data;
    int verificado;
    if(Leitura(widgets->interno->path_atual, &(widgets->interno->raiz), &(widgets->interno->doc)) == 0){
        mensagem("Arvore montada", "A arvore foi montada com sucesso", "dialog-information");
            verificado = 1;
    }
    else{
        mensagem("Erro", "Erro ao montar a arvore", "dialog-error");
        verificado =0;
    }

    widgets->interno->verif_patricia = verificado;
}

//criar uma funcao que verifica se a arvore ja foi montada
int verificaArvoreMontada(int verificado){
    if(verificado == 0){
        mensagem("Arvore nao montada", "A arvore ainda nao foi montada, monte a arvore primeiro", "dialog-error");
        return 0;
    }
    else{
        return 1;
    }
}


//Verifica se a arvore esta montada, e limpa a tabela de impressão do GTK

void on_bt_ImprimirPatricia_clicked(GtkButton *bt_ImprimirPatricia, void *data) {
        
        AppWidgets *widgets = (AppWidgets *)data;
        int verificado;
        verificado = widgets->interno->verif_patricia;
        if(verificaArvoreMontada(verificado) == 1){
            
            gtk_stack_set_visible_child_name(widgets->stack, "view_imprimir");  
            //limpar o gtkliststore
            gtk_list_store_clear(widgets->liststore);
        }
}

//quando o usuario aperta o botao lista, dentro da tela Imprimir Patricia, eh chamada a funcao que coloca os dados de impressao
void on_bt_listar_clicked(GtkButton *bt_listar, void *data) {
        AppWidgets *widgets = (AppWidgets *)data;
        GtkListStore *modelo_armazenamento = widgets->liststore;

        gtk_list_store_clear(modelo_armazenamento);

        Ordem(widgets->interno->raiz, data);

}

//Configura um evento que entra dentro da tela de realizar busca quando o usuario aperta o botao

void on_bt_RealizarBusca_clicked (GtkButton *bt_RealizarBusca, void *data) {
        AppWidgets *widgets = (AppWidgets *)data;
        int verificado;
        verificado = widgets->interno->verif_patricia;

        if(verificaArvoreMontada(verificado) == 1){
            
            gtk_stack_set_visible_child_name(widgets->stack, "view_relevanciaPesq");
            //limpar o gtkliststore
            gtk_list_store_clear(widgets->liststore2);
        }
}

//Configura um evento para quando o usuario aperta o botao localizar, e faz com que a aplicação volte a tela inicial

void on_bt_pesqDoc_clicked (GtkButton *bt_pesqDoc, void *data) {
        AppWidgets *widgets = (AppWidgets *)data;
        gtk_stack_set_visible_child_name(widgets->stack, "view_inicial");

}


//Configura um evento que pega o valor da entrada da busca
void on_bt_relevanciaPesq_clicked (GtkButton *bt_relevancia, void *data) {
         AppWidgets *widgets = (AppWidgets *)data;
        const char *pesq;

        pesq = gtk_entry_get_text(GTK_ENTRY(widgets->entry_relevancia));

        widgets->interno->pesq_relevancia = pesq;
       
        //verifica se a entry esta vazia
        if(strcmp(widgets->interno->pesq_relevancia, "") == 0){
        
            mensagem("Pesquisa invalida", "Digite um termo para pesquisar", "dialog-error");
            return;
        }else{
            mensagem("Pesquisa realizada", widgets->interno->pesq_relevancia, "dialog-information");
        }

        gtk_stack_set_visible_child_name(widgets->stack, "view_relevanciaImprimir");

}

void on_bt_listar2_clicked (GtkButton *bt_listar2, void *data) {
        AppWidgets *widgets = (AppWidgets *)data;
        GtkListStore *modelo_armazenamento = widgets->liststore2;

        
        gtk_list_store_clear(modelo_armazenamento);

     //   Ordem2(widgets->interno->raiz, widgets);
        
        calculoRelevancia(widgets->interno->raiz,widgets->interno->pesq_relevancia, &(widgets->interno->doc), &(widgets->interno->busca), data);
        

        

}

//cria funcao que coloca uma mensagem de aviso na tela
void mensagem(const char *texto_principal, const char *texto_secundario, const char *icone) {
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_WARNING, GTK_BUTTONS_OK, "%s", texto_principal);
    gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog), "%s", texto_secundario);

    if (icone != NULL) {
        gtk_window_set_icon_name(GTK_WINDOW(dialog), icone);
    }

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}


//janela de dialogo que permite o usuario selecionar o arquivo desejado
char *selecionar_arquivo() {
    GtkWidget *dialog;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    gint res;

    dialog = gtk_file_chooser_dialog_new("Selecionar Arquivo", NULL, action, "_Cancelar", GTK_RESPONSE_CANCEL, "_Abrir", GTK_RESPONSE_ACCEPT, NULL);

    res = gtk_dialog_run(GTK_DIALOG(dialog));
    if (res == GTK_RESPONSE_ACCEPT) {
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        char *filename = gtk_file_chooser_get_filename(chooser);
        gtk_widget_destroy(dialog);
        return filename;
    } else {
        gtk_widget_destroy(dialog);
        return NULL;
    }
}

int Inicializa_geral(Arvore * raiz, Tdocumento * documento, TBusca * busca){
    Inicializar_Arvore(raiz);
    inicializaDoc(documento);
    InicializaBusca(busca);
    return 1;
}

int Leitura(const char *path, Arvore * raiz, Tdocumento * documento){
    //cabecalhos de constantes na main
    char string[50] , string_tratada[50], string_nome_arquivo[50];
    FILE *arq;
    int index_do_arquivo = 0, contador = -1, tamanho_string, c; //auxilia na verificação de qual arquivo se está lendo
    arq = fopen(path, "r");
    if (arq == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        return 1;
    }

    while(fscanf(arq,"%s",string) != EOF){

        tamanho_string = strlen(string);

        if (string[tamanho_string-1] == ';'){
            //Cada arquivo tem 3 partes: Index, titulo e abstract. Isso explica o porque do mod 3
            contador = (contador + 1)%4; 

            //remove o ';' da string:
            for (c = 0; c < (tamanho_string - 1); c++){
                if(isalnum(string[c])){
                    string_tratada[c] = tolower(string[c]);
                }
                else{
                    string_tratada[c] = string[c];
                }
            }
            //Substitui o ';' pelo '\0'

            //Atualiza string para ser a string tratada
            strcpy(string, string_tratada);
            string[tamanho_string-1] = '\0';

            //caso esteja no estado de leitura do index:
            if (contador == 0){
                index_do_arquivo = atoi(string);
                continue;
            }
            if (contador == 1){
                strcpy(string_nome_arquivo, string);
                continue;
            }

        }
        else{
            for (c = 0; c < (tamanho_string); c++){
                if(isalnum(string[c])){
                    string_tratada[c] = tolower(string[c]);
                }
                else{
                    string_tratada[c] = string[c];
                }
            }
            strcpy(string,string_tratada);
            string[tamanho_string] = '\0';
        }
        Insere_Palavra_Arvore(raiz, string , index_do_arquivo, string_nome_arquivo, documento);
    }
    fclose(arq);
    return 0;
}



void Ordem(Arvore ap, void *data)
{
    AppWidgets *widgets = (AppWidgets *)data;
	/*Funcao com o objetivo de imprimir todas as palavras contidas na Patricia em ordem */
    
    if(ap == NULL)
        return;
    if(EInterno(ap))
        Ordem(ap->NO.NInterno.Esq, data);
    printPalavra(ap, data);
    if(EInterno(ap))
        Ordem(ap->NO.NInterno.Dir, data);

}

void printPalavra(Arvore no, void *data) { 
    AppWidgets *widgets = (AppWidgets *)data;
    
    GtkListStore *modelo_armazenamento = widgets->liststore;
    GtkTreeIter *iter;
    char *palavra = NULL;
    
    char *Ids = NULL;

    if(no == NULL)
        return;
    else if(no->nt == Externo){

        gtk_list_store_append(modelo_armazenamento, &iter);
            
        palavra= (char*)malloc(sizeof(char)*strlen(no->NO.Chave)+1);
        strcpy(palavra, no->NO.Chave);
        
        gtk_list_store_set(modelo_armazenamento, &iter, 0, palavra, -1);

       
        Ids = (char*)malloc(sizeof(char)*strlen(Imprime_lista(&no->tuplas))+1);
        strcpy(Ids, Imprime_lista(&no->tuplas));
        gtk_list_store_set(modelo_armazenamento, &iter, 1, Ids, -1);

       //libera memoria
       
        free(Ids);
        free(palavra);
        }
}

char* Imprime_lista(Tlista * lista){
    char IdNovo[15];
    char stringCompleta[200];
    char *stringRetorno;
    strcpy(stringCompleta, "");

    Aponta_lista aux = lista->primeiro->prox;
    if (Lista_vazia(lista)){
        
        return NULL;
    }
    while(aux != NULL){
       //funcao que formata e guarda os dados em uma string
        sprintf(IdNovo, "<%d,%d> ", aux->num_ocorrencias,aux->index_arquivo);
        strcat(stringCompleta, IdNovo);
        aux = aux->prox;
    }

    //libera memoria das strings 
    //retorna a string com os dados formatados
    strcat(stringCompleta, "\0");

    stringRetorno = (char *)malloc(sizeof(char) * (strlen(stringCompleta) + 1));
    strcpy(stringRetorno, stringCompleta);
    return stringRetorno;
}


int calculoRelevancia(Arvore raiz, char* entradaBusca, Tdocumento* doc, TBusca* busca, void *data){
    double relevancia;
    AppWidgets *widgets = (AppWidgets *)data;
    int qtDocs = quantidadeDocs(doc);
    ApontaCelulaDoc aux = doc->primeiro->prox;
    while(aux != NULL){
        relevancia = (1.0 / aux->totalTermos) * termo(raiz, entradaBusca, qtDocs, aux->idDoc);      
        if(relevancia > 0){
            InsereBuscaOrdenado(busca, aux->idDoc, relevancia);
        }
        aux = aux->prox;
    }

    if(BuscaVazia(&(widgets->interno->busca)) != 0){
        mensagem("Pesquisa invalida", "Nenhum documento encontrado para a busca", "dialog-error");
        return 0;
    }

    ImprimeBusca(busca, doc, data);
}

void ImprimeBusca(TBusca* busca, Tdocumento* doc, void *data) {
    AppWidgets *widgets = (AppWidgets *)data;
    
    GtkListStore *modelo_armazenamento = widgets->liststore2;
    GtkTreeIter *iter;
    
    ApontaBusca aux = busca->primeiro->prox;

    while (aux != NULL) {
        
        imprimeDoc(doc, aux->idDoc, aux, data);
        

        removeBusca(busca, aux);
        aux = aux->prox;
    }
    // Percorre a lista de busca e imprime os resultados, juntamente com a relevância
    // A função imprimeDoc() imprime informações do documento associado ao ID armazenado na célula de busca
}
void imprimeDoc(Tdocumento* doc, int idDoc, ApontaBusca busca,void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    char nomeDocString[150];
    char idDocString[15];
    char relevanciaString[15];
    char *nomeDoc = NULL;
    char *idDochar = NULL;
    char *relevancia = NULL;
    GtkTreeIter *iter;
    GtkListStore *modelo_armazenamento = widgets->liststore2;
    ApontaCelulaDoc aux = doc->primeiro->prox;
    while(aux){
        if(aux->idDoc == idDoc){
            //transforma o id do documento em string
            sprintf(idDocString, "%d", aux->idDoc);

            //transforma o nome do documento em string
            sprintf(nomeDocString, "%s", aux->nomeDoc);

            sprintf(relevanciaString, "%.2lf", busca->relevancia);

            nomeDoc = (char *)malloc(sizeof(char) * (strlen(nomeDocString) + 1));
            strcpy(nomeDoc, nomeDocString);
            idDochar = (char *)malloc(sizeof(char) * (strlen(idDocString) + 1));
            strcpy(idDochar, idDocString);
            relevancia = (char *)malloc(sizeof(char) * (strlen(relevanciaString) + 1));
            strcpy(relevancia, relevanciaString);

            gtk_list_store_append(modelo_armazenamento, &iter);
            
            //colocar o valor de idDoc e nomeDoc na lista, na primeira e segunda coluna
            gtk_list_store_set(modelo_armazenamento, &iter, 0, idDochar, -1);
            gtk_list_store_set(modelo_armazenamento, &iter, 1, nomeDoc, -1);
            gtk_list_store_set(modelo_armazenamento, &iter, 2, relevancia, -1);

            free(nomeDoc);
            free(idDochar);
            free(relevancia);

            return;
        }
        aux = aux->prox;
    }
    // Percorre a lista de documentos e imprime o nome do documento associado ao ID
}

