/*
** EPITECH PROJECT, 2023
** antman
** File description:
** h file for antman
*/

#ifndef ANTMAN_H_
    #define ANTMAN_H_

    // libraries
    #include <stdbool.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stdint.h>
    #include <unistd.h>
    #include <sys/sysmacros.h>
    #include <fcntl.h>
    #include "lib.h"

    // structures
    typedef struct vector_s {
        int x;
        int y;
    } vector_t;

    // prototypes
    bool error_handling(int ac, char **av);
    long int file_size(char *file);
    char *read_file(char *path, int size);
    bool file_type(char **av);
    bool image_compress(char *path);
    bool text_compress(char *path);
    char **fill_arr(char **info, char *str);
    vector_t *dimension_size(char *str);
    int find(char **dicc, char *word, int unique);
    char **insert(char **dicc, char *word, int size);
    char **create_dicc(int unique, char **info);
    char **empty_arr(char **arr, int len);
    bool is_repeated(char **info, int pos);
    bool is_checked(char **info, int pos);
    void display_sixfour(int nb);

#endif
