PROGRAM_NAME = philo
COMPILER = cc
FLAGS = -Wall -Wextra -Werror -g
DEBUG_FLAGS = -fsanitize=address,undefined -Werror=address -Wnull-dereference -g
MANDATORY = main.c init.c init2.c utils.c utils2.c validate.c philo_activites.c
MANDATORY_OBJS = $(MANDATORY:.c=.o)
all: mandatory

mandatory: $(MANDATORY_OBJS)
	$(COMPILER) $(FLAGS) $(MANDATORY_OBJS) -o $(PROGRAM_NAME)

debug: re $(MANDATORY_OBJS)
	$(COMPILER) $(FLAGS) $(DEBUG_FLAGS) $(MANDATORY_OBJS) $(LIBFT_A) $(READLINE_FLAG) -o $(PROGRAM_NAME)
clean:
	rm -rf *.o *.out *.gch .vscode *.txt *.log

fclean: clean
	rm -rf $(PROGRAM_NAME)

re: fclean all

.PHONY: all mandatory clean fclean
