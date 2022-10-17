NAME := fdf
CC := gcc
FILES := main render init_map helpers interface
SRCSDIR := srcs
SRCS := $(addprefix $(SRCSDIR)/, $(addsuffix .c, $(FILES)))
OBJSDIR := objs
OBJS := $(addprefix $(OBJSDIR)/, $(addsuffix .o, $(FILES)))
WWW := -Wall -Wextra -Werror
MINILIB := -lmlx -framework OpenGL -framework AppKit
INCS := -I includes -I libft/includes
HDRS = libft/includes/libft.h includes/fdf.h
LIBFT := $(INCS) -L libft/ -lft
CFLAGS := $(WWW) $(MINILIB) $(LIBFT) -fsanitize=address
OFLAGS := $(WWW) $(INCS) 

.PHONY: all libftcomp clean fclean re run debug drun

all: $(NAME)

$(NAME): .prerequisites libft/libft.a $(OBJS) Makefile
	@touch .prerequisites
	@echo "Compiling project binary\n"
	@$(CC) $(OBJS) $(CFLAGS) -o $@

.prerequisites: $(OBJSDIR) $(HDRS) $(SRCS)

$(OBJSDIR):
	@mkdir -p $@

$(HDRS):
	touch $@

$(SRCS):
	touch $@

$(OBJS): $(OBJSDIR)/%.o:$(SRCSDIR)/%.c $(HDRS) Makefile
	@$(CC) $(OFLAGS) -c $< -o $@

libft/libft.a:
	@make --no-print-directory -C ./libft

clean:
	@echo "Cleaning project object files\n"
	@rm -rf $(OBJSDIR)

fclean: clean
	@make --no-print-directory -C ./libft fclean
	@echo "Cleaning project binary\n"
	@rm -f $(NAME)
	@rm -f .prerequisites

re: fclean all

run: re
	./$(NAME) test_maps/basictest.fdf

debug:
	@make -C ./libft testlib
	$(CC) $(SRCS) $(CFLAGS) -g -o $(NAME)

drun: fclean debug
	lldb $(NAME) 
