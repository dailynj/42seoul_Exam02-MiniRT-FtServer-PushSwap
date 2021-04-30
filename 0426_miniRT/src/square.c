#include "../includes/minirt.h"

t_square	*square(t_point point, t_vec normal, double length)
{
	t_square *sq;

	if(!(sq = (t_square *)malloc(sizeof(t_square))))
		return (NULL);
	sq->point = point;
	sq->normal = normal;
    sq->length = length;
	return (sq);
}

t_bool hit_square(t_object *world, t_ray *ray, t_hit_record *rec)
{
    t_point	p[4];
    t_vec		temp;
    double		root;
    t_square    *sq = world->element;

    root = vec_dot(vec_minus(sq->point, ray->origin), sq->normal);
    if (vec_dot(sq->normal, ray->dir) == 0)
        root = root / EPSILON;
    else
        root = root / vec_dot(sq->normal, ray->dir);
    if (root < 0 || root < rec->tmin || root > rec->tmax)
        return (0);
    hit_square_sub(world, p);
    temp = ray_at(ray, root);
    if (!(is_inside_(p[0], p[1], p[2], temp) || is_inside_(p[0], p[1], p[3], temp)))
        return (0);
    rec->t = root;
    rec->p = temp;
    rec->normal = sq->normal;
    rec->albedo = world->albedo;
    set_face_normal(ray, rec);
    // get_square_uv(rec, sq, p[3]);
    return (1);
}

void	hit_square_sub(t_object *world, t_point *p)
{
    t_square *sq = world->element;

	p[0] = vec_mul_num(sq->length / 2, vec_unit(vec_cross(vec(0, -1, 0), sq->normal)));
	p[2] = vec_mul_num(sq->length / 2, vec_unit(vec_cross(vec(0, 1, 0), sq->normal)));
	p[2] = vec_add(vec_add(p[2], vec_mul_num(sq->length / 2, vec_unit(vec_cross(p[0], sq->normal)))), sq->point);
	p[0] = vec_add(vec_add(p[0], vec_mul_num(sq->length / 2, vec_unit(vec_cross(p[0], sq->normal)))), sq->point);
	p[1] = vsymmetric(p[0], sq->point);
	p[3] = vsymmetric(p[2], sq->point);
}

t_bool	is_inside_(t_point p1, t_point p2, t_point p3, t_point p)
{
	t_vec	v1;
	t_vec	v2;

	v1 = vec_cross(vec_minus(p2, p1), vec_minus(p, p1));
	v2 = vec_cross(vec_minus(p2, p1), vec_minus(p3, p1));
	if (vec_dot(v1, v2) < 0)
		return (0);
	v1 = vec_cross(vec_minus(p3, p1), vec_minus(p, p1));
	v2 = vec_cross(vec_minus(p3, p1), vec_minus(p2, p1));
	if (vec_dot(v1, v2) < 0)
		return (0);
	v1 = vec_cross(vec_minus(p2, p3), vec_minus(p, p3));
	v2 = vec_cross(vec_minus(p2, p3), vec_minus(p1, p3));
	if (vec_dot(v1, v2) < 0)
		return (0);
	else
		return (1);
}