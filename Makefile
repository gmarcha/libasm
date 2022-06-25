NAME		:= libasm.a
NAME_TEST	:= libasm.out

CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror
CDEBUG		:= lldb

AS			:= nasm
ASFLAGS		:= -f elf64

AR			:= ar
ARFLAGS		:= -rcs

TESTS_HDR	:= tests.h

SRCS_FILES	:= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
TESTS_FILES	:= ft_strlen.c ft_strcpy.c ft_strcmp.c ft_write.c ft_read.c ft_strdup.c main.c

SRCS_DIR	:= srcs/
TESTS_DIR	:= tests/
OBJS_DIR	:= objs/

TESTS_INC	:= $(addprefix $(TESTS_DIR), $(TESTS_HDR))
SRCS		:= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
TESTS		:= $(addprefix $(TESTS_DIR), $(TESTS_FILES))
SRCS_OBJS	:= $(addprefix $(OBJS_DIR)$(SRCS_DIR), $(SRCS_FILES:.s=.o))
TESTS_OBJS	:= $(addprefix $(OBJS_DIR)$(TESTS_DIR), $(TESTS_FILES:.c=.o))

all:						$(NAME)

test:						$(NAME_TEST)

run:						test
							./$(NAME_TEST)

valgrind:					test
							valgrind ./$(NAME_TEST)

debug:						test
							$(CDEBUG) $(NAME_TEST)

$(NAME):					$(SRCS_OBJS)
							$(AR) $(ARFLAGS) $@ $^

$(NAME_TEST):				$(TESTS_OBJS) $(NAME)
							$(CC) $(CFLAGS) -o $@ $^

$(OBJS_DIR)$(SRCS_DIR)%.o:	$(SRCS_DIR)%.s
							@ mkdir -p $(dir $@)
							$(AS) $(ASFLAGS) -o $@ $<

$(OBJS_DIR)$(TESTS_DIR)%.o:	$(TESTS_DIR)%.c $(TESTS_INC)
							@ mkdir -p $(dir $@)
							$(CC) $(CFLAGS) -o $@ -c $<

clean:
							rm -rf $(OBJS_DIR)

fclean:						clean
							rm -rf $(NAME) $(NAME_TEST)

re:							fclean all

.PHONY:						all test run clean fclean re
