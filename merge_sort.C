//Merge Sort Using Divide and Conquer
#include<stdio.h>
//#include<conio.h>
int a[100], b[100], n;
void mergesort(int, int);
void merge(int, int, int);
void display();
int main(){
	int k;
//	clrscr();
	printf("\nenter the number of elements: ");
	scanf("%d", &n);
	printf("\nenter the elements of array: \n");
	for(k=0; k<n; k++)
		scanf("%d", &a[k]);
	printf("\nbefore sort: \n");
	display();
	mergesort(0, n-1);
	printf("\nafter sort: \n");
	display();
//	getch();
	return 0;
}
void mergesort(int low, int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		mergesort(low, mid);
		mergesort(mid+1, high);
		merge(low, mid, high);
	}

}
void merge(int low, int mid, int high){
	int h=low, i=low, j=mid+1, k;
	while(h<=mid && j<=high){
		if(a[h]<=a[j]){
			b[i]=a[h];
			h=h+1;
		}else{
			b[i]=a[j];
			j=j+1;
		}
		i=i+1;
	}
	if(h>mid){
		for(k=j; k<=high; k++){
			b[i]=a[k];
			i++;
		}
	}else{
		for(k=h; k<=mid; k++){
			b[i]=a[k];
			i++;
		}
	}
	for(k=low; k<=high; k++){
		a[k]=b[k];
	}
}
void display(){
	int k;
	for(k=0; k<n; k++)
		printf("%d\t", a[k]);
}
