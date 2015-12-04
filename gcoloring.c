//Graph Coloring Algorithm using Backtracking
#include<stdio.h>
//#include<conio.h>
void display();
void input();
void result();
int gcolor(int);
int nextvalue(int);
int n, m, a[10][10], x[10];

int main(){
//	clrscr();
	input();
	display();
	gcolor(1);
	getch();
	return 0;
}

void input(){
	int i, j;
	printf("\nenter the number of nodes:");
	scanf("%d",&n);
	printf("\nenter the number of colors:");
	scanf("%d",&m);
	printf("\nenter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
   			scanf("%d", &a[i][j]);
   			if(i==j)
    			a[i][j]=0;
  		}
}

int gcolor(int k){
	do{
		x[k]=nextvalue(k);
		if(x[k]==0)
			return x[k];
		if(k==n)
			result();
		else
			gcolor(k+1);
	}while(1);
}

int nextvalue(int k){
	int j;
	do{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
			return x[k];
		for(j=1; j<=n; j++)
			if(a[k][j]!=0 && x[k]==x[j])
				break;
		if(j==(n+1))
			return x[k];
	}while(1);
}

void display(){
	int i, j;
	printf("\nadjacency matrix[][]: \n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
}

void result(){
	int i;
	printf("\nsolution array[]: \n");
	for(i=1; i<=n; i++)
				printf("%d\t", x[i]);
	printf("\n");
}
