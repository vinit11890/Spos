#include<iostream>
using namespace std;
int main()
{
	int A[100][4];
	int i,j,n,total=0,index,temp;
	float avg_wt,avg_tat;
	cout<<"enter the number of process:";
	cin>>n;
	
	cout<<"enter burst time:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"p"<<i+1<<":";
		cin>>A[i][1];
		A[i][0]=i+1;
	}
	
	for(i=0;i<n;i++)
	{
		index=i;
		for(j=i+1;j<n;j++)
		if(A[i][1]<A[index][1])
		index=j;
		
		temp=A[i][1];
		A[i][1]=A[index][1];
		A[index][1]= temp;
				
		temp=A[i][0];
		A[i][0]=A[index][0];
		A[index][0]= temp;
	}
	A[0][2]=0;
	for(i=0;i<n;i++)
	{
		A[i][2]=0;
		for(j=i+1;j<n;j++)
		A[i][2] += A[j][1];
		total += A[i][2];
	}
	avg_wt=(float)total/n;
	total=0;
	cout<<"P BT WT TAT"<<endl;
	
	for(i=0;i<n;i++)
	{
		A[i][3]=A[i][1]+A[i][2];
		total+=A[1][3];
		cout<<"P"<<A[i][0]<<""<<A[i][1]<<""<<A[i][2]<<""<<A[i][3]<<endl;
	}
	
	avg_tat=(float)total/n;
	cout<<"Average waiting time="<<avg_wt<<endl;
	cout<<"Average turnarount time="<<avg_tat<<endl;
}
