/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:29:52 by sperron           #+#    #+#             */
/*   Updated: 2024/10/27 23:07:48 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/garbage_collector.h"

void	free_all(t_garb_c *trash)
{
	size_t	i;

	i = 0;
	if (trash == NULL)
		return ;
	while (i < trash->count)
	{
		free(trash->ptr_arr[i]);
		trash->ptr_arr[i] = NULL;
		i++;
	}
	free(trash->ptr_arr);
	trash->ptr_arr = NULL;
	trash->count = 0;
	trash->capacite = 0;
}
