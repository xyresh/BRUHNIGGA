/*
*   BRUHNIGGA VERSION 1.0
*
*   File: Main.c
*
*   Author: MrAyO github.com/xyresh
*
*   This performs exactly what the BRUH python Version does But it is written in C and only Works on linux Desktop
*   with The GTK API's.
*   Also it Performs the Sound bit of it by issuing a shell command which is Rather Autistic If you Think about It and it Assumes you Have VLC installed 
*   or at a minimum the CVLC daemon is available from the shell.Could've learned how to use other APIS built into the system or whatever but 
*   i Am Really bad at coding shit and this is quite literally a bodge
*
*   
*/

#include <gtk/gtk.h>
#include <stdlib.h>
  
static int counter = 0;
  
void greet(GtkWidget* widget, gpointer data)
{
    // printf equivalent in GTK+
    g_print("BRUH\n");
    //THIS Can Be changed to system("timeout -k 0.7 0.7  mpg123 'bruh.mp3'");
    //it seriously just may work but i never gave it a go and i couldn't be arsed to do it
    system("timeout -k 0.7 0.7  cvlc 'bruh.mp3'");
}




//Kill The Main Window
void destroy(GtkWidget* widget, gpointer data)
{
    gtk_main_quit();
}



//Main Function LOL
int main(int argc, char* argv[])
{
    //instantiate Structs
    GtkWidget* window;
    GtkWidget* button;
    gtk_init(&argc, &argv);
    //Create Window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //KIll signal, We get Violent HERE!!!
    g_signal_connect(window, "destroy",
                     G_CALLBACK(destroy), NULL);


    gtk_container_set_border_width(GTK_CONTAINER(window), 60);
    //simple button lol
    button = gtk_button_new_with_label("BRUHNIGGA");
  
    g_signal_connect(GTK_OBJECT(button),
                     "clicked", G_CALLBACK(greet),
                     "button");
  
    gtk_container_add(GTK_CONTAINER(window), button);
  
    gtk_widget_show_all(window);
  
    gtk_main();
  
    return 0;
}
