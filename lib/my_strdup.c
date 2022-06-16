/*
** EPITECH PROJECT, 2022
** lib
** File description:
** strdup
*/

#include "my.h"

char *my_strdup(const char *str)
{
    int length = my_strlen(str);
    char *new = malloc(sizeof(char) * length + 1);

    for (int i = 0; i < length + 1; i++) {
        new[i] = str[i];
    }
    return new;
}

char *my_strndup(const char *str, int n)
{
    int i;

    char *new = malloc(sizeof(char) * n + 1);
    for (i = 0; i < n; i++) {
        new[i] = str[i];
    }
    new[i] = '\0';
    return new;
}

char *my_strndupafter(const char *str, int n)
{
    int i = 0;

    char *new = malloc(sizeof(char) * ((my_strlen(str) - n) + 1));
    for (n; str[n] != '\0'; n++) {
        new[i++] = str[n];
    }
    new[i] = '\0';
    return new;
}
