/*
** EPITECH PROJECT, 2017
** PRS_Codingstyle_2017
** File description:
**      main.c correction coding style
*/
#include "EpiStyle.h"

int count_columns(char *line, int i, ssize_t read)
{
        if (read > 80) {
                my_printf("      line %d : ", i, read);
		my_printf("F3 numbers of columns %zu :\n");
                my_printf("     %s", line);
        }
        return (EXIT_SUCCESS);
}

int detect_fault(char *line, int i, ssize_t read)
{
        int c = 0;
        if (detect_comment(line) == EXIT_COMMENT)
                return (EXIT_SUCCESS);
        c += count_columns(line, i, read);
        c += check_one_statement(line, i);
        return (c);
}

int Epidetect(char *str)
{
        FILE *f;
        int i = 0;
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        int c = 0;

        my_printf(GREEN "[FILE]" RESET CYAN" %s\n" RESET, str);
        f = fopen(str, "r");
        read = getline(&line, &len, f);
        if (f == NULL)
                return (EXIT_FAILED);
        while (read != -1) {
                i++;
                c += detect_fault(line, i, read);
                read = getline(&line, &len, f);
        }
        if (c != 0)
                my_printf("\n");
        free(line);
        fclose(f);
        return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
        for (int i = 1; i < argc; i++) {
                if (Epidetect(argv[i]) == EXIT_FAILED)
                        return (EXIT_FAILED);
                }
}
