#include "minirt.h"

// create color
t_color		color(double r, double g, double b)
{
	t_color c;

	c.x = r;
	c.y = g;
	c.z = b;
	return (c);
}

int write_color(int t, t_color pixel_color)
{
	return (t << 24 | (int)(pixel_color.x * 255) << 16 | (int)(pixel_color.y * 255) << 8 | (int)(pixel_color.z * 255));
}

// Image의 크기 및 종횡비, Projection 공간에서 나타나는 Vector에 따른 색상을 결정
t_vec   	ray_color(t_ray r)
{
	t_vec unit_direction = vec_unit(r.dir);
    double t = 0.5 * (unit_direction.y + 1.0);
    return vec_add(vec_mul_num(1.0 - t, color(1.0, 1.0, 1.0)), vec_mul_num(t, color(0.5, 0.7, 1.0)));
}