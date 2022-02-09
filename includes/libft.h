/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:50:58 by guderram          #+#    #+#             */
/*   Updated: 2022/02/09 14:05:06 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct p_point
{
	pthread_t			thread;
	long				pos;
	unsigned long long	last_eat;
	long				nbr_eat;
	pthread_mutex_t		fork;
	struct s_point		*strc;

}				t_pointp;

typedef struct s_point
{
	int				argc;
	long			nphi;
	long			tdie;
	long			teat;
	long			tslp;
	long			ntpe;
	int				stop;
	pthread_mutex_t	say_message;
	pthread_mutex_t	take_forks;
	t_pointp		*phi;
}				t_point;

int					ft_exit_error(int error);
int					ft_free_malloc(int error, t_point *strc);
void				ft_putchar(char c);
void				ft_putnbr(unsigned long long nb);
unsigned long long	ft_get_time(void);
int					ft_isdigit(int c);
void				ft_putstr(char *str);
int					ft_init_philo(t_point *str);
void				ft_start_thread(t_point *strc);
int					ft_verif_argv(char **str, int argc);
int					ft_init_struct(char **str, t_point *strc, int argc);
void				*ft_taches(void *ptr);
int					ft_go_taches(t_point *strc);
int					ft_still_alive(t_point *strc);
void				ft_time_to_eat(t_pointp *philo);
void				ft_time_to_take_forks(t_pointp *phi);
void				ft_print_message(t_point *strc, long pos, char *msg);
long				ft_long_atoi(const char *nptr);
int					ft_still_alive_bis(t_point *strc, long feed, long i);
#endif
