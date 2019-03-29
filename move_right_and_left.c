/*
** EPITECH PROJECT, 2018
** move_right_and_left.c
** File description:
** 
*/
#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>

int move_right_bis(char *buff, int *tab)
{
    if ((buff[tab[1] + 1 * 3] == '#' && \
    (buff[tab[1] + 1 * 2 - tab[0]] == '#' || \
    buff[tab[1] + 1 * 2 + tab[0]] == '#') && \
    buff[tab[1] + 1 * 2] != 'O'))
        tab[6] += -1;
    if (buff[tab[1] + 1 * 2] == 'O')
        tab[3]++;
    buff[tab[1] + 1 * 2] = 'X';
    return (0);
}

int move_right(char *buff, int *O, int *tab)
{
    if ((buff[tab[1] + 1] != '#' && buff[tab[1] + 1] != 'X') || \
    (buff[tab[1] + 1 * 2] != '#' && buff[tab[1] + 1] == 'X' && \
    buff[tab[1] + 1 * 2] != 'X') || (buff[tab[1] + 1] != '#' && \
    buff[tab[1] + 1] != 'X' && buff[tab[1] + 1 * 2] != 'X')) {
        if (buff[tab[1] + 1] == 'X' && buff[tab[1] + 1 * 2] != '#' \
        && buff[tab[1] + 1 * 2] != 'X')
            move_right_bis(buff, tab);
        buff[tab[1]] = ' ';
        if (*O == 1) {
            buff[tab[1]] = 'O';
            *O = 0;
        }
        if (buff[tab[1] + 1] == 'O')
            *O = 1;
        buff[tab[1] + 1] = 'P';
        tab[1]++;
    }
    return (0);
}

int move_left_bis(char *buff, int *tab)
{
    if ((buff[tab[1] - 1 * 3] == '#' && \
    (buff[tab[1] - 1 * 2 - tab[0]] == '#' || \
    buff[tab[1] - 1 * 2 + tab[0]] == '#') && \
    buff[tab[1] - 1 * 2] != 'O'))
        tab[6] += -1;
    if (buff[tab[1] - 1 * 2] == 'O')
        tab[3]++;
    buff[tab[1] - 1 * 2] = 'X';
    return (0);
}

int move_left(char *buff, int *O, int *tab)
{
    if ((buff[tab[1] - 1] != '#' && buff[tab[1] - 1] != 'X') || \
    (buff[tab[1] - 1 * 2] != '#' && buff[tab[1] - 1] == 'X' && \
    buff[tab[1] - 1 * 2] != 'X') || (buff[tab[1] - 1] != '#' && \
    buff[tab[1] - 1] != 'X' && buff[tab[1] - 1 * 2] != 'X')) {
        if (buff[tab[1] - 1] == 'X' && buff[tab[1] - 1 * 2] != '#' && \
        buff[tab[1] - 1 * 2] != 'X')
            move_left_bis(buff, tab);
        buff[tab[1]] = ' ';
        if (*O == 1) {
            buff[tab[1]] = 'O';
            *O = 0;
        }
        if (buff[tab[1] - 1] == 'O')
            *O = 1;
        buff[tab[1] - 1] = 'P';
        tab[1]--;
    }
    return (0);
}