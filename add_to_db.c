/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_db.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:48:53 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/05 16:32:16 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	add_record_to_db(t_db *db)
{
	unsigned int	i;
	char			*data;

	i = 0;
	if (!db->filled)
		return ;
	db->last_id++;
	while (i < DICTIONARY_SIZE)
	{
		if (db->tabs[i].name[0] != 0)
		{
			data = (char*)malloc(sizeof(char) * BUFF_LEN);
			printf("Enter data for [%s] table: ", db->tabs[i].name);
			read_input(&data);
			add_cell(db, db->last_id, data, i);
			SMART_FREE(data);
		}
		i++;
	}
}
