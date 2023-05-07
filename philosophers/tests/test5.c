#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>


// long counter = 0;

// void *function(void *arg)
// {
// 	for(int i = 0; i < 10000; i++)//change the value to see the race condition
// 	{
// 		counter++;
// 	}
// 	return (NULL);
// }

// int main (int argc, char **argv)
// {
// 	pthread_t t1, t2;

// 	pthread_create(&t1, NULL, &function, NULL);
// 	pthread_create(&t1, NULL, &function, NULL);
// 	pthread_join(t1, (void **)counter);
// 	pthread_join(t2, (void **)counter);
// 	printf("%ld", counter);
// 	return 0;
// }


//the incrementation of the counter s value its cpu regestrar or in the memory... 
//example 
//in the first thread there is counter == 10 after few ineration in thread a counter == 20 the thing is for thread2
// in it s cpu regestrar the value of counter is 10 so it incremnet too this causes a wrong result.


//mutex condition -----------


long counter = 0;
pthread_mutex_t mutex;
void *function(void *arg)
{
	for(int i = 0; i < 100000; i++)//change the value to see the race condition
	{
		pthread_mutex_lock(&mutex);//wait unti; the lock is 0
		counter++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int main (int argc, char **argv)
{
	pthread_t t1, t2;
	pthread_mutex_init(&mutex, NULL);

	pthread_create(&t1, NULL, &function, NULL);
	pthread_create(&t1, NULL, &function, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	// pthread_mutex_destroy(&mutex);// not neccesserly
	printf("%ld", counter);
	return 0;
}


// mutual exclusion object
// In computer programming, a mutex (mutual exclusion object) 
// is a program object that is created so that multiple program thread 
// can take turns sharing the same resource, such as access to a file.



