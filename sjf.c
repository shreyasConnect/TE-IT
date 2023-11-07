#include<stdio.h>

#include<stdbool.h>

struct Process

{

    int at,bt,ct,tat,wt,rt,pid;

    bool completed;

};



void sjf(struct Process p[], int size)

{

    int count=0; //to make count how many processes completed

    int curtime=0; //to make count of current time

    int index=0; //tells us that which process is served at this time

    int temp=0;//

    while (count!=size)

    {

        //by default comleted in struct is given false in main 

        //and arriaval time less  than current time

        //rt(runtime) = bt given in main

        //run time hepls us to maintain count of how much process is serves till current time

        //as in pre-pemtive sjf for each second shortest job will execute first

        //temp contain count of run time of last executed process.

        //if temp is then same process execute not then other.



        temp=9999;

        for(int i=0;i<size;i++)

        {

            if(p[i].completed==false && p[i].at<=curtime && p[i].rt<temp)

            {

                temp=p[i].rt; //so taht only one process is get from for loop which have short burst time.

                index=i; //tells us that which process is served at this time

            }

        }



        //runtime is decresed by 1 second because in one for loop 1  sec completed

        p[index].rt-=1;



        if(p[index].rt==0)

        {

            p[index].completed=true;  //if rt==0 then process is completed 

            p[index].ct=curtime+1; //+1 because we are 1 sec behind

            p[index].tat=p[index].ct-p[index].at;

            p[index].wt=p[index].tat-p[index].bt;

            count++; //number of process completed is incresed

        }



        curtime++; 

    }

}

int main()

{

    printf("Enter number of process:\n");

    int n;

    float avg_wt = 0, avg_tat = 0;

    scanf("%d",&n);

    struct Process p[n];

    for(int i=0;i<n;i++)

    {

        printf("\n Process ID : ");

        scanf("%d", &p[i].pid);

        printf(" \n Enter arrival time of process P: \n");

        scanf("%d",&p[i].at);

        printf("\n enter burst time of process P\n");

        scanf("%d",&p[i].bt);

        p[i].completed=false;

        p[i].rt=p[i].bt;

    }

    sjf(p,n);

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT");

    for (int i = 0; i < n; i++)

    {

        avg_wt += p[i].wt;

        avg_tat += p[i].tat;

        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);

    }

    printf("\n\nAverage Turn Around Time : %f ms", avg_tat / n);

    printf("\n\nAverage Waiting Time : %f ms", avg_wt / n);

    //cout<<s<<endl;

    return 0;

}
