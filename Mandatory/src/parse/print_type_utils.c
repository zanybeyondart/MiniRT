#include "../../inc/minirt.h"

//Can be removed

void print_split_result(char **split_result) //Just to print check 
{
    int h = 0;
    printf("\n//This is the string divide\n");
    while (split_result[h])
    {
        printf("From Mini Function => Word[%d]: %s\n", h, split_result[h]);
        h++;
    }
}

void print_array_char(char **arr) //Just to print check
{
    int k = 0;
    printf("\n//This is the colour divide\n");
    while (arr[k])
    {
        printf("From Mini Function => This is Char array[%d]: %s\n", k, arr[k]);
        k++;
    }
    printf("\n");
}

void print_array_float(float *rgb) //Just to print check
{
    int i = 0;
    while (i<3) 
    {
        printf("From Mini Function => This is Float Array %d = %f \n", i + 1, rgb[i]);
        i++;
    }
}
