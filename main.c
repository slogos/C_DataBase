/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 19:30:37 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/05 15:23:46 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"
#include "print_header.h"

void	awesome_feature(char *user_input)
{
	printf("HAVE YOU CHECK ALL OUR AWESOME FEATURES (y/n)?\n");
	scanf("%s", user_input);
	if (!strcmp(user_input, "y"))
		system("open https://youtu.be/5AtkWnBjGBU?t=88");
}

int		main(void)
{
	char	*user_input;
	int		flag;
	t_db	*db;

	flag = 0;
	db = NULL;
	user_input = (char*)malloc(sizeof(char) * BUFF_LEN);
	while (42)
	{
		system("clear");
		PRINT_MMAIN;
		(!flag) ? printf(PROMPT1) : printf(PROMPT2);
		flag = 0;
		read_input(&user_input);
		if (!strcmp(user_input, "1"))
			create_newdb(db);
		else if (!strcmp(user_input, "2"))
			open_db(db);
		else if (!strcmp(user_input, "3"))
			break ;
		else
			flag = 1;
	}
	SMART_FREE(user_input);
	return (0);
}
