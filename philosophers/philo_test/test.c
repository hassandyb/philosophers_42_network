

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>


long ft_epoch_time()
{
	struct timeval tv;
	int r;
	
	r = gettimeofday(&tv, NULL);
	if(r != 0)
		return (-1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec * 0.001));
}

int main ()
{
	printf("%ld\n", ft_epoch_time());
}