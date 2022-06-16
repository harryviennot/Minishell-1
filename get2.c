/*
** EPITECH PROJECT, 2022
** B-PSU-101-TLS-1-1-minishell1-harry.viennot
** File description:
** get2
*/

#include "my.h"

int check_for_redir(char **args)
{
    for (int i = 0; args[i] != NULL; i++) {
        if (my_strcmp(args[i], ">") == 0 || my_strcmp(args[i], "<") == 0 ||
        my_strcmp(args[i], ">>") == 0)
            return i;
    }
    return 0;
}

operator_t *get_operators(operator_t *operator, char **args)
{
    int redir = 0;

    operator = malloc(sizeof(operator_t));
    redir = check_for_redir(args);
    if (redir != 0) {
        operator->redir = args[redir];
        operator->filename = args[redir + 1];
        operator->args = args;
        operator->args[redir] = NULL;
        operator->args[redir + 1] = NULL;
    } else {
        operator->redir = NULL;
        operator->filename = NULL;
        operator->args = args;
    }
    return operator;
}
