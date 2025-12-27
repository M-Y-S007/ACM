#include<iostream>
using namespace std;
long long val[1200];
long long vis[1200];
long long func(int n){
	if(val[n])return vis[n];
	if(n==1){
		return 1;
	}
	if(n==2){
		return 2;
	}
	int result = 1;
	for(int i=1;i<=n/2;i++){
		result += func(i);
	}
	val[n]=1;
	vis[n]=result;
	return result;
}

int main(){
	int n;
	cin>>n;
	int ans = func(n);
	cout<<ans<<endl;
	return 0;
} 
