/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taches.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:48:32 by guderram          #+#    #+#             */
/*   Updated: 2022/02/09 10:15:29 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_message(t_point *strc, long pos, char *msg) // ecrit un message sur la sortie standard
{
	unsigned long long time;

	pthread_mutex_lock(&strc->say_message);
	time = ft_get_time();
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(pos + 1); // car lenonce demande que les phi soit de 1 a n
	ft_putchar(' ');
	ft_putstr(msg);
	ft_putchar('\n');
	pthread_mutex_unlock(&strc->say_message);
}

void	ft_time_to_take_forks(v_point *phi) // Fonction permettant au philo de prendre et lock le mutex des forks
{
	pthread_mutex_lock(&phi->strc->take_forks);
	pthread_mutex_lock(&phi->fork); // fork du philo
	ft_print_message(phi->strc ,phi->pos, "has taken a fork");
	if (phi->strc->nphi > 1)
	{
		if (phi->pos == 0) // si phi est le premier
			pthread_mutex_lock(&phi->strc->phi[phi->strc->nphi].fork); // alors prend la fork du dernier
		else
			pthread_mutex_lock(&phi->strc->phi[phi->pos - 1].fork); // sinon prend celle du phi precedent
		ft_print_message(phi->strc ,phi->pos, "has taken a fork");
	}
	pthread_mutex_unlock(&phi->strc->take_forks);

}

void	ft_time_to_eat(v_point *phi) // fait manger un philo
{
	phi->last_eat = ft_get_time(); // dernier repas de phi, temps pri au debut du repas
	ft_print_message(phi->strc ,phi->pos, "is eating");
	usleep(phi->strc->teat * 1000);

	/*			rend les fouchettes			*/
	pthread_mutex_unlock(&phi->fork); // fork du philo
	if (phi->pos == 0) // si phi est le premier
		pthread_mutex_unlock(&phi->strc->phi[phi->strc->nphi].fork); // alors rend la fork du dernier
	else
		pthread_mutex_unlock(&phi->strc->phi[phi->pos - 1].fork); // sinon rend celle du phi precedent
	// pthread_mutex_unlock(&phi->strc->take_forks);
	phi->nbr_eat = phi->nbr_eat + 1; // incre le nombre de repas de phi
}

void	*ft_taches(void *ptr) // execute les differentes taches requise
{
	v_point *phi;

	phi = (v_point *)ptr;
	// if (phi->strc->nphi > 1)
	// {
	ft_time_to_take_forks(phi);
	if (phi->strc->nphi > 1)
	{
		ft_time_to_eat(phi);


	/*		va dormir		*/
	
		ft_print_message(phi->strc ,phi->pos, "is sleeping");
		usleep(phi->strc->tslp * 1000);
		ft_print_message(phi->strc ,phi->pos, "is thinking");
	}
	if (phi->strc->stop == 0)
		ft_taches(ptr);
	// }	
	return (0);
}

// void	*ft_taches(void *ptr) // execute les differentes taches requise
// {
// 	v_point *phi;
// 	size_t time;
// 	int i; // garde fou 

// 	i = 0; // garde fou

// 	phi = (v_point *)ptr;
// 	time = ft_get_time();
// 	phi->tstart = time;
// 	// printf("")
// 	// ft_still_alive(phi) == 1
// 	while (i < 10)
// 	{
// 		printf("[%ld]bif : '%ld' ", phi->pos,(long)(time - phi->tstart));
// 		if ((long)(time - phi->tstart) >= 1)
// 		{
// 			ft_time_to_eat(phi);
// 		}
// 		// printf(" test\n");
// 		usleep(1000);
// 		// printf(" test 2\n");
// 		time = ft_get_time();
// 		printf("dans still alive : %ld\n", (long)(time - phi->tstart));
// 		i++;
// 	}
// 	printf("ok jusque ici : %ld, %ld\n", phi->pos, phi->strc->tdie);

// 	return (0);
// }

int		ft_still_alive(t_point *strc) // ret 1 ok sinon erreur
{
	long	i;
	unsigned long long time;
	long feed;

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
	// printf("tdie : %lu\n", (time - strc->phi[i].last_eat));
	if (strc->stop != 0 && feed != strc->ntpe)
	{
		// printf("time : %llu\n", time);
		// printf("last eat : %llu\n", strc->phi[i].last_eat);
		// printf("tdie : %llu\n", (time - strc->phi[i].last_eat));
		ft_print_message(strc, i, "died");
		return (0);
	}
	if (feed == strc->nphi)
	{
		strc->stop = 1;
		return (0);
	}

	// if (((long)(time - phi->last_eat) >= phi->strc->tdie) && phi->last_eat != 0)
	// {
	// 	printf("MORT DE %ld : ", phi->pos);
	// 	// printf("%ld\n", (long)(time - phi->last_eat));
		
	// 	return (0);
	// }
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
