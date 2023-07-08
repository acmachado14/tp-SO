#include <gtk/gtk.h>

void on_combo_changed(GtkComboBox *combo, gpointer user_data)
{
    gint active = gtk_combo_box_get_active(combo);
    g_print("Selecionado: %d\n", active);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    // Criar a janela principal
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Criar o GtkComboBox
    GtkWidget *combo = gtk_combo_box_new_text();
    gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "Opção 1");
    gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "Opção 2");
    gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "Opção 3");

    // Conectar o sinal de mudança
    g_signal_connect(combo, "changed", G_CALLBACK(on_combo_changed), NULL);

    // Criar um layout de caixa vertical
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_box_pack_start(GTK_BOX(vbox), combo, FALSE, FALSE, 0);

    // Adicionar o layout à janela
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Exibir todos os widgets
    gtk_widget_show_all(window);

    // Iniciar o loop principal da GTK
    gtk_main();

    return 0;
}
