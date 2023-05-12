# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 17:04:58 by mel-gand          #+#    #+#              #
#    Updated: 2023/05/12 16:04:24 by mel-gand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./libf/
LDFLAGS = -lreadline -L/Users/mel-gand/.brew/opt/readline/lib -I/Users/mel-gand/.brew/opt/readline/include
RM = rm -rf
SRC = minishell.c libf/ft_split.c libf/ft_strlen.c libf/ft_substr.c libf/ft_strdup.c libf/ft_strjoin.c tokenizer.c \
		handle_quotes.c tokenizer_error.c split_token.c  split_spaces.c split_spaces_utils.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c philo.h
	@$(CC) -c $(CFLAGS) $< -o $@ minishell.h libft/libft.h

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re