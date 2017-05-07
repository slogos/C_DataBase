/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_records.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:05:24 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/05 15:19:26 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"
#include "print_header.h"

void	print_tab_header(t_db *db)
{
	unsigned int	i;

	i = 0;
	while (i <= db->filled)
	{
		printf("--------------------");
		i++;
	}
	printf("-\n");
	printf("|%-19s", "ID");
	i = 0;
	while (i < DICTIONARY_SIZE)
	{
		if (db->tabs[i].name[0] != 0)
			printf("|%-19s", db->tabs[i].name);
		i++;
	}
	printf("|\n");
	i = 0;
	while (i <= db->filled)
	{
		printf("--------------------");
		i++;
	}
	printf("-\n");
}

void	print_tabs(t_db *db)
{
	if (db->filled == 0)
	{
		TAB_DELIMETR;
		printf("|%35s%-22s|\n", "***EMPTY***", "");
		TAB_DELIMETR;
		return ;
	}
	print_tab_header(db);
	print_records(db);
}

void	print_records(t_db *db)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i < db->last_id)
	{
		j = 0;
		printf("|%-19u", i + 1);
		while (j < DICTIONARY_SIZE)
		{
			if (db->tabs[j].name[0] != 0)
				printf("|%-19s", db->tabs[j].data[i].data[0] != 0 ? \
					db->tabs[j].data[i].data : "(none)");
			j++;
		}
		i++;
		printf("|\n");
	}
	i = 0;
	while (i <= db->filled)
	{
		printf("--------------------");
		i++;
	}
	printf("-\n");
}

void	print_record(t_db *db, long long index)
{
	unsigned int	i;

	i = 0;
	if (index < 0)
		return ;
	printf("|%-20lld", index + 1);
	while (i < DICTIONARY_SIZE)
	{
		if (db->tabs[i].name[0] != 0)
			printf("|%-19s", db->tabs[i].data[index].data);
		i++;
	}
	printf("|\n");
	i = 0;
	while (i <= db->filled)
	{
		printf("--------------------");
		i++;
	}
	printf("-\n");
}

void	print_tab(t_db *db, long long index)
{
	unsigned int	i;

	i = 0;
	if (index < 0)
		return ;
	printf("----------------------------------------\n");
	printf("|%-20s", "ID");
	printf("|%-20s\n", db->tabs[index].name);
	printf("----------------------------------------\n");
	while (i < db->last_id)
	{
		printf("|%-20d|%-20s|\n", i + 1, db->tabs[index].data[i].data);
		i++;
	}
	printf("----------------------------------------\n");
}
