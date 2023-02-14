/*
** EPITECH PROJECT, 2023
** create_dicc
** File description:
** create diccionary using a hashmap
*/

#include "antman.h"

bool display_pipe(int pos)
{
    write(1, "|", 1);
    display_sixfour(pos);
    return (true);
}

void display_dicc(char **dicc, char **info, int size)
{
    int pos = 0;
    bool code = false;

    for (int j = 0; dicc[j]; j++) {
        my_putstr(dicc[j]);
        write(1, "@", 1);
    }
    for (int j = 0; info[j]; j++) {
        pos = find(dicc, info[j], size);
        if (pos != -1)
            code = display_pipe(pos);
        if (info[j][0] == ' ' && code && info[j + 1]
        && find(dicc, info[j + 1], size) != -1)
            continue;
        if (pos == -1) {
            my_putstr(info[j]);
            code = false;
        }
    }
}

char **create_dicc(int size, char **info)
{
    char **dicc = malloc(sizeof(char *) * (size + 1));
    dicc[size] = NULL;
    dicc = empty_arr(dicc, size);

    for (int j = 0; info[j]; j++) {
        if (my_strlen(info[j]) > 2 && !is_checked(info, j)
        && is_repeated(info, j))
            dicc = insert(dicc, info[j], size);
    }
    display_dicc(dicc, info, size);
    return (dicc);
}
