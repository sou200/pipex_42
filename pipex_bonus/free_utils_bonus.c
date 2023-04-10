/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:21:33 by serhouni          #+#    #+#             */
/*   Updated: 2023/02/28 17:01:34 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freeall(char **arr)
{
	int	i;

	i = 0;

	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

void term(t_data *data)
{
	int i;
	
	closepipes(data, 0, 0, 1);
	waitallpids(data);
	free(data->pids);
	i = 0;
	while(i < data->pipec)
		free(data->pipefd[i++]);
	free(data->pipefd);
}

void waitallpids(t_data *data)
{
	int i;

	i = 0;
	while(i < data->cmndc)
		waitpid(data->pids[i++], NULL, 0);	
}

void closepipes(t_data *data, int pre, int cmndi, int isparent)
{
	int i;

	i = 0;
	while(i < data->pipec)
	{
		if(i == pre && !isparent)
			close(data->pipefd[i][1]);
		else if(i == pre + 1 && !isparent)
			close(data->pipefd[i][0]);
		else
		{
			close(data->pipefd[i][0]);
			close(data->pipefd[i][1]);
		}
		i++;
	}
	if(cmndi == 2)
		close(data->outfile);
	else if(cmndi == data->argc - 2)
		close(data->infile);
	else
	{
		close(data->infile);
		close(data->outfile);
	}
}
