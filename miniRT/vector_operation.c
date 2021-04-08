/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:26:38 by najlee            #+#    #+#             */
/*   Updated: 2021/04/07 19:26:39 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

// 벡터의 길이 구하기
double          vec_length(t_vector vector)
{
    return (sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2)));
}

// 두 벡터 더하기
t_vector        plus_two_vector(t_vector vector1, t_vector vector2)
{
    t_vector    vector;

    vector.x = vector1.x + vector2.x;
    vector.y = vector1.y + vector2.y;
    vector.z = vector1.z + vector2.z;
    return (vector);
}

// 두 벡터 빼기
t_vector        minus_two_vector(t_vector vector1, t_vector vector2)
{
    t_vector    vector;

    vector.x = vector1.x - vector2.x;
    vector.y = vector1.y - vector2.y;
    vector.z = vector1.z - vector2.z;
    return (vector);
}

// 두 벡터 곱하기
t_vector        mul_two_vector(t_vector vector1, t_vector vector2)
{
    t_vector    vector;

    vector.x = vector1.x * vector2.x;
    vector.y = vector1.y * vector2.y;
    vector.z = vector1.z * vector2.z;
    return (vector);
}

// 벡터에 상수 곱하기
t_vector        mul_num_vector(double t, t_vector vector1)
{
    t_vector    vector;

    vector.x = vector1.x * t;
    vector.y = vector1.y * t;
    vector.z = vector1.z * t;
    return (vector);
}

// 벡터에 상수 나누기
t_vector        div_num_vector(double t, t_vector vector1)
{
    t_vector    vector;

    vector.x = vector1.x * (1/t);
    vector.y = vector1.y * (1/t);
    vector.z = vector1.z * (1/t);
    return (vector);
}

// 두 벡터 내적
double          dot_product(t_vector vector1, t_vector vector2)
{
    return (vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z);
}

// 두 벡터 외적
t_vector        cross_product(t_vector vector1, t_vector vector2)
{
    t_vector    vector;

    vector.x = vector1.y * vector2.z - vector1.z * vector2.y;
    vector.y = vector1.x * vector2.z - vector1.z * vector2.x;
    vector.z = vector1.x * vector2.y - vector1.y * vector2.x;
    return (vector);
}
// 단위 벡터
t_vector        unit_vector(t_vector vector1)
{
    t_vector    vector;

    vector.x = vector1.x / vec_length(vector1);
    vector.y = vector1.y / vec_length(vector1);
    vector.z = vector1.z / vec_length(vector1);
    return (vector);
}