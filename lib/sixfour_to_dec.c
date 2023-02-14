/*
** EPITECH PROJECT, 2023
** 64_to_dec.c
** File description:
** from base 64 to dec
*/

#include "my_num.h"
#include "my_string.h"

const char s[65] =
"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";

int sixfour_to_dec(char *nb)
{
    int i = 0;
    int dec = 0;
    int iter = 0;

    for (int x = my_strlen(nb) - 1; x >= 0; x--) {
        i = 0;
        while (s[i] && s[i] != nb[x])
            i++;
        if (s[i])
            dec += i * my_compute_power_rec(64, iter);
        iter++;
    }
    return (dec);
}
