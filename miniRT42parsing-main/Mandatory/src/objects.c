#include "../inc/minirt.h"

t_objects	*add_to_list(t_objects *main, void *data, t_objs type, int id)
{
	t_objects	*new;
	t_objects	*main_bk;

	main_bk = main;
	new = ft_smart_malloc(sizeof(t_objects));
	new->data = data;
	new->id = id;
	new->type = type;
	new->next = NULL;
	if (main == NULL)
	{
		main = new;
		return (main);
	}
	while (main->next)
		main = main->next;
	main->next = new;
	return (main_bk);
}