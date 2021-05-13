/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:51:18 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:44:58 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

size_t	ft_wordcnt_char(char *s, char d)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != d)
		{
			cnt++;
			while (s[i] && s[i] != d)
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

char	*ft_worddup_char(char *s, char d)
{
	size_t	len;
	char	*ptr;

	len = 0;
	while (s[len] && s[len] != d)
		len++;
	if (!(ptr = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

char	**ft_split_char(char *s, char d)
{
	char	**ptr;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	len = ft_wordcnt_char(s, d);
	if (!(ptr = (char **)ft_calloc(len + 1, sizeof(char *))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < len && s[j])
	{
		if (s[j] != d)
		{
			if (!(ptr[i++] = ft_worddup_char(&(s[j]), d)))
				return (ft_freeall(ptr));
			while (s[j] && s[j] != d)
				j++;
		}
		else
			j++;
	}
	return (ptr);
}
