#include "minirt.h"

t_sphere	sphere(t_vec center, double radius)
{
  t_sphere sp;

  sp.center = center;
  sp.radius = radius;
  sp.radius2 = radius * radius;
  return (sp);
}

t_bool hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec) 
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

  if (root < rec->tmin || rec->tmax < root){
    root = (-half_b + sqrtd) / a;
    if (root < rec->tmin || rec->tmax < root)
      return (FALSE);
  }

  rec->t = root;
  rec->p = ray_at(ray, root);
  rec->normal = vec_div(sp->radius, vec_minus(rec->p, sp->center));

  set_face_normal(ray, rec);

  return (TRUE);
}

void	set_face_normal(t_ray *ray, t_hit_record *rec)
{
	// 광선의 방향벡터와 교점의 법선벡터의 내적이 음수이면 광선은 앞면(객체의)에 hit 한 것이다
	rec->front_face = vec_dot(ray->dir, rec->normal) < 0;
	// 광선의 앞면에 hit 면 그대로 아니면 법선을 반대로 뒤집는다. (항상 광선 방향벡터와 법선 벡터를 반대인 상태로 사용하기위해)
	rec->normal = (rec->front_face) ? rec->normal : vec_mul_num(-1, rec->normal);
}