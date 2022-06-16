/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** remove
*/

#include "my.h"

char *remove_n(char *tmp)
{
    int len = my_strlen(tmp);
    tmp[len - 1] = '\0';
    return tmp;
}

char *remove_p(char *str)
{
    int i;
    int j = 0;
    char *paths = NULL;
    paths = malloc(sizeof(char) * (my_strlen(str) - 5 + 1));
    for (i = 5; str[i] != '\0'; i++) {
        paths[j++] = str[i];
    }
    paths[j] = '\0';
    return paths;
}
