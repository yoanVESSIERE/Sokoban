/*
** EPITECH PROJECT, 2018
** function.c
** File description:
** 
*/
#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}

void clrefrsh(void)
{
    clear();
    refresh();
}

int lenth(char *buff, int e)
{
    int i = e;
    int j = e;
    int res;

    for (; buff[i] != '\n'; i++);
    for (; buff[j] != '\n'; j--);
    res = i - j;
    return (res);
}