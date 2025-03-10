PROGRAM_NAME = philo
COMPILER = cc
FLAGS = -Wall -Wextra -Werror -pthread
MANDATORY = main.c init.c init2.c utils.c utils2.c validate.c philo_activites.c\
			philo_activities2.c
MANDATORY_OBJS = $(MANDATORY:.c=.o)
all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(MANDATORY_OBJS)
	$(COMPILER) $(FLAGS) $(MANDATORY_OBJS) -o $(PROGRAM_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o *.out *.gch .vscode *.txt *.log

fclean: clean
	rm -rf $(PROGRAM_NAME)

re: fclean all

.PHONY: all mandatory clean fclean re
