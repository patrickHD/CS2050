#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Name: Patrick Daniel
   Pawprint: phd6x2
   Date: 2/4/2015
   Lab section: G
   Sub code: Snow
   CS2050 Lab2 */

struct point{
    int x;
    int y;
};

struct point* read_file(char* file_name, int size);
double distance(struct point first, struct point second);
struct point* sort(struct point* array, int size);
void print_points(struct point* array, int size);

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("\nNot enough parameters\n");
        return 0;
    }
    struct point *points;
    //points=malloc(sizeof(point*5))
    points=read_file(argv[2], atoi(argv[1]));
    points=sort(points,atoi(argv[1]));
    print_points(points, atoi(argv[1]));

    //printf("%d", points[2].x);
    return 0;
}

struct point* sort(struct point* array, int size)
{
    int i=0; int z=0;
    struct point origin;
    origin.x=0; origin.y=0;
    for(i=0; i<size; i++)
    {
        for(z=0; z<size-1; z++)
        {
            if(distance(array[z],origin)>distance(array[z+1], origin))
            {
                int tempx=array[z+1].x;
                int tempy=array[z+1].y;
                array[z+1].x=array[z].x;
                array[z+1].y=array[z].y;
                array[z].x=tempx;
                array[z].y=tempy;
            }
        }
    }
    return array;
}

struct point* read_file(char* file_name, int size)
{
    struct point points[size];
    int i=0;
    FILE *input = fopen(file_name, "r");
    for(i=0; i<size; i++)
    {
        fscanf(input, "%d %d", &points[i].x, &points[i].y);
        //printf("%d %d\n", points[i].x, points[i].y);
    }
    fclose(input);
    return points;
};

double distance(struct point first, struct point second)
{
    return sqrt(pow(first.x-second.x,2)+pow(first.y-second.y,2));
}

void print_points(struct point* array, int size)
{
    int i=0;
    for(i=0; i<size; i++)
    {
        printf("(%d,%d)\n", array[i].x, array[i].y);
    }
}
