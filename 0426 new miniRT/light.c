#include "minirt.h"

t_light		*light_point(t_vec light_origin, t_color light_color, double bright_ratio)
{
	t_light	*light;

	if(!(light = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}

