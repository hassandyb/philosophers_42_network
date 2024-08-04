# Philosophers Project

## Introduction

Welcome to the **Philosophers Project**! This endeavor dives into the fascinating world of **threading** and **mutexes** in programming. Inspired by the classic "Dining Philosophers" problem, this project explores how multiple processes can work concurrently and solve coordination challenges through threading.

## Project Overview

In the world of computing, a **process** is a running program with its own resources and memory. Each process operates independently and has unique identifiers like Process ID, Group ID, and User ID. When you run a program, it starts with one thread—the smallest unit of execution within a process. 

### What is a Thread?

A **thread** is a basic unit of execution that can run concurrently with other threads within the same process. By default, when you execute a program, it allocates one thread to perform the tasks. For this project, we allocate as many threads as there are philosophers.

Threads share the memory allocated in the heap, the code, and static/global memory but operate with separate stacks. This separation allows threads to perform tasks independently while still sharing common resources.

### Stack, Program Counter, and Registers

- **Stack**: A data structure that keeps track of function calls, local variables, and other information in a program. Functions push data onto the stack when called and pop it off when they return.
- **Stack Pointer (SP)**: A register that holds the memory address of the top of the stack, tracking the current position.
- **Program Counter (PC)**: A register holding the address of the next instruction to execute. It increments as each instruction is processed.
- **Registers**: Small, fast memory locations within a processor for holding data being operated on. Registers are crucial for performance as they are faster to access than regular memory.

### The Dining Philosophers Problem

The Dining Philosophers problem illustrates the complexities of synchronization and resource sharing among multiple threads. Each philosopher must think and eat, but they share common resources (forks) that require careful management to avoid conflicts.

## Key Concepts

### Thread Synchronization with Mutexes

In multithreading, synchronization ensures that multiple threads do not interfere with each other. **Mutexes** (short for mutual exclusions) are used to prevent simultaneous access to shared resources, avoiding conflicts and ensuring thread safety.

- **`pthread_mutex_init`**: Initializes a mutex. It is safe to destroy an unlocked mutex, but attempting to destroy a locked mutex or reinitialize an already initialized mutex results in undefined behavior.
- **`pthread_join` vs. `pthread_detach`**:
  - **`pthread_join()`**: Waits for a thread to finish and returns its exit status. Use this when you need the main thread to wait for other threads to complete.
  - **`pthread_detach()`**: Detaches a thread and automatically releases its resources upon termination. Use this when you do not need to wait for the thread to complete.

## Resources

For a deeper understanding of threading and mutexes, explore the following resources:

### Videos
- [Threading Basics (Arabic)](https://www.youtube.com/watch?v=6yk0KDWOEtE&list=TLPQMDQwNTIwMjPDwBykeLTqUQ&index=2&ab_channel=MASHAEL)
- [Advanced Threading Concepts (Arabic)](https://www.youtube.com/watch?v=TFW-PMRZHY8)
- [Philosophers Problem Overview (English)](https://www.youtube.com/watch?v=uA8X5zNOGw8&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM)
- [Detailed Explanation of Mutexes (English)](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)

### Articles
- [Philosophers Problem Explanation](https://velog.io/@hidaehyunlee/Philosophers-Dining-philosophers-problem-%EC%86%8C%EA%B0%9C)
- [Understanding Mutexes and Threads](https://namu.wiki/w/%EC%8B%9D%EC%82%AC%ED%95%98%EB%8A%94%20%EC%B2%A0%ED%95%99%EC%9E%90%20%EB%AC%B8%EC%A0%9C)

## Conclusion

The Philosophers Project is not just an exercise in threading and synchronization; it's a creative challenge that demonstrates the principles of concurrent programming. By managing threads and shared resources, you gain valuable insights into the complexities of real-world software development.
