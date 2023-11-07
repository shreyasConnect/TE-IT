#include<stdio.h>

#include<stdlib.h>

#include<pthread.h>

#include<semaphore.h>



sem_t empty,full;

pthread_mutex_t mutex;

int buffer[5];

int count =0;



void* producer(void *arg){

	long int num = (long int)arg;

	//producer is trying to consume the data

	sem_wait(&empty);

	//producer is allowed to produce data and waiting for his turn

	pthread_mutex_lock(&mutex);

	//producer is producing a data

		buffer[count]=rand()%10;

		printf("\n Producer %ld produced %d item", num+1,buffer[count]);

		count++;

		sleep(1);

	pthread_mutex_unlock(&mutex);//producer have released mutex lock

	sem_post(&full);

	pthread_exit(NULL);

}



void* consumer(void *arg){

	long int num =(long int)arg;

	//consumer is trying to consume data

	sem_wait(&full);

	//consumer is allowed to consume data and waiting for his turn

	pthread_mutex_lock(&mutex);

	//consumer is consuming the data

	count--;

	printf("\n Consumer %ld consumed %d item", num+1,buffer[count]);

	sleep(1);

	pthread_mutex_unlock(&mutex);//consumer have released mutex lock

	sem_post(&empty);

	pthread_exit(NULL);

}



int main(){

	int np,nc; //number of producers and consumers

	pthread_t p[10],c[10];//thread variables

	

	unsigned long int i,j,k,l;

	//read number of producers and consumers

	printf("\n Enter the number of producers and consumers: ");

	scanf("%d %d", &np,&nc);

	//initialise semaphore variables

	sem_init(&empty,0,5); //1-variable name 2-0 means not shared 3-initial value

	sem_init(&full,0,0);

	//declaration of mutex

	pthread_mutex_init(&mutex,NULL);

	for( i=0;i<np;i++)

		pthread_create(&p[i],NULL,producer,(void*)i);

	for( j=0;j<nc;j++)

		pthread_create(&c[j],NULL,consumer,(void*)j);

	for(k=0;k<np;k++)

		pthread_join(p[k],NULL);

	for(l=0;l<nc;l++)

		pthread_join(c[l],NULL);

}

	
