/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:01:15 by segan             #+#    #+#             */
/*   Updated: 2023/04/03 12:04:46 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_philos(t_philo **philos)
{
	int			i;
	const int	len = philos[0]->rule->num_of_philos;

	i = 0;
	while (i < len)
	{
		printf("---------------\n");
		printf("%dst philo\n", i + 1);
	}
}
