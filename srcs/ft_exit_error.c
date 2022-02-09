/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:23:41 by guderram          #+#    #+#             */
/*   Updated: 2022/02/09 11:22:29 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_free_malloc(int error, t_point *strc)
{
	if (error == 3 || error == 4)
	{
		free(strc->phi);
		strc->phi = NULL;
	}
	if (error == 0)
		return (0);
	return (ft_exit_error(error));
}

int	ft_exit_error(int error)
{
	if (error == 1)
		ft_putstr("Nombre d'arguments invalides !\n");
	if (error == 2)
	{
		ft_putstr("Les arguments demandes ne ");
		ft_putstr("comporte que des nombres entiers positifs\n");
	}
	if (error == 3)
		ft_putstr("Erreur pendant la phase de malloc !\n");
	if (error == 4)
		ft_putstr("Erreur pendant la phase de creation du thread !\n");
	return (-1);
}
