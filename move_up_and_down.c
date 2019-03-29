/*
** EPITECH PROJECT, 2018
** move_up_and_down.c
** File description:
** 
*/
#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>

int move_up_bis(char *buff, int *tab)
{
    if ((buff[tab[1] - tab[0] * 3] == '#' && \
    (buff[tab[1] - tab[0] * 2 - 1] == '#' || \
    buff[tab[1] - tab[0] * 2 + 1] == '#') && buff[tab[1] - tab[0] * 2] != 'O'))
        tab[6] += -1;
    if (buff[tab[1] - tab[0] * 2] == 'O')
        tab[3]++;
    buff[tab[1] - tab[0] * 2] = 'X';
    return (0);
}

int move_up(char *buff, int *O, int *tab)
{
    if ((buff[tab[1] - tab[0]] != '#' && buff[tab[1] - tab[0]] != 'X') || \
    (buff[tab[1] - tab[0] * 2] != '#' && buff[tab[1] - tab[0]] == 'X' && \
    buff[tab[1] - tab[0] * 2] != 'X') || (buff[tab[1] - tab[0]] != '#' && \
    buff[tab[1] - tab[0]] != 'X' && buff[tab[1] - tab[0] * 2] != 'X')) {
        if (buff[tab[1] - tab[0]] == 'X' && buff[tab[1] - tab[0] * 2] != '#' \
        && buff[tab[1] - tab[0] * 2] != 'X')
            move_up_bis(buff, tab);
        buff[tab[1]] = ' ';
        if (*O == 1) {
            buff[tab[1]] = 'O';
            *O = 0;
        }
        if (buff[tab[1] - tab[0]] == 'O')
            *O = 1;
        buff[tab[1] - tab[0]] = 'P';
        tab[1] = tab[1] - tab[0];
    }
    return (0);
}

int move_down_bis(char *buff, int *tab)
{
    if ((buff[tab[1] + tab[0] * 3] == '#' && \
    (buff[tab[1] + tab[0] * 2 - 1] == '#' || \
    buff[tab[1] + tab[0] * 2 + 1] == '#') && \
    buff[tab[1] + tab[0] * 2] != 'O'))
        tab[6] += -1;
    if (buff[tab[1] + tab[0] * 2] == 'O')
        tab[3]++;
    buff[tab[1] + tab[0] * 2] = 'X';
    return (0);
}

int move_down(char *buff, int *O, int *tab)
{
    if ((buff[tab[1] + tab[0]] != '#' && buff[tab[1] + tab[0]] != 'X') || \
    (buff[tab[1] + tab[0] * 2] != '#' && buff[tab[1] + tab[0]] == 'X' && \
    buff[tab[1] + tab[0] * 2] != 'X') || (buff[tab[1] + tab[0]] != '#' && \
    buff[tab[1] + tab[0]] != 'X' && buff[tab[1] + tab[0] * 2] != 'X')) {
        if (buff[tab[1] + tab[0]] == 'X' && buff[tab[1] + tab[0] * 2] != '#' \
        && buff[tab[1] + tab[0] * 2] != 'X')
            move_down_bis(buff, tab);
        buff[tab[1]] = ' ';
        if (*O == 1) {
            buff[tab[1]] = 'O';
            *O = 0;
        }
        if (buff[tab[1] + tab[0]] == 'O')
            *O = 1;
        buff[tab[1] + tab[0]] = 'P';
        tab[1] = tab[1] + tab[0];
    }
    return (0);
}