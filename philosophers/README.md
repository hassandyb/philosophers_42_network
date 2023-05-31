Philosophers

Introduction: In this project, you will learn the basics of threading a process.
You will see how to create threads and you will discover mutexes.

Proccrss == a running program
each procees has 
--> process ID 
--> group ID
--> user ID
-->  Files
--> lockes
--> sockets

==> thread ??

A thread is the smallest unit that can perform work on a CPU. In other words, at least 1 thread is required to do anything.
And by default, when you run a program, it allocates one thread. We'll allocate as many threads as there are philosophers here.

thread == thread runs a small part of the process

RAM == (random access memory) when you run a program =>operating system takes a copy of the data the program to the ram - when the program finished the original data in the memory will be updated with data from the ram


==> deference between process and threads???

processes are indepent from each other and dont share any thing
threads share the memro allocated in the heap - the code - static/global memory 
| with defrent stack == > with means deferent stack pointer, program counter, and registers

what  stack pointer, program counter, and registers are ?????
* Stack                    is a data structure that is used to keep track of function calls, local variables, and other information in a program. As functions are called, data is pushed onto the stack, and as functions return, data is popped off the stack
* The stack pointer (SP)   is a register that holds the memory address of the current top of the stack. . The stack pointer is used to keep track of the current position on the stack.
* The program counter (PC) is a register that holds the memory address of the next instruction to be executed in the program. The program counter is incremented as each instruction is executed, causing the processor to fetch and execute the next instruction in sequence.
* Registers                are small, fast memory locations within a processor that are used to hold data that is currently being operated on by the processor. Registers are typically used to hold operands, intermediate results, and other data that is needed to perform calculations and execute instructions. Registers are faster to access than memory, so using registers can help to improve the performance of a program.
summary  => The stack pointer, program counter, and registers are all closely related to the stack. As mentioned earlier, the stack is used to keep track of function calls, local variables, and other information in a program. When a function is called, the program counter is pushed onto the stack, along with any function arguments and local variables. The stack pointer is then updated to point to the new top of the stack. As the function executes, the processor uses registers to hold data that is needed to perform calculations and execute instructions. When the function returns, the stack pointer is used to pop data off the stack and restore the previous state of the program, including the previous value of the program counter.


###resources
arabic 
https://www.youtube.com/watch?v=6yk0KDWOEtE&list=TLPQMDQwNTIwMjPDwBykeLTqUQ&index=2&ab_channel=MASHAEL
https://www.youtube.com/watch?v=TFW-PMRZHY8
https://www.youtube.com/watch?v=8Sv7D4DUB_4&ab_channel=MASHAEL

english
https://www.youtube.com/watch?v=uA8X5zNOGw8&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM
https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2
https://velog.io/@hidaehyunlee/Philosophers-Dining-philosophers-problem-%EC%86%8C%EA%B0%9C
https://velog.io/@junppyo/philosopher
https://namu.wiki/w/%EC%8B%9D%EC%82%AC%ED%95%98%EB%8A%94%20%EC%B2%A0%ED%95%99%EC%9E%90%20%EB%AC%B8%EC%A0%9C


==> pthread_mutex_init

It shall be safe to destroy an initialized mutex that is unlocked. Attempting to destroy a locked mutex results in undefined behavior.


Attempting to initialize an already initialized mutex results in undefined behavior.


==> deference between pthread_join and pthread_detach

pthread_join() tells the main thread to wait for the joined thread to finish. pthread_detach() tells the system to automatically release the resources used by the detached thread when it terminates. The main thread will continue executing after calling pthread_detach(), but it will not end until the detached thread finishes.

The differences between pthread_join() and pthread_detach():

Function			Description
pthread_join()		Waits for the thread to finish and returns its exit status.
pthread_detach()	Detaches the thread and releases its resources when it terminates. The main thread 

will continue executing after calling pthread_detach().
The choice of which function to use depends on the specific requirements of the application. If the main thread needs to wait for the thread to finish, then pthread_join() should be used. If the main thread does not need to wait for the thread to finish, then pthread_detach() can be used.



Semaphore   ------------------------------------

After calling `sem_wait(sem)` and `sem_post(sem)`, the `sem` variable remains unchanged. The `sem` variable is a semaphore descriptor that is used to identify and operate on the semaphore.

The `sem_wait` function is used to decrement the value of the semaphore. If the semaphore value is greater than zero, it decrements the value and allows the calling process/thread to proceed. If the semaphore value is already zero, indicating that it is being used by another process/thread, `sem_wait` will block the calling process/thread until the semaphore becomes available.

Here's an example of how you can use `sem_wait`:

```c
sem_wait(semaphore);
// Critical section - code that should be accessed by only one philosopher at a time
sem_post(semaphore);
```

The `sem_post` function is used to increment the value of the semaphore. It "posts" (or releases) the semaphore, indicating that it is available for other processes/threads to use.

Here's an example of how you can use `sem_post`:

```c
// Perform some operations before entering the critical section

sem_post(semaphore);

// Continue with other operations

```

In the example above, `sem_wait` is called before entering the critical section to acquire the semaphore, ensuring that only one philosopher can access the critical section at a time. `sem_post` is called after the critical section to release the semaphore, allowing other philosophers to acquire it and access the critical section.

The `sem` variable serves as a handle to the semaphore and is used as an argument to both `sem_wait` and `sem_post` functions to operate on the semaphore identified by the handle.





####   waitpid  function

The `waitpid` function is used to make a parent process wait for the termination of a specific child process. It allows the parent process to retrieve information about the child process after it has exited.

Here's the syntax of the `waitpid` function:

```c
#include <sys/types.h>
#include <sys/wait.h>

pid_t waitpid(pid_t pid, int *status, int options);
```

- `pid`: The process ID of the child process you want to wait for. You can use different values:
  - `> 0`: Wait for the specific child process with the given process ID.
  - `-1`: Wait for any child process.
  - `0`: Wait for any child process in the same process group as the calling process.
  - `< -1`: Wait for any child process whose process group ID is equal to the absolute value of `pid`.
- `status`: A pointer to an integer where the exit status or termination information of the child process will be stored.
- `options`: Optional flags that control the behavior of the `waitpid` function. You can use 0 for default behavior.

The `waitpid` function can have several return values:
- `-1`: An error occurred, and the child process could not be waited for.
- `0`: When using `pid` with value 0 or a negative value, it means no child process is available to be waited for.
- `> 0`: The process ID of the terminated child process that is being waited for.

Here's a simple example demonstrating the usage of `waitpid`:

```c
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t childPid = fork();

    if (childPid == -1) {
        perror("fork");
        return 1;
    }

    if (childPid == 0) {
        // Child process
        printf("Child process executing.\n");
        sleep(3);
        printf("Child process exiting.\n");
        return 0;
    } else {
        // Parent process
        printf("Parent process waiting for child.\n");
        int status;
        pid_t terminatedChildPid = waitpid(childPid, &status, 0);
        if (terminatedChildPid == -1) {
            perror("waitpid");
            return 1;
        }
        printf("Parent process: Child process with PID %d has exited with status %d.\n", terminatedChildPid, status);
    }

    return 0;
}
```

In this example, the parent process forks a child process. The child process sleeps for 3 seconds and then exits. The parent process uses `waitpid` to wait for the termination of the child process. The exit status of the child process is stored in the `status` variable, which the parent process can then use or display as needed.

Note: The `waitpid` function is just one way to wait for child processes in Linux/UNIX systems. There are other related functions like `wait` and `waitid` that offer different features and behaviors.

##  Sem_open

The `sem_open` function in C is used to create or open a named semaphore. Named semaphores allow synchronization and communication between different processes.

Here's the syntax of the `sem_open` function:

```c
#include <semaphore.h>

sem_t *sem_open(const char *name, int oflag, mode_t mode, unsigned int value);
```

- `name`: The name of the semaphore. It should start with a forward slash ("/") followed by a unique name.
- `oflag`: The flag indicating how the semaphore should be opened. It can take one or more of the following values:
  - `O_CREAT`: Create the semaphore if it doesn't exist.
  - `O_EXCL`: When combined with `O_CREAT`, ensures that the semaphore is created exclusively (fails if it already exists).
- `mode`: The permissions of the semaphore when it is created (if `O_CREAT` is used). It follows the same format as file permissions in `chmod()`.
- `value`: The initial value of the semaphore.

The `sem_open` function returns a pointer to the semaphore descriptor (`sem_t *`) if successful, or `SEM_FAILED` on error.

Here's an example that demonstrates the usage of `sem_open`:

```c
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int main() {
    sem_t *mySemaphore;

    // Create or open the semaphore
    mySemaphore = sem_open("/my_semaphore", O_CREAT | O_EXCL, 0644, 1);
    if (mySemaphore == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    // Semaphore operations
    printf("Semaphore created/opened successfully!\n");

    // Close and unlink the semaphore when done
    sem_close(mySemaphore);
    sem_unlink("/my_semaphore");

    return 0;
}
```

In this example, the `sem_open` function is used to create or open a named semaphore named "/my_semaphore" with an initial value of 1. If the semaphore creation/opening is successful, the `sem_open` function returns a valid semaphore descriptor (`sem_t *`). You can then perform semaphore operations or synchronization using this descriptor.

After using the semaphore, it's important to close it using `sem_close` and unlink it using `sem_unlink`. Closing the semaphore releases the resources associated with it, and unlinking removes it from the system.

Note: Named semaphores created with `sem_open` should be closed and unlinked when they are no longer needed to ensure proper cleanup of system resources.








