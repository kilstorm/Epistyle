/*
** EPITECH PROJECT, 2017
** PRS_Codingstyle_2017
** File description:
**	__DESCRIPTION__
*/
#include "EpiStyle.h"

int check_one_statement(char *line, int i)
{
        int c = 0;
        c += check_aftersemicolon(line, i);
        c += check_equal(line, i);
        //c += check_virgule(line, i);
        c += check_return(line, i);
        //c += check_brackets(line, i);
        c += check_brackets2(line, i);
        return (c);
}

int check_equal(char *line, int i)
{
        int j = 0;
        int count = 0;

        while (line[j] != '\0') {
                j++;
                if (line[j] == '=')
                        count++;
                if (line[j] == '(' || line[j] == ')')
                        count = 0;
        }
        if (count > 1) {
                my_printf("      line %d : L1 Code Line Content\n", i);
                my_printf("     %s", line);
                return (EXIT_FAULT);
        }
        return (EXIT_SUCCESS);
}

int check_aftersemicolon(char *line, int i)
{
	int j = 0;
        int count = 0;

        if (detect_for(line) == 1)
		return (EXIT_SUCCESS);
        while (line[j] != '\0') {
                j++;
                if (line[j] == ';')
                        count++;
        }
        if (count > 1) {
                my_printf("      line %d : L1 Code Line Content\n", i);
                my_printf("     %s", line);
                return (EXIT_FAULT);
        }
        return (EXIT_SUCCESS);
}

int check_virgule(char *line, int i)
{
        int j = 0;
        int count = 0;

        while (line[j] != '\0') {
                if (line[j] == '(')  {
                        while(line[j] != ')')
                                j++;
                }
                if (line[j] == ',')
                        count++;
                j++;
        }
        if (count > 0) {
                my_printf("      line %d : L1 Code Line Content and L5 Variable Declaration\n", i);
                my_printf("     %s", line);
                return (EXIT_FAULT);
        }
        return (EXIT_SUCCESS);
}
