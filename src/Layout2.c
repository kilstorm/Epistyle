/*
** EPITECH PROJECT, 2017
** PRS_Codingstyle_2017
** File description:
**	__DESCRIPTION__
*/
#include "EpiStyle.h"

int check_return(char *line, int i)
{
	size_t len = my_strlen(line);
	char *str = (char*)malloc(sizeof(char) * len + 2);
	char *ret = "return";
	int k = 0;

	strcpy(str, line);
	while(!isalpha(*line) && *line != '\0')
		line++;
	for(k = 0; line[k] == ret[k]; k++);
	if (k == 6) {
		if (line[k] == '(') {
			my_printf("      line %d : L3 Spaces\n", i);
			my_printf("     %s", str);
			free(str);
			return (EXIT_FAULT);
		}
	}
	free(str);
	return (EXIT_SUCCESS);
}

int check_brackets2(char *line, int i)
{
	int j = 0;

	j = detect_alpha(line);
	if (line[j] == 'i' && line[++j] == 'f' && !isalpha(line[++j])
	&& line[j] != ' ') {
		my_printf("      line %d : L4 Curly Brackets\n", i);
		my_printf("     %s", line);
		return (EXIT_FAULT);
	}
	return (EXIT_SUCCESS);
}
