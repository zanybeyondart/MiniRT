#include "../inc/minirt.h"

int main(int argc, char **argv) //munira function
{   
    t_objects *objects;
    char *file_path;

    if (argc == 2 && argv[1])
    {
        file_path = ft_smart_malloc(ft_strlen("./Mandatory/src/scenes/")\
         + ft_strlen(argv[1]) + 1);
        objects = ft_smart_malloc(sizeof(t_objects));
        ft_strcpy(file_path, "./Mandatory/src/scenes/");
        ft_strcat(file_path, argv[1]);
        read_file(file_path, objects);
    }
    if(argc<2)
        printf("Too few arguments");
    else if(argc>2)
        printf("Too many arguments");
}