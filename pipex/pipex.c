/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:34:24 by serhouni          #+#    #+#             */
/*   Updated: 2023/02/08 19:16:10 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initpipes(t_data *data)
{
	data->islocal = 0;
	if (pipe(data->pipefd) < 0)
		exiterror(NULL, 1);
}
// void f()
// {
// 	system("leaks pipex");
// }
int	main(int argc, char const *argv[], char **env)
{
	t_data	data;
	if (argc != 5)
		exiterror("Invalid Input!", 1);
	initpipes(&data);
	execmnd1(&data, argv, env);
	execmnd2(&data, argv, env);
	close(data.pipefd[1]);
	close(data.pipefd[0]);
	waitpid(data.pid1, NULL, 0);
	waitpid(data.pid2, NULL, 0);
	return (0);
}
