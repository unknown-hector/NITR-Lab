#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// m: rows
// n:columns
// A,B stores input matrices, C stores output(A+B) matrix.
int m, n, **A, **B, **C;
void add_matrix(int,int);
void add_row(void*);
void main()
{
printf("THIS IS A PROGRAM TO ADD TWO m*n MATRICES BY USING m*n NUMBER OF THREADS\n\n");
printf("Enter the value of M: ");
scanf("%i",&m);
printf("Enter the value of N: ");
scanf("%i",&n);
A = (int**)malloc(m*sizeof(int*));
B = (int**)malloc(m*sizeof(int*));
C = (int**)malloc(m*sizeof(int*));
for(int i=0; i<m; ++i)
{
A[i] = (int*)malloc(n*sizeof(int));
B[i] = (int*)malloc(n*sizeof(int));
C[i] = (int*)malloc(n*sizeof(int));
}
printf("\nEnter the value of the elements of 1st array below -->\n");
for(int i=0; i<m; ++i)
{
for(int j=0; j<n; ++j)
{
scanf("%i", *(A+i)+j);
}}
printf("\nEnter the value of the elements of 2nd array below -->\n");
for(int i=0; i<m; ++i)
{
for(int j=0; j<n; ++j)
{
scanf("%i", *(B+i)+j);
}
}
add_matrix(m,n);
printf("\n\nSum of the matrices is as follows:\n");
for(int i=0; i<m; ++i)
{
for(int j=0; j<n; ++j)
{
printf(" %i", *(*(C+i)+j));
}
printf("\n");
}
for(int i=0; i<m; ++i)
{
free(*(A+i));
free(*(B+i));
free(*(C+i));
}
free(A);
free(B);
free(C);
A = NULL;
B = NULL;
C = NULL;printf("\n");
}
void add_matrix(int M, int N)
{
pthread_t T[M][N];
for(int i=0; i<M; ++i)
{
int tmp[2];
for(int j=0; j<N; ++j)
{
tmp[0] = i;
tmp[1] = j;
pthread_create(&T[i][j],NULL,(void*)add_row,
(void*)tmp);
pthread_join(T[i][j],NULL);
}
}
}
void add_row(void* arg)
{
int *TMP = (int*)arg;
C[TMP[0]][TMP[1]] = A[TMP[0]][TMP[1]] +
B[TMP[0]][TMP[1]];
}
