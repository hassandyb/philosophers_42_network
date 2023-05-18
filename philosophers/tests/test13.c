#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
#include <sys/syscall.h>




// data race condition

long long a = 0;

void *ft_count(void *arg)
{
	while(a < 10000000)
	{
		a++;
		// usleep(10);
	}
	printf("%lld\n", a);
	return 0;
}

int main ()
{
	int n = 20;
	pthread_t t[20];
	int i = -1;
	while(++i < 20)
		pthread_create(&t[i], NULL, ft_count, NULL);
	i = -1;
	while(++i < 20)
		pthread_join(t[i], NULL);


}