//Prim's Minimum Spanning Tree Algorithm
#include<stdio.h>
#define infinity 999
void display();
void input();
void prims();
int a,b,u,v,n,i,j,ne=1;
int visited[10]={0},min,mincost=0,cost[10][10];

int main(){
	//clrscr();
	printf("\nEnter the number of nodes:");
	scanf("%d",&n);
	printf("\nEnter the cost matrix:\n");
	input();
	display();
	prims();
	printf("\n Minimun Cost:%d",mincost);
	return 0;
}
void input(){
	int i, j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
   			scanf("%d",&cost[i][j]);
   			if(cost[i][j]==0)
    			cost[i][j]=infinity;
  		}
}

void prims(){
	visited[1]=1;
	printf("\n");
	while(ne < n){
		for(i=1,min=999;i<=n;i++)
			for(j=1;j<=n;j++)
				if(cost[i][j]< min)
					if(visited[i]!=0){
						min=cost[i][j];
						a=u=i;
						b=v=j;
					}
		if(visited[u]==0 || visited[v]==0){
			printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
	}
}

void display(){
	int i, j;
	printf("\nCost Matrix[][]: \n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
			printf("%d\t", cost[i][j]);
		printf("\n");
	}
}
