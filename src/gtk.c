#include "Headers/gtk.h"
#include "Headers/SistemaArquivo.h"

char *paginaAnterior;
SistemaArquivo sistemaArquivo;

char* obterDataAtual() {
    time_t rawtime;
    struct tm* timeinfo;
    char* data = (char*)malloc(sizeof(char) * 20);  // 19 caracteres para a data e hora + 1 caractere nulo de terminação

    if (data == NULL) {
        // Tratar o erro de alocação de memória
        return NULL;
    }

    // Obter o tempo atual
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Formatar a data e hora no formato dd-mm-yyyy HH:MM:SS
    strftime(data, 20, "%d-%m-%Y %H:%M:%S", timeinfo);

    return data;
}

char** descomprimirConteudoDiretorio(const char* conteudoDiretorio, int* quantidadeNomes) {
    const char* delimitador = "\n";
    char* copiaConteudo = strdup(conteudoDiretorio); // Faz uma cópia da string para não modificar a original
    char* token = strtok(copiaConteudo, delimitador);
    int capacidade = 10; // Capacidade inicial do array
    int tamanho = 0; // Tamanho atual do array
    char** nomes = malloc(capacidade * sizeof(char*));
    
    while (token != NULL) {
        nomes[tamanho] = strdup(token); // Cria uma cópia do token
        tamanho++;
        
        if (tamanho >= capacidade) {
            capacidade *= 2; // Dobra a capacidade do array
            nomes = realloc(nomes, capacidade * sizeof(char*));
        }
        
        token = strtok(NULL, delimitador);
    }
    
    free(copiaConteudo); // Libera a memória alocada pela cópia
    *quantidadeNomes = tamanho; // Define a quantidade de nomes
    
    return nomes;
}

void atualizarTabelaPrincipal(AppWidgets *widgets){    
    gtk_list_store_clear(widgets->liststore1);

    char *conteudoBruto = listarConteudoDiretorio(&sistemaArquivo);
    
    printf("%s\n", conteudoBruto);
    int quantidadeNomes;
    char **conteudo = descomprimirConteudoDiretorio(conteudoBruto, &quantidadeNomes);

    for(int i = 0; i < quantidadeNomes; i++){
        printf("o conteudo era pra ser esse: %s\n", conteudo[i]);
        GtkTreeIter iter;
        gtk_list_store_append(widgets->liststore1, &iter);
        gtk_list_store_set(widgets->liststore1, &iter, 0, conteudo[i], 1, "teste", 2, "teste", 3, "teste", -1);
    }
    gtk_stack_set_visible_child_name(widgets->stack, "principal");
}

void on_button_iniciar_clicked(GtkWidget *bt_inciar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;

    const char *particaoChar = gtk_entry_get_text(GTK_ENTRY(widgets->entry_particao));
    const char *blocoChar = gtk_entry_get_text(GTK_ENTRY(widgets->entry_bloco));

    char *endptr;
    int particaoInt = strtol(particaoChar, &endptr, 10);
    int blocoInt = strtol(blocoChar, &endptr, 10);

    printf("Partição: %d\n", particaoInt);
    printf("Bloco: %d\n", blocoInt);

    sistemaArquivo = inicializaSistemaArquivo(10, 4096);

    paginaAnterior = "inicial";
    //entrarDiretorio(&sistemaArquivo, "raiz");
    
    criarDiretorio(&sistemaArquivo, "teste1");
    criarDiretorio(&sistemaArquivo, "dir1");
    
    //ListaBlocoConteudo *listaBloco = criarArquivo(&sistemaArquivo, "batata");
    
    //printf("teste 1\n");
    //inserirConteudoArquivo(&sistemaArquivo, listaBloco, "lepo");
    //printf("teste 2\n");
    
    atualizarTabelaPrincipal(widgets);
    
    printf("teste 3\n");
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
        .dataAcesso = obterDataAtual()
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

    criarDiretorio(&sistemaArquivo, nomeDir);
    
    atualizarTabelaPrincipal(widgets);
    
    gtk_stack_set_visible_child_name(widgets->stack, "principal");
}
