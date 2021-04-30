/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:09:12 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/15 08:33:17 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "trace.h"
#include "scene.h"
#include "control.h"

int		main(int argc, char *argv[])
{
	t_cntl		cntl;

	if (argc == 2)
	{
		if (file_type_check(argv[1], ".rt") == 0)
		{
			printf("FIRST ARG MUST BE END WITH '.rt'\n");
			exit(0);
		}
		cntl_init(&cntl, argv[1]);
		my_mlx_control(&cntl);
	}
	else if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 10) != 0)
		{
			printf("SECOND ARG MUST BE '--save'\n");
			exit(0);
		}
		cntl_init_except_resolution(&cntl, argv[1]);
		bmp_save_direct(&cntl);
	}
	else
		printf("WRONG ARGC");
	return (0);
}
