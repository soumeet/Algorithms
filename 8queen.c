//N-Queen using Backtracking
#include<stdio.h>
//#include<conio.h>
void display(); 
void nQueen(int, int);
int place(int, int);
int n, x[10];
int main(){
//	clrscr();
	printf("\nenter the number of queens: ");
	scanf("%d",&n);
	nQueen(1, n);	
	getch();
	return 0;
}

void nQueen(int k, int n){
	int i;
	for(i=1; i<=n; i++)
		if(place(k, i)){
			x[k]=i;
			if(k==n)
				display();
			else
				nQueen(k+1, n);		
		}
}

int place(int k, int i){
	int j;
	for(j=1; j<=k-1; j++)
		if(x[j]==i || (abs(x[j]-i)==abs(j-k)))
			return 0;
	return 1;
}

void display(){
	int i;
	printf("\nqueens positions: \n");
	for(i=1; i<=n; i++)
			printf("%d\t", x[i]);
}
