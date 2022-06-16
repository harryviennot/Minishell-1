/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_putchar
*/

#include "my.h"

int my_strncmp(const char *data_1, char const *data_2, int n)
{
    int i;

    for (i = 0; (i < n && data_1[i] != '\0') &&
        data_1[i] == data_2[i]; i++);
    if (data_1[i] == data_2[i]) {
        return 0;
    } else {
        return data_1[i] - data_2[i];
    }
}

int my_strcmp(const char *data_1, char const *data_2)
{
    int i = 0;

    for (i; (data_1[i] != '\0' || data_2[i] != '\0') &&
        data_1[i] == data_2[i]; i++);
    if (data_1[i] == data_2[i]) {
        return 0;
    } else {
        return data_1[i] - data_2[i];
    }
}
