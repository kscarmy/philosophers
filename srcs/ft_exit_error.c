/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:23:41 by guderram          #+#    #+#             */
/*   Updated: 2021/10/19 20:18:21 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_exit_error(int error) // exit with the proper error message
{
	if (error == 1)
		ft_putstr("Nombre d'arguments invalides !\n");
	if (error == 2)
		ft_putstr("Les arguments demandes ne comporte que des nombres entiers positifs\n");
	return (-1);
}
