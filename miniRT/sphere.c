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

int hit_sphere(t_vec center, double radius, t_ray r) {
    vec3 oc = vec(r.origin.x - center.x, r.origin.y - center.y, r.origin.z - center.z);
    double a = vec_dot(r.dir(), r.dir());
    double b = 2.0 * vec_dot(oc, r.dir());
    double c = vec_dot(oc, oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
		if (discriminant > 0)
				return (1);
		return (0);
}
