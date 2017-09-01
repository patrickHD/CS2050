#include <stdio.h>
#include <stdlib.h>

typedef struct points{
    float axis[2];
    int id;
}Points;

typedef enum{
    SortById,
    SortByXAxis
}SortType;

Points *fill_Array(char* filename, int* length);
void print_Set(Points *set, int number_of_points);
void mergesort(Points *set, int low, int high, int number_of_points, SortType sort);
void merge(Points *set, int low, int middle, int high, int number_of_points, SortType sort);
int binary_search(Points *set, int number_of_points, int ID_Target);
void range_query_on_x(Points *set, int number_of_points, float mean, float std_dev);

//preforms the necessary operations
int main(int argc, char* argv[])
{
    Points *pts;
    int len, searchID;
    pts=fill_Array(argv[1], &len);
    mergesort(pts, 0, len-1, len, SortById);
    print_Set(pts, len);
    printf("\nEnter an ID to search for: ");
    scanf("%d", &searchID);
    if(binary_search(pts, len, searchID)==-1)
    {
        printf("ID not found\n");
    }
    else
    {
        printf("%d %f %f\n", pts[binary_search(pts, len, searchID)].id, pts[binary_search(pts, len, searchID)].axis[0], pts[binary_search(pts, len, searchID)].axis[1]);
    }
    printf("\nSorting on X-axis\n");
    mergesort(pts, 0, len-1, len, SortByXAxis);
    print_Set(pts, len);
    printf("Enter an X value and a distance (e.g. 5.556 4.555): ");
    float xval, xdist;
    scanf("%f %f", &xval, &xdist);
    range_query_on_x(pts, len, xval, xdist);
    return 0;
}

//fills an array with numbers from an input files
Points *fill_Array(char* filename, int* length)
{
    int i;
    FILE* inputF=fopen(filename, "r");
    if(inputF==NULL)
    {
        printf("File not found\n");
        return;
    }
    fscanf(inputF, "%d", length);
    Points *pts=malloc(sizeof(Points)*(*length));
    for(i=0; i<*length; i++)
    {
        fscanf(inputF, "%d %f %f", &pts[i].id, &pts[i].axis[0], &pts[i].axis[1]);
    }
    return pts;
}

//prints the points in the array
void print_Set(Points *set, int number_of_points)
{
    int i;
    for(i=0; i<number_of_points; i++)
    {
        printf("%d %f %f\n", set[i].id, set[i].axis[0], set[i].axis[1]);
    }
}

//sorts the array
void mergesort(Points *set, int low, int high, int number_of_points, SortType sort)
{
    if (low < high)
    {
        int m = (high + low)/2;
        mergesort(set, low, m, number_of_points, sort);
        mergesort(set, m + 1, high, number_of_points, sort);
        merge(set, low, m, high, number_of_points, sort);
    }
}

//merges the array
void merge(Points *set, int low, int middle, int high, int number_of_points, SortType sort)
{
    Points *set2=malloc(sizeof(Points)*number_of_points);
    int i = low, j = middle + 1, k = 0;

    if(sort==0)
    {
        while (i <= middle && j <= high)
        {
            if (set[i].id <= set[j].id)
                set2[k++].id = set[i++].id;
            else
                set2[k++].id = set[j++].id;
        }

        while (i <= middle){
            set2[k++].id = set[i++].id;}
        while (j <= high){
            set2[k++].id = set[j++].id;}

        k--;
        while (k >= 0)
        {
            set[low + k].id = set2[k].id;
            k--;
        }
    }
    else
    {
        while (i <= middle && j <= high)
        {
            if (set[i].axis[0] <= set[j].axis[0])
                set2[k++].axis[0] = set[i++].axis[0];
            else
                set2[k++].axis[0] = set[j++].axis[0];
        }

        while (i <= middle){
            set2[k++].axis[0] = set[i++].axis[0];}
        while (j <= high){
            set2[k++].axis[0] = set[j++].axis[0];}

        k--;
        while (k >= 0)
        {
            set[low + k].axis[0] = set2[k].axis[0];
            k--;
        }
    }
}

//searches for a number
int binary_search(Points *set, int number_of_points, int ID_Target)
{
    int low=0;
    int high=number_of_points-1;
    if(low>high)
    {
        return -1;
    }
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(set[mid].id==ID_Target)
        {
            return mid;
        }
        else if(set[mid].id<ID_Target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}

//This function will print out all points with axis[0] values within one standard deviation of
//the mean, all points with axis[0] values in the range [mean – std_dev, mean + std_dev].
void range_query_on_x(Points *set, int number_of_points, float mean, float std_dev)
{
    int low=0;
    int high=number_of_points-1;
    int lowend=mean-std_dev;
    int highend=mean+std_dev;
    int mid;

    while(low <= high)
    {
        mid=(low+high)/2;
        if(set[mid].axis[0] < lowend)
        {
            low=mid-1;
        }
        else if(set[mid].axis[0] > highend)
        {
            high=mid-1;
        }
        else
        {
            break;
        }
    }
    while(mid <= number_of_points)
    {
        if(set[mid].axis[0] <= highend)
        {
            printf("%d %f %f\n", set[mid].id, set[mid].axis[0], set[mid].axis[1]);
            mid++;
        }
        else
        {
            break;
        }
    }
}
