/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:46:09 by najlee            #+#    #+#             */
/*   Updated: 2021/04/06 20:48:03 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

int main()
{
	void	*mlx_ptr;
	void	*win_ptr; // 생성할 윈도우를 가리키는 포인터
	
	mlx_ptr = mlx_init();	
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hellow World!"); 
	mlx_loop(mlx_ptr); // 생성한 윈도우가 있는 mlx_ptr을 rendering한다. 
	return (0);
}
