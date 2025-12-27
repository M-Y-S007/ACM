#include <iostream>
using namespace std;
int val[1000005];
int vis[1000005];
long long func(int N){
	if(N == 1)return 1;
	if(N == 2)return 2;
	if(N == 3)return 5;
	if(val[N])return vis[N];
	val[N] = 1;
	vis[N] = (2*func(N-1) + func(N-3))%10000;
	return vis[N];

}

int main(){
	int N;
	cin>>N;
	int ans = func(N);
	cout<<ans<<endl;
	return 0;
}
