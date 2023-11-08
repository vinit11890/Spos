#include<iostream>
using namespace std;
int main()
{
	int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
	cout<<"enter total number(maximum20):";
	cin>>n;
	cout<<"\n enter process burst time aka DURATION\n";
	for(i=0;i<n;i++)
	{
		cout<<"p["<<i+1<<"]:";
		cin>>bt[i];
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		{
			wt[i]+=bt[j];
		}
	}
	cout<<"\nprocess\t\tburst time\twaiting time\tturnaround time";
	
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		avwt+=wt[i];
		avtat+=tat[i];
		cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
	}
	avwt/=i;
	avtat/=i;
	cout<<"\n\n Average wating time:"<<avwt;
	cout<<"\n\n Turnaround time:"<<avtat;
	return 0;
}
