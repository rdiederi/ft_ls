# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/31 02:35:30 by rdiederi          #+#    #+#              #
#    Updated: 2018/08/29 19:15:52 by rdiederi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang

FLAGS = -Wall -Werror -Wextra

INC := -I includes

################################################################################
#------------------------------------------------------------------------------#
#								    Libft                                      #
#------------------------------------------------------------------------------#
LIBFT_SRC = ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memccpy.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strlen.c\
			ft_strdup.c\
			ft_strcpy.c\
			ft_strncpy.c\
			ft_strcat.c\
			ft_strncat.c\
			ft_strlcat.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strstr.c\
			ft_strnstr.c\
			ft_strcmp.c\
			ft_strncmp.c\
			ft_atoi.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_memalloc.c\
			ft_memdel.c\
			ft_strnew.c\
			ft_strdel.c\
			ft_strclr.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strequ.c\
			ft_strnequ.c\
			ft_strsub.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_strsplit.c\
			ft_itoa.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_putendl.c\
			ft_memccpy.c\
			ft_putnbr.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_islower.c\
			ft_isupper.c\
			ft_check_int_max.c\
			ft_int_len.c\
			ft_lstnew.c\
			ft_lstdelone.c\
			ft_lstdel.c\
			ft_lstadd.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_get_lst_len.c\
			ft_isspace.c\
			ft_itoa_base.c\
			ft_str_tolower.c\
			ft_str_is_uppercase.c\
			ft_str_is_printable.c\
			ft_str_is_numeric.c\
			ft_str_is_lowercase.c\
			ft_str_is_alpha.c\
			ft_nbr_to_oct.c\
			ft_memdup.c\
			ft_isxdigit.c\
			ft_isgraph.c\
			ft_iscntrl.c\
			ft_isblank.c\
			ft_count_whitespace.c\
			ft_abs.c\
			ft_lstswap.c
LIBFT =		$(addprefix My_libft/, $(LIBFT_SRC))
################################################################################

################################################################################
#------------------------------------------------------------------------------#
#	     							get_next_line                              #
#------------------------------------------------------------------------------#
GNL_SRC = 	get_next_line.c
GNL	= 		$(addprefix get_next_line/, $(GNL_SRC))
################################################################################

################################################################################
#------------------------------------------------------------------------------#
#                                   ft_printf                                  #
#------------------------------------------------------------------------------#
FT_PRINTF_SRC = buffer.c\
				ft_check_fmt.c\
				ft_find_flag.c\
				ft_print_error.c\
				ft_printf.c\
				ft_printf_base.c\
				ft_printf_base_tools.c\
				ft_printf_nbr.c\
				ft_printf_nbr_tools.c\
				ft_printf_putchar.c\
				ft_printf_string.c\
				ft_printf_stringuni.c\
				ft_printf_stringuni2.c\
				ft_putchar_uni.c\
				ft_putchar_uni2.c\
				ft_type.c
FT_PRINTF =	$(addprefix ft_printf/, $(FT_PRINTF_SRC))
################################################################################

OBJ_LIST = 	$(patsubst %.c, %.o, $(LIBFT) $(GNL) $(FT_PRINTF))

BIN_PATH = 	bin
BIN =		$(addprefix $(BIN_PATH)/, $(OBJ_LIST))

all : $(NAME)

$(NAME) : $(BIN)
	ar rc $@ $?
	ranlib $@

$(BIN_PATH)/%.o :  %.c
	@mkdir -p $(BIN_PATH)
	@mkdir -p $(addprefix $(BIN_PATH)/,$(dir $<))
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	rm -rf $(BIN_PATH)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re
