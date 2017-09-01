/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 4/29/2015
    Lab section: G
    Sub code: The End
    CS2050 Lab11
*/

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "parser.h"

int is_phone_number(char *word);
int is_date(char* word);
int looks_like_name(const char* word);
int is_email(char* word);

#endif // PARSER_H_INCLUDED
