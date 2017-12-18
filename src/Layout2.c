/*
** EPITECH PROJECT, 2017
** PRS_Codingstyle_2017
** File description:
**	__DESCRIPTION__
*/
#include "EpiStyle.h"

int check_return(char *line, int i)
{
        char *str = malloc(sizeof(*str));
        char *ret = "return";
        int k = 0;

        memcpy(str, line, strlen(line) + 1);
        while(!isalpha(*line) && *line != '\0')
                line++;
        for(k = 0; line[k] == ret[k]; k++);
        if (k == 6) {
                if (line[k] == '(') {
                        my_printf("      line %d : L3 Spaces\n", i);
                        my_printf("     %s", str);
                        return (EXIT_FAULT);
                }
        }
        return (EXIT_SUCCESS);
}

int check_brackets(char *line, int i)
{
        int j = 0;

        while(!isalpha(line[j]) && line[j] != '\0')
                j++;
        if (line[j] == 'i' && line[++j] == 'f' && !isalpha(line[++j])) {
                while (line[j] != '\0') {
                        if (line[j] == '}') {
                                my_printf("      line %d : L4 Curly Brackets\n", i);
                                my_printf("     %s", line);
                                return (EXIT_FAULT);
                        }
                        j++;
                }
        }
        return (EXIT_SUCCESS);
}

int check_brackets2(char *line, int i)
{
        int j = 0;

        while(!isalpha(line[j]) && line[j] != '\0')
                j++;
        if (line[j] == 'i' && line[++j] == 'f' && !isalpha(line[++j])
        && line[j] != ' ') {
                my_printf("      line %d : L4 Curly Brackets\n", i);
                my_printf("     %s", line);
                return (EXIT_FAULT);
        }
        return (EXIT_SUCCESS);
}
