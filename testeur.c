#include "cub3d.h"

void    printf_tab(char **all, char *name)
{
    int i;
    
    i = 0;
    if (!all)
        ft_printf("tab vide\n");
    while (all[i])
	{
        ft_printf("%s[%d] : %s\n",name, i, all[i]);
		i++;
	}
}

//printf_tab = on va afficher le nom du char ** et l'afficher entierement  