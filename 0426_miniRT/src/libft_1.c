#include "../includes/minirt.h"

size_t ft_strlen(char *str){
	int i = 0;
	while(str[i])
		i++;
	return i;
}

static char			**ft_freeall(char **s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *ptr;

	ptr = s;
	while (n-- > 0)
		*ptr++ = c;
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	char *tmp;

	tmp = malloc(count * size);
	if (!tmp)
		return (0);
	ft_memset(tmp, 0, count * size);
	return (tmp);
}



size_t				ft_strlcpy(char *dst,  char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	if (!dst)
		return (0);
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}