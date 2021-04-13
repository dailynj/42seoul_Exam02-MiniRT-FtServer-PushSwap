/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:39:58 by najlee            #+#    #+#             */
/*   Updated: 2021/04/13 14:39:59 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	// 광선의 방향벡터와 교점의 법선벡터의 내적이 음수이면 광선은 앞면(객체의)에 hit 한 것이다
	rec->front_face = (vec_dot(r->dir, rec->normal) < 0);
	// 광선의 앞면에 hit 면 그대로 아니면 법선을 반대로 뒤집는다. (항상 광선 방향벡터와 법선 벡터를 반대인 상태로 사용하기위해)
	rec->normal = (rec->front_face) ? rec->normal : vec_mul_num(-1.0, rec->normal);
}

// chapter 6.3
int   hit_sphere(t_vec center, double radius, t_ray ray, t_hit_record *rec) {
    t_vec oc;
    double a;
    double b;
    double c;
    double discriminant;;

    oc = vec3(ray.orig.x - center.x, ray.orig.y - center.y, ray.orig.z - center.z);
    a = vec_dot(ray.dir, ray.dir);
    b = 2.0 * vec_dot(oc, ray.dir);
    c = vec_dot(oc, oc) - radius * radius;
    discriminant = b * b - 4 * a * c;
    
    if (discriminant < 0)
        return (0); // false
    
    double root = ((-b - sqrt(discriminant) / (2.0 * a)));
    if (root < rec->tmin || rec->tmax < root) {
        root = (-b + sqrt(discriminant)) / (2.0 * a);
        if (root < rec->tmin || rec->tmax < root)
            return (0); //false
    }

    rec->t = root;
    rec->p = ray_at(ray, rec->t);
    rec->normal = vec3((rec->p.x - center.x) / radius,
                    (rec->p.y - center.y) / radius,
                    (rec->p.z - center.z) / radius);
    set_face_normal(&ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장.
    return (1); //true
}

// chapter 6.2
// double hit_sphere(t_vec center, double radius, t_ray ray) {
//     t_vec oc = vec3(ray.orig.x - center.x, ray.orig.y - center.y, ray.orig.z - center.z);
//     double a = vec_dot(ray.dir, ray.dir);
//     double b = 2.0 * vec_dot(oc, ray.dir);
//     double c = vec_dot(oc, oc) - radius * radius;
//     double discriminant = b * b - 4 * a * c;
//     if (discriminant < 0)
//         return (-1.0);
//     else
//         return ((-b - sqrt(discriminant) / (2.0 * a)));
// }