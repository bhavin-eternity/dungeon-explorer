CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 
TARGET = dungeon-explorer
SRC= src/main.c

$(TARGET):	$(SRC)
	$(CC)	$(CFLAGS)	$(SRC)	-o	$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean