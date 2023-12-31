/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:31:38 by maddou            #+#    #+#             */
/*   Updated: 2023/07/14 12:49:36 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redir_out(t_cmd *cmd, int i)
{
	int	fd;

	fd = open(cmd->red[i + 1].data, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		g_exit = 1;
		ft_printf("bash: %s: %s", cmd->red[i + 1].data, strerror(errno));
		return (1);
	}
	if (access(cmd->red[i + 1].data, F_OK | W_OK) == -1)
	{
		g_exit = 1;
		ft_printf("bash: %s: %s", cmd->red[i + 1].data, strerror(errno));
		return (1);
	}
	dup2(fd, 1);
	close(fd);
	return (0);
}

int	dredir_out(t_cmd *cmd, int i)
{
	int	fd;

	fd = open(cmd->red[i + 1].data, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		g_exit = 1;
		ft_printf("bash: %s: %s", cmd->red[i + 1].data, strerror(errno));
		return (1);
	}
	if (access(cmd->red[i + 1].data, F_OK | W_OK) == -1)
	{
		g_exit = 1;
		ft_printf("bash: %s: %s", cmd->red[i + 1].data, strerror(errno));
		return (1);
	}
	dup2(fd, 1);
	close(fd);
	return (0);
}

int	redir_in(t_cmd *cmd, int i)
{
	int	fd;

	fd = open(cmd->red[i + 1].data, O_RDONLY, 0644);
	if (fd < 0)
	{
		g_exit = 1;
		ft_printf("bash: %s: %s\n", cmd->red[i + 1].data, strerror(errno));
		return (1);
	}
	if (access(cmd->red[i + 1].data, F_OK | R_OK) == -1)
	{
		g_exit = 1;
		ft_printf("bash: %s: %s\n", cmd->red[i + 1].data, strerror(errno));
		return (1);
	}
	dup2(fd, 0);
	close(fd);
	return (0);
}

int	check_redirect_in_out(t_cmd *cmd, int *i)
{
	if (cmd->red[*i].name == 4)
	{
		if (redir_in(cmd, *i) == 1)
			return (1);
		(*i)++;
	}
	else if (cmd->red[*i].name == 5)
	{
		if (redir_out(cmd, *i) == 1)
			return (1);
		(*i)++;
	}
	return (0);
}

int	check_redirect(t_cmd *cmd, int fd_her)
{
	int	i;

	i = 0;
	while (i < cmd->nb_red)
	{
		if (cmd->red[i].name == 4 || cmd->red[i].name == 5)
		{
			if (check_redirect_in_out(cmd, &i) == 1)
				return (1);
		}
		else if (cmd->red[i].name == 7)
		{
			if (dredir_out(cmd, i) == 1)
				return (1);
			i++;
		}
		else if (cmd->red[i].name == 6)
		{
			dup2(fd_her, 0);
			close(fd_her);
			i++;
		}
		i++;
	}
	return (0);
}
