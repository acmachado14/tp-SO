#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    gchar *nome;
    gchar *dataCriacao;
    gchar *dataModificacao;
    gchar *dataAcesso;
    gchar *conteudo;
    int tipo;
} Modelo;

typedef struct{
    GtkStack *stack;
    GtkWidget *window;

    // Tela inicial
    GtkWidget *entry_particao;
    GtkWidget *entry_bloco;
    GtkWidget *button_iniciar;

    // Tela principal
    GtkWidget *bt_create;
    GtkWidget *bt_edit;
    GtkWidget *bt_list;
    GtkWidget *bt_delete;
    GtkWidget *bt_iterative;
    GtkWidget *bt_voltar_principal;
    GtkWidget *bt_create_dir;
    GtkListStore *liststore1;
    GtkTreeView *treeview;

    // Tela listarArquivo
    GtkTextView *print_arquivo;
    GtkTextBuffer *buffer_arquivo;
    GtkWidget *bt_voltar_listar;

    // Tela criar
    GtkWidget *entry_conteudo;
    GtkWidget *entry_nome_arquivo;
    GtkWidget *bt_salvar;
    GtkWidget *bt_voltar;

    // Tela criar diretorio
    GtkWidget *entry_nome_dir;
    GtkWidget *bt_salvar_dir;
    GtkWidget *bt_voltar_dir;

    // Tela editar
    GtkWidget *entry_nome_edit;
    GtkWidget *bt_salvar_editar;
    GtkWidget *bt_voltar_editar;

    // Tela iterativo
    GtkWidget *entry_entrada_iterativo;
    GtkWidget *bt_command_line;
    GtkWidget *bt_pesquisar_arquivo;
    GtkWidget *bt_voltar_iterativo;
    GtkTextView *print_entradas;
    GtkTextView *print_saidas;
    GtkTextBuffer *buffer_entradas;
    GtkTextBuffer *buffer_saidas;
} AppWidgets;

void on_button_iniciar_clicked(GtkWidget *bt_inciar, void *data);

void on_button_create_clicked(GtkWidget *bt_criar, void *data);

void on_voltar_principal_clicked(GtkWidget *bt_criar, void *data);

void on_button_edit_clicked(GtkWidget *bt_edit, void *data);

void on_button_list_clicked(GtkWidget *bt_list, void *data);

void on_main_destroy(GtkWidget *bt_close, void *data);

void on_voltar_listar_clicked(GtkWidget *bt_voltar, void *data);

void on_button_voltar_clicked(GtkWidget *bt_voltar, void *data);

void on_voltar_editar_clicked(GtkWidget *bt_voltar, void *data);

void on_voltar_iterativo_clicked(GtkWidget *bt_voltar, void *data);

void on_button_iterative_clicked(GtkWidget *bt_voltar, void *data);

void on_button_salvar_clicked(GtkWidget *bt_confirma, void *data);

void on_button_salvar_editar_clicked(GtkWidget *bt_confirma, void *data);

void on_button_pesquisar_arquivo_clicked(GtkWidget *bt_voltar, void *data);

void on_button_command_line_clicked(GtkWidget *bt_voltar, void *data);

void on_button_delete_clicked(GtkWidget *bt_voltar, void *data);

void on_button_salvar_dir_clicked(GtkWidget *bt_confirma, void *data);

void on_voltar_criar_dir_clicked(GtkWidget *bt_voltar, void *data);

void on_button_create_dir_clicked(GtkWidget *bt_confirma, void *data);