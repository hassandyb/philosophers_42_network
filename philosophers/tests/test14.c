#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
#include <sys/syscall.h>

pthread_mutex_t a;

void *ft_routine(void *arg)
{
	if()
	a = 100;
}
int main()
{

	pthread_t *d1, *d2;
	pthread_create(d1, NUll, ft_routine, NULL);
	pthread_create(d2, NUll, ft_routine, NULL);
}