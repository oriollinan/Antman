/*
** EPITECH PROJECT, 2023
** text_compress
** File description:
** compresses a text
*/

#include "antman.h"

bool is_checked(char **info, int pos)
{
    char *word = info[pos];
    pos--;

    while (pos >= 0) {
        if (my_strcmp(word, info[pos]) == 0)
            return (true);
        pos--;
    }
    return (false);
}

bool is_repeated(char **info, int pos)
{
    char *word = info[pos];

    for (int j = 0; info[j]; j++) {
        if (j == pos)
            continue;
        if (my_strcmp(word, info[j]) == 0)
            return (true);
    }
    return (false);
}

int repeated_words(char **info)
{
    int repeated = 0;

    for (int j = 0; info[j]; j++) {
        if (my_strlen(info[j]) > 2 && !is_checked(info, j)
        && is_repeated(info, j))
            repeated++;
    }
    return (repeated);
}

char **empty_arr(char **arr, int len)
{
    for (int j = 0; j < len; j++)
        arr[j] = NULL;
    return (arr);
}

bool text_compress(char *path)
{
    char *file = read_file(path, file_size(path));
    vector_t *dimensions = dimension_size(file);
    char **info = my_arr_ini(dimensions->x, dimensions->y);
    info = fill_arr(info, file);
    int repeated = repeated_words(info);
    char **dicc = NULL;

    if (repeated == 0)
        my_putstr(file);
    else
        dicc = create_dicc(repeated, info);
    free(file);
    free(dicc);
    free_arr(info);
    free(dimensions);
    return (true);
}
