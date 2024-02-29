CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRC = atoi.c dict_handler.c has_duplicate.c is_valid_dictionary.c main.c main_helper.c number_handler.c print.c print_dict.c sort.c trim_spaces.c utils.c
OBJ = $(SRC:.c=.o)

NAME = rush-02

all: $(NAME)

$(NAME):: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re