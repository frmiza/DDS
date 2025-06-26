CC = gcc
CFLAGS = -Iinclude

SRC = src/LinkedList.c src/teste.c src/DataStructure.c
OBJ = $(SRC:.c=.o)

DDS: $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) DDS
