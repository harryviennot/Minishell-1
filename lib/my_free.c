/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_count_occurences
*/

#include "my.h"

void my_free(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}
