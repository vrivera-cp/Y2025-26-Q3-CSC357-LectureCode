#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 16

// read a line from stdin
char *get_single_line() {
    char *buffer = NULL;
    size_t n = 0;
    getline(&buffer, &n, stdin);
    return buffer;
}

// read from pipe and write to stdout
void read_pipe(int read_fd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes; 
    while((bytes = read(read_fd, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, sizeof(char) * bytes, 1, stdout);
    }
}

int main(void) {

    int p_to_c[2];
    int c_to_p[2];
    pipe(p_to_c);
    pipe(c_to_p);

    if (fork()) {
        // parent
        close(p_to_c[0]);
        close(c_to_p[1]);

        char *line = get_single_line();

        write(p_to_c[1], line, sizeof(char) * strlen(line));
        close(p_to_c[1]);

        read_pipe(c_to_p[0]);
        close(p_to_c[0]);

        free(line);
    } else {
        // child
        close(p_to_c[1]);
        close(c_to_p[0]);
        
        read_pipe(p_to_c[0]);
        close(p_to_c[0]);

        char *line = get_single_line();

        write(c_to_p[1], line, sizeof(char) * strlen(line));
        close(c_to_p[1]);

        free(line);
    }

    return 0;
}