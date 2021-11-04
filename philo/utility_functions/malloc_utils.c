/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:45:57 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/04 14:46:16 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = s;
	while (i < n)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t ele, size_t size)
{
	void	*ptr;

	ptr = malloc(ele * size);
	if (ptr == 0)
		return (0);
	ft_memset(ptr, 0, ele * size);
	return (ptr);
}
