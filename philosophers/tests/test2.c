#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>


// an example where the program ends  
// void *myturn(void *arg)
// {
// 	for(int i = 0; i < 5; i++)
// 	{
// 		sleep(2);
// 		printf("My turn\n");
// 	}
// 	return NULL;
// }

// void yourturn ()
// {
// 	for(int i = 0; i < 5; i++)
// 	{
// 		sleep(1);// i made the 1 so the process ends faster 
// 		printf("Your turn\n");
// 	}
// }
// int main ()
// {
// 	pthread_t newthread;
// 	pthread_create(&newthread, NULL, myturn, NULL);

// 	yourturn();
// }

// how can we make the progame actually still progress until the pthread_create finished

void *myturn(void *arg)
{
	for(int i = 0; i < 5; i++)
	{
		sleep(2);
		printf("My turn\n");
	}
	return NULL;
}

void yourturn ()
{
	for(int i = 0; i < 5; i++)
	{
		sleep(1);// i made the 1 so the function ends faster 
		printf("Your turn\n");
	}
}
int main ()
{
	pthread_t newthread;
	// printf("%ld\n", newthread->__sig);
	pthread_create(&newthread, NULL, myturn, NULL);
	yourturn();
	pthread_join(newthread, NULL);// the progame wont stop until the function called by pthread_create finished .
}







