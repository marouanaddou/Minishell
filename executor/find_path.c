/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:27:03 by mel-gand          #+#    #+#             */
/*   Updated: 2023/06/19 12:23:43 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	path_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i + 1])
				i++;
		}
		i++;
	}
	return (count);
}

char* const    *find_execpath(t_parser *parser, int i)
{
    char *pathenv;
    char **pathname;
    int nb;
    int j;

    nb = 0;
    j = 0;
    pathenv = getenv("PATH"); // get the path from the env struct
    pathname = malloc (sizeof(char *) * (path_count(pathenv, ':') + 1));
    pathname = ft_split(pathenv, ':', &nb);
    while (pathname[j])
    {
        pathname[j] = ft_strjoin(pathname[j], "/");
        pathname[j] = ft_strjoin(pathname[j], parser->comm[i].new_cmd[0]);
        if ((access(pathname[j], 0)== 0))
            break;
        j++;
    }
    // put the return in another char * and free the cha** pathname
    return ((char* const    *)pathname[j]);
}