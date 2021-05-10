/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:44:29 by aroque            #+#    #+#             */
/*   Updated: 2020/09/22 21:54:55 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "camera.h"
#include "server.h"

/*
**	open_scene_file(): Open the scene file as a file
**	descriptor integer. If the file doesn't have the
**	correct extension or fails to open, the function
**	returns -1. Otherwise, it returns the scene fd.
**
**	@file: scene filesystem path.
**
**	Return: fd number in case of success, -1 otherwise.
*/

static int		open_scene_file(const char *file, int *errcode)
{
	int		fd;
	char	*ext;

	fd = -1;
	ext = ft_strrchr(file, '.');
	if (ext && !ft_strncmp(ext, EXTENSION, 0x100))
	{
		if ((fd = open(file, O_RDONLY)) < 0)
			*errcode = ERRSYS;
	}
	else
		*errcode = EBADEXT;
	return (fd);
}

/*
** new_world(): Allocate and returns a pointer to
** a struct s_world. Lists and other elements will
** be initialized as NULL.
**
** Return: struct s_world pointer if succesful, NULL otherwise;
*/

static t_world	*new_world(void)
{
	t_world	*world;

	if (!(world = malloc(sizeof(*world))))
		return (NULL);
	world->cameras = NULL;
	world->lights = NULL;
	world->figures = NULL;
	world->ambient = NULL;
	world->resolution = NULL;
	return (world);
}

/*
**	scene_initializer(const char *file): Initializes a new
**  struct s_world, based on information given on the .rt scene file.
**  If an error in found during the world parsing, the execution
**  will be terminated. Some error descriptions can be found
**  on the errcode.h header file.
**
**	@file: scene filesystem path.
**
**	Return: Pointer to struct s_world generated by the scene file.
*/

t_world			*scene_initializer(const char *file)
{
	int			fd;
	int			err;
	char		*note;
	t_world		*world;

	err = 0;
	note = NULL;
	if ((fd = open_scene_file(file, &err)) < 0)
		message_and_exit(err, 0x0);
	world = new_world();
	err = parser_file(fd, world, &note);
	if ((close(fd)) < 0)
		message_and_exit(ERRSYS, 0x0);
	if (err)
	{
		free_world(world);
		message_and_exit(err, note);
	}
	return (world);
}