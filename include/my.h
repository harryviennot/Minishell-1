/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <dirent.h>
    #include <stdarg.h>
    #include <signal.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "../lib/include/my.h"

    typedef struct {
        char *redir;
        char *filename;
        char **args;
        int pipes;
        int save_out;
        int save_in;
        int fd;
    } operator_t;

    int my_minishell(char **env);
    char *remove_n(char *tmp);
    char **my_cd(char **args, char **env);
    char **my_ready_setenv(char **args, char **env);
    char **my_setenv(char **env, char *name, char *var);
    char **my_unsetenv(char **args, char **env);
    char *remove_p(char *str);
    char **get_bins(char **env);
    void run_program(char **args, char **env);
    char *get_prog_fp(char *program, char *dirpath);
    char *concatenate(char *strg1, char *strg2);
    char *my_getenv(char *str, char **env);
    char **p_my_env(char **env, char **args);
    int get_name_index(char *str, char **env);
    char *get_pwd(void);
    int check_existing_file(char *filep, char *given_file);
    void check_dir(char *filepath);
    int check_multiple_cmds(char *line);
    int check_exit(char *str, int val);
    operator_t *get_operators(operator_t *operator, char **args);
    void stdout_to_file(operator_t *operator);
    void file_to_stdout(operator_t *operator);

    struct flag {
        char *attrib;
        char **(*find)(char **, char **);
    };

    static struct flag const flag_TAB[] = {
        {"cd", &my_cd},
        {"setenv", &my_ready_setenv},
        {"unsetenv", &my_unsetenv},
        {"env", &p_my_env},
    };

#endif
