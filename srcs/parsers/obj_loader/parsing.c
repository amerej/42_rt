/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 10:37:39 by aditsch           #+#    #+#             */
/*   Updated: 2017/03/23 10:37:40 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_parser.h"

void		strsplit_free(char **split)
{
	size_t	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
}

int			start_parsing(t_object *object, char *filename)
{
	t_faces_components	components;

	ft_bzero(&components, sizeof(t_faces_components));
	if (!count_components(filename, &components))
		return (0);
	prepare_components(&components);
	if (!copy_components(object, filename, &components))
		return (0);
	if (!copy_faces(object, filename, &components))
		return (0);
	return (1);
}
