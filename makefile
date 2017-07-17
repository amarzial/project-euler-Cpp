EXECUTABLE=euler
CC=g++
TEMPLATE=template.cpp
MAIN=start.cpp
OTHER_SRC=utils.cpp
OBJECTS=$(addprefix obj/,$(MAIN:.cpp=.o) $(OTHER_SRC:.cpp=.o))
PROBLEMS_SRC=$(wildcard probs/*.cpp)
PROBLEMS_OBJ=$(addprefix obj/,$(notdir $(PROBLEMS_SRC:.cpp=.o)))
CFLAGS=--std=c++11 -Wall
BFLAGS=--std=c++11

.PHONY: all

all: obj $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(PROBLEMS_OBJ)
	$(CC) -g -o $(EXECUTABLE) $(OBJECTS) $(PROBLEMS_OBJ)

obj/%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -g -o $@ -I.

obj/%.o: probs/%.cpp
	$(CC) -c $(CFLAGS) $< -g -o $@ -I.

obj:
	mkdir -p obj

$(MAIN): $(PROBLEMS_SRC) $(TEMPLATE)
	python updater.py

clean:
	rm -rf $(OBJECTS) $(PROBLEMS_OBJ)

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all
