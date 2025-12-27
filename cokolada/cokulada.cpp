#include <iostream>
using namespace std;
int main()
{
	int K,m=0,D=1,n=0;
	cin>>K;
	while(1)
	{
		if(D>=K)break;
		else{
			D=D<<1;
			n++;
		}
	}
	if(K==D){
		cout<<D<<" "<<0;
		return 0;
	}
	while(1)
	{
		if(K%2==1)break;
		else{
			K=K>>1;
			m++;
		}
	}
	cout<<D<<" "<<n-m;
	return 0;
}
