/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 2/15/2015
    Lab section: G
    CS2050 Homework 1
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LEN 20
#include <string.h>

typedef struct {
    int year;
    char* make;
    char* model;
    int miles;
} Car;

void fill_garage(Car** garage, char* cars, int* num_cars);
int equals (Car* car, int year, char* make, char* model);
void drive_cars(Car* garage, int* num_cars, char* driving_records);
void store_car_statisitcs(Car* garage, int num_cars, char* outFile);
void empty_garage(Car* garage, int num_cars);
/*Main takes in the names of the three files as command line arguments and then acts
as a driver to call the other functions.*/
int main(int argc, char** argv)
{
    if(argc<2)
    {
        printf("Not enough arguments\n");
        return -1;
    }
    Car* garage=NULL;
    int num_cars;

    fill_garage(&garage, argv[1], &num_cars);
    drive_cars(garage, &num_cars, argv[2]);
    store_car_statisitcs(garage, num_cars, argv[3]);
    empty_garage(garage, num_cars);
    return 0;
}
/*This function will dynamically create an array to hold the cars and read the contents of
the input file into it.*/
void fill_garage(Car** garage, char* cars, int* num_cars)
{
    int i;
    FILE* inputF=fopen(cars, "r");

    if(inputF==NULL)
    {
        printf("Error opening file \n");
        return;
    }
    fscanf(inputF, "%d", num_cars);
    *garage=malloc(sizeof(Car)*(*num_cars));

    for(i=0; i< *num_cars; i++)
    {
        (*garage)[i].make=malloc(sizeof(char)*MAX_STRING_LEN);
        (*garage)[i].model=malloc(sizeof(char)*MAX_STRING_LEN);
        fscanf(inputF, "%d %s %s %d", &(*garage)[i].year, (*garage)[i].make, (*garage)[i].model, &(*garage)[i].miles);
    }

    fclose(inputF);
}
/*This function will determine if the provided car has the specified year, make, and model*/
int equals(Car* car, int year, char* make, char* model)
{
    if(strcmp((*car).make, make)==0 && (*car).year==year && strcmp((*car).model, model)==0)
    {
        return 1;
    }
    return 0;
}
/*This function will read from the file specified by the driving_records parameter and on
each line read in a year, make, model, and number of miles driven. It will then add the
number of miles to the specified car.*/
void drive_cars(Car* garage, int* num_cars, char* driving_records)
{
    int i=0;
    int new_cars, Uyear, Umiles;

    FILE* updateF=fopen(driving_records, "r");
    fscanf(updateF, "%d", &new_cars);

    char* Umake=malloc(sizeof(char)*MAX_STRING_LEN);
    char* Umodel=malloc(sizeof(char)*MAX_STRING_LEN);

    for(i=0; i<new_cars; i++)
    {
        fscanf(updateF, "%d %s %s %d", &Uyear, Umake, Umodel, &Umiles);
        if(equals(garage, Uyear, Umake, Umodel)==1)
        {
            garage[i].miles+=Umiles;
        }
    }
}
/*Write the car statistics to the output file.*/
void store_car_statisitcs(Car* garage, int num_cars, char* outFile)
{
    int i;
    FILE* outF=fopen(outFile, "w");

    for(i=0; i<num_cars; i++)
    {
        fprintf(outF, "The %d %s %s drove %d miles\n", garage[i].year, garage[i].make, garage[i].model, garage[i].miles);
    }
    fclose(outF);
}
/*Frees all malloced memory*/
void empty_garage(Car* garage, int num_cars)
{
    int i;
    for(i=0; i<num_cars; i++)
    {
        free(garage[i].make);
        free(garage[i].model);
    }
    free(garage);
}
