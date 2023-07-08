#include <gtk/gtk.h>

void on_button_clicked(GtkButton *button, gpointer user_data)
{
    GtkTextView *textview = GTK_TEXT_VIEW(user_data);

    // Obter o buffer de texto associado ao GtkTextView
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(textview);

    // Definir o texto no buffer
    const gchar *text = "Olá, mundo!";
    gtk_text_buffer_set_text(buffer, text, -1);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    // Criar a janela principal
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Criar o GtkTextView
    GtkTextView *textview = GTK_TEXT_VIEW(gtk_text_view_new());
    gtk_text_view_set_editable(textview, FALSE); // Impede a edição do texto

    // Criar o botão
    GtkWidget *button = gtk_button_new_with_label("Definir Texto");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), textview);

    // Criar o layout de caixa vertical
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_box_pack_start(GTK_BOX(vbox), GTK_WIDGET(textview), TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);

    // Adicionar o layout à janela
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Exibir todos os widgets
    gtk_widget_show_all(window);

    // Iniciar o loop principal da GTK
    gtk_main();

    return 0;
}
