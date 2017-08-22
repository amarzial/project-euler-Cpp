EXECUTABLE=euler
CC=g++
MAIN=start.cpp
OTHER_SRC=utils.cpp
SRCDIR=src/
OBJDIR=obj/
PROBDIR=prob/
INCDIR=include/
SOURCES=$(addprefix $(SRCDIR),$(MAIN) $(OTHER_SRC))
OBJECTS=$(addprefix $(OBJDIR),$(MAIN:.cpp=.o) $(OTHER_SRC:.cpp=.o))
PROBLEMS_SRC=$(wildcard $(PROBDIR)/*.cpp)
PROBLEMS_OBJ=$(addprefix $(OBJDIR),$(notdir $(PROBLEMS_SRC:.cpp=.o)))
TEMPLATE=$(SRCDIR)template.cpp
UPDATER_SCRIPT=updater.py
CFLAGS=--std=c++11 -Wall
BFLAGS=--std=c++11
OFLAGS=-g

.PHONY: all

all: $(OBJDIR) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(PROBLEMS_OBJ)
	$(CC) $(OFLAGS) -o $(EXECUTABLE) $(OBJECTS) $(PROBLEMS_OBJ)

obj/%.o: $(SRCDIR)%.cpp
	$(CC) -c $(CFLAGS) $< $(OFLAGS) -o $@ -I$(INCDIR)

obj/%.o: $(PROBDIR)%.cpp
	$(CC) -c $(CFLAGS) $< $(OFLAGS) -o $@ -I$(INCDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(addprefix $(SRCDIR),$(MAIN)): $(PROBLEMS_SRC) $(TEMPLATE)
	python $(UPDATER_SCRIPT) $(TEMPLATE)

clean:
	rm -rf $(OBJECTS) $(PROBLEMS_OBJ)

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all
