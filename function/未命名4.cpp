#include<iostream>
using namespace std;
#define int long long
int vis[25][25][25];
int val[25][25][25];

int func(int a,int b,int c){
	if(a<=0 || b<=0 || c<=0)return 1;
	if(a>20 || b>20 || c>20)return func(20,20,20);
	if(vis[a][b][c])return val[a][b][c];
	if(a<b && b<c){
		val[a][b][c] = func(a,b,c-1) + func(a,b-1,c-1) - func(a,b-1,c);
		vis[a][b][c] = 1;
		return val[a][b][c];
	}else{
		val[a][b][c] = func(a-1,b,c) + func(a-1,b-1,c) + func(a-1,b,c-1) - func(a-1,b-1,c-1);
		vis[a][b][c] = 1;
		return val[a][b][c];
	}
	
}

signed main(){
	int a,b,c;
	cin>>a>>b>>c;
	while(a!=-1 || b!=-1 || c!=-1){
		int ans = func(a,b,c);
		
		cout << "w("<<a<<","<<b<<","<<c<<")";
		
		cin >> a >> b >> c;
	}
}
