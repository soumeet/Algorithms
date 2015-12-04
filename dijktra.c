#include<stdio.h>
#define infinity 999
void display();
void display1();
void input(); 
void dij();
int n, v, cost[10][10], dist[10], label[10][2], flag[10];

int main(){
	//clrscr(); 
	ed
	printf("\nEnter the number of nodes:");
	scanf("%d",&n);
	printf("\nEnter the cost matrix:\n");
	input();
	printf("\nEnter the source:");
	scanf("%d",&v);
	display();
	dij();
	printf("\nShortest path:\n");
	display1();
	return 0;
}

/*
void dij(){
	int i,u,count,w,flag[10],min;
	for(i=1;i<=n;i++)
		flag[i]=0,dist[i]=cost[v][i];
	count=2;
	while(count<=n){
		min=99;
		for(w=1;w<=n;w++)
   			if(dist[w]<min && !flag[w])
    			min=dist[w],u=w;
  		flag[u]=1;
  		count++;
  		for(w=1;w<=n;w++)
  			 if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
    			dist[w]=dist[u]+cost[u][w];
 	}
}
*/

void dij(){
	int i, j;
	for(i=1;i<=n;i++)
		flag[i]=0;
	for(i=1;i<=n;i++)
		if(i==v)
			label[i][0]=0, label[i][1]=0;
		else{
			for(j=1; j<=n; j++){
				if(cost[i][j]!=infinity)
	
			}
		}	
	}
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

void display(){
	int i, j;
	printf("\nCost Matrix[][]: \n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
			printf("%d\t", cost[i][j]);
		printf("\n");
	}
}

void display1(){
	int i;
	for(i=1;i<=n;i++)
		if(i!=v)
			printf("%d->%d,cost=%d\n",v,i,dist[i]);
}
 

