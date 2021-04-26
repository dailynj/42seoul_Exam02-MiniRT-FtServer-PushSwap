#include "minirt.h"

t_vec	ray_at(t_ray *ray, double t)
{
	t_vec out;

	out.x = ray->origin.x + ray->dir.x * t;
	out.y = ray->origin.y + ray->dir.y * t;
	out.z = ray->origin.z + ray->dir.z * t;
	return (out);
}