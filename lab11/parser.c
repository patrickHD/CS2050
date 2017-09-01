/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 4/29/2015
    Lab section: G
    Sub code: The End
    CS2050 Lab11
*/

#include "parser.h"
#define MAX_STR_LEN 20

int is_phone_number(char *word)
{
    if(word[0]!='(')
    {
        return 0;
    }
    int i;
    for(i=1; i<4; i++)
    {
        if(isdigit(word[i])==0)
        {
            return 0;
        }
    }
    if(word[4]!=')')
    {
        return 0;
    }
    if(word[5]!='-')
    {
        return 0;
    }
    for(i=6; i<9; i++)
    {
        if(isdigit(word[i])==0)
        {
            return 0;
        }

    }
    if(word[9]!='-')
    {
        return 0;
    }
    for(i=10; i<14; i++)
    {
        if(isdigit(word[i])==0)
        {
            return 0;
        }
    }
    return 1;
}

int is_date(char* word)
{
    if(isdigit(word[0])==0 || word[2]!='/' || word[5]!='/')
    {
        return 0;
    }
    char* tmp=malloc(sizeof(char)*5);
    int day, mon;
    tmp[0]=word[0];
    tmp[1]=word[1];
    tmp[2]='\0';
    mon=atoi(tmp);
    tmp[0]=word[3];
    tmp[1]=word[4];
    tmp[2]='\0';
    day=atoi(tmp);
    if((mon==1 || mon==3 || mon==5 || mon==7 || mon==8 || mon==10 || mon==12) && day>31)
    {
        return 0;
    }
    if((mon==4 || mon==6 || mon==9 || mon==11) && day > 30)
    {
        return 0;
    }
    if(mon==2 && day>28)
    {
        return 0;
    }
    return 1;
}

int looks_like_name(const char* word)
{
    if(isalpha(word[0])==1)
        {return 1;}
    else
        {return 0;}
}

int is_email(char* word)
{
    int i, len, at;
    char* temp=malloc(sizeof(char)*30);
    len=strlen(word);
    int found=0;
    for(i=0; i<len; i++)
    {
        if(word[i]=='@')
        {
            found = 1;
        }
    }
    if(found==1)
    {
        for(i=0; i<len; i++)
        {
            if(word[i]=='@')
            {
                at=i;
            }
        }
        for(i=0; i<at; i++)
        {
            temp[i]=word[i];
        }
        temp[at+1]='\0';
        for(i=0; i<strlen(temp); i++)
        {
            if(isalnum(temp[i])==0)
                return 0;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
