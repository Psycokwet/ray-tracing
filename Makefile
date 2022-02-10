NAME				=	cub3D
NAME_BONUS			=	cub3D_bonus
MAKE_LIBFT			=	makelibft
LIBSPATH			=	libs/
LIBFTPATH			=	libft/
LIBFT_AR			=	libft.a
LIBMLX_AR			= 	libmlx.a

SRC_PATH			= ./srcs/
SRC_BONUS_PATH		= ./srcs_bonus/
OBJ_PATH			= bin/
OBJ_BONUS_PATH		= bin_bonus/

LIBFT_PATH			= libft/
LIBMLX_UNIX_PATH	= minilibx-linux/

COLORS_PATH 	= colors/
IMG_PATH		= img/
FILES_PATH		= files/
COMMON_PATH		= common/
GAME_PATH		= game/

OBJ_PATHS_INIT			=	$(addprefix $(OBJ_PATH),$(COLORS_PATH) 	\
													$(IMG_PATH) 	\
													$(COMMON_PATH) 	\
													$(GAME_PATH) 	\
													$(FILES_PATH))
OBJ_PATHS_INIT			+= 	$(OBJ_PATH)

OBJ_BONUS_PATHS_INIT		=	$(addprefix $(OBJ_BONUS_PATH),$(COLORS_PATH) 	\
														$(IMG_PATH) 	\
														$(COMMON_PATH) 	\
														$(GAME_PATH) 	\
														$(FILES_PATH))
OBJ_BONUS_PATHS_INIT	+= 	$(OBJ_BONUS_PATH)


## No need for a \ on the last line
HEADERS_FILES				=	cub3d.h
HEADERS_FILES_BONUS			=	cub3D.h
SRC_FILES					=	main.c
SRC_BONUS_FILES				=	main.c
COLORS_FILES				=	get_opposite.c 	\
								add_shade.c 	\
								create_trgb.c
IMG_FILES					=	my_mlx_pixel_put.c
FILES_FILES					=	args_parse.c	\
								check_save_arg.c \
								free_array.c\
								free_env.c\
								get_colors_from_line.c\
								init_colors.c\
								init_srcs.c\
								is_map.c\
								parse_file.c\
								parse_line.c\
								parse_map.c\
								parse_value.c\
								set_colors_fc.c\
								set_src_map.c\
								set_srcs.c\
								test_line_for_map.c
COMMON_FILES				=	quit_app.c
GAME_FILES					=	start_cub_3d.c \
								events.c \
								init.c \
								print_pictures.c \
								rotations.c \
								run.c \
								raycasting.c
BONUS_FILES					=	init_bonus_text.c \
								mousing.c \
								raycasting_floor_ceil.c

SRC_FILES += $(addprefix $(COLORS_PATH), $(COLORS_FILES))
SRC_FILES += $(addprefix $(IMG_PATH), $(IMG_FILES))
SRC_FILES += $(addprefix $(FILES_PATH), $(FILES_FILES))
SRC_FILES += $(addprefix $(COMMON_PATH), $(COMMON_FILES))
SRC_FILES += $(addprefix $(GAME_PATH), $(GAME_FILES))

SRC_BONUS_FILES += $(addprefix $(COLORS_PATH), $(COLORS_FILES))
SRC_BONUS_FILES += $(addprefix $(IMG_PATH), $(IMG_FILES))
SRC_BONUS_FILES += $(addprefix $(FILES_PATH), $(FILES_FILES))
SRC_BONUS_FILES += $(addprefix $(COMMON_PATH), $(COMMON_FILES))
SRC_BONUS_FILES += $(addprefix $(GAME_PATH), $(GAME_FILES))
SRC_BONUS_FILES += $(addprefix $(GAME_PATH), $(BONUS_FILES))

OBJREGULAR_FILES	= 	$(SRC_FILES:.c=.o)			## get all .o names from .c names
OBJBONUS_FILES = $(SRC_BONUS_FILES:.c=.o)

OBJ_FILES = $(OBJREGULAR_FILES)
OBJ_BONUS_FILES = $(OBJBONUS_FILES)

SRC 		= $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ 		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

SRC_BONUS = $(addprefix $(SRC_BONUS_PATH), $(SRC_BONUS_FILES))
OBJ_BONUS = $(addprefix $(OBJ_BONUS_PATH), $(OBJ_BONUS_FILES))

CC			=	clang

CFLAGS		+=	-W -Wall -Wextra -g -D BUFFER_SIZE=32 -g3 -Werror  -pedantic 		## '+=' allow to keep default flags.

LDFLAGS		=	-L$(addprefix $(LIBSPATH), $(LIBFTPATH)) -lft -L$(addprefix $(LIBSPATH), $(LIBMLX_UNIX_PATH)) -lm -lbsd -lX11 -lXext $(addprefix $(addprefix $(LIBSPATH), $(LIBMLX_UNIX_PATH)), $(LIBMLX_AR))

RM			= 	rm -f

OS			= $(shell uname)
ifeq ($(OS), Linux)
	CFLAGS	+= -DLINUX
endif

all					:	$(OBJ_PATHS_INIT) $(MAKE_LIBFT) $(NAME)

bonus				:	$(OBJ_BONUS_PATHS_INIT) $(MAKE_LIBFT) $(NAME_BONUS)

$(addprefix $(LIBSPATH), $(LIBFT_PATH))  		:
	git clone https://github.com/Psycokwet/libft.git $(addprefix $(LIBSPATH), $(LIBFT_PATH))

$(MAKE_LIBFT)		: $(addprefix $(LIBSPATH), $(LIBFT_PATH))
	$(MAKE) -C $(addprefix $(LIBSPATH), $(LIBFT_PATH))

$(MAKE_LIBFT)		: $(addprefix $(LIBSPATH), $(LIBMLX_UNIX_PATH))
	$(MAKE) -C $(addprefix $(LIBSPATH), $(LIBMLX_UNIX_PATH))

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c $(HEADERS_FILES)
	$(CC) -o $@ -c $< $(CFLAGS)  $(INC)

$(OBJ_BONUS_PATH)%.o	:	$(SRC_BONUS_PATH)%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I ./srcs_bonus/

$(OBJ_PATHS_INIT)	:
	mkdir -p  $@

$(OBJ_BONUS_PATHS_INIT)	:
	mkdir -p  $@

$(NAME)			: 	$(OBJ)  $(addprefix $(LIBSPATH), $(addprefix $(LIBFTPATH),$(LIBFT_AR)))
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)  $(INC)

$(NAME_BONUS)	: 	$(OBJ_BONUS)  $(addprefix $(LIBSPATH), $(addprefix $(LIBFTPATH),$(LIBFT_AR)))
	$(CC) -o $(NAME_BONUS) $(OBJ_BONUS) $(LDFLAGS)  $(INC)


clean_local		:									## delete all .o
	$(RM) $(OBJ) $(OBJ_BONUS)

clean			:									## delete all .o
	$(RM) $(OBJ) $(OBJ_BONUS)
	$(MAKE) -C $(addprefix $(LIBSPATH), $(LIBFT_PATH)) clean

fclean			:	clean_local							## clean + delete executable
	$(RM) $(NAMETEST) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(addprefix $(LIBSPATH), $(LIBFT_PATH)) fclean
	make -C $(addprefix $(LIBSPATH), $(LIBMLX_UNIX_PATH)) clean

re				:	fclean all							## delete all .o and recompile all. Must use when editing a .h

.PHONY			:	all bonus clean fclean re
## voir dependances plus tard
