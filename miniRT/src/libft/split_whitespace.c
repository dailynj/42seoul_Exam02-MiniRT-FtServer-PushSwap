/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:51:23 by najlee            #+#    #+#             */
/*   Updated: 2021/05/17 13:43:16 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

size_t	ft_wordcnt_whitespace(char *s)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != 9 && s[i] != 10 && s[i] != 11 && s[i] != 12
						&& s[i] != 13 && s[i] != 32)
		{
			cnt++;
			while (s[i] && (s[i] != 9 && s[i] != 10 && s[i] != 11
				&& s[i] != 12 && s[i] != 13 && s[i] != 32))
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

char	*ft_worddup_whitespace(char *s)
{
	size_t	len;
	char	*ptr;

	len = 0;
	while (s[len] && (s[len] != 9 && s[len] != 10 && s[len] != 11
					&& s[len] != 13 && s[len] != 32))
		len++;
	if (!(ptr = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

char	**ft_split_whitespace(char *s)
{
	char	**ptr;
	int		len;
	int		idx[5];

	ft_memset(idx, 0, 5);
	if (!s)
		return (NULL);
	len = ft_wordcnt_whitespace(s);
	if (!(ptr = (char **)ft_calloc(len + 1, sizeof(char *))))
		return (NULL);
	while (idx[0] < len && s[idx[1]])
	{
		if ((!(9 <= s[idx[1]] && s[idx[1]] <= 13)) && s[idx[1]] != 32)
		{
			if (!(ptr[idx[0]++] = ft_worddup_whitespace(&(s[idx[1]]))))
				return (ft_freeall(ptr));
			while (s[idx[1]] && (!(9 <= s[idx[1]] && s[idx[1]] <= 13))
							&& s[idx[1]] != 32)
				idx[1]++;
		}
		else
			idx[1]++;
	}
	return (ptr);
}
