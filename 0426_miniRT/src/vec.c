#include "../includes/minirt.h"

t_vec vec(double x, double y, double z)
{
		t_vec out;
		out.x = x;
		out.y = y;
		out.z = z;
		return (out);
}

// 벡터의 길이 구하기
double          vec_length(t_vec vector)
{
    return (sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2)));
}

// 두 벡터 더하기
t_vec        vec_add(t_vec vector1, t_vec vector2)
{
    t_vec    vector;

    vector.x = vector1.x + vector2.x;
    vector.y = vector1.y + vector2.y;
    vector.z = vector1.z + vector2.z;
    return (vector);
}

// 두 벡터 빼기
t_vec        vec_minus(t_vec vector1, t_vec vector2)
{
    t_vec    vector;

    vector.x = vector1.x - vector2.x;
    vector.y = vector1.y - vector2.y;
    vector.z = vector1.z - vector2.z;
    return (vector);
}

// 두 벡터 곱하기
t_vec        vec_mul(t_vec vector1, t_vec vector2)
{
    t_vec    vector;

    vector.x = vector1.x * vector2.x;
    vector.y = vector1.y * vector2.y;
    vector.z = vector1.z * vector2.z;
    return (vector);
}

// 벡터에 상수 곱하기
t_vec        vec_mul_num(double t, t_vec vector1)
{
    t_vec    vector;

    vector.x = vector1.x * t;
    vector.y = vector1.y * t;
    vector.z = vector1.z * t;
    return (vector);
}

// 벡터에 상수 나누기
t_vec        vec_div(double t, t_vec vector1)
{
    t_vec    vector;

    vector.x = vector1.x * (1/t);
    vector.y = vector1.y * (1/t);
    vector.z = vector1.z * (1/t);
    return (vector);
}

// 두 벡터 내적
double          vec_dot(t_vec vector1, t_vec vector2)
{
    return (vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z);
}

// 두 벡터 외적
t_vec        vec_cross(t_vec vector1, t_vec vector2)
{
    t_vec    vector;

    vector.x = vector1.y * vector2.z - vector1.z * vector2.y;
    vector.y = vector1.x * vector2.z - vector1.z * vector2.x;
    vector.z = vector1.x * vector2.y - vector1.y * vector2.x;
    return (vector);
}
// 단위 벡터
t_vec        vec_unit(t_vec vector1)
{
    t_vec    vector;

    vector.x = vector1.x / vec_length(vector1);
    vector.y = vector1.y / vec_length(vector1);
    vector.z = vector1.z / vec_length(vector1);
    return (vector);
}

t_vec vec_min(t_vec vec1, t_vec vec2)
{
    t_vec    vector;

    vector.x = fmin(vec1.x , vec2.x);
    vector.y = fmin(vec1.y , vec2.y);
    vector.z = fmin(vec1.z , vec2.z);
    return (vector);
}

t_vec		vsymmetric(t_point p1, t_point stan)
{
	t_point	result;

	result.x = 2 * stan.x - p1.x;
	result.y = 2 * stan.y - p1.y;
	result.z = 2 * stan.z - p1.z;
	return (result);
}