/*
** EPITECH PROJECT, 2023
** create_dicc_dec
** File description:
** get diccionary of file and create an array of 2 dim
*/

#include "giantman.h"

int get_chars_dicc(char *info)
{
    int i = 0;
    int last_sep = 0;

    while (info[i]) {
        if (info[i] == '@')
            last_sep = i;
        if (info[i] == ' ')
            break;
        i++;
    }
    return (last_sep);
}

char *fill_chars_dicc(char *info, int last_sep)
{
    char *dicc_str = my_malloc_ini(last_sep);

    for (int i = 0; i < last_sep; i++)
        dicc_str[i] = info[i];
    return (dicc_str);
}

char **get_dicc(char *info, int last_sep)
{
    char **arr = NULL;
    char *dicc_str = fill_chars_dicc(info, last_sep);

    if (!dicc_str)
        return (NULL);
    arr = my_new_split(dicc_str, "@");
    return (arr);
}
