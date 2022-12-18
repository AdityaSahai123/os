#include<stdio.h>
#include<stdlib.h>

struct process{

    int pid;// pid
    int at;//arrival time
    int bt;//burst time
    int ct;// compiletion time
    int tat;// turn around time
    int wt;//waiting time
    int rt;//response time
    int st;//start time
};

int compare(const void *p1, const void *p2)
{
    int a=((struct process *)p1)->at;
    int b= ((struct process *p2)->at;

    if(a<b)
        return -1;
    
    else
        return 1;
}

int main()
{

    int n;
    float sumwt=0, sumtat=0, sumrt=0;
    float avgrt=0,avgwt=0,avgtat=0;
    int ideal=0;
    float cpu, thu;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    struct process p[n];

    for(int i=0;i<n;i++)
    {
        p[i].pid=i;
        printf("Enter arrival time and burst time for P%d: ",i);
        scanf("%d%d",&p[i].at,&p[i].bt);
    }

    qsort((void*)p,n,sizeof(struct process),compare);

    for(int i=0;i<n;i++)
    {

        //first time
        if(i==0)
        {
            p[i].st=p[i].at;
            p[i].ct=p[i].st+p[i].bt;
            p[i].rt=0;
        }

        else if(p[i-1].ct < p[i].at)
        {
            p[i].st=p[i].at;
            p[i].ct=p[i].st+p[i].bt;
            p[i].rt= 0;
            ideal +=p[i].at-p[i-1].ct;
        }

        else
        {
            p[i].st=p[i-1].ct;
            p[i].ct=p[i].st+p[i].bt;
            p[i].rt=p[i].st-p[i].at;
        }

        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }

    for(int i = 0 ; i <n ; i++){
        sumWT += p[i].wt;
        sumTat +=p[i].tat;
        sumrt += p[i].rt;
    }
    
    
    avgWT = sumWT/n;
    avgTat = sumTat/n;
    avgrt = sumrt/n;
    
    
    printf("process\tat\tbt\tst\tct\trt\ttat\twt\n");
    
    for(int i = 0 ; i < n ; i++){
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid , p[i].at , p[i].bt , p[i].st , p[i].ct , p[i].rt , p[i].tat , p[i].wt);
    }
    
     printf("Average Response Time =  %0.2f\n Average TurnAround Time = %0.2f\n  Average Waiting Time = %0.2f\n" , avgrt , avgTat , avgWT);
    
    int totalTime = p[n-1].ct;

    cpuUtilization = ((float)(totalTime - idealTime) / totalTime )*100;
    Throughput = (float)n/(float)totalTime;

    printf("CPU Utilitzation - 0.2%f Throughput - 0.2%f" , cpuUtilization , Throughput);

    return 0;
}