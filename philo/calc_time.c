/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:59:55 by segan             #+#    #+#             */
/*   Updated: 2023/04/10 21:09:13 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	calc_time(struct timeval based_time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec - based_time.tv_sec) * 1000 + \
	(now.tv_usec - based_time.tv_usec) / 1000);
}

long long	calc_time2(struct timeval past, struct timeval present)
{
	return ((present.tv_sec - past.tv_sec) * 1000000L + \
	(present.tv_usec - past.tv_usec));
}
