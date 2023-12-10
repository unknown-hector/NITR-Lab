

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
 void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
  
        // Last i elements are already 
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            
            {
              int temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
            }
                
}
int main(void)
{
   int n,fd[2];
   pid_t pid;
    int line[10];
   if(pipe(fd)==-1) exit(1);
   else
      printf("PIPE created successfully\n");
      if((pid=fork())<0)
      exit(1);
      else if(pid>0)
      {
        int arr[]={7,10,8,7,6,5,4,3,2,1};
        
         write(fd[1],arr, sizeof(arr));
       
      
          waitpid(pid,0,0);
          int temp[10];
         
          read(fd[0],temp,sizeof(temp));
            for(int i=0;i<10;i++)
            {
               printf(" %d ", temp[i]);
               }
         }
         else 
         {
           int ar[10];
            read(fd[0],ar,sizeof(ar));
         
              int size=10;
            int i=0;
            bubbleSort(ar,10);
         
            write(fd[1],ar,sizeof(ar));
     
           
           }

        return 0;
}

