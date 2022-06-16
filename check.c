/*
** EPITECH PROJECT, 2022
** B-PSU-101-TLS-1-1-minishell1-harry.viennot
** File description:
** check
*/

#include "my.h"
#include <sys/stat.h>

int check_existing_file(char *filep, char *given_file)
{
    char *file;
    int a = 1;
    DIR *d;
    struct dirent *dir;
    d = opendir(filep);
    if (d) {
        dir = readdir(d);
        while (dir != NULL && a != 0) {
            file = dir->d_name;
            a = my_strcmp(file, given_file);
            dir = readdir(d);
        }
    }
    return a;
}

char get_ftype2(char *filepath, char ftype)
{
    struct stat buf;
    stat(filepath, &buf);
    if (S_ISFIFO(buf.st_mode) == 1)
        ftype = '0';
    if (S_ISLNK(buf.st_mode) == 1)
        ftype = '0';
    if (S_ISSOCK(buf.st_mode) == 1)
        ftype = '0';
    return ftype;
}

char get_ftype(char *filepath)
{
    char ftype = 'n';
    struct stat buf;
    stat(filepath, &buf);
    if (S_ISREG(buf.st_mode) == 1)
        ftype = '0';
    if (S_ISDIR(buf.st_mode) == 1)
        ftype = 'd';
    if (S_ISCHR(buf.st_mode) == 1)
        ftype = '0';
    if (S_ISBLK(buf.st_mode) == 1)
        ftype = '0';
    get_ftype2(filepath, ftype);
    return ftype;
}

void check_dir(char *filepath)
{
    if (get_ftype(filepath) == 'd')
        my_printf_err("%s: Permission denied.\n", filepath);
    else if (get_ftype(filepath) == '0')
        my_printf_err("%s: Permission denied.\n", filepath);
    else
        my_printf_err("%s: Command not found.\n", filepath);
}

int check_exit(char *str, int val)
{
    if (my_strcmp(str, "exit\n") == 0) {
        write(1, "exit\n", 5);
        return 0;
    } else if (val == -1) {
        write(1, "\nexit\n", 6);
        return 0;
    } else
        return 1;
}
