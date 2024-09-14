#include "../../inc/minirt.h"

int check_rgb_range(float rgb[3])
{
    int i;

    i = 0;
    while (i < 3)
    {
        if (rgb[i] < 0 || rgb[i] > 255)
        {
            printf("Error: RGB value out of bounds."\
            "RGB values should be between 0 and 255.\n");
            return (1);
        }
        i++;
    }
    return 0;
}

int check_normal_range(float normal[3])
{
    int i = 0;
    while (i < 3)
    {
        if (normal[i] < -1 || normal[i] > 1)
        {
            printf("Error: Normal value out of bounds. "\
            "3D Normal values should be between -1 and 1.\n");
            return (1);
        }
        i++;
    }
    return 0;
}

int check_lighting_range(float lighting)
{
    if (lighting < 0.0 || lighting > 1.0)
    {
        printf("Error: Lighting value out of bounds. "\
        "It should be between 0.0 and 1.0.\n");
        return 1;
    }
    return 0;
}

int check_fov_range(float fov)
{
    if (fov<0 || fov>180)
    {
        printf("Error: FOV fov value out of bounds. "\
        "It should be between 0 and 180.\n");
        return (1);
    }
    return (0);
}