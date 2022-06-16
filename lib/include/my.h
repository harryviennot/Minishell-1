/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my
*/

#ifndef LIB_HEADER
    #define LIB_HEADER

    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdarg.h>

    int my_arraylen(char **str);
    void my_printf(char *string, ...);
    void my_put_nbr(int nb);
    void my_putchar(char c);
    void my_putstr(char *str);
    char **my_str_to_word_array(char *str, char separator);
    int my_strncmp(const char *data_1, char const *data_2, int n);
    int my_strcmp(const char *data_1, char const *data_2);
    char *my_strdup(const char *str);
    char *my_strndup(const char *str, int n);
    char *my_strndupafter(const char *str, int n);
    int my_strlen(char const *str);
    int my_strstr(char *str, char *to_find);
    void *my_memcpy(void *dest, const void *src, int len);
    char *my_strcat(char *dest, const char *src);
    char *my_strcpy(char *dest, const char *src);
    int count_occurences(char *str, char c);
    void my_free(char **array);
    void my_puterr(char *str);
    char *my_cleanstr(char *str);
    char **my_quote_array(char *str, char separator);
    char **create_wordarray(char *str, char *separators);
    void free_array(char **array);
    void my_put_nbr_err(int nb);
    void my_putchar_err(char c);
    void my_printf_err(char *string, ...);

#endif
