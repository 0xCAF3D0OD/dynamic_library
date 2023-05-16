NAME=	hello
CC=		gcc
CFLAG=	$(shell echo $$CFLAG)
LDFLAG=	-shared
SRCS=	hello.c

G=		\033[32m
R=		\033[0m

NEWLINE =

all: $(NAME)

$(NAME): $(SRCS)
#	display compiling message.
	@printf  "$(G)compiling.$(R)"
	@sleep 1
#	create a new repesitory obj/
	@mkdir "obj" > /dev/null
#	compiling files, -fPIC: allows code to run independently of the actual load address, making it easy to create
#	shared libraries that can be loaded at different addresses in memory.
	@$(CC) $$CFLAG -fPIC -c $(SRCS) -o obj/$(SRCS:.c=.o) > /dev/null
	@sleep 1
	@printf "$(G)\rcompiling..$(R)"
#	compiling the object with the flag -shared: This flag tells the compiler to generate an output file that can be
#	used to create a shared library. The result of the compilation is a binary file that can be dynamically
#	loaded into memory by several programs at the same time.
	@$(CC) $(LDFLAG) obj/$(SRCS:.c=.o) -o $(NAME).so > /dev/null
	@sleep 1
	@printf "$(G)\rcompiling...$(R)"
#	Create the new binary exec
	@$(CC) obj/$(SRCS:.c=.o) $(NAME).so -o $(NAME) > /dev/null
	@sleep 1
	@printf "$(G)\rDone : $(NAME)!$(R)\n\n"

clean:
	@rm -rf obj/*.o obj/ > /dev/null

fclean: clean
	@rm -rf $(NAME) > /dev/null

re: fclean all

.PHONY: clean fclean re

