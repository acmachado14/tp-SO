#include "../headers/gtk.h"

char *paginaAnterior;

char* obterDataAtual() {
    time_t rawtime;
    struct tm* timeinfo;
    char* data = (char*)malloc(sizeof(char) * 11);  // 10 caracteres para a data + 1 caractere nulo de terminação

    if (data == NULL) {
        // Tratar o erro de alocação de memória
        return NULL;
    }

    // Obter o tempo atual
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Formatar a data no formato dd-mm-yyyy
    strftime(data, 11, "%d-%m-%Y", timeinfo);

    return data;
}

void on_button_iniciar_clicked(GtkWidget *bt_inciar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;

    const char *particao = gtk_entry_get_text(GTK_ENTRY(widgets->entry_particao));
    const char *bloco = gtk_entry_get_text(GTK_ENTRY(widgets->entry_bloco));

    printf("Partição: %s\n", particao);
    printf("Bloco: %s\n", bloco);

    paginaAnterior = "inicial";
        
    gtk_stack_set_visible_child_name(widgets->stack, "principal");
}

void on_button_create_clicked(GtkWidget *bt_criar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    paginaAnterior = "principal";

    gtk_stack_set_visible_child_name(widgets->stack, "criar");
}

void on_voltar_principal_clicked(GtkWidget *bt_criar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    gtk_stack_set_visible_child_name(widgets->stack, paginaAnterior);
}

void on_button_edit_clicked(GtkWidget *bt_edit, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    // Lógica para editar um arquivo
    GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(widgets->treeview));
    GtkTreeModel *model;
    GtkTreeIter iter;

    if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
        gchar *nomeArquivo;
        gchar *dataCriacao;
        gchar *dataModificacao;
        gchar *dataAcesso;

        printf("Modelo selecionado\n");
        // Obtendo os valores das colunas
        gtk_tree_model_get(model, &iter, 0, &nomeArquivo, 1, &dataCriacao, 2, &dataModificacao, 3, &dataAcesso, -1);

        // Faça algo com as informações obtidas, por exemplo, exibi-las em um diálogo ou passá-las para outra função de edição

        printf("Nome: %s\n", nomeArquivo);
        printf("Data de criação: %s\n", dataCriacao);
        printf("Data de modificação: %s\n", dataModificacao);
        printf("Data de acesso: %s\n", dataAcesso);

        g_free(nomeArquivo);
        g_free(dataCriacao);
        g_free(dataModificacao);
        g_free(dataAcesso);
    }

    paginaAnterior = "principal";

    gtk_stack_set_visible_child_name(widgets->stack, "editar");
}

void on_button_list_clicked(GtkWidget *bt_list, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    // Definir o texto no buffer
    const gchar *text = "Olá, mundo!";
    gtk_text_buffer_set_text(widgets->buffer_arquivo, text, -1);

    paginaAnterior = "principal";

    gtk_stack_set_visible_child_name(widgets->stack, "listarArquivo");
}


void on_main_destroy(GtkWidget *bt_close, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    //gtk_stack_set_visible_child_name(widgets->stack, "inicial");
}

void on_voltar_listar_clicked(GtkWidget *bt_voltar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    gtk_stack_set_visible_child_name(widgets->stack, paginaAnterior);
}

void on_button_voltar_clicked(GtkWidget *bt_voltar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    gtk_stack_set_visible_child_name(widgets->stack, paginaAnterior);
}

void on_voltar_editar_clicked(GtkWidget *bt_voltar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    gtk_stack_set_visible_child_name(widgets->stack, paginaAnterior);
}

void on_voltar_iterativo_clicked(GtkWidget *bt_voltar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    gtk_stack_set_visible_child_name(widgets->stack, paginaAnterior);
}

void on_button_iterative_clicked(GtkWidget *bt_voltar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    paginaAnterior = "principal";

    gtk_stack_set_visible_child_name(widgets->stack, "iterativo");
}

void on_button_delete_clicked(GtkWidget *bt_voltar, void *data){

    AppWidgets *widgets = (AppWidgets *)data;

    // Lógica para deletar um diretório
    GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(widgets->treeview));
    GtkTreeModel *model;
    GtkTreeIter iter;

    if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
        gchar *nomeDiretorio;
        gtk_tree_model_get(model, &iter, 0, &nomeDiretorio, -1);

        // Remova o diretório do modelo de dados
        gtk_list_store_remove(widgets->liststore1, &iter);

        g_free(nomeDiretorio);
    }
}

void on_button_command_line_clicked(GtkWidget *bt_voltar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    // Definir o texto no buffer
    const char *particao = gtk_entry_get_text(GTK_ENTRY(widgets->entry_entrada_iterativo));

    gtk_text_buffer_set_text(widgets->buffer_entradas, particao, -1);

    gtk_text_buffer_set_text(widgets->buffer_saidas, particao, -1);
}

void on_button_pesquisar_arquivo_clicked(GtkWidget *bt_voltar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;

    const char *nome_arquivo = gtk_entry_get_text(GTK_ENTRY(widgets->entry_entrada_iterativo));

    char caminho_arquivo[256]; // Defina o tamanho adequado para o caminho do arquivo
    snprintf(caminho_arquivo, sizeof(caminho_arquivo), "arquivos/%s", nome_arquivo);

    FILE *arquivo = fopen(caminho_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho_arquivo = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    char *buffer = malloc(tamanho_arquivo + 1); // +1 para o caractere nulo de terminação
    if (buffer == NULL) {
        printf("Erro de alocação de memória\n");
        fclose(arquivo);
        return;
    }

    fread(buffer, 1, tamanho_arquivo, arquivo);
    buffer[tamanho_arquivo] = '\0';

    fclose(arquivo);

    gtk_text_buffer_set_text(widgets->buffer_entradas, buffer, -1);

    gtk_text_buffer_set_text(widgets->buffer_saidas, buffer, -1);

    free(buffer);
}

void on_button_salvar_editar_clicked(GtkWidget *bt_confirma, void *data) {
    AppWidgets *widgets = (AppWidgets *)data;

    const char *nome = gtk_entry_get_text(GTK_ENTRY(widgets->entry_nome_edit));

    size_t tamanho = strlen(nome) + 1;

    char* entryNome = (char*)malloc(tamanho * sizeof(char));

    strncpy(entryNome, nome, tamanho);

    // Lógica para editar um arquivo
    GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(widgets->treeview));
    GtkTreeModel *model;
    GtkTreeIter iter;

    if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
        gchar *nomeArquivo;
        gchar *dataCriacao;
        gchar *dataModificacao;
        gchar *dataAcesso;

        // Obtendo os valores das colunas
        gtk_tree_model_get(model, &iter, 0, &nomeArquivo, 1, &dataCriacao, 2, &dataModificacao, 3, &dataAcesso, -1);

        //Da pra printar aqui se for preciso

        gtk_list_store_set(GTK_LIST_STORE(model), &iter, 0, entryNome, 1, dataCriacao, 2, obterDataAtual(), 3, dataAcesso, -1);

        // Liberar a memória alocada para as strings obtidas do modelo
        g_free(nomeArquivo);
        g_free(dataCriacao);
        g_free(dataModificacao);
        g_free(dataAcesso);
    }
    
    gtk_stack_set_visible_child_name(widgets->stack, "principal");
}

void on_button_salvar_clicked(GtkWidget *bt_confirma, void *data) {
    AppWidgets *widgets = (AppWidgets *)data;

    const char *nome = gtk_entry_get_text(GTK_ENTRY(widgets->entry_nome_arquivo));
    const char *conteudo = gtk_entry_get_text(GTK_ENTRY(widgets->entry_conteudo));

    size_t tamanho = strlen(nome) + 1;

    char* novaString = (char*)malloc(tamanho * sizeof(char));

    strncpy(novaString, nome, tamanho);

    Modelo arquivo = {
        .nome = novaString,
        .dataCriacao = obterDataAtual(),
        .dataModificacao = obterDataAtual(),
        .dataAcesso = "null"
    };

    GtkTreeIter iter;
    gtk_list_store_append(widgets->liststore1, &iter);
    gtk_list_store_set(widgets->liststore1, &iter, 0, arquivo.nome, 1, arquivo.dataCriacao, 2, arquivo.dataModificacao, 3, arquivo.dataAcesso, -1);
        
    gtk_stack_set_visible_child_name(widgets->stack, "principal");
}

void on_button_create_dir_clicked(GtkWidget *bt_confirma, void *data) {
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    paginaAnterior = "principal";

    gtk_stack_set_visible_child_name(widgets->stack, "criar_dir");
}

void on_voltar_criar_dir_clicked(GtkWidget *bt_voltar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    gtk_stack_set_visible_child_name(widgets->stack, paginaAnterior);
}

void on_button_salvar_dir_clicked(GtkWidget *bt_confirma, void *data) {
    AppWidgets *widgets = (AppWidgets *)data;

    const char *nome = gtk_entry_get_text(GTK_ENTRY(widgets->entry_nome_dir));

    size_t tamanho = strlen(nome) + 1;

    char* nomeDir = (char*)malloc(tamanho * sizeof(char));

    strncpy(nomeDir, nome, tamanho);

    Modelo arquivo = {
        .nome = nomeDir,
        .dataCriacao = obterDataAtual(),
        .dataModificacao = obterDataAtual(),
        .dataAcesso = obterDataAtual(),
        .conteudo = "null",
        .tipo = 1
    };

    GtkTreeIter iter;
    gtk_list_store_append(widgets->liststore1, &iter);
    gtk_list_store_set(widgets->liststore1, &iter, 0, arquivo.nome, 1, arquivo.dataCriacao, 2, arquivo.dataModificacao, 3, arquivo.dataAcesso, -1);
        
    gtk_stack_set_visible_child_name(widgets->stack, "principal");
}
