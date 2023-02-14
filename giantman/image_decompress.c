/*
** EPITECH PROJECT, 2023
** image_decompress
** File description:
** decompresses an ppm file
*/

#include "giantman.h"

void display_sixfour(char *nb)
{
    int num = sixfour_to_dec(nb);
    my_put_nbr(num);
}

void check_rep(char *img, int *i, int nb)
{
    int rep = 0;

    while (img[*i] != '\n') {
        rep = (rep * 10) + img[(*i)] - '0';
        (*i)++;
    }
    while (rep != 0) {
        my_put_nbr(nb);
        write(1, "\n", 1);
        rep--;
    }
}

void deco_nbrs(char *img, int i)
{
    int nb = 0;
    int x = 0;

    while (img[i]) {
        nb = 0;
        x = 0;
        while (img[i] && img[i] != '*' && img[i] != '\n') {
            nb = (nb * 10) + img[i] - '0';
            x++;
            i++;
        }
        if (img[i] == '*') {
            i++;
            check_rep(img, &i, nb);
        } else {
            my_put_nbr(nb);
            write(1, "\n", 1);
        }
        i++;
    }
}

int display_lines(char *img)
{
    int i = 0;
    int tmp = 0;

    while (img[i]) {
        tmp = 0;
        while (img[i] != '\n') {
            my_putchar(img[i]);
            tmp = (tmp * 10) + img[i] - '0';
            i++;
        }
        if (tmp == 255) {
            my_putchar(img[i]);
            i++;
            break;
        }
        my_putchar(img[i]);
        i++;
    }
    return (i);
}

bool image_decompress(char *path)
{
    char *img = read_file(path, file_size(path));
    int i = 0;

    if (!img)
        return (false);
    i = display_lines(img);
    deco_nbrs(img, i);
    return (true);
}
