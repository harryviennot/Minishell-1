/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strcpy(char *dest, const char *src)
{
    int length = my_strlen(src);
    void *str = my_memcpy(dest, src, length + 1);

    return str;
}
