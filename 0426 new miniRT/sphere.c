#include "minirt.h"

//int			(*hit)(struct s_world *this, t_ray *ray, double min, double max, t_hit_record *out)
t_bool hit_sphere(t_vec center, double radius, t_ray ray, t_hit_record rec) 
{
  t_vec oc = vec(ray.origin.x - center.x, ray.origin.y - center.y, ray.origin.z - center.z);
  double a = vec_dot(ray.dir, ray.dir);
  double half_b = vec_dot(oc, ray.dir);
  double c = vec_dot(oc, oc) - radius * radius;
  double discriminant = half_b * half_b - a * c;

  if (discriminant < 0)
    return (false);

  double sqrtd = sqrt(discriminant);
  double root = (-half_b - sqrtd) / a;
  
  if (root < rec.tmin || rec.tmax < root){
    root = (-half_b + sqrtd) / a;
    if (root < rec.tmin || rec.tmax < root)
      return (false);
  }
  rec.t = root;
  rec.p = ray_at(&ray, rec.t);
  rec.normal = vec_div(radius, vec_minus(rec.p, center));
  return (true);
}