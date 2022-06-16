/*
** EPITECH PROJECT, 2022
** B-PSU-101-TLS-1-1-minishell1-harry.viennot
** File description:
** my_unsetenv
*/

#include "my.h"

char **delete_env_var(char **env, int i)
{
    for (; env[i] != NULL; i++) {
        env[i] = env[i + 1];
    }
    return env;
}

char **my_unsetenv(char **env, char **args)
{
    char *var = NULL;
    int index;

    var = malloc(sizeof(char) * (my_strlen(args[1]) + 1));
    var[0] = 0;
    var = my_strcat(var, args[0]);
    var = my_strcat(var, "=");
    index = get_name_index(var, env);
    free(var);
    if (index == -1)
        return env;
    else
        env = delete_env_var(env, index);
    return env;
}
