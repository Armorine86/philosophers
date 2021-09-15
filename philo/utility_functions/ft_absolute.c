/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:49:15 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/15 10:36:28 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_abs(int num)
{
	if (num < 0)
		num = -num;
	return (num);
}
