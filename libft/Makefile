CFLAGS = -Wall -Wextra -Werror

NAME = ../libft.a

PRINTFNAME = ft_printf/libftprintf.a

SOURCE = ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_touppers.c \
		ft_tolower.c \
		ft_tolowers.c \
		ft_isalpha.c \
		ft_strdup.c \
		ft_strndup.c \
		ft_atoi.c \
		ft_atoi_base.c \
		ft_strlen.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_bzero.c \
		ft_memccpy.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_strlcat.c \
		ft_memalloc.c \
		ft_strnew.c \
		ft_memdel.c \
		ft_strclr.c \
		ft_strdel.c \
		ft_strdel2.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strrev.c \
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_utoa.c \
		ft_utoa_base.c \
		ft_lltoa.c \
		ft_lltoa_base.c \
		ft_ulltoa.c \
		ft_ulltoa_base.c \
		ft_strsplit.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstaddtail.c \
		ft_abs.c \
		ft_fabs.c \
		ft_swap.c \
		ft_cswap.c \
		ft_arrintsort.c \
		ft_pow.c \
		ft_max.c \
		ft_min.c \
		ft_unictoa.c \
		ft_countexp.c \
		ft_countmant.c \
		ft_dtoa.c \
		ft_round.c \
		ft_detoa.c \
		ft_detoa_base.c \
		ft_strdel3.c \
		get_next_line.c \
		ft_get_number.c \

PRINTF = ft_printf
HANDLE = $(PRINTF)/handlers
PRINTFSRC = $(PRINTF)/ft_printf.c\
	  $(PRINTF)/parser.c\
	  $(PRINTF)/helper.c\
	  $(PRINTF)/helper2.c\
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

OBJECTS = $(SOURCE:.c=.o)
PRINTFOBJ = $(PRINTFSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(PRINTFOBJ)
	ar rc $(NAME) $(OBJECTS) $(PRINTFOBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)
	rm -f $(PRINTFOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re
