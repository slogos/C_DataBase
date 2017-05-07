/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:49:48 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/05 15:50:32 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static long long	save_tab(t_db *db, char *tab_name)
{
	int				flag;
	long long		i;
	unsigned int	key;

	flag = 0;
	printf("Enter table name: ");
	while (1)
	{
		i = 0;
		if (read_input(&tab_name) == -1)
			return (-1);
		key = hash(tab_name);
		if (db->map[key].name[0] != 0 && \
				!strcmp(db->map[key].name, tab_name))
		{
			i = db->map[key].index;
			flag = 1;
			break ;
		}
		else
			printf("Invalid table name, please try again...\n");
	}
	return (i);
}

void				add_record_to_tab(t_db *db)
{
	char			*tab_name;
	char			*data;
	unsigned int	id;
	long long		i;

	id = 0;
	data = (char*)malloc(sizeof(char) * BUFF_LEN);
	tab_name = (char*)malloc(sizeof(char) * BUFF_LEN);
	i = save_tab(db, tab_name);
	if (i == -1)
		return ;
	printf("Enter data: ");
	read_input(&data);
	printf("Enter id (0 for new record): ");
	scanf("%u", &id);
	if (id == 0)
		db->last_id++;
	add_cell(db, id != 0 ? id : db->last_id, data, i);
	SMART_FREE(tab_name);
	SMART_FREE(data);
}
