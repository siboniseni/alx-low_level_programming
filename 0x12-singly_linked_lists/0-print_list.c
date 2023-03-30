#include <stdio.h>
#include "lists.h"


typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;

    	int *head = &list_s;

	if (head == NULL)
	{
		printf("[0] (nil)");
	}
	else
	{
		printf("[%u] %s\n", head->len, head->str);
	}

} list_t;
