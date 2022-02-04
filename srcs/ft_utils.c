/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:53:20 by guderram          #+#    #+#             */
/*   Updated: 2022/02/04 23:05:25 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// void	ft_putnbr(long nb)
// {
// 	if (nb != -2147483648)
// 	{
// 		if (nb < 0)
// 		{
// 			nb = nb * -1;
// 			ft_putchar('-');
// 		}
// 		if (nb > 9)
// 		{
// 			ft_putnbr(nb / 10);
// 			ft_putnbr(nb % 10);
// 		}
// 		else
// 			ft_putchar(nb + '0');
// 	}
// 	else
// 	{
// 		ft_putchar('-');
// 		ft_putchar('2');
// 		ft_putnbr(147483648);
// 	}
// }

void	ft_putnbr(unsigned long long nb)
{
	char	c;

	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

// void	ft_print_philo_status(t_point *strc) // A SUPPRIMER
// {
// 	int i = 0;

// 	while (i < strc->nphi)
// 	{
// 		printf("philo '%ld' ", strc->phi[i].pos);
// 		printf("tdie '%ld' ", strc->phi[i].last_eat);
// 		printf("\n");
// 		i++;
// 	}
// }

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
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

int	ft_isdigit(int c) // 1 si oui, 0 si non
{
	if ((48 <= c) && (c <= 57))
		return (1);
	else
		return (0);
}

unsigned long long	ft_get_time(void) // TEST
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

