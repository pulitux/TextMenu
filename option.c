#include "textmenu.h"
#include <stdio.h>
#include <stdlib.h>

void main(void)
    {
    extern char menu_dir[];
    struct  text_menu *option;
    int     r = 0;

    set_menu_dir("/home/pulitux/Escritorio/Programming/C/menus");
    option = load_text_menu("option.menu");

    printf("\n%s\n", menu_dir);

    r = run_text_menu(*option);

    printf("\n\nOption %d selected.\n\n", r);
    }
