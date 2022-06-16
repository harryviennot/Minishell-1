/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_putchar
*/

#include "my.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_puterr(char *str)
{
    write(2, str, my_strlen(str));
}
