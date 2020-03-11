#include<stdio.h>
int r,c;
int min=1000000001;
int m[1001][1001];
int pre[1001][1001];

int main(void)
{
	scanf("%d%d",&r,&c);
	
	
	int i,j,k,l,sum,ans,tmp;
	for (i=1;i<=r;i++){
		for (j=1;j<=c;j++){
			scanf("%d",&m[i][j]);
			if (min>m[i][j]) min=m[i][j];
		}
	
	}
	/* 
	sum=0;
	for (i=1;i<=r;i++){
		tmp=sum;
		for (j=1;j<=c;j++){
			sum+=pre[i][j];
			
		}
		sum=tmp;
	}

	*/
	printf("%d\n",min);
	
	return 0;
 } 