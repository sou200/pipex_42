/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:34:17 by serhouni          #+#    #+#             */
/*   Updated: 2023/02/08 16:28:17 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

#define ALC_ERR "Error: memory allocation!"

typedef struct s_data
{
	int	infile;
	int	outfile;
	int	pipefd[2];
	int	pid1;
	int	pid2;
	int islocal;
}		t_data;


void	execmnd1(t_data *data, const char **argv, char **env);
void	execmnd2(t_data *data, const char **argv, char **env);
void	initpipes(t_data *data);
void	freeall(char **arr);
char	*getpath(t_data *data, const char *name, char **env);
void	exiterror(char *message, int isexit);
char	**getcmndargs(const char *cmnd, char **name);

void getinfile(t_data *data, const char **argv);
void getoutfile(t_data *data, const char **argv);
void stdredirection(int in, int out);

#endif