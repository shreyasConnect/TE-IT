#include <sys/ipc.h>

#include <sys/shm.h>

#include <stdio.h>

int main()
{

    // ftok to generate unique key

    key_t key = ftok("shmfile", 65);

    // shmget returns an identifier in shmid

    int shmid = shmget(key, 1024, 0666 | IPC_CREAT); // creates shared memory of 1KB(1024) with read and write mode

    // shmat to attach to shared memory

    char *str = (char *)shmat(shmid, (void *)0, 0); // second argument is the address which OS automatically chooses.

    printf("Write data: ");

    gets(str);

    printf("Data written in memory: %s\n", str);

    // detach from shared memory

    shmdt(str);

    return 0;
}