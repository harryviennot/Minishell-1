/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** main
*/

#include "my.h"

char **copy_env(char **env)
{
    int i = 0;
    char **my_env = NULL;
    int len = my_arraylen(env);

    my_env = malloc(sizeof(char *) * (len + 1));
    for (i; env[i] != NULL; i++) {
        my_env[i] = my_strdup(env[i]);
    }
    my_env[i] = NULL;
    return my_env;
}

char **p_my_env(char **env, char **args)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_printf("%s\n", env[i]);
    }
    return env;
}

int main(int ac, char **av, char **env)
{
    char **my_env = NULL;
    my_env = copy_env(env);
    if (ac == 1) {
        my_minishell(my_env);
    } else
        return 84;
    return 0;
}
