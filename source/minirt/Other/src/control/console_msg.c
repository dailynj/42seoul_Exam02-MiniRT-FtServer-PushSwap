/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:28:26 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:30:08 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

static void		default_msg(void)
{
	system("clear");
	printf("* ~ * ~ * DEFAULT MODE * ~ * ~ *\n");
	printf("* ~ * ~ * ~ KEYBOARD ~ * ~ * ~ *\n");
	printf("*   O KEY  :  LIGHT ON / OFF   *\n");
	printf("*   C KEY  :  CAMERA MODE      *\n");
	printf("*   L KEY  :  LIGHT MODE       *\n");
	printf("*   1 KEY  :  SEPHIA FILTER    *\n");
	printf("*   2 KEY  :  RED FILTER       *\n");
	printf("*   3 KEY  :  GREEN FILTER     *\n");
	printf("*   4 KEY  :  BLUE FILTER      *\n");
	printf("*   9 KEY  :  FILTER REMOVE    *\n");
	printf("*   SPACE  :  RENDER START     *\n");
	printf("* ~ * ~ * ~  MOUSE  ~ * ~ * ~  *\n");
	printf("* LEFT BUTTON  : OBJECT SELECT *\n");
}

static void		object_msg(void)
{
	system("clear");
	printf("* ~ * ~ OBJECT MODE ~ * ~ *\n");
}

static void		camera_msg(void)
{
	system("clear");
	printf("* ~ * ~ CAMERA MODE ~ * ~ *\n");
}

static void		light_msg(void)
{
	system("clear");
	printf("* ~ * ~ LIGHT MODE ~ * ~ *\n");
}

void			console_message(int mode)
{
	if (mode == DEFM)
		default_msg();
	if (mode == OBJM)
		object_msg();
	if (mode == CAMM)
		camera_msg();
	if (mode == LIGM)
		light_msg();
}
