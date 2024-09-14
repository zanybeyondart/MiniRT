/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 03:18:47 by zvakil            #+#    #+#             */
/*   Updated: 2024/09/14 03:38:00 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../gnl/get_next_line.h"

int	is_valid_type(char *test)
{
	int	i;

    i = 0;
	while ((test[i] == ' ' || test[i] == '\t') && test[i] != '\0')
        i++;
    if (test[i] == '\0')
        return 0;
   if (test[i] == 'A' || test[i] == 'C' || test[i] == 'L')
        return 1;
    if (test[i] == 's' && test[i + 1] == 'p')
        return 1;
    if (test[i] == 'p' && test[i + 1] == 'l')
        return 1;
    if (test[i] == 'c' && test[i + 1] == 'y')
        return 1;
    return 0;
}

int read_test(char *test, t_objects *objects)
{
    int i;
    
    i=0;
    while((test[i] == ' ' || test[i] == '\t') && test[i] !='\0')
        i++;
    if (!is_valid_type(test))
    {
        printf("Incorrect type in the file -> %c \n", test[i]);
        return 1;
    }
    if(test[i] == 'A' && check_ambient(test, objects))
        return(1);
    if(test[i] == 'C' && check_camera(test, objects))
        return(1);
    if(test[i] == 'L' && check_light(test, objects))
        return(1);
    if(test[i] == 's' && test[i+1] == 'p' && check_sphere(test, objects))
        return(1);
    if(test[i] == 'p' && test[i+1] == 'l' &&  check_plane(test, objects))
        return(1);
    if(test[i] == 'c' && test[i+1] == 'y' && check_cylinder(test, objects))
        return(1);
    return(0);
}

int empty_line(char *line)
{
    int i = 0;

    while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'\
     || line[i] == '\n' || line[i] == '\r'))
        i++;
    return (line[i] == '\0');
}

int	read_file(char *readfile, t_objects *objects)
{
    int fd = open(readfile, O_RDONLY);
    int error =0; 


    if(fd<0) 
    {
        perror("Error opening file");
        return 1;
    }

    char *test = get_next_line(fd);
    if (!test) 
    {
        printf("Error: The file is empty \n");
        close(fd);
        return 1;
    }
    while(test)
    {
        if(!empty_line(test))
        {
            if (read_test(test, objects) != 0)
            {
                free(test);
                close(fd);
                return 1;
            }
        }
		
        free(test);
        test = get_next_line(fd);
    }
    free(test);
    close(fd);
    printf("Success\n");
    return(0);
}