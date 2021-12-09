c++ = clang++ -Wall -Wextra -Werror
vector = vector_main.cpp
NAMES = vector_test map_test stack_test

NAME = vector_test
all: $(NAME)

$(NAME): $(vector)
	@$(c++) $(vector) -o $(NAME)
clean:
	@rm -rf $(NAMES)
re: clean all

.PHONY: all re clean