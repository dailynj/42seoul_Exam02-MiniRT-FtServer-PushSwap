#include "minirt.h"

t_vec	ray_at(t_ray *ray, double t)
{
	t_vec out;

	out.x = ray->origin.x + ray->dir.x * t;
	out.y = ray->origin.y + ray->dir.y * t;
	out.z = ray->origin.z + ray->dir.z * t;
	return (out);
}

t_ray		ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.origin = cam->orig;
	// left_bottom + u * horizontal + v * vertical - origin 의 단위 벡터.
	ray.dir = vec_unit(vec_minus(vec_add(vec_add(cam->left_bottom, vec_mul_num(u, cam->horizontal)), vec_mul_num(v, cam->vertical)), cam->orig));
	return (ray);
}

// Image의 크기 및 종횡비, Projection 공간에서 나타나는 Vector에 따른 색상을 결정
t_vec				ray_color(t_ray ray, t_object *world)
{
	double			t;
	t_hit_record	rec;
	
	rec.tmin = 0;
	rec.tmax = INFINITY;

	if (hit(world, &ray, &rec))
		return (vec_mul_num(0.5, vec_add(rec.normal, color(1, 1, 1))));

	t_vec unit_direction = vec_unit(ray.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	return (vec(1.0 - 0.5 * t, 1.0 - 0.3 * t, 1.0));
}
