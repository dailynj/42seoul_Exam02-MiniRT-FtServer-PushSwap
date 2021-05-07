#include "../../includes/minirt.h"

t_triangle	*triangle(t_vec p1, t_vec p2, t_vec p3)
{
	t_triangle *tr;

	if(!(tr = (t_triangle *)malloc(sizeof(t_triangle))))
		return (NULL);
	tr->p1 = p1;
	tr->p2 = p2;
    tr->p3 = p3;
    tr->normal = vec_unit(vec_cross(vec_minus(p2, p1), vec_minus(p3, p1)));
	return (tr);
}

t_bool hit_triangle(t_object *world, t_ray *ray, t_hit_record *rec)
{
    t_triangle      *tr = world->element;
    rec->t = -vec_dot(vec_minus(ray->origin, tr->p1), tr->normal) / vec_dot(tr->normal, ray->dir);
    rec->p = ray_at(ray, rec->t);
    if (check_tri(tr->p2, tr->p1, tr->p3, rec->p) == FALSE)
        return (FALSE);
    if (check_tri(tr->p3, tr->p2, tr->p1, rec->p) == FALSE)
        return (FALSE);
    if (check_tri(tr->p1, tr->p3, tr->p2, rec->p) == FALSE)
        return (FALSE);

    rec->normal = tr->normal;
    rec->albedo = world->albedo;
    set_face_normal(ray, rec);
    return (TRUE);
}

t_bool check_tri(t_vec a, t_vec b, t_vec c, t_vec point)
{
    t_vec l_;
    t_vec r_;
    t_vec m_;

    l_ = vec_minus(a, b);
    r_ = vec_minus(c, b);
    m_ = vec_minus(point, b);
    if (vec_dot(vec_cross(l_, r_), vec_cross(m_, r_)) < 0)
        return (FALSE);
    if (vec_dot(vec_cross(r_, l_), vec_cross(m_, l_)) < 0)
        return (FALSE);
    return (TRUE);
}