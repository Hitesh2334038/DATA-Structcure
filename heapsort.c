#include<stdio.h>
#include<stdlib.h>

void insert(int A[],int n)
{
	int temp,i=n;
	
	temp=A[i];
	while(i>1 && temp>A[i/2])
	{
		A[i]=A[i/2];
		i=i/2;
	}
	A[i]=temp;
}

int delete(int A[],int n)
{
	int x,temp,i,j,val;
	x=A[n];
	val=A[1];
	A[n]=val;
	A[1]=x;
	i=1;
	j=i*2;
	while(j<=n-1)
	{
		if(j<n-1 && A[j+1]>A[j])
			j=j+1;
		if(A[i]<A[j])
		{
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		
			i=j;
			j=2*j;
		}
		else
		   break;
	}
	return val;

}

void main()
{
	int H[]={0,10,20,30,25,5,40,35};
	int i;
	for(i=2;i<=7;i++)
		insert(H,i);
		//printf("deleted element is %d \n",delete(H,6));
	//for(i=1;i<=7;i++)
	//	printf(" %d ",H[i]);
	//printf("\n");
	//for(i=6;i<0;i--)
	//	delete(H,6);
		for(i=7;i>1;i--) 
		 {
			 delete(H,i);
		 } 
	for(i=1;i<=7;i++)
		printf(" %d ",H[i]);
}
