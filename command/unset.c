/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:36:48 by maddou            #+#    #+#             */
/*   Updated: 2023/06/16 20:07:06 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void unset_command(t_parser *parser)
{
    int i;
    int j;
    int u;
    int v;

    if (parser->comm[0].new_cmd[1] != NULL)
    {
        i = length(parser->lex->env);
        j = length(parser->lex->exp);
        u = 0;
        v = 1;
        while (parser->comm[u].new_cmd[v] != NULL)
        {
            if (i != 0)
                remove_node(&parser->lex->env, parser->comm[u].new_cmd[v]);
            if (j != 0)
                remove_node(&parser->lex->exp, parser->comm[u].new_cmd[v]);
            g_exit = 0;
            v++;
        }
    }
    
}