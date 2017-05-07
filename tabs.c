/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:05:42 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/05 14:04:24 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"
#include "print_header.h"

int		check_id(char *tab_name)
{
	unsigned long int i;

	i = 0;
	while (i < strlen(tab_name))
		if (!isdigit(tab_name[i++]))
			return (0);
	return (1);
}

void	delete_id(t_db *db, char *tab_name, int i)
{
	unsigned int	id;

	printf("Enter ID number:\n");
	while (42)
	{
		read_input(&tab_name);
		if (!check_id(tab_name))
			printf("Invalid ID format, please try again...\n");
		else if ((unsigned int)atoi(tab_name) > db->last_id)
			printf("Invalid ID range, please try again...\n");
		else
			break ;
	}
	id = atoi(tab_name);
	while (i < DICTIONARY_SIZE)
	{
		if (db->tabs[i].name[0] != 0)
		{
			memset(&db->tabs[i].map[hash(db->tabs[i].data[id - 1].data)], 0, \
				sizeof(t_map));
			memset(&db->tabs[i].data[id - 1], 0, sizeof(t_cell));
		}
		i++;
	}
}

void	delete_column(t_db *db, char *tab_name)
{
	unsigned int i;
	unsigned int key;

	i = 0;
	key = hash(tab_name);
	while (strcmp(db->map[key].name, tab_name) != 0)
		key++;
	while (strcmp(db->tabs[i].name, tab_name) != 0)
		i++;
	if (key >= DICTIONARY_SIZE || i >= DICTIONARY_SIZE)
		return ;
	memset(&db->tabs[i], 0, sizeof(t_tab));
	memset(&db->map[key], -1, sizeof(t_map));
	db->filled--;
	if (db->filled == 0)
	{
		db->last_id = 0;
		db->count = 0;
		memset(db, 0, sizeof(t_db));
	}
	SMART_FREE(tab_name);
}

void	validate_column_name(t_db *db, char *tab_name)
{
	int				flag;
	unsigned int	i;

	flag = 0;
	printf("Enter column name:\n");
	while (42)
	{
		i = 0;
		read_input(&tab_name);
		while (i < db->count)
			if (!strcmp(db->tabs[i++].name, tab_name))
			{
				flag = 1;
				break ;
			}
		if (flag)
			break ;
		else
			printf("Invalid column name, please try again...\n");
	}
	delete_column(db, tab_name);
}

void	delete_tab(t_db *db)
{
	char *tab_name;

	tab_name = (char*)malloc(sizeof(char) * BUFF_LEN);
	DELETE_TAB;
	while (42)
	{
		read_input(&tab_name);
		if (!strcmp(tab_name, "0"))
			return ;
		else if (!strcmp(tab_name, "1"))
		{
			validate_column_name(db, tab_name);
			break ;
		}
		else if (!strcmp(tab_name, "2"))
		{
			delete_id(db, tab_name, 0);
			SMART_FREE(tab_name);
			break ;
		}
		else
			printf("Invalid option, please try again...\n");
	}
}
