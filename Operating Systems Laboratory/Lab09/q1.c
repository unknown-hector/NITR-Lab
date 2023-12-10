#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#define MAX 20
#define THREAD_MAX 5
int a[MAX];
int part = 0;
void merge(int l,
int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
// Create temp arrays
int L[n1], R[n2];
// Copy data to temp arrays
// L[] and R[]
for (i = 0; i < n1; i++)
L[i] = a[l + i];
for (j = 0; j < n2; j++)
R[j] = a[m + 1 + j];
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2)
{
if (L[i] <= R[j])
{
a[k] = L[i];
i++;
}
else
{
a[k] = R[j];
j++;
}
k++;
}while (i < n1) {
a[k] = L[i];
i++;
k++;
}
while (j < n2)
{
a[k] = R[j];
j++;
k++;
}
}
void merge_sort(int low, int high)
{
int mid = low + (high - low) / 2;
if (low < high) {
merge_sort(low, mid);
merge_sort(mid + 1, high);
merge(low, mid, high);
}
}void* thread_part(void* arg)
{
int thread_part = part++;
int low = thread_part * (MAX / 5);
int high = (thread_part + 1) * (MAX / 5) - 1;
int mid = low + (high - low) / 2;
if (low < high) {
merge_sort(low, mid);
merge_sort(mid + 1, high);
merge(low, mid, high);
}
}
int main()
{
srand(time(0));
printf("Before sorting : ");
for (int i = 0; i < MAX; i++)
{
a[i] = rand() % 100;
printf("%d ", a[i]);
}
printf("\n");pthread_t threads[THREAD_MAX];
for (int i = 0; i < THREAD_MAX; i++)
pthread_create(&threads[i], NULL, thread_part,
(void*)NULL);
for (int i = 0; i < THREAD_MAX; i++)
pthread_join(threads[i], NULL);
merge(0, 3,7);
merge(8,11,15);
merge(0,7,15);
merge(0,15,19);
printf("After Sorting : ");
for (int i = 0; i < MAX; i++)
printf("%d ", a[i]);
printf("\n");
return 0;
}
