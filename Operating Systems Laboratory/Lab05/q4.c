#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
    int fd[2];
    pipe(fd);
    pid_t pid=fork();
    
    if(pid>0)
       {
       int x;
       scanf("%d", &x);
          write(fd[1],&x, sizeof(x));
          printf("Parent :  %d \n", x);
        waitpid(pid,0,0);
       
        
        
    }
   else 
   {
   int a;
       read(fd[0],&a,sizeof(a));
       printf("Child : %d \n",a);
       
      


    }
    return 0;
}

