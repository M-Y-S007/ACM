#include <iostream>
using namespace std;
#define int long long
int vis[50][50];
int val[50][50];
int n;
int func(int k,int m){
	if(k == 2*n){
		if(m == 0)return 1;
		else return 0;
		}
	if(vis[k][m])return val[k][m];
	int t = 0;
	if(m<n){
		t += func(k+1,m+1);
	}
	if(m>0){
		t += func(k+1,m-1);
	}
	val[k][m] = t;
	vis[k][m] = 1;
	return t;
}   

signed main(){
	cin>>n;
	int ans = func(0,0);
	cout << ans << endl;
	return 0;
}
