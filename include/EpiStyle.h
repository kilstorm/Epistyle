//
// EPITECH PROJECT, 2017
// PRS_Codingstyle_2017
// File description:
//	__DESCRIPTION__
//

#ifndef EPISTYLE_H_
#define EPISTYLE_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define EXIT_SUCCESS 0
#define EXIT_FAULT 1
#define EXIT_FAILED 84
#define EXIT_FOR 1
#define EXIT_COMMENT 2
#define EXIT_MALLOC 84

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define BROWN  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

/*---------------Main-----------------*/

int Epidetect(char *str);
int detect_fault(char *line, int i, ssize_t read);

/*---------------Layout---------------*/

int check_one_statement(char *line, int i);
int check_aftersemicolon(char *line, int i);
int check_equal(char *line, int i);
int check_return(char *line, int i);
int check_brackets2(char *line, int i);

/*---------------Utils---------------*/

int detect_comment(char *line);
int detect_for(char *line);
int detect_alpha(char *line);
int count_columns(char *line, int i, ssize_t read);

/*--------------Variable-------------*/


#endif
