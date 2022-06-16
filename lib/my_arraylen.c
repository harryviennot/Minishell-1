/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_putchar
*/

#include "my.h"

int my_arraylen(char **str)
{
    int i = 0;
    while (str[i] != NULL)
        i++;
    return i;
}
