#include <iostream>
using namespace std;
int main()
{
	int sum=1,n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		sum=(sum+1)<<1;
	}
	cout<<sum<<endl;
	return 0;
	
}
