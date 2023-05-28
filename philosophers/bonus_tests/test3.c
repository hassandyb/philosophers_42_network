


#include <stdio.h>
#include <unistd.h>

void track(int i)
{
	sleep(2);
	printf("chlid id ", i);
	exit(0);
}

int main(int argc, char const *argv[])
{
	int id  = 0;
	for (int i = 0; i < 10; i++)
	{
		id = fork();
		if (id == 0)
		{
			track(i + 1);
		}

	}
 
//	printf("hi\n");
	return 0;
}

fork 
fork 
fork


