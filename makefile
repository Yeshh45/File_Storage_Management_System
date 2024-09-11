CC = gcc
CFLAGS = -pthread -Wall

# Compile the project
all: file_storage

file_storage: src/file_storage.c src/utils.c
	$(CC) $(CFLAGS) -o file_storage src/file_storage.c src/utils.c

# Clean the project
clean:
	rm -f file_storage
