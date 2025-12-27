#include <iostream>
using namespace std;
int main()
{
	int n,x,number=0;
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		int c = i ;
		while(c>0){
			if(c%10==x){
				number++;
		
        	}
        c/=10;
		}
	}
	cout<<number;
	return 0;

}
