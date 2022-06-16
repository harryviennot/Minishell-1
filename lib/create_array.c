/*
** EPITECH PROJECT, 2022
** lib
** File description:
** create word array
*/

#include "my.h"

int is_separator(char c, char *separators)
{
    for (int i = 0; separators[i] != '\0'; i++)
        if (c == separators[i] || c == '"')
            return 1;
    return 0;
}

int count_separators(char *str, char *cseparators)
{
    int separators = 0;
    for (int i = 0; str[i] != 0; i++) {
        if (is_separator(str[i], cseparators))
            separators++;
    }
    return separators;
}

void make_one_arg(char *str, int *i, char **array, int *index)
{
    if (str[*i] == '"') {
        str[*i] = 0;
        ++*i;
        array[*index] = str + *i;
        ++*index;
        for (; str[*i] != '"' && str[*i] != 0; ++*i);
        str[*i] = 0;
    }
}

char **create_wordarray(char *str, char *cseparators)
{
    int separators = count_separators(str, cseparators);
    char *aux = my_strdup(str);
    char **array = NULL;
    int index = 0;
    int i = 0;
    array = malloc(sizeof(char *) * (separators + 2));
    for (; aux[i] != 0; i++) {
        if (is_separator(aux[i], cseparators)) {
            make_one_arg(aux, &i, array, &index);
            aux[i] = 0;
        } else if (i == 0 || aux[i - 1] == 0) {
            array[index] = aux + i;
            index++;
        }
    }
    array[index] = NULL;
    return array;
}

void free_array(char **array)
{
    free(&array[0][0]);
    free(array);
}
