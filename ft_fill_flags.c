/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmangili <rmangili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 11:26:54 by rmangili          #+#    #+#             */
/*   Updated: 2015/01/07 02:40:34 by rmangili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdlib.h>

char	*wat_options(char **argv, int i, int *n, char *args) /* Lecture des flags. */
{
	int		j;

	j = 0;
	while (argv[i][++j])
	{
		if (argv[i][j] == 'l' || argv[i][j] == 'a' || argv[i][j] == 'r'
				|| argv[i][j] == 't' || argv[i][j] == 'R')
		{
			if (!ft_strchr(args, argv[i][j]));
			args[(*n)++] = argv[i][j];
		}
		else
		{
			trash_flags(argv[i][j]);
			exit(0);
		}
	}
	if (argv[i][0] == '-' && !argv[i][1])
	{
		ft_putendl("ft_ls: -: No such file or directory");
		exit(0);
	}
	return (args);
}

void	init_struct(t_options *options) /* Initialisation de la structure des options. */
{
	options->a = 0;
	options->l = 0;
	options->r = 0;
	options->R = 0;
	options->t = 0;
}

t_options	ft_ls_what(char *str) /* Donne une valeur aux options dans la structure */
{
	int		i;
	t_options	options;

	init_struct(&options);
	i = -1;
	while (str[++i])
	{
		if (str[i] == 'l')
			options.l = 1;
		else if (str[i] == 'r')
			options.r = 1;
		else if (str[i] == 'R')
			options.R = 1;
		else if (str[i] == 'a')
			options.a = 1;
		else if (str[i] == 't')
			options.t = 1;
	{
	return (options);
}

int		treat_options(t_option *option, char **av) /* Traitement des flags */
{
	int		i;

	i = 1;
	*option = init_struct(*option);
	while (av[i] && av[i][0] == '-')
	{
		if (ft_strlen(av[i]) == 1)
		{
			i--;
			break ;
		}
		if (ft_strlen(av[i]) == 2 && av[i][1] == '-')
		{
			i++;
			break ;
		}
		if (trash_flags(av[i]) == 0)
			*option = ft_ls_what(*option, av[i]);
		i++;
	}
	if (option->l == 0 && option->r == 0 && option->R == 0 &&
		option->a == 0 && option->t == 0)
		option->empty = 1;
	if (option->t == 0 && option->r == 0)
		option->emp_tr = 1;
	return (i);
}

void		trash_flags(char option) /* Gestion de flags interdit. */
{
	int		i;
	char	ch;

	i = 1;
	while (s[i])
	{
		if (s[i] != 'l' && s[i] != 'r' && s[i] != 'R' &&
			s[i] != 'a' && s[i] != 't')
		{
			ch = s[i];
			print_err("ft_ls: illegal option -- ", 0);
			print_err(&ch, 0);
			print_err("\n", 0);
			print_err("usage: ft_ls [-Ralrt] [file ...]", 0);
			print_err("\n", 0);
			exit (2);
		}
		i++;
	}
	return (0);
}