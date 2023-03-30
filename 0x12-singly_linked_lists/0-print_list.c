#include <stdio.h>
#include "lists.h"

size_t print_list(const list_t *h)
{
	size_t node_num = 0;

	const list_t *head = h;

	if (head == NULL)
	{
		printf("[0] (nil)");
	}
	else
	{
		printf("[%u] %s\n", head->len, head->str);
		
		head = head->next;
		node_num++;
	}
	return (node_num);
} 
