/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:52:52 by segan             #+#    #+#             */
/*   Updated: 2023/03/29 22:06:20 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_err_invalid_arg(void)
{
	write(2, "invalid arguments\n", 18);
	return (0);
}

int	print_err_enomem(void)
{
	write(2, "malloc failed\n", 14);
	return (0);
}
