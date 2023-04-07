/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:59:55 by segan             #+#    #+#             */
/*   Updated: 2023/04/07 15:54:52 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	calc_time(struct timeval start_dining)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec - start_dining.tv_sec) * 1000000L + \
	(now.tv_usec - start_dining.tv_usec));
}
