//Depth First Search Algorithm
#include<stdio.h>
//#include<conio.h>
void display();
void input();
void dfs();
int pop();
void push(int);
int v,n,t=-1,visited[10]={0},a[10][10],stk[10]={0};
int main(){
	clrscr();
	printf("\nenter the number of nodes: ");
	scanf("%d",&n);
	printf("\nenter the adjacent matrix: \n");
	input();
//	display();
	printf("\nenter the starting vertex: \n");
	scanf("%d",&v);
	printf("\ndfs traversal: \n");
	dfs(v);	
	getch();
	return 0;
}
void input(){
	int i, j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
   			scanf("%d",&a[i][j]);
}
void dfs(int v){
	printf("%d->", v);
	int i,j,u=v;
	visited[u]=1;
	while(1){
		for(j=1; j<=n; j++){
			if(a[u][j]!=0 && visited[j]==0){
				visited[j]=1;
				push(j);
			}
		}
		u=pop();
		printf("%d->", u);
		if(t==-1)
			break;		
	}
	printf("NULL\n");
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
void push(int x){
	stk[++t]=x;
}
int pop(){
	return stk[t--];
}
