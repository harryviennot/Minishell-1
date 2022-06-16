/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_count_occurences
*/

#include "my.h"

int count_occurences(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            count++;
    }
    return count;
}
