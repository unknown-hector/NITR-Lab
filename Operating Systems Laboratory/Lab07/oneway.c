#include <stdio.h>
#include<stdlib.h>
#include <errno.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include <unistd.h>
#define FIFO_NAME "myfile.txt"
int main(void)
{
    char s[300];
    int num,fd;
    mkfifo(FIFO_NAME, 0666);
    printf("waiting for readers..\n");
    fd=open(FIFO_NAME,O_RDWR);
    while(1)
    {
    printf("got a reader-- type some text\n");
    fgets(s, sizeof(s), stdin);
    if((num=write(fd,s,strlen(s)))==-1)
       perror("write");
    else
       printf("Write wrote %d bytes\n",num);
      
       printf("Type  0 to stop reading or 1 to continue reading\n");
       int cas=1;
       scanf("%d",&cas);
       if(cas==0)
           break;
       }
       
       return 0;
}
