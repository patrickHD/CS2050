#include <stdio.h>
#include <stdlib.h>

int* readFile(char* inputFile, int* list);
void print_data(int* list);
int findMin(int* list);
int findMax(int* list);
int findAvg(int* list);
void writeOut(char* outFile, int min, int max, int avg);

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("\nNot enough parameters\n");
        return 0;
    }

    int *numbers;
    numbers=malloc(sizeof(int)*10);
    numbers=readFile(argv[1], numbers);
   // print_data(numbers, 10);
    int min = findMin(numbers);
    int max = findMax(numbers);
    int avg = findAvg(numbers);
    printf("min: %d\n", min);
    printf("max: %d\n", max);
    printf("avg: %d\n", avg);
    writeOut(argv[2], min, max, avg);
    return 0;
}

int* readFile(char* inputFile, int* list)
{
    int number;
    int i=0;

    FILE *input_file=fopen(inputFile, "r");
    if(input_file==NULL)
    {
        return 0;
    }

    for(i=0;i<10;i++)
	{
		fscanf(input_file, "%d", &number);
		*(list+i)=number;
	}
	return list;
}

void print_data(int* list)
{
    int i=0;
    for(i=0;i<10;i++)
    {
        printf("\n%d", *(list+i));
    }
}

int findMin(int* list)
{
    int i=0;
    int smallest=1000;
    for(i=0; i<10; i++)
    {
        if(*(list+i)<smallest)
        {
            smallest=*(list+i);
        }
    }
    return smallest;
}

int findMax(int* list)
{
    int i=0;
    int largest=0;
    for(i=0; i<10; i++)
    {
        if(*(list+i)>largest)
        {
            largest=*(list+i);
        }

    }
    return largest;
}

int findAvg(int* list)
{
    int i=0;
    int total=0;
    for(i=0; i<10; i++)
    {
        total += *(list+i);
    }
    return total/10;
}

void writeOut(char* outFile, int min, int max, int avg)
{
    FILE *output_file=fopen(outFile, "w");
    if (output_file == NULL)
    {
        printf("Error opening file\n");
    }
    fprintf(output_file, "min: %d\n", min);
    fprintf(output_file, "max: %d\n", max);
    fprintf(output_file, "avg: %d\n", avg);
    fclose(output_file);
}
