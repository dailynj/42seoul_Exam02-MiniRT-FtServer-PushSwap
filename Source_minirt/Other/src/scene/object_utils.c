/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:36:07 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 02:22:17 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_objects		*obj_new(int obj_type, void *object, t_texture *texture)
{
	t_objects	*new;

	if (!(new = (t_objects *)malloc(sizeof(t_objects))))
		return (0);
	new->next = 0;
	new->type = obj_type;
	new->object = object;
	new->texture = texture;
	new->rotate = NULL;
	new->rotate_normal = NULL;
	return (new);
}

void			obj_add_back(t_objects **lst, t_objects *new)
{
	t_objects	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
