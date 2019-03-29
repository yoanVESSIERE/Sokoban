/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** 
*/
#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>

int file_open(char *av[]);

int moving(char *buff, int *O, int *tab)
{
    tab[0] = lenth(buff, tab[1]);
    switch (getch()) {
        case 'A':
            move_up(buff, O, tab);
            break;
        case 'B':
            move_down(buff, O, tab);
            break;
        case 'C':
            move_right(buff, O, tab);
            break;
        case 'D':
            move_left(buff, O, tab);
            break;
        case ' ':
            return (-1);
            break;
    }
    return (tab[1]);
}

int out(int *tab, char *av[])
{
    if (tab[1] == -1) {
        clrefrsh();
        file_open(av);
        tab[4] += 1;
        }
    if (tab[2] == tab[3] || tab[6] == 0) {
        clrefrsh();
        tab[4] += 1;
    }
        return (0);
}

int maping(char *buff, char *av[], int len)
{
    int O = 0;
    int tab[7] = {len, 0, 0, 0, 0, 0, 0};

    player_start_and_sokoban_end(buff, tab);
    check_error(buff);
    initscr();
    while (1) {
        check_window(len, buff);
        tab[1] = moving(buff, &O, tab);
        out(tab, av);
        if (tab[4] != 0){
            printw("%s", buff);
            refresh();
            break;
        }
        clrefrsh();
    }
    endwin();
    end(tab);
    return (0);
}

int file_open(char *av[])
{
    int file = 0;
    int buff_size = 50000;
    char buff[buff_size + 1];
    int len = 0;

    file = open(av[1], O_RDONLY);
    read(file, buff, buff_size);
    buff[buff_size] = '\0';
    close(file);
    for (len = 0; buff[len] != '\n'; len++);
    len += 1;
    maping(buff, av, len);
    return (0);
}

int main(int ac, char *av[])
{
    if (ac != 2 || (ac == 1 && av[1][0] == '-' && av[1][1] == 'h')) {
        putstr("LESS_OR_MORE_ARG\n");
        exit(LESS_OR_MORE_ARG);
    }
    if ((av[1][0] == '-') && (av[1][1] == 'h')) {
        putstr("USAGE\n     ./my_sokoban map\n");
        putstr("DESCRIPTION\n");
        putstr("     map  file representing the warehouse map, containing");
        putstr("'#' for walls,\n");
        putstr("     'P' for the player, 'X' for boxes and 'O' for storage");
        putstr(" locations.\n");
        return (0);
    }
    if (open(av[1], O_RDONLY) == -1) {
        putstr("OPEN_ERROR");
        exit(OPEN_ERROR);
        close(*av[1]);
    }
    file_open(av);
    return (0);
}
