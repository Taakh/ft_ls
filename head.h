/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmangili <rmangili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 20:02:26 by rmangili          #+#    #+#             */
/*   Updated: 2015/01/07 02:40:36 by rmangili         ###   ########.fr       */
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
void		wat_options(ls_type *lst, int argc, char **argv); // Lecture des flags.
void		init_struct(t_options *options); // Initialisation de la structure des options.
int			ft_ls_what(char *str, ls_type *lst); // Traitement des flags.
int			treat_options(t_option *option, char **av); /* Traitement des flags */
void		trash_flags(char option); /* Gestion de flags interdit. */

/* print, affichage d'un certain nombre de choses -a voir dans le code- */
void 		print(t_param *lst, t_option option);
void 		print_err_file(t_param *lst, t_option option);
void 		print_dir_content(char *path, t_cont *list, t_param *lst, t_option option);
t_biggest 	*print_blocks_get_biggest(t_cont *list, t_biggest *bist, t_option option);
void 		put_dir_name(char *s);

/* params, gestions des parametres */
void 		cont_init(t_cont **new, struct stat *buf);
t_cont 		*create_new(char *name, t_cont *new, struct stat *buf, t_option option);
int 		detect_type(char *name, char *path, t_cont **new, t_option option);
int 		fill_list(t_cont **lst, t_cont *new, t_option option);
void 		collect_params(char *name, t_option option, t_param *lst);

#endif