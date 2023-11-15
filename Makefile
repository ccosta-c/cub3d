# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 11:04:41 by ccosta-c          #+#    #+#              #
#    Updated: 2023/11/13 11:04:50 by ccosta-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COLORS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COMMANDS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CC = cc
RM = rm -f
AR = ar -rcs

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FLAGS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CFLAGS		= -Wall -Wextra -Werror -g
MKFLAGS		= --no-print-directory
LIBXFLAGS	= -L ./minilibx-linux -Ilmlx -lXext -lX11 -lm
LIBFTFLAGS	= -L ./libft -lft

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FOLDERS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
DEPS		= includes
SRCS		= .
SRCS_BONUS	= bonus
LIBFT		= libft
LIBX 		= minilibx-linux

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FILES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
SRC				=	parser.c \
					debugging.c \
					utils.c \
					frees.c \
					initialize.c \
					checks.c
OBJS 			:= $(SRC:.c=.o)
BONUS			=
OBJS_BONUS		:= $(BONUS:.c=.o)
NAME			= cub3D
NAME_BONUS		= cub3D
TARGET			= $(addprefix $(SRCS)/, $(OBJS))
TARGET_BONUS	= $(addprefix $(SRCS_BONUS)/, $(OBJS_BONUS))


#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RULES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
all: $(NAME)

$(NAME): $(TARGET)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)libft/*$(RESET)"
	make $(MKFLAGS) -C $(LIBFT)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)minilibx-linux/*$(RESET)"
	make all $(MKFLAGS) -sC $(LIBX)

	$(CC) $(CFLAGS) main.c $(TARGET) $(LIBFTFLAGS) $(LIBXFLAGS) -o $(NAME)

	echo "$(GREEN)Done.$(RESET)"

%.o : %.c
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean $(MKFLAGS) -C $(LIBFT)
	echo "[$(RED) Deleted $(RESET)] $(GREEN)libft/*.o$(RESET)"
	make clean $(MKFLAGS) -C $(LIBX)
	echo "[$(RED) Deleted $(RESET)] $(GREEN)minilibx-linux/*.o$(RESET)"
	echo "[$(RED) Deleted $(RESET)] $(GREEN)*/*.o$(RESET)"
	$(RM) $(TARGET) $(TARGET_BONUS)

fclean: clean
	make fclean $(MKFLAGS) -C $(LIBFT)
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

bonus: $(TARGET_BONUS)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)libft/*$(RESET)"
	make $(MKFLAGS) -C $(LIBFT)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)minilibx-linux/*$(RESET)"
	make $(MKFLAGS) -sC $(LIBX)
	$(CC) $(CFLAGS) bonus/main.c $(TARGET_BONUS) $(LIBFTFLAGS) $(LIBXFLAGS) -o $(NAME_BONUS) -I $(DEPS)
	echo "$(GREEN)Done.$(RESET)"

debug:
	$(CC) $(CFLAGS) $(LIBXFLAGS) main.c $(SRC) libft/libft.a minilibx-linux/libmlx.a -g

.SILENT:
re: fclean all
