#include "minirt.h"

// create color
t_color		color(double r, double g, double b)
{
	t_color c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

int write_color(int t, t_color pixel_color)
{
	return (t << 24 | (int)(pixel_color.r * 255) << 16 | (int)(pixel_color.g * 255) << 8 | (int)(pixel_color.b * 255));
}

// Image의 크기 및 종횡비, Projection 공간에서 나타나는 Vector에 따른 색상을 결정
t_color		ray_color(t_ray ray)
{
	t_vector unit_direction = unit_vector(ray.dir);
    double t = (0.5 * (unit_direction.y + 1.0));
    return (plus_two_color(mul_num_color((1.0 - t), color(0.3, 0.4, 1.0)), mul_num_color(t, color(0.9, 0.9, 1.0))));
}

t_color     plus_two_color(t_color color1, t_color color2)
{
    t_color c;

	c.r = color1.r + color2.r;
	c.g = color1.g + color2.g;
    c.b = color1.b + color2.b;
	return (c);
}

t_color     mul_num_color(double t, t_color color)
{
    t_color c;

	c.r = t * color.r;
	c.g = t * color.g;
    c.b = t * color.b;
	return (c);
}

int			color_to_trgb(t_color color)
{
	return (0 << 24 | (int)color.r << 16 | (int)color.g << 8 | (int)color.b);
}

int         get_t(int trgb)
{
  return (trgb & (0xFF << 24));
}

int         get_r(int trgb)
{
  return (trgb & (0xFF << 16));
}

int         get_g(int trgb)
{
  return (trgb & (0xFF << 8));
}

int         get_b(int trgb)
{
  return (trgb & 0xFF);
}
