#include<iostream>
using namespace std;
int func(int n,int m){
	if(n==m+1)return 1;
	if(n==m+2)return 2;

	return func(n-1,m)+func(n-2,m);
}

int main(){
	
	int m,n;
	cin>>m>>n;
	int ans = func(n,m);
	cout<<ans<<endl;
	
	return 0;
}
//高精度
