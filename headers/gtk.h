#include <gtk/gtk.h>

typedef struct dadosGTK{
    const char *path_atual;
    char *pesq_relevancia;
    int verif_patricia;
}dadosGTK;

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
    GtkListStore *liststore1;

    // Tela listarArquivo
    GtkTextView *print_arquivo;
    GtkWidget *bt_voltar_listar;

    // Tela criar
    GtkWidget *entry_tipo_modelo;
    GtkWidget *entry_nome_arquivo;
    GtkWidget *bt_salvar;
    GtkWidget *bt_voltar;

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

    dadosGTK *interno;
} AppWidgets;

void on_button_iniciar_clicked(GtkWidget *bt_inciar, void *data);

void on_button_create_clicked(GtkWidget *bt_criar, void *data);

void on_voltar_principal_clicked(GtkWidget *bt_criar, void *data);

void on_button_edit_clicked(GtkWidget *widget, void *data);

void on_button_list_clicked(GtkWidget *widget, void *data);

void on_main_destroy(GtkWidget *widget, void *data);
