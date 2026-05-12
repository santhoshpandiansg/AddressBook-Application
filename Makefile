CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c11

TARGET = addressbook

SRC = main.c contact.c file.c populate.c

OBJ = $(SRC:.c=.o)

DEPS = contact.h file.h populate.h

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

rebuild: clean all