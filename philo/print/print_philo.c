/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:01:15 by segan             #+#    #+#             */
/*   Updated: 2023/04/08 21:25:49 by segan            ###   ########.fr       */
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

void	print_rule(t_rule rule)
{
	printf("num of philo : %d\n", rule.num_of_philos);
	printf("time to die : %d\n", rule.time_to_die);
	printf("time to eat : %d\n", rule.time_to_eat);
	printf("time to sleep : %d\n", rule.time_to_sleep);
	printf("num of each philo eat : %d\n", rule.num_of_each_phil_eat);
}

void	print_philo_stat(t_philo *philo, int whoami, char *stat)
{
	long long		time;
	pthread_mutex_t	printer_mutex;

	time = calc_time(philo->dining_start);
	pthread_mutex_init(&printer_mutex, NULL);
	pthread_mutex_lock(&printer_mutex);
	if (philo->alive == false)
		return ;
	printf("%lld %d %s\n", time, whoami + 1, stat);
	pthread_mutex_unlock(&printer_mutex);
}
