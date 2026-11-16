#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]){
    if (argc == 1) {
        fprintf(stderr, "Usage: %s <program>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    pid_t pid = fork();
    if (pid == 0) {
        for (int i = 1; i<argc; i++) {
            printf("%s\n", argv[i]);
        }
    }
  
}