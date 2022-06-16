/*
** EPITECH PROJECT, 2021
** lib
** File description:
** my_printf
*/

#include "my.h"

int isarg(char *string, int index)
{
    if (string[index] == '%') {
        index++;
        for (; string[index] == ' '; index++) {
        }
        if (string[index] == 'd' || string[index] == 's' ||
            string[index] == 'c') {
            return index;
        }
    }
    return 0;
}

void print_parameters(char *string, int i, va_list args)
{
    if (string[i - 1] == ' ' && string[i] != '%')
        my_putchar(' ');
    switch (string[i]) {
    case 'c':
        my_putchar(va_arg(args, int));
        break;
    case 'd':
        my_put_nbr(va_arg(args, int));
        break;
    case 's':
        my_putstr(va_arg(args, char *));
        break;
    default:
        break;
    }
}

void my_printf(char *string, ...)
{
    va_list args;

    va_start(args, string);
    for (int i = 0; string[i] != '\0'; i++) {
        if (isarg(string, i) != 0) {
            i = isarg(string, i);
            print_parameters(string, i, args);
        } else {
            my_putchar(string[i]);
        }
    }
    va_end(args);
}
