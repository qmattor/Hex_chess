CC := g++
NAME := Hex_Chess
CFLAGS := -Wall -Wextra -Werror -pedantic -std=c++14
LINT := cpplint
LINT_FLAGS := --filter=-runtime/references,-build/c++11,-build/include_what_you_use,-build/include --root=.
DEBUG_PARAM := 
LIBFT :=
HEADERS := 
SFML :=
SRC := Hex_Chess.cpp
SOURCE := main.cpp $(SRC)
ALL_SRC := $(SOURCE) $(HEADERS)
TEST := test.cpp $(SRC)


OBJECTS := $(patsubst %.cpp,%.o,$(SOURCE))
TEST_OBJ := $(patsubst %.cpp,%.o,$(TEST))
ALL_OBJ := test.o $(patsubst %.cpp,%.o,$(SOURCE))


all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): lint $(OBJECTS)
	$(CC) $(LIBFT) $(OBJECTS) $(CFLAGS) $(SFML) -o $(NAME)

#boost testing
tests: test
test: $(TEST_OBJ)
	$(CC) $(LIBFT) $(TEST_OBJ) $(CFLAGS) -lboost_unit_test_framework -o tests

lint: $(ALL_SRC)
	$(LINT) $(LINT_FLAGS) $^

debug:
	$(CC) $(SOURCE) $(LIBFT) $(CFLAGS) $(SFML) -g -o $(NAME)
	# valgrind --leak-check=full ./$(NAME) $(DEBUG_PARAM)

clean:
	rm -f $(ALL_OBJ)

#full clean
fclean: dclean
	rm -f $(NAME)
	rm -f tests

#debug clean
dclean: clean
	rm -rf $(NAME).dSYM

re: fclean all



