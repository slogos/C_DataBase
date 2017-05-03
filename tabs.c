#include "ft_db.h"

void create_tab(t_db *db)
{
	char *tab_name = (char*)malloc(sizeof(char) * BUFF_LEN);

	printf("Enter a name (0 to cancel): \n");
	scanf("%s", tab_name);

	if (strcmp(tab_name, "0") == 0)
	{
		SMART_FREE(tab_name);
		return ;
	}

	add_tab(db, tab_name);
	SMART_FREE(tab_name);
}

void delete_tab(t_db *db)
{
	char *tab_name = (char*)malloc(sizeof(char) * BUFF_LEN);
	int flag = 0;
	unsigned int i;

	printf
	("Enter a name (0 to cancel): \n");
	while (1)
	{
		i = 0;
		scanf("%s", tab_name);
		if (!strcmp(tab_name, "0"))
			return;
		while (i < db->count)
			if (!strcmp(db->tabs[i++].name, tab_name))
			{
				flag = 1;
				break;
			}
		if (flag)
			break;
		else 
			printf("Invalid table name, please try again...\n");
	}
	memset(&db->tabs[--i], 0, sizeof(t_tab));
	SMART_FREE(tab_name);
}
