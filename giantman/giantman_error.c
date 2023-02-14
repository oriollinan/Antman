/*
** EPITECH PROJECT, 2023
** giantman_error
** File description:
** handles the errors
*/

#include "giantman.h"

long int file_size(char *file)
{
    struct stat fi;

    if (stat(file, &fi) != -1) {
        if (fi.st_mode & S_IFMT == S_IFDIR)
            return (-2);
        return (fi.st_size);
    } else
        return (-1);
    return (0);
}

char *read_file(char *path, int size)
{
    char *buf = NULL;
    int fd = 0;

    if (size < 0)
        return (NULL);
    if ((fd = open(path, O_RDONLY)) == -1)
        return (NULL);
    buf = my_malloc_ini(size);
    if (!buf)
        return (NULL);
    if (read(fd, buf, size) == -1) {
        free(buf);
        return (NULL);
    }
    if (close(fd) == -1) {
        free(buf);
        return (NULL);
    }
    return (buf);
}

bool file_type_error(char **av)
{
    bool ret = false;

    if (my_strcmp(av[2], "1") == 0)
        ret = true;
    if (my_strcmp(av[2], "2") == 0)
        ret = true;
    if (my_strcmp(av[2], "3") == 0)
        ret = true;
    return (ret);
}

bool error_handling(int ac, char **av)
{
    if (ac != 3)
        return (true);
    char *str = read_file(av[1], file_size(av[1]));
    if (!str)
        return (true);
    free(str);
    if (!file_type_error(av))
        return (true);
    return (false);
}
