NAME		=	rt
BONUS		=	bonus	
MAKE_LIBFT	=	makelibft
LIBFTPATH	=	libft/
LIBFT_AR	=	libft/libft.a

SRC_PATH			= ./
OBJ_PATH			= bin/
LIBFT_PATH			= libft/

OBJ_PATHS_INIT			=	$(addprefix $(OBJ_PATH),$(SETTERS_PATH) 		\
													$(WRITERS_PATH) 		\
													$(CONVERTS_PATH)		\
													$(PREPARE_FLAGS_PATH)	\
													$(NBR_MANAGEMENT_PATH)	\
													$(COMMANDS_PATH))
OBJ_PATHS_INIT			+= 	$(OBJ_PATH)
## No need for a \ on the last line
HEADERS_FILES				=	main.h
SRC_FILES					=	main.c

OBJREGULAR_FILES	= 	$(SRC_FILES:.c=.o)			## get all .o names from .c names

OBJ_FILES = $(OBJREGULAR_FILES)

SRC 		= $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ 		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

CC			=	clang

CFLAGS		+=	-W -Wall -Wextra -Werror -g3 -pedantic 		## '+=' allow to keep default flags.

LDFLAGS		=	-L$(LIBFTPATH) -lft

RM			= 	rm -f

OS			= $(shell uname)
ifeq ($(OS), Linux)
	CFLAGS	+= -DLINUX
endif

all					:	 $(OBJ_PATHS_INIT) $(MAKE_LIBFT) $(NAME)

$(LIBFT_PATH)  		:
	git clone https://github.com/Psycokwet/libft.git $(LIBFT_PATH)

$(MAKE_LIBFT)		: $(LIBFT_PATH)
	$(MAKE) -C $(LIBFT_PATH)

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c $(HEADERS_FILES)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJ_PATHS_INIT)	:
	mkdir -p  $@  

$(NAME)			: 	$(OBJ)  $(LIBFT_AR)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

$(BONUS)		: all
		
clean_local		:									## delete all .o
	$(RM) $(OBJ) $(OBJBONUS)

clean			:									## delete all .o
	$(RM) $(OBJ) $(OBJBONUS)
	$(MAKE) -C $(LIBFT_PATH) clean	

fclean			:	clean_local							## clean + delete executable
	$(RM) $(NAMETEST) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean					

re				:	fclean all							## delete all .o and recompile all. Must use when editing a .h

.PHONY			:	all bonus clean fclean re
## voir dependances plus tard 