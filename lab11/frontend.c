/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 4/29/2015
    Lab section: G
    Sub code: The End
    CS2050 Lab11
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "parser.h"
#define MAX_LINE 250

int main(int argc, char* argv[])
{
    if(argc<2)
    {
        printf("Not enough arguments.\n");
        return 0;
    }
    FILE* fp=fopen(argv[1], "r");
    char buffer[MAX_LINE];
    int numwords=0;
    int nflag=0;
    char* tmp=malloc(sizeof(char)*30);
    while(fgets(buffer, MAX_LINE, fp))
    {
        buffer[strlen(buffer)-1]='\0';
        char* token=strtok(buffer, " \n\r\t");
        while(token!=NULL)
        {
            if(is_phone_number(token)==1)
            {
                printf("Phone number: %s\n", token);
            }
            else if(is_date(token)==1)
            {
                printf("Date: %s\n", token);
            }
            else if(is_email(token)==1)
            {
                printf("Email: %s\n", token);
            }
            else if(looks_like_name(token)==1)
            {
                if(nflag==0)
                {
                    strcpy(tmp,token);
                    nflag=1;
                }
                else
                {
                    printf("Name: %s %s \n", tmp, token);
                    nflag=0;
                }
            }
            else
            {
                nflag=0;
            }
            token=strtok(NULL, " \n\r\t");
            numwords++;
        }
    }
    printf("There are %d words in the file\n", numwords);
    return 0;
}
