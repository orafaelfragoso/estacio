CC = clang
CFLAGS = -Wall -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
EXEC = supertrunfo

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
