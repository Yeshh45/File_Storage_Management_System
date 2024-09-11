#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "utils.h"

#define MAX_FILE_NAME 100

// Structure to represent a file
typedef struct {
    char fileName[MAX_FILE_NAME];
    char* content;
} File;

// Initialize storage for files
File* files[MAX_FILES];
int file_count = 0;

// Mutex for thread safety
pthread_mutex_t file_mutex = PTHREAD_MUTEX_INITIALIZER;

// Create a file
void create_file(const char* file_name, const char* content) {
    pthread_mutex_lock(&file_mutex);

    // Create new file and allocate memory for content
    File* new_file = (File*) malloc(sizeof(File));
    strcpy(new_file->fileName, file_name);
    new_file->content = (char*) malloc(strlen(content) + 1);
    strcpy(new_file->content, content);

    files[file_count++] = new_file;

    pthread_mutex_unlock(&file_mutex);
    printf("File %s created successfully!\n", file_name);
}

// Retrieve file content
void read_file(const char* file_name) {
    pthread_mutex_lock(&file_mutex);

    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i]->fileName, file_name) == 0) {
            printf("File content: %s\n", files[i]->content);
            pthread_mutex_unlock(&file_mutex);
            return;
        }
    }
    pthread_mutex_unlock(&file_mutex);
    printf("File %s not found!\n", file_name);
}

// Delete a file
void delete_file(const char* file_name) {
    pthread_mutex_lock(&file_mutex);

    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i]->fileName, file_name) == 0) {
            free(files[i]->content);
            free(files[i]);

            for (int j = i; j < file_count - 1; j++) {
                files[j] = files[j + 1];
            }
            file_count--;
            printf("File %s deleted successfully!\n", file_name);
            pthread_mutex_unlock(&file_mutex);
            return;
        }
    }
    pthread_mutex_unlock(&file_mutex);
    printf("File %s not found!\n", file_name);
}

int main() {
    // Sample usage
    create_file("Yeshwanth.txt", "This is my file.");
    read_file("Yeshwanth.txt");
    delete_file("Yeshwanth.txt");

    return 0;
}
