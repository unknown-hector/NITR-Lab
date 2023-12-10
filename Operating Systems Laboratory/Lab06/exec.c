#include <stdio.h>
#include<unistd.h>
int main()
{
    execl("/bin/ls","ls","-l","-a",NULL);
    printf("EXEC Failed\n");

}
