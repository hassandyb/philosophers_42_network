

#include <stdio.h>
#include <semaphore.h>

// int main() 
// {
//     sem_t *mySemaphore = sem_open("/my_semaphore", O_CREAT, 0644, 1);

//     if (mySemaphore == SEM_FAILED) {
//         perror("sem_open");
//         return 1;
//     }


//     printf("-- %d  --\n", *mySemaphore);
//     // Perform some critical section operations
//     sem_wait(mySemaphore);
//     printf("-- %d  --\n", *mySemaphore);

//     // ... Do something ...
//     sem_post(mySemaphore);
//     printf("-- %d  --\n", *mySemaphore);


//     // Close and unlink the semaphore
//     sem_close(mySemaphore);
//     sem_unlink("/my_semaphore");

//     return 0;
// }
#include <stdio.h>
#include <semaphore.h>

int main() 
{
    sem_t *mySemaphore = sem_open("/my_semaphore", O_CREAT, 0644, 1);

    if (mySemaphore == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }

    int semValue;
    sem_getvalue(mySemaphore, &semValue);
    printf("Semaphore value: %d\n", semValue);

    // Perform some critical section operations
    sem_wait(mySemaphore);

    sem_getvalue(mySemaphore, &semValue);
    printf("Semaphore value: %d\n", semValue);

    // ... Do something ...
    sem_post(mySemaphore);

    sem_getvalue(mySemaphore, &semValue);
    printf("Semaphore value: %d\n", semValue);

    // Close and unlink the semaphore
    sem_close(mySemaphore);
    sem_unlink("/my_semaphore");

    return 0;
}



