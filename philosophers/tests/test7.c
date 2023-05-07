#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <time.h>


//return value from a thread
void *roll_dice()
{
	int value = (rand() % 6) + 1;
	printf("%d\n", value);
	int *result = malloc (sizeof(int));
	*result = value;
	return (void *) result;
}


int main(int argc, char **argv)
{
	int *result;
	pthread_t t;
	pthread_create(&t, NULL, &roll_dice, NULL);
	pthread_join(t, (void *)&result);

	printf("%d\n", *result);
}

