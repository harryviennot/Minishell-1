/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_memcpy implementation
*/

#include "my.h"

void *my_memcpy(void *dest, const void *src, int len)
{
    char *d = dest;
    const char *s = src;

    while (len--) {
        *d++ = *s++;
    }
    return dest;
}
