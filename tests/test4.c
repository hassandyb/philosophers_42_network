#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>









// this time we want a value returned by the function myturn and || safty and speed issues with thraeds








// #define   BIG 1000000000UL
// unsigned long counter = 0;
// void *count_to_big(void *arg)
// {

// 	for (unsigned long i = 0; i < BIG; i++)
// 	{
// 		counter++;
// 	}

// }

// int main ()
// {
// 	pthread_t t;
// 	// pthread_create(&t, NULL, count_to_big, NULL);
// 	count_to_big(NULL);
// 	count_to_big(NULL);
// 	printf("Done. counter == %ld\n", counter);
// }

//result 
//Done. counter == 2000000000
//./a.out  3.63s user 0.00s system 99% cpu 3.633 total
//-------------------------------------------------using threads  race condion issue 

// #define   BIG 1000000000UL
// unsigned long counter = 0;
// void *count_to_big(void *arg)
// {

// 	for (unsigned long i = 0; i < BIG; i++)
// 	{
// 		counter++;
// 	}
// 	return NULL;
// }

// int main ()
// {
// 	pthread_t t;
// 	pthread_create(&t, NULL, count_to_big, NULL);
// 	count_to_big(NULL);
// 	// count_to_big(NULL);
// 	pthread_join(t, NULL);
// 	printf("Done. counter == %ld\n", counter);
// }

// result   // wrong result   and takes mooore time 11.28s ====> race condion issue 
// Done. counter == wrong value changes every time you copal again
// ./a.out  11.28s user 0.01s system 199% cpu 5.658 total
//-------------------------------------------  using the mutex locks to solve the problem


#define   BIG 1000000
unsigned long counter = 0;
// pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int y = 0;
void *count_to_big(void *arg)
{

	for (unsigned long i = 0; i < BIG; i++)
	{
		// pthread_mutex_lock(&lock);


		counter++;
		// printf("%lu  %s\n", counter, (char *)arg);
		// pthread_mutex_unlock(&lock);
	}
	return NULL;
}

int main ()
{
	pthread_t t;
	pthread_t t2;
	pthread_create(&t, NULL, count_to_big, "a");
	pthread_create(&t2, NULL, count_to_big, "b");
	// count_to_big("b");
	// count_to_big(NULL);
	pthread_join(t, NULL);
	pthread_join(t2, NULL);
	printf("Done. counter == %ld\n", counter);
}








