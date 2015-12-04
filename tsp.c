//Travelling Salesman Problem Algorithm using Backtracking
#include<stdio.h>
//#include<conio.h>
void display();
void input();
void result();
void cost_calc();
void tsp(int);
int nextvalue(int);
int n, a[10][10], x[10]={0}, mincost=999, path[10]={0};
int main(){
//	clrscr();	
	printf("\nenter number of nodes:");
	scanf("%d",&n);
	printf("\nenter cost matrix:\n");
	input();
	display();
	x[1]=1;
	tsp(2);
	result();
	getch();
	return 0;
}
void input(){
	int i, j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
   			scanf("%d", &a[i][j]);
   			if(i==j)
    				a[i][j]=0;
  		}
}
void tsp(int k){
	do{
		x[k]=nextvalue(k);
		if(x[k]==0)
			return;
		if(k==n)
			cost_calc();
		else
			tsp(k+1);
	}while(1);
}
int nextvalue(int k){
	int j;
	do{
		x[k]=(x[k]+1)%(n+1);
		if(x[k]==0)
			return x[k];
		if(a[x[k-1]][x[k]]!=0){
			for(j=1; j<=k-1; j++)
				if(x[j]==x[k])
					break;
			if(j==k)
				if((k<n) || ((k==n) && (a[x[n]][x[1]]!=0)))
					return x[k];
		}
	}while(1);
}
void display(){
	int i, j;
	printf("\nCost Matrix[][]: \n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
}
void cost_calc(){
	int i, cost=0;
	for(i=1; i<=n; i++){
		if(i!=n)
			cost=cost+a[x[i]][x[i+1]];
		else
			cost=cost+a[x[n]][x[1]];
	}	
	if(mincost>cost){
		for(i=1; i<=n; i++)
			path[i]=x[i];	
		mincost=cost;
	}	
}
void result(){
	int i;	
	printf("\nTravelling Salesman Path: \n");
	for(i=1; i<=n; i++)
		printf("%d\t", path[i]);
	printf("\nCost: %d\n", mincost);
}
