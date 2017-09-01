#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

typedef struct{
    unsigned long int comparisons;
    unsigned long int swaps;
    long double duration;
}SortStat;

typedef struct{
    int* first;
    int* second;
    int* third;
}Arrays;

Arrays generate_arrays(int len);
SortStat bubble_sort(int array[], int len);
SortStat selection_sort(int array[], int len);
SortStat insertion_sort(int array[], int len);
unsigned long int linear_search(int array[], int len, int key);
unsigned long int binary_search(int array[], int low, int high, int key);

int main(void)
{
    int lsstat, bsstat, len=10;
    while(len <= 10000)
    {
        printf("For arrays of size %d\n", len);
        Arrays arreys=generate_arrays(len);
        SortStat bstat=bubble_sort(arreys.first, len);
        SortStat sstat=selection_sort(arreys.second, len);
        SortStat istat=insertion_sort(arreys.third, len);
        lsstat=linear_search(arreys.second, len, len*2);
        bsstat=binary_search(arreys.first, 0, len, len*2);
        printf("Bubble sort made %ld comparisons, %ld swaps, and took %Lf milliseconds\n", bstat.comparisons, bstat.swaps, bstat.duration);
        printf("Selection sort made %ld comparisons, %ld swaps, and took %Lf milliseconds\n", sstat.comparisons, sstat.swaps, sstat.duration);
        printf("Insertion sort made %ld comparisons, %ld swaps, and took %Lf milliseconds\n", istat.comparisons, istat.swaps, istat.duration);
        printf("Linear search made %d comparisons\n", lsstat);
        printf("Binary search made %d comparisons\n", bsstat);
        printf("\n");
        len*=10;
    }
    return 0;
}

Arrays generate_arrays(int len)
{
    int i, gen;
    Arrays arreys;
    arreys.first=malloc(sizeof(int)*len);
    arreys.second=malloc(sizeof(int)*len);
    arreys.third=malloc(sizeof(int)*len);

    for(i=0; i<len; i++)
    {
        gen=(rand()%(len+1));
        *(arreys.first+i)=gen;  //printf("%d",*(arreys.first+i));
        *(arreys.second+i)=gen; //printf("%d",*(arreys.second+i));
        *(arreys.third+i)=gen;  //printf("%d",*(arreys.third+i));
    }
    return arreys;
}
SortStat bubble_sort(int array[], int len)
{
    SortStat bstats;
    bstats.comparisons=0;
    bstats.duration=0;
    bstats.swaps=0;

    clock_t t = clock();

    int c, d, swap;
    for (c=0; c<(len-1); c++)
    {
        for (d=0; d<len-c-1; d++)
        {
            bstats.comparisons++;
            if (array[d] > array[d+1])
            {
                bstats.swaps++;
                swap=array[d];
                array[d]=array[d+1];
                array[d+1]=swap;
            }
        }
    }
    t = clock() - t;
    bstats.duration=((long double) t)/CLOCKS_PER_SEC * 1000;
    return bstats;
}

SortStat selection_sort(int array[], int len)
{
    SortStat sstats;
    sstats.comparisons=0;
    sstats.duration=0;
    sstats.swaps=0;

    clock_t t = clock();

    int c, d, position, swap;
    for(c=0; c<(len-1); c++)
    {
        position=c;
        for(d=c+1; d<len; d++)
        {
            sstats.comparisons++;
            if(array[position] > array[d])
            position = d;
        }
        if(position != c)
        {
            sstats.swaps++;
            swap=array[c];
            array[c]=array[position];
            array[position]=swap;
        }
    }

    t = clock() - t;
    sstats.duration=((long double) t)/CLOCKS_PER_SEC * 1000;
    return sstats;
}

SortStat insertion_sort(int array[], int len)
{
    SortStat istats;
    istats.comparisons=0;
    istats.duration=0;
    istats.swaps=0;

    clock_t t = clock();

    int c,d,temp;
    for(c=1; c<=len-1; c++)
    {
        d=c;
        istats.comparisons++;
        while(d>0 && array[d]<array[d-1])
        {
            istats.swaps++;
            temp=array[d];
            array[d]=array[d-1];
            array[d-1]=temp;
            d--;
        }
    }
    t = clock() - t;
    istats.duration=((long double) t)/CLOCKS_PER_SEC * 1000;
    return istats;
}

unsigned long int linear_search(int array[], int len, int key)
{
    int i, comp=0;
    for (i=0; i<len; i++)
    {
        comp++;
        if(array[i]==key)
        {
            comp++;
        }
    }
    return comp;
}

unsigned long int binary_search(int array[], int low, int high, int key)
{
    int mid, comp=0;

    if (low > high)
    {
        comp++;
        return -1;
    }
    mid = (low + high) / 2;
    if (array[mid] == key)
    {
        comp++;
    }
    else if (array[mid] > key)
    {
        comp++;
        binary_search(array, low, mid - 1, key);
    }
    else if (array[mid] < key)
    {
        comp++;
        binary_search(array, mid + 1, high, key);
    }
    return comp;
}
