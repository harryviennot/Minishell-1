/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_putchar
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}
