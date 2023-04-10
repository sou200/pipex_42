/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:34:21 by serhouni          #+#    #+#             */
/*   Updated: 2023/02/27 00:43:46 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void getinfile(t_data *data, const char *name)
{
	data->infile = open(name, O_RDONLY);
    if(data->infile < 0)
        exiterror(NULL, 1);
}
void getoutfile(t_data *data, const char *name)
{
	data->outfile = open(name, O_WRONLY | O_CREAT, 0770);
    if(data->outfile < 0)
        exiterror(NULL, 1);
}
void stdredirection(int in, int out)
{
	dup2(in, STDIN_FILENO);
    dup2(out, STDOUT_FILENO);
}