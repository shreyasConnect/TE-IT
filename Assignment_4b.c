#include <stdio.h>

#include <pthread.h>

pthread_mutex_t wrt, mutex;

int a=10, readcount=0;


void * writer(void *args)
{
    long int num;

    num=(long int )args;

    pthread_mutex_lock(&wrt);

    printf("\nwriter %ld is in the cs",num);


    printf("\nwriter %ld is writing %d", num, ++a);

    sleep(1);

    pthread_mutex_unlock(&wrt);

    printf("\nreader %ld left cs",num);

}

void * reader(void *args)
{
    long int num =(long int) args;

    pthread_mutex_lock(&mutex);
    readcount++;

    pthread_mutex_unlock(&mutex);

    if(readcount==1)
    {
        pthread_mutex_lock(&wrt);
    }

    printf("\nreader is in critical section");

    printf("\nreader %ld is reading %d",num , --a);
    sleep(1);
    pthread_mutex_lock(&mutex);

    readcount--;

    pthread_mutex_unlock(&mutex);

    if(readcount==0)
    {
        pthread_mutex_unlock(&wrt);
    }

   
    printf("\nreader %ld left the cs", num);


}

int main()
{
    pthread_t r[10], w[10];

    int nor , now;
   
    unsigned long int i, j,k,l;

    pthread_mutex_init(&mutex, NULL);

    pthread_mutex_init(&wrt,NULL);

    printf("enter no of reader and writer");
    scanf("%d %d",&nor, &now);

    for(i=0; i<nor; i++)
    {
        pthread_create(&r[i],NULL, reader,(void *)i);
    }

     for(j=0; j<now; j++)
    {
        pthread_create(&w[j],NULL, writer,(void *)j);
    }

     for( k=0; k<nor; k++)
    {
        pthread_join(r[k],NULL);
    }
    for(int l=0; l<now; l++)
    {
        pthread_join(w[l],NULL);
    }

    return 0;

}
