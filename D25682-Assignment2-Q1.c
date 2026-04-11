#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    char buffer[100];

    // Parent writes to file
    fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    printf("Enter text: ");
    fgets(buffer, sizeof(buffer), stdin);

    write(fd, buffer, strlen(buffer));
    close(fd);

    // Create child process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        int fd2;
        char data[100];

        fd2 = open("data.txt", O_RDONLY);
        read(fd2, data, sizeof(data));

        printf("\nChild read: %s\n", data);

        close(fd2);
    } else {
        // Parent process
        wait(NULL);
        printf("\nParent finished\n");
    }

    return 0;
}