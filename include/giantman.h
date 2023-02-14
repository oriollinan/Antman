/*
** EPITECH PROJECT, 2023
** giantmanç
** File description:
** h file for giantman
*/

#ifndef GIANTMAN_H_
    #define GIANTMAN_H_

    // libraries
    #include <stdbool.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stdint.h>
    #include <unistd.h>
    #include <sys/sysmacros.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include "lib.h"

    // prototypes
    bool error_handling(int ac, char **av);
    bool file_type(char **av);
    bool image_decompress(char *path);
    char *read_file(char *path, int size);
    long int file_size(char *file);
    bool text_decompress(char *path);
    int get_chars_dicc(char *info);
    char **get_dicc(char *info, int last_sep);

#endif
