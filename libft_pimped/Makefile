COMPIL = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude
#MAKEFLAGS += -j20

NAME = libft.a

DIR = src/

FT_IS_DIR = ft_is/
FT_IS_SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c 
FT_IS_OBJ = ${addprefix ${FT_IS_DIR}, ${FT_IS_SRCS:.c=.o}}

FT_MEM_DIR = ft_mem/
FT_MEM_SRCS = ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c 
FT_MEM_OBJ = ${addprefix ${FT_MEM_DIR}, ${FT_MEM_SRCS:.c=.o}}

FT_STR_DIR = ft_str/
FT_STR_SRCS = ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			  ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
			  ft_strrchr.c ft_strtrim.c ft_strcmp.c 
FT_STR_OBJ = ${addprefix ${FT_STR_DIR}, ${FT_STR_SRCS:.c=.o}}

FT_LST_DIR = ft_lst/
FT_LST_SRCS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
			  ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
			  ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
FT_LST_OBJ = ${addprefix ${FT_LST_DIR}, ${FT_LST_SRCS:.c=.o}}

FT_PUT_DIR = ft_put/
FT_PUT_SRCS = ft_putchar.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
FT_PUT_OBJ = ${addprefix ${FT_PUT_DIR}, ${FT_PUT_SRCS:.c=.o}}

FT_GNL_DIR = gnl/
FT_GNL_SRCS = get_next_line.c get_next_line_utils.c
FT_GNL_OBJ = ${addprefix ${FT_GNL_DIR}, ${FT_GNL_SRCS:.c=.o}}

FT_PRINTF_DIR = ft_printf/
FT_PRINTF_SRCS = ft_printf.c ft_print_hex.c ft_print_ptr.c ft_utils2.c ft_utils.c
FT_PRINTF_OBJ = ${addprefix ${FT_PRINTF_DIR}, ${FT_PRINTF_SRCS:.c=.o}}

FT_OTHER_DIR = ft_other/
FT_OTHER_SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_itoa.c ft_split.c ft_substr.c \
				ft_tolower.c ft_toupper.c ft_is_splitable.c ft_free_tab.c
FT_OTHER_OBJ = ${addprefix ${FT_OTHER_DIR}, ${FT_OTHER_SRCS:.c=.o}}


OBJS = ${FT_IS_OBJ} ${FT_MEM_OBJ} ${FT_STR_OBJ} ${FT_LST_OBJ} \
	   ${FT_PUT_OBJ} ${FT_GNL_OBJ} ${FT_PRINTF_OBJ} \
	   ${FT_OTHER_OBJ}

%.o: %.c
	${COMPIL} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS} 

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY = all bonus clean fclean re
