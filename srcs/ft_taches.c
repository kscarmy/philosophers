/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taches.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:48:32 by guderram          #+#    #+#             */
/*   Updated: 2021/11/16 21:09:08 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_time_to_eat(v_point *phi) // fait manger un philo
{
	size_t	time;

	phi->tstart = 0;
	time = ft_get_time();
	ft_putnbr(time);
	ft_putstr(" ");
	ft_putnbr(phi->pos);
	ft_putstr(" is eating\n");
	usleep(phi->strc->teat);
	phi->tstart = (long)ft_get_time;
	
}

void	*ft_taches(void *ptr) // execute les differentes taches requise
{
	v_point *phi;
	size_t time;
	int i; // garde fou 

	i = 0; // garde fou

	phi = (v_point *)ptr;
	time = ft_get_time();
	phi->tstart = time;
	// printf("")
	// ft_still_alive(phi) == 1
	while (i < 10)
	{
		printf("[%ld]bif : '%ld' ", phi->pos,(long)(time - phi->tstart));
		if ((long)(time - phi->tstart) >= 1)
		{
			ft_time_to_eat(phi);
		}
		// printf(" test\n");
		usleep(1000);
		// printf(" test 2\n");
		time = ft_get_time();
		printf("dans still alive : %ld\n", (long)(time - phi->tstart));
		i++;
	}
	printf("ok jusque ici : %ld, %ld\n", phi->pos, phi->strc->tdie);

	return (0);
}

int		ft_still_alive(v_point *phi) // ret 1 ok sinon erreur
{
	size_t time;

	time = ft_get_time();	
	if (((long)(time - phi->tstart) >= phi->strc->tdie) && phi->tstart != 0)
	{
		printf("MORT DE %ld : ", phi->pos);
		printf("%ld\n", (long)(time - phi->tstart));
		
		return (0);
	}
	return (1);
}

int		ft_go_taches(t_point *strc) // ret 1 ok sinon erreur
{
	pthread_t thread;
	int	i;

	i = 0;
	while (i < strc->nphi)
	{
		if (pthread_create(&thread, NULL, &ft_taches, (void *)&strc->phi[i]))
			return (ft_free_malloc(4, strc)); // ret error thread
		pthread_detach(thread);
		i++;
		usleep(1);
	}
	// while (ft_still_alive(strc) == 1)
	// {
	// }
	return (1);
}
