//Breadth First Search Algorithm
#include<stdio.h>
//#include<conio.h>
void adj();
void input();
void bfs(int);
int delQue();
void addQue(int);
int v,n,f=0,r=0,visited[10]={0},a[10][10],que[10]={0};
int main(){
//	clrscr();
	input();
	//adj();
	printf("\nenter the starting vertex: \n");
	scanf("%d",&v);
	printf("\nbfs traversal: \n");
	bfs(v);	
	getch();
	return 0;
}
void input(){
	int i, j;
	printf("\nenter the number of nodes: ");
	scanf("%d",&n);
	printf("\nenter the adjacent matrix: \n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
   			scanf("%d",&a[i][j]);
}
void bfs(int v){
	printf("%d->", v);
	int j,u=v;
	visited[u]=1;
	while(1){
		for(j=1; j<=n; j++){
			if(a[u][j]!=0 && visited[j]==0){
				visited[j]=1;
				addQue(j);
			}
		}
		u=delQue();
		printf("%d->", u);
		if(f==r)
			break;		
	}
	printf("NULL\n");
}
void adj(){
	int i, j;
	printf("\nadjacency matrix[][]: \n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
}
void addQue(int x){
	que[r++]=x;
}
int delQue(){
	return que[f++];
}
