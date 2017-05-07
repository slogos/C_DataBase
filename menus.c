/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:13:00 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/05 16:49:50 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"
#include "print_header.h"

int			search_by_index_menu(t_db *db, char *user_input)
{
	if (!strcmp(user_input, "1"))
		search_record(db);
	else if (!strcmp(user_input, "2"))
		search_tab(db);
	else if (!strcmp(user_input, "3"))
		return (-1);
	else if (!strcmp(user_input, "4"))
	{
		if (db)
			db = NULL;
		SMART_FREE(user_input);
		exit(0);
	}
	else
		return (1);
	return (0);
}

void		print_search_menu(t_db *db)
{
	char	*user_input;
	int		flag;

	flag = 0;
	user_input = (char*)malloc(sizeof(char) * BUFF_LEN);
	while (42)
	{
		PRINT_SEARCH_MENU;
		(!flag) ? printf(PROMPT1) : printf(PROMPT2);
		flag = 0;
		read_input(&user_input);
		flag = search_by_index_menu(db, user_input);
		if (flag == -1)
			return ;
	}
	SMART_FREE(user_input);
}

int			search_menu_by_index(t_db *db, char *user_input, char *db_name)
{
	if (!strcmp(user_input, "1"))
		create_tab(db);
	else if (!strcmp(user_input, "2"))
		add_record_to_tab(db);
	else if (!strcmp(user_input, "3"))
		delete_tab(db);
	else if (!strcmp(user_input, "4"))
		add_record_to_db(db);
	else if (!strcmp(user_input, "5"))
		print_search_menu(db);
	else if (!strcmp(user_input, "6"))
		serialize_db(db, db_name);
	else if (!strcmp(user_input, "7"))
		return (-1);
	else if (!strcmp(user_input, "8"))
	{
		(db) ? db = NULL : 0;
		exit(0);
	}
	else if (!strcmp(user_input, "9"))
		awesome_feature(user_input);
	else
		return (1);
	return (0);
}

static int	check_menu_entry(t_db *db, char *db_name)
{
	char	*user_input;

	user_input = (char*)malloc(sizeof(char) * BUFF_LEN);
	if (read_input(&user_input) == -1)
	{
		SMART_FREE(user_input);
		return (-1);
	}
	else if (!search_menu_by_index(db, user_input, db_name))
		return (0);
	else
	{
		SMART_FREE(user_input);
		return (1);
	}
	SMART_FREE(user_input);
	return (0);
}

void		print_dbmenu(t_db *db, char *db_name)
{
	int		flag;

	flag = 0;
	(!db) ? db = init_db() : 0;
	while (42)
	{
		system("clear");
		printf("\n");
		print_tabs(db);
		PRINT_DBMENU;
		flag = check_menu_entry(db, db_name);
		if (flag == -1)
			return ;
	}
}
