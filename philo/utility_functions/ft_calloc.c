/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:51:30 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/03 12:56:08 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t ele, size_t size)
{
	void	*ptr;

	ptr = malloc(ele * size);
	if (ptr == 0)
		return (0);
	ft_memset(ptr, 0, ele * size);
	return (ptr);
}
