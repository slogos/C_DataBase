/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_db.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:40:12 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/05 15:21:13 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	open_db(t_db *db)
{
	char *db_name;

	db_name = (char *)malloc(sizeof(char) * BUFF_LEN);
	printf("Enter a name: ");
	scanf("%s", db_name);
	db = deserialize_db(db, db_name);
	print_dbmenu(db, db_name);
	SMART_FREE(db_name);
}
