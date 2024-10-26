/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:23:41 by sperron           #+#    #+#             */
/*   Updated: 2024/10/26 18:12:08 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/garbage_collector.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n && dest != src)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*dest;

	if (new_size == 0)
		return (free(ptr), NULL);
	dest = malloc(new_size);
	if (!dest)
		exit(1);
	if (ptr)
	{
		if (old_size < new_size)
			ft_memcpy(dest, (const void *)ptr, old_size);
		else
			ft_memcpy(dest, (const void *)ptr, new_size);
		free(ptr);
	}
	return (dest);
}
