/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:43:20 by guderram          #+#    #+#             */
/*   Updated: 2022/02/09 11:48:37 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_still_alive_bis(t_point *strc, long feed, long i)
{
	if (strc->stop != 0 && feed != strc->ntpe)
	{
		ft_print_message(strc, i, "died");
		return (0);
	}
	if (feed == strc->nphi)
	{
		strc->stop = 1;
		return (0);
	}
	return (1);
}

long	ft_long_atoi(const char *nptr)
{
	long	re;
	long	i;
	long	sig;

	i = 0;
	sig = 1;
	re = 0;
	while ((nptr[i] == '\n') || (nptr[i] == '\t') || (nptr[i] == '\v')
		|| (nptr[i] == '\f') || (nptr[i] == '\r') || (nptr[i] == ' '))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			sig = -sig;
		i++;
	}
	while ((48 <= nptr[i]) && (nptr[i] <= 57))
	{
		re = (re * 10) + (nptr[i] - 48);
		i++;
	}
	return (re * sig);
}

void	ft_print_message(t_point *strc, long pos, char *msg)
{
	unsigned long long	time;

	pthread_mutex_lock(&strc->say_message);
	time = ft_get_time();
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(pos + 1);
	ft_putchar(' ');
	ft_putstr(msg);
	ft_putchar('\n');
	pthread_mutex_unlock(&strc->say_message);
}
