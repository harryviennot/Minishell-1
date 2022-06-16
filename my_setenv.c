/*
** EPITECH PROJECT, 2022
** B-PSU-101-TLS-1-1-minishell1-harry.viennot
** File description:
** my_setenv
*/

#include "my.h"

int check_var_existance(char *str, char **env)
{
    int same = 1;

    for (int i = 0; env[i] != NULL; i++) {
        same = my_strncmp(str, env[i], my_strlen(str) - 1);
        if (same == 0)
            return 1;
    }
    return 0;
}

char **new_env(char **env, char *name, char *var)
{
    int i = 0;
    char **n_env = NULL;
    char *line = NULL;
    int len = my_arraylen(env);

    n_env = malloc(sizeof(char *) * (len + 2));
    line = malloc(sizeof(char) * (my_strlen(name) + my_strlen(var) + 2));
    for (i; env[i] != NULL; i++) {
        n_env[i] = my_strdup(env[i]);
    }
    my_free(env);
    line[0] = '\0';
    line = my_strcat(line, name);
    line = my_strcat(line, var);
    n_env[i++] = line;
    n_env[i] = NULL;
    return n_env;
}

char **change_env(char **env, char *name, char *var)
{
    char *line = NULL;
    int index = get_name_index(name, env);

    line = malloc(sizeof(char) * (my_strlen(name) + my_strlen(var) + 2));
    free(env[index]);
    line[0] = '\0';
    line = my_strcat(line, name);
    line = my_strcat(line, var);
    env[index] = line;
    return env;
}

char **my_setenv(char **env, char *name, char *var)
{
    int exist = 0;

    char *tmp = malloc(sizeof(char) * strlen(name) + 2);
    tmp[0] = 0;
    my_strcat(tmp, name);
    my_strcat(tmp, "=");
    exist = check_var_existance(tmp, env);
    if (exist == 0)
        env = new_env(env, tmp, var);
    else
        env = change_env(env, tmp, var);
    return env;
}

char **my_ready_setenv(char **env, char **args)
{
    if (my_arraylen(args) > 3) {
        write(2, "too many arguments to function 'setenv'\n", 40);
        return env;
    } else if (my_arraylen(args) < 3) {
        write(2, "too few arguments to function 'setenv'\n", 39);
        return env;
    }
    env = my_setenv(env, args[1], args[2]);
    return env;
}
