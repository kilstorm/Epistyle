//
// EPITECH PROJECT, 2017
// my_printf
// File description:
//	__DESCRIPTION__
//
#ifndef LIBMY_H
#define LIBMY_H

#define LBITS 0x101010101010101L
#define HBITS 0x8080808080808080L
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int my_atoi(char *str);
void my_bzero(void *s, size_t n);
double my_pow(double n, int pow);
void *my_memchr(const void *mem, const unsigned char c,
					size_t n);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_memset(void *s, int c, size_t n);
char *my_strchr(const char *s, int c);
int my_strchri(char *s, int c, int i);
int my_strchri_lu(char *s, int c, int i);
size_t my_strlen(const char *str);
int my_strncmp(const char *s1, const char *s2, size_t n);
size_t my_wcharlen(unsigned c);
size_t my_wstrlen(unsigned *s);

#endif
