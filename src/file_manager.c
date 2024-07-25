#include <gtk/gtk.h>
#include <dirent.h>
#include <sys/stat.h>
#include <glib.h>
#include "file_manager.h"

extern gchar *current_path;

static void on_row_activated(GtkTreeView *tree_view, GtkTreePath *path, GtkTreeViewColumn *column, gpointer user_data);

static GtkTreeModel* create_file_manager_model(const gchar *path) {
    GtkListStore *store;
    GtkTreeIter iter;
    struct dirent *entry;
    struct stat info;
    DIR *dp;
    gchar fullpath[PATH_MAX];

    g_print("Creating file manager model for path: %s\n", path);

    store = gtk_list_store_new(3, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    dp = opendir(path);
    if (dp == NULL) {
        g_warning("Failed to open directory: %s", path);
        return GTK_TREE_MODEL(store);
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] == '.') continue; // skip hidden files

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        stat(fullpath, &info);

        if (S_ISDIR(info.st_mode)) {
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, 0, "folder", 1, entry->d_name, 2, "Folder", -1);
        } else {
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, 0, "text-x-generic", 1, entry->d_name, 2, "File", -1);
        }
    }

    closedir(dp);
    g_print("File manager model created\n");
    return GTK_TREE_MODEL(store);
}

static GtkWidget* create_icon_view(GtkTreeModel *model) {
    GtkWidget *view;
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;

    g_print("Creating icon view\n");

    view = gtk_tree_view_new_with_model(model);

    renderer = gtk_cell_renderer_pixbuf_new();
    column = gtk_tree_view_column_new_with_attributes("Icon", renderer, "icon-name", 0, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Name", renderer, "text", 1, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text", 2, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);

    g_signal_connect(view, "row-activated", G_CALLBACK(on_row_activated), NULL);

    g_print("Icon view created\n");

    return view;
}

static void on_row_activated(GtkTreeView *tree_view, GtkTreePath *path, GtkTreeViewColumn *column, gpointer user_data) {
    GtkTreeModel *model = gtk_tree_view_get_model(tree_view);
    GtkTreeIter iter;
    gchar *name;
    gchar *type;

    g_print("Row activated\n");

    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gtk_tree_model_get(model, &iter, 1, &name, 2, &type, -1);

        if (g_strcmp0(type, "Folder") == 0) {
            gchar *new_path = g_build_filename(current_path, name, NULL);
            g_free(current_path);
            current_path = new_path;
            GtkTreeModel *new_model = create_file_manager_model(current_path);
            gtk_tree_view_set_model(tree_view, new_model);
            g_object_unref(new_model);
        }

        g_free(name);
        g_free(type);
    }
}

GtkWidget* create_file_manager_view() {
    GtkTreeModel *model;
    GtkWidget *view;

    g_print("Creating file manager view\n");

    if (current_path == NULL) {
        current_path = g_strdup(g_get_home_dir()); // Asegurarse de que current_path esté inicializado
    }

    model = create_file_manager_model(current_path);
    view = create_icon_view(model);

    g_print("File manager view created\n");

    return view;
}
