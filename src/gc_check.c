/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:40:39 by sperron           #+#    #+#             */
/*   Updated: 2024/10/26 18:04:56 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/garbage_collector.h"

bool	is_ptr_in_trash(t_garb_c *trash, void *ptr)
{
	size_t	i;

	i = 0;
	while (i < trash->count)
	{
		if (trash->ptr_arr[i] == ptr)
			return (true);
		i++;
	}
	return (false);
}
