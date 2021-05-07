#include "../includes/minirt.h"

// esc key press event
int	key_hook(int keycode, t_cntl *cntl)
{
	if(keycode == 53)
	{
		mlx_destroy_window(cntl->mlx, cntl->win);
		exit(0);
	}
	return (0);
}

// close button press event
int exit_hook()
{
	exit(0);
}