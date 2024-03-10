#include<stdio.h>
#include<conio.h>
void main()
{
    int ms,bs,nob,ef,n,mp[10],tif=0;
    int i,p=0;
    
    printf("Enter the total memory available(in Bytes) __");
    scanf("%d",&ms);
    printf("Enter the block size(in Bytes)__");
    scanf("%d",&bs);
    nob = ms/bs;
    ef = ms-nob*bs;
    printf("\n Enter the number of processes __");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Memory Required for Process %d(in Bytes)__",i+1);
        scanf("%d",&mp[i]);
    }
    printf("\n No. of Blocks available in memory __ %d",nob);
    printf("\n\n process\t  Memory Required\t  Allocated\t  Internal Fragmentation");
    for(i=0;i<n && p<nob;i++)
    {
        printf("\n %d\t\t %d",i+1,mp[i]);
        if(mp[i]>bs)
        {
            printf("\t\t No \t\t__");
        }
        else
        {
            printf("\t\t YES \t%d",bs-mp[i]);
            tif = tif + bs-mp[i];
            p++;
        }
    }
    if(i<n)
    {
        printf("\n Memory is Full, Remaining Processes cannot be accomodated");
        printf("\n Total extrernal Fragmentation is %d",ef);
        getch();
    }
}