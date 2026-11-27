#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){
    if (argc == 1) {
        fprintf(stderr, "Usage: %s <program>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int wstatus;
    
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {

        execvp(argv[1], &argv[1]);

    }

    pid_t child_pid = wait(&wstatus);

    if (child_pid == -1) {
        perror("wait");
        exit(EXIT_FAILURE); // check if wait failed 
    }

    if (WIFEXITED(wstatus)) { // check child exited normally
        int code = WEXITSTATUS(wstatus);

        if (code != 0) {
            fprintf(stderr, "Child failed with exit code %d\n", code);
        }

        exit(code); // exit with the same status that the child exited with

    } else {
        fprintf(stderr, "Child didn't exit normally\n");
        exit(EXIT_FAILURE);
    }
}