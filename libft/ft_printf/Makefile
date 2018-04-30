NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

HANDLE = handlers

INCLUDES = ../includes

LIB = ../

CFLAGS = -c $(FLAGS)

SRC = ft_printf.c\
	  parser.c\
	  helper.c\
	  helper2.c\
	  $(HANDLE)/apply_app.c\
	  $(HANDLE)/apply_plusspace.c\
	  $(HANDLE)/apply_blanks.c\
	  $(HANDLE)/apply_zero.c\
	  $(HANDLE)/apply_precision.c\
	  $(HANDLE)/num_handler.c\
	  $(HANDLE)/double_handler.c\
	  $(HANDLE)/n_handler.c\
	  $(HANDLE)/char_handler.c\
	  $(HANDLE)/hex_handler.c\
	  $(HANDLE)/int_handler.c\
	  $(HANDLE)/octal_handler.c\
	  $(HANDLE)/unsigned_handler.c\
	  $(HANDLE)/perc_handler.c\
	  $(HANDLE)/wchar_handler.c\
	  $(HANDLE)/wstring_handler.c\
	  $(HANDLE)/string_handler.c\
	  $(HANDLE)/pointer_handler.c\
	  $(HANDLE)/binary_handler.c\
	  $(HANDLE)/nonprint_handler.c\
	  $(HANDLE)/e_handler.c\
	  $(HANDLE)/f_handler.c\
	  $(HANDLE)/g_handler.c\
	  $(HANDLE)/a_handler.c\
	  $(HANDLE)/date_handler.c\
	  $(HANDLE)/time_handler.c\
	  $(HANDLE)/mass_handler.c\
	  $(HANDLE)/failconv_handler.c\


LIBSRC =$(LIB)/ft_isdigit.c \
		$(LIB)/ft_toupper.c \
		$(LIB)/ft_touppers.c \
		$(LIB)/ft_tolower.c \
		$(LIB)/ft_tolowers.c \
		$(LIB)/ft_strdup.c \
		$(LIB)/ft_strndup.c \
		$(LIB)/ft_strchr.c \
		$(LIB)/ft_atoi_base.c \
		$(LIB)/ft_strlen.c \
		$(LIB)/ft_putchar.c \
		$(LIB)/ft_putchar_fd.c \
		$(LIB)/ft_putstr.c \
		$(LIB)/ft_strdel.c \
		$(LIB)/ft_strdel2.c \
		$(LIB)/ft_memset.c \
		$(LIB)/ft_strcmp.c \
		$(LIB)/ft_strncpy.c \
		$(LIB)/ft_strjoin.c \
		$(LIB)/ft_itoa.c \
		$(LIB)/ft_itoa_base.c \
		$(LIB)/ft_lltoa.c \
		$(LIB)/ft_lltoa_base.c \
		$(LIB)/ft_ulltoa.c \
		$(LIB)/ft_ulltoa_base.c \
		$(LIB)/ft_cswap.c \
		$(LIB)/ft_max.c \
		$(LIB)/ft_min.c \
		$(LIB)/ft_unictoa.c \
		$(LIB)/ft_detoa.c \
		$(LIB)/ft_detoa_base.c \
		$(LIB)/ft_dtoa.c \
		$(LIB)/ft_round.c \
		$(LIB)/ft_pow.c \
		$(LIB)/ft_abs.c \
		$(LIB)/ft_countexp.c \
		$(LIB)/ft_countmant.c \

OBJ = $(SRC:.c=.o)

LIBOBJ = $(LIBSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBOBJ)
	ar rc $(NAME) $(OBJ) $(LIBOBJ)
	ranlib $(NAME)

clean: 
	rm -rf $(OBJ) $(LIBOBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

%.o: %.c
	gcc $(FLAGS) -I $(INCLUDES) -c -o $@ $<

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re
