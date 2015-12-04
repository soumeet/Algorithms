//Maximum and Minimum using Divide and Conquer
#include<stdio.h>
#include<conio.h>
int a[100], max, min, max1, min1, c=0;
void max_min(int, int);
int main(){
	int k, n;
	clrscr();
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	printf("\nEnter the elements of array: ");

	for(k=0; k<n; k++)
		scanf("%d", &a[k]);
	max_min(0, n-1);
    printf("\nMax: %d Min: %d", max, min);
	    printf("\nComparison: %d", c);
	getch();
	return 0;
}


void max_min(int i, int j){
	int mid, min1, max1;


	if(i==j){
		max=a[i];
		min=a[i];
	}
	else if(i==(j-1)){
		if(a[i]>a[j]){
			max=a[i];
			min=a[j];
		}else{
			max=a[j];
			min=a[i];
		}
		c++;
	}else{
		mid=(i+j)/2;
		max_min(i, mid);
		max1=max;
		min1=min;
		max_min(mid+1, j);
		if(max1>max)
			max=max1;
		if(min1<min)
			min=min1;
		c=c+2;
	}
}