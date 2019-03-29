/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** 
*/

#define LESS_OR_MORE_ARG 84
#define OPEN_ERROR       84
#define INVALID_MAP      84

#ifndef VAR
#define VAR

void my_putchar(char c);

int putstr(char const *str);

int move_up(char *buff, int *O, int *tab);

int move_down(char *buff, int *O, int *tab);

int move_right(char *buff, int *O, int *tab);

int move_left(char *buff, int *O, int *tab);

void clrefrsh(void);

int end(int *tab);

int player_start_and_sokoban_end(char *buff, int *tab);

int check_error(char *buff);

int check_window(int len, char *buff);

int lenth(char *buff, int e);

#endif