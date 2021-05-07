/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:53:43 by najlee            #+#    #+#             */
/*   Updated: 2021/01/13 20:59:01 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define OPEN_MAX 256

int		ft_final(char **backup, char **line, ssize_t read_len);
void	ft_fill_line(char **backup, char **line, ssize_t nl_line);
ssize_t	ft_nl_index(char *backup);
int		get_next_line(int fd, char **line);
char	*ft_strdup(char *s1);
ssize_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
