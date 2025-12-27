#include<iostream>
using namespace std;
int a[100005];
int sum[100005];
int part_sum(int l,int r){
	if(l==1)return sum[r];
	return sum[r]-sum[l-1];
}
int main(){
	int n,m;
	int l,r;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	cin>>m;
	for(int j=1;j<=m;j++){
		cin>>l>>r;
		cout<<part_sum(l,r)<<endl;
	}
}
