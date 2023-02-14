/*
** EPITECH PROJECT, 2023
** hash
** File description:
** deal with the hash map for antman
*/

#include "antman.h"

int hash(char *word, int size)
{
    int key = 0;

    if (size == 0)
        return (0);
    for (int i = 0; word[i]; i++) {
        key += word[i];
        key = (key * word[i]) % size;
    }
    return (key);
}

char **insert(char **dicc, char *word, int size)
{
    int key = hash(word, size);

    while (dicc[key]) {
        if (my_strcmp(dicc[key], word) == 0)
            return (dicc);
        if (key == size - 1)
            key = 0;
        else
            key++;
    }
    dicc[key] = word;
    return (dicc);
}

int find(char **dicc, char *word, int size)
{
    int key = hash(word, size);
    int start = key;
    bool loop = false;

    while (my_strcmp(word, dicc[key]) != 0) {
        loop = true;
        if (key == size - 1)
            key = 0;
        else
            key++;
        if (key == start)
            break;
    }
    if (key == start && loop)
        return (-1);
    return (key);
}
