#include "Headers/gtk.h"
#include "Headers/LeituraIterativa.h"

char *paginaAnterior;
SistemaArquivo sistemaArquivo;

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

void removerUltimoCaractere(char *str) {
    if (str == NULL || strlen(str) == 0) {
        return;  // Verifica se a string é nula ou vazia
    }

    int tamanho = strlen(str);
    if (str[tamanho - 1] == ' ') {
        str[tamanho - 1] = '\0';  // Substitui o último caractere por '\0'
    }
}

void atualizarTabelaPrincipal(AppWidgets *widgets){    
    gtk_list_store_clear(widgets->liststore1);

    //Diretorios
    char *conteudoBruto = listarConteudoDiretorio(&sistemaArquivo);
    
    printf("%s\n", conteudoBruto);
    int quantidadeNomes;
    char **conteudo = descomprimirConteudoDiretorio(conteudoBruto, &quantidadeNomes);

    for(int i = 0; i < quantidadeNomes; i++){
        removerUltimoCaractere(conteudo[i]);
        int enderecoAtualINode;
        enderecoAtualINode = getUltimoEnderecoINodeNavegacaoDiretorio(sistemaArquivo.navegacaoDiretorio);
        ListaEntradaDiretorio *listaED;
        listaED = (sistemaArquivo.listaINode[enderecoAtualINode]->listaED);

        char *dataCriacao;
        char *dataModificacao;
        char *dataAcesso;
        while (listaED != NULL){
            if(strcmp(listaED->entradaDiretorio.nome, conteudo[i]) == 0){                
                int a = listaED->entradaDiretorio.enderecoINode;
                INode *iNode = sistemaArquivo.listaINode[a];
                dataCriacao = iNode->atributos.dataCriacao;
                dataModificacao = iNode->atributos.dataUltimaModificacao;
                dataAcesso = iNode->atributos.dataUltimoAcesso;
                break;
            }
            listaED = listaED->proximo;
        }

        GtkTreeIter iter;
        gtk_list_store_append(widgets->liststore1, &iter);
        gtk_list_store_set(widgets->liststore1, &iter, 0, conteudo[i], 1, dataCriacao, 2, dataModificacao, 3, dataAcesso, -1);
    }
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
    
    criarDiretorio(&sistemaArquivo, "teste1");
    criarDiretorio(&sistemaArquivo, "dir1");
    
    BlocoConteudo **blocoConteudo;
    blocoConteudo = criarArquivo(&sistemaArquivo, "Arquivo01");
    printf("%s", listarConteudoDiretorio(&sistemaArquivo));
    inserirConteudoArquivo(&sistemaArquivo, blocoConteudo, "Give me more points, please!");

    atualizarTabelaPrincipal(widgets);
    
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
    
    int enderecoAtualINode;
    enderecoAtualINode = getUltimoEnderecoINodeNavegacaoDiretorio(sistemaArquivo.navegacaoDiretorio);
    ListaEntradaDiretorio *listaED;
    listaED = (sistemaArquivo.listaINode[enderecoAtualINode]->listaED);
    
    sairDiretorio(&sistemaArquivo);
    atualizarTabelaPrincipal(widgets);
    
}

void on_button_edit_clicked(GtkWidget *bt_edit, void *data){
    AppWidgets *widgets = (AppWidgets *)data;

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
    
    // Lógica para editar um arquivo
    GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(widgets->treeview));
    GtkTreeModel *model;
    GtkTreeIter iter;

    paginaAnterior = "principal";
    if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
        char *nomeArquivo;
        gchar *dataCriacao;
        gchar *dataModificacao;
        gchar *dataAcesso;

        gtk_tree_model_get(model, &iter, 0, &nomeArquivo, 1, &dataCriacao, 2, &dataModificacao, 3, &dataAcesso, -1);
        removerUltimoCaractere(nomeArquivo);

        int enderecoAtualINode;
        enderecoAtualINode = getUltimoEnderecoINodeNavegacaoDiretorio(sistemaArquivo.navegacaoDiretorio);
        ListaEntradaDiretorio *listaED;
        listaED = (sistemaArquivo.listaINode[enderecoAtualINode]->listaED);
        while (listaED != NULL){
            if(strcmp(listaED->entradaDiretorio.nome, nomeArquivo) == 0){                
                if(listaED->entradaDiretorio.tipo == arquivo){
                    char *text = listarConteudoArquivo(&sistemaArquivo, nomeArquivo);
                    gtk_text_buffer_set_text(widgets->buffer_arquivo, text, -1);
                    gtk_stack_set_visible_child_name(widgets->stack, "listarArquivo");
                    break;
                }else{
                    entrarDiretorio(&sistemaArquivo, nomeArquivo);
                    atualizarTabelaPrincipal(widgets);
                    break;
                }
            }
            listaED = listaED->proximo;
        }

        g_free(nomeArquivo);
        g_free(dataCriacao);
        g_free(dataModificacao);
        g_free(dataAcesso);
    }
}


void on_main_destroy(GtkWidget *bt_close, void *data){

}

void on_voltar_listar_clicked(GtkWidget *bt_voltar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;

    gtk_stack_set_visible_child_name(widgets->stack, paginaAnterior);
}

void on_button_voltar_clicked(GtkWidget *bt_voltar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;

    gtk_stack_set_visible_child_name(widgets->stack, paginaAnterior);
}

void on_voltar_editar_clicked(GtkWidget *bt_voltar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;

    gtk_stack_set_visible_child_name(widgets->stack, paginaAnterior);
}

void on_voltar_iterativo_clicked(GtkWidget *bt_voltar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;

    gtk_stack_set_visible_child_name(widgets->stack, paginaAnterior);
}

void on_button_iterative_clicked(GtkWidget *bt_voltar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
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

        removerUltimoCaractere(nomeDiretorio);

        if(apagarDiretorio(&sistemaArquivo, nomeDiretorio)){
            printf("Diretório %s removido\n", nomeDiretorio);
        }

        if(apagarArquivo(&sistemaArquivo, nomeDiretorio)){
            printf("Arquivo %s removido\n", nomeDiretorio);
        }

        atualizarTabelaPrincipal(widgets);

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

        gtk_tree_model_get(model, &iter, 0, &nomeArquivo, 1, &dataCriacao, 2, &dataModificacao, 3, &dataAcesso, -1);

        if(renomearDiretorio(&sistemaArquivo, entryNome, nomeArquivo)){
            printf("Diretório ou Arquivo %s renomeado para %s\n", nomeArquivo, entryNome);
        }

        atualizarTabelaPrincipal(widgets);

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

    size_t tamanhoNome = strlen(nome) + 1;
    char* novoNome = (char*)malloc(tamanhoNome * sizeof(char));
    strncpy(novoNome, nome, tamanhoNome);

    size_t tamanhoConteudo = strlen(conteudo) + 1;
    char* novaConteudo = (char*)malloc(tamanhoConteudo * sizeof(char));
    strncpy(novaConteudo, conteudo, tamanhoConteudo);

    BlocoConteudo **blocoConteudo;
    blocoConteudo = criarArquivo(&sistemaArquivo, novoNome);
    inserirConteudoArquivo(&sistemaArquivo, blocoConteudo, novaConteudo);

    atualizarTabelaPrincipal(widgets);
        
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
