#include "../../includes/minirt.h"

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
	t_square* sq = world->element;
	if (hit_plane(world, ray, rec) == FALSE)
		return (FALSE);
	t_vec u = vec(0, 1, 0);
	if ((sq->normal.x == 0 && sq->normal.y == 1) && sq->normal.z == 0)
		u = vec(0, 0, 1);
	t_vec v = vec_cross(sq->normal, u);
	double u_len = vec_dot(u, vec_minus(rec->p, sq->point)) / vec_dot(u, u);
	double v_len = vec_dot(v, vec_minus(rec->p, sq->point)) / vec_dot(v, v);
	if ((u_len < sq->length / -2.0) || (u_len > sq->length / 2.0) || (v_len < sq->length / -2.0) || (v_len > sq->length / 2.0))
		return (FALSE);
	set_face_normal(ray, rec);
    return (TRUE);
}