#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "textmenu.h"

char    menu_dir[100];


char *set_menu_dir(char *directory)
    {
    extern char menu_dir[];

    strcpy(menu_dir, directory);
    if(menu_dir[strlen(menu_dir) - 1] != "/")
        strcat(menu_dir, "/");
    }

int run_text_menu(struct text_menu menu)
    {
    int n;
    int r = 0;

    while ((r<1) || (r>menu.n_entries))
        {
        puts(menu.title);
        printf("\n");
        for (n = 0; n < menu.n_entries; n++)
            {
            printf("\t[%2d] ", n + 1);
            puts(menu.entry[n]);
            }
        puts(menu.question);
        scanf("%d", &r);
        }
    return(r);
    }

struct text_menu *load_text_menu(char *menu_file)
    {
    FILE    *fp;
    extern char menu_dir[];
    char    menu_path[120];
    char    line[20][100];
    int     n = 0;
    struct  text_menu   *menu;

    strcpy(menu_path, menu_dir);
    strcat(menu_path, menu_file);
    fp = fopen(menu_path, "r");

    while(fgets(&line[n], 100, fp) != NULL)
        n++;

    menu = (struct text_menu *) calloc(1, sizeof(struct text_menu));
    menu->n_entries = (n - 2);
    strcpy(menu->question ,line[n - 1]);
    strcpy(menu->title ,line[0]);
    menu->entry = (long *) calloc((menu->n_entries - 1), sizeof(long));
    for(n--; n-- > 1;)
        {
        menu->entry[n - 1] = calloc((strlen(line[n])+1), sizeof(char));
        strcpy(menu->entry[n -1], line[n]);
        }

    return(menu);
    }

