#include "minirt.h"

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
  t_sphere *sp = world->element;
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
  rec->albedo = world->albedo;

  set_face_normal(ray, rec);

  return (TRUE);
}

t_bool		hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec; // temp_rec의 tmin, tmax 값 초기화를 위해.
	hit_anything = FALSE;
	while(world)
	{
		if (hit_obj(world, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}

// hit_obj는 오브젝트 타입에 맞는 hit함수로 연결해주는 관문
t_bool		hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (world->type == SP)
		hit_result = hit_sphere(world, ray, rec); //hit_sphere의 첫번째 인자도 t_sphere *에서 t_object *로 수정해주자.
	return (hit_result);
}

void	set_face_normal(t_ray *ray, t_hit_record *rec)
{
	// 광선의 방향벡터와 교점의 법선벡터의 내적이 음수이면 광선은 앞면(객체의)에 hit 한 것이다
	rec->front_face = vec_dot(ray->dir, rec->normal) < 0;
	// 광선의 앞면에 hit 면 그대로 아니면 법선을 반대로 뒤집는다. (항상 광선 방향벡터와 법선 벡터를 반대인 상태로 사용하기위해)
	rec->normal = (rec->front_face) ? rec->normal : vec_mul_num(-1, rec->normal);
}