#include<iostream>
using namespace std;
int a[5000005];
int d[5000005];
int main(){
	int n,p,x,y,z;
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i-1]=a[i]-a[i-1];
	}
	for(int j=1;j<=p;j++){
		cin>>x>>y>>z;
		d[x-1]+=z;
		d[y]-=z;
	}
	for(int k=1;k<=n;k++){
		a[k]=a[k-1]+d[k-1];
	}
	int min=a[1];
	for(int l=1;l<=n;l++){
		if(min>a[l])min=a[l];
	}
	cout<<min;
}
