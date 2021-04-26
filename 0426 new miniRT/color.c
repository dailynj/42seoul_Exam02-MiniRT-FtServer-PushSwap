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
	t_vec color;
	t_vec center = point3(0, 0, -1);
    // 빨간 구 그리기
    // color = vec(1, 0, 0);
	// if (hit_sphere(center, 0.5, r))
	// 	return (color);
	
	// 그라데이션 구 그리기
	
	double t = hit_sphere(center, 0.5, r);
	if (t > 0.0) // 만약 해가 있다면!
	{
		t_vec tmp = ray_at(&r, t); // t를 활용해서 tmp 벡터를 구한다.
		t_vec N = vec_unit(vec(tmp.x - 0, tmp.y - 0, tmp.z - (-1))); // tmp 벡터의 unit벡터를 구한다! 
		color = vec_mul_num(0.5, vec(N.x + 1, N.y + 1, N.z + 1));
		return (color);
	}  

	// 해가 없다면~!
	t_vec unit_direction = vec_unit(r.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	color = vec(1.0 - 0.5 * t, 1.0 - 0.3 * t, 1.0);
  return (color);
}