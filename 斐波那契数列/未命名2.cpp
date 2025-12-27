#include<bits/stdc++.h>
using namespace std;
#define int long long
int func(int n){
	if((n==1)||(n==2)){
		return 1;
	}
	return(func(n-1)+func(n-2));
}

void solve(){
	int n;
	cin>>n;
	int ans =func(n);
	cout<<ans<<endl;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		solve() ;
	}
	return 0;
}
