#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
#include <sys/syscall.h>





void *function(void *arg)
{
	printf("start\n");
	sleep(1);
	printf("end\n");
	return 0;
}


a_macro_who_does_the_main ()
{
	pthread_t t[max];
	int i = 0;
	for(i = 0; i < max; i++)
		pthread_create(&t[i], NULL, &function, NULL);
	for(i = 0; i < max; i++)
		pthread_join(t[i], NULL);
	int y = 2;
	wait(&y);
	return 0;
}