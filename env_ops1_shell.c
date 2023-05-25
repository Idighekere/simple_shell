#include "shell.h"

/**
 * do_env - it gets the env, adds or deletes a var
 * @delete: the variable to delete
 * @add: the variable to add
 *
 * Return: the current environ. after the changes
 */

char **do_env(char *add, char *delete)
{
	static shell_list_s *my_env;
	char *tmp = '\0';
	int ab = 0, cd = 0, len = 0;

	if (!my_env)
	{
		my_env = listify((char **)add);
		return (NULL);
	}
	if (add)
		add_node_end(&my_env, add);
	else if (delete)
	{
		len = list_len(my_env);
		for (ab = 0; ab < len; ab++)
		{
			cd = 0;
			tmp = get_node_at_index(my_env, ab)->ptr;
			do {
				if (delete[cd] != tmp[cd])
					break;
				cd++;
			} while (delete && tmp && delete[cd] && tmp[cd] != '=');

			if (!(delete[cd]) && tmp[cd] == '=')
			{
				delete_node_at_index(&my_env, ab);
				break;
			}
		}
	}
	return (arrayify(my_env));
}
