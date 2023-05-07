###Philosophers

###Introduction: In this project, you will learn the basics of threading a process.
You will see how to create threads and you will discover mutexes.

Proccrss == a running program
each procees has 
--> process ID 
--> group ID
--> user ID
-->  Files
--> lockes
--> sockets

thread ??

A thread is the smallest unit that can perform work on a CPU. In other words, at least 1 thread is required to do anything.
And by default, when you run a program, it allocates one thread. We'll allocate as many threads as there are philosophers here.

thread == thread runs a small part of the process

RAM == (random access memory) when you run a program =>operating system takes a copy of the data the program to the ram - when the program finished the original data in the memory will be updated with data from the ram


deference between process and threads???

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