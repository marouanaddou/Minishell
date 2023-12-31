/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unclosed_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:52:25 by mel-gand          #+#    #+#             */
/*   Updated: 2023/07/12 16:52:33 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	dquote(char *str, int *i)
{
	int	cnt;

	cnt = 0;
	while (str[*i])
	{
		if (str[*i] == 34)
		{
			cnt++;
			break ;
		}
		(*i)++;
	}
	if (cnt == 0)
	{
		ft_printf("bash: unexpected EOF while looking for matching\n");
		g_exit = 258;
		free(str);
		return (-1);
	}
	return (0);
}

int	quote(char *str, int *i)
{
	int	cnt;

	cnt = 0;
	while (str[*i])
	{
		if (str[*i] == 39)
		{
			cnt++;
			break ;
		}
		(*i)++;
	}
	if (cnt == 0)
	{
		ft_printf("bash: unexpected EOF while looking for matching\n");
		g_exit = 258;
		free(str);
		return (-1);
	}
	return (0);
}

int	check_unclosed_quotes(char *str)
{
	int	i;
	int	flag;

	i = 0;
	while (str[i])
	{
		if (str[i] == 34)
		{
			i++;
			flag = dquote(str, &i);
		}
		else if (str[i] == 39)
		{
			i++;
			flag = quote(str, &i);
		}
		if (flag == -1)
			return (-1);
		i++;
	}
	return (flag);
}
