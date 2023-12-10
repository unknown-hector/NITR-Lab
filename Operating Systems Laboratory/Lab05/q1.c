#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
int main()
{
    pid_t pid=fork();
    int x,y;
    if(pid>0)
       {
              
             
                x=02,y=04;
              
              }
         else if(pid==0)
         {
              
              
              printf(" %d %d \n", x,y);
              
            }

}

 
/* 
 

Note : it gives error,

   if  variables in parent are accesed by child , it will not give error ,

   so by contradiction we are proving.

 */

