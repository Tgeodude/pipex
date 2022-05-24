#NAMES
NAME		= pipex
MAKE		= make

#COMP USE CC INSTEAD?!?!??!
CC			= cc
CFLAGS		=  -g

#LIBFT
LIBFT_DIR	= libft
LIBFT		= libft.a
LIBFT_MAKE	= cd $(LIBFT_DIR) && $(MAKE)
LIBFT_INC	= -L libft -lft

#SRC
SRC_DIR		= Src
SRC			= $(SRC_DIR)/pipex_main.c \
				$(SRC_DIR)/pipex_error.c \
				$(SRC_DIR)/pipex_parse.c \
				$(SRC_DIR)/pipex_ft_split.c \
				$(SRC_DIR)/pipex_free.c \
				$(SRC_DIR)/pipex_path.c \

#INC
INC_DIR		= Inc
INC			= $(INC_DIR) pipex.h

#OBJ
OBJ_DIR		= Obj
OBJ			= $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.c=.o))
OBJ_BON_DIR		= Object_bonus
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



#RULES
all:	$(NAME)

clean:
		${RM_DIR} ${OBJ_DIR}
		${RM_DIR} ${OBJ_BON_DIR}


fclean:	clean
		${RM_FILE} $(NAME)
		cd $(LIBFT_DIR) && $(MAKE) fclean

re:		fclean all

#OTHER
.PHONY: all clean fclean re