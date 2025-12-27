#include<iostream>
#include<vector>
using namespace std;
int n,k;
vector<int>a;
bool dfs(int i,int sum){
	if(i==n)return sum==k;
	if(dfs(i+1,sum))return true;
	if(dfs(i+1,sum+a[i]))return true;
	return false;
	
}
void solve(){
	if(dfs(0,0))cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}


int main(){

	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>k;
	solve();
}
