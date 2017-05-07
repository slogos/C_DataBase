/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:18:11 by slogos            #+#    #+#             */
/*   Updated: 2017/05/05 13:18:12 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_HEADER_H
# define PRINT_HEADER_H

# define PROMPT1 "=^..^= : "
# define PROMPT2 "=^..^= (try again...) : "
# define NOT_DONE  			{	printf("UNDER IMPLEMENTATION\n"); \
								sleep(2); }
# define DELETE_TAB 		{	printf("%-20s", "[DELETE COLUMN(1)]"); \
								printf("%-20s", "[DELETE ROW(2)]"); \
								printf("%-20s", "[CANCEL (0)]\n"); }
# define PRINT_SEARCH_MENU 	{	system("clear"); \
								printf("\n"); \
								printf("%-30s", "[SEARCH DATA IN CELL(1)]"); \
								printf("%-25s", "[SEARCH COLUMN(2)]"); \
								printf("%-20s", "[BACK (3)]"); \
								printf("%-20s\n", "[EXIT (4)]"); \
								printf("\n\n"); }
# define PRINT_DBMENU 		{	printf("\n\n"); \
								printf("%-20s", "[ADD COLUMN(1)]"); \
								printf("%-30s", "[ADD DATA TO CELL(2)]"); \
								printf("%-20s", "[DELETE(3)]"); \
								printf("%-20s\n", "[ADD ROW(4)]"); \
								printf("%-20s", "[SEARCH(5)]"); \
								printf("%-30s", "[EXPORT TO FILE (6)]"); \
								printf("%-20s", "[BACK (7)]"); \
								printf("%-20s\n", "[EXIT (8)]"); \
								printf("\n%s\n", "[LIKE (9)]"); \
								printf("\n\n"); \
								printf(PROMPT1); }
# define PRINT_MMAIN 		{	printf("\n\n"); \
								printf("%-25s", "[CREATE NEW DB (1)]"); \
								printf("%-32s", "[OPEN FROM FILE (2)]"); \
								printf("%s\n", "[EXIT (3)]"); \
								printf("\n\n"); }
# define TAB_DELIMETR 	printf("---------------------------------------------\
--------------\n")

#endif
