#include "../includes/minirt.h"

t_sphere	*sphere(t_point center, double radius)
{
	t_sphere *sp;

	if(!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

t_bool hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec) 
{
  if (sphere_discriminant(world->element, ray, rec) == FALSE)
    return (FALSE);

  rec->albedo = world->albedo;
  set_face_normal(ray, rec);
  return (TRUE);
}

t_bool      sphere_discriminant(t_sphere* sp, t_ray *ray, t_hit_record *rec)
{
  t_vec oc = vec(ray->origin.x - sp->center.x, ray->origin.y - sp->center.y, ray->origin.z - sp->center.z);
  double a = vec_dot(ray->dir, ray->dir);
  double half_b = vec_dot(oc, ray->dir);
  double c = vec_dot(oc, oc) - sp->radius * sp->radius;
  double discriminant = half_b * half_b - a * c;
  
  if (discriminant < 0)
    return (FALSE);
  double sqrtd = sqrt(discriminant);
  double root = (-half_b - sqrtd) / a;
  if (root < rec->tmin || rec->tmax < root)
  {
    root = (-half_b + sqrtd) / a;
    if (root < rec->tmin || rec->tmax < root)
      return (FALSE);
  }
  rec->t = root;
  rec->p = ray_at(ray, root);
  rec->normal = vec_div(sp->radius, vec_minus(rec->p, sp->center));
  return (TRUE);
}