/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:37:32 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/05 16:55:11 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <sys/stat.h>
# include <unistd.h>
# define SMART_FREE(x) {free(x); x = NULL;}
# define DICTIONARY_SIZE 1000
# define MAGIC_NUMBER 42
# define BUFF_LEN 20

typedef struct		s_map
{
	long long		index;
	char			name[BUFF_LEN];
}					t_map;

typedef struct		s_cell
{
	unsigned int	id;
	char			data[BUFF_LEN];
}					t_cell;

typedef struct		s_tab
{
	char			name[BUFF_LEN];
	unsigned int	count;
	t_cell			data[DICTIONARY_SIZE];
	t_map			map[DICTIONARY_SIZE];
}					t_tab;

typedef struct		s_db
{
	t_tab			tabs[DICTIONARY_SIZE];
	t_map			map[DICTIONARY_SIZE];
	unsigned int	count;
	unsigned int	filled;
	unsigned int	last_id;
}					t_db;

t_db				*deserialize_db(t_db *db, char *path);
t_db				*init_db(void);
unsigned int		hash(char *message);
void				awesome_feature(char *user_input);
void				create_tab(t_db *db);
void				delete_tab(t_db *db);
void				open_db(t_db *db);
void				create_newdb(t_db *db);
void				serialize_db(t_db *db, char *filename);
void				add_record_to_tab(t_db *db);
void				add_record_to_db(t_db *db);
void				search_record(t_db *db);
void				search_tab(t_db *db);
void				print_tab(t_db *db, long long index);
void				print_record(t_db *db, long long index);
void				print_tab_header(t_db *db);
void				delete_id(t_db *db, char *tab_name, int i);
void				new_cell(t_cell *new, unsigned int id, char *data);
void				new_tab(t_tab *new, char *name);
void				add_tab(t_db *db, char *name);
void				add_cell(t_db *db, unsigned int id, char *data, \
					unsigned int idx);
void				print_tabs(t_db *db);
void				print_records(t_db *db);
void				print_dbmenu(t_db *db, char *db_name);
void				print_mmenu(void);
int					read_input(char **str);

#endif
