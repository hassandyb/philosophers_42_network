#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
#include <sys/syscall.h>


int main ()
{
	struct timeval t;

	gettimeofday(&t, NULL);
	printf("tv_sec = %ld\ntv_usec = %d\n", t.tv_sec, t.tv_usec);
}
