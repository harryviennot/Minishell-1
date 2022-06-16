/*
** EPITECH PROJECT, 2022
** B-PSU-101-TLS-1-1-minishell1-harry.viennot
** File description:
** redirect
*/

#include "my.h"

void file_to_stdout(operator_t *operator)
{
    if (operator->redir == NULL)
        return;
    close(operator->fd);
    if (operator->redir[0] == '>')
        dup2(operator->save_out, 1);
    if (operator->redir[0] == '<')
        dup2(operator->save_in, 0);
}

void stdout_to_file(operator_t *operator)
{
    int fd;

    if (operator->redir == NULL)
        return;
    operator->save_out = dup(STDOUT_FILENO);
    operator->save_in = dup(STDIN_FILENO);
    if (my_strcmp(operator->redir, ">") == 0) {
        fd = open(operator->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        dup2(fd, 1);
    }
    if (my_strcmp(operator->redir, ">>") == 0) {
        fd = open(operator->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
        dup2(fd, 1);
    }
    if (my_strcmp(operator->redir, "<") == 0) {
        fd = open(operator->filename, O_RDONLY);
        dup2(fd, 0);
    }
    operator->fd = fd;
}
