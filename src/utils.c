/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/
#include "EpiStyle.h"

int detect_comment(char *line)
{
	int j = 0;

	while (line[j] != '\0') {
		if (line[j] == '/' || line[j] == '*') {
			j++;
			if (line[j] == '/' || line[j] == '*')
				return (EXIT_COMMENT);
		}
		j++;
	}
	return (EXIT_SUCCESS);
}

int detect_for(char *line)
{
	char *ret = "for";
	int k = 0;

	while(!isalpha(*line) && *line != '\0')
		line++;
	for(k = 0; line[k] == ret[k]; k++);
	if (k == 3)
		return (EXIT_FOR);
	return (EXIT_SUCCESS);
}

int detect_alpha(char *line)
{
	int j = 0;

	while(!isalpha(line[j]) && line[j] != '\0')
		j++;
	return (j);
}
