/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** get
*/

#include "my.h"

int check_if_same(char *file, char *program)
{
    if (my_strcmp(file, program) == 0)
        return 1;
    else
        return 0;
}

int get_name_index(char *str, char **env)
{
    int i;
    int b = 500;

    for (i = 0; env[i] != NULL && b != 0; i++) {
        b = my_strncmp(str, env[i], my_strlen(str) - 1);
    }
    if (b == 500)
        return -1;
    return i - 1;
}

char *get_prog_fp(char *program, char *dirpath)
{
    char *file;
    char *filepath = NULL;
    int a = 0;
    DIR *d;
    struct dirent *dir;
    d = opendir(dirpath);
    if (d) {
        while ((dir = readdir(d)) != NULL && a == 0) {
            file = dir->d_name;
            a = check_if_same(file, program);
        }
    }
    if (a == 1)
        filepath = concatenate(dirpath, file);
    closedir(d);
    return filepath;
}

char *my_getenv(char *str, char **env)
{
    int i;
    int b = 1;
    int len = my_strlen(str);
    char *result = NULL;

    for (i = 0; env[i] != NULL && b != 0; i++) {
        b = my_strncmp(str, env[i], len - 1);
    }
    if (b == 0)
        result = my_strndupafter(env[i - 1], len + 1);
    return result;
}

char *get_pwd(void)
{
    char *tmp;
    size_t buf = 255;

    tmp = malloc(sizeof(char) * 255);
    getcwd(tmp, buf);
    return tmp;
}
