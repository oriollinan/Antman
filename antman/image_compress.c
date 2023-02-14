/*
** EPITECH PROJECT, 2023
** image_compress
** File description:
** compresses an image file type
*/

#include "antman.h"

void display_sixfour(int nb)
{
    char *str = dec_to_base(64, nb);
    my_putstr(str);
    free(str);
}

int check_rep(char *img, int *i, int *num)
{
    bool first = true;
    int rep = 0;
    int prev = 0;

    while ((*num) == prev || first) {
        first = false;
        prev = (*num);
        (*num) = 0;
        rep++;
        while (img[(*i)] && img[(*i)] != '\n') {
            (*num) = ((*num) * 10) + (img[(*i)] - '0');
            (*i)++;
        }
        if (img[(*i)])
            (*i)++;
    }
    my_put_nbr(prev);
    return (rep);
}

void display_nbrs_img(char *img, int i)
{
    int rep = 0;
    int num = 0;

    while (img[i] != '\n') {
        num = (num * 10) + img[i] - 48;
        i++;
    }
    i++;
    while (img[i] || num != 0) {
        rep = check_rep(img, &i, &num);
        if (rep != 1) {
            write(1, "*", 1);
        my_put_nbr(rep);
        }
        write(1, "\n", 1);
    }
}

int display_lines_img(char *img)
{
    int num = 0;
    int i = 0;

    while (img[i]) {
        num = 0;
        while (img[i] != '\n') {
            my_putchar(img[i]);
            num = (num * 10) + (img[i] - 48);
            i++;
        }
        if (num == 255) {
            my_putchar(img[i]);
            i++;
            break;
        }
        my_putchar(img[i]);
        i++;
    }
    return (i);
}

bool image_compress(char *path)
{
    char *img = read_file(path, file_size(path));
    int i = 0;

    if (!img)
        return (false);
    i = display_lines_img(img);
    display_nbrs_img(img, i);
    free(img);
    return (true);
}
