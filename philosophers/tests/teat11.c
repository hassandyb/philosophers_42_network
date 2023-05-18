#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int slod = 0;
pthread_mutex_t lock;

void *user(void *data)
{
	int x = *(int *) data;
	printf("bfore lock\n");
pthread_mutex_lock(&lock);
printf("afther  lock\n");
sleep(5);
pthread_mutex_unlock(&lock);
	
	return (0);
}

int main()
{
	pthread_t th[7];
	int val = {2};
	pthread_mutex_init(&lock, NULL);
	for (size_t i = 0; i < 7; i++)
	{
		pthread_create(&th[0], NULL, user, &val);
		
	}
	

for (size_t i = 0; i < 7; i++)
	pthread_join(th[i], NULL);
		pthread_mutex_destroy(&lock);
printf("%d", slod);

}