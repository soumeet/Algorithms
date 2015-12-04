//Quick Sort Using Divide and Conquer
#include<stdio.h>
//#include<conio.h>
void input();
int partition(int, int);
void quicksort(int, int);
void display();
int a[100], n;
int main(){	
//	clrscr();
	input();
	printf("\nbefore sort: \n");
	display();
	quicksort(0, n-1);
	printf("\nafter sort: \n");
	display();
//	getch();
	return 0;
}

void display(){
	int i;
	for(i=0; i<n; i++)
		printf("%d\t", a[i]);
}

void input(){
	int i;
	printf("\nenter no of elements: ");
	scanf("%d", &n);
	printf("\nenter %d elements: \n", n);
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
}

int partition(int l, int u){
	int v=a[l], i=l, j=u;
//	printf("partition: v:%d i:%d j:%d\n", v, i, j);
	do{
		do{
			i=i+1;
//			printf("partition: v:%d i:%d j:%d\n", v, i, j);
		}while(a[i]<v);
		do{
			j=j-1;
//			printf("partition: v:%d i:%d j:%d\n", v, i, j);
		}while(a[j]>v);
		if(i<j){
//			printf("partition: Interchanging i:%d j:%d\n", i, j);
			int tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
		}
	}while(i<j);
	a[l]=a[j];
	a[j]=v;
	return j;
}
void quicksort(int p, int q){
	int j;
	if(p<q){
		j=partition(p, q+1);
		quicksort(p, j-1);
		quicksort(j+1, q);
	}
}
