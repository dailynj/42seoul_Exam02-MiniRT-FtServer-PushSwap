/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:51:31 by najlee            #+#    #+#             */
/*   Updated: 2021/05/17 14:17:09 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_cylinder          *cylinder(t_point point, double radius, double height, t_vec normal)
{
	t_cylinder	*cy;

	if (!(cy = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (NULL);
	cy->point = point;
	cy->normal = normal;
	cy->radius = radius;
	cy->height = height;
	return (cy);
}

t_bool              hit_cylinder(t_object *world, t_ray *ray, t_hit_record *rec)
{
    t_cylinder      *cylinder;

    cylinder = (t_cylinder *)world->element;
	
    if (cylinder_discriminant(cylinder, ray, rec) == FALSE)
        return (FALSE);
    rec->p = ray_at(ray, rec->t);
    rec->normal = vec_unit(vec_minus(vec_minus(rec->p, cylinder->point),
                    vec_mul_num(
                    vec_dot(cylinder->normal, vec_minus(rec->p, cylinder->point)), cylinder->normal)));
    rec->albedo = world->albedo;
    if (!cylinder_height_check(cylinder, ray, rec))
        return (FALSE);
    set_face_normal(ray, rec);
    return (TRUE);
}

/*
** 판별식으로 point가 원기둥을 hit하나 확인
*/

t_bool              cylinder_discriminant(t_cylinder *cylinder,
                                            t_ray *ray, t_hit_record *rec)
{
    double          a;
    double          b;
    double          c;
    double          d;
	
    a = vec_length_2(vec_minus(ray->dir, vec_mul_num(
            vec_dot(cylinder->normal, ray->dir), cylinder->normal)));
    b = vec_dot(vec_minus(ray->dir, vec_mul_num(
            vec_dot(cylinder->normal, ray->dir), cylinder->normal)),
            vec_minus(vec_minus(ray->origin, cylinder->point),
            vec_mul_num(vec_dot(cylinder->normal,
            vec_minus(ray->origin, cylinder->point)), cylinder->normal)));
    c = vec_length_2(vec_minus(vec_minus(ray->origin, cylinder->point),
            vec_mul_num(vec_dot(cylinder->normal,
            vec_minus(ray->origin, cylinder->point)), cylinder->normal))) -
            cylinder->radius * cylinder->radius;

    d = b * b - a * c;
    rec->t = (-b - sqrt(d)) / a;
    rec->t2 = (-b + sqrt(d)) / a;
    if (d < 0)
        return (FALSE);
    if (rec->t < rec->tmin || rec->t > rec->tmax)
        if (rec->t2 < rec->tmin || rec->t2 > rec->tmax)
            return (FALSE);
    return (TRUE);
}

/*
** 원기둥 길이 제한 함수
*/

t_bool              cylinder_height_check(t_cylinder *cylinder,
                                                t_ray *ray, t_hit_record *rec)
{
    double          h;
    h = vec_length_2(vec_minus(rec->p, cylinder->point)) -
            cylinder->radius * cylinder->radius;
    if (sqrt(h) > cylinder->height)
    {
        rec->p = ray_at(ray, rec->t2);
        h = vec_length_2(vec_minus(rec->p, cylinder->point)) -
                cylinder->radius * cylinder->radius;
        rec->normal = vec_unit(vec_div(cylinder->radius, vec_minus(vec_minus(rec->p, cylinder->point), 
		vec_mul_num(vec_dot(cylinder->normal, vec_minus(rec->p, cylinder->point)), cylinder->normal))));
        if (sqrt(h) > cylinder->height)
            return (FALSE);
    }
    return (TRUE);
}