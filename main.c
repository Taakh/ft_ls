/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmangili <rmangili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 02:01:11 by rmangili          #+#    #+#             */
/*   Updated: 2015/01/07 02:40:33 by rmangili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_param 	*cont_params_init(void) /* Initialisation de la liste */
{
	t_param			*new;

	if ((new = (t_param *)malloc(sizeof(*new))) == 0)
		print_err("ft_ls: ", "malloc");
	new->err = 0;
	new->file = 0;
	new->dir = 0;
	new->dir_name = 0;
	new->dir_num = 0;
	new->counter = 0;
	new->flag = 0;
	return (new);
}

int 	main(int ac, char **av) /* Main ... */
{
	int				i;
	t_param			*lst;
	t_option		option;

	i = treat_options(&option, av);
	lst = cont_params_init();
	if (ac == 1 || (ac == 2 && i == 2))
		collect_params(".", option, lst);
	while (i != ac)
	{
		collect_params(av[i], option, lst);
		i++;
	}
	print(lst, option);
	return (0);
}