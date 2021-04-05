NAME				=	rt
BONUS				=	bonus	
MAKE_LIBFT			=	makelibft
LIBSPATH			=	libs/
LIBFTPATH			=	libft/
LIBFT_AR			=	libft.a
LIBMLX_AR			= 	libmlx.a

SRC_PATH			= ./srcs/
OBJ_PATH			= bin/
LIBFT_PATH			= libft/
LIBMLX_UNIX_PATH	= minilibx-linux/

COLORS_PATH = colors/
EXAMPLE_PATH = example/

OBJ_PATHS_INIT			=	$(addprefix $(OBJ_PATH),$(COLORS_PATH) 		\
													$(EXAMPLE_PATH))
OBJ_PATHS_INIT			+= 	$(OBJ_PATH)
## No need for a \ on the last line
HEADERS_FILES				=	cub3d.h
SRC_FILES					=	main.c
COLORS_FILES				=	get_opposite.c 	\
								add_shade.c 	\
								create_trgb.c

SRC_FILES += $(addprefix $(COLORS_PATH), $(COLORS_FILES))


OBJREGULAR_FILES	= 	$(SRC_FILES:.c=.o)			## get all .o names from .c names

OBJ_FILES = $(OBJREGULAR_FILES)

SRC 		= $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ 		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

CC			=	clang

CFLAGS		+=	-W -Wall -Wextra -Werror -g3 -pedantic 		## '+=' allow to keep default flags.

LDFLAGS		=	-L$(addprefix $(LIBSPATH), $(LIBFTPATH)) -lft -L$(addprefix $(LIBSPATH), $(LIBMLX_UNIX_PATH)) -lm -lbsd -lX11 -lXext $(addprefix $(addprefix $(LIBSPATH), $(LIBMLX_UNIX_PATH)), $(LIBMLX_AR))

RM			= 	rm -f

OS			= $(shell uname)
ifeq ($(OS), Linux)
	CFLAGS	+= -DLINUX
endif

all					:	 $(OBJ_PATHS_INIT) $(MAKE_LIBFT) $(NAME)


$(addprefix $(LIBSPATH), $(LIBFT_PATH))  		:
	git clone https://github.com/Psycokwet/libft.git $(addprefix $(LIBSPATH), $(LIBFT_PATH))

$(MAKE_LIBFT)		: $(addprefix $(LIBSPATH), $(LIBFT_PATH))
	$(MAKE) -C $(addprefix $(LIBSPATH), $(LIBFT_PATH))

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c $(HEADERS_FILES)
	$(CC) -o $@ -c $< $(CFLAGS)  $(INC) 

$(OBJ_PATHS_INIT)	:
	mkdir -p  $@  

$(NAME)			: 	$(OBJ)  $(addprefix $(LIBSPATH), $(addprefix $(LIBFTPATH),$(LIBFT_AR)))
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)  $(INC) 

$(BONUS)		: all
		
clean_local		:									## delete all .o
	$(RM) $(OBJ) $(OBJBONUS)

clean			:									## delete all .o
	$(RM) $(OBJ) $(OBJBONUS)
	$(MAKE) -C $(addprefix $(LIBSPATH), $(LIBFT_PATH)) clean	

fclean			:	clean_local							## clean + delete executable
	$(RM) $(NAMETEST) $(NAME)
	$(MAKE) -C $(addprefix $(LIBSPATH), $(LIBFT_PATH)) fclean					

re				:	fclean all							## delete all .o and recompile all. Must use when editing a .h

.PHONY			:	all bonus clean fclean re
## voir dependances plus tard 