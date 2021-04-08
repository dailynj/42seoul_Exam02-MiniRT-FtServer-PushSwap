/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:20:32 by najlee            #+#    #+#             */
/*   Updated: 2021/04/07 19:20:35 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_h

# include <math.h>
// # include <fcntl.h>
// # include <unistd.h>
// # include <stdlib.h>
// # include <stdio.h>
// # include <pthread.h>

// 벡터 구조체
typedef struct  s_vector {
    double      x;
    double      y;
    double      z;
}               t_vector;

// vector_operation.c
double          vec_length(t_vector vector);
t_vector        plus_two_vector(t_vector vector1, t_vector vector2);
t_vector        minus_two_vector(t_vector vector1, t_vector vector2);
t_vector        mul_two_vector(t_vector vector1, t_vector vector2);
t_vector        mul_num_vector(double t, t_vector vector1);
t_vector        div_num_vector(double t, t_vector vector1);
double          dot_product(t_vector vector1, t_vector vector2);
t_vector        cross_product(t_vector vector1, t_vector vector2);
t_vector        unit_vector(t_vector vector1);

#endif