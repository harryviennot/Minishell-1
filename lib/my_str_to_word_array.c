/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_putchar
*/

#include "my.h"

char **string_to_arr_ext(char **array, char *str, int count, char separator)
{
    char *temp;
    int i = 0;
    int x;
    int j;
    int boucle;
    for (boucle = 0; boucle <= count; boucle++) {
        j = i;
        for (x = 0; str[j] != separator && str[j] != '\0'; j++, x++);
        temp = malloc(sizeof(char) * (x));
        for (x = 0; str[i] != separator && str[i] != '\0'; i++, x++) {
            temp[x] = str[i];
        }
        temp[x] = '\0';
        array[boucle] = temp;
        i++;
    }
    array[boucle] = NULL;
    return array;
}

char **my_str_to_word_array(char *str, char separator)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator) {
            count += 1;
        }
    }
    char **array = malloc(sizeof(char *) * (count + 2));
    array = string_to_arr_ext(array, str, count, separator);
    return array;
}
