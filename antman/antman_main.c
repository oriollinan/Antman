/*
** EPITECH PROJECT, 2023
** antman_main
** File description:
** main for the antman
*/

#include "antman.h"

int main(int ac, char **av)
{
    if (error_handling(ac, av))
        return (84);
    if (!file_type(av))
        return (84);
    return (0);
}
