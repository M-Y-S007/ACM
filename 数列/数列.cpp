#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int k,N,m=0;
	long long sum=0;
	cin>>k>>N;
	while(1)
	{
		if(N%2==1){
			N=N-1;
			N=N/2;
			m+=1;
			sum+=pow(k,m-1);
			if(N==0)break;
		}
		else {
			N=N/2;
			m+=1;
		}
	}
	cout<<sum;
	
	return 0;
}
