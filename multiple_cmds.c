/*
** EPITECH PROJECT, 2022
** B-PSU-101-TLS-1-1-minishell1-harry.viennot
** File description:
** multiple_cmds
*/

#include "my.h"

int check_multiple_cmds(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ';')
            return 1;
    }
    return 0;
}
