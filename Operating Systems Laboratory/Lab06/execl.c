#include <stdio.h>
#include<unistd.h>
int main()
{
    execl("/home/administrator/120CS0173/Lab06/hello","hello",NULL);
    printf("EXEC Failed\n");

}

