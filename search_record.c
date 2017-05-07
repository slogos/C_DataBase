/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_record.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:46:09 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/05 14:20:31 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	create_tab(t_db *db)
{
	char	*tab_name;

	tab_name = (char*)malloc(sizeof(char) * BUFF_LEN);
	printf("Enter a name (0 to cancel): \n");
	read_input(&tab_name);
	if (strcmp(tab_name, "0") == 0)
	{
		SMART_FREE(tab_name);
		return ;
	}
	add_tab(db, tab_name);
	db->filled++;
	SMART_FREE(tab_name);
}

void	search_by_index(t_db *db, char *term, unsigned int i, long long index)
{
	unsigned int key;

	key = hash(term);
	while (i < DICTIONARY_SIZE)
	{
		if (db->tabs[i].map[key].name[0] != 0 && \
			strcmp(db->tabs[i].map[key].name, term) == 0)
		{
			index = db->tabs[i].map[key].index;
			print_record(db, index);
			if (strcmp(db->tabs[i].map[key + 1].name, term) == 0)
			{
				key++;
				i = 0;
			}
		}
		i++;
	}
}

void	search_record(t_db *db)
{
	char			*term;

	term = (char*)malloc(sizeof(char) * BUFF_LEN);
	printf("Enter cell data:\n");
	read_input(&term);
	print_tab_header(db);
	search_by_index(db, term, 0, -1);
	printf("BACK [0] << \n");
	read_input(&term);
	SMART_FREE(term);
}
