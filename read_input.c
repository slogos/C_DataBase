/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:31:25 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/05 14:36:53 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int	read_input(char **str)
{
	size_t	bufsize;
	ssize_t	len;

	len = 0;
	bufsize = BUFF_LEN;
	len = getline(str, &bufsize, stdin);
	if (len <= 0)
		return (-1);
	(*str)[--len] = 0;
	return (0);
}
