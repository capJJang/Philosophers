/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:20:11 by segan             #+#    #+#             */
/*   Updated: 2023/03/30 00:27:36 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_rule	rule;
	t_table	*forks;

	if (!argv_validation(argc, argv, &rule))
		return (0);
	forks = init_mutex(rule.num_of_philos);
	if (forks == NULL)
		return (0);
	create_philos();
}
