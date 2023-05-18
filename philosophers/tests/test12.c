#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
#include <sys/syscall.h>


//epoch time


// Epoch time, also known as Unix time or POSIX time, represents the number of seconds that have elapsed since 00:00:00 Coordinated Universal Time (UTC) on January 1, 1970 (not accounting for leap seconds). It is widely used in computer systems, operating systems, and programming languages as a standard way to measure time.

// The concept of epoch time was introduced in the Unix operating system and has since been adopted by various other systems. The choice of January 1, 1970, as the epoch start date was arbitrary but became a common standard across many platforms.

// Epoch time is a simple and standardized way to represent time because it is based on a continuous and increasing count of seconds. It is typically stored as a 32-bit or 64-bit signed integer value, representing the number of seconds elapsed since the epoch.

// pthread_mutex_lock

// When a thread calls pthread_mutex_lock and the lock is already held by another thread, the calling thread will be suspended or blocked until it can obtain the lock.

// In other words, if a thread tries to acquire a mutex lock using pthread_mutex_lock and the lock is currently held by another thread, the calling thread will be put to sleep or suspended by the operating system until the lock becomes available. The thread will remain in a blocked state and will not continue its execution until it successfully acquires the lock.

// Once the lock is released by the thread that currently holds it, one of the blocked threads will be awakened and allowed to proceed. The awakened thread will then acquire the lock and continue its execution.

// This behavior ensures that only one thread at a time can hold the lock and access the critical section or shared resource protected by the lock. Other threads that attempt to acquire the lock while it is held will be suspended until the lock becomes available.

// It's important to note that the order in which the blocked threads are awakened and granted the lock is generally not deterministic and can depend on factors such as the scheduling policy of the operating system. Therefore, it's crucial to use mutex locks correctly and design your program to handle synchronization and resource sharing appropriately.



// _STRUCT_TIMEVAL
// {
// 	__darwin_time_t         tv_sec;         /* seconds */
// 	__darwin_suseconds_t    tv_usec;        /* and microseconds */
// };


//using the gettimeofday function  -  

// 1 with a prointer

// int main ()
// {
// 	struct timeval *t;

// 	t = malloc(sizeof(struct timeval));
// 	gettimeofday(t, NULL);

// 	printf("tv_sec = %ld\ntv_usec = %d\n", t->tv_sec, t->tv_usec);

// }

// 2 with local struct

int main ()
{
	struct timeval t;
	int a, b;
	gettimeofday(&t, NULL);
	a = t.tv_sec;
	// printf("tv_sec = %ld\n", t.tv_sec);
	sleep(30);
	b = t.tv_sec;
	gettimeofday(&t, NULL);
	// printf("tv_sec = %ld\n", t.tv_sec);
	printf("%d\n", b - a);

}
