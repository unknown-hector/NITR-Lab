#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        pid_t p=fork();
        if(p>0)
        {
                 wait(NULL);
                 break;
             }
        else if(p == 0)
        {
            
            printf(" parent %d , child %d \n", getppid(),getpid());
        }
           else 
               printf(" Fork Incomplete \n");
    }
    
    
}

