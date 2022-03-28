#NAMES
NAME		= pipex
MAKE		= make

#COMP USE CC INSTEAD?!?!??!
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

#LIBFT
LIBFT_DIR	= libft
LIBFT		= libft.a
LIBFT_MAKE	= cd $(LIBFT_DIR) && $(MAKE)
LIBFT_INC	= -L libft -lft

#SRC
SRC_DIR		= src
SRC			= $(SRC_DIR)/pipex.c \
				$(SRC_DIR)/parse.c \

SRC_BON_DIR	= src_bonus
SRC_BON		= $(SRC_BON_DIR)/pipex_bonus.c  \

#INC
INC_DIR		= inc
INC			= $(INC_DIR) pipex.h
INC_BON_DIR		= inc_bonus
INC_BON		= $(INC_BON_DIR) pipex_bonus.h

#OBJ
OBJ_DIR		= obj
OBJ			= $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.c=.o))
OBJ_BON_DIR		= obj_bonus
OBJ_BON		= $(patsubst $(SRC_BON_DIR)%, $(OBJ_BON_DIR)%, $(SRC_BON:.c=.o))

#OBJ_INC
OBJ_INC		= -I $(INC_DIR) -I libft
OBJ_BON_INC	= -I $(INC_BON_DIR) -I libft

#RMS
RM_DIR		= rm -rf
RM_FILE		= rm -f

#DEPS
$(NAME): $(OBJ)
	$(LIBFT_MAKE)
	$(CC) $(OBJ) $(LIBFT_INC) -o $(NAME)

#OBJ DEPS
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(OBJ_INC) -c $< -o $@

$(OBJ_BON_DIR)/%.o: $(SRC_BON_DIR)/%.c
	$(CC) $(CFLAGS) $(OBJ_BON_INC) -c $< -o $@

$(OBJ)		:	| $(OBJ_DIR)
$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

$(OBJ_BON)		:	| $(OBJ_BON_DIR)
$(OBJ_BON_DIR):
			mkdir -p $(OBJ_BON_DIR)


#RULES
all:	$(NAME)

bonus:	fclean $(NAME) $(OBJ_BON)
		$(LIBFT_MAKE)
		$(CC) $(OBJ_BON) $(LIBFT_INC) -o $(NAME)

clean:
		${RM_DIR} ${OBJ_DIR}
		${RM_DIR} ${OBJ_BON_DIR}


fclean:	clean
		${RM_FILE} $(NAME)
		cd $(LIBFT_DIR) && $(MAKE) fclean

re:		fclean all

#OTHER
.PHONY: all clean fclean re