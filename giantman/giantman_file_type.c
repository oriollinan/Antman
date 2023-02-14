/*
** EPITECH PROJECT, 2023
** file_type
** File description:
** find the file type
*/

#include "giantman.h"

bool file_type(char **av)
{
    if (my_strcmp(av[2], "3") == 0)
        return (image_decompress(av[1]));
    else if (my_strcmp(av[2], "1") == 0)
        return (text_decompress(av[1]));
    return (text_decompress(av[1]));
}
