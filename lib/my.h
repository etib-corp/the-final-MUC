/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** all lib
*/

#ifndef MY_H_
    #define MY_H_

    #include <stddef.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include "list.h"

    #define MY_FREE_VA(x, method, ...) \
    do { \
        if ((x) != NULL) { \
            method((x), __VA_ARGS__); \
            (x) = NULL; \
        } \
    } while (0)

    #define MY_FREE(x, method) \
    do { \
        if ((x) != NULL) { \
            method((x)); \
            (x) = NULL; \
        } \
    } while (0)


typedef struct flags {
    char c;
    int (*func)(va_list *, int fd);
} flags_t;

char *str_nrm(char *s, int n);
void *my_calloc(size_t len, size_t size);
bool my_is_digit(char str);
char *my_strchr(char *str, char c);
void **append_array(void *str, void **array, int len);
char *my_strstr(char *str, char const *to_find);
char *creatpath(char *node, char *path);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int len);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *str);
char *my_memset(char *s, int j, int size);
char **my_str_to_word_array(char *str, char *token);
int mini_printf(char const *format, int fd, ...);
int my_printdigits(va_list *list, int fd);
int my_put_nbr(int nb, int fd);
int my_va_putstr(va_list *l, int fd);
int my_putstr(char const *str, int fd);
int my_va_putchar(va_list *l, int fd);
int my_putchar(char c, int fd);
int skip(char c, char *token);
size_t my_lennbr(size_t nb);
void my_swap(char *a, char *b);
char *my_revstr(char *str);
char *my_itoa(size_t nb);

#endif /* MY_H_ */
