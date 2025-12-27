#include<bits/stdc++.h>
using namespace std;
#define int long long
int vis[16000];
int a[16000];
int func(int n){
	if(n==1){
		return 1;
	}
	if(vis[n])return a[n];
	a[n]=2*func(n-1) + 1;
	vis[n] = 1;
	return(2*func(n-1)+1);
}
signed main(){
	int n;
	cin>>n;
	int ans = func(n);
	cout<<ans<<endl;
	return 0;
}
