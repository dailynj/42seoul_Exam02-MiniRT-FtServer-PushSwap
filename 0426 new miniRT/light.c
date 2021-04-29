#include "minirt.h"

t_light		*light_point(t_vec light_origin, t_color light_color, double bright_ratio)
{
	t_light	*light;

	if(!(light = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}

t_color		phong_lighting(t_scene *scene)
{
	t_color	light_color;
	t_object	*lights;

	light_color = color(0, 0, 0); //광원이 하나도 없다면, 빛의 양은 (0, 0, 0)일 것이다.
	lights = scene->light;
	while (lights) //여러 광원에서 나오는 모든 빛에 대해 각각 diffuse, specular 값을 모두 구해줘야 한다
	{
		if(lights->type == LIGHT_POINT)
			light_color = vec_add(light_color, point_light_get(scene, lights->element));
		lights = lights->next;
	}
	light_color = vec_add(light_color, scene->ambient);
	return (vec_minus(vec_mul(light_color, scene->rec.albedo), color(1, 1, 1)));
	//모든 광원에 의한 빛의 양을 구한 후, 오브젝트의 반사율과 곱해준다. 그 값이 (1, 1, 1)을 넘으면 (1, 1, 1)을 반환한다.
}

t_color		point_light_get(t_scene *scene, t_light *light)
{
	t_color		diffuse;
	t_vec		light_dir;
	double		kd; // diffuse의 강도
	t_color		specular;
	t_vec		view_dir;
	t_vec		reflect_dir;
	double		spec;
	double		ksn;
	double		ks;

	light_dir = vec_unit(vec_minus(light->origin, scene->rec.p)); //교점에서 출발하여 광원을 향하는 벡터(정규화 됨)
	// cosΘ는 Θ 값이 90도 일 때 0이고 Θ가 둔각이 되면 음수가 되므로 0.0보다 작은 경우는 0.0으로 대체한다.
	kd = fmax(vec_dot(scene->rec.normal, light_dir), 0.0);// (교점에서 출발하여 광원을 향하는 벡터)와 (교점에서의 법선벡터)의 내적값.
	diffuse = vec_mul_num(kd, light->light_color);
	view_dir = vec_unit(vec_mul_num(-1, scene->ray.dir));
	reflect_dir = reflect(vec_mul_num(-1, light_dir), scene->rec.normal);
	ksn = 64; // shininess value
	ks = 0.5; // specular strength
	spec = pow(fmax(vec_dot(view_dir, reflect_dir), 0.0), ksn);
	specular = vec_mul_num(spec, vec_mul_num(ks, light->light_color));
	return (vec_add(diffuse, specular));
	return (diffuse);
}

t_vec			reflect(t_vec v, t_vec n)
{
	//v - 2 * dot(v, n) * n;
	return (vec_minus(v, vec_mul_num(vec_dot(v, n) * 2, n)));
}