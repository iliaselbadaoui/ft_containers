c++ = clang++ -Wall -Wextra -Werror
vector = vector_main.cpp
NAMES = vector map stack
test_vector: $(vector)
	@$(c++) $(vector) -o vector
clean:
	@rm -rf $(NAMES)