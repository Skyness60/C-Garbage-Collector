/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:27:20 by sperron           #+#    #+#             */
/*   Updated: 2024/10/27 23:08:10 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/garbage_collector.h"

void	init_garbage_collector(t_garb_c *trash)
{
	trash->capacite = 2;
	trash->count = 0;
	trash->ptr_arr = malloc(trash->capacite * sizeof(void *));
	if (!trash->ptr_arr)
		return (gc_error(MALLOC_ERROR, trash));
	if (trash->verbose == true)
		gc_putstr("Garbage collector initialized\n");
}
