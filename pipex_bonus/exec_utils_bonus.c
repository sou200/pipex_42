/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:16:44 by serhouni          #+#    #+#             */
/*   Updated: 2023/02/28 17:16:16 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	execmnd1(t_data *data, const char **argv, char **env)
// {
// 	char	*cmndname;
// 	char	**cmndargs;
// 	char	*cmndpath;
// 	cmndargs = getcmndargs(argv[2], &cmndname);
// 	if (cmndargs == NULL)
// 		exiterror(ALC_ERR, 1);
// 	cmndpath = getpath(data, cmndname, env);
// 	if (cmndpath == NULL)
// 	 	exiterror(NULL, 1);
// 	getinfile(data, argv);
// 	data->pid1 = fork();
// 	if (data->pid1 < 0)
// 		exiterror(NULL, 1);
// 	if (data->pid1 == 0)
// 	{
// 		close(data->pipefd[0]);
// 		stdredirection(data->infile, data->pipefd[1]);
// 		close(data->pipefd[1]);
// 		close(data->infile);
// 		if (execve(cmndpath, cmndargs, NULL) < 0)
// 			exiterror(NULL, 1);
// 	}
// 	if(!data->islocal)
// 	{
// 		free(cmndpath);
// 		freeall(cmndargs);
// 	}
// }

void	execmnd(t_data *data, const char **argv, char **env, int cmndi)
{
	char	*cmndname;
	char	**cmndargs;
	char	*cmndpath;
	cmndargs = getcmndargs(argv[cmndi], &cmndname);
	if (cmndargs == NULL)
		exiterror(ALC_ERR, 1);
	cmndpath = getpath(data, cmndname, env);
	if (cmndpath == NULL)
	 	exiterror(NULL, 1);
	data->pids[cmndi - 2] = fork();
	if (data->pids[cmndi - 2] < 0)
		exiterror(NULL, 1);
	if (data->pids[cmndi - 2] == 0)
	{
		closepipes(data, cmndi - 3, cmndi, 0);
		stdredirection(data->toread, data->towrite);
		close(data->toread);
		close(data->towrite);
		if (execve(cmndpath, cmndargs, NULL) < 0)
			exiterror(NULL, 1);
	}
	if(!data->islocal)
	{
		free(cmndpath);
		freeall(cmndargs);
	}
}

// void	execmnd2(t_data *data, const char **argv, char **env)
// {
// 	char	*cmndname;
// 	char	**cmndargs;
// 	char	*cmndpath;
// 	cmndargs = getcmndargs(argv[3], &cmndname);
// 	if (cmndargs == NULL)
// 		exiterror(ALC_ERR, 1);
// 	cmndpath = getpath(data, cmndname, env);
// 	if (cmndpath == NULL)
// 	 	exiterror(NULL, 1);
// 	getoutfile(data, argv);
// 	data->pid2 = fork();
// 	if (data->pid2 < 0)
// 		exiterror(NULL, 1);
// 	if (data->pid2 == 0)
// 	{
// 		close(data->pipefd[1]);
// 		stdredirection(data->pipefd[0], data->outfile);
// 		close(data->pipefd[0]);
// 		close(data->outfile);
// 		if (execve(cmndpath, cmndargs, NULL) < 0)
// 			exiterror(NULL, 1);
// 	}
// 	freeall(cmndargs);
// 	free(cmndpath);
// }
