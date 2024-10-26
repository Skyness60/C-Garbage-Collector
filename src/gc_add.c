/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:27:51 by sperron           #+#    #+#             */
/*   Updated: 2024/10/26 18:22:02 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/garbage_collector.h"

void	add_ptr(t_garb_c *trash, void *ptr)
{
	void	**new_ptr;

	new_ptr = NULL;
	if (ptr == NULL)
		return ;
	if (is_ptr_in_trash(trash, ptr))
		return ;
	if (trash->count == trash->capacite)
	{
		trash->capacite *= 2;
		new_ptr = ft_realloc((void *)trash->ptr_arr, \
		trash->count * sizeof(void *), trash->capacite * sizeof(void *));
		if (!new_ptr)
			exit(1);
		trash->ptr_arr = new_ptr;
	}
	trash->ptr_arr[trash->count++] = ptr;
}

void	add_ptr_tab(t_garb_c *trash, void **ptr_arr, int arr_len, \
bool is_malloced)
{
	int	i;

	i = 0;
	while (i < arr_len)
		add_ptr(trash, ptr_arr[i++]);
	if (is_malloced == true)
		add_ptr(trash, ptr_arr);
}
