#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

char *get_env_val(char *);

/**
 * get_path - get the path in a double char pointer
 * Return: the double char pointer of the path
 */
char **get_path()
{
	char *tempo = NULL;
	char **ret = NULL;

	tempo = get_env_val("PATH");
	ret = _strtok(tempo, ":");
	do_mem(0, tempo);
	return (ret);
}

/**
 * get_env_val - get the value of an env variable
 * @name: the name of the variable to get the value of
 * Return: the string pointer to where the value part of the variable starts
 */
char *get_env_val(char *name)
{
	int a = 0, b = 0;
	char **env = NULL;
	char *rest = NULL;

	env = get_env();
	while (env[a])
	{
		b = 0;
		while (env[a][b] && name[b])
		{
			if (env[a][b] != name[b])
				break;
			b++;
		}
		/* b only counts until null byte if name matches */
		if (name[b] == '\0' && env[a][b] == '=')
		{
			if (!env[a][b + 1])
				return (NULL);
			rest = do_mem((_strlen((env[a]) + b + 1) + 1), NULL);
			_strcpy(rest, ((env[a]) + b + 1));
			free_double_array(env);
			return (rest);
		}
		a++;
	}
	free_double_array(env);
	return (NULL);
}

/**
  * find_path - finds if a command exists in a path and returns the path
  * @path: paths to search
  * @command: command to search for
  * Return: path where command is
  */
char *find_path(char **path, char *command)
{
	/* pointer for directory entry  & opendir returns a pointer of DIR type*/
	struct dirent *de = NULL;
	DIR *dr = NULL;
	int a = 0;

	if (!command || !path)
		return (NULL);
	for (a = 0; path[a]; a++)
	{
		dr = opendir(path[a]);
		/* opendir returns NULL if couldn't open directory */
		if (!dr)
		{
			write(STDOUT_FILENO, "Could not open directory\n", 25);
			closedir(dr);
		}
		else
		{
			while ((de = readdir(dr)) != NULL)
			{
				if (_strcmp((*de).d_name, command) == 0)
				{
					closedir(dr);
					return (path[a]);
				}
			}
			closedir(dr);
		}
	}
	return (NULL);
}

/**
 * get_env - get current environment as a malloc'd, NULL-terminating char**
 * Return: the environment as a char**
 */
char **get_env(void)
{
	return (do_env('\0', '\0'));
}

/**
 * get_full_command - get the command with the correct path prepended
 * @path: all of the possible paths
 * @command: the base command
 * Return: the correct path + command (leave command alone if already done)
 */
char *get_full_command(char *path, char *command)
{
	int a = 0, b = 0;
	char *rest = NULL;
	char **temp_split = NULL;

	/* if command has any / in it, then return command */
	temp_split = _strtok(command, "/");
	if (temp_split && temp_split[0] && temp_split[1])
	{
		free_double_array(temp_split);
		return (command);
	}
	free_double_array(temp_split);

	/* else, concat the path with the command and a slash */
	a = _strlen(path);
	b = _strlen(command);
	rest = do_mem(sizeof(char) * (a + b + 1 + 1), NULL);
	_strcat(rest, path);
	_strcat(rest, "/");
	_strcat(rest, command);
	return (rest);
}
