#include <stdio.h>
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
    
    int headMovement=0;
    for(int i =0; i < tracksNo; i++)
    {
        headMovement += abs(head-sequence[i]);
        head = sequence[i];
    }
    printf("Total number of head Movement = %d", headMovement);
}