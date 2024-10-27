/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:22:37 by sperron           #+#    #+#             */
/*   Updated: 2024/10/27 23:09:41 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/garbage_collector.h"

void	debug_gc(t_garb_c *trash)
{
	size_t	i;

	i = -1;
	if (trash == NULL)
		return ;
	printf("=== Garbage Collector Stats ===\n");
	printf("Nombre de pointeurs : %zu\n", trash->count);
	printf("Capacité : %zu\n", trash->capacite);
	printf("Mémoire utilisée : %zu octets\n", trash->count * sizeof(void *));
	while (++i < trash->count)
		printf("Pointer %zu: %p\n", i, trash->ptr_arr[i]);
	printf("================================\n");
}
