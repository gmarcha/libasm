NAME		:= libasm.a
NAME_TEST	:= libasm.out

CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror

AS			:= nasm
ASFLAGS		:= -f elf64

AR			:= ar
ARFLAGS		:= -rcs

SRCS_FILES	:= ft_strlen.s
TESTS_FILES	:= ft_strlen.c main.c

SRCS_DIR	:= srcs/
TESTS_DIR	:= tests/
OBJS_DIR	:= objs/

SRCS		:=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))
TESTS		:=	$(addprefix $(TESTS_DIR), $(TESTS_FILES))
SRCS_OBJS	:=	$(addprefix $(OBJS_DIR)$(SRCS_DIR), $(SRCS_FILES:.s=.o))
TESTS_OBJS	:=	$(addprefix $(OBJS_DIR)$(TESTS_DIR), $(TESTS_FILES:.c=.o))

all:						$(NAME)

test:						$(NAME_TEST)

run:						test
							./$(NAME_TEST)

$(NAME):					$(SRCS_OBJS)
							$(AR) $(ARFLAGS) $@ $^

$(NAME_TEST):				$(TESTS_OBJS) $(NAME)
							$(CC) $(CFLAGS) -o $(NAME_TEST) $^

$(OBJS_DIR)$(SRCS_DIR)%.o:	$(SRCS_DIR)%.s
							@ mkdir -p $(dir $@)
							$(AS) $(ASFLAGS) -o $@ $<

$(OBJS_DIR)$(TESTS_DIR)%.o:	$(TESTS_DIR)%.c
							@ mkdir -p $(dir $@)
							$(CC) $(CFLAGS) -o $@ -c $<

clean:
							rm -rf $(OBJS_DIR)

fclean:						clean
							rm -rf $(NAME)

re:							fclean all

.PHONY:						all test clean fclean re
