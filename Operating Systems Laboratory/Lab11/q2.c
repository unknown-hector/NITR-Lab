#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
 sem_t mutex[5];
 void* even(void* arg){
    long int i = (long int)arg;
    
    sem_wait(&mutex[(i+1)%5]);
    printf("philosopher#%ld grabbed fork#%ld (right) \n",i,(i+1)%5);
    sleep(1);
    sem_wait(&mutex[i]);
    printf("philosopher#%ld grabbed fork#%ld (left)\n",i,i);
    printf("philosopher#%ld is eating\n",i);
    sleep(1);
    sem_post(&mutex[i]);
    sem_post(&mutex[(i+1)%5]);
    printf("philosopher#%ld is thinking\n",i);
}
 
void* odd(void* arg){
    long int i = (long int)arg;
    
    sem_wait(&mutex[i]);
    printf("philosopher#%ld grabbed fork#%ld (left)\n",i,i);
    sleep(1);
    sem_wait(&mutex[(i+1)%5]);
    printf("philosopher#%ld grabbed fork#%ld (right)\n",i,(i+1)%5);
    printf("philosopher#%ld is eating\n",i);
    sleep(1);
    sem_post(&mutex[(i+1)%5]);
    sem_post(&mutex[i]);
    printf("philosopher#%ld is thinking\n",i);
    
}
 
int main(){
    long int p = 0;
    for(int i=0;i<5;i++){
        sem_init(&mutex[i],0,1);
    }
    pthread_t p0, p1, p2, p3, p4;
    
    pthread_create(&p0,NULL,even,(void*)p);
    p++;
    pthread_create(&p1,NULL,odd,(void*)p);
    p++;
    pthread_create(&p2,NULL,even,(void*)p);
    p++;
    pthread_create(&p3,NULL,odd,(void*)p);
    p++;
    pthread_create(&p4,NULL,even,(void*)p);
    
    pthread_join(p0,NULL);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    pthread_join(p3,NULL);
    pthread_join(p4,NULL);
    
    return 0;
}
