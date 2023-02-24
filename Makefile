# E89 Pedagogical & Technical Lab
# project:     2022_laser
# created on:  2022-11-22 - 11:19 +0100
# 1st author:  dylan.le - dylan.le
# description: Makefile

NAME	=	event

SRCS	=	src/main.c		\
		src/put_pixel.c		\
		src/clear_pixelarray.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror -Iinclude

LDFLAGS	+=       -llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm

RM	=	rm -vf

CC	:=	gcc

ifdef RELEASE
CFLAGS += -O2
endif

ifdef DEBUG
CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

# Theses rules do not directly map to a specific file
.PHONY: all clean fclean re
