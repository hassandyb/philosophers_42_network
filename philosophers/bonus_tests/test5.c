


#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t childPid = fork();

    if (childPid == 0) {
        // Child process
        printf("Child process executing.\n");
        sleep(5);
        printf("Child process exiting.\n");
        return 0;
    } else {
        // Parent process
        printf("Parent process waiting for child.\n");
        int status;
		// pid_t terminatedChildPid = 0;
        pid_t terminatedChildPid = waitpid(childPid, &status, 0);

        printf("Parent process: Child process with PID %d has exited with status %d.\n", terminatedChildPid, status);
    }

    return 0;
}


