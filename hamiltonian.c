//Hamiltonian Cycle Path Algorithm using Backtracking
#include<stdio.h>
#include<stdlib.h>
void display();
void input();
void result();
void final();
int tsp();
void hamiltonian(int);
int nextvalue(int);
int n, a[10][10], x[10]={0}, mincost=999, path[10]={0};
FILE *fout;
int main(){
	printf("\nEnter the number of nodes:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	input();
	display();
	x[1]=1;
	hamiltonian(2);
	final();
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

void hamiltonian(int k){
	do{
		x[k]=nextvalue(k);
		if(x[k]==0)
			return;
		if(k==n)
			result();
		else
			hamiltonian(k+1);
	}while(1);
}

int nextvalue(int k){
	int j;
	do{
		x[k]=(x[k]+1)%(n+1);
		if(x[k]==0)
			return x[k];
		if(a[x[k-1]][x[k]]!=0){ //checks for edge
			for(j=1; j<=k-1; j++)
				if(x[j]==x[k])
					break;
			if(j==k)
				if((k<n) || ((k==n) && (a[x[n]][x[1]]!=0))) //checks for distinct vertex
					return x[k];
		}
	}while(1);
}

void display(){
	int i, j;
	printf("\nAdjacency Matrix[][]: \n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
}

void result(){
	int i;
	printf("\nSolution Array[]: \n");
	for(i=1; i<=n; i++)
		printf("%d\t", x[i]);
	printf("\nCost: %d\n", tsp());
	if(mincost>tsp()){
		for(i=1; i<=n; i++)
			path[i]=x[i];	
		mincost=tsp();
	}
}

int tsp(){
	int i, cost=0;
	for(i=1; i<n; i++)
		cost=cost+a[x[i]][x[i+1]];
	return cost;	
}

void final(){
	int i;	
	printf("\nTravelling Salesman Path: \n");
	for(i=1; i<=n; i++)
		printf("%d\t", path[i]);
	printf("\nCost: %d\n", mincost);
}

