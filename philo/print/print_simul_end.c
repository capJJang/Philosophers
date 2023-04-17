/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_simul_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:41:00 by segan             #+#    #+#             */
/*   Updated: 2023/04/17 21:42:22 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_simul_end(pthread_mutex_t *printer)
{
	pthread_mutex_lock(printer);
	printf("simulation end\n");
	pthread_mutex_unlock(printer);
}
