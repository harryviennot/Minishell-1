/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_putchar
*/

#include "my.h"

char *trim(char *buff)
{
    int x = 0;
    while (1) {
        if ((*buff == ' ') || (*buff == '\t') ||
            (*buff == '\r') || (*buff == '\n')) {
            x++;
            ++buff;
        } else
            break;
    }
    int y = my_strlen(buff) - 1;
    while (1) {
        if (buff[y] == ' ' || (buff[y] == '\t') ||
            (buff[y] == '\r') || (buff[y] == '\n')) {
            y--;
        } else
            break;
    }
    y = my_strlen(buff) - y;
    buff[my_strlen(buff) - y + 1] = '\0';
    return buff;
}

int countsize(char *str)
{
    int reg = 0;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == ' ' || str[i] == '\t') && reg == 0) {
            count++;
            reg = 1;
        } else if ((str[i] == ' ' || str[i] == '\t') && reg == 1)
            continue;
        else {
            count++;
            reg = 0;
        }
    }
    return count;
}

char *my_cleanstr(char *str)
{
    str = trim(str);
    int reg = 0;
    int count = countsize(str);
    char *new = malloc(sizeof(char) * (count + 1));
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == ' ' || str[i] == '\t') && reg == 0) {
            new[j++] = str[i];
            reg = 1;
        } else if ((str[i] == ' ' || str[i] == '\t') && reg == 1)
            continue;
        else {
            new[j++] = str[i];
            reg = 0;
        }
    }
    new[j] = '\0';
    return new;
}
