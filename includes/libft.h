/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:50:58 by guderram          #+#    #+#             */
/*   Updated: 2021/10/20 13:59:01 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h> // OK : write
# include <sys/time.h> // OK : gettimeofday



# include <stdio.h> // A SUPP : printf

typedef struct p_point // donnees du philo pos (position)
{
	int		pos; // position du philo dans la file

}				v_point;

typedef struct s_point
{
	int		argc; // nombre arguments
	long	nphi; // nombre philosophes
	long	tdie; // temps pour mourir
	long	teat; // temps pour manger
	long	tslp; // temps pour dormir
	long	ntpe; // Number of Times each Philosopher must Eat
	v_point phi; // donnes d'un philo
	long	time; // heure
}				t_point;



// ft_exit_error.c
int		ft_exit_error(int error); // exit with the proper error message

// ft_utils.c
size_t	get_time(void); // TEST

int		ft_isdigit(int c); // 1 si oui, 0 si non
long	ft_long_atoi(const char *nptr);
void	ft_putstr(char *str);

// main.c
int		ft_verif_argv(char **str, int argc); // ret 1 OK, sinon ret 0 PB
int	ft_init_struct(char ** str, t_point *strc, int argc); // initialise la structure de donnees, 1 OK sinon 0


#endif
