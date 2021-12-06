c++ = clang++ -Wall -Wextra -Werror
vector = vector_main.cpp
NAMES = vector_test map_test stack_test
test_vector: $(vector)
	@$(c++) $(vector) -o vector
clean:
	@rm -rf $(NAMES)