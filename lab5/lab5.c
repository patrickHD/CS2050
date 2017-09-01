/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 3/4/2015
    Lab section: G
    Sub code: recursion
    CS2050 Lab5
*/

#include <stdio.h>
#include <stdlib.h>

int* load_array(char* file, int* length);
void insertion_sort(int array[], int length);
int binary_search(int array[], int low, int high, int key);
int fib(int n);
int range(int array[], int length, int low, int high);


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Incorrect number of command line arguments\n");
        printf("Correct usage: %s <number list>\n", argv[0]);
    }
    int length, i;
    int* array;
    array=load_array(argv[1], &length);
    insertion_sort(array, length);
    for(i=0; i<length; i++)
    {
        array[i]=fib(array[i]);
        printf("%d\n", array[i]);
    }
    int search;
    printf("Enter a number to search for: "); scanf("%d", &search);
    if(binary_search(array, 0, length, search)==-1)
    {printf("%d not found\n", search);}
    else
    {printf("%d was found at index %d\n", search, binary_search(array, 0, length, search));}
    int lo, hi;
    printf("Bonus: Enter a range to search for.\n");
    printf("Low:  "); scanf("%d", &lo);
    printf("High: "); scanf("%d", &hi);
    int rang=range(array, length, lo, hi);
    printf("There are %d numbers between %d and %d inclusively.\n", rang, lo, hi);
    return 0;
}

int* load_array(char* file, int* length)
{
    int i;
    FILE* inputF = fopen(file, "r");
    fscanf(inputF, "%d", length);
    int *array;
    array=malloc(sizeof(int)*(*length));
    for(i=0; i<*length; i++)
    {
        fscanf(inputF, "%d", &array[i]);
    }
    return array;
}

void insertion_sort(int array[], int length)
{
    int temp, C, i;
    for (i=1; i<length; i++)
    {
        temp=array[i];
        C=i-1;
        while ( (temp < array[C]) && (C>=0) )
        {
            array[C+1] = array[C];
            C=C-1;
        }
        array[C+1]=temp;
   }
}

int binary_search(int array[], int low, int high, int key)
{
    int mid;

    if (low > high)
    {
        return -1;
    }
    mid = (low + high) / 2;
    if (array[mid] == key)
    {
        return mid;
    }
    else if (array[mid] > key)
    {
        binary_search(array, low, mid - 1, key);
    }
    else if (array[mid] < key)
    {
        binary_search(array, mid + 1, high, key);
    }
}

int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return (fib(n-1)+fib(n-2));
    }
}

int range(int array[], int length, int low, int high)
{
    int i, z=0;
    for(i=0; i<length; i++)
    {
        if(array[i]>=low && array[i]<=high)
        {
            z++;
        }
    }
    return z;
}
