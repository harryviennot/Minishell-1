/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** my_code
*/

#include "my.h"

char *concatenate(char *strg1, char *strg2)
{
    int i = 0;
    int lenstr = my_strlen(strg1);
    int lenstr2 = my_strlen(strg2);
    char *concatenated = malloc(sizeof(char) * (lenstr + lenstr2 + 2));
    for (int j = 0; strg1[j] != '\0'; j++) {
        concatenated[i++] = strg1[j];
    }
    concatenated[i++] = '/';
    for (int j = 0; strg2[j] != '\0'; j++) {
        concatenated[i++] = strg2[j];
    }
    concatenated[i] = '\0';
    return concatenated;
}

char **cd_minus(char **env, char *current_fp)
{
    char *name = NULL;
    char *new_fp = NULL;

    name = my_getenv("OLDPWD", env);
    if (name == NULL) {
        my_printf(": No such file or directory.\n");
    } else {
        env = my_setenv(env, "OLDPWD", current_fp);
        chdir(name);
        new_fp = get_pwd();
        env = my_setenv(env, "PWD", new_fp);
        free(new_fp);
    }
    free(name);
    return env;
}

char **cd_dir(char **env, char **args, char *current_fp)
{
    char *new_fp = NULL;
    int var = chdir(args[1]);
    if (var == -1) {
        var = chdir(concatenate(current_fp, args[1]));
        if (var == -1)
            my_printf_err("%s: No such file or directory.\n", args[1]);
        return env;
    }
    env = my_setenv(env, "OLDPWD", my_getenv("PWD", env));
    free(current_fp);
    new_fp = get_pwd();
    env = my_setenv(env, "PWD", new_fp);
    free(new_fp);
    return env;
}

char **cd_nothing(char **env)
{
    char *new_fp = NULL;
    chdir(my_getenv("HOME", env));
    env = my_setenv(env, "OLDPWD", my_getenv("PWD", env));
    new_fp = get_pwd();
    env = my_setenv(env, "PWD", new_fp);
    free(new_fp);
    return env;
}

char **my_cd(char **env, char **args)
{
    char *current_fp = NULL;
    int len_args = my_arraylen(args);

    if (len_args > 2) {
        write(2, "cd: Too many arguments\n", 24);
        return env;
    }
    if (len_args == 1 || (len_args == 2 && my_strlen(args[1]) == 1 &&
        args[1][0] == '~')) {
        env = cd_nothing(env);
        return env;
    }
    current_fp = get_pwd();
    if (args[1][0] == '-' && my_strlen(args[1]) == 1) {
        env = cd_minus(env, current_fp);
    } else
        env = cd_dir(env, args, current_fp);
    return env;
}
