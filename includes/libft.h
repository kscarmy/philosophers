/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:50:58 by guderram          #+#    #+#             */
/*   Updated: 2022/02/09 09:23:29 by guderram         ###   ########.fr       */
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
	pthread_t thread;
	long		pos; // position du philo dans la file
	unsigned long long	last_eat; // dernier repas
	long	nbr_eat; // nombre de repas servis
	pthread_mutex_t	fork; // fourchette mutex
	struct s_point	*strc; // structure principale

}				v_point;

typedef struct s_point
{
	int		argc; // nombre arguments
	long	nphi; // nombre philosophes
	long	tdie; // temps pour mourir
	long	teat; // temps pour manger
	long	tslp; // temps pour dormir
	long	ntpe; // Number of Times each Philosopher must Eat
	int		stop; // 0 = OK, else STOP
	pthread_mutex_t	say_message; // permet de faire dire un message sans conflit
	pthread_mutex_t	take_forks; // permet de recuperer les deux fourchettes et lecrire en un bloc dans le tchat
	v_point *phi; // donnes d'un philo
	// unsigned long long	time; // heure
}				t_point;



// ft_exit_error.c
int		ft_exit_error(int error); // exit with the proper error message
int		ft_free_malloc(int error, t_point *strc); // free les mallocs et retourne une erreur si il y en a une : 0 pas d'erreurs tout est ok, sinon error et va sur ft_exit_error

// ft_utils.c
void	ft_putchar(char c);
void	ft_putnbr(unsigned long long nb);

void	ft_print_philo_status(t_point *strc); // A SUPPRIMER
unsigned long long	ft_get_time(void); // renvoie lheure

int		ft_isdigit(int c); // 1 si oui, 0 si non
long	ft_long_atoi(const char *nptr);
void	ft_putstr(char *str);

// main.c
int	ft_init_philo(t_point *str); // initialise les philos

int		ft_verif_argv(char **str, int argc); // ret 1 OK, sinon ret 0 PB
int	ft_init_struct(char ** str, t_point *strc, int argc); // initialise la structure de donnees, 1 OK sinon 0

// ft_taches.c
void	ft_print_message(t_point *strc, long pos, char *msg); // ecrit un message sur la sortie standard
void	*ft_taches(void *ptr); // execute les differentes taches requise
int		ft_go_taches(t_point *strc); // ret 1 ok sinon erreur
int		ft_still_alive(t_point *strc); // ret 1 ok sinon erreur
void	ft_time_to_eat(v_point *philo); // fait manger un philo

#endif
