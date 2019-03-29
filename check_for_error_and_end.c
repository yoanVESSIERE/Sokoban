/*
** EPITECH PROJECT, 2018
** check_for_error_and_end.c
** File description:
** 
*/
#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>

int check_window(int len, char *buff)
{
    int x;
    int y;
    int i;

    for (i = 0; buff[i] != '\0'; i++);
    i = i / len;
    getmaxyx(stdscr, y, x);
    if (x < len || y < i) {
        clear();
        erase();
        mvprintw(y/2, (x - 27) / 2,"PLEASE RESIZE YOUR WINDOW");
        refresh();
    }
    else
        printw("%s", buff);
    return (0);
}

int error_count(int *error, char *buff, int i)
{
    if (buff[i] == 'O')
        error[0]++;
    if (buff[i] == 'X')
        error[1]++;
    if (buff[i] == 'P')
        error[2]++;
    if (buff[i] != 'O' && buff[i] != 'X' && buff[i] != 'P' && \
    buff[i] != '#' && buff[i] != ' ' && buff[i] != '\n')
        error[3]++;
    return (0);
}

int check_error(char *buff)
{
    int i;
    int error[4] = {0};

    for (i = 0; buff[i] != '\0'; i++)
        error_count(error, buff, i);
    if (error[0]!= error[1]|| error[2]!= 1 || error[0]== 0 || error[1]== 0 \
    || i < 18 || error[3]!= 0) {
        putstr("INVALID_MAP\n");
        exit(INVALID_MAP);
    }
    return (0);
}

int player_start_and_sokoban_end(char *buff, int *tab)
{
    int i = 0;

    for (i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == 'O')
            tab[2] += 1;
        if (buff[i] == 'P')
            tab[1] = i;
        if (buff[i] == 'X')
            tab[6] += 1;
    }
    return (0);
}

int end(int *tab)
{
    if (tab[2] == tab[3])
        exit(0);
    else
        exit(1);
    return (0);
}