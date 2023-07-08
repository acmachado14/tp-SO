#include "headers/gtk.h"

int main(int argc, char *argv[]){
    
    GtkBuilder *builder;
    AppWidgets *widgets = g_slice_new(AppWidgets);

    gtk_init(&argc, &argv);

    // Adiciona o xml ao builder, conseguindo a descricao de cada objeto
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "glade/window.glade", NULL);
    printf("builder: %p\n", builder);

    if (builder == NULL){
        g_critical("Nao foi possivel carregar o arquivo");
        return 1;
    }
  
    // Conseguir o endereco da window da janela principal
    widgets->stack = GTK_STACK(gtk_builder_get_object(builder, "stack"));
    widgets->window = GTK_WIDGET(gtk_builder_get_object(builder, "main"));

    // Tela inicial
    widgets->entry_particao = GTK_WIDGET(gtk_builder_get_object(builder, "particao"));
    widgets->entry_bloco = GTK_WIDGET(gtk_builder_get_object(builder, "bloco"));
    widgets->button_iniciar = GTK_WIDGET(gtk_builder_get_object(builder, "button_iniciar"));

    // Tela principal
    widgets->bt_create = GTK_WIDGET(gtk_builder_get_object(builder, "button_create"));
    widgets->bt_edit = GTK_WIDGET(gtk_builder_get_object(builder, "button_edit"));
    widgets->bt_list = GTK_WIDGET(gtk_builder_get_object(builder, "button_list"));
    widgets->bt_delete = GTK_WIDGET(gtk_builder_get_object(builder, "button_delete"));
    widgets->bt_iterative = GTK_WIDGET(gtk_builder_get_object(builder, "button_iterative"));
    widgets->bt_voltar_principal = GTK_WIDGET(gtk_builder_get_object(builder, "voltar_principal"));
    widgets->liststore1 = GTK_LIST_STORE(gtk_builder_get_object(builder, "liststore1"));

    // Tela listarArquivo
    widgets->print_arquivo = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "print_arquivo"));
    widgets->bt_voltar_listar = GTK_WIDGET(gtk_builder_get_object(builder, "voltar_listar"));

    // Tela criar
    widgets->entry_tipo_modelo = GTK_WIDGET(gtk_builder_get_object(builder, "tipo_modelo"));
    widgets->entry_nome_arquivo = GTK_WIDGET(gtk_builder_get_object(builder, "nome_arquivo"));
    widgets->bt_salvar = GTK_WIDGET(gtk_builder_get_object(builder, "button_salvar"));
    widgets->bt_voltar = GTK_WIDGET(gtk_builder_get_object(builder, "button_voltar"));

    // Tela editar
    widgets->entry_nome_edit = GTK_WIDGET(gtk_builder_get_object(builder, "nome_edit"));
    widgets->bt_salvar_editar = GTK_WIDGET(gtk_builder_get_object(builder, "button_salvar_editar"));
    widgets->bt_voltar_editar = GTK_WIDGET(gtk_builder_get_object(builder, "voltar_editar"));

    // Tela iterativo
    widgets->entry_entrada_iterativo = GTK_WIDGET(gtk_builder_get_object(builder, "entrada_iterativo"));
    widgets->bt_command_line = GTK_WIDGET(gtk_builder_get_object(builder, "button_command_line"));
    widgets->bt_pesquisar_arquivo = GTK_WIDGET(gtk_builder_get_object(builder, "button_pesquisar_arquivo"));
    widgets->bt_voltar_iterativo = GTK_WIDGET(gtk_builder_get_object(builder, "voltar_iterativo"));
    widgets->print_entradas = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "print_entradas"));
    widgets->print_saidas = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "print_saidas"));

    if (widgets->window == NULL){
        g_critical("Falha ao obter o objeto window do arquivo glade");
        return 1;
    }

    // Conseguir o endereco do botao e dos sinais
    gtk_builder_connect_signals(builder, widgets);

    // Nao preciso mais do construtor(builder)
    g_object_unref(builder);

    gtk_widget_show(widgets->window);
    
    gtk_main();

    // Destroi o builder
    g_slice_free(AppWidgets, widgets);

    return 0;
}

