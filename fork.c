#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
void forkexample()
{
    pid_t p;
    p = fork();
    if(p == 0)
    {
        printf("Hello from Child!\n");
    }
    else
    {
        printf("Hello from Parent!\n"); 
    }
}
      int main()
{
    forkexample();
    return 0;
}  

   