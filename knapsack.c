//Knapsack Problem using Greedy Method
#include<stdio.h>
float p[10], w[10], x[10], m, profit;
int j[10], n; 
void knapsack();
void display();
void input();
void sort();
int main(){
	printf("\nEnter number of Jobs: ");
	scanf("%d", &n);
	printf("\nEnter Knapsack Capacity: ");
	scanf("%f", &m);
	input();
	printf("\nGiven Data:");	
	display();
	sort();
	printf("\nAfter Sort:");
	display();
	knapsack();
	printf("\nSolution Vector[]:      ");
	int i;
	for(i=1; i<=n; i++)
		printf("%f\t", x[i]);
	printf("\nMaximum Profit: %f\n", profit);
	return 0;
}

void sort(){
	int i, k;	
	for(i=1; i<=n; i++){
		for(k=1; k<=n; k++){
			if((p[k]/w[k])<=(p[k+1]/w[k+1])){
				int tmp=j[k];
				j[k]=j[k+1];
				j[k+1]=tmp;
				tmp=p[k];
				p[k]=p[k+1];
				p[k+1]=tmp;
				tmp=w[k];
				w[k]=w[k+1];
				w[k+1]=tmp;			
			}
		}
	}
}

void input(){
	int i;
	for(i=1; i<=n; i++){
		j[i]=i;
		printf("Enter weight of job no.%d: ", i);
		scanf("%f", &w[i]);
		printf("Enter profit of job no.%d: ", i);
		scanf("%f", &p[i]);
	}
}

void display(){
	int i;
	printf("\nJob No.:  ");
	for(i=1; i<=n; i++)
		printf("%d\t", j[i]);
	printf("\nWeight:   ");
	for(i=1; i<=n; i++)
		printf("%0.0f\t", w[i]);
	printf("\nProfit:   ");
	for(i=1; i<=n; i++)
		printf("%0.0f\t", p[i]);
	printf("\n");
}

void knapsack(){
	int i;
	float u;
	profit=0;
	for(i=1; i<=n; i++)
		x[i]=0.0;
	u=m;
	for(i=1; i<=n; i++){
		if(w[i]>u)
			break;
		x[i]=1.0;
		u=u-w[i];
		profit=profit+p[i];
	}
	if(i<=n)
		x[i]=u/w[i];
	profit=profit+(x[i]*p[i]);
}
