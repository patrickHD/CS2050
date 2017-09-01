/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 2/11/2015
    Lab section: G
    Sub code: DATA STRUXTURE
    CS2050 Lab3
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LEN 20

typedef struct{
    int accountID;
    char* name;
    double amount;
} account;

account* load_accounts(char* inputFile, int* size);
account* find_accounts(account* accounts, int size, int accountID);
void update_accounts(char* updateFile, account* accounts, int size);
void write_accounts(char* outputFile, account* accounts, int size);
void free_accounts(account* accounts, int size);

/* main runs the created functions and preforms the necessary operations*/
int main(int argc, char** argv)
{
    if(argc<3)
    {
        printf("Not enough arguments.\n");
        return 0;
    }

    int size;
    account* accounts;
    accounts=load_accounts(argv[1], &size);
    update_accounts(argv[2], accounts, size);
    write_accounts(argv[3], accounts, size);
    return 0;
}

/* load_accounts creates an array to the old the accounts and reads the input data into it */
account* load_accounts(char* inputFile, int* size)
{
    int i;
    FILE* input=fopen(inputFile, "r");
    fscanf(input, "%d", size);

    account *accounts=malloc(sizeof(account)*(*size));
    for(i=0; i<(*size); i++)
    {
        accounts[i].name=malloc(sizeof(char)*MAX_STRING_LEN);
        fscanf(input,"%d %s %lf", &accounts[i].accountID, accounts[i].name, &accounts[i].amount);
    }
    return accounts;
}

/*find_accounts searches for an account with the specified ID*/
account* find_accounts(account* accounts, int size, int accountID)
{
    int i;
    for(i=0; i<size; i++)
    {
        if(accounts[i].accountID==accountID)
        {
            return &accounts[i];
        }
    }
    return NULL;
}

/* update_accounts uses find_accounts to update the account amounts using an update file*/
void update_accounts(char* updateFile, account* accounts, int size)
{
    int i, sizeX;
    int UaccID;
    double Uamnt;

    FILE* updateF=fopen(updateFile, "r");
    fscanf(updateF, "%d", &sizeX);
    account *Pacc;

    for(i=0; i<sizeX; i++)
    {
        fscanf(updateF, "%d %lf", &UaccID, &Uamnt);
        if(find_accounts(accounts, sizeX, UaccID)!=NULL)
        {
            Pacc=find_accounts(accounts, sizeX, UaccID);
            (*Pacc).amount=(*Pacc).amount+Uamnt;
        }
    }
}
/* write accounts writes the final data to a file */
void write_accounts(char* outputFile, account* accounts, int size)
{
    int i;
    FILE* outputF=fopen(outputFile, "w");
    for(i=0; i<size; i++)
    {
        fprintf(outputF, "%d %s %lf\n", accounts[i].accountID, accounts[i].name, accounts[i].amount);
    }
}

void free_accounts(account* accounts, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        free(accounts[i].name);
    }
    free(accounts);
}
