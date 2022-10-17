NAME = libft.a

WWW := -Wall -Wextra -Werror

INCLUDES := -I includes

FLAGS = $(WWW) $(INCLUDES)

CC = gcc

TEST = test_bin

FILES = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr 		   \
			ft_memcmp ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat 	   \
			ft_strncat ft_strlcat ft_strchr ft_strrchr ft_strstr ft_strnstr    \
			ft_strcmp ft_strncmp ft_atoi ft_isalpha ft_isdigit ft_isalnum 	   \
			ft_isascii ft_isprint ft_toupper ft_tolower ft_putchar ft_putstr   \
			ft_memrcpy ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr 	   \
			ft_strsplit ft_countwords ft_get_delim_str ft_striter ft_striteri  \
			ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin	   \
			ft_strtrim ft_itoa ft_strrev ft_intlen ft_putendl ft_putchar_fd	   \
			ft_putstr_fd ft_putendl_fd ft_putnbr ft_putnbr_fd ft_lstnew		   \
			ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap ft_memclear  \
			ft_strlcpy ft_iswhitespace get_next_line ft_lstpopref ft_strjoind  \
			ft_strsplit_free ft_freearray ft_intmax ft_intmin ft_clampint

SRCSDIR := srcs
SRCS := $(addprefix $(SRCSDIR)/, $(addsuffix .c, $(FILES)))

OBJSDIR := objs
OBJS := $(addprefix $(OBJSDIR)/, $(addsuffix .o, $(FILES)))

all: $(NAME) 

$(NAME): .prerequisites $(OBJS) makefile
	@touch .prerequisites
	@echo "Packaging libft\n"
	@ar -rc $(NAME) $(OBJS)

.prerequisites: $(OBJSDIR) $(HDRS) $(SRCS)

$(OBJS): $(OBJSDIR)/%.o:$(SRCSDIR)/%.c $(HDRS) Makefile
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJSDIR):
	@mkdir -p objs

$(HDRS):
	touch $@

$(SRCS):
	touch$@

clean:
	@echo "Cleaning libft object files\n"
	@rm -rf $(OBJSDIR)

fclean: clean
	@echo "Cleaning libft library\n"
	@rm -f $(NAME)

re: fclean all
