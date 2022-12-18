#include <stdio.h>
int main()
{
    int n;
  
    printf("\n Enter the no. of pages:\n");
    scanf("%d",&n);
  
    int incomingStream[n]; 
    printf("\n Enter the reference string(different page numbers) :\n");

    for(int i=0;i<n;i++)
     scanf("%d",&incomingStream[i]);

    int pageFaults = 0;


    int frames ;
    printf("Enter number of frames: ");
    scanf("%d",&frames);
    int m,  s, pages;

    pages = sizeof(incomingStream)/sizeof(incomingStream[0]);

   
    int temp[frames];
    for(m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }

    for(m = 0; m < pages; m++)
    {
        s = 0;

        for(int j = 0; j < frames; j++)
        {
            if(incomingStream[m] == temp[j])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        
        if((pageFaults <= frames) && (s == 0))
        {
            temp[m] = incomingStream[m];
        }
        else if(s == 0)
        {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }
      
        printf("\n");
        for(int j = 0; j < frames; j++)
        {
            if(temp[j] != -1)
                printf(" %d", temp[j]);
            else
                printf("-");
        }
      
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);
     printf("\nPage Fault ratio = %.2f\n",(float)pageFaults/n);
   printf("\nPage Hit Ratio = %.2f\n",(float)(n- pageFaults)/n);
    return 0;
}