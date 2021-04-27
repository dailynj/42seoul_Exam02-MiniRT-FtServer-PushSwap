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
t_vec				ray_color(t_ray ray, t_sphere *sphere)
{
	double			t;
	t_hit_record	rec;
	// t_vec			N;
	// t_vec			center = point3(0, 0, -1);
	
	// 그라데이션 구 그리기
	rec.tmin = 0;
	rec.tmax = INFINITY;

	if (hit_sphere(sphere, &ray, &rec))
		return (vec_mul_num(0.5, vec_add(rec.normal, color(1, 1, 1))));

	// 하늘
	t_vec unit_direction = vec_unit(ray.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	return (vec(1.0 - 0.5 * t, 1.0 - 0.3 * t, 1.0));
}