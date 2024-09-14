#include "../../inc/minirt.h"

// Updated validation function
int validate_split(char **arr, int expected_count)
{
    int count = 0;
    int i = 0;

    while (arr[count])
        count++;

    if (count != expected_count)
    {
        printf("Error: Incorrect number of values. Expected %d "\
         "values separated by commas.\n", expected_count);
        return 1;
    }
    while (i < expected_count)
    {
        if (arr[i][0] == '\0')
        {
            printf("Error: Missing value between commas.\n");
            return 1;
        }
        i++;
    }
    return 0;
}

int parse_xyz(char *input, float xyz[3])
{
    char **arr_xyz;
    int u = 0;

    arr_xyz = ft_split_2(input, ',', 1);
    if (!arr_xyz || validate_split(arr_xyz, 3))
    {
        free(arr_xyz);
        return (1);
    }

    while (arr_xyz[u])
    {
        xyz[u] = atof(arr_xyz[u]);
        u++;
    }
    free(arr_xyz);
}
int parse_normal(char *input, float normal[3])
{
    char **arr_normal;
    int u = 0;

    arr_normal = ft_split_2(input, ',', 1);
    if (!arr_normal || validate_split(arr_normal, 3))
    {
        free(arr_normal);
        return (1);
    }

    while (arr_normal[u])
    {
        normal[u] = atof(arr_normal[u]);
        u++;
    }
    free(arr_normal);
}

int parse_rgb(char *input, float rgb[3])
{
    char **arr_rgb;
    int u = 0;

    arr_rgb = ft_split_2(input, ',', 1);
    if (!arr_rgb || validate_split(arr_rgb, 3))
    {
        free(arr_rgb);
        return(1);
    }
    while (arr_rgb[u])
    {
        rgb[u] = atof(arr_rgb[u]);
        u++;
    }
    free(arr_rgb);
}