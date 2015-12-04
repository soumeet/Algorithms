//Matrix Chain Multiplication
#include<stdio.h>
//#include<conio.h>
void input();
void mcm();
void display();
void parenthesiation(int, int);
int m[10][10]={0}, s[10][10]={0}, p[]={10,50,2,100,10}, n=5;
int main(){	
//	clrscr();
//	input();
	mcm();
	display();
	parenthesiation(1, n);
//	getch();
	return 0;
}

void display(){
	int i, j;
	printf("\nm[][]: \n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
			printf("%d\t", m[i][j]);
		printf("\n");	
	}
	printf("\ns[][]: \n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
			printf("%d\t", s[i][j]);
		printf("\n");	
	}
}

void input(){
	int i;
	printf("\nenter no of matrices: ");
	scanf("%d", &n);
	printf("\nenter elements: \n");
	for(i=1; i<=n+1; i++)
		scanf("%d", &p[i]);
}

void mcm(){
	int i, j, k, l;
	n=n-1;
//	for(i=1; i<=n; i++)	
//		m[i][i]=0;
	for(l=2; l<=n; l++){
		for(i=1; i<=n-l+1; i++){
			j=i+l-1;
			m[i][j]=99999;
			for(k=i; k<=j-1; k++){
				int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}
			}			
		}
	}
}

void parenthesiation(int i, int j){
     if(i==j)
         printf("A%d", i);
     else{
         printf("(");
         parenthesiation(i, s[i][j]);
         parenthesiation(s[i][j]+1, j);
         printf(")");
     }
}

