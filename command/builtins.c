/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 23:07:52 by mel-gand          #+#    #+#             */
/*   Updated: 2023/06/15 14:37:52 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int builtin_commands(t_parser *parser, int i)
{
    if (ft_strnstr(parser->comm[i].new_cmd[0], "echo") == 0)
        g_exit = echo_command(parser->comm[i].new_cmd);
    else if (ft_strnstr(parser->comm[i].new_cmd[0], "cd") == 0)
        g_exit = cd_command(parser->comm[i].new_cmd);
    else if (ft_strnstr(parser->comm[i].new_cmd[0], "pwd") == 0)
        g_exit = pwd_command();
    else if (ft_strnstr(parser->comm[i].new_cmd[0], "$?") == 0)
    {
        g_exit = special_var(parser->comm[i].new_cmd);
    }
    // else if (ft_strnstr(comm[i].cmd[0], "export") == 0)
    //     export_command(comm);
    // else if (ft_strnstr(comm[i].cmd[0], "unset") == 0)
    //     unset_command(comm);
    // else if (ft_strnstr(comm[i].cmd[0], "env") == 0)
    //     env_command(comm);
    else if (ft_strnstr(parser->comm[i].new_cmd[0], "exit") == 0)
        exit_command(parser->comm[i].new_cmd);
    return (g_exit);
}