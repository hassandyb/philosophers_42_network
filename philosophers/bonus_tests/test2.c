


#include <stdio.h>
#include <unistd.h>

// int main ()
// {
// 	int r1;

// 	printf("one process running - its pid = %d\n", getpid());
// 	r1 = fork();
// 	if(r1 > 0)
// 	{
// 		printf("\ntow process ar now running!\n\n");
// 		printf("parent process is now running - its pid = %d, it child process pid = %d\n", getpid(), r1);
// 	}
// 	if(r1 == 0)
// 	{
		
// 		printf("child process is running - its pid = %d\n", getpid());
// 	}


// }






//------------------------------------------


int main ()
{
	int r1, r2, p1, p2;


	printf("one process running - its pid = %d\n", getpid());
	r1 = fork();
	if(r1 > 0)
	{
		printf("\ntow process ar now running!\n\n");
		printf("parent process is now running - its pid = %d, it child process pid = %d\n", p1 = getpid(), r1);
	}
	if(r1 == 0)
	{
		
		printf("the first child process is running - its pid = %d\n", getpid());
	}
	printf("-----------------------\n");
	r2 = fork();
	if(r2 > 0)
		printf("the second child process is running - its pid = %d\n", getpid());
	if(r2 == 0)
		printf("the third child process is now running - it s pid = %d\n", r2);
}








// i created this code 

// int main ()
// {
// 	int r1, r2, p1, p2;


// 	printf("one process running - its pid = %d\n", getpid());
// 	r1 = fork();
// 	if(r1 > 0)
// 	{
// 		printf("\ntow process ar now running!\n\n");
// 		printf("parent process is now running - its pid = %d, it child process pid = %d\n", p1 = getpid(), r1);
// 	}
// 	if(r1 == 0)
// 	{
		
// 		printf("the first child process is running - its pid = %d\n", getpid());
// 	}
// 	printf("-----------------------\n");
// 	r2 = fork();
// 	if(r2 > 0)
// 		printf("the second child process is running - its pid = %d\n", getpid());
// 	if(r2 == 0)
// 		printf("the third child process is now running - it s pid = %d\n", r2);
// }


// i get this 


// one process running - its pid = 82448

// tow process ar now running!

// parent process is now running - its pid = 82448, it child process pid = 82449
// -----------------------
// the second child process is running - its pid = 82448
// the first child process is running - its pid = 82449
// -----------------------
// the third child process is now running - it s pid = 0
// the second child process is running - its pid = 82449                                                                                                          
// the third child process is now running - it s pid = 0


// i think that wrong , cuase since we are in the second fork i think we need a way to specify when we are in the the second and the third process , so what can we add for this      :    if(r2 > 0), if(r2 == 0)    to specify when we are in the third and the second process







