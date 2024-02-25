LIBFT_PATH = Ultimate_Libft
SRC_PATH = src

NAME = fdf

SCRS = $(SRC_PATH)/main.c\
$(SRC_PATH)/functions_for_colors.c\
$(SRC_PATH)/error_msgs.c\
$(SRC_PATH)/load_matrix.c\
$(SRC_PATH)/struct_utils.c\
$(SRC_PATH)/checking_optional_color_parameter.c\
$(SRC_PATH)/struct_utils2.c\

OBJS = $(SCRS:.c=.o)

HEADER = $(SRC_PATH)/fdf.h

COMPILER = $(CC)

CFLAGS = -Wall -Werror -Wextra
LIBRARY_FLAG = -LUltimate_Libft -lft -LMLX42 -lmlx42 -ldl -lglfw -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
EXEC-NAME-FLAG = -o

RM = rm -rf

all: make-library $(NAME)

make-library:
	$(MAKE) -C $(LIBFT_PATH)

make-library-debug:
	$(MAKE) -C $(LIBFT_PATH) debug

$(NAME): $(OBJS) $(HEADER)
	$(COMPILER) $(CFLAGS) $(OBJS) $(LIBRARY_FLAG) $(EXEC-NAME-FLAG) $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

debug: CFLAGS += -g
debug: make-library-debug $(NAME)