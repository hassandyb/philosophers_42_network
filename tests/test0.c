#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <time.h>

//what is a pthread ??

#define a 2

void *function(void *arg)
{
	return NULL;
}

int main ()
{
	pthread_t t[2];
	for(int i = 0; i < a; i++)
	{
		pthread_create(&t[i], NULL, &function, NULL);
		printf("%lu\n", (unsigned long)t[i]);// you will have to type cast it cause you will get an error
	}
	for(int i = 0; i < a; i++)
	{
		pthread_join(t[i], NULL);
	}
}

//-----------


// #define a 2

// void *function(void *arg)
// {
// 	// pthread_t t;
// 	pthread_t t = pthread_self();// pthread_self stckes the value the curent thread
// 	printf("%lu\n", (unsigned long)t);
// 	return NULL;
// }

// int main ()
// {
// 	pthread_t t[2];
// 	for(int i = 0; i < a; i++)
// 	{
// 		pthread_create(&t[i], NULL, &function, NULL);
// 		printf("%lu\n", (unsigned long)t[i]);// you will have to type cast it cause you will get an error
// 	}
// 	for(int i = 0; i < a; i++)
// 	{
// 		pthread_join(t[i], NULL);
// 	}
// }

