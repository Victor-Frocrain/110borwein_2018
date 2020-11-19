/*
** EPITECH PROJECT, 2019
** titration
** File description:
** titration
*/

#include "borwein.h"

void display_usage(void)
{
    char *str = NULL;
    int fd = open("README", O_RDONLY);

    if (fd < 0)
        return;
    str = get_next_line(fd);
    while (str) {
        printf("%s\n", str);
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    exit(MY_EXIT_SUCCESS);
}

bool parse_arg(char *str)
{
    int i = 0;

    for (i = 0; str && str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (false);
    if (i == 0)
        return (false);
    return (true);
}

bool parser(int ac, char **av)
{
    if (ac != 2)
        return (false);
    if (strcmp(av[1], "-h") == 0)
        display_usage();
    if (parse_arg(av[1]) == false)
        return (false);
    return (true);
}

int borwein(int ac, char **av)
{
    int nb = 0;

    if (parser(ac, av) == false)
        return (MY_EXIT_ERROR);
    nb = strtod(av[1], NULL);
    compute_integrals(nb);
    return (MY_EXIT_SUCCESS);
}
