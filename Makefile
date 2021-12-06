c++ = clang++ -Wall -Wextra -Werror
vector = vector_main.cpp -o vector
NAMES = vector map stack
test_vector:
	@$(c++) $(vector)
clean:
	@rm -rf $(NAMES)