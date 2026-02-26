#include<stdio.h>
int main()
{
    int n,i,j,tatsum=0,wtsum=0;
    float tatavg,wtavg;
    printf("enter the number of processes:");
    scanf("%d",&n);

    int at[n],bt[n],ct[n],tat[n],wt[n];

    for(i=0;i<n;i++)
    {
        printf("enter the arrival time P%d:",i+1);
        scanf("%d",&at[i]);
  
    }
    for(i=0;i<n;i++)
    {
        printf("enter the Burst time P%d:",i+1);
        scanf("%d",&bt[i]);

    }

    //--------------find completion time---------------

    ct[0]=at[0]+bt[0];
    for(i=0;i<n;i++)
    {
        if(ct[i-1]< at[i])
        {
            ct[i]=at[i]+bt[i];
        }
        else{
            ct[i]=ct[i-1]+bt[i];
        }
    }
    //------------------find turn around time and wating time-------------------------

    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        tatsum+=tat[i];
        wt[i]=tat[i]-bt[i];
        wtsum+=wt[i];
    }
   
    tatavg=(float)tatsum/n;
    wtavg=(float)wtsum/n;

    //-------------------output print----------------------
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("p%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\n");
    printf("TAT average:%2f\n",tatavg);
    printf("WT average:%2f\n",wtavg);

    return 0;
}


