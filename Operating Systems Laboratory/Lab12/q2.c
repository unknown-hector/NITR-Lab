#include<stdio.h>

int main(){
	int i, n, total=0;
	int count=0, y, time;
	int wt=0, tat=0;
	int at[15], bt[15], ct[15], temp[15];
	float avg_wt=0, avg_tat=0;

	printf("Enter No of Processes :");
	scanf("%d", &n);
	y=n;

	for(i=0; i<n; i++){
		printf("Enter the arrival time and Burst Time of process %d\n", i+1);
		scanf("%d", &at[i]);
		scanf("%d", &bt[i]);
		temp[i]= bt[i];
	}
	for(y=n; y!=0;){
		int min=9999;
		int k;
		i=0;
		while(i<n){
			if(at[i]<=total && temp[i]<min){
				min= temp[i];
				k=i;
			}
			i++;
		}
		total+=bt[k];
		ct[k]= total;
		temp[k]=9999;
		y--;
	}
	for(i=0; i<n; i++){
		printf("Process No: %d, BT %d, TAT %d, WT %d\n", i+1, bt[i], ct[i]-at[i], ct[i]-at[i]-bt[i]);
		tat+=ct[i]- at[i];
		wt+=ct[i]-at[i]-bt[i];
	}
	
	avg_wt= wt*1.0/n;
	avg_tat= tat*1.0/n;

	printf("Average Waiting time is %f,\n And average TurnAround Time is %f\n", avg_wt, avg_tat);	
		

				

	return 0;
}
