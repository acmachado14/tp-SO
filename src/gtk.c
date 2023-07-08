#include "../headers/gtk.h"

void on_button_iniciar_clicked(GtkWidget *bt_inciar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;

    const char *particao = gtk_entry_get_text(GTK_ENTRY(widgets->entry_particao));
    const char *bloco = gtk_entry_get_text(GTK_ENTRY(widgets->entry_bloco));

    printf("Partição: %s\n", particao);
    printf("Bloco: %s\n", bloco);
        
    gtk_stack_set_visible_child_name(widgets->stack, "principal");
}

void on_button_create_clicked(GtkWidget *bt_criar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    gtk_stack_set_visible_child_name(widgets->stack, "criar");
}

void on_voltar_principal_clicked(GtkWidget *bt_criar, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    gtk_stack_set_visible_child_name(widgets->stack, "inicial");
}

void on_button_edit_clicked(GtkWidget *widget, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    gtk_stack_set_visible_child_name(widgets->stack, "editar");
}

void on_button_list_clicked(GtkWidget *widget, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    gtk_stack_set_visible_child_name(widgets->stack, "listarArquivo");
}

void on_main_destroy(GtkWidget *widget, void *data){
    AppWidgets *widgets = (AppWidgets *)data;
    
    //logica

    //gtk_stack_set_visible_child_name(widgets->stack, "inicial");
}

/*

on_button_delete_clicked

on_voltar_listar_clicked

on_button_voltar_clicked

on_button_salvar_clicked

on_voltar_editar_clicked

on_button_salvar_editar_clicked

on_button_command_line_clicked

on_button_pesquisar_arquivo_clicked

on_voltar_iterativo_clicked
*/