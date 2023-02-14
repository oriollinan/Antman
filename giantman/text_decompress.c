/*
** EPITECH PROJECT, 2023
** text_compress
** File description:
** decompresses a text
*/

#include "giantman.h"

void display_word(char *word, char **dicc_d)
{
    int pos = sixfour_to_dec(word);
    my_putstr(dicc_d[pos]);
    free(word);
}

int deco_word(char *info, int i, char **dicc_d)
{
    int len_str = 0;
    char *str = NULL;
    int next = 0;

    for (int j = i; info[j]; j++) {
        if (info[j] != ' ' && info[j] != '\n' &&
        info[j] != ',' && info[j] != '|') {
            len_str++;
        } else
            break;
    }
    str = my_malloc_ini(len_str);
    for (int j = 0; j < len_str; j++, i++)
        str[j] = info[i];
    display_word(str, dicc_d);
    return (i);
}

bool text_decompress(char *path)
{
    char *info = read_file(path, file_size(path));
    int first_c = 0;
    char **dicc_d = NULL;
    if (!info)
        return (false);
    first_c = get_chars_dicc(info);
    if (first_c != 0)
        first_c++;
    dicc_d = get_dicc(info, first_c - 1);
    for (int i = first_c; info[i]; i++) {
        if (info[i] == '|')
            i = deco_word(info, (i + 1), dicc_d);
        if (info[i] && info[i] != '|')
            my_putchar(info[i]);
        if (info[i] == '|') {
            my_putchar(' ');
            i--;
        }
    }
    return (true);
}
