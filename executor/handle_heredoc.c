/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:54:32 by mel-gand          #+#    #+#             */
/*   Updated: 2023/07/14 17:51:10 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_heredoc(t_cmd *comm, int i)
{
	int	j;
	int	pos;

	j = 0;
	pos = 0;
	while (j < comm[i].nb_red)
	{
		if (comm[i].red->name == 6)
			pos = j;
		j = j + 2;
	}
	return (pos);
}

char	*save_data_her(t_parser *parser, t_red *red, char *save_her,
		char *input)
{
	if (red->ex_dollar == 2)
	{
		input = find_dollar_utils(parser, input, 0, 'e');
		if (input != NULL && check_special_variable(input) == 1)
			input = special_var_in_heredoc(input);
	}
	if (input != NULL)
	{
		save_her = ft_strjoin(save_her, input);
		save_her = ft_strjoin(save_her, "\n");
		free(input);
	}
	return (save_her);
}

int	here_doc(t_parser *parser, t_red *red)
{
	int		i;
	char	*input;
	char	*save_her;

	i = 0;
	save_her = NULL;
	red->fd = malloc(sizeof(int) * 2 + 1);
	if (pipe(red->fd) == -1)
		fd_error(parser);
	while (1)
	{
		input = readline("> ");
		if (input == NULL || ft_strcmp(input, red->data) == 0)
			break ;
		else
			save_her = save_data_her(parser, red, save_her, input);
	}
	if (save_her != NULL)
	{
		ft_putstr_fd(save_her, red->fd[1]);
		free(save_her);
	}
	close(red->fd[1]);
	return (red->fd[0]);
}

int	handle_heredoc(t_parser *parser, int i)
{
	int	j;
	int	fd_r;
	int	nb_her;

	fd_r = 0;
	nb_her = 0;
	if (parser->comm[i].nb_red != 0)
	{
		j = 0;
		while (j < parser->comm->nb_red)
		{
			if (parser->comm[i].red[j].name == 6)
				fd_r = here_doc(parser, &parser->comm[i].red[j + 1]);
			j = j + 2;
		}
	}
	return (fd_r);
}
