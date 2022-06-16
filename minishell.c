/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** minishell
*/

#include "my.h"

void run_program(char **args, char **env)
{
    pid_t fork_val = fork();
    int status;
    int ret;

    if (fork_val == 0) {
        ret = execve(args[0], args, env);
        if (ret == -1)
            check_dir(args[0]);
        exit(0);
    } else if (fork_val > 0) {
        waitpid(fork_val, &status, 0);
        if (status == 139)
            my_puterr("Segmentation fault\n");
    }
    free_array(args);
}

void built_in(char **args, char **env)
{
    char **bins = my_str_to_word_array(my_getenv("PATH", env), ':');
    char *prog_fp = NULL;
    for (int i = 0; bins[i] != NULL && prog_fp == NULL; i++) {
        prog_fp = get_prog_fp(args[0], bins[i]);
    }
    if (prog_fp == NULL)
        my_printf_err("%s: command not found.\n", args[0]);
    else {
        args[0] = prog_fp;
        run_program(args, env);
    }
}

char **check_da_program(char *tmp, char **env)
{
    char **args = create_wordarray(tmp, " \t");
    operator_t *operator = get_operators(operator, args);
    stdout_to_file(operator);
    for (int i = 0; i < 4; i++) {
        if (my_strcmp(flag_TAB[i].attrib, args[0]) == 0) {
            env = flag_TAB[i].find(env, args);
            file_to_stdout(operator);
            return env;
        }
    }
    if (count_occurences(args[0], '/') != 0)
        run_program(args, env);
    else
        built_in(args, env);
    file_to_stdout(operator);
    return env;
}

char **ready_for_program(char *tmp, char **env)
{
    char **cmds = NULL;

    if (my_strlen(tmp) == 1 && tmp[0] == '\n')
        return env;
    tmp = remove_n(tmp);
    if (check_multiple_cmds(tmp) == 1) {
        cmds = my_str_to_word_array(tmp, ';');
        for (int i = 0; cmds[i] != NULL; i++) {
            check_da_program(cmds[i], env);
        }
        return env;
    }
    check_da_program(tmp, env);
    return env;
}

int my_minishell(char **env)
{
    int b;
    int val;
    char *tmp = NULL;
    size_t buf = 32;
    
    do {
        write(1, "$> ", 3);
        val = getline(&tmp, &buf, stdin);
        if (check_exit(tmp, val) == 0)
            return 0;
        env = ready_for_program(tmp, env);
    } while (b);
    my_free(env);
    return 0;
}
