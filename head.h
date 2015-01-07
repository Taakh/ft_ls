/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmangili <rmangili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 20:02:26 by rmangili          #+#    #+#             */
/*   Updated: 2015/01/04 05:27:43 by rmangili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H
# include <sys/stat.h>
# include "libft/libft.h"
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <errno.h>
typedef struct		s_infos
{
	int		size;
	int		link;
	char	*name;
	char	*group;
	time_t	date;
	char 	*rights;
	char	*autor;
	char	*path;
	char	type;

}								t_infos;

typedef struct				s_param
{
	t_infos					*err;
	t_infos					*file;
	t_infos					*dir;
	char					*dir_name;
	int						dir_num;
	int						counter;
	int						flag;
}							t_param;

typedef struct		s_options
{
	int		a;
	int		l;
	int		r;
	int		R;
	int		t;
}								t_options;

/* ft_fill_flags, gestions des flags */
void	wat_options(ls_type *lst, int argc, char **argv); // Lecture des flags.
void	init_struct(t_options *options); // Initialisation de la structure des options.
int		ft_ls_what(char *str, ls_type *lst); // Traitement des flags.


#endif