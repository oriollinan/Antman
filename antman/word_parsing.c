/*
** EPITECH PROJECT, 2023
** word_parsing
** File description:
** put all words into 2 dimensional array
*/

#include "antman.h"

int check_word(char *str, int *i, int *length)
{
    int words = 0;
    bool word = false;

    while (str[(*i)] && str[(*i)] != ' ' &&
    str[(*i)] != '\n' && str[(*i)] != ',') {
        word = true;
        (*i)++;
        (*length)++;
    }
    if (word)
        words++;
    while (str[(*i)] && (str[(*i)] == ' '
    || str[(*i)] == '\n' || str[(*i)] == ',')) {
        words++;
        (*i)++;
    }
    (*i)--;
    return (words);
}

vector_t *dimension_size(char *str)
{
    vector_t *dimension = malloc(sizeof(vector_t));
    dimension->x = 0;
    dimension->y = 1;
    int length = 0;

    for (int i = 0; str[i]; i++) {
        length = 0;
        dimension->y += check_word(str, &i, &length);
        dimension->x = (length > dimension->x) ? length : dimension->x;
    }
    dimension->x += 1;
    dimension->y += 2;
    return (dimension);
}

char **fill_arr(char **info, char *str)
{
    int info_len = my_arrlen(info);
    int j = 0;
    int i = 0;

    for (int x = 0; str[x] && j < info_len; x++) {
        i = 0;
        while (str[x] && str[x] != ' ' && str[x] != '\n' && str[x] != ',') {
            info[j][i] = str[x];
            i++;
            x++;
        }
        if (i != 0 && j < info_len - 1)
            j++;
        if (str[x] && info[j])
            info[j][0] = str[x];
        j++;
    }
    info[j] = NULL;
    return (info);
}
