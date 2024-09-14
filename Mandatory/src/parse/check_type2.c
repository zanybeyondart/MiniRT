#include "../../inc/minirt.h"

int check_sphere(char *str, t_objects *objects)
{
    char    **split_result;
    float   diameter;
    float   rgb[3];
    float   xyz[3];

    // t_objects	*obj;
    // obj = objects;
    split_result = ft_split_2(str, ' ', 0);
    if (split_result[1])
        if(parse_xyz(split_result[1], xyz))
            return (1);
    if (split_result[2])
        diameter = atof(split_result[2]);
    if (diameter <= 0)
    {
        printf("Diameter value cannot be negative\n");
        return (1);
    }
    if (split_result[3])
        if (parse_rgb(split_result[3], rgb))
            return (1);
    if (check_rgb_range(rgb) != 0)
        return (1);

    // print_array_float(xyz);
    // printf("Diameter -> %f \n", diameter);
    // print_array_float(rgb);

    // objects = add_to_list(objects, set_sphere(xyz[0], xyz[1], xyz[2], create_trgb(0, rgb[0], rgb[1], rgb[2])), SPHERE, 2);
}

int check_plane(char *str, t_objects *objects)
{
    char    **split_result;
    float   xyz[3];
    float   normal[3];
    float   rgb[3];
    int u;

    // t_objects	*obj;
    // obj = objects;
    split_result = ft_split_2(str, ' ', 0);
    if (split_result[1])
        if (parse_xyz(split_result[1], xyz))
            return (1);
    if (split_result[2])
        if (parse_normal(split_result[2], normal))
            return (1);
    if (check_normal_range(normal) != 0)
        return (1);
    if (split_result[3])
        if(parse_rgb(split_result[3], rgb))
            return (1);
    if (check_rgb_range(rgb) != 0)
        return (1);

    // print_array_float(xyz);
    // print_array_float(normal);
    // print_array_float(rgb);

    // set_plane(xyz[0],xyz[0],xyz[0],normal[0],normal[1],normal[2],rgb[0],rgb[1],rgb[2]);
}

int check_cylinder(char *str, t_objects *objects)
{
    char    **split_result;
    float   xyz[3];
    float   normal[3];
    float   rgb[3];
    float   cylinder_diameter;
    float   cylinder_height;
    int u;

    // t_objects	*obj;
    // obj = objects;
    split_result = ft_split_2(str, ' ', 0);
    if (split_result[1])
        if (parse_xyz(split_result[1], xyz))
            return (1);
    if (split_result[2])
        if (parse_normal(split_result[2], normal))
            return (1);
    if (check_normal_range(normal) != 0)
        return (1);
    if(split_result[3])
        cylinder_diameter = atof(split_result[3]);
    if (cylinder_diameter<= 0)
    {
        printf("Error: Cylinder Diameter cannot be less than 0\n");
        return (1);
    }
    if(split_result[4])
        cylinder_height = atof(split_result[4]);
    if (cylinder_height<= 0)
    {
        printf("Error: Cylinder Height cannot be less than 0\n");
        return (1);
    }  
    if (split_result[5])
        if(parse_rgb(split_result[5], rgb))
            return (1);
    if (check_rgb_range(rgb) != 0)
        return (1);

    // print_array_float(xyz);
    // print_array_float(normal);
    // printf("Cylinder Diameter %f\n",cylinder_diameter);
    // printf("Cylinder Height %f\n",cylinder_height);
    // print_array_float(rgb);

    // set_cylinder(xyz[0],xyz[0],xyz[0],normal[0],normal[1],normal[2],cylinder_diameter/2,cylinder_height,rgb[0],rgb[1],rgb[2]);
}
