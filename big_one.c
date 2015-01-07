/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmangili <rmangili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 02:21:45 by rmangili          #+#    #+#             */
/*   Updated: 2015/01/07 02:40:35 by rmangili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <head.h>

t_biggest
	*get_biggest_uid_gid_link(t_cont *list, t_biggest *bist)
{
	int				siz;
	struct passwd	*new_uid;
	struct group	*new_gid;

	siz = ft_getsize_nbr(list->nlink);
	if (siz > bist->link_biggest)
		bist->link_biggest = siz;
	new_uid = getpwuid(list->uid);
	siz = ft_strlen(new_uid->pw_name);
	if (siz > bist->uid_biggest)
		bist->uid_biggest = siz;
	new_gid = getgrgid(list->gid);
	siz = ft_strlen(new_gid->gr_name);
	if (siz > bist->gid_biggest)
		bist->gid_biggest = siz;
	bist->flag_not_hidden = 1;
	bist->blocks += list->blocks;
	return (bist);
}

t_biggest
	*get_biggest_attr(t_cont *list, t_option option, t_biggest *bist, int flag)
{
	int				siz;
	int				dev;

	while (list)
	{
		if (list->name[0] == '.' && option.a == 0 && flag == 1)
		{
			list = list->next;
			continue;
		}
		bist = get_biggest_uid_gid_link(list, bist);
		siz = ft_getsize_nbr(list->size);
		dev = ft_getsize_nbr(list->rdev);
		if (siz > bist->size_biggest)
			bist->size_biggest = siz;
		if (dev > bist->size_biggest)
			bist->size_biggest = 8;
		if (ft_getsize_nbr(list->size) > 8)
			bist->flag_big_file = 1;
		if (S_ISCHR(list->mode) || S_ISBLK(list->mode))
			bist->flag_there_is_dev = 1;
		list = list->next;
	}
	return (bist);
}

t_biggest
	*bist_init(void)
{
	t_biggest		*bist;

	bist = (t_biggest *)malloc(sizeof(*bist));
	bist->link_biggest = 0;
	bist->size_biggest = 0;
	bist->uid_biggest = 0;
	bist->gid_biggest = 0;
	bist->flag_there_is_dev = 0;
	bist->flag_big_file = 0;
	bist->blocks = 0;
	bist->flag_not_hidden = 0;
	return (bist);
}

t_biggest
	*get_biggest(t_cont *list, t_option option, int flag_i_am_dir)
{
	t_biggest		*bist;

	if (list == 0)
		return (0);
	bist = 0;
	bist = bist_init();
	bist = get_biggest_attr(list, option, bist, flag_i_am_dir);
	return (bist);
}
