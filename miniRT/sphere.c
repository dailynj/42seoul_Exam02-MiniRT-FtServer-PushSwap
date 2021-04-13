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

double hit_sphere(t_vec center, double radius, t_ray ray) {
    t_vec oc = vec3(ray.orig.x - center.x, ray.orig.y - center.y, ray.orig.z - center.z);
    double a = vec_dot(ray.dir, ray.dir);
    double b = 2.0 * vec_dot(oc, ray.dir);
    double c = vec_dot(oc, oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return (-1.0);
    else
        return ((-b - sqrt(discriminant) / (2.0 * a)));
}
