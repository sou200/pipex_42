/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:34:24 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/28 02:29:33 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(int argc, t_data *data, char const **argv)
{
	data->islocal = 0;
	int i;

	i = 0;
	data->argc = argc;
	data->cmndc = argc - 3;
	data->pipec = argc - 4;
	data->pipefd = malloc(sizeof(int *)*(data->pipec));
	data->pids = malloc(sizeof(int)*(data->cmndc));
	if(data->pids == NULL || data->pipefd == NULL)
		exiterror(ALC_ERR, 1);
	while(i < data->pipec)
	{
		data->pipefd[i] = malloc(sizeof(int)*2);
		if(data->pipefd[i] == NULL)
			exiterror(ALC_ERR, 1);
		if (pipe(data->pipefd[i++]) < 0)
			exiterror(NULL, 1);
	}
	getinfile(data, argv[1]);
	getoutfile(data, argv[argc - 1]);
}

void piping(t_data *data, int i)
{
		if(i == 2)
		{
			data->toread = data->infile;
			data->towrite = data->pipefd[0][1];
		}
		else if(i == data->argc - 2)
		{
			data->toread = data->pipefd[data->argc - 5][0];
			data->towrite = data->outfile;
		}
		else
		{
			data->toread = data->pipefd[i - 3][0];
			data->towrite = data->pipefd[i - 2][1];
		}
}

// void f()
// {
// 	system("leaks pipex");
// }

int	main(int argc, char const *argv[], char **env)
{
	t_data	data;
	int i;
	init(argc, &data, argv);
	i = 2;
	while(i < argc - 1)
	{
		piping(&data, i);
		execmnd(&data ,argv, env, i);
		i++;
	}
	term(&data);
	return (0);
}
