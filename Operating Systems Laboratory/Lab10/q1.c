#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
sem_t mutex;sem_t mutex1;
sem_t mutex2;
int buf = 0;
void* produce(void* arg){
long int pid = (long int)arg;
int i;
for(i=0;i<4;i++){
sem_wait(&mutex1);
sem_wait(&mutex);
buf++;
printf("producer#%ld added one entry, total = %d\n",pid, buf);
sleep(1);
sem_post(&mutex);
sem_post(&mutex2);
}
}
void* consume(void* arg){
long int cid = (long int)arg;
int i;
for(i=0;i<4;i++){
sem_wait(&mutex2);
sem_wait(&mutex);
buf--;
printf("consumer#%ld removed a entry, total entries = %d\n",cid, buf);
sleep(1);sem_post(&mutex);
sem_post(&mutex1);
}
}
int main(){
long int p = 1, c = 1;
sem_init(&mutex,0,1);
sem_init(&mutex1,0,5);
sem_init(&mutex2,0,0);
pthread_t p1, p2, p3;
pthread_t c1, c2, c3;
pthread_create(&p1,NULL,produce,(void*)p);
p++;
pthread_create(&p2,NULL,produce,(void*)p);
p++;
pthread_create(&p3,NULL,produce,(void*)p);
pthread_create(&c1,NULL,consume,(void*)c);
c++;
pthread_create(&c2,NULL,consume,(void*)c);
c++;
pthread_create(&c3,NULL,consume,(void*)c);
pthread_join(p1,NULL);
pthread_join(p2,NULL);
pthread_join(p3,NULL);
pthread_join(c1,NULL);
pthread_join(c2,NULL);
pthread_join(c3,NULL);
return 0;
}
