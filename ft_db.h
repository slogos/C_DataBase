/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:37:32 by dbotova           #+#    #+#             */
/*   Updated: 2017/04/24 18:37:36 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# define NAME_LEN 30
# define DATA_LEN 100
# define DEFAULT_TABLE_SIZE 1000

typedef struct		s_name
{
	char			FirstName[NAME_LEN];
	char			LastName[NAME_LEN];
}					t_name;

typedef struct		s_major
{
	double			GPA;
	char			SchoolName[NAME_LEN];
	int				YearOfGraduation;
}					t_major;

typedef struct		s_background
{
	char			ethnic[NAME_LEN];
	char			country[NAME_LEN];
	char			religion[NAME_LEN];
}					t_background;

typedef struct		s_db
{
	t_name			**name;
	t_major			**major;
	t_background	**background;
}					t_db;

#endif
