/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:50:58 by guderram          #+#    #+#             */
/*   Updated: 2021/11/06 11:27:57 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h> // OK : write
# include <sys/time.h> // OK : gettimeofday
# include <stdlib.h> // OK : malloc
# include <pthread.h> // ok : pthread



# include <stdio.h> // A SUPP : printf

typedef struct p_point // donnees du philo pos (position)
{
	long		pos; // position du philo dans la file
	long	tstart; // temps au debut
	struct s_point	*strc; // structure principale

}				v_point;

typedef struct s_point
{
	int		argc; // nombre arguments
	long	nphi; // nombre philosophesp
	long	tdie; // temps pour mourir
	long	teat; // temps pour manger
	long	tslp; // temps pour dormir
	long	ntpe; // Number of Times each Philosopher must Eat
	v_point *phi; // donnes d'un philo
	long	time; // heure
	int		*forks; // -1 = fourchette libre, sinon correspond au numero du philosophe l'utilisant
}				t_point;



// ft_exit_error.c
int		ft_exit_error(int error); // exit with the proper error message
int		ft_free_malloc(int error, t_point *strc); // free les mallocs et retourne une erreur si il y en a une : 0 pas d'erreurs tout est ok, sinon error et va sur ft_exit_error

// ft_utils.c
void	ft_putchar(char c);
void	ft_putnbr(long nb);

void	ft_print_philo_status(t_point *strc); // A SUPPRIMER
size_t	ft_get_time(void); // TEST

int		ft_isdigit(int c); // 1 si oui, 0 si non
long	ft_long_atoi(const char *nptr);
void	ft_putstr(char *str);

// main.c
int	ft_init_philo(t_point *str); // initialise les philos

int		ft_verif_argv(char **str, int argc); // ret 1 OK, sinon ret 0 PB
int	ft_init_struct(char ** str, t_point *strc, int argc); // initialise la structure de donnees, 1 OK sinon 0

// ft_taches.c
void	*ft_taches(void *ptr); // execute les differentes taches requise
int		ft_go_taches(t_point *strc); // ret 1 ok sinon erreur
int		ft_still_alive(v_point *phi); // ret 1 ok sinon erreur
void	ft_time_to_eat(v_point *philo); // fait manger un philo

#endif
