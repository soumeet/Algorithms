//Flyod Warshall Algortihm
#include<stdio.h>
//#include<conio.h>
void flyod_warshall();
void input();
void display();
int min(int, int);
int cost[10][10], n, a[10][10];

int main(){
//	clrscr();	
	input();
	flyod_warshall();
	display();
//	getch();	
	return 0;	
}

void display(){
	int i, j;
	printf("\nafter : \n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
}

void input(){
	int i, j;
	printf("\nenter no of vertices: ");
	scanf("%d", &n);
	printf("\nenter weight of vertices: \n");
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			scanf("%d", &cost[i][j]);
}


void flyod_warshall(){
	int i, j, k;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			a[i][j]=cost[i][j];
	for(k=1; k<=n; k++)
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				a[i][j]=min(a[i][j], a[i][k]+a[k][j]);
}

int min(int x, int y){
	if(x<y)
		return x;
	else
		return y; 
}
