/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:18:25 by serhouni          #+#    #+#             */
/*   Updated: 2023/02/08 19:12:15 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*checkpath(const char *name, char **path_arr, char *paths)
{
	char	*fullname;
	char	*execpath;
	int		i;

	fullname = ft_strjoin("/", name);
	if (fullname == NULL)
		return (free(paths), freeall(path_arr), NULL);
	i = 0;
	while (path_arr[i] != NULL)
	{
		execpath = ft_strjoin(path_arr[i++], fullname);
		if (execpath == NULL)
			return (free(paths), freeall(path_arr), free(fullname), NULL);
		if (access(execpath, F_OK) != -1)
			return (free(paths), freeall(path_arr), free(fullname), execpath);
		free(execpath);
	}
	return (free(paths), freeall(path_arr), free(fullname), NULL);
}

char	*getpath(t_data *data, const char *name, char **env)
{
	int		i;
	char	*paths;
	char	**path_arr;
	

	i = 0;
	if (access(name, F_OK) != -1)
	{
		data->islocal = 1;
		return (char *)name;
	}
	while (env[i] != NULL)
	{
		if (ft_strnstr(env[i], "PATH=", 5) != NULL)
		{
			paths = ft_substr(env[i], 5, ft_strlen(env[i]));
			if (paths == NULL)
				return (NULL);
			path_arr = ft_split(paths, ':');
			if (path_arr == NULL)
				return (free(paths), NULL);
			return (checkpath(name, path_arr, paths));
		}
		i++;
	}
	return (NULL);
}

void	exiterror(char *message, int isexit)
{
	if(message == NULL)
		perror("pipex");
	else
		ft_putendl_fd(message, STDERR_FILENO);
	if(isexit)
		exit(1);
}

char	**getcmndargs(const char *cmnd, char **name)
{
	char	**cmndspl;

	cmndspl = ft_split(cmnd, ' ');
	if (cmndspl == NULL)
		return (NULL);
	*name = cmndspl[0];
	return cmndspl;
}
