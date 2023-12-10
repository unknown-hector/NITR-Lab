#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
    int a,n;
    printf("give depth and degree");
    scanf("%d%d",&a,&n);
    l:
    if(a==0){
        //printf("process %d\n",a);
        return 0;
    }
    for(int i=0;i<n;i++){
        pid_t p=fork();
        pid_t par=getppid();
    pid_t ch=getpid();
    //printf("parent: %d  child: %d\n",par,ch);
        if(p>0){
            waitpid(p,0,0);
        }
        else
        {
        printf("parent: %d  child: %d\n",par,ch);
            a--;
            goto l;
        }
    }
    //printf("process %d\n",a);
    return 0;
}
