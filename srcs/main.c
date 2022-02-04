/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:51:37 by guderram          #+#    #+#             */
/*   Updated: 2022/02/04 22:44:53 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_init_philo(t_point *strc) // initialise les philos
{
	int i;

	i = 0;
	strc->phi = malloc(sizeof(v_point) * strc->nphi);
	if (strc->phi == NULL)
		return(ft_free_malloc(3, strc));
	while (i < strc->nphi)
	{
		strc->phi[i].pos = i;
		strc->phi[i].last_eat = ft_get_time();
		strc->phi[i].strc = strc;
		strc->phi[i].nbr_eat = 0;
		pthread_mutex_init(&strc->phi[i].fork, NULL);
		i++;
	}
	i = 0;
	while (i < strc->nphi)
	{
		pthread_create(&strc->phi[i].thread, NULL, ft_taches, (void *)&strc->phi[i]);
		i++;
	}
	return (1);
}

int	ft_init_struct(char **str, t_point *strc, int argc) // initialise la structure de donnees, 1 OK sinon 0
{
	strc->argc = argc - 1;
	strc->nphi = ft_long_atoi(str[1]);
	strc->tdie = ft_long_atoi(str[2]);
	strc->teat = ft_long_atoi(str[3]);
	strc->tslp = ft_long_atoi(str[4]);
	strc->stop = 0;
	pthread_mutex_init(&strc->take_forks, NULL);
	pthread_mutex_init(&strc->say_message, NULL);
	if (argc == 6)
		strc->ntpe = ft_long_atoi(str[5]);
	else
		strc->ntpe = -1; // initialise sur une valeur non utilisee
	if (strc->nphi <= 0)
		return (0);
	if (strc->tdie <= 0)
		return (0);
	if (strc->teat <= 0)
		return (0);
	if (strc->tslp <= 0)
		return (0);
	if (argc == 6 && strc->ntpe <= 0)
		return (0);
	return (1);
}

int	ft_verif_argv(char **str, int argc) // ret 1 OK, sinon ret 0 PB
{
	int i;
	int u;

	i = 1; // prend pas le premier arg car nom de l'executable
	u = 0;
	while (i < argc)
	{
		while (str[i][u] != '\0')
		{
			if (ft_isdigit(str[i][u]) == 0)
				return (0);
			u++;
		}
		u = 0;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_point	strc;
	if (argc < 5 || argc > 6)
		return (ft_exit_error(1));
	if (ft_verif_argv(argv, argc) == 0)
		return (ft_exit_error(2));
	
	if (ft_init_struct(argv, &strc, argc) == 0)
		return (ft_exit_error(2));
	// strc.time = ft_get_time();
	// printf("heure : '%ld'\n", strc.time);
	if (ft_init_philo(&strc) == 0)
		return (-1);
	
	// ft_print_philo_status(&strc);
	// if (ft_go_taches(&strc) != 1)
	// 	return (-1);
	// strc.phi.pos = 45;
	// printf("phi : %d", strc.phi.pos);
	// printf("main :\n'%d'\n'%ld'\n'%ld'\n'%ld'\n'%ld'\n'%ld'\n", strc.argc, strc.nphi, strc.tdie, strc.teat, strc.tslp, strc.ntpe);
	while (ft_still_alive(&strc) == 1)
	{
	}
	return (0);
}
