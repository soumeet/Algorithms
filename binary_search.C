//Binary Search Using Divide and Conquer
#include<stdio.h>
#include<conio.h>
int binary_search(int [], int , int, int);
int main(){
	int n, i, x, a[100], loc;

	clrscr();
	printf("\nEnter the numbers of elements: ");
	scanf("%d", &n);
	printf("\nEnter the numbers of sorted array: \n");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("\nEnter the Key: \n");
	scanf("%d", &x);
	loc=binary_search(a, 0, n, x);
	if(loc==-1)
		printf("\nElement not found %d", loc);
	else
		printf("\nElement found at: %d", loc);

	getch();
	return 0;
}

int binary_search(int ar[], int low, int high, int key){
	printf("\nRunning...");
	if(low<=high){
		int mid=(low+high)/2;
		if(key==ar[mid])
			return mid;
		else if(key>ar[mid])
			binary_search(ar, mid+1, high, key);
		else
			binary_search(ar, low, mid-1, key);
	}
	return -1;
}
