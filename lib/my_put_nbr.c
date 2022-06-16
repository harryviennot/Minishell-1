/*
** EPITECH PROJECT, 2021
** lib
** File description:
** my_printf
*/

#include "my.h"

void my_put_nbr(int nb)
{
    if (nb < 10 && nb >= 0)
        my_putchar(nb + 48);
    else {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
}

void my_put_nbr_err(int nb)
{
    if (nb < 10 && nb >= 0)
        my_putchar_err(nb + 48);
    else {
        my_put_nbr_err(nb / 10);
        my_putchar_err(nb % 10 + 48);
    }
}
