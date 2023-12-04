# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 16:29:03 by hualhash          #+#    #+#              #
#    Updated: 2023/11/28 19:18:02 by hualhash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c events.c init.c math_utils.c render.c string_utils.c ft_printf.c function1.c
OBJ = $(SRC:.c=.o)



LIBS = -Lminilibx -lmlx -framework OpenGL -framework AppKit -lm

TARGET = fractol

all: $(PRNTF_LIB) $(TARGET)

$(TARGET): $(OBJ) $(PRNTF_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
