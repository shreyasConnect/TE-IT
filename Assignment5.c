#include <stdio.h>

#include<stdbool.h>



int p,r;

int arr[100][100];

int current_available[10];

int resource_available[10];

int allocation_sum[10];

int answer_sequence[10];



void bankers(){

    //allocation_sum

    for(int i=0;i<p;i++){

        allocation_sum[i]=0;

    }

    for(int i=0;i<p;i++){

        for(int j=0;j<r;j++){

            allocation_sum[j]=allocation_sum[j]+arr[i][j];

        }

    }

    

    //current available

    for(int i=0;i<r;i++){

        current_available[i]=resource_available[i]-allocation_sum[i];

    }   

    

    int count=0;

    int a=0;

    int visted[p];

    for(int i=0;i<p;i++){

        visted[i]=-1;

    }

        

    while(count<p){

        for(int i=0;i<p;i++){

            bool check=true;

            for(int j=2*r;j<3*r;j++){

                if(arr[i][j]>current_available[j-2*r]){

                    check=false;

                    break;

                }    

            }

            if(check && visted[i]==-1){

                answer_sequence[a]=i;

                visted[i]=1;

                for(int j=0;j<r;j++){

                    current_available[j]=current_available[j]+arr[i][j];

                }

                a++;

                count++;

            }

        }

    } 

    

    //print table

    int l, m;

    printf("\n\tPID\tALLOCATE\tMAX\t\tNEED\n");

    for (l = 0; l < p; l++)

    {

        printf("\tP%d\t", l);

        for (m = 0; m < r; m++)

            printf("%d ", arr[l][m]);

        printf("\t\t");

        for (m = r; m < 2*r; m++)

            printf("%d ", arr[l][m]);

        printf("\t\t");

        for (m = 2*r; m < 3*r; m++)

            printf("%d ", arr[l][m]);

        printf("\n");

    }    

    

    //safe sequence

    printf("\nSafe Sequence: \n");

    for(int i=0;i<p-1;i++){

        printf("p%d->",answer_sequence[i]);

    }

    printf("p%d\n",answer_sequence[p-1]);

}



int main()

{

    printf("Enter Number of Process: ");

    scanf("%d",&p);

    printf("Enter Number of Resources: ");

    scanf("%d",&r);

    for(int i=0;i<p;i++){

        printf("Enter Resources allocated to P%d: ", i);

        for(int j=0;j<r;j++){

            scanf("%d",&arr[i][j]);

        }

    }

    

    for(int i=0;i<p;i++){

        printf("Enter Maxneed for P%d: ", i);

        for(int j=r;j<2*r;j++){

            scanf("%d",&arr[i][j]);

        }

    }

    

    printf("Enter Resource available: ");

    for(int i=0;i<r;i++){

        scanf("%d",&resource_available[i]);

    }

    

    //Calculate Need

    for(int i=0;i<p;i++){

        for(int j=2*r;j<3*r;j++){

            arr[i][j]=arr[i][j-r]-arr[i][j-2*r];

        }

    }

    

    bankers();

    

    return 0;

}
