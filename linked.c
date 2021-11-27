#include "hsh.h"

args_t *add(args_t **head, const char *arg)
{
	args_t *tmp = *head;
	args_t *new_n;

	if (!head || !arg)
		return (NULL);
	new_n = malloc(sizeof(args_t));
	if (new_n == NULL)
		return (NULL);
	new_n->arg = strdup(arg);
	new_n->next = NULL;
	if (*head == NULL)
	{
		*head = new_n;
		return (new_n);
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new_n;
	return (new_n);
}

size_t print_list(const args_t *h)
{
	size_t n = 0;
	const args_t *tmp;

	tmp = h;
	while (tmp != NULL)
	{
		if (tmp->arg == NULL)
		{
			printf("[%d] %s\n", 0, "(nil)");
		}
		else
			printf("%s\n", tmp->arg);
		tmp = tmp->next;
		n += 1;
	}
	return (n);
}

size_t count(args_t *head)
{
	int i;

	for (i = 0; head; i++)
	{
		head = head->next;
	}
	return (i);
}

char **transform(args_t **head)
{
	int i;
	args_t *h = *head;
	char **arguments;

	for (i = 0; h; i++)
		h = h->next;
	arguments = malloc((i + 1) * sizeof(char*));
	h = *head;
	for (i = 0; h; i++, h = h->next)
	{
		arguments[i] = h->arg;
	}
	arguments[i] = NULL;
	return (arguments);
}
