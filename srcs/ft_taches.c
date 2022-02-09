/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taches.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:48:32 by guderram          #+#    #+#             */
/*   Updated: 2022/02/09 14:03:50 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_time_to_take_forks(t_pointp *phi)
{
	pthread_mutex_lock(&phi->strc->take_forks);
	pthread_mutex_lock(&phi->fork);
	ft_print_message(phi->strc, phi->pos, "has taken a fork");
	if (phi->strc->nphi > 1)
	{
		if (phi->pos == 0)
			pthread_mutex_lock(&phi->strc->phi[phi->strc->nphi].fork);
		else
			pthread_mutex_lock(&phi->strc->phi[phi->pos - 1].fork);
		ft_print_message(phi->strc, phi->pos, "has taken a fork");
	}
	pthread_mutex_unlock(&phi->strc->take_forks);
}

void	ft_time_to_eat(t_pointp *phi)
{
	phi->last_eat = ft_get_time();
	ft_print_message(phi->strc, phi->pos, "is eating");
	usleep(phi->strc->teat * 1000);
	pthread_mutex_unlock(&phi->fork);
	if (phi->pos == 0)
		pthread_mutex_unlock(&phi->strc->phi[phi->strc->nphi].fork);
	else
		pthread_mutex_unlock(&phi->strc->phi[phi->pos - 1].fork);
	phi->nbr_eat = phi->nbr_eat + 1;
}

void	*ft_taches(void *ptr)
{
	t_pointp	*phi;

	phi = (t_pointp *)ptr;
	ft_time_to_take_forks(phi);
	if (phi->strc->nphi > 1)
	{
		ft_time_to_eat(phi);
		ft_print_message(phi->strc, phi->pos, "is sleeping");
		usleep(phi->strc->tslp * 1000);
		ft_print_message(phi->strc, phi->pos, "is thinking");
	}
	if (phi->strc->stop == 0)
		ft_taches(ptr);
	return (0);
}

int	ft_still_alive(t_point *strc)
{
	unsigned long long	time;
	long				i;
	long				feed;

	i = 0;
	feed = 0;
	time = ft_get_time();
	while (i < strc->nphi && strc->stop == 0)
	{
		if (strc->phi[i].nbr_eat == strc->ntpe)
			feed++;
		if ((time - strc->phi[i].last_eat) > (unsigned long long)strc->tdie)
			strc->stop = 1;
		else
			i++;
	}
	return (ft_still_alive_bis(strc, feed, i));
}

int	ft_go_taches(t_point *strc)
{
	pthread_t	thread;
	int			i;

	i = 0;
	while (i < strc->nphi)
	{
		if (pthread_create(&thread, NULL, &ft_taches, (void *)&strc->phi[i]))
			return (ft_free_malloc(4, strc));
		pthread_detach(thread);
		i++;
		usleep(1);
	}
	return (1);
}
