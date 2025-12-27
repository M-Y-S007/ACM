#include<iostream>
using namespace std;
#define int long long
int func(int n){
	if(n==1){
		return 1;
	
	}
	return func(n-1)*n;
}

signed main(){
	int n;
	cin>>n;
	int ans = func(n);
	cout<<ans<<endl;
	
	return 0;
} 
