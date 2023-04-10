/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:34:17 by serhouni          #+#    #+#             */
/*   Updated: 2023/02/28 17:14:57 by serhouni         ###   ########.fr       */
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
	int	**pipefd;
	int toread;
	int towrite;
	int	*pids;
	int argc;
	int cmndc;
	int pipec;
	int islocal;
}		t_data;


void	execmnd1(t_data *data, const char **argv, char **env);
void	execmnd2(t_data *data, const char **argv, char **env);
void	execmnd(t_data *data, const char **argv, char **env, int cmndi);
void	init(int argc, t_data *data, char const **argv);
void	freeall(char **arr);
char	*getpath(t_data *data, const char *name, char **env);
void	exiterror(char *message, int isexit);
char	**getcmndargs(const char *cmnd, char **name);

void getinfile(t_data *data, const char *name);
void getoutfile(t_data *data, const char *name);
void stdredirection(int in, int out);

void closepipes(t_data *data, int pre, int cmndi, int isparent);
void term(t_data *data);
void waitallpids(t_data *data);
void piping(t_data *data, int i);

#endif