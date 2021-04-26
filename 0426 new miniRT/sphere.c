#include "minirt.h"

int hit_sphere(t_vec center, double radius, t_ray r) {
    t_vec oc = vec(r.origin.x - center.x, r.origin.y - center.y, r.origin.z - center.z);
    double a = vec_dot(r.dir, r.dir);
    double b = 2.0 * vec_dot(oc, r.dir);
    double c = vec_dot(oc, oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
		return (-1);
	else
		return ((-b - sqrt(discriminant) / (2.0 * a)));
}