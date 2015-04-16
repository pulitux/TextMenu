#ifndef TEXTMENU_H_INCLUDED
#define TEXTMENU_H_INCLUDED

struct  text_menu
    {
    int     n_entries;
    char    title[50];
    char    question[40];
    char    *(*entry);
    int     answer;
    };

struct user_input
    {
    char    title[100];
    char    question[100];
    char    answer[100];
    };

char *set_menu_dir(char *directory);

int run_text_menu(struct text_menu menu);

struct text_menu *load_text_menu(char *menu_file);

struct user_input *load_user_input(char *menu_file);

#endif // TEXTMENU_H_INCLUDED
