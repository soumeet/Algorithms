//Bellmanford Shortest Path
#include<stdio.h>
//#include<conio.h>
int bellmanford();
void input();
void display();
void display1();
int a[10][10], cost[10][10], spl[10], prev[10];
int n;
int main(){
//	clrscr();	
	printf("\nenter Number of Vertices: \n");
	scanf("%d", &n);
	printf("\nenter Cost Matrix: \n");
	input();
	display();
	if(!bellmanford())
		printf("\nnegative cycle found\n");
	else{
		printf("\nfinal: \n");
		display1();
	}
	getch();
	return 0;	
}

void input(){
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			scanf("%d", &cost[i][j]);
}

void display(){
	int i, j;
	printf("\nA[][]: \n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
			printf("%d\t", cost[i][j]);
		printf("\n");
	}
}

void display1(){
	int i;
	printf("\nvtx:\t");
	for(i=1; i<=n; i++){
		printf("%d\t", i);
	}
	printf("\nspl:\t");
	for(i=1; i<=n; i++){
		printf("%d\t", spl[i]);
	}
	printf("\nprev:\t");
	for(i=1; i<=n; i++){
		printf("%d\t", prev[i]);
	}
	printf("\n");
}

int bellmanford(){
	int i, j, k;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			a[i][j]=cost[i][j];
	for(i=1; i<=n; i++){
		spl[i]=99;
		prev[i]=0;
	}
	display1();
	spl[1]=0;
	int x=0;
	for(k=1; k<=n-1; k++){
		for(i=1; i<=n-1; i++){
			for(j=1; j<=n; j++){
//				printf("\nk:%d a[%d][%d]:%d spl[%d]:%d prev[%d]:%d ", k, i, j, a[i][j], i, spl[i], i, prev[i]);
				if(a[i][j]!=0 && a[i][j]!=99){
					x=a[i][j]+spl[i];
//					printf("\nx:%d spl[%d]:%d prev[%d]:%d ", x, j, spl[j], j, prev[j]);
					if(x<spl[j]){
						spl[j]=x;
						prev[j]=i;
					}
				}
				
			}
			display1();
		}
	}
	for(i=1; i<n; i++)
		for(j=1; j<=n; j++){
			if(a[i][j]!=0 && a[i][j]!=99)
				x=a[i][j]+spl[i];
			if(x<spl[j])
				return 0;
		}
	return 1;
}
