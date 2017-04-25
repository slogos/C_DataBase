/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 19:30:37 by dbotova           #+#    #+#             */
/*   Updated: 2017/04/24 19:30:39 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	print_background(t_db *db, int flag, int i)
{
	int 	tmp;
	int 	IndexStudent;
	char 	*ethnic[5] = {"Hispanic", "Native American", "White", "African", "Asian"};
	char 	*country[5] = {"Russia", "Moldova", "USA", "France", "Honduras"};
	char 	*religion[5] = {"Orthodox", "Muslim", "Christian", "Woodoo", "Ghipsy"};
	
	db->background = (t_background **)malloc(sizeof(t_background *) * i);
	
	for (int j = 0; j < i; j++)
	{
		db->background[j] = (t_background *)malloc(sizeof(t_background));
		strcpy(db->background[j]->ethnic, ethnic[j]);
		strcpy(db->background[j]->country, country[j]);
		strcpy(db->background[j]->religion, religion[j]);
	}
	
	while (1)
	{
		printf(" -------------------------------------\n");
		for (int l = 0; l < i; l++)
			printf(" | %d. %s %-30s |\n", l, 
				db->name[l]->FirstName, db->name[l]->LastName);
		printf(" -------------------------------------\n");
		printf("\nChoose Student (type -1 for Previous):\n\n");
		scanf("%d", &IndexStudent);
		if (IndexStudent == -1)
			break;

		while (1)
		{
			printf("1.Ethnic; 2. Country; 3.Religion; 4. To Previous\n\n");
			scanf("%d", &tmp);

			if (tmp == 4)
				break;
			else if (tmp == 1)
			{
				printf(" -------------------------------------\n");
				printf(" | %-32s |\n", db->background[IndexStudent]->ethnic);
				printf(" -------------------------------------\n");	
			}
			else if (tmp == 2)
			{
				printf(" -------------------------------------\n");
				printf(" | %-32s |\n", db->background[IndexStudent]->country);
				printf(" -------------------------------------\n");	
			}
			else if (tmp == 3)
			{
				printf(" -------------------------------------\n");
				printf(" | %-32s |\n", db->background[IndexStudent]->religion);
				printf(" -------------------------------------\n");	
			}
		}
	}
}

void	print_school(t_db *db, int flag, int i)
{
	int 	tmp;
	int 	IndexStudent;
	char 	*school[5] = {"Stanford", "Berckley", "MIT", "Univeristy of California", "University of Washington"};
	double 	GPA[5] = {4.5, 3.5, 4.8, 2.5, 4.1};
	int		Year[5] = {2003, 2005, 2010, 2007, 2015};
	
	db->major = (t_major **)malloc(sizeof(t_major *) * i);
	
	for (int j = 0; j < i; j++)
	{
		db->major[j] = (t_major *)malloc(sizeof(t_major));
		strcpy(db->major[j]->SchoolName, school[j]);
		db->major[j]->GPA = GPA[j];
		db->major[j]->YearOfGraduation = Year[j];
	}
	
	while (1)
	{
		printf(" -------------------------------------\n");
		for (int l = 0; l < i; l++)
			printf(" | %d. %s %-30s |\n", l, 
				db->name[l]->FirstName, db->name[l]->LastName);
		printf(" -------------------------------------\n");
		printf("\nChoose Student (type -1 for Previous):\n\n");
		scanf("%d", &IndexStudent);
		if (IndexStudent == -1)
			break;

		while (1)
		{
			printf("1.School Name; 2. GPA; 3.Year of Graduation; 4. To Previous\n\n");
			scanf("%d", &tmp);

			if (tmp == 4)
				break;
			else if (tmp == 1)
			{
				printf(" -------------------------------------\n");
				printf(" | %-32s |\n", db->major[IndexStudent]->SchoolName);
				printf(" -------------------------------------\n");	
			}
			else if (tmp == 2)
			{
				printf(" -------------------------------------\n");
				printf(" | %0.2f                             |\n", db->major[IndexStudent]->GPA);
				printf(" -------------------------------------\n");	
			}
			else if (tmp == 3)
			{
				printf(" -------------------------------------\n");
				printf(" | %-32d |\n", db->major[IndexStudent]->YearOfGraduation);
				printf(" -------------------------------------\n");	
			}
		}
	}
}

void		print_personal(t_db *db, int flag, int i)
{
	int 	index;

	while (1)
	{
		printf("1.FirstName; 2.LastName; 3.FullName; 4. To Previous\n\n");
		scanf("%d", &index);

		if (index == 4)
			break;
		else if (index == 1)
		{
			printf(" -------------------------------------\n");
			for (int j = 0; j < i; ++j)
				printf(" | %d. %-30s |\n", j, db->name[j]->FirstName);
			printf(" -------------------------------------\n");
		}
		else if (index == 2)
		{
			printf(" -------------------------------------\n");
			for (int j = 0; j < i; ++j)
				printf(" | %d. %-30s |\n", j, db->name[j]->LastName);
			printf(" -------------------------------------\n");	
		}
		else if (index == 3)
		{
			printf(" -------------------------------------\n");
			for (int j = 0; j < i; ++j)
				printf(" | %d. %s %-30s |\n", j, 
					db->name[j]->FirstName, db->name[j]->LastName);
			printf(" -------------------------------------\n");	
		}
	}
}

int main ()
{
	int 	i;
	int 	index;
	t_db	*db;

	printf("How many students?\n");
	scanf("%d", &i);
	db = (t_db *)malloc(sizeof(t_db));
	db->name = (t_name **)malloc(sizeof(t_name *) * i);

	for (int j = 0; j < i; j++)
	{
		db->name[j] = (t_name *)malloc(sizeof(t_name));
		scanf("%s %s", db->name[j]->FirstName, db->name[j]->LastName);
	}

	printf("\nQuery for DataBase\n\nChose one option:\n");
	while (1)
	{	
		printf("1.Personal; 2.School; 3.Background; (type -1 to exit)\n\n");
		scanf("%d", &index);
		
		if (index == -1)
			break;
		else if (index == 1)
			print_personal(db, 1, i);
		else if (index == 2)
			print_school(db, 2, i);
		else if (index == 3)
			print_background(db, 3, i);
	}
	return (0);
}
