#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <num>\n", argv[0]);
        return 1;
    }

    int num = atoi(argv[1]);
    if (num < 0) {
        printf("Error: Please enter a non-negative number.\n");
        return 1;
   }

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed.\n");
        return 1;
    } else if (pid == 0) { // Child process
        printf("Child process PID: %d\n", getpid());
        printf("Fibonacci sequence: ");

        for (int i = 0; i < num; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
        exit(0);
    } else { // Parent process
        wait(NULL); // Wait for the child process to complete
        printf("Parent process PID: %d\n", getpid());
    }

    return 0;
}
