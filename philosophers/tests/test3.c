#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>









// this time we want a value returned by the function myturn



void *myturn(void *arg)
{
	int *v = (int *)malloc (sizeof(int));
	*v = 5;
	for(int i = 0; i < 5; i++)
	{
		sleep(2);
		printf("My turn  -- arg == %d\n", (*v)++);// *v++ is wrong caus ein that cae you are increasing the adresse of the ptr not it value
	}
	return (v);
}

void yourturn ()
{
	for(int i = 0; i < 5; i++)
	{
		sleep(2);
		printf("Your turn\n");
	}
}
int main ()
{
	pthread_t newthread;
	int *result;

	pthread_create(&newthread, NULL, myturn, NULL);
	yourturn();
	pthread_join(newthread, (void *)&result);// the second parameter of pthread_join is used to get the return of the function inside pthred_create.
	printf("result = %d\n", *result);
}