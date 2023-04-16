/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:20:11 by segan             #+#    #+#             */
/*   Updated: 2023/04/17 02:06:08 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_everyones_death(t_philo **philo)
{
	int		i;
	bool	everyone_is_dead;
	bool	someone_died;

	i = 0;
	everyone_is_dead = true;
	someone_died = false;
	while (1)
	{
		if (philo[i]->alive == true)
		{
			if(someone_died)
			{
				kill_philo(philo, philo[0]->rule->num_of_philos);
				everyone_is_dead = true;
			}
		}
		else
		{
			kill_philo(philo, philo[0]->rule->num_of_philos);
			someone_died = true;
		}
		i++;
		if (i == philo[0]->rule->num_of_philos)
		{
					// printf("asdf\n");
			i = 0;
			if (everyone_is_dead == true)
			{
				printf("simulation ends\n");
				break ;
			}
			else
				everyone_is_dead = true ;
			usleep(100);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_rule			rule;
	pthread_mutex_t	**forks;
	pthread_mutex_t	*printer;
	t_philo			**philo;

	if (!argv_validation(argc, argv, &rule))
		return (0);
	forks = init_mutex(rule.num_of_philos);
	if (forks == NULL)
		return (0);
	printer = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(printer, NULL);
	// if (printer == NULL)
	// 	return ((int) free_forks(forks, rule.num_of_philos));
	philo = init_philo(rule, forks, printer);
	if (philo == NULL)
	{
		free(printer);
		return (free_forks_and_philo(forks, philo, rule.num_of_philos));
	}
	enter_dining_room(philo, argc);
	wait_everyones_death(philo);
	free_forks_and_philo(forks, philo, rule.num_of_philos);
	free(printer);
	//while(1);
}
