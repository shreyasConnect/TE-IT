#include<stdio.h>

#include<unistd.h>



int main(int argc , char *argv[]){

printf("In child file \n");

printf("Array in reverse order\n");

for (int i = argc- 1 ; i >=0; i--){

printf("%s ", argv[i]);

}

return 0;

}
