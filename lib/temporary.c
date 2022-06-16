/*
** EPITECH PROJECT, 2022
** B-PSU-101-TLS-1-1-minishell1-harry.viennot
** File description:
** temporary
*/

#include "my.h"

int count_quote(char *str)
{
    int count = 0;
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == '"')
            count++;
    }
    return count;
}

int check_quote(char **array)
{
    int count = 0;

    for (int i = 0; array[i] != NULL; i++) {
        count = count_quote(array[i]);
    }
    if (count <= 2)
        return 1;
    return 0;
}
//need to strcat each str of array with spaces until next quote
char **modify(char **array)
{
    int count = 0;
    int x;
    int a = 0;
    int i;
    for (i = 0; array[i] != NULL; i++) {
        if (count_quote(array[i++]) == 1)
            x = i - 1;
            while (count_quote(array[i++]) != 1)
                count++;
    }
    int boucle = my_arraylen(array) - (count + 2);
    char **new_array = malloc(sizeof(char *) * (boucle + 1));
    for (i = 0; a != x; a++) {
        new_array[a] = array[i];
    }
    new_array[a] = NULL;
    return new_array;
}

char **my_quote_array(char *str, char separator)
{
    char **array = my_word_array(str, separator);
    while (check_quote(array))
        array = modify(array);
    return array;
}
