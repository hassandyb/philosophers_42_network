#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>



//multiple threads.... -----------


long counter = 0;
pthread_mutex_t mutex;
void *function(void *arg)
{
	for(int i = 0; i < 1000; i++)//change the value to see the race condition
	{
		pthread_mutex_lock(&mutex);//wait unti; the lock is 0
		counter++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int main (int argc, char **argv)
{
	pthread_t t[4];

	pthread_mutex_init(&mutex, NULL);
	for(int i = 0; i < 4; i++)
	{
		pthread_create(&t[i], NULL, &function, NULL);// or t + i => like incrementing a pointer
	}
	for(int i = 0; i < 4; i++)
	{
		// printf("here ------\n");
		pthread_join(t[i], NULL);
	}

	pthread_mutex_destroy(&mutex);// not neccesserly
	printf("%ld", counter);
	return 0;
}

//multiple threads....| threads are not staring in paralel -----------


long counter = 0;
pthread_mutex_t mutex;
void *function(void *arg)
{
	for(int i = 0; i < 1000; i++)//change the value to see the race condition
	{
		pthread_mutex_lock(&mutex);//wait unti; the lock is 0
		counter++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int main (int argc, char **argv)
{
	pthread_t t[4];

	pthread_mutex_init(&mutex, NULL);
	for(int i = 0; i < 4; i++)
	{
		pthread_create(&t[i], NULL, &function, NULL);// or t + i => like incrementing a pointer
		printf("Thread %d has started\n", i);
		pthread_join(t[i], NULL);
		printf("Thread %d has finished\n", i);
	}


	pthread_mutex_destroy(&mutex);// not neccesserly
	printf("%ld", counter);
	return 0;
}
// soultion add and other for and put the join and message on it 

long counter = 0;
pthread_mutex_t mutex;
void *function(void *arg)
{
	for(int i = 0; i < 1000; i++)//change the value to see the race condition
	{
		pthread_mutex_lock(&mutex);//wait unti; the lock is 0
		counter++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int main (int argc, char **argv)
{
	pthread_t t[4];

	pthread_mutex_init(&mutex, NULL);
	for(int i = 0; i < 4; i++)
	{
		pthread_create(&t[i], NULL, &function, NULL);// or t + i => like incrementing a pointer
		printf("Thread %d has started\n", i);
	}
	for(int i = 0; i < 4; i++)
	{
		pthread_join(t[i], NULL);
		printf("Thread %d has finished\n", i);
	}
	// pthread_mutex_destroy(&mutex);// not neccesserly
	printf("%ld", counter);
	return 0;
}

