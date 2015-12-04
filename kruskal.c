//Kruskal's Minimum Spanning Tree Algorithm
#include<stdio.h>
//#include<conio.h>
#define infinity 999
void display(); 	
void input();
void kruskal();
int n,ne=1,mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
int main(){
//	clrscr();
	input();
	display(); 
	kruskal();	
	printf("\nminimum cost: %d\n",mincost);
	getch();
	return 0;
}
void kruskal(){
	int i, j, a, b, u, v, min;
	while(ne<n){
		for(i=1,min=999;i<=n;i++){
			for(j=1;j<=n;j++){
				if(cost[i][j]<min){
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v)){
			printf("\n%d edge (%d,%d) =%d",ne++,a,b,min);
	   		mincost +=min;
	  	}
	  	cost[a][b]=cost[b][a]=999;
 	}
}
int find(int i){
	while(parent[i])
		i=parent[i];
	return i;
}
int uni(int i,int j){
	if(i!=j){
		parent[j]=i;
		return 1;
 	}
	return 0;
}
void input(){
	int i, j;
	printf("\nenter the number of nodes:");
	scanf("%d",&n);
	printf("\nenter the cost matrix: \n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
   			scanf("%d",&cost[i][j]);
   			if(cost[i][j]==0)
    			cost[i][j]=infinity;
  		}
}
void display(){
	int i, j;
	printf("\ncost matrix[][]: \n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
			printf("%d\t", cost[i][j]);
		printf("\n");
	}
}
