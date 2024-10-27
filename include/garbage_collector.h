/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:06:17 by sperron           #+#    #+#             */
/*   Updated: 2024/10/27 23:11:17 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef enum e_error
{
	MALLOC_ERROR,
	REALLOC_ERROR,
}			t_error;

typedef struct s_garbage_c
{
	void	**ptr_arr;
	size_t	capacite;
	size_t	count;
	bool	verbose;
}	t_garb_c;

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	add_ptr(t_garb_c *trash, void *ptr);
void	add_ptr_tab(t_garb_c *trash, void **ptr_arr, int arr_len, \
bool is_malloced);
void	debug_gc(t_garb_c *trash);
void	init_garbage_collector(t_garb_c *trash);
void	free_all(t_garb_c *trash);
void	remove_ptr(t_garb_c *trash, void *ptr);
bool	is_ptr_in_trash(t_garb_c *trash, void *ptr);
void	gc_putstr(const char *str);
void	gc_error(t_error error, t_garb_c *trash);
#endif // !GARBAGE_COLLECTOR_H