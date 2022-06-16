/*
** EPITECH PROJECT, 2022
** liv
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, const char *src)
{
    int length_dest = my_strlen(dest);

    my_strcpy(dest + length_dest, src);
    return dest;
}
