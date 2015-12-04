//Job Sequence With DeadLine using Greedy Method
#include<stdio.h>
//#include<conio.h>
int d[10], p[10], j[10], job_seq[10], n, profit=0; 
int jswd();
void display();
void input();
void sort();
//int findMax();
int main(){
//	clrscr();	
	int i;
	input();
	display();
	sort();
	display();
	for(i=1; i<=jswd(); i++)
		profit=profit+p[j[i]];
	printf("\nmaximum profit: %d\n", profit);
	display();
	getch();
	return 0;
}

void sort(){
	int i, k;	
	for(i=1; i<=n; i++){
		for(k=1; k<=n; k++){
			if(p[k]<p[k+1]){
				int tmp=p[k];
				p[k]=p[k+1];
				p[k+1]=tmp;
				tmp=d[k];
				d[k]=d[k+1];
				d[k+1]=tmp;
				tmp=j[k];
				j[k]=j[k+1];
				j[k+1]=tmp;				
			}
		}
	}
}

void input(){
	int i;
	printf("\nenter number of jobs: ");
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		j[i]=i;
		printf("Enter deadline of job no.%d: ", i);
		scanf("%d", &d[i]);
		printf("Enter profit of job no.%d: ", i);
		scanf("%d", &p[i]);
	}
}

void display(){
	int i;
	printf("\ngiven Data:");
	printf("\njob No.:  ");
	for(i=1; i<=n; i++)
		printf("%d\t", j[i]);
	printf("\ndeadline: ");
	for(i=1; i<=n; i++)
		printf("%d\t", d[i]);
	printf("\nprofit:   ");
	for(i=1; i<=n; i++)
		printf("%d\t", p[i]);
	printf("\n");
}

int jswd(){
	int i, q, k, r;
	d[0]=j[0]=0;
	j[1]=1;
	k=1;
	for(i=2; i<=n; i++){
		r=k;
		while((d[j[r]]>d[i]) && (d[j[r]]!=r))
			r=r-1;
		if((d[j[r]]<=d[i]) && (d[i]>r)){
			for(q=k; q<=(r+1); q++)
				j[q+1]=j[q];
			j[r+1]=i;
			k=k+1;
		}
	}	
	return k;
}
