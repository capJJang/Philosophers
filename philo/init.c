/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 05:00:32 by segan             #+#    #+#             */
/*   Updated: 2023/03/30 00:31:03 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//void	*init_table(t_rule rule)
//{

//}

void	*init_mutex(int num_of_forks)
{
	pthread_mutex_t	*mutex;
	int				i;

	i = 0;
	mutex = (pthread_mutex_t *) \
	malloc(sizeof(pthread_mutex_t) * (num_of_forks));
	if (mutex == NULL)
	{
		return (mutex);
	}
	while (i < num_of_forks)
		pthread_mutex_init(&mutex[i++], NULL);
	return (mutex);
}
