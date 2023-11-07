#include<stdio.h>

#include<fcntl.h>

#include<string.h>

#include<unistd.h>

#include<sys/stat.h>

#include<sys/types.h>



int main(){

	int fd1,fd2; 

	char *myfifo1="file1",str1[100],str2[100]; //str1 and str2 are used for reading and writing the data

	char *myfifo2="file2";

	//create FIFO pipes(Files)

	fd1=mkfifo(myfifo1,0666);

	fd2=mkfifo(myfifo2,0666);

	//read=0222,write=0444

	

	//read data to write on first fifo pipe

	printf("\n enter string:");

	fgets(str1,100,stdin); //stdin is the source from where it will read the data

	

	//write data on first fifo pipe

	fd1=open(myfifo1,O_WRONLY); //mode for writing - O_WRONLY 

	write(fd1,str1,strlen(str1)+1); //address of the pipe,soure of the data, size of the data

	close(fd1);

	

	//read data from second pipe

	{

	fd2=open(myfifo2,O_RDONLY);

	read(fd2,str2,100);

	}

	//print output

	printf("\n Message from fifo2 process:\n%s",str2);

	close(fd2);

	

	

}

	