/*
** EPITECH PROJECT, 2023
** dec_to_base
** File description:
** goes from dec base to other bases
*/

#include "my_num.h"
#include "my_string.h"

const char s[65] =
"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";

char *base_to_str(int nb, int base)
{
    char *str = my_malloc_ini(2);
    str[1] = '\0';

    switch (base) {
        case 8:
            str[0] = B_8[nb];
        case 10:
            str[0] = B_10[nb];
        case 16:
            str[0] = B_16[nb];
        case 64:
            str[0] = s[nb];
    }
    return (str);
}

char *dec_to_base(int base, unsigned long int nb)
{
    int p = 0;
    int n = 0;
    char *str = NULL;
    char *tmp = NULL;

    if (nb == 0)
        return (my_strdup("0"));
    while (my_compute_power_rec(base, p + 1) <= nb)
        p++;
    str = my_malloc_ini(p + 1);
    while (p >= 0) {
        n = nb / my_compute_power_rec(base, p);
        nb %= (int) my_compute_power_rec(base, p);
        tmp = base_to_str(n, base);
        str = my_strcat(str, tmp);
        free(tmp);
        p--;
    }
    return (str);
}
