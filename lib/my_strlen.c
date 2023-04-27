/*
** EPITECH PROJECT, 2023
** mystrlen
** File description:
** mystrlen
*/

int my_strlen(char const *str)
{
    int i = 0;
    int count = 0;
    while (str[i] != '\0') {
        count = count + 1;
        i = i + 1;
    }
    return count;
}
