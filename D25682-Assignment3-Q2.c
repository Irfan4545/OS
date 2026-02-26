#include <stdio.h>
int main()
{
    int n = 5;
    int pid[5] = {0, 1, 2, 3, 4};

    int AT[5]  = {0, 0, 0, 0, 0};
    int BT1[5] = {5, 7, 6, 8, 5};
    int IO[5]  = {2, 2, 3, 1, 2};
    int BT2[5] = {3, 2, 4, 2, 5};

    int PCT[5], CT[5], TAT[5], WT[5];
    float avgTAT = 0, avgWT = 0;

    // First process
    PCT[0] = BT1[0] + IO[0];
    CT[0]  = PCT[0] + BT2[0];

    // Remaining processes (FCFS)
    for(int i = 1; i < n; i++)
    {
        PCT[i] = CT[i-1] + BT1[i] + IO[i];
        CT[i]  = PCT[i] + BT2[i];
    }

    // TAT & WT
    for(int i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i]  = TAT[i] - (BT1[i] + BT2[i]);

        avgTAT += TAT[i];
        avgWT  += WT[i];
    }

    avgTAT /= n;
    avgWT  /= n;

    // Output
    printf("\nPID\tAT\tBT1\tIO\tBT2\tPCT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], AT[i], BT1[i], IO[i], BT2[i],
               PCT[i], CT[i], TAT[i], WT[i]);
    }

    printf("\nAverage TAT = %.2f", avgTAT);
    printf("\nAverage WT  = %.2f\n", avgWT);

    return 0;
}





