#include <stdio.h>
#include <limits.h>
#include <math.h>
int main()
{
    printf("Enter the number of tracks in request queue : \n");
    int tracksNo;
    scanf("%d", &tracksNo);
    
    printf("Enter the track sequence from request queue:\n");
    int sequence[tracksNo];
    for(int i = 0; i < tracksNo;i++)
    {
        scanf("%d", &sequence[i]);
    }
    printf("Enter the initial position of head : \n");
    int head;
    scanf("%d", &head);
    int min = INT_MAX;
    int temp = 0;
    int x = -1;
    int headMovement=0;
    printf("Seek sequence is : \n");
    for(int i =0; i < tracksNo; i++)
    {
        for(int j = 0; j < tracksNo; j++)
        {
            if(sequence[j]==-1) continue;
            if(abs(head-sequence[j]) < min)
            {
                min = abs(head-sequence[j]);
                temp = sequence[j];
                x = j;
            }
        }               
        headMovement+=abs(head-temp);
        head = temp;
        sequence[x] = -1;
        printf("%d\n", head);
        min = INT_MAX;
    }
    printf("Total number of head Movement = %d", headMovement);
}