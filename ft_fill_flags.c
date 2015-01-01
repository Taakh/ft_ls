/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmangili <rmangili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 11:26:54 by rmangili          #+#    #+#             */
/*   Updated: 2015/01/01 23:52:57 by rmangili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdlib.h>

char	*wat_options(char **argv, int i, int *n, char *args) // Lecture des flags. 
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

void	init_struct(t_options *options) // Initialisation de la structure des options.
{
	options->a = 0;
	options->l = 0;
	options->r = 0;
	options->R = 0;
	options->t = 0;
}

t_options	ft_ls_what(char *str) // Traitement des flags.
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
t_options	check_args(int	argc, char **argv, t_options options) // Recuperation des arguments.
{

}

void		trash_flags(char option) // Gestion d'erreurs.
{
	ft_putstr("ls : illegal option : -- ");
	ft_putchar(option);
	ft_putstr("\nusage : ls [-Ralrt] [file ...]\n");
}

int		main(int argc,	char **argv) // Main.
{
	t_options		options;

	options = check_args(argc, argv, options);
	ls_no_option(argv, argc, options);
	return (0);
}
