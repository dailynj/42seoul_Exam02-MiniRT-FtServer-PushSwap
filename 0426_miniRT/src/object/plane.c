#include "../../includes/minirt.h"

t_plane	*plane(t_point point, t_vec normal)
{
	t_plane *pl;

	if(!(pl = (t_plane *)malloc(sizeof(t_plane))))
		return (NULL);
	pl->point = point;
	pl->normal = normal;
	return (pl);
}

t_bool hit_plane(t_object *world, t_ray *ray, t_hit_record *rec)
{
  t_plane *pl;
  double	denom;
	double root;
	t_vec	to_hit;

	pl = world->element;
	denom = vec_dot(pl->normal, ray->dir);
	if (fabs(denom) < EPSILON)
		return (FALSE);
	to_hit = vec_minus(pl->point, ray->origin);
	root = vec_dot(to_hit, pl->normal) / denom;
	if (root < rec->tmin || root > rec->tmax)
		return (FALSE);

  rec->t = root;
  rec->p = ray_at(ray, root);
  rec->albedo = world->albedo;
  rec->normal = pl->normal;

	set_face_normal(ray, rec);
  
	return (TRUE);
}