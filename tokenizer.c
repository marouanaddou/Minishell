/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:38:20 by mel-gand          #+#    #+#             */
/*   Updated: 2023/05/12 21:19:49 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int tokenizer(t_lexer *lex)
{
    if (quotes_error(lex) == -1)
        return (-1);
    split_token(lex);
    if (pipe_error(lex) == -1)
        return (-1);
    return (0);
}