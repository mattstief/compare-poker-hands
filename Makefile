SRCS=main.cpp judge.cpp hand.cpp card.cpp
SRCDIR=src
CC=g++
DIR=build
CFLAGS=-g -w -Wall -o poker.exe
OBJS=$(addprefix $(DIR)/,$(SRCS:.cpp=.o))
EXE=$(DIR)/poker.exe

.PHONY: all clean

all: $(EXE)

$(DIR):
	mkdir -p $@

$(DIR)/%.o: $(SRCDIR)/%.cpp | $(DIR)
	$(CC) -c -o $@ $<

$(EXE) : $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -fr $(DIR) output