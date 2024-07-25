#include <gtk/gtk.h>
#include "file_manager.h"

// Declaración de las variables globales
gchar *current_path = NULL;
gchar *previous_path = NULL;
gchar *next_path = NULL;

// Declaración de funciones
static void activate(GtkApplication *app, gpointer user_data);
static void on_back_clicked(GtkButton *button, gpointer user_data);
static void on_forward_clicked(GtkButton *button, gpointer user_data);
static void on_home_clicked(GtkButton *button, gpointer user_data);
static void update_file_manager_view(GtkWidget *window);

int main(int argc, char *argv[]) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.profilex", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *toolbar;
    GtkWidget *scroll_window;
    GtkWidget *file_manager_view;

    g_print("Activating application\n");

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "ProFileX");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Crear la barra de herramientas
    toolbar = gtk_toolbar_new();
    gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 0);

    // Botón de retroceso
    GtkToolItem *back_button = gtk_tool_button_new(NULL, "Back");
    GtkWidget *back_icon = gtk_image_new_from_icon_name("go-previous", GTK_ICON_SIZE_LARGE_TOOLBAR);
    gtk_tool_button_set_icon_widget(GTK_TOOL_BUTTON(back_button), back_icon);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), GTK_TOOL_ITEM(back_button), -1);
    g_signal_connect(back_button, "clicked", G_CALLBACK(on_back_clicked), window);

    // Botón de avance
    GtkToolItem *forward_button = gtk_tool_button_new(NULL, "Forward");
    GtkWidget *forward_icon = gtk_image_new_from_icon_name("go-next", GTK_ICON_SIZE_LARGE_TOOLBAR);
    gtk_tool_button_set_icon_widget(GTK_TOOL_BUTTON(forward_button), forward_icon);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), GTK_TOOL_ITEM(forward_button), -1);
    g_signal_connect(forward_button, "clicked", G_CALLBACK(on_forward_clicked), window);

    // Botón de inicio
    GtkToolItem *home_button = gtk_tool_button_new(NULL, "Home");
    GtkWidget *home_icon = gtk_image_new_from_icon_name("go-home", GTK_ICON_SIZE_LARGE_TOOLBAR);
    gtk_tool_button_set_icon_widget(GTK_TOOL_BUTTON(home_button), home_icon);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), GTK_TOOL_ITEM(home_button), -1);
    g_signal_connect(home_button, "clicked", G_CALLBACK(on_home_clicked), window);

    scroll_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_box_pack_start(GTK_BOX(vbox), scroll_window, TRUE, TRUE, 0);

    file_manager_view = create_file_manager_view();
    gtk_container_add(GTK_CONTAINER(scroll_window), file_manager_view);

    if (current_path == NULL) {
        current_path = g_strdup(g_get_home_dir());
    }

    gtk_widget_show_all(window);

    g_print("Application activated\n");
}

static void update_file_manager_view(GtkWidget *window) {
    GtkWidget *scroll_window = gtk_bin_get_child(GTK_BIN(gtk_widget_get_parent(window)));
    GtkWidget *file_manager_view = create_file_manager_view();
    
    // Elimina los widgets existentes en el contenedor
    gtk_container_foreach(GTK_CONTAINER(scroll_window), (GtkCallback)gtk_widget_destroy, NULL);
    
    // Agrega la nueva vista
    gtk_container_add(GTK_CONTAINER(scroll_window), file_manager_view);
    gtk_widget_show_all(scroll_window); // Asegúrate de mostrar la ventana de desplazamiento
}

static void on_back_clicked(GtkButton *button, gpointer user_data) {
    GtkWidget *window = GTK_WIDGET(user_data);

    g_print("Back button clicked\n");
    if (previous_path) {
        g_free(next_path);
        next_path = g_strdup(current_path);
        g_free(current_path);
        current_path = g_strdup(previous_path);
        g_free(previous_path);
        previous_path = NULL; // Restablece previous_path
        update_file_manager_view(window);
    } else {
        g_print("No previous path to navigate to.\n");
    }
}

static void on_forward_clicked(GtkButton *button, gpointer user_data) {
    GtkWidget *window = GTK_WIDGET(user_data);

    g_print("Forward button clicked\n");
    if (next_path) {
        g_free(previous_path);
        previous_path = g_strdup(current_path);
        g_free(current_path);
        current_path = g_strdup(next_path);
        g_free(next_path);
        next_path = NULL; // Restablece next_path
        update_file_manager_view(window);
    } else {
        g_print("No next path to navigate to.\n");
    }
}

static void on_home_clicked(GtkButton *button, gpointer user_data) {
    GtkWidget *window = GTK_WIDGET(user_data);

    g_print("Home button clicked\n");
    g_free(previous_path);
    previous_path = g_strdup(current_path);
    g_free(current_path);
    current_path = g_strdup(g_get_home_dir());
    update_file_manager_view(window);
}
